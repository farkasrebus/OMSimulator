-- name: TrafficLightScenario
-- status: ?
-- teardown_command: rm TrafficLightScenario.log

-- Uncomment below if script shall be executed by a standard Lua interpreter (see README.md)
-- require("package")
-- OMSimulatorLua = package.loadlib("../../install/linux/lib/libOMSimulatorLua.so", "luaopen_OMSimulatorLua")
-- OMSimulatorLua()
-- OMFitLua = package.loadlib("../../install/linux/lib/libOMFitLua.so", "luaopen_OMFitLua")
-- OMFitLua()

setLogFile("TrafficLightScenario.log")

version = getVersion()
-- print(version)

model = newModel()
setTempDirectory(".")

-- instantiate FMU
instantiateFMU(model, "TrafficLightScenario_Car.fmu", "Car")
instantiateFMU(model, "TrafficLightScenario_DummyTrafficLight.fmu", "Light")

-- add connections: connect(light.color,car.lightColorInteger);
addConnection(model, "Car.color", "Light.color")

-- describe(model)

-- configure simulation
-- set result file
setResultFile(model, "TrafficLightScenario.mat")
-- Simulate for 5 secs
setStopTime(model, 5.0)
-- communicate every 0.01 s
setCommunicationInterval(model, 0.01)







initialize(model)
simulate(model)

terminate(model)
unload(model)

-- Result:
-- endResult
