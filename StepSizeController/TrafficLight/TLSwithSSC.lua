package.path = package.path .. ";../StepSizeController.lua"
require("StepSizeController")

oms2_setLogFile("TrafficLightScenario.log")
oms2_setTempDirectory("./tmp")
oms2_newFMIModel("TrafficLight")
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
-- Initial communication interval
oms2_setCommunicationInterval("TrafficLight", 0.01)

oms2_initialize("TrafficLight")

bm=BandModel:create()
bm:addBand(-10.0,0.0,0.01)
bm:addBand(0.0,10.0,0.005)
bm:addBand(10.0,20.0,0.01)

sm=SensitivityModel:create()
sm.zeroCrossings["TrafficLight.Car:distance"]=bm

oms2_simulateWithASSC("TrafficLight",0.01,sm,0.005,5.0)

oms2_unloadModel("TrafficLight")

