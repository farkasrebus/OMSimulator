// define class name and unique id
#define MODEL_IDENTIFIER ThermostatMonitor_HeatingOnMonitor
#define MODEL_GUID "{d8f86733-647a-4b59-8a31-3d7ff510ca12}"

// include fmu header files, typedefs and macros
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "openmodelica.h"
#include "openmodelica_func.h"
#include "simulation_data.h"
#include "util/omc_error.h"
#include "ThermostatMonitor_HeatingOnMonitor_functions.h"
#include "simulation/solver/initialization/initialization.h"
#include "simulation/solver/events.h"
#include "fmu2_model_interface.h"

#ifdef __cplusplus
extern "C" {
#endif

void setStartValues(ModelInstance *comp);
void setDefaultStartValues(ModelInstance *comp);
void eventUpdate(ModelInstance* comp, fmi2EventInfo* eventInfo);
fmi2Real getReal(ModelInstance* comp, const fmi2ValueReference vr);
fmi2Status setReal(ModelInstance* comp, const fmi2ValueReference vr, const fmi2Real value);
fmi2Integer getInteger(ModelInstance* comp, const fmi2ValueReference vr);
fmi2Status setInteger(ModelInstance* comp, const fmi2ValueReference vr, const fmi2Integer value);
fmi2Boolean getBoolean(ModelInstance* comp, const fmi2ValueReference vr);
fmi2Status setBoolean(ModelInstance* comp, const fmi2ValueReference vr, const fmi2Boolean value);
fmi2String getString(ModelInstance* comp, const fmi2ValueReference vr);
fmi2Status setString(ModelInstance* comp, const fmi2ValueReference vr, fmi2String value);
fmi2Status setExternalFunction(ModelInstance* c, const fmi2ValueReference vr, const void* value);

// define model size
#define NUMBER_OF_STATES 0
#define NUMBER_OF_EVENT_INDICATORS 2
#define NUMBER_OF_REALS 2
#define NUMBER_OF_INTEGERS 2
#define NUMBER_OF_STRINGS 0
#define NUMBER_OF_BOOLEANS 1
#define NUMBER_OF_EXTERNALFUNCTIONS 0

// define variable data for model
#define $Preply_vr 0 
#define $Prequest_vr 1 
#define $PturnOff_vr 0 
#define $PturnOn_vr 1 
#define $Pturnedon_vr 0 


// define initial state vector as vector of value references
#define STATES {  }
#define STATESDERIVATIVES {  }


// implementation of the Model Exchange functions
extern void ThermostatMonitor_HeatingOnMonitor_setupDataStruc(DATA *data);
#define fmu2_model_interface_setupDataStruc ThermostatMonitor_HeatingOnMonitor_setupDataStruc
#include "fmu2_model_interface.c"

// Set values for all variables that define a start value
void setDefaultStartValues(ModelInstance *comp) {
  comp->fmuData->modelData->realVarsData[0].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[1].attribute.start = 0;
  comp->fmuData->modelData->integerVarsData[0].attribute.start = 0;
  comp->fmuData->modelData->integerVarsData[1].attribute.start = 0;
  comp->fmuData->modelData->booleanVarsData[0].attribute.start = 0;
}
// Set values for all variables that define a start value
void setStartValues(ModelInstance *comp) {
  comp->fmuData->modelData->realVarsData[0].attribute.start =  comp->fmuData->localData[0]->realVars[0];
  comp->fmuData->modelData->realVarsData[1].attribute.start =  comp->fmuData->localData[0]->realVars[1];
  comp->fmuData->modelData->integerVarsData[0].attribute.start =  comp->fmuData->localData[0]->integerVars[0];
  comp->fmuData->modelData->integerVarsData[1].attribute.start =  comp->fmuData->localData[0]->integerVars[1];
  comp->fmuData->modelData->booleanVarsData[0].attribute.start =  comp->fmuData->localData[0]->booleanVars[0];
}

// Used to set the next time event, if any.
void eventUpdate(ModelInstance* comp, fmi2EventInfo* eventInfo) {
}

fmi2Real getReal(ModelInstance* comp, const fmi2ValueReference vr) {
  switch (vr) {
    case $Preply_vr : return comp->fmuData->localData[0]->realVars[0]; break;
    case $Prequest_vr : return comp->fmuData->localData[0]->realVars[1]; break;
    default:
      return 0;
  }
}

fmi2Status setReal(ModelInstance* comp, const fmi2ValueReference vr, const fmi2Real value) {
  switch (vr) {
    case $Preply_vr : comp->fmuData->localData[0]->realVars[0] = value; break;
    case $Prequest_vr : comp->fmuData->localData[0]->realVars[1] = value; break;
    default:
      return fmi2Error;
  }
  return fmi2OK;
}

fmi2Integer getInteger(ModelInstance* comp, const fmi2ValueReference vr) {
  switch (vr) {
    case $PturnOff_vr : return comp->fmuData->localData[0]->integerVars[0]; break;
    case $PturnOn_vr : return comp->fmuData->localData[0]->integerVars[1]; break;
    default:
      return 0;
  }
}
fmi2Status setInteger(ModelInstance* comp, const fmi2ValueReference vr, const fmi2Integer value) {
  switch (vr) {
    case $PturnOff_vr : comp->fmuData->localData[0]->integerVars[0] = value; break;
    case $PturnOn_vr : comp->fmuData->localData[0]->integerVars[1] = value; break;
    default:
      return fmi2Error;
  }
  return fmi2OK;
}
fmi2Boolean getBoolean(ModelInstance* comp, const fmi2ValueReference vr) {
  switch (vr) {
    case $Pturnedon_vr : return comp->fmuData->localData[0]->booleanVars[0]; break;
    default:
      return fmi2False;
  }
}

fmi2Status setBoolean(ModelInstance* comp, const fmi2ValueReference vr, const fmi2Boolean value) {
  switch (vr) {
    case $Pturnedon_vr : comp->fmuData->localData[0]->booleanVars[0] = value; break;
    default:
      return fmi2Error;
  }
  return fmi2OK;
}

fmi2String getString(ModelInstance* comp, const fmi2ValueReference vr) {
  switch (vr) {
    default:
      return "";
  }
}

fmi2Status setString(ModelInstance* comp, const fmi2ValueReference vr, fmi2String value) {
  switch (vr) {
    default:
      return fmi2Error;
  }
  return fmi2OK;
}

fmi2Status setExternalFunction(ModelInstance* c, const fmi2ValueReference vr, const void* value){
  switch (vr) {
    default:
      return fmi2Error;
  }
  return fmi2OK;
}


#ifdef __cplusplus
}
#endif

