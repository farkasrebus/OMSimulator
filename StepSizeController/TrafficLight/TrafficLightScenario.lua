oms2_setLogFile("TrafficLightScenario.log")
oms2_setTempDirectory("./tmp")
oms2_newFMIModel("TrafficLight")

-- instantiate FMU
status = oms2_addFMU("TrafficLight", "TrafficLightScenario_Car.fmu", "Car")
status = oms2_addFMU("TrafficLight", "TrafficLightScenario_DummyTrafficLight.fmu", "Light")

-- add connections: connect(light.color,car.lightColorInteger);
oms2_addConnection("TrafficLight", "Car:color", "Light:color")



-- configure simulation
-- set result file
oms2_setResultFile("TrafficLight", "TrafficLightScenario.mat")
-- Simulate for 5 secs
oms2_setStopTime("TrafficLight", 5.0)
-- Initial communication interval
oms2_setCommunicationInterval("TrafficLight", 0.01)
bigSteps=true
print("Initialization: Communication interval set to 0.01")

oms2_initialize("TrafficLight")

-- For constant step size simulation
-- oms2_simulate("TrafficLight")

-- For step size control  specific to this model
-- oms2_stepUntil("TrafficLight",0.4)
-- oms2_setCommunicationInterval("TrafficLight", 0.005)
-- oms2_stepUntil("TrafficLight",2.0)

-- For step size control by variable checking
tcur=0.0
stopDistanceInfo=false
while (tcur<=5.0)
do
	oms2_doSteps("TrafficLight",1)
	dist=oms2_getReal("TrafficLight.Car:distance")
	crit=oms2_getBoolean("TrafficLight.Car:criticalSituation")
	--print(dist .." ".. crit .." " .. oms2_getInteger("TrafficLight.Car:stateInteger"), bigSteps)
	---[[
	if bigSteps==true then
		if crit==1.0 then 
			oms2_setCommunicationInterval("TrafficLight", 0.005)
			print("Critical situation. Communication interval set to 0.005")
			bigSteps=false
		end
	elseif crit==0.0 then 
		oms2_setCommunicationInterval("TrafficLight", 0.01)
		print("Critical situation over. Communication interval set to 0.01")
		bigSteps=true
	--else 
	--	print("No changes necessary")
	end
	--]]
	if ((not stopDistanceInfo) and oms2_getInteger("TrafficLight.Car:stateInteger")==3.0) then
		print("Car's distance from pedestrian crossing after breaking: ".. dist)
		stopDistanceInfo=true
	end
	tcur=oms2_getCurrentTime("TrafficLight")
end

dist=oms2_getReal("TrafficLight.Car:distance")

oms2_terminate("TrafficLight")
oms2_unloadModel("TrafficLight")

