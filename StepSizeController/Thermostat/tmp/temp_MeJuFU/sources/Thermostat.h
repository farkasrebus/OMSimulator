/*----------------------------------------------------------------------------
 * File:  Thermostat.h
 *
 * UML Component (Module) Declaration (Operations and Signals)
 *
 * your copyright statement can go here (from te_copyright.body)
 *--------------------------------------------------------------------------*/

#ifndef THERMOSTAT_H
#define THERMOSTAT_H
#ifdef	__cplusplus
extern	"C"	{
#endif

#include "advancedThermostat_sys_types.h"
void Thermostat_TemperatureStreamPort_measured_temperature( const r_t );
void Thermostat_ThermostatControlPort_set_target_temperature( const r_t );
void Thermostat_ThermostatControlPort_turn_thermostat_off( void );
void Thermostat_ThermostatControlPort_turn_thermostat_on( void );
void Thermostat_HeatingControlPort_set_hysteresis_intervallum( const r_t );
void Thermostat_HeatingControlPort_turn_heating_off( void );
void Thermostat_HeatingControlPort_turn_heating_on( void );

#ifdef	__cplusplus
}
#endif
#endif  /* THERMOSTAT_H */
