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
	sm.zeroCrossings = {} -- maps from variable name to an object with a function getStepSize()
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

-- step size control based on a sensitivity model
function didEventOccur(vars)
	local eventOccured=false
	for v,pv in pairs(vars)
	do
		local currVal=oms2_getReal(v)
		--print(v .. pv .. currVal)
		if (pv ~= currVal) then
			vars[v]=currVal
			eventOccured=true
		end	
	end
	return eventOccured
end

function getValues(vars)
	local values={}
	for v,_ in pairs(vars)
	do
		values[v]=oms2_getReal(v)	
	end
	return values
end

function getNextStepSize(prevValues,zeroCrossings,communicationInterval,imin)
	local minStepSize=communicationInterval
	-- discrete event chains: if there was an event we adjust the step size to the minimal value
	local eventOccured=didEventOccur(prevValues)
	if (eventOccured) then
		--print("Event")
		minStepSize=imin
		return minStepSize
	else
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
		return minStepSize
	end
end

function oms2_simulateWithASSC(model,communicationInterval,sensitivityModel,imin,tmax)
	local tcur=0.0
	local prevValues=getValues(sensitivityModel.events)
	--print(dump(prevValues))
	while (tcur<tmax)
	do
		local nextStepSize = getNextStepSize(prevValues,sensitivityModel.zeroCrossings,communicationInterval,imin)
		oms2_setCommunicationInterval(model, nextStepSize)
		oms2_doSteps(model,1)
		tcur=tcur+nextStepSize
	end
end
