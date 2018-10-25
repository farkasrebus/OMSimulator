oms2_setLogFile("test.log")
--oms2_setLoggingLevel(2);
status = oms2_setTempDirectory("./tmp")

oms2_newFMIModel("MonitoredThermostat")
-- instantiate FMU
oms2_addFMU("MonitoredThermostat","advancedThermostat.fmu","Thermostat")
oms2_addFMU("MonitoredThermostat","Room.fmu","Room")
oms2_addFMU("MonitoredThermostat","ThermostatMonitor_CentralMonitor.fmu","CentralMonitor")
oms2_addFMU("MonitoredThermostat","ThermostatMonitor_CriticalTemperatureMonitor.fmu","TemperatureMonitor")
oms2_addFMU("MonitoredThermostat","ThermostatMonitor_HeatingOnMonitor.fmu","HeatingMonitor")
oms2_addFMU("MonitoredThermostat","ThermostatMonitor_ThermostatOnMonitor.fmu","ThermostatMonitor")


oms2_addSolver("MonitoredThermostat", "solver", "internal")
oms2_addConnection("MonitoredThermostat", "Room", "solver")
oms2_addConnection("MonitoredThermostat", "Thermostat", "solver")
oms2_addConnection("MonitoredThermostat","CentralMonitor","solver")
oms2_addConnection("MonitoredThermostat","TemperatureMonitor","solver")
oms2_addConnection("MonitoredThermostat","HeatingMonitor","solver")
oms2_addConnection("MonitoredThermostat","ThermostatMonitor","solver")
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
-- set result file
oms2_setResultFile("MonitoredThermostat", "Test.mat")
oms2_addSignalsToResults("MonitoredThermostat","CentralMonitor:nextHeartBeat")
-- configure simulation
oms2_setCommunicationInterval("MonitoredThermostat", 10.0)
oms2_setStopTime("MonitoredThermostat", 1000.0)
oms2_setMasterAlgorithm("MonitoredThermostat","assc")
-- configure assc
oms2_addEventIndicator("MonitoredThermostat.Thermostat:Thermostat_HeatingControlPort_turn_heating_on")
oms2_addEventIndicator("MonitoredThermostat.CentralMonitor:termReq")
oms2_addEventIndicator("MonitoredThermostat.CentralMonitor:heatReq")
oms2_addEventIndicator("MonitoredThermostat.CentralMonitor:tempReq")
oms2_addEventIndicator("MonitoredThermostat.ThermostatMonitor:reply")
oms2_addEventIndicator("MonitoredThermostat.HeatingMonitor:reply")
oms2_addEventIndicator("MonitoredThermostat.TemperatureMonitor:reply")
oms2_addTimeIndicator("MonitoredThermostat.CentralMonitor:nextHeartBeat")

oms2_setMinimalStepSize("MonitoredThermostat", 0.1)
oms2_setMaximalStepSize("MonitoredThermostat", 1.0)
-- simulate
oms2_initialize("MonitoredThermostat")
oms2_simulate("MonitoredThermostat")
-- terminate
oms2_unloadModel("MonitoredThermostat")
