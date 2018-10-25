// define class name and unique id
#define MODEL_IDENTIFIER ThermostatMonitor_CentralMonitor
#define MODEL_GUID "{0f62d11e-c13e-4487-966f-02951abfc8fb}"

// include fmu header files, typedefs and macros
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "openmodelica.h"
#include "openmodelica_func.h"
#include "simulation_data.h"
#include "util/omc_error.h"
#include "ThermostatMonitor_CentralMonitor_functions.h"
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
#define NUMBER_OF_STATES 5
#define NUMBER_OF_EVENT_INDICATORS 17
#define NUMBER_OF_REALS 16
#define NUMBER_OF_INTEGERS 2
#define NUMBER_OF_STRINGS 0
#define NUMBER_OF_BOOLEANS 11
#define NUMBER_OF_EXTERNALFUNCTIONS 0

// define variable data for model
#define $PlastHeatReply_vr 0 
#define $PlastTempReply_vr 1 
#define $PlastTermReply_vr 2 
#define $PnextHeartBeat_vr 3 
#define $Pstate_vr 4 
#define $P$DER$PlastHeatReply_vr 5 
#define $P$DER$PlastTempReply_vr 6 
#define $P$DER$PlastTermReply_vr 7 
#define $P$DER$PnextHeartBeat_vr 8 
#define $P$DER$Pstate_vr 9 
#define $PheatReply_vr 10 
#define $PheatReq_vr 11 
#define $PtempReply_vr 12 
#define $PtempReq_vr 13 
#define $PtermReply_vr 14 
#define $PtermReq_vr 15 
#define $PheatOnGrant_vr 0 
#define $PheatOnPermission_vr 1 
#define $P$whenCondition1_vr 0 
#define $P$whenCondition10_vr 1 
#define $P$whenCondition2_vr 2 
#define $P$whenCondition3_vr 3 
#define $P$whenCondition4_vr 4 
#define $P$whenCondition5_vr 5 
#define $P$whenCondition6_vr 6 
#define $P$whenCondition7_vr 7 
#define $P$whenCondition8_vr 8 
#define $P$whenCondition9_vr 9 
#define $Pgrant_vr 10 


// define initial state vector as vector of value references
#define STATES { $PlastHeatReply_vr, $PlastTempReply_vr, $PlastTermReply_vr, $PnextHeartBeat_vr, $Pstate_vr }
#define STATESDERIVATIVES { $P$DER$PlastHeatReply_vr, $P$DER$PlastTempReply_vr, $P$DER$PlastTermReply_vr, $P$DER$PnextHeartBeat_vr, $P$DER$Pstate_vr }


// implementation of the Model Exchange functions
extern void ThermostatMonitor_CentralMonitor_setupDataStruc(DATA *data);
#define fmu2_model_interface_setupDataStruc ThermostatMonitor_CentralMonitor_setupDataStruc
#include "fmu2_model_interface.c"

// Set values for all variables that define a start value
void setDefaultStartValues(ModelInstance *comp) {
  comp->fmuData->modelData->realVarsData[0].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[1].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[2].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[3].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[4].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[5].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[6].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[7].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[8].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[9].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[10].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[11].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[12].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[13].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[14].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[15].attribute.start = 0;
  comp->fmuData->modelData->integerVarsData[0].attribute.start = 0;
  comp->fmuData->modelData->integerVarsData[1].attribute.start = 0;
  comp->fmuData->modelData->booleanVarsData[0].attribute.start = 0;
  comp->fmuData->modelData->booleanVarsData[1].attribute.start = 0;
  comp->fmuData->modelData->booleanVarsData[2].attribute.start = 0;
  comp->fmuData->modelData->booleanVarsData[3].attribute.start = 0;
  comp->fmuData->modelData->booleanVarsData[4].attribute.start = 0;
  comp->fmuData->modelData->booleanVarsData[5].attribute.start = 0;
  comp->fmuData->modelData->booleanVarsData[6].attribute.start = 0;
  comp->fmuData->modelData->booleanVarsData[7].attribute.start = 0;
  comp->fmuData->modelData->booleanVarsData[8].attribute.start = 0;
  comp->fmuData->modelData->booleanVarsData[9].attribute.start = 0;
  comp->fmuData->modelData->booleanVarsData[10].attribute.start = 0;
}
// Set values for all variables that define a start value
void setStartValues(ModelInstance *comp) {
  comp->fmuData->modelData->realVarsData[0].attribute.start =  comp->fmuData->localData[0]->realVars[0];
  comp->fmuData->modelData->realVarsData[1].attribute.start =  comp->fmuData->localData[0]->realVars[1];
  comp->fmuData->modelData->realVarsData[2].attribute.start =  comp->fmuData->localData[0]->realVars[2];
  comp->fmuData->modelData->realVarsData[3].attribute.start =  comp->fmuData->localData[0]->realVars[3];
  comp->fmuData->modelData->realVarsData[4].attribute.start =  comp->fmuData->localData[0]->realVars[4];
  comp->fmuData->modelData->realVarsData[5].attribute.start =  comp->fmuData->localData[0]->realVars[5];
  comp->fmuData->modelData->realVarsData[6].attribute.start =  comp->fmuData->localData[0]->realVars[6];
  comp->fmuData->modelData->realVarsData[7].attribute.start =  comp->fmuData->localData[0]->realVars[7];
  comp->fmuData->modelData->realVarsData[8].attribute.start =  comp->fmuData->localData[0]->realVars[8];
  comp->fmuData->modelData->realVarsData[9].attribute.start =  comp->fmuData->localData[0]->realVars[9];
  comp->fmuData->modelData->realVarsData[10].attribute.start =  comp->fmuData->localData[0]->realVars[10];
  comp->fmuData->modelData->realVarsData[11].attribute.start =  comp->fmuData->localData[0]->realVars[11];
  comp->fmuData->modelData->realVarsData[12].attribute.start =  comp->fmuData->localData[0]->realVars[12];
  comp->fmuData->modelData->realVarsData[13].attribute.start =  comp->fmuData->localData[0]->realVars[13];
  comp->fmuData->modelData->realVarsData[14].attribute.start =  comp->fmuData->localData[0]->realVars[14];
  comp->fmuData->modelData->realVarsData[15].attribute.start =  comp->fmuData->localData[0]->realVars[15];
  comp->fmuData->modelData->integerVarsData[0].attribute.start =  comp->fmuData->localData[0]->integerVars[0];
  comp->fmuData->modelData->integerVarsData[1].attribute.start =  comp->fmuData->localData[0]->integerVars[1];
  comp->fmuData->modelData->booleanVarsData[0].attribute.start =  comp->fmuData->localData[0]->booleanVars[0];
  comp->fmuData->modelData->booleanVarsData[1].attribute.start =  comp->fmuData->localData[0]->booleanVars[1];
  comp->fmuData->modelData->booleanVarsData[2].attribute.start =  comp->fmuData->localData[0]->booleanVars[2];
  comp->fmuData->modelData->booleanVarsData[3].attribute.start =  comp->fmuData->localData[0]->booleanVars[3];
  comp->fmuData->modelData->booleanVarsData[4].attribute.start =  comp->fmuData->localData[0]->booleanVars[4];
  comp->fmuData->modelData->booleanVarsData[5].attribute.start =  comp->fmuData->localData[0]->booleanVars[5];
  comp->fmuData->modelData->booleanVarsData[6].attribute.start =  comp->fmuData->localData[0]->booleanVars[6];
  comp->fmuData->modelData->booleanVarsData[7].attribute.start =  comp->fmuData->localData[0]->booleanVars[7];
  comp->fmuData->modelData->booleanVarsData[8].attribute.start =  comp->fmuData->localData[0]->booleanVars[8];
  comp->fmuData->modelData->booleanVarsData[9].attribute.start =  comp->fmuData->localData[0]->booleanVars[9];
  comp->fmuData->modelData->booleanVarsData[10].attribute.start =  comp->fmuData->localData[0]->booleanVars[10];
}

// Used to set the next time event, if any.
void eventUpdate(ModelInstance* comp, fmi2EventInfo* eventInfo) {
}

fmi2Real getReal(ModelInstance* comp, const fmi2ValueReference vr) {
  switch (vr) {
    case $PlastHeatReply_vr : return comp->fmuData->localData[0]->realVars[0]; break;
    case $PlastTempReply_vr : return comp->fmuData->localData[0]->realVars[1]; break;
    case $PlastTermReply_vr : return comp->fmuData->localData[0]->realVars[2]; break;
    case $PnextHeartBeat_vr : return comp->fmuData->localData[0]->realVars[3]; break;
    case $Pstate_vr : return comp->fmuData->localData[0]->realVars[4]; break;
    case $P$DER$PlastHeatReply_vr : return comp->fmuData->localData[0]->realVars[5]; break;
    case $P$DER$PlastTempReply_vr : return comp->fmuData->localData[0]->realVars[6]; break;
    case $P$DER$PlastTermReply_vr : return comp->fmuData->localData[0]->realVars[7]; break;
    case $P$DER$PnextHeartBeat_vr : return comp->fmuData->localData[0]->realVars[8]; break;
    case $P$DER$Pstate_vr : return comp->fmuData->localData[0]->realVars[9]; break;
    case $PheatReply_vr : return comp->fmuData->localData[0]->realVars[10]; break;
    case $PheatReq_vr : return comp->fmuData->localData[0]->realVars[11]; break;
    case $PtempReply_vr : return comp->fmuData->localData[0]->realVars[12]; break;
    case $PtempReq_vr : return comp->fmuData->localData[0]->realVars[13]; break;
    case $PtermReply_vr : return comp->fmuData->localData[0]->realVars[14]; break;
    case $PtermReq_vr : return comp->fmuData->localData[0]->realVars[15]; break;
    default:
      return 0;
  }
}

fmi2Status setReal(ModelInstance* comp, const fmi2ValueReference vr, const fmi2Real value) {
  switch (vr) {
    case $PlastHeatReply_vr : comp->fmuData->localData[0]->realVars[0] = value; break;
    case $PlastTempReply_vr : comp->fmuData->localData[0]->realVars[1] = value; break;
    case $PlastTermReply_vr : comp->fmuData->localData[0]->realVars[2] = value; break;
    case $PnextHeartBeat_vr : comp->fmuData->localData[0]->realVars[3] = value; break;
    case $Pstate_vr : comp->fmuData->localData[0]->realVars[4] = value; break;
    case $P$DER$PlastHeatReply_vr : comp->fmuData->localData[0]->realVars[5] = value; break;
    case $P$DER$PlastTempReply_vr : comp->fmuData->localData[0]->realVars[6] = value; break;
    case $P$DER$PlastTermReply_vr : comp->fmuData->localData[0]->realVars[7] = value; break;
    case $P$DER$PnextHeartBeat_vr : comp->fmuData->localData[0]->realVars[8] = value; break;
    case $P$DER$Pstate_vr : comp->fmuData->localData[0]->realVars[9] = value; break;
    case $PheatReply_vr : comp->fmuData->localData[0]->realVars[10] = value; break;
    case $PheatReq_vr : comp->fmuData->localData[0]->realVars[11] = value; break;
    case $PtempReply_vr : comp->fmuData->localData[0]->realVars[12] = value; break;
    case $PtempReq_vr : comp->fmuData->localData[0]->realVars[13] = value; break;
    case $PtermReply_vr : comp->fmuData->localData[0]->realVars[14] = value; break;
    case $PtermReq_vr : comp->fmuData->localData[0]->realVars[15] = value; break;
    default:
      return fmi2Error;
  }
  return fmi2OK;
}

fmi2Integer getInteger(ModelInstance* comp, const fmi2ValueReference vr) {
  switch (vr) {
    case $PheatOnGrant_vr : return comp->fmuData->localData[0]->integerVars[0]; break;
    case $PheatOnPermission_vr : return comp->fmuData->localData[0]->integerVars[1]; break;
    default:
      return 0;
  }
}
fmi2Status setInteger(ModelInstance* comp, const fmi2ValueReference vr, const fmi2Integer value) {
  switch (vr) {
    case $PheatOnGrant_vr : comp->fmuData->localData[0]->integerVars[0] = value; break;
    case $PheatOnPermission_vr : comp->fmuData->localData[0]->integerVars[1] = value; break;
    default:
      return fmi2Error;
  }
  return fmi2OK;
}
fmi2Boolean getBoolean(ModelInstance* comp, const fmi2ValueReference vr) {
  switch (vr) {
    case $P$whenCondition1_vr : return comp->fmuData->localData[0]->booleanVars[0]; break;
    case $P$whenCondition10_vr : return comp->fmuData->localData[0]->booleanVars[1]; break;
    case $P$whenCondition2_vr : return comp->fmuData->localData[0]->booleanVars[2]; break;
    case $P$whenCondition3_vr : return comp->fmuData->localData[0]->booleanVars[3]; break;
    case $P$whenCondition4_vr : return comp->fmuData->localData[0]->booleanVars[4]; break;
    case $P$whenCondition5_vr : return comp->fmuData->localData[0]->booleanVars[5]; break;
    case $P$whenCondition6_vr : return comp->fmuData->localData[0]->booleanVars[6]; break;
    case $P$whenCondition7_vr : return comp->fmuData->localData[0]->booleanVars[7]; break;
    case $P$whenCondition8_vr : return comp->fmuData->localData[0]->booleanVars[8]; break;
    case $P$whenCondition9_vr : return comp->fmuData->localData[0]->booleanVars[9]; break;
    case $Pgrant_vr : return comp->fmuData->localData[0]->booleanVars[10]; break;
    default:
      return fmi2False;
  }
}

fmi2Status setBoolean(ModelInstance* comp, const fmi2ValueReference vr, const fmi2Boolean value) {
  switch (vr) {
    case $P$whenCondition1_vr : comp->fmuData->localData[0]->booleanVars[0] = value; break;
    case $P$whenCondition10_vr : comp->fmuData->localData[0]->booleanVars[1] = value; break;
    case $P$whenCondition2_vr : comp->fmuData->localData[0]->booleanVars[2] = value; break;
    case $P$whenCondition3_vr : comp->fmuData->localData[0]->booleanVars[3] = value; break;
    case $P$whenCondition4_vr : comp->fmuData->localData[0]->booleanVars[4] = value; break;
    case $P$whenCondition5_vr : comp->fmuData->localData[0]->booleanVars[5] = value; break;
    case $P$whenCondition6_vr : comp->fmuData->localData[0]->booleanVars[6] = value; break;
    case $P$whenCondition7_vr : comp->fmuData->localData[0]->booleanVars[7] = value; break;
    case $P$whenCondition8_vr : comp->fmuData->localData[0]->booleanVars[8] = value; break;
    case $P$whenCondition9_vr : comp->fmuData->localData[0]->booleanVars[9] = value; break;
    case $Pgrant_vr : comp->fmuData->localData[0]->booleanVars[10] = value; break;
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

