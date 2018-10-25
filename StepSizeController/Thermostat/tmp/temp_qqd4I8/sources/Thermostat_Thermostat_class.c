/*----------------------------------------------------------------------------
 * File:  Thermostat_Thermostat_class.c
 *
 * Class:       Thermostat  (Thermostat)
 * Component:   Thermostat
 *
 * your copyright statement can go here (from te_copyright.body)
 *--------------------------------------------------------------------------*/

#include "advancedThermostat_sys_types.h"
#include "Thermostat_classes.h"


/*
 * Statically allocate space for the instance population for this class.
 * Allocate space for the class instance and its attribute values.
 * Depending upon the collection scheme, allocate containoids (collection
 * nodes) for gathering instances into free and active extents.
 */
static Escher_SetElement_s Thermostat_Thermostat_container[ Thermostat_Thermostat_MAX_EXTENT_SIZE ];
static Thermostat_Thermostat Thermostat_Thermostat_instances[ Thermostat_Thermostat_MAX_EXTENT_SIZE ];
Escher_Extent_t pG_Thermostat_Thermostat_extent = {
  {0}, {0}, &Thermostat_Thermostat_container[ 0 ],
  (Escher_iHandle_t) &Thermostat_Thermostat_instances,
  sizeof( Thermostat_Thermostat ), Thermostat_Thermostat_STATE_1, Thermostat_Thermostat_MAX_EXTENT_SIZE
  };
/*----------------------------------------------------------------------------
 * State and transition action implementations for the following class:
 *
 * Class:      Thermostat  (Thermostat)
 * Component:  Thermostat
 *--------------------------------------------------------------------------*/

/*
 * State 1:  [thermostat_off]
 */
static void Thermostat_Thermostat_act1( Thermostat_Thermostat *, const Escher_xtUMLEvent_t * const );
static void
Thermostat_Thermostat_act1( Thermostat_Thermostat * self, const Escher_xtUMLEvent_t * const event )
{
  Thermostat_HeatingController * heating_controller=0;
  /* SELECT any heating_controller FROM INSTANCES OF HeatingController */
  XTUML_OAL_STMT_TRACE( 1, "SELECT any heating_controller FROM INSTANCES OF HeatingController" );
  heating_controller = (Thermostat_HeatingController *) Escher_SetGetAny( &pG_Thermostat_HeatingController_extent.active );
  /* GENERATE HeatingController1:turn_off_request() TO heating_controller */
  XTUML_OAL_STMT_TRACE( 1, "GENERATE HeatingController1:turn_off_request() TO heating_controller" );
  { Escher_xtUMLEvent_t * e = Escher_NewxtUMLEvent( heating_controller, &Thermostat_HeatingControllerevent1c );
    Escher_SendEvent( e );
  }
}

/*
 * State 2:  [updating]
 */
static void Thermostat_Thermostat_act2( Thermostat_Thermostat *, const Escher_xtUMLEvent_t * const );
static void
Thermostat_Thermostat_act2( Thermostat_Thermostat * self, const Escher_xtUMLEvent_t * const event )
{
  /* IF ( ( self.measured_temperature > ( self.target_temperature + self.hysteresis ) ) ) */
  XTUML_OAL_STMT_TRACE( 1, "IF ( ( self.measured_temperature > ( self.target_temperature + self.hysteresis ) ) )" );
  if ( ( self->measured_temperature > ( self->target_temperature + self->hysteresis ) ) ) {
    /* GENERATE Thermostat6:should_turn_off() TO self */
    XTUML_OAL_STMT_TRACE( 2, "GENERATE Thermostat6:should_turn_off() TO self" );
    { Escher_xtUMLEvent_t * e = Escher_NewxtUMLEvent( self, &Thermostat_Thermostatevent6c );
      Escher_SendSelfEvent( e );
    }
  }
  else if ( ( self->measured_temperature < ( self->target_temperature - self->hysteresis ) ) ) {
    /* GENERATE Thermostat5:should_turn_on() TO self */
    XTUML_OAL_STMT_TRACE( 2, "GENERATE Thermostat5:should_turn_on() TO self" );
    { Escher_xtUMLEvent_t * e = Escher_NewxtUMLEvent( self, &Thermostat_Thermostatevent5c );
      Escher_SendSelfEvent( e );
    }
  }
  else {
    /* GENERATE Thermostat8:should_wait() TO self */
    XTUML_OAL_STMT_TRACE( 2, "GENERATE Thermostat8:should_wait() TO self" );
    { Escher_xtUMLEvent_t * e = Escher_NewxtUMLEvent( self, &Thermostat_Thermostatevent8c );
      Escher_SendSelfEvent( e );
    }
  }
}

/*
 * State 3:  [heating_off]
 */
static void Thermostat_Thermostat_act3( Thermostat_Thermostat *, const Escher_xtUMLEvent_t * const );
static void
Thermostat_Thermostat_act3( Thermostat_Thermostat * self, const Escher_xtUMLEvent_t * const event )
{
  Thermostat_HeatingController * heating_controller=0;
  /* SELECT any heating_controller FROM INSTANCES OF HeatingController */
  XTUML_OAL_STMT_TRACE( 1, "SELECT any heating_controller FROM INSTANCES OF HeatingController" );
  heating_controller = (Thermostat_HeatingController *) Escher_SetGetAny( &pG_Thermostat_HeatingController_extent.active );
  /* GENERATE HeatingController1:turn_off_request() TO heating_controller */
  XTUML_OAL_STMT_TRACE( 1, "GENERATE HeatingController1:turn_off_request() TO heating_controller" );
  { Escher_xtUMLEvent_t * e = Escher_NewxtUMLEvent( heating_controller, &Thermostat_HeatingControllerevent1c );
    Escher_SendEvent( e );
  }
}

/*
 * State 4:  [heating_on]
 */
static void Thermostat_Thermostat_act4( Thermostat_Thermostat *, const Escher_xtUMLEvent_t * const );
static void
Thermostat_Thermostat_act4( Thermostat_Thermostat * self, const Escher_xtUMLEvent_t * const event )
{
  Thermostat_HeatingController * heating_controller=0;
  /* SELECT any heating_controller FROM INSTANCES OF HeatingController */
  XTUML_OAL_STMT_TRACE( 1, "SELECT any heating_controller FROM INSTANCES OF HeatingController" );
  heating_controller = (Thermostat_HeatingController *) Escher_SetGetAny( &pG_Thermostat_HeatingController_extent.active );
  /* GENERATE HeatingController2:turn_on_request() TO heating_controller */
  XTUML_OAL_STMT_TRACE( 1, "GENERATE HeatingController2:turn_on_request() TO heating_controller" );
  { Escher_xtUMLEvent_t * e = Escher_NewxtUMLEvent( heating_controller, &Thermostat_HeatingControllerevent2c );
    Escher_SendEvent( e );
  }
}

/*
 * State 5:  [hysteresis]
 */
static void Thermostat_Thermostat_act5( Thermostat_Thermostat *, const Escher_xtUMLEvent_t * const );
static void
Thermostat_Thermostat_act5( Thermostat_Thermostat * self, const Escher_xtUMLEvent_t * const event )
{
}

const Escher_xtUMLEventConstant_t Thermostat_Thermostatevent1c = {
  Thermostat_DOMAIN_ID, Thermostat_Thermostat_CLASS_NUMBER, THERMOSTAT_THERMOSTATEVENT1NUM,
  ESCHER_IS_INSTANCE_EVENT };
const Escher_xtUMLEventConstant_t Thermostat_Thermostatevent2c = {
  Thermostat_DOMAIN_ID, Thermostat_Thermostat_CLASS_NUMBER, THERMOSTAT_THERMOSTATEVENT2NUM,
  ESCHER_IS_INSTANCE_EVENT };
const Escher_xtUMLEventConstant_t Thermostat_Thermostatevent5c = {
  Thermostat_DOMAIN_ID, Thermostat_Thermostat_CLASS_NUMBER, THERMOSTAT_THERMOSTATEVENT5NUM,
  ESCHER_IS_INSTANCE_EVENT };
const Escher_xtUMLEventConstant_t Thermostat_Thermostatevent6c = {
  Thermostat_DOMAIN_ID, Thermostat_Thermostat_CLASS_NUMBER, THERMOSTAT_THERMOSTATEVENT6NUM,
  ESCHER_IS_INSTANCE_EVENT };
const Escher_xtUMLEventConstant_t Thermostat_Thermostatevent7c = {
  Thermostat_DOMAIN_ID, Thermostat_Thermostat_CLASS_NUMBER, THERMOSTAT_THERMOSTATEVENT7NUM,
  ESCHER_IS_INSTANCE_EVENT };
const Escher_xtUMLEventConstant_t Thermostat_Thermostatevent8c = {
  Thermostat_DOMAIN_ID, Thermostat_Thermostat_CLASS_NUMBER, THERMOSTAT_THERMOSTATEVENT8NUM,
  ESCHER_IS_INSTANCE_EVENT };


/*
 * State-Event Matrix (SEM)
 * Row index is object (MC enumerated) current state.
 * Row zero is the uninitialized state (e.g., for creation event transitions).
 * Column index is (MC enumerated) state machine events.
 */
static const Escher_SEMcell_t Thermostat_Thermostat_StateEventMatrix[ 5 + 1 ][ 6 ] = {
  /* row 0:  uninitialized state (for creation events) */
  { EVENT_CANT_HAPPEN, EVENT_CANT_HAPPEN, EVENT_CANT_HAPPEN, EVENT_CANT_HAPPEN, EVENT_CANT_HAPPEN, EVENT_CANT_HAPPEN },
  /* row 1:  Thermostat_Thermostat_STATE_1 (thermostat_off) */
  { Thermostat_Thermostat_STATE_2, EVENT_IS_IGNORED, EVENT_CANT_HAPPEN, EVENT_CANT_HAPPEN, EVENT_IS_IGNORED, EVENT_CANT_HAPPEN },
  /* row 2:  Thermostat_Thermostat_STATE_2 (updating) */
  { EVENT_IS_IGNORED, Thermostat_Thermostat_STATE_1, Thermostat_Thermostat_STATE_4, Thermostat_Thermostat_STATE_3, EVENT_IS_IGNORED, Thermostat_Thermostat_STATE_5 },
  /* row 3:  Thermostat_Thermostat_STATE_3 (heating_off) */
  { EVENT_IS_IGNORED, Thermostat_Thermostat_STATE_1, EVENT_CANT_HAPPEN, EVENT_CANT_HAPPEN, Thermostat_Thermostat_STATE_2, EVENT_CANT_HAPPEN },
  /* row 4:  Thermostat_Thermostat_STATE_4 (heating_on) */
  { EVENT_IS_IGNORED, Thermostat_Thermostat_STATE_1, EVENT_CANT_HAPPEN, EVENT_CANT_HAPPEN, Thermostat_Thermostat_STATE_2, EVENT_CANT_HAPPEN },
  /* row 5:  Thermostat_Thermostat_STATE_5 (hysteresis) */
  { EVENT_IS_IGNORED, Thermostat_Thermostat_STATE_1, EVENT_CANT_HAPPEN, EVENT_CANT_HAPPEN, Thermostat_Thermostat_STATE_2, EVENT_CANT_HAPPEN }
};

  /*
   * Array of pointers to the class state action procedures.
   * Index is the (MC enumerated) number of the state action to execute.
   */
  static const StateAction_t Thermostat_Thermostat_acts[ 6 ] = {
    (StateAction_t) 0,
    (StateAction_t) Thermostat_Thermostat_act1,  /* thermostat_off */
    (StateAction_t) Thermostat_Thermostat_act2,  /* updating */
    (StateAction_t) Thermostat_Thermostat_act3,  /* heating_off */
    (StateAction_t) Thermostat_Thermostat_act4,  /* heating_on */
    (StateAction_t) Thermostat_Thermostat_act5  /* hysteresis */
  };

  /*
   * Array of string names of the state machine names.
   * Index is the (MC enumerated) number of the state.
   */
  static const c_t * const state_name_strings[ 6 ] = {
    "",
    "thermostat_off",
    "updating",
    "heating_off",
    "heating_on",
    "hysteresis"
  };

/*
 * instance state machine event dispatching
 */
void
Thermostat_Thermostat_Dispatch( Escher_xtUMLEvent_t * event )
{
  Escher_iHandle_t instance = GetEventTargetInstance( event );
  Escher_EventNumber_t event_number = GetOoaEventNumber( event );
  Escher_StateNumber_t current_state;
  Escher_StateNumber_t next_state;
  if ( 0 != instance ) {
    current_state = instance->current_state;
    if ( current_state > 5 ) {
      /* instance validation failure (object deleted while event in flight) */
      UserEventNoInstanceCallout( event_number );
    } else {
      next_state = Thermostat_Thermostat_StateEventMatrix[ current_state ][ event_number ];
      if ( next_state <= 5 ) {
        STATE_TXN_START_TRACE( "Thermostat", current_state, state_name_strings[ current_state ] );
        /* Execute the state action and update the current state.  */
        ( *Thermostat_Thermostat_acts[ next_state ] )( instance, event );
        STATE_TXN_END_TRACE( "Thermostat", next_state, state_name_strings[ next_state ] );
        instance->current_state = next_state;
      } else if ( next_state == EVENT_CANT_HAPPEN ) {
          /* event cant happen */
          UserEventCantHappenCallout( current_state, next_state, event_number );
          STATE_TXN_CH_TRACE( "Thermostat", current_state );
      } else if ( next_state == EVENT_IS_IGNORED ) {
          /* event ignored */
          STATE_TXN_IG_TRACE( "Thermostat", current_state );
      } else {
        /* empty else */
      }
    }
  }
}

