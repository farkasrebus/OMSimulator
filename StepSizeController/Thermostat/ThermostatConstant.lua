--[[
package.path = package.path .. ";../StepSizeController.lua"
require("StepSizeController")
--]]

-- oms2_setLoggingLevel(2)
oms2_setLogFile("ThermostatConstant.log")
oms2_setTempDirectory("./tmp")
oms2_newFMIModel("ThermostatExample")
-- instantiate FMU
oms2_addFMU("ThermostatExample","advancedThermostat.fmu","Thermostat")
oms2_addFMU("ThermostatExample","Room.fmu","Room")
oms2_addSolver("ThermostatExample", "solver", "internal")
oms2_addConnection("ThermostatExample", "Room", "solver")
oms2_addConnection("ThermostatExample", "Thermostat", "solver")
-- add connections
oms2_addConnection("ThermostatExample",
	"Thermostat:Thermostat_HeatingControlPort_set_hysteresis_intervallum_hysteresis_intervallum",
	"Room:heatingControlPort1.set_hysteresis_intervallum1.hysteresis_intervallum[1]")
oms2_addConnection("ThermostatExample",
	"Thermostat:Thermostat_HeatingControlPort_set_hysteresis_intervallum_hysteresis_intervallum1",
	"Room:heatingControlPort1.set_hysteresis_intervallum1.hysteresis_intervallum[2]")
oms2_addConnection("ThermostatExample",
	"Thermostat:Thermostat_HeatingControlPort_set_hysteresis_intervallum_hysteresis_intervallum2",
	"Room:heatingControlPort1.set_hysteresis_intervallum1.hysteresis_intervallum[3]")
oms2_addConnection("ThermostatExample",
	"Thermostat:Thermostat_TemperatureStreamPort_measured_temperature_measured_temperature",
	"Room:temperatureStreamPort1.measured_temperature1.measured_temperature[1]")
oms2_addConnection("ThermostatExample",
	"Thermostat:Thermostat_TemperatureStreamPort_measured_temperature_measured_temperature1",
	"Room:temperatureStreamPort1.measured_temperature1.measured_temperature[2]")
oms2_addConnection("ThermostatExample",
	"Thermostat:Thermostat_TemperatureStreamPort_measured_temperature_measured_temperature2",
	"Room:temperatureStreamPort1.measured_temperature1.measured_temperature[3]")
oms2_addConnection("ThermostatExample",
	"Thermostat:Thermostat_ThermostatControlPort_set_target_temperature_target_temperature",
	"Room:thermostatControlPort1.set_target_temperature1.target_temperature[1]")
oms2_addConnection("ThermostatExample",
	"Thermostat:Thermostat_ThermostatControlPort_set_target_temperature_target_temperature1",
	"Room:thermostatControlPort1.set_target_temperature1.target_temperature[2]")
oms2_addConnection("ThermostatExample",
	"Thermostat:Thermostat_ThermostatControlPort_set_target_temperature_target_temperature2",
	"Room:thermostatControlPort1.set_target_temperature1.target_temperature[3]")
oms2_addConnection("ThermostatExample",
	"Thermostat:Thermostat_HeatingControlPort_set_hysteresis_intervallum",
	"Room:heatingControlPort1.set_hysteresis_intervallum1.counter")
oms2_addConnection("ThermostatExample",
	"Thermostat:Thermostat_TemperatureStreamPort_measured_temperature",
	"Room:temperatureStreamPort1.measured_temperature1.counter")
oms2_addConnection("ThermostatExample",
	"Thermostat:Thermostat_ThermostatControlPort_set_target_temperature",
	"Room:thermostatControlPort1.set_target_temperature1.counter")
oms2_addConnection("ThermostatExample",
	"Thermostat:Thermostat_ThermostatControlPort_turn_thermostat_off",
	"Room:thermostatControlPort1.turn_thermostat_off1.counter")
oms2_addConnection("ThermostatExample",
	"Thermostat:Thermostat_ThermostatControlPort_turn_thermostat_on",
	"Room:thermostatControlPort1.turn_thermostat_on1.counter")
oms2_addConnection("ThermostatExample",
	"Room:heatingControlPort1.turn_heating_off1.counter",
	"Thermostat:Thermostat_HeatingControlPort_turn_heating_off")
oms2_addConnection("ThermostatExample",
	"Room:heatingControlPort1.turn_heating_on1.counter",
	"Thermostat:Thermostat_HeatingControlPort_turn_heating_on")
-- set result file
oms2_setResultFile("ThermostatExample", "ThermostatConstant4.mat")
-- configure simulation
oms2_setStopTime("ThermostatExample", 1000.0)
oms2_initialize("ThermostatExample")

--local x = os.clock()
oms2_setCommunicationInterval("ThermostatExample", 1.0)
oms2_stepUntil("ThermostatExample", 0.1)
oms2_setCommunicationInterval("ThermostatExample", 1.0)
oms2_simulate("ThermostatExample")
--print(string.format("elapsed time: %.2f\n", os.clock() - x))
--  terminate
oms2_unloadModel("ThermostatExample")
