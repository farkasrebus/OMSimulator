/* Main Simulation File */
#include "ThermostatMonitor_CentralMonitor_model.h"


/* dummy VARINFO and FILEINFO */
const FILE_INFO dummyFILE_INFO = omc_dummyFileInfo;
const VAR_INFO dummyVAR_INFO = omc_dummyVarInfo;
#if defined(__cplusplus)
extern "C" {
#endif

int ThermostatMonitor_CentralMonitor_input_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->localData[0]->integerVars[1] /* heatOnPermission variable */ = data->simulationInfo->inputVars[0];
  data->localData[0]->realVars[10] /* heatReply variable */ = data->simulationInfo->inputVars[1];
  data->localData[0]->realVars[12] /* tempReply variable */ = data->simulationInfo->inputVars[2];
  data->localData[0]->realVars[14] /* termReply variable */ = data->simulationInfo->inputVars[3];
  
  TRACE_POP
  return 0;
}

int ThermostatMonitor_CentralMonitor_input_function_init(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->inputVars[0] = data->modelData->integerVarsData[1].attribute.start;
  data->simulationInfo->inputVars[1] = data->modelData->realVarsData[10].attribute.start;
  data->simulationInfo->inputVars[2] = data->modelData->realVarsData[12].attribute.start;
  data->simulationInfo->inputVars[3] = data->modelData->realVarsData[14].attribute.start;
  
  TRACE_POP
  return 0;
}

int ThermostatMonitor_CentralMonitor_input_function_updateStartValues(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->modelData->integerVarsData[1].attribute.start = data->simulationInfo->inputVars[0];
  data->modelData->realVarsData[10].attribute.start = data->simulationInfo->inputVars[1];
  data->modelData->realVarsData[12].attribute.start = data->simulationInfo->inputVars[2];
  data->modelData->realVarsData[14].attribute.start = data->simulationInfo->inputVars[3];
  
  TRACE_POP
  return 0;
}

int ThermostatMonitor_CentralMonitor_inputNames(DATA *data, char ** names){
  TRACE_PUSH

  names[0] = (char *) data->modelData->integerVarsData[1].info.name;
  names[1] = (char *) data->modelData->realVarsData[10].info.name;
  names[2] = (char *) data->modelData->realVarsData[12].info.name;
  names[3] = (char *) data->modelData->realVarsData[14].info.name;
  
  TRACE_POP
  return 0;
}

int ThermostatMonitor_CentralMonitor_output_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->outputVars[0] = data->localData[0]->integerVars[0] /* heatOnGrant DISCRETE */;
  data->simulationInfo->outputVars[1] = data->localData[0]->realVars[11] /* heatReq variable */;
  data->simulationInfo->outputVars[2] = data->localData[0]->realVars[0] /* lastHeatReply STATE(1) */;
  data->simulationInfo->outputVars[3] = data->localData[0]->realVars[1] /* lastTempReply STATE(1) */;
  data->simulationInfo->outputVars[4] = data->localData[0]->realVars[2] /* lastTermReply STATE(1) */;
  data->simulationInfo->outputVars[5] = data->localData[0]->realVars[4] /* state STATE(1) */;
  data->simulationInfo->outputVars[6] = data->localData[0]->realVars[13] /* tempReq variable */;
  data->simulationInfo->outputVars[7] = data->localData[0]->realVars[15] /* termReq variable */;
  
  TRACE_POP
  return 0;
}


/*
 equation index: 28
 type: SIMPLE_ASSIGN
 $whenCondition10 = (*Real*)(heatOnPermission) > 0.5
 */
void ThermostatMonitor_CentralMonitor_eqFunction_28(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,28};
  modelica_boolean tmp18;
  RELATIONHYSTERESIS(tmp18, ((modelica_real)((modelica_integer)data->localData[0]->integerVars[1] /* heatOnPermission variable */)), 0.5, 14, Greater);
  data->localData[0]->booleanVars[1] /* $whenCondition10 DISCRETE */ = tmp18;
  TRACE_POP
}
/*
 equation index: 29
 type: SIMPLE_ASSIGN
 $whenCondition9 = time >= nextHeartBeat
 */
void ThermostatMonitor_CentralMonitor_eqFunction_29(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,29};
  modelica_boolean tmp19;
  RELATIONHYSTERESIS(tmp19, data->localData[0]->timeValue, data->localData[0]->realVars[3] /* nextHeartBeat STATE(1) */, 13, GreaterEq);
  data->localData[0]->booleanVars[9] /* $whenCondition9 DISCRETE */ = tmp19;
  TRACE_POP
}
/*
 equation index: 30
 type: SIMPLE_ASSIGN
 $whenCondition8 = termReply > -0.5
 */
void ThermostatMonitor_CentralMonitor_eqFunction_30(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,30};
  modelica_boolean tmp20;
  RELATIONHYSTERESIS(tmp20, data->localData[0]->realVars[14] /* termReply variable */, -0.5, 12, Greater);
  data->localData[0]->booleanVars[8] /* $whenCondition8 DISCRETE */ = tmp20;
  TRACE_POP
}
/*
 equation index: 31
 type: SIMPLE_ASSIGN
 $whenCondition7 = heatReply > -0.5
 */
void ThermostatMonitor_CentralMonitor_eqFunction_31(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,31};
  modelica_boolean tmp21;
  RELATIONHYSTERESIS(tmp21, data->localData[0]->realVars[10] /* heatReply variable */, -0.5, 11, Greater);
  data->localData[0]->booleanVars[7] /* $whenCondition7 DISCRETE */ = tmp21;
  TRACE_POP
}
/*
 equation index: 32
 type: SIMPLE_ASSIGN
 $whenCondition6 = tempReply > -0.5
 */
void ThermostatMonitor_CentralMonitor_eqFunction_32(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,32};
  modelica_boolean tmp22;
  RELATIONHYSTERESIS(tmp22, data->localData[0]->realVars[12] /* tempReply variable */, -0.5, 10, Greater);
  data->localData[0]->booleanVars[6] /* $whenCondition6 DISCRETE */ = tmp22;
  TRACE_POP
}
/*
 equation index: 33
 type: SIMPLE_ASSIGN
 $whenCondition5 = tempReply < -0.5
 */
void ThermostatMonitor_CentralMonitor_eqFunction_33(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,33};
  modelica_boolean tmp23;
  RELATIONHYSTERESIS(tmp23, data->localData[0]->realVars[12] /* tempReply variable */, -0.5, 9, Less);
  data->localData[0]->booleanVars[5] /* $whenCondition5 DISCRETE */ = tmp23;
  TRACE_POP
}
/*
 equation index: 34
 type: SIMPLE_ASSIGN
 $whenCondition4 = state < 1.5
 */
void ThermostatMonitor_CentralMonitor_eqFunction_34(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,34};
  modelica_boolean tmp24;
  RELATIONHYSTERESIS(tmp24, data->localData[0]->realVars[4] /* state STATE(1) */, 1.5, 8, Less);
  data->localData[0]->booleanVars[4] /* $whenCondition4 DISCRETE */ = tmp24;
  TRACE_POP
}
/*
 equation index: 35
 type: SIMPLE_ASSIGN
 $whenCondition3 = state > 2.5 and state < 3.5
 */
void ThermostatMonitor_CentralMonitor_eqFunction_35(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,35};
  modelica_boolean tmp25;
  modelica_boolean tmp26;
  RELATIONHYSTERESIS(tmp25, data->localData[0]->realVars[4] /* state STATE(1) */, 2.5, 2, Greater);
  RELATIONHYSTERESIS(tmp26, data->localData[0]->realVars[4] /* state STATE(1) */, 3.5, 3, Less);
  data->localData[0]->booleanVars[3] /* $whenCondition3 DISCRETE */ = (tmp25 && tmp26);
  TRACE_POP
}
/*
 equation index: 36
 type: SIMPLE_ASSIGN
 $whenCondition2 = state > 3.5 and state < 4.5
 */
void ThermostatMonitor_CentralMonitor_eqFunction_36(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,36};
  modelica_boolean tmp27;
  modelica_boolean tmp28;
  RELATIONHYSTERESIS(tmp27, data->localData[0]->realVars[4] /* state STATE(1) */, 3.5, 4, Greater);
  RELATIONHYSTERESIS(tmp28, data->localData[0]->realVars[4] /* state STATE(1) */, 4.5, 5, Less);
  data->localData[0]->booleanVars[2] /* $whenCondition2 DISCRETE */ = (tmp27 && tmp28);
  TRACE_POP
}
/*
 equation index: 37
 type: SIMPLE_ASSIGN
 $whenCondition1 = state > 4.5
 */
void ThermostatMonitor_CentralMonitor_eqFunction_37(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,37};
  modelica_boolean tmp29;
  RELATIONHYSTERESIS(tmp29, data->localData[0]->realVars[4] /* state STATE(1) */, 4.5, 7, Greater);
  data->localData[0]->booleanVars[0] /* $whenCondition1 DISCRETE */ = tmp29;
  TRACE_POP
}
/*
 equation index: 38
 type: SIMPLE_ASSIGN
 grant = lastTermReply + lastHeatReply + lastTempReply > 2.5
 */
void ThermostatMonitor_CentralMonitor_eqFunction_38(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,38};
  modelica_boolean tmp30;
  RELATIONHYSTERESIS(tmp30, data->localData[0]->realVars[2] /* lastTermReply STATE(1) */ + data->localData[0]->realVars[0] /* lastHeatReply STATE(1) */ + data->localData[0]->realVars[1] /* lastTempReply STATE(1) */, 2.5, 6, Greater);
  data->localData[0]->booleanVars[10] /* grant DISCRETE */ = tmp30;
  TRACE_POP
}
/*
 equation index: 39
 type: SIMPLE_ASSIGN
 heatOnGrant = if state > 4.5 and grant then 1.0 else 0.0
 */
void ThermostatMonitor_CentralMonitor_eqFunction_39(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,39};
  modelica_boolean tmp31;
  RELATIONHYSTERESIS(tmp31, data->localData[0]->realVars[4] /* state STATE(1) */, 4.5, 7, Greater);
  data->localData[0]->integerVars[0] /* heatOnGrant DISCRETE */ = ((tmp31 && data->localData[0]->booleanVars[10] /* grant DISCRETE */)?1.0:0.0);
  TRACE_POP
}
/*
 equation index: 40
 type: SIMPLE_ASSIGN
 der(lastTempReply) = 0.0
 */
void ThermostatMonitor_CentralMonitor_eqFunction_40(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,40};
  data->localData[0]->realVars[6] /* der(lastTempReply) STATE_DER */ = 0.0;
  TRACE_POP
}
/*
 equation index: 41
 type: SIMPLE_ASSIGN
 der(lastHeatReply) = 0.0
 */
void ThermostatMonitor_CentralMonitor_eqFunction_41(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,41};
  data->localData[0]->realVars[5] /* der(lastHeatReply) STATE_DER */ = 0.0;
  TRACE_POP
}
/*
 equation index: 42
 type: SIMPLE_ASSIGN
 der(lastTermReply) = 0.0
 */
void ThermostatMonitor_CentralMonitor_eqFunction_42(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,42};
  data->localData[0]->realVars[7] /* der(lastTermReply) STATE_DER */ = 0.0;
  TRACE_POP
}
/*
 equation index: 43
 type: SIMPLE_ASSIGN
 der(nextHeartBeat) = 0.0
 */
void ThermostatMonitor_CentralMonitor_eqFunction_43(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,43};
  data->localData[0]->realVars[8] /* der(nextHeartBeat) STATE_DER */ = 0.0;
  TRACE_POP
}
/*
 equation index: 44
 type: SIMPLE_ASSIGN
 der(state) = 0.0
 */
void ThermostatMonitor_CentralMonitor_eqFunction_44(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,44};
  data->localData[0]->realVars[9] /* der(state) STATE_DER */ = 0.0;
  TRACE_POP
}
/*
 equation index: 45
 type: SIMPLE_ASSIGN
 tempReq = if state > 3.5 and state < 4.5 then 1.0 else 0.0
 */
void ThermostatMonitor_CentralMonitor_eqFunction_45(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,45};
  modelica_boolean tmp32;
  modelica_boolean tmp33;
  RELATIONHYSTERESIS(tmp32, data->localData[0]->realVars[4] /* state STATE(1) */, 3.5, 4, Greater);
  RELATIONHYSTERESIS(tmp33, data->localData[0]->realVars[4] /* state STATE(1) */, 4.5, 5, Less);
  data->localData[0]->realVars[13] /* tempReq variable */ = ((tmp32 && tmp33)?1.0:0.0);
  TRACE_POP
}
/*
 equation index: 46
 type: SIMPLE_ASSIGN
 heatReq = if state > 2.5 and state < 3.5 then 1.0 else 0.0
 */
void ThermostatMonitor_CentralMonitor_eqFunction_46(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,46};
  modelica_boolean tmp34;
  modelica_boolean tmp35;
  RELATIONHYSTERESIS(tmp34, data->localData[0]->realVars[4] /* state STATE(1) */, 2.5, 2, Greater);
  RELATIONHYSTERESIS(tmp35, data->localData[0]->realVars[4] /* state STATE(1) */, 3.5, 3, Less);
  data->localData[0]->realVars[11] /* heatReq variable */ = ((tmp34 && tmp35)?1.0:0.0);
  TRACE_POP
}
/*
 equation index: 47
 type: SIMPLE_ASSIGN
 termReq = if state > 1.5 and state < 2.5 then 1.0 else 0.0
 */
void ThermostatMonitor_CentralMonitor_eqFunction_47(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,47};
  modelica_boolean tmp36;
  modelica_boolean tmp37;
  RELATIONHYSTERESIS(tmp36, data->localData[0]->realVars[4] /* state STATE(1) */, 1.5, 0, Greater);
  RELATIONHYSTERESIS(tmp37, data->localData[0]->realVars[4] /* state STATE(1) */, 2.5, 1, Less);
  data->localData[0]->realVars[15] /* termReq variable */ = ((tmp36 && tmp37)?1.0:0.0);
  TRACE_POP
}
/*
 equation index: 57
 type: WHEN
 
 when {$whenCondition10} then
   reinit(state,  2.0);
 end when;
 */
void ThermostatMonitor_CentralMonitor_eqFunction_57(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,57};
  if((data->localData[0]->booleanVars[1] /* $whenCondition10 DISCRETE */ && !data->simulationInfo->booleanVarsPre[1] /* $whenCondition10 DISCRETE */ /* edge */))
  {
    data->localData[0]->realVars[4] /* state STATE(1) */ = 2.0;
    infoStreamPrint(LOG_EVENTS, 0, "reinit state = %g", data->localData[0]->realVars[4] /* state STATE(1) */);
    data->simulationInfo->needToIterate = 1;
  }
  TRACE_POP
}
/*
 equation index: 56
 type: WHEN
 
 when {$whenCondition9} then
   reinit(state,  2.0);
 end when;
 */
void ThermostatMonitor_CentralMonitor_eqFunction_56(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,56};
  if((data->localData[0]->booleanVars[9] /* $whenCondition9 DISCRETE */ && !data->simulationInfo->booleanVarsPre[9] /* $whenCondition9 DISCRETE */ /* edge */))
  {
    data->localData[0]->realVars[4] /* state STATE(1) */ = 2.0;
    infoStreamPrint(LOG_EVENTS, 0, "reinit state = %g", data->localData[0]->realVars[4] /* state STATE(1) */);
    data->simulationInfo->needToIterate = 1;
  }
  TRACE_POP
}
/*
 equation index: 55
 type: WHEN
 
 when {$whenCondition8} then
   reinit(state,  3.0);
 end when;
 */
void ThermostatMonitor_CentralMonitor_eqFunction_55(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,55};
  if((data->localData[0]->booleanVars[8] /* $whenCondition8 DISCRETE */ && !data->simulationInfo->booleanVarsPre[8] /* $whenCondition8 DISCRETE */ /* edge */))
  {
    data->localData[0]->realVars[4] /* state STATE(1) */ = 3.0;
    infoStreamPrint(LOG_EVENTS, 0, "reinit state = %g", data->localData[0]->realVars[4] /* state STATE(1) */);
    data->simulationInfo->needToIterate = 1;
  }
  TRACE_POP
}
/*
 equation index: 54
 type: WHEN
 
 when {$whenCondition7} then
   reinit(state,  4.0);
 end when;
 */
void ThermostatMonitor_CentralMonitor_eqFunction_54(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,54};
  if((data->localData[0]->booleanVars[7] /* $whenCondition7 DISCRETE */ && !data->simulationInfo->booleanVarsPre[7] /* $whenCondition7 DISCRETE */ /* edge */))
  {
    data->localData[0]->realVars[4] /* state STATE(1) */ = 4.0;
    infoStreamPrint(LOG_EVENTS, 0, "reinit state = %g", data->localData[0]->realVars[4] /* state STATE(1) */);
    data->simulationInfo->needToIterate = 1;
  }
  TRACE_POP
}
/*
 equation index: 53
 type: WHEN
 
 when {$whenCondition6} then
   reinit(state,  5.0);
 end when;
 */
void ThermostatMonitor_CentralMonitor_eqFunction_53(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,53};
  if((data->localData[0]->booleanVars[6] /* $whenCondition6 DISCRETE */ && !data->simulationInfo->booleanVarsPre[6] /* $whenCondition6 DISCRETE */ /* edge */))
  {
    data->localData[0]->realVars[4] /* state STATE(1) */ = 5.0;
    infoStreamPrint(LOG_EVENTS, 0, "reinit state = %g", data->localData[0]->realVars[4] /* state STATE(1) */);
    data->simulationInfo->needToIterate = 1;
  }
  TRACE_POP
}
/*
 equation index: 52
 type: WHEN
 
 when {$whenCondition5} then
   reinit(state,  1.0);
 end when;
 */
void ThermostatMonitor_CentralMonitor_eqFunction_52(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,52};
  if((data->localData[0]->booleanVars[5] /* $whenCondition5 DISCRETE */ && !data->simulationInfo->booleanVarsPre[5] /* $whenCondition5 DISCRETE */ /* edge */))
  {
    data->localData[0]->realVars[4] /* state STATE(1) */ = 1.0;
    infoStreamPrint(LOG_EVENTS, 0, "reinit state = %g", data->localData[0]->realVars[4] /* state STATE(1) */);
    data->simulationInfo->needToIterate = 1;
  }
  TRACE_POP
}
/*
 equation index: 51
 type: WHEN
 
 when {$whenCondition4} then
   reinit(nextHeartBeat,  180.0 + time);
 end when;
 */
void ThermostatMonitor_CentralMonitor_eqFunction_51(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,51};
  if((data->localData[0]->booleanVars[4] /* $whenCondition4 DISCRETE */ && !data->simulationInfo->booleanVarsPre[4] /* $whenCondition4 DISCRETE */ /* edge */))
  {
    data->localData[0]->realVars[3] /* nextHeartBeat STATE(1) */ = 180.0 + data->localData[0]->timeValue;
    infoStreamPrint(LOG_EVENTS, 0, "reinit nextHeartBeat = %g", data->localData[0]->realVars[3] /* nextHeartBeat STATE(1) */);
    data->simulationInfo->needToIterate = 1;
  }
  TRACE_POP
}
/*
 equation index: 50
 type: WHEN
 
 when {$whenCondition3} then
   reinit(lastTermReply,  termReply);
 end when;
 */
void ThermostatMonitor_CentralMonitor_eqFunction_50(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,50};
  if((data->localData[0]->booleanVars[3] /* $whenCondition3 DISCRETE */ && !data->simulationInfo->booleanVarsPre[3] /* $whenCondition3 DISCRETE */ /* edge */))
  {
    data->localData[0]->realVars[2] /* lastTermReply STATE(1) */ = data->localData[0]->realVars[14] /* termReply variable */;
    infoStreamPrint(LOG_EVENTS, 0, "reinit lastTermReply = %g", data->localData[0]->realVars[2] /* lastTermReply STATE(1) */);
    data->simulationInfo->needToIterate = 1;
  }
  TRACE_POP
}
/*
 equation index: 49
 type: WHEN
 
 when {$whenCondition2} then
   reinit(lastHeatReply,  heatReply);
 end when;
 */
void ThermostatMonitor_CentralMonitor_eqFunction_49(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,49};
  if((data->localData[0]->booleanVars[2] /* $whenCondition2 DISCRETE */ && !data->simulationInfo->booleanVarsPre[2] /* $whenCondition2 DISCRETE */ /* edge */))
  {
    data->localData[0]->realVars[0] /* lastHeatReply STATE(1) */ = data->localData[0]->realVars[10] /* heatReply variable */;
    infoStreamPrint(LOG_EVENTS, 0, "reinit lastHeatReply = %g", data->localData[0]->realVars[0] /* lastHeatReply STATE(1) */);
    data->simulationInfo->needToIterate = 1;
  }
  TRACE_POP
}
/*
 equation index: 48
 type: WHEN
 
 when {$whenCondition1} then
   reinit(lastTempReply,  tempReply);
 end when;
 */
void ThermostatMonitor_CentralMonitor_eqFunction_48(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,48};
  if((data->localData[0]->booleanVars[0] /* $whenCondition1 DISCRETE */ && !data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */ /* edge */))
  {
    data->localData[0]->realVars[1] /* lastTempReply STATE(1) */ = data->localData[0]->realVars[12] /* tempReply variable */;
    infoStreamPrint(LOG_EVENTS, 0, "reinit lastTempReply = %g", data->localData[0]->realVars[1] /* lastTempReply STATE(1) */);
    data->simulationInfo->needToIterate = 1;
  }
  TRACE_POP
}


int ThermostatMonitor_CentralMonitor_functionDAE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  int equationIndexes[1] = {0};
  
  data->simulationInfo->needToIterate = 0;
  data->simulationInfo->discreteCall = 1;
  ThermostatMonitor_CentralMonitor_functionLocalKnownVars(data, threadData);
  ThermostatMonitor_CentralMonitor_eqFunction_28(data, threadData);

  ThermostatMonitor_CentralMonitor_eqFunction_29(data, threadData);

  ThermostatMonitor_CentralMonitor_eqFunction_30(data, threadData);

  ThermostatMonitor_CentralMonitor_eqFunction_31(data, threadData);

  ThermostatMonitor_CentralMonitor_eqFunction_32(data, threadData);

  ThermostatMonitor_CentralMonitor_eqFunction_33(data, threadData);

  ThermostatMonitor_CentralMonitor_eqFunction_34(data, threadData);

  ThermostatMonitor_CentralMonitor_eqFunction_35(data, threadData);

  ThermostatMonitor_CentralMonitor_eqFunction_36(data, threadData);

  ThermostatMonitor_CentralMonitor_eqFunction_37(data, threadData);

  ThermostatMonitor_CentralMonitor_eqFunction_38(data, threadData);

  ThermostatMonitor_CentralMonitor_eqFunction_39(data, threadData);

  ThermostatMonitor_CentralMonitor_eqFunction_40(data, threadData);

  ThermostatMonitor_CentralMonitor_eqFunction_41(data, threadData);

  ThermostatMonitor_CentralMonitor_eqFunction_42(data, threadData);

  ThermostatMonitor_CentralMonitor_eqFunction_43(data, threadData);

  ThermostatMonitor_CentralMonitor_eqFunction_44(data, threadData);

  ThermostatMonitor_CentralMonitor_eqFunction_45(data, threadData);

  ThermostatMonitor_CentralMonitor_eqFunction_46(data, threadData);

  ThermostatMonitor_CentralMonitor_eqFunction_47(data, threadData);

  ThermostatMonitor_CentralMonitor_eqFunction_57(data, threadData);

  ThermostatMonitor_CentralMonitor_eqFunction_56(data, threadData);

  ThermostatMonitor_CentralMonitor_eqFunction_55(data, threadData);

  ThermostatMonitor_CentralMonitor_eqFunction_54(data, threadData);

  ThermostatMonitor_CentralMonitor_eqFunction_53(data, threadData);

  ThermostatMonitor_CentralMonitor_eqFunction_52(data, threadData);

  ThermostatMonitor_CentralMonitor_eqFunction_51(data, threadData);

  ThermostatMonitor_CentralMonitor_eqFunction_50(data, threadData);

  ThermostatMonitor_CentralMonitor_eqFunction_49(data, threadData);

  ThermostatMonitor_CentralMonitor_eqFunction_48(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}


int ThermostatMonitor_CentralMonitor_functionLocalKnownVars(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


/* forwarded equations */
extern void ThermostatMonitor_CentralMonitor_eqFunction_40(DATA* data, threadData_t *threadData);
extern void ThermostatMonitor_CentralMonitor_eqFunction_41(DATA* data, threadData_t *threadData);
extern void ThermostatMonitor_CentralMonitor_eqFunction_42(DATA* data, threadData_t *threadData);
extern void ThermostatMonitor_CentralMonitor_eqFunction_43(DATA* data, threadData_t *threadData);
extern void ThermostatMonitor_CentralMonitor_eqFunction_44(DATA* data, threadData_t *threadData);

static void functionODE_system0(DATA *data, threadData_t *threadData)
{
  ThermostatMonitor_CentralMonitor_eqFunction_40(data, threadData);

  ThermostatMonitor_CentralMonitor_eqFunction_41(data, threadData);

  ThermostatMonitor_CentralMonitor_eqFunction_42(data, threadData);

  ThermostatMonitor_CentralMonitor_eqFunction_43(data, threadData);

  ThermostatMonitor_CentralMonitor_eqFunction_44(data, threadData);
}

int ThermostatMonitor_CentralMonitor_functionODE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  data->simulationInfo->callStatistics.functionODE++;
  
  ThermostatMonitor_CentralMonitor_functionLocalKnownVars(data, threadData);
  functionODE_system0(data, threadData);

  
  TRACE_POP
  return 0;
}

#ifdef FMU_EXPERIMENTAL
#endif
/* forward the main in the simulation runtime */
extern int _main_SimulationRuntime(int argc, char**argv, DATA *data, threadData_t *threadData);

#include "ThermostatMonitor_CentralMonitor_12jac.h"
#include "ThermostatMonitor_CentralMonitor_13opt.h"

struct OpenModelicaGeneratedFunctionCallbacks ThermostatMonitor_CentralMonitor_callback = {
   NULL,
   NULL,
   NULL,
   ThermostatMonitor_CentralMonitor_callExternalObjectDestructors,
   NULL,
   NULL,
   NULL,
   #if !defined(OMC_NO_STATESELECTION)
   ThermostatMonitor_CentralMonitor_initializeStateSets,
   #else
   NULL,
   #endif
   ThermostatMonitor_CentralMonitor_initializeDAEmodeData,
   ThermostatMonitor_CentralMonitor_functionODE,
   ThermostatMonitor_CentralMonitor_functionAlgebraics,
   ThermostatMonitor_CentralMonitor_functionDAE,
   ThermostatMonitor_CentralMonitor_functionLocalKnownVars,
   ThermostatMonitor_CentralMonitor_input_function,
   ThermostatMonitor_CentralMonitor_input_function_init,
   ThermostatMonitor_CentralMonitor_input_function_updateStartValues,
   ThermostatMonitor_CentralMonitor_output_function,
   ThermostatMonitor_CentralMonitor_function_storeDelayed,
   ThermostatMonitor_CentralMonitor_updateBoundVariableAttributes,
   ThermostatMonitor_CentralMonitor_functionInitialEquations,
   0, /* useHomotopy - 0: no homotopy or local homotopy, 1: global homotopy, 2: new global homotopy approach */
   ThermostatMonitor_CentralMonitor_functionInitialEquations_lambda0,
   ThermostatMonitor_CentralMonitor_functionRemovedInitialEquations,
   ThermostatMonitor_CentralMonitor_updateBoundParameters,
   ThermostatMonitor_CentralMonitor_checkForAsserts,
   ThermostatMonitor_CentralMonitor_function_ZeroCrossingsEquations,
   ThermostatMonitor_CentralMonitor_function_ZeroCrossings,
   ThermostatMonitor_CentralMonitor_function_updateRelations,
   ThermostatMonitor_CentralMonitor_checkForDiscreteChanges,
   ThermostatMonitor_CentralMonitor_zeroCrossingDescription,
   ThermostatMonitor_CentralMonitor_relationDescription,
   ThermostatMonitor_CentralMonitor_function_initSample,
   ThermostatMonitor_CentralMonitor_INDEX_JAC_A,
   ThermostatMonitor_CentralMonitor_INDEX_JAC_B,
   ThermostatMonitor_CentralMonitor_INDEX_JAC_C,
   ThermostatMonitor_CentralMonitor_INDEX_JAC_D,
   ThermostatMonitor_CentralMonitor_initialAnalyticJacobianA,
   ThermostatMonitor_CentralMonitor_initialAnalyticJacobianB,
   ThermostatMonitor_CentralMonitor_initialAnalyticJacobianC,
   ThermostatMonitor_CentralMonitor_initialAnalyticJacobianD,
   ThermostatMonitor_CentralMonitor_functionJacA_column,
   ThermostatMonitor_CentralMonitor_functionJacB_column,
   ThermostatMonitor_CentralMonitor_functionJacC_column,
   ThermostatMonitor_CentralMonitor_functionJacD_column,
   ThermostatMonitor_CentralMonitor_linear_model_frame,
   ThermostatMonitor_CentralMonitor_linear_model_datarecovery_frame,
   ThermostatMonitor_CentralMonitor_mayer,
   ThermostatMonitor_CentralMonitor_lagrange,
   ThermostatMonitor_CentralMonitor_pickUpBoundsForInputsInOptimization,
   ThermostatMonitor_CentralMonitor_setInputData,
   ThermostatMonitor_CentralMonitor_getTimeGrid,
   ThermostatMonitor_CentralMonitor_symbolicInlineSystem,
   ThermostatMonitor_CentralMonitor_function_initSynchronous,
   ThermostatMonitor_CentralMonitor_function_updateSynchronous,
   ThermostatMonitor_CentralMonitor_function_equationsSynchronous,
   ThermostatMonitor_CentralMonitor_read_input_fmu,
   #ifdef FMU_EXPERIMENTAL
   ThermostatMonitor_CentralMonitor_functionODE_Partial,
   ThermostatMonitor_CentralMonitor_functionFMIJacobian,
   #endif
   ThermostatMonitor_CentralMonitor_inputNames
};

void ThermostatMonitor_CentralMonitor_setupDataStruc(DATA *data, threadData_t *threadData)
{
  assertStreamPrint(threadData,0!=data, "Error while initialize Data");
  data->callback = &ThermostatMonitor_CentralMonitor_callback;
  data->modelData->modelName = "ThermostatMonitor.CentralMonitor";
  data->modelData->modelFilePrefix = "ThermostatMonitor_CentralMonitor";
  data->modelData->resultFileName = NULL;
  data->modelData->modelDir = "/home/farkasr/git/OMSimulator/StepSizeController/Thermostat";
  data->modelData->modelGUID = "{0f62d11e-c13e-4487-966f-02951abfc8fb}";
  data->modelData->initXMLData = NULL;
  data->modelData->modelDataXml.infoXMLData =
  #if defined(OMC_MINIMAL_METADATA)
    NULL;
  #else
  #include "ThermostatMonitor_CentralMonitor_info.c"
  #endif
  ;
  
  data->modelData->nStates = 5;
  data->modelData->nVariablesReal = 16;
  data->modelData->nDiscreteReal = 0;
  data->modelData->nVariablesInteger = 2;
  data->modelData->nVariablesBoolean = 11;
  data->modelData->nVariablesString = 0;
  data->modelData->nParametersReal = 0;
  data->modelData->nParametersInteger = 0;
  data->modelData->nParametersBoolean = 0;
  data->modelData->nParametersString = 0;
  data->modelData->nInputVars = 4;
  data->modelData->nOutputVars = 8;
  
  data->modelData->nAliasReal = 0;
  data->modelData->nAliasInteger = 0;
  data->modelData->nAliasBoolean = 0;
  data->modelData->nAliasString = 0;
  
  data->modelData->nZeroCrossings = 17;
  data->modelData->nSamples = 0;
  data->modelData->nRelations = 15;
  data->modelData->nMathEvents = 0;
  data->modelData->nExtObjs = 0;
  data->modelData->modelDataXml.fileName = "ThermostatMonitor_CentralMonitor_info.json";
  data->modelData->modelDataXml.modelInfoXmlLength = 0;
  data->modelData->modelDataXml.nFunctions = 0;
  data->modelData->modelDataXml.nProfileBlocks = 0;
  data->modelData->modelDataXml.nEquations = 58;
  data->modelData->nMixedSystems = 0;
  data->modelData->nLinearSystems = 0;
  data->modelData->nNonLinearSystems = 0;
  data->modelData->nStateSets = 0;
  data->modelData->nJacobians = 4;
  data->modelData->nOptimizeConstraints = 0;
  data->modelData->nOptimizeFinalConstraints = 0;
  
  data->modelData->nDelayExpressions = 0;
  
  data->modelData->nClocks = 0;
  data->modelData->nSubClocks = 0;
  
  data->modelData->nSensitivityVars = 0;
  data->modelData->nSensitivityParamVars = 0;
}

#ifdef __cplusplus
}
#endif

static int rml_execution_failed()
{
  fflush(NULL);
  fprintf(stderr, "Execution failed!\n");
  fflush(NULL);
  return 1;
}

