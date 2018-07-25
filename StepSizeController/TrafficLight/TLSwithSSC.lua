package.path = package.path .. ";../StepSizeController.lua"
require("StepSizeController")

oms2_setLogFile("TrafficLightScenario.log")
oms2_setTempDirectory("./tmp")
oms2_newFMIModel("TrafficLight")
-- instantiate FMU
status = oms2_addFMU("TrafficLight", "TrafficLightScenario_Car.fmu", "Car")
status = oms2_addFMU("TrafficLight", "TrafficLightScenario_DummyTrafficLight.fmu", "Light")
-- add connections: connect(light.color,car.lightColorInteger);
oms2_addConnection("TrafficLight", "Car:color", "Light:color")
-- set result file
oms2_setResultFile("TrafficLight", "TrafficLightScenario.mat")
-- Simulate for 5 secs
oms2_setStopTime("TrafficLight", 5.0)
-- Initial communication interval
oms2_setCommunicationInterval("TrafficLight", 0.01)

oms2_initialize("TrafficLight")

simulateWithAdaptiveStepSizeControl("TrafficLight","TrafficLight.Car:criticalSituation",0.01,0.005,5.0)

oms2_unloadModel("TrafficLight")

