oms2_setLogFile("TrafficLightScenario.log")
oms2_newFMIModel("ThermostatExample")
oms2_setTempDirectory("./tmp")
oms2_addFMU("ThermostatExample", "advancedThermostat.fmu", "Thermostat")
oms2_setResultFile("ThermostatExample", "Thermostat.mat")

oms2_initialize("ThermostatExample")
offint=oms2_getInteger("ThermostatExample.Thermostat:Thermostat_HeatingControlPort_turn_heating_off")
print(offint)
oms2_terminate("ThermostatExample")
oms2_unloadModel("ThermostatExample")