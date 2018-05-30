-- Uncomment below if script shall be executed by a standard Lua interpreter (see README.md)
 require("package")
 OMSimulatorLua = package.loadlib("../../install/linux/lib/libOMSimulatorLua.so", "luaopen_OMSimulatorLua")
 OMSimulatorLua()
 OMFitLua = package.loadlib("../../install/linux/lib/libOMFitLua.so", "luaopen_OMFitLua")
 OMFitLua()

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
-- Initial communication interval
setCommunicationInterval(model, 0.01)
bigSteps=true
print("Initialization: Communication interval set to 0.01")

initialize(model)

-- For constant step size simulation
-- simulate(model)

-- For step size control  specific to this model
-- stepUntil(model,0.4)
--setCommunicationInterval(model, 0.005)
--stepUntil(model,2.0)

-- For step size control by variable checking
tcur=0.0
stopDistanceInfo=false
while (tcur<=5.0)
do
	doSteps(model,1)
	dist=getReal(model, "Car.distance")
	crit=getBoolean(model,"Car.criticalSituation")
	--print(dist .." ".. crit .." " .. getInteger(model,"Car.stateInteger"), bigSteps)
	--[[
	if bigSteps==true then
		if crit==1.0 then 
			setCommunicationInterval(model, 0.005)
			print("Critical situation. Communication interval set to 0.005")
			bigSteps=false
		end
	elseif crit==0.0 then 
		setCommunicationInterval(model, 0.01)
		print("Critical situation over. Communication interval set to 0.01")
		bigSteps=true
	--else 
	--	print("No changes necessary")
	end
	--]]
	if ((not stopDistanceInfo) and getInteger(model,"Car.stateInteger")==3.0) then
		print("Car's distance from pedestrian crossing after breaking: ".. dist)
		stopDistanceInfo=true
	end
	tcur=getCurrentTime(model)
end

dist=getReal(model, "Car.distance")


terminate(model)
unload(model)

-- Result:
-- endResult
