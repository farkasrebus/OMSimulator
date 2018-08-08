#include "fmuTemplate.h"
#include "Thermostat.h"

fmi2Integer Thermostat_ThermostatControlPort_turn_thermostat_off_triggered;
fmi2Integer Thermostat_TemperatureStreamPort_measured_temperature_triggered;
fmi2Integer Thermostat_ThermostatControlPort_set_target_temperature_triggered;
fmi2Integer Thermostat_HeatingControlPort_set_hysteresis_intervallum_triggered;
fmi2Integer Thermostat_HeatingControlPort_turn_heating_on_triggered;
fmi2Integer Thermostat_HeatingControlPort_turn_heating_off_triggered;
fmi2Integer Thermostat_ThermostatControlPort_turn_thermostat_on_triggered;

fmi2Real Thermostat_ThermostatControlPort_set_target_temperature_target_temperature_triggered[5];
fmi2Real Thermostat_ThermostatControlPort_set_target_temperature_target_temperature_previous_triggered[5];
fmi2Real Thermostat_TemperatureStreamPort_measured_temperature_measured_temperature_triggered[5];
fmi2Real Thermostat_TemperatureStreamPort_measured_temperature_measured_temperature_previous_triggered[5];
fmi2Real Thermostat_HeatingControlPort_set_hysteresis_intervallum_hysteresis_intervallum_triggered[5];
fmi2Real Thermostat_HeatingControlPort_set_hysteresis_intervallum_hysteresis_intervallum_previous_triggered[5];


void setThermostat_ThermostatControlPort_turn_thermostat_off(fmi2Integer value){
	Thermostat_ThermostatControlPort_turn_thermostat_off_triggered = value;
}
void setThermostat_TemperatureStreamPort_measured_temperature(fmi2Integer value){
	Thermostat_TemperatureStreamPort_measured_temperature_triggered = value;
}
void setThermostat_ThermostatControlPort_set_target_temperature(fmi2Integer value){
	Thermostat_ThermostatControlPort_set_target_temperature_triggered = value;
}
void setThermostat_HeatingControlPort_set_hysteresis_intervallum(fmi2Integer value){
	Thermostat_HeatingControlPort_set_hysteresis_intervallum_triggered = value;
}
void setThermostat_HeatingControlPort_turn_heating_on(fmi2Integer value){
	Thermostat_HeatingControlPort_turn_heating_on_triggered = value;
}
void setThermostat_HeatingControlPort_turn_heating_off(fmi2Integer value){
	Thermostat_HeatingControlPort_turn_heating_off_triggered = value;
}
void setThermostat_ThermostatControlPort_turn_thermostat_on(fmi2Integer value){
	Thermostat_ThermostatControlPort_turn_thermostat_on_triggered = value;
}

void setThermostat_HeatingControlPort_set_hysteresis_intervallum_hysteresis_intervallum(fmi2Real value, int index){
	Thermostat_HeatingControlPort_set_hysteresis_intervallum_hysteresis_intervallum_triggered[index] = value;
}
void setThermostat_TemperatureStreamPort_measured_temperature_measured_temperature(fmi2Real value, int index){
	Thermostat_TemperatureStreamPort_measured_temperature_measured_temperature_triggered[index] = value;
}
void setThermostat_ThermostatControlPort_set_target_temperature_target_temperature(fmi2Real value, int index){
	Thermostat_ThermostatControlPort_set_target_temperature_target_temperature_triggered[index] = value;
}

fmi2Integer getThermostat_ThermostatControlPort_turn_thermostat_off(){
	return Thermostat_ThermostatControlPort_turn_thermostat_off_triggered;
}

fmi2Integer getThermostat_TemperatureStreamPort_measured_temperature(){
	return Thermostat_TemperatureStreamPort_measured_temperature_triggered;
}

fmi2Integer getThermostat_ThermostatControlPort_set_target_temperature(){
	return Thermostat_ThermostatControlPort_set_target_temperature_triggered;
}

fmi2Integer getThermostat_HeatingControlPort_set_hysteresis_intervallum(){
	return Thermostat_HeatingControlPort_set_hysteresis_intervallum_triggered;
}

fmi2Integer getThermostat_HeatingControlPort_turn_heating_on(){
	return Thermostat_HeatingControlPort_turn_heating_on_triggered;
}

fmi2Integer getThermostat_HeatingControlPort_turn_heating_off(){
	return Thermostat_HeatingControlPort_turn_heating_off_triggered;
}

fmi2Integer getThermostat_ThermostatControlPort_turn_thermostat_on(){
	return Thermostat_ThermostatControlPort_turn_thermostat_on_triggered;
}


fmi2Real getThermostat_HeatingControlPort_set_hysteresis_intervallum_hysteresis_intervallum(int index){
	return Thermostat_HeatingControlPort_set_hysteresis_intervallum_hysteresis_intervallum_triggered[index];
}
fmi2Real getThermostat_TemperatureStreamPort_measured_temperature_measured_temperature(int index){
	return Thermostat_TemperatureStreamPort_measured_temperature_measured_temperature_triggered[index];
}
fmi2Real getThermostat_ThermostatControlPort_set_target_temperature_target_temperature(int index){
	return Thermostat_ThermostatControlPort_set_target_temperature_target_temperature_triggered[index];
}

void setThermostat_HeatingControlPort_turn_heating_onSignal(){
	int index = getThermostat_HeatingControlPort_turn_heating_on();
	setThermostat_HeatingControlPort_turn_heating_on(index + 1);
}

void setThermostat_HeatingControlPort_turn_heating_offSignal(){
	int index = getThermostat_HeatingControlPort_turn_heating_off();
	setThermostat_HeatingControlPort_turn_heating_off(index + 1);
}


void unset_every_variable(){
	Thermostat_HeatingControlPort_turn_heating_on_triggered = 0;
	Thermostat_HeatingControlPort_turn_heating_off_triggered = 0;
}

fmi2Boolean Thermostat_TemperatureStreamPort_measured_temperatureIsChanged(int index){
	fmi2Boolean exp1 = getThermostat_TemperatureStreamPort_measured_temperature() > index;
	fmi2Boolean exp2 = getThermostat_TemperatureStreamPort_measured_temperature_measured_temperature(index) != Thermostat_TemperatureStreamPort_measured_temperature_measured_temperature_previous_triggered[index];
	Thermostat_TemperatureStreamPort_measured_temperature_measured_temperature_previous_triggered[index] = getThermostat_TemperatureStreamPort_measured_temperature_measured_temperature(index);
	
	return exp1 || exp2;
}
fmi2Boolean Thermostat_ThermostatControlPort_turn_thermostat_onIsChanged(int index){
	fmi2Boolean exp1 = getThermostat_ThermostatControlPort_turn_thermostat_on() > index;
	
	return exp1;
}
fmi2Boolean Thermostat_ThermostatControlPort_set_target_temperatureIsChanged(int index){
	fmi2Boolean exp1 = getThermostat_ThermostatControlPort_set_target_temperature() > index;
	fmi2Boolean exp2 = getThermostat_ThermostatControlPort_set_target_temperature_target_temperature(index) != Thermostat_ThermostatControlPort_set_target_temperature_target_temperature_previous_triggered[index];
	Thermostat_ThermostatControlPort_set_target_temperature_target_temperature_previous_triggered[index] = getThermostat_ThermostatControlPort_set_target_temperature_target_temperature(index);
	
	return exp1 || exp2;
}
fmi2Boolean Thermostat_ThermostatControlPort_turn_thermostat_offIsChanged(int index){
	fmi2Boolean exp1 = getThermostat_ThermostatControlPort_turn_thermostat_off() > index;
	
	return exp1;
}
fmi2Boolean Thermostat_HeatingControlPort_set_hysteresis_intervallumIsChanged(int index){
	fmi2Boolean exp1 = getThermostat_HeatingControlPort_set_hysteresis_intervallum() > index;
	fmi2Boolean exp2 = getThermostat_HeatingControlPort_set_hysteresis_intervallum_hysteresis_intervallum(index) != Thermostat_HeatingControlPort_set_hysteresis_intervallum_hysteresis_intervallum_previous_triggered[index];
	Thermostat_HeatingControlPort_set_hysteresis_intervallum_hysteresis_intervallum_previous_triggered[index] = getThermostat_HeatingControlPort_set_hysteresis_intervallum_hysteresis_intervallum(index);
	
	return exp1 || exp2;
}


void fire_all_triggered_event(){
	int index;
	for(index = 0; index < 5; index++){
		if(Thermostat_TemperatureStreamPort_measured_temperatureIsChanged(index)){
			Thermostat_TemperatureStreamPort_measured_temperature(getThermostat_TemperatureStreamPort_measured_temperature_measured_temperature(index)
			);
		}
	}
	for(index = 0; index < 5; index++){
		if(Thermostat_ThermostatControlPort_turn_thermostat_onIsChanged(index)){
			Thermostat_ThermostatControlPort_turn_thermostat_on();
		}
	}
	for(index = 0; index < 5; index++){
		if(Thermostat_ThermostatControlPort_set_target_temperatureIsChanged(index)){
			Thermostat_ThermostatControlPort_set_target_temperature(getThermostat_ThermostatControlPort_set_target_temperature_target_temperature(index)
			);
		}
	}
	for(index = 0; index < 5; index++){
		if(Thermostat_ThermostatControlPort_turn_thermostat_offIsChanged(index)){
			Thermostat_ThermostatControlPort_turn_thermostat_off();
		}
	}
	for(index = 0; index < 5; index++){
		if(Thermostat_HeatingControlPort_set_hysteresis_intervallumIsChanged(index)){
			Thermostat_HeatingControlPort_set_hysteresis_intervallum(getThermostat_HeatingControlPort_set_hysteresis_intervallum_hysteresis_intervallum(index)
			);
		}
	}
}
