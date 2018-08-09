package.path = package.path .. ";../StepSizeController.lua"

require("StepSizeController")

oms2_setLogFile("MonitoredThermostat.log")
oms2_setTempDirectory("./tmp")
oms2_newFMIModel("MonitoredThermostat")

oms2_addFMU("MonitoredThermostat","advancedThermostat.fmu","Thermostat")
oms2_addFMU("MonitoredThermostat","Room.fmu","Room")
oms2_addFMU("MonitoredThermostat","ThermostatMonitor_CentralMonitor.fmu","CentralMonitor")
oms2_addFMU("MonitoredThermostat","ThermostatMonitor_CriticalTemperatureMonitor.fmu","TemperatureMonitor")
oms2_addFMU("MonitoredThermostat","ThermostatMonitor_HeatingOnMonitor.fmu","HeatingMonitor")
oms2_addFMU("MonitoredThermostat","ThermostatMonitor_ThermostatOnMonitor.fmu","ThermostatMonitor")


oms2_addSolver("MonitoredThermostat", "solver", "internal")
oms2_connectSolver("MonitoredThermostat", "Room", "solver")
oms2_connectSolver("MonitoredThermostat", "Thermostat", "solver")
oms2_connectSolver("MonitoredThermostat","CentralMonitor","solver")
oms2_connectSolver("MonitoredThermostat","TemperatureMonitor","solver")
oms2_connectSolver("MonitoredThermostat","HeatingMonitor","solver")
oms2_connectSolver("MonitoredThermostat","ThermostatMonitor","solver")

oms2_addConnection("MonitoredThermostat",
	"Thermostat:Thermostat_HeatingControlPort_set_hysteresis_intervallum_hysteresis_intervallum",
	"Room:heatingControlPort1.set_hysteresis_intervallum1.hysteresis_intervallum[1]")
oms2_addConnection("MonitoredThermostat",
	"Thermostat:Thermostat_HeatingControlPort_set_hysteresis_intervallum_hysteresis_intervallum1",
	"Room:heatingControlPort1.set_hysteresis_intervallum1.hysteresis_intervallum[2]")
oms2_addConnection("MonitoredThermostat",
	"Thermostat:Thermostat_HeatingControlPort_set_hysteresis_intervallum_hysteresis_intervallum2",
	"Room:heatingControlPort1.set_hysteresis_intervallum1.hysteresis_intervallum[3]")
oms2_addConnection("MonitoredThermostat",
	"Thermostat:Thermostat_TemperatureStreamPort_measured_temperature_measured_temperature",
	"Room:temperatureStreamPort1.measured_temperature1.measured_temperature[1]")
oms2_addConnection("MonitoredThermostat",
	"Thermostat:Thermostat_TemperatureStreamPort_measured_temperature_measured_temperature1",
	"Room:temperatureStreamPort1.measured_temperature1.measured_temperature[2]")
oms2_addConnection("MonitoredThermostat",
	"Thermostat:Thermostat_TemperatureStreamPort_measured_temperature_measured_temperature2",
	"Room:temperatureStreamPort1.measured_temperature1.measured_temperature[3]")
oms2_addConnection("MonitoredThermostat",
	"Thermostat:Thermostat_ThermostatControlPort_set_target_temperature_target_temperature",
	"Room:thermostatControlPort1.set_target_temperature1.target_temperature[1]")
oms2_addConnection("MonitoredThermostat",
	"Thermostat:Thermostat_ThermostatControlPort_set_target_temperature_target_temperature1",
	"Room:thermostatControlPort1.set_target_temperature1.target_temperature[2]")
oms2_addConnection("MonitoredThermostat",
	"Thermostat:Thermostat_ThermostatControlPort_set_target_temperature_target_temperature2",
	"Room:thermostatControlPort1.set_target_temperature1.target_temperature[3]")
oms2_addConnection("MonitoredThermostat",
	"Thermostat:Thermostat_HeatingControlPort_set_hysteresis_intervallum",
	"Room:heatingControlPort1.set_hysteresis_intervallum1.counter")
oms2_addConnection("MonitoredThermostat",
	"Thermostat:Thermostat_TemperatureStreamPort_measured_temperature",
	"Room:temperatureStreamPort1.measured_temperature1.counter")
oms2_addConnection("MonitoredThermostat",
	"Thermostat:Thermostat_ThermostatControlPort_set_target_temperature",
	"Room:thermostatControlPort1.set_target_temperature1.counter")
oms2_addConnection("MonitoredThermostat",
	"Thermostat:Thermostat_ThermostatControlPort_turn_thermostat_off",
	"Room:thermostatControlPort1.turn_thermostat_off1.counter")
oms2_addConnection("MonitoredThermostat",
	"Thermostat:Thermostat_ThermostatControlPort_turn_thermostat_on",
	"Room:thermostatControlPort1.turn_thermostat_on1.counter")
oms2_addConnection("MonitoredThermostat",
	"Room:heatingControlPort1.turn_heating_off1.counter",
	"Thermostat:Thermostat_HeatingControlPort_turn_heating_off")
-- oms2_addConnection("MonitoredThermostat",
--	"Room:heatingControlPort1.turn_heating_on1.counter",
--	"Thermostat:Thermostat_HeatingControlPort_turn_heating_on")
oms2_addConnection("MonitoredThermostat",
	"Room:heatingControlPort1.turn_heating_on1.counter",
	"CentralMonitor:heatOnGrant")
oms2_addConnection("MonitoredThermostat",
	"CentralMonitor:heatOnPermission",
	"Thermostat:Thermostat_HeatingControlPort_turn_heating_on")


oms2_addConnection("MonitoredThermostat",
	"Room:thermostatControlPort1.turn_thermostat_on1.counter",
	"ThermostatMonitor:turnOn")
oms2_addConnection("MonitoredThermostat",
	"Room:thermostatControlPort1.turn_thermostat_off1.counter",
	"ThermostatMonitor:turnOff")
oms2_addConnection("MonitoredThermostat",
	"Thermostat:Thermostat_HeatingControlPort_turn_heating_off",
	"HeatingMonitor:turnOff")
oms2_addConnection("MonitoredThermostat",
	"Room:temperatureStreamPort1.measured_temperature1.measured_temperature[1]",
	"TemperatureMonitor:temperature")
oms2_addConnection("MonitoredThermostat",
	"Room:thermostatControlPort1.set_target_temperature1.target_temperature[1]",
	"TemperatureMonitor:target")
oms2_addConnection("MonitoredThermostat",
	"Room:heatingControlPort1.set_hysteresis_intervallum1.hysteresis_intervallum[1]",
	"TemperatureMonitor:hysteresis")

--oms2_addConnection("MonitoredThermostat",
--	"Env:turnHeatingOnPermission",
--  "CentralMonitor:heatOnPermission")
oms2_addConnection("MonitoredThermostat","CentralMonitor:heatOnGrant","HeatingMonitor:turnOn")

oms2_addConnection("MonitoredThermostat","CentralMonitor:termReq","ThermostatMonitor:request")
oms2_addConnection("MonitoredThermostat","CentralMonitor:heatReq","HeatingMonitor:request")
oms2_addConnection("MonitoredThermostat","CentralMonitor:tempReq","TemperatureMonitor:request")
oms2_addConnection("MonitoredThermostat","CentralMonitor:termReply","ThermostatMonitor:reply")
oms2_addConnection("MonitoredThermostat","CentralMonitor:heatReply","HeatingMonitor:reply")
oms2_addConnection("MonitoredThermostat","CentralMonitor:tempReply","TemperatureMonitor:reply")

oms2_setResultFile("MonitoredThermostat", "MonitoredThermostat.mat")

--oms2_setStopTime("MonitoredThermostat", 500.0)
--oms2_setCommunicationInterval("MonitoredThermostat", 1.0)
oms2_initialize("MonitoredThermostat")

-- band model for the first time the thermostat should be turned on
bm=BandModel:create()
bm:addBand(18.0,19.02,0.1)
bm:addBand(19.02,19.1,1.0)
bm:addBand(19.1,24.0,10.0)
bm:addBand(24.0,26.0,0.1)

sm=SensitivityModel:create()
sm.zeroCrossings["MonitoredThermostat.Room:temperatureStreamPort1.measured_temperature1.measured_temperature[1]"]=bm
-- events indicating messages between monitors
sm.events["MonitoredThermostat.Thermostat:Thermostat_HeatingControlPort_turn_heating_on"]="integer"
sm.events["MonitoredThermostat.CentralMonitor:termReq"]="real"
sm.events["MonitoredThermostat.CentralMonitor:heatReq"]="real"
sm.events["MonitoredThermostat.CentralMonitor:tempReq"]="real"
sm.events["MonitoredThermostat.ThermostatMonitor:reply"]="real"
sm.events["MonitoredThermostat.HeatingMonitor:reply"]="real"
sm.events["MonitoredThermostat.TemperatureMonitor:reply"]="real"
-- sm.events["CentralMonitor:heatOnGrant"]=real -- it is possible to include it but useless

oms2_simulateWithASSC("MonitoredThermostat",10.0,sm,0.01,500.0)

--oms2_simulate("MonitoredThermostat")

oms2_unloadModel("MonitoredThermostat")




