/*----------------------------------------------------------------------------
 * File:  Thermostat_HeatingController_class.h
 *
 * Class:       HeatingController  (HeatingController)
 * Component:   Thermostat
 *
 * your copyright statement can go here (from te_copyright.body)
 *--------------------------------------------------------------------------*/

#ifndef THERMOSTAT_HEATINGCONTROLLER_CLASS_H
#define THERMOSTAT_HEATINGCONTROLLER_CLASS_H

#ifdef	__cplusplus
extern	"C"	{
#endif

/*
 * Structural representation of application analysis class:
 *   HeatingController  (HeatingController)
 */
struct Thermostat_HeatingController {
  Escher_StateNumber_t current_state;
  /* application analysis class attributes */
};



#define Thermostat_HeatingController_MAX_EXTENT_SIZE 10
extern Escher_Extent_t pG_Thermostat_HeatingController_extent;

/*
 * instance event:  HeatingController1:'turn_off_request'
 */
typedef struct {
  EVENT_BASE_ATTRIBUTE_LIST         /* base attributes of all event classes */
  /* Note:  no supplemental data for this event */
} Thermostat_HeatingControllerevent1;
extern const Escher_xtUMLEventConstant_t Thermostat_HeatingControllerevent1c;
/*
 * instance event:  HeatingController2:'turn_on_request'
 */
typedef struct {
  EVENT_BASE_ATTRIBUTE_LIST         /* base attributes of all event classes */
  /* Note:  no supplemental data for this event */
} Thermostat_HeatingControllerevent2;
extern const Escher_xtUMLEventConstant_t Thermostat_HeatingControllerevent2c;
/*
 * union of events targeted towards 'HeatingController' state machine
 */
typedef union {
  Thermostat_HeatingControllerevent1 heatingcontroller1_1;  
  Thermostat_HeatingControllerevent2 heatingcontroller2_2;  
} Thermostat_HeatingController_Events_u;
/*
 * enumeration of state model states for class
 */
#define Thermostat_HeatingController_STATE_1 1  /* state [1]:  (heating_off) */
#define Thermostat_HeatingController_STATE_2 2  /* state [2]:  (heating_on) */
/*
 * enumeration of state model event numbers
 */
#define THERMOSTAT_HEATINGCONTROLLEREVENT1NUM 0  /* HeatingController1:'turn_off_request' */
#define THERMOSTAT_HEATINGCONTROLLEREVENT2NUM 1  /* HeatingController2:'turn_on_request' */
extern void Thermostat_HeatingController_Dispatch( Escher_xtUMLEvent_t * );

#ifdef	__cplusplus
}
#endif

#endif  /* THERMOSTAT_HEATINGCONTROLLER_CLASS_H */
