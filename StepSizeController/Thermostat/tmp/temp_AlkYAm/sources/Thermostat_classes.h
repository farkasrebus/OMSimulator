/*----------------------------------------------------------------------------
 * File:  Thermostat_classes.h
 *
 * This file defines the object type identification numbers for all classes
 * in the component:  Thermostat
 *
 * your copyright statement can go here (from te_copyright.body)
 *--------------------------------------------------------------------------*/

#ifndef THERMOSTAT_CLASSES_H
#define THERMOSTAT_CLASSES_H

#ifdef	__cplusplus
extern	"C"	{
#endif

/*
 * Initialization services for component:  Thermostat
 */
extern Escher_Extent_t * const Thermostat_class_info[];
extern const EventTaker_t Thermostat_EventDispatcher[];
void Thermostat_execute_initialization( void );

#define Thermostat_STATE_MODELS 2
/* Define constants to map to class numbers.  */
#define Thermostat_Thermostat_CLASS_NUMBER 0
#define Thermostat_HeatingController_CLASS_NUMBER 1
#define Thermostat_MAX_CLASS_NUMBERS 2

/* Provide a map of classes to task numbers.  */
#define Thermostat_TASK_NUMBERS  0, 0

#define Thermostat_class_dispatchers\
  Thermostat_Thermostat_Dispatch,\
  Thermostat_HeatingController_Dispatch

/* Provide definitions of the shapes of the class structures.  */

typedef struct Thermostat_Thermostat Thermostat_Thermostat;
typedef struct Thermostat_HeatingController Thermostat_HeatingController;

/* union of class declarations so we may derive largest class size */
#define Thermostat_CLASS_U \
  char Thermostat_dummy;\

/*
 * UML Domain Functions (Synchronous Services)
 */
void Thermostat_create( void );

#include "Thermostat.h"
#include "Thermostat_Thermostat_class.h"
#include "Thermostat_HeatingController_class.h"
/*
 * roll-up of all events (with their parameters) for component Thermostat
 */
typedef union {
  Thermostat_Thermostat_Events_u Thermostat_Thermostat_Events_u_namespace;
  Thermostat_HeatingController_Events_u Thermostat_HeatingController_Events_u_namespace;
} Thermostat_DomainEvents_u;

#ifdef	__cplusplus
}
#endif
#endif  /* THERMOSTAT_CLASSES_H */
