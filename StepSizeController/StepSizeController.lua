-- simple, variable-driven step size control - deprecated
local bigSteps=true
function doAdaptiveStep (model,criticalVarName,bigStepSize,smallStepSize)
	oms2_doSteps(model,1)
	local crit=oms2_getBoolean(criticalVarName)
	if bigSteps==true then
		if crit==1.0 then 
			oms2_setCommunicationInterval(model, smallStepSize)
			print("Critical situation. Communication interval set to " .. smallStepSize)
			bigSteps=false
		end
	elseif crit==0.0 then 
		oms2_setCommunicationInterval(model, bigStepSize)
		print("Critical situation over. Communication interval set to " .. bigStepSize)
		bigSteps=true
	end
end

function simulateWithAdaptiveStepSizeControl(model,criticalVarName,bigStepSize,smallStepSize,tmax)
	local tcur=0.0
	while (tcur<tmax)
	do
		doAdaptiveStep (model,criticalVarName,bigStepSize,smallStepSize)
		tcur=oms2_getCurrentTime(model)
	end
end

-- sensitivity model
SensitivityModel = {}
SensitivityModel.__index = SensitivityModel

function SensitivityModel:create()
	local sm = {}
	setmetatable(sm,SensitivityModel)
	sm.events = {} -- discrete events - collection of variables, where any change is interesting
	sm.zeroCrossings = {} -- maps from variable name to step size adjustment based on value
	-- sm.monitors -- todo: predictive monitors
	return sm
end

-- step size control based on a sensitivity model
function getNextStepSize(sensitivityModel,communicationInterval)
	local minStepSize=communicationInterval
	-- discrete chains
	-- tbd	
	-- zero crossings
	local zc=sensitivityModel.zeroCrossings
	for variable,bandFunc in pairs(zc)
	do
		value=oms2_getReal(k)
		step=bandFunc(value)
		if (step != nil and step<minStepSize) then
			minStepSize=step
		end
	end
	-- predictive models
	-- tbd
	return minStepSize
end

function oms2_simulateWithASSC(model,communicationInterval,sensitivityModel,tmax)
	local tcur=0.0
	while (tcur<tmax)
	do
		local nextStepSize = getNextStepSize(sensitivityModel,communicationInterval)
		oms2_setCommunicationInterval(model, nextStepSize)
		oms2_doSteps(model,1)
		tcur=tcur+nextStepSize
	end
end
