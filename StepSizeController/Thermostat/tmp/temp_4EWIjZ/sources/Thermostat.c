/*----------------------------------------------------------------------------
 * File:  Thermostat.c
 *
 * UML Component Port Messages
 * Component/Module Name:  Thermostat
 *
 * your copyright statement can go here (from te_copyright.body)
 *--------------------------------------------------------------------------*/

#include "advancedThermostat_sys_types.h"
#include "advancedThermostat_sys_typesToOut.h"
#include "Thermostat.h"
#include "Thermostat_classes.h"

/*
 * Interface:  TemperatureStream
 * Required Port:  TemperatureStreamPort
 * From Provider Message:  measured_temperature
 */
void
Thermostat_TemperatureStreamPort_measured_temperature( const r_t p_measured_temperature )
{
  Thermostat_Thermostat * thermostat=0;
  /* SELECT any thermostat FROM INSTANCES OF Thermostat */
  XTUML_OAL_STMT_TRACE( 1, "SELECT any thermostat FROM INSTANCES OF Thermostat" );
  thermostat = (Thermostat_Thermostat *) Escher_SetGetAny( &pG_Thermostat_Thermostat_extent.active );
  /* ASSIGN thermostat.measured_temperature = PARAM.measured_temperature */
  XTUML_OAL_STMT_TRACE( 1, "ASSIGN thermostat.measured_temperature = PARAM.measured_temperature" );
  thermostat->measured_temperature = p_measured_temperature;
  /* GENERATE Thermostat7:update() TO thermostat */
  XTUML_OAL_STMT_TRACE( 1, "GENERATE Thermostat7:update() TO thermostat" );
  { Escher_xtUMLEvent_t * e = Escher_NewxtUMLEvent( thermostat, &Thermostat_Thermostatevent7c );
    Escher_SendEvent( e );
  }
}

/*
 * Interface:  ThermostatControl
 * Required Port:  ThermostatControlPort
 * From Provider Message:  set_target_temperature
 */
void
Thermostat_ThermostatControlPort_set_target_temperature( const r_t p_target_temperature )
{
  Thermostat_Thermostat * thermostat=0;
  /* SELECT any thermostat FROM INSTANCES OF Thermostat */
  XTUML_OAL_STMT_TRACE( 1, "SELECT any thermostat FROM INSTANCES OF Thermostat" );
  thermostat = (Thermostat_Thermostat *) Escher_SetGetAny( &pG_Thermostat_Thermostat_extent.active );
  /* ASSIGN thermostat.target_temperature = PARAM.target_temperature */
  XTUML_OAL_STMT_TRACE( 1, "ASSIGN thermostat.target_temperature = PARAM.target_temperature" );
  thermostat->target_temperature = p_target_temperature;
  /* GENERATE Thermostat7:update() TO thermostat */
  XTUML_OAL_STMT_TRACE( 1, "GENERATE Thermostat7:update() TO thermostat" );
  { Escher_xtUMLEvent_t * e = Escher_NewxtUMLEvent( thermostat, &Thermostat_Thermostatevent7c );
    Escher_SendEvent( e );
  }
}

/*
 * Interface:  ThermostatControl
 * Required Port:  ThermostatControlPort
 * From Provider Message:  turn_thermostat_off
 */
void
Thermostat_ThermostatControlPort_turn_thermostat_off()
{
  Thermostat_Thermostat * thermostat=0;
  /* SELECT any thermostat FROM INSTANCES OF Thermostat */
  XTUML_OAL_STMT_TRACE( 1, "SELECT any thermostat FROM INSTANCES OF Thermostat" );
  thermostat = (Thermostat_Thermostat *) Escher_SetGetAny( &pG_Thermostat_Thermostat_extent.active );
  /* GENERATE Thermostat2:turn_off() TO thermostat */
  XTUML_OAL_STMT_TRACE( 1, "GENERATE Thermostat2:turn_off() TO thermostat" );
  { Escher_xtUMLEvent_t * e = Escher_NewxtUMLEvent( thermostat, &Thermostat_Thermostatevent2c );
    Escher_SendEvent( e );
  }
}

/*
 * Interface:  ThermostatControl
 * Required Port:  ThermostatControlPort
 * From Provider Message:  turn_thermostat_on
 */
void
Thermostat_ThermostatControlPort_turn_thermostat_on()
{
  Thermostat_Thermostat * thermostat=0;
  /* SELECT any thermostat FROM INSTANCES OF Thermostat */
  XTUML_OAL_STMT_TRACE( 1, "SELECT any thermostat FROM INSTANCES OF Thermostat" );
  thermostat = (Thermostat_Thermostat *) Escher_SetGetAny( &pG_Thermostat_Thermostat_extent.active );
  /* GENERATE Thermostat1:turn_on() TO thermostat */
  XTUML_OAL_STMT_TRACE( 1, "GENERATE Thermostat1:turn_on() TO thermostat" );
  { Escher_xtUMLEvent_t * e = Escher_NewxtUMLEvent( thermostat, &Thermostat_Thermostatevent1c );
    Escher_SendEvent( e );
  }
}

/*
 * Interface:  HeatingControl
 * Provided Port:  HeatingControlPort
 * To Provider Message:  set_hysteresis_intervallum
 */
void
Thermostat_HeatingControlPort_set_hysteresis_intervallum( const r_t p_hysteresis_intervallum )
{
  Thermostat_Thermostat * thermostat=0;
  /* SELECT any thermostat FROM INSTANCES OF Thermostat */
  XTUML_OAL_STMT_TRACE( 1, "SELECT any thermostat FROM INSTANCES OF Thermostat" );
  thermostat = (Thermostat_Thermostat *) Escher_SetGetAny( &pG_Thermostat_Thermostat_extent.active );
  /* ASSIGN thermostat.hysteresis = PARAM.hysteresis_intervallum */
  XTUML_OAL_STMT_TRACE( 1, "ASSIGN thermostat.hysteresis = PARAM.hysteresis_intervallum" );
  thermostat->hysteresis = p_hysteresis_intervallum;
  /* GENERATE Thermostat7:update() TO thermostat */
  XTUML_OAL_STMT_TRACE( 1, "GENERATE Thermostat7:update() TO thermostat" );
  { Escher_xtUMLEvent_t * e = Escher_NewxtUMLEvent( thermostat, &Thermostat_Thermostatevent7c );
    Escher_SendEvent( e );
  }
}

/*
 * Interface:  HeatingControl
 * Provided Port:  HeatingControlPort
 * From Provider Message:  turn_heating_off
 */
void
Thermostat_HeatingControlPort_turn_heating_off()
{
  setThermostat_HeatingControlPort_turn_heating_offSignal();
}

/*
 * Interface:  HeatingControl
 * Provided Port:  HeatingControlPort
 * From Provider Message:  turn_heating_on
 */
void
Thermostat_HeatingControlPort_turn_heating_on()
{
  setThermostat_HeatingControlPort_turn_heating_onSignal();
}
/*
 * UML Domain Functions (Synchronous Services)
 */

/*
 * Domain Function:  create
 */
void
Thermostat_create()
{
  Thermostat_HeatingController * heating_controller;Thermostat_Thermostat * thermostat;
  /* CREATE OBJECT INSTANCE thermostat OF Thermostat */
  XTUML_OAL_STMT_TRACE( 1, "CREATE OBJECT INSTANCE thermostat OF Thermostat" );
  thermostat = (Thermostat_Thermostat *) Escher_CreateInstance( Thermostat_DOMAIN_ID, Thermostat_Thermostat_CLASS_NUMBER );
  /* ASSIGN thermostat.target_temperature = 22.5 */
  XTUML_OAL_STMT_TRACE( 1, "ASSIGN thermostat.target_temperature = 22.5" );
  thermostat->target_temperature = 22.5;
  /* ASSIGN thermostat.measured_temperature = 20 */
  XTUML_OAL_STMT_TRACE( 1, "ASSIGN thermostat.measured_temperature = 20" );
  thermostat->measured_temperature = 20;
  /* ASSIGN thermostat.hysteresis = 2 */
  XTUML_OAL_STMT_TRACE( 1, "ASSIGN thermostat.hysteresis = 2" );
  thermostat->hysteresis = 2;
  /* CREATE OBJECT INSTANCE heating_controller OF HeatingController */
  XTUML_OAL_STMT_TRACE( 1, "CREATE OBJECT INSTANCE heating_controller OF HeatingController" );
  heating_controller = (Thermostat_HeatingController *) Escher_CreateInstance( Thermostat_DOMAIN_ID, Thermostat_HeatingController_CLASS_NUMBER );
}
/* xtUML class info (collections, sizes, etc.) */
Escher_Extent_t * const Thermostat_class_info[ Thermostat_MAX_CLASS_NUMBERS ] = {
  &pG_Thermostat_Thermostat_extent,
  &pG_Thermostat_HeatingController_extent
};

/*
 * Array of pointers to the class event dispatcher method.
 * Index is the (model compiler enumerated) number of the state model.
 */
const EventTaker_t Thermostat_EventDispatcher[ Thermostat_STATE_MODELS ] = {
  Thermostat_class_dispatchers
};

void Thermostat_execute_initialization()
{
  /*
   * Initialization Function:  create
   * Component:  Thermostat
   */
  Thermostat_create();

}

void Thermostat_Terminate()
{


			Thermostat_Thermostat * f=0;Escher_ObjectSet_s package_set_space={0}; Escher_ObjectSet_s * package_set = &package_set_space;
		/* SELECT many package_set FROM INSTANCES OF Thermostat */
		XTUML_OAL_STMT_TRACE( 1, "SELECT many package_set FROM INSTANCES OF Thermostat" );
		Escher_CopySet( package_set, &pG_Thermostat_Thermostat_extent.active );
		/* FOR EACH f IN package_set */
		XTUML_OAL_STMT_TRACE( 1, "FOR EACH f IN package_set" );
		{ Escher_Iterator_s iterf;
		Thermostat_Thermostat * iif;
		Escher_IteratorReset( &iterf, package_set );
		while ( (iif = (Thermostat_Thermostat *)Escher_IteratorNext( &iterf )) != 0 ) {
			f = iif; {
		  Escher_DeleteInstance((Escher_iHandle_t) f,Thermostat_DOMAIN_ID, Thermostat_Thermostat_CLASS_NUMBER);			 
    }}}
    Escher_ClearSet( package_set );

}
