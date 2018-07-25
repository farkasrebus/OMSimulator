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

oms2_exportDependencyGraphs("TrafficLight","x.dot","")

oms2_unloadModel("TrafficLight")