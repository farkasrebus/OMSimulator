/*----------------------------------------------------------------------------
 * File:  Thermostat_HeatingController_class.c
 *
 * Class:       HeatingController  (HeatingController)
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
static Escher_SetElement_s Thermostat_HeatingController_container[ Thermostat_HeatingController_MAX_EXTENT_SIZE ];
static Thermostat_HeatingController Thermostat_HeatingController_instances[ Thermostat_HeatingController_MAX_EXTENT_SIZE ];
Escher_Extent_t pG_Thermostat_HeatingController_extent = {
  {0}, {0}, &Thermostat_HeatingController_container[ 0 ],
  (Escher_iHandle_t) &Thermostat_HeatingController_instances,
  sizeof( Thermostat_HeatingController ), Thermostat_HeatingController_STATE_1, Thermostat_HeatingController_MAX_EXTENT_SIZE
  };
/*----------------------------------------------------------------------------
 * State and transition action implementations for the following class:
 *
 * Class:      HeatingController  (HeatingController)
 * Component:  Thermostat
 *--------------------------------------------------------------------------*/

/*
 * State 1:  [heating_off]
 */
static void Thermostat_HeatingController_act1( Thermostat_HeatingController *, const Escher_xtUMLEvent_t * const );
static void
Thermostat_HeatingController_act1( Thermostat_HeatingController * self, const Escher_xtUMLEvent_t * const event )
{
  /* SEND HeatingControlPort::turn_heating_off() */
  XTUML_OAL_STMT_TRACE( 1, "SEND HeatingControlPort::turn_heating_off()" );
  Thermostat_HeatingControlPort_turn_heating_off();
}

/*
 * State 2:  [heating_on]
 */
static void Thermostat_HeatingController_act2( Thermostat_HeatingController *, const Escher_xtUMLEvent_t * const );
static void
Thermostat_HeatingController_act2( Thermostat_HeatingController * self, const Escher_xtUMLEvent_t * const event )
{
  /* SEND HeatingControlPort::turn_heating_on() */
  XTUML_OAL_STMT_TRACE( 1, "SEND HeatingControlPort::turn_heating_on()" );
  Thermostat_HeatingControlPort_turn_heating_on();
}

const Escher_xtUMLEventConstant_t Thermostat_HeatingControllerevent1c = {
  Thermostat_DOMAIN_ID, Thermostat_HeatingController_CLASS_NUMBER, THERMOSTAT_HEATINGCONTROLLEREVENT1NUM,
  ESCHER_IS_INSTANCE_EVENT };
const Escher_xtUMLEventConstant_t Thermostat_HeatingControllerevent2c = {
  Thermostat_DOMAIN_ID, Thermostat_HeatingController_CLASS_NUMBER, THERMOSTAT_HEATINGCONTROLLEREVENT2NUM,
  ESCHER_IS_INSTANCE_EVENT };


/*
 * State-Event Matrix (SEM)
 * Row index is object (MC enumerated) current state.
 * Row zero is the uninitialized state (e.g., for creation event transitions).
 * Column index is (MC enumerated) state machine events.
 */
static const Escher_SEMcell_t Thermostat_HeatingController_StateEventMatrix[ 2 + 1 ][ 2 ] = {
  /* row 0:  uninitialized state (for creation events) */
  { EVENT_CANT_HAPPEN, EVENT_CANT_HAPPEN },
  /* row 1:  Thermostat_HeatingController_STATE_1 (heating_off) */
  { EVENT_IS_IGNORED, Thermostat_HeatingController_STATE_2 },
  /* row 2:  Thermostat_HeatingController_STATE_2 (heating_on) */
  { Thermostat_HeatingController_STATE_1, EVENT_IS_IGNORED }
};

  /*
   * Array of pointers to the class state action procedures.
   * Index is the (MC enumerated) number of the state action to execute.
   */
  static const StateAction_t Thermostat_HeatingController_acts[ 3 ] = {
    (StateAction_t) 0,
    (StateAction_t) Thermostat_HeatingController_act1,  /* heating_off */
    (StateAction_t) Thermostat_HeatingController_act2  /* heating_on */
  };

  /*
   * Array of string names of the state machine names.
   * Index is the (MC enumerated) number of the state.
   */
  static const c_t * const state_name_strings[ 3 ] = {
    "",
    "heating_off",
    "heating_on"
  };

/*
 * instance state machine event dispatching
 */
void
Thermostat_HeatingController_Dispatch( Escher_xtUMLEvent_t * event )
{
  Escher_iHandle_t instance = GetEventTargetInstance( event );
  Escher_EventNumber_t event_number = GetOoaEventNumber( event );
  Escher_StateNumber_t current_state;
  Escher_StateNumber_t next_state;
  if ( 0 != instance ) {
    current_state = instance->current_state;
    if ( current_state > 2 ) {
      /* instance validation failure (object deleted while event in flight) */
      UserEventNoInstanceCallout( event_number );
    } else {
      next_state = Thermostat_HeatingController_StateEventMatrix[ current_state ][ event_number ];
      if ( next_state <= 2 ) {
        STATE_TXN_START_TRACE( "HeatingController", current_state, state_name_strings[ current_state ] );
        /* Execute the state action and update the current state.  */
        ( *Thermostat_HeatingController_acts[ next_state ] )( instance, event );
        STATE_TXN_END_TRACE( "HeatingController", next_state, state_name_strings[ next_state ] );
        instance->current_state = next_state;
      } else if ( next_state == EVENT_IS_IGNORED ) {
          /* event ignored */
          STATE_TXN_IG_TRACE( "HeatingController", current_state );
      } else {
        /* empty else */
      }
    }
  }
}

