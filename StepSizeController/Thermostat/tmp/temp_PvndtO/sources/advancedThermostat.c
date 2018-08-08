// define class name and unique id
#define MODEL_IDENTIFIER advancedThermostat
#define MODEL_GUID "{51ff18ff-0176-4f26-bfc2-69f8fb635652}"

// include fmu header files, typedefs and macros
#include "fmuTemplate.h"
#include "advancedThermostat_sys_main.h"
#include "advancedThermostat_sys_typesToOut.h"


// STL
#include <assert.h>
#include <stdio.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

void setStartValues(ModelInstance *comp);
void setDefaultStartValues(ModelInstance *comp);
void eventUpdate(ModelInstance *comp, fmi2EventInfo *eventInfo, int eventUpdate);
fmi2Real getReal(ModelInstance *comp, const fmi2ValueReference vr);
fmi2Status setReal(ModelInstance *comp, const fmi2ValueReference vr, const fmi2Real value);
fmi2Integer getInteger(ModelInstance *comp, const fmi2ValueReference vr);
fmi2Status setInteger(ModelInstance *comp, const fmi2ValueReference vr, const fmi2Integer value);
fmi2Boolean getBoolean(ModelInstance *comp, const fmi2ValueReference vr);
fmi2Status setBoolean(ModelInstance *comp, const fmi2ValueReference vr, const fmi2Boolean value);
fmi2String getString(ModelInstance *comp, const fmi2ValueReference vr);
fmi2Status setExternalFunction(ModelInstance *c, const fmi2ValueReference vr, const void *value);

// define model size
#define NUMBER_OF_STATES 0
#define NUMBER_OF_EVENT_INDICATORS 0
#define NUMBER_OF_BOOLEANS 0
#define NUMBER_OF_INTEGERS 7
#define NUMBER_OF_REALS 15
#define NUMBER_OF_STRINGS 0
#define NUMBER_OF_EXTERNALFUNCTIONS 0

// define variable data for model
#define Thermostat_HeatingControlPort_turn_heating_offDefine 0
#define Thermostat_TemperatureStreamPort_measured_temperature_measured_temperature2Define 2
#define Thermostat_HeatingControlPort_set_hysteresis_intervallumDefine 1
#define Thermostat_ThermostatControlPort_turn_thermostat_onDefine 4
#define Thermostat_ThermostatControlPort_set_target_temperature_target_temperature2Define 5
#define Thermostat_ThermostatControlPort_set_target_temperatureDefine 6
#define Thermostat_HeatingControlPort_set_hysteresis_intervallum_hysteresis_intervallumDefine 6
#define Thermostat_ThermostatControlPort_turn_thermostat_offDefine 2
#define Thermostat_HeatingControlPort_set_hysteresis_intervallum_hysteresis_intervallum2Define 8
#define Thermostat_TemperatureStreamPort_measured_temperature_measured_temperatureDefine 0
#define Thermostat_ThermostatControlPort_set_target_temperature_target_temperatureDefine 3
#define Thermostat_ThermostatControlPort_set_target_temperature_target_temperature1Define 4
#define Thermostat_HeatingControlPort_turn_heating_onDefine 5
#define Thermostat_TemperatureStreamPort_measured_temperatureDefine 3
#define Thermostat_TemperatureStreamPort_measured_temperature_measured_temperature1Define 1
#define Thermostat_HeatingControlPort_set_hysteresis_intervallum_hysteresis_intervallum1Define 7

// define initial state vector as vector of value references
#define STATES {}
#define STATESDERIVATIVES {}

void calculateValues(ModelInstance *comp) {}

// Set values for all variables that define a start value
void setDefaultStartValues(ModelInstance *comp) {}
// Set values for all variables that define a start value
void setStartValues(ModelInstance *comp) {
	advancedThermostat_sys_mainRunner();
}
// Used to set the next time event, if any.
void eventUpdate(ModelInstance *comp, fmi2EventInfo *eventInfo, int timeEvent) {}

fmi2Real getReal(ModelInstance *comp, const fmi2ValueReference vr) {
	switch (vr) {
		default:
			return 0;
	}
}

fmi2Integer getInteger(ModelInstance *comp, const fmi2ValueReference vr) {
	switch (vr) {
		case Thermostat_HeatingControlPort_turn_heating_onDefine:
			return getThermostat_HeatingControlPort_turn_heating_on();
			break;
		case Thermostat_HeatingControlPort_turn_heating_offDefine:
			return getThermostat_HeatingControlPort_turn_heating_off();
			break;
		default:
			return 0;
	}
}

fmi2Boolean getBoolean(ModelInstance *comp, const fmi2ValueReference vr) {
	switch (vr) {
		default:
			return fmi2False;
	}
}

fmi2String getString(ModelInstance *comp, const fmi2ValueReference vr) {
	switch (vr) {
		default:
			return "";
	}
}


fmi2Status setReal(ModelInstance *comp, const fmi2ValueReference vr, const fmi2Real value) {
	switch (vr) {
		case Thermostat_ThermostatControlPort_set_target_temperature_target_temperature1Define:
			setThermostat_ThermostatControlPort_set_target_temperature_target_temperature(value, 1);
			break;
		case Thermostat_HeatingControlPort_set_hysteresis_intervallum_hysteresis_intervallum2Define:
			setThermostat_HeatingControlPort_set_hysteresis_intervallum_hysteresis_intervallum(value, 2);
			break;
		case Thermostat_TemperatureStreamPort_measured_temperature_measured_temperature2Define:
			setThermostat_TemperatureStreamPort_measured_temperature_measured_temperature(value, 2);
			break;
		case Thermostat_TemperatureStreamPort_measured_temperature_measured_temperatureDefine:
			setThermostat_TemperatureStreamPort_measured_temperature_measured_temperature(value, 0);
			break;
		case Thermostat_HeatingControlPort_set_hysteresis_intervallum_hysteresis_intervallum1Define:
			setThermostat_HeatingControlPort_set_hysteresis_intervallum_hysteresis_intervallum(value, 1);
			break;
		case Thermostat_TemperatureStreamPort_measured_temperature_measured_temperature1Define:
			setThermostat_TemperatureStreamPort_measured_temperature_measured_temperature(value, 1);
			break;
		case Thermostat_ThermostatControlPort_set_target_temperature_target_temperatureDefine:
			setThermostat_ThermostatControlPort_set_target_temperature_target_temperature(value, 0);
			break;
		case Thermostat_ThermostatControlPort_set_target_temperature_target_temperature2Define:
			setThermostat_ThermostatControlPort_set_target_temperature_target_temperature(value, 2);
			break;
		case Thermostat_HeatingControlPort_set_hysteresis_intervallum_hysteresis_intervallumDefine:
			setThermostat_HeatingControlPort_set_hysteresis_intervallum_hysteresis_intervallum(value, 0);
			break;
		default:
			return fmi2Error;
	}
	return fmi2OK;
}
fmi2Status setInteger(ModelInstance *comp, const fmi2ValueReference vr, const fmi2Integer value) {
	switch (vr) {
		case Thermostat_TemperatureStreamPort_measured_temperatureDefine:
			setThermostat_TemperatureStreamPort_measured_temperature(value);
			break;
		case Thermostat_ThermostatControlPort_turn_thermostat_onDefine:
			setThermostat_ThermostatControlPort_turn_thermostat_on(value);
			break;
		case Thermostat_ThermostatControlPort_set_target_temperatureDefine:
			setThermostat_ThermostatControlPort_set_target_temperature(value);
			break;
		case Thermostat_ThermostatControlPort_turn_thermostat_offDefine:
			setThermostat_ThermostatControlPort_turn_thermostat_off(value);
			break;
		case Thermostat_HeatingControlPort_set_hysteresis_intervallumDefine:
			setThermostat_HeatingControlPort_set_hysteresis_intervallum(value);
			break;
		default:
			return fmi2Error;
	}
	return fmi2OK;
}
fmi2Status setBoolean(ModelInstance *comp, const fmi2ValueReference vr, const fmi2Boolean value) {
	switch (vr) {
		default:
			return fmi2Error;
	}
	return fmi2OK;
}

fmi2Status setExternalFunction(ModelInstance *c, const fmi2ValueReference vr, const void *value) {
	switch (vr) {
	default:
		return fmi2Error;
	}
	return fmi2OK;
}


// include code that implements the FMI based on the above definitions
#include "fmuTemplate.c"

#ifdef __cplusplus
}
#endif
