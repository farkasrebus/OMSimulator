-- dump function

function dump(o)
   if type(o) == 'table' then
      local s = '{ '
      for k,v in pairs(o) do
         if type(k) ~= 'number' then k = '"'..k..'"' end
         s = s .. '['..k..'] = ' .. dump(v) .. ','
      end
      return s .. '} '
   else
      return tostring(o)
   end
end

-- sensitivity model
SensitivityModel = {}
SensitivityModel.__index = SensitivityModel

function SensitivityModel:create()
	local sm = {}
	setmetatable(sm,SensitivityModel)
	sm.events = {} -- discrete events - set of variables, where any change is interesting
	sm.timeIndicators = {} -- timed events - set of variables indicating the next event
	sm.zeroCrossings = {} -- interesting threshold-crossings - maps from variable name to something with a getStepSize() function
	return sm
end

BandModel = {}
BandModel.__index = BandModel

function BandModel:create()
	local bm = {}
	setmetatable(bm,BandModel)
	bm.bounds = {} -- maps the lower bound of the band to the upper bound
	bm.stepSizes = {} -- maps the lower bound of the band to the step size
 	return bm
end


function BandModel:addBand(bandMinValue,bandMaxValue,stepSize)
	self.bounds[bandMinValue]=bandMaxValue
	self.stepSizes[bandMinValue]=stepSize
end

function BandModel:getStepSize(value)
	for min,max in pairs(self.bounds)
	do
		if (value >= min and value <=max) then
			return self.stepSizes[min]
		end
	end
	return nil
end

DynamicBandModel = {}
DynamicBandModel.__index = DynamicBandModel

function DynamicBandModel:create(trg,relBandWith)
	local dbm = {}
	setmetatable(dbm,DynamicBandModel)
	dbm.target = trg -- a variable describing the current targetValue
	dbm.relativeBandWith = relBandWith -- a variable describing the current relative difference from the target value
	dbm.levels = {} -- maps from fraction of bandwith to (max) step size
	return dbm
end

function DynamicBandModel:getStepSize(value)
	local currtrg=oms2_getReal(self.target)
	local currhys=oms2_getReal(self.relativeBandWith)
	local diff=math.abs(value-currtrg)
	if (diff>currhys) then 
		return nil 
	else
		local fracsize=diff/currhys
		local min=self.levels[1.0]
		for f,s in pairs(self.levels) do
			if (fracsize<f and s<min) then min=s end
		end
		return min
	end
end

-- step size control based on a sensitivity model
function didEventOccur(vars)
	--print("param for didEventOccur",dump(vars))
	local eventOccured=false
	for v,pv in pairs(vars.reals)
	do
		local currVal=oms2_getReal(v)
		--print(v .. pv .. currVal)
		if (pv ~= currVal) then
			vars.reals[v]=currVal
			eventOccured=true
		end	
	end
	for v,pv in pairs(vars.ints)
	do
		local currVal=oms2_getInteger(v)
		--print(v .. pv .. currVal)
		if (pv ~= currVal) then
			vars.ints[v]=currVal
			eventOccured=true
		end	
	end
	for v,pv in pairs(vars.bools)
	do
		local currVal=oms2_getBoolean(v)
		--print(v .. pv .. currVal)
		if (pv ~= currVal) then
			vars.bools[v]=currVal
			eventOccured=true
		end	
	end
	--print(dump(vars))
	return eventOccured
end

function getValues(vars)
	local values={}
	local intvalues={}
	local realvalues={}
	local boolvalues={}
	--print("Parameter for getValues",dump(vars))
	for v,t in pairs(vars)
	do
		if ("real"==t) then 
			realvalues[v]=oms2_getReal(v)
		elseif ("integer"==t) then
			intvalues[v]=oms2_getInteger(v)
		elseif ("boolean"==t) then
			boolvalues[v]=oms2_getBoolean(v)
		else
			print("Unsupported data type: ",t," Supported data types are real, integer, boolean")
		end	
	end
	values.ints=intvalues
	values.reals=realvalues
	values.bools=boolvalues
	--print(dump(values))
	return values
end

function getNextTimedEvent(vars)
	local min=math.huge;
	for v,_ in pairs(vars)
	do
		local value=oms2_getReal(v)
		if (value > 0 and value<min) then min=value end
	end
	return min
end

function getNextStepSize(prevValues,zeroCrossings,timedIndicators,communicationInterval,imin,tcur)
	local minStepSize=communicationInterval
	-- discrete event chains: if there was an event we adjust the step size to the minimal value
	local eventOccured=didEventOccur(prevValues)
	if (eventOccured) then
		-- print("Event")
		return imin
	else
		local nextTimedEvent = getNextTimedEvent(timedIndicators)
		--print("Next:",nextTimedEvent,"Current:",tcur)
		if (nextTimedEvent<=tcur) then
			return imin
		else
			if (nextTimedEvent-tcur < minStepSize) then minStepSize=nextTimedEvent-tcur end
			-- zero crossings
			local zc=zeroCrossings
			for variable,bands in pairs(zc)
			do
				value=oms2_getReal(variable)
				step=bands:getStepSize(value)
				if (step ~= nil and step<minStepSize) then
					minStepSize=step
				end
			end
			if (minStepSize<imin) then return imin else return minStepSize end
		end
	end
end

function oms2_simulateWithASSC(model,communicationInterval,sensitivityModel,imin,tmax)
	local tcur=0.0
	--print(dump(sensitivityModel))
	local prevValues=getValues(sensitivityModel.events)
	--print(dump(prevValues))
	while (tcur<tmax)
	do
		local nextStepSize = getNextStepSize(prevValues,sensitivityModel.zeroCrossings,sensitivityModel.timeIndicators,communicationInterval,imin,tcur)
		oms2_setCommunicationInterval(model, nextStepSize)
		oms2_doSteps(model,1)
		tcur=tcur+nextStepSize
	end
end
