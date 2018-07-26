package.path = package.path .. ";../StepSizeController.lua"

require("StepSizeController")

oms2_setLogFile("ThermostatSSC.log")
oms2_setTempDirectory("./tmp")
oms2_newFMIModel("ThermostatExample")

oms2_addFMU("ThermostatExample","advancedThermostat.fmu","Thermostat")
---[[
oms2_addFMU("ThermostatExample","Room.fmu","Room")
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
	"Thermostat:Thermostat_HeatingControlPort_turn_heating_on")--]]

oms2_setResultFile("ThermostatExample", "ThermostatSSC.mat")

oms2_setStopTime("ThermostatExample", 1000.0)
oms2_setCommunicationInterval("ThermostatExample", 10.0)
oms2_initialize("ThermostatExample")

bm=BandModel:create()
bm:addBand(18.0,19.02,0.1)
bm:addBand(19.02,19.1,1.0)
bm:addBand(19.1,22.0,10.0)

sm=SensitivityModel:create()
sm.zeroCrossings["ThermostatExample.Room:temperatureStreamPort1.measured_temperature1.measured_temperature[1]"]=bm

local x = os.clock()
oms2_simulateWithASSC("ThermostatExample",10.0,sm,0.1,1000.0)
print(string.format("elapsed time: %.2f\n", os.clock() - x))
oms2_unloadModel("ThermostatExample")
