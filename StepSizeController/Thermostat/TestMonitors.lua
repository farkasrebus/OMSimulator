oms2_setLogFile("MonitorTest.log")
oms2_setTempDirectory("./tmp/test")
oms2_newFMIModel("HeatSystem")

oms2_addFMU("HeatSystem","ThermostatMonitor_CentralMonitor.fmu","CentralMonitor")
oms2_addFMU("HeatSystem","ThermostatMonitor_CriticalTemperatureMonitor.fmu","TemperatureMonitor")
oms2_addFMU("HeatSystem","ThermostatMonitor_HeatingOnMonitor.fmu","HeatingMonitor")
oms2_addFMU("HeatSystem","ThermostatMonitor_ThermostatOnMonitor.fmu","ThermostatMonitor")
oms2_addFMU("HeatSystem","ThermostatMonitor_DummyTestEnvironment.fmu","Env")

oms2_addSolver("HeatSystem", "solver", "internal")
oms2_connectSolver("HeatSystem","CentralMonitor","solver")
oms2_connectSolver("HeatSystem","TemperatureMonitor","solver")
oms2_connectSolver("HeatSystem","HeatingMonitor","solver")
oms2_connectSolver("HeatSystem","ThermostatMonitor","solver")
oms2_connectSolver("HeatSystem","Env","solver")

oms2_addConnection("HeatSystem","Env:turnThermostatOn","ThermostatMonitor:turnOn")
oms2_addConnection("HeatSystem","Env:turnThermostatOff","ThermostatMonitor:turnOff")
oms2_addConnection("HeatSystem","Env:turnHeatingOff","HeatingMonitor:turnOff")
oms2_addConnection("HeatSystem","Env:temperature","TemperatureMonitor:temperature")
oms2_addConnection("HeatSystem","Env:target","TemperatureMonitor:target")
oms2_addConnection("HeatSystem","Env:hysteresis","TemperatureMonitor:hysteresis")

oms2_addConnection("HeatSystem","Env:turnHeatingOnPermission","CentralMonitor:heatOnPermission")
oms2_addConnection("HeatSystem","CentralMonitor:heatOnGrant","HeatingMonitor:turnOn")

oms2_addConnection("HeatSystem","CentralMonitor:termReq","ThermostatMonitor:request")
oms2_addConnection("HeatSystem","CentralMonitor:heatReq","HeatingMonitor:request")
oms2_addConnection("HeatSystem","CentralMonitor:tempReq","TemperatureMonitor:request")
oms2_addConnection("HeatSystem","CentralMonitor:termReply","ThermostatMonitor:reply")
oms2_addConnection("HeatSystem","CentralMonitor:heatReply","HeatingMonitor:reply")
oms2_addConnection("HeatSystem","CentralMonitor:tempReply","TemperatureMonitor:reply")

oms2_setResultFile("HeatSystem", "MonitorTest.mat")
-- configure simulation
oms2_setStopTime("HeatSystem", 200.0)
oms2_setCommunicationInterval("HeatSystem", 1.0)
oms2_initialize("HeatSystem")

oms2_simulate("HeatSystem")


oms2_unloadModel("HeatSystem")
