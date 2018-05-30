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


