/*----------------------------------------------------------------------------
 * File:  Thermostat_Thermostat_class.h
 *
 * Class:       Thermostat  (Thermostat)
 * Component:   Thermostat
 *
 * your copyright statement can go here (from te_copyright.body)
 *--------------------------------------------------------------------------*/

#ifndef THERMOSTAT_THERMOSTAT_CLASS_H
#define THERMOSTAT_THERMOSTAT_CLASS_H

#ifdef	__cplusplus
extern	"C"	{
#endif

/*
 * Structural representation of application analysis class:
 *   Thermostat  (Thermostat)
 */
struct Thermostat_Thermostat {
  Escher_StateNumber_t current_state;
  /* application analysis class attributes */
  r_t target_temperature;  /* - target_temperature */
  r_t measured_temperature;  /* - measured_temperature */
  r_t hysteresis;  /* - hysteresis */
};



#define Thermostat_Thermostat_MAX_EXTENT_SIZE 10
extern Escher_Extent_t pG_Thermostat_Thermostat_extent;

/*
 * instance event:  Thermostat1:'turn_on'
 */
typedef struct {
  EVENT_BASE_ATTRIBUTE_LIST         /* base attributes of all event classes */
  /* Note:  no supplemental data for this event */
} Thermostat_Thermostatevent1;
extern const Escher_xtUMLEventConstant_t Thermostat_Thermostatevent1c;
/*
 * instance event:  Thermostat2:'turn_off'
 */
typedef struct {
  EVENT_BASE_ATTRIBUTE_LIST         /* base attributes of all event classes */
  /* Note:  no supplemental data for this event */
} Thermostat_Thermostatevent2;
extern const Escher_xtUMLEventConstant_t Thermostat_Thermostatevent2c;
/*
 * instance event:  Thermostat5:'should_turn_on'
 */
typedef struct {
  EVENT_BASE_ATTRIBUTE_LIST         /* base attributes of all event classes */
  /* Note:  no supplemental data for this event */
} Thermostat_Thermostatevent5;
extern const Escher_xtUMLEventConstant_t Thermostat_Thermostatevent5c;
/*
 * instance event:  Thermostat6:'should_turn_off'
 */
typedef struct {
  EVENT_BASE_ATTRIBUTE_LIST         /* base attributes of all event classes */
  /* Note:  no supplemental data for this event */
} Thermostat_Thermostatevent6;
extern const Escher_xtUMLEventConstant_t Thermostat_Thermostatevent6c;
/*
 * instance event:  Thermostat7:'update'
 */
typedef struct {
  EVENT_BASE_ATTRIBUTE_LIST         /* base attributes of all event classes */
  /* Note:  no supplemental data for this event */
} Thermostat_Thermostatevent7;
extern const Escher_xtUMLEventConstant_t Thermostat_Thermostatevent7c;
/*
 * instance event:  Thermostat8:'should_wait'
 */
typedef struct {
  EVENT_BASE_ATTRIBUTE_LIST         /* base attributes of all event classes */
  /* Note:  no supplemental data for this event */
} Thermostat_Thermostatevent8;
extern const Escher_xtUMLEventConstant_t Thermostat_Thermostatevent8c;
/*
 * union of events targeted towards 'Thermostat' state machine
 */
typedef union {
  Thermostat_Thermostatevent1 thermostat1_1;  
  Thermostat_Thermostatevent2 thermostat2_2;  
  Thermostat_Thermostatevent5 thermostat5_3;  
  Thermostat_Thermostatevent6 thermostat6_4;  
  Thermostat_Thermostatevent7 thermostat7_5;  
  Thermostat_Thermostatevent8 thermostat8_6;  
} Thermostat_Thermostat_Events_u;
/*
 * enumeration of state model states for class
 */
#define Thermostat_Thermostat_STATE_1 1  /* state [1]:  (thermostat_off) */
#define Thermostat_Thermostat_STATE_2 2  /* state [2]:  (updating) */
#define Thermostat_Thermostat_STATE_3 3  /* state [3]:  (heating_off) */
#define Thermostat_Thermostat_STATE_4 4  /* state [4]:  (heating_on) */
#define Thermostat_Thermostat_STATE_5 5  /* state [5]:  (hysteresis) */
/*
 * enumeration of state model event numbers
 */
#define THERMOSTAT_THERMOSTATEVENT1NUM 0  /* Thermostat1:'turn_on' */
#define THERMOSTAT_THERMOSTATEVENT2NUM 1  /* Thermostat2:'turn_off' */
#define THERMOSTAT_THERMOSTATEVENT5NUM 2  /* Thermostat5:'should_turn_on' */
#define THERMOSTAT_THERMOSTATEVENT6NUM 3  /* Thermostat6:'should_turn_off' */
#define THERMOSTAT_THERMOSTATEVENT7NUM 4  /* Thermostat7:'update' */
#define THERMOSTAT_THERMOSTATEVENT8NUM 5  /* Thermostat8:'should_wait' */
extern void Thermostat_Thermostat_Dispatch( Escher_xtUMLEvent_t * );

#ifdef	__cplusplus
}
#endif

#endif  /* THERMOSTAT_THERMOSTAT_CLASS_H */
