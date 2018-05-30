package.path = package.path .. ";../StepSizeController.lua"
require("StepSizeController")

setLogFile("TrafficLightScenario.log")
model = newModel()
setTempDirectory(".")
-- instantiate FMU
instantiateFMU(model, "TrafficLightScenario_Car.fmu", "Car")
instantiateFMU(model, "TrafficLightScenario_DummyTrafficLight.fmu", "Light")
-- add connections: connect(light.color,car.lightColorInteger);
addConnection(model, "Car.color", "Light.color")
-- set result file
setResultFile(model, "TrafficLightScenario.mat")
-- Simulate for 5 secs
setStopTime(model, 5.0)
-- Initial communication interval
setCommunicationInterval(model, 0.01)

initialize(model)

simulateWithAdaptiveStepSizeControl(model,"Car.criticalSituation",0.01,0.005,5.0)

terminate(model)
unload(model)

