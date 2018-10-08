#ifndef ADVANCED_THERMOSTAT_SYS_TYPES_TO_OUT
#define ADVANCED_THERMOSTAT_SYS_TYPES_TO_OUT

#include "fmuTemplate.h"

void setThermostat_ThermostatControlPort_turn_thermostat_off(fmi2Integer value);
void setThermostat_TemperatureStreamPort_measured_temperature(fmi2Integer value);
void setThermostat_ThermostatControlPort_set_target_temperature(fmi2Integer value);
void setThermostat_HeatingControlPort_set_hysteresis_intervallum(fmi2Integer value);
void setThermostat_HeatingControlPort_turn_heating_on(fmi2Integer value);
void setThermostat_HeatingControlPort_turn_heating_off(fmi2Integer value);
void setThermostat_ThermostatControlPort_turn_thermostat_on(fmi2Integer value);

void setThermostat_HeatingControlPort_set_hysteresis_intervallum_hysteresis_intervallum(fmi2Real value, int index);
void setThermostat_TemperatureStreamPort_measured_temperature_measured_temperature(fmi2Real value, int index);
void setThermostat_ThermostatControlPort_set_target_temperature_target_temperature(fmi2Real value, int index);

fmi2Integer getThermostat_ThermostatControlPort_turn_thermostat_off();
fmi2Integer getThermostat_TemperatureStreamPort_measured_temperature();
fmi2Integer getThermostat_ThermostatControlPort_set_target_temperature();
fmi2Integer getThermostat_HeatingControlPort_set_hysteresis_intervallum();
fmi2Integer getThermostat_HeatingControlPort_turn_heating_on();
fmi2Integer getThermostat_HeatingControlPort_turn_heating_off();
fmi2Integer getThermostat_ThermostatControlPort_turn_thermostat_on();

fmi2Real getThermostat_HeatingControlPort_set_hysteresis_intervallum_hysteresis_intervallum(int index);
fmi2Real getThermostat_TemperatureStreamPort_measured_temperature_measured_temperature(int index);
fmi2Real getThermostat_ThermostatControlPort_set_target_temperature_target_temperature(int index);

void setThermostat_HeatingControlPort_turn_heating_onSignal();
void setThermostat_HeatingControlPort_turn_heating_offSignal();

void unset_every_variable();

void fire_all_triggered_event();

#endif // ADVANCED_THERMOSTAT_SYS_TYPES_TO_OUT