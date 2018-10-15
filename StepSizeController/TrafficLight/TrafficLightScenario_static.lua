oms2_setLogFile("TrafficLightScenario.log")
status = oms2_setTempDirectory("./tmp")
status = oms2_newFMIModel("TrafficLight")

-- instantiate FMU
status = oms2_addFMU("TrafficLight", "TrafficLightScenario_Car.fmu", "Car")
status = oms2_addFMU("TrafficLight", "TrafficLightScenario_DummyTrafficLight.fmu", "Light")
oms2_addSolver("TrafficLight", "solver", "internal")
oms2_addConnection("TrafficLight", "Car", "solver")
oms2_addConnection("TrafficLight", "Light", "solver")

-- add connections: connect(light.color,car.lightColorInteger);
oms2_addConnection("TrafficLight", "Car:color", "Light:color")

-- set result file
oms2_setResultFile("TrafficLight", "TrafficLightScenario.mat")
-- Simulate for 5 secs
oms2_setStopTime("TrafficLight", 5.0)
-- communicate every 0.01 s
oms2_setCommunicationInterval("TrafficLight", 0.01)

oms2_initialize("TrafficLight")
oms2_simulate("TrafficLight")

oms2_unloadModel("TrafficLight")
