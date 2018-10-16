oms2_setLogFile("test.log")
oms2_setLoggingLevel(2);
status = oms2_setTempDirectory("./tmp")
status = oms2_newFMIModel("TrafficLight")

-- instantiate FMU
status = oms2_addFMU("TrafficLight", "TrafficLightScenario_Car.fmu", "Car")
status = oms2_addFMU("TrafficLight", "TrafficLightScenario_DummyTrafficLight.fmu", "Light")
oms2_addSolver("TrafficLight", "solver", "internal")
oms2_addConnection("TrafficLight", "Car", "solver")
oms2_addConnection("TrafficLight", "Light", "solver")

oms2_addConnection("TrafficLight", "Car:color", "Light:color")

-- set result file
oms2_setResultFile("TrafficLight", "TrafficLightScenario.csv")
-- Simulate for 5 secs
oms2_setStopTime("TrafficLight", 5.0)
-- communicate every 0.01 s
oms2_setCommunicationInterval("TrafficLight", 0.01)

oms2_setMasterAlgorithm("TrafficLight","assc")
oms2_setCriticalVariable("TrafficLight.Car:distance");
crit=oms2_getCriticalVariable("TrafficLight")
print(crit);

--[[
oms2_initialize("TrafficLight")
dist=oms2_getReal("TrafficLight.Car:distance")
print("dist: "..dist)
oms2_simulate("TrafficLight")
--]]

oms2_unloadModel("TrafficLight")

