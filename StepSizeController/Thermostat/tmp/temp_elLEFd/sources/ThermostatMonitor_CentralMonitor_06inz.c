/* Initialization */
#include "ThermostatMonitor_CentralMonitor_model.h"
#include "ThermostatMonitor_CentralMonitor_11mix.h"
#include "ThermostatMonitor_CentralMonitor_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

void ThermostatMonitor_CentralMonitor_functionInitialEquations_0(DATA *data, threadData_t *threadData);


/*
 equation index: 1
 type: SIMPLE_ASSIGN
 lastTempReply = $START.lastTempReply
 */
void ThermostatMonitor_CentralMonitor_eqFunction_1(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1};
  data->localData[0]->realVars[1] /* lastTempReply STATE(1) */ = data->modelData->realVarsData[1].attribute /* lastTempReply STATE(1) */.start;
  TRACE_POP
}

/*
 equation index: 2
 type: SIMPLE_ASSIGN
 state = 1.0
 */
void ThermostatMonitor_CentralMonitor_eqFunction_2(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2};
  data->localData[0]->realVars[4] /* state STATE(1) */ = 1.0;
  TRACE_POP
}

/*
 equation index: 3
 type: SIMPLE_ASSIGN
 $whenCondition4 = state < 1.5
 */
void ThermostatMonitor_CentralMonitor_eqFunction_3(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3};
  modelica_boolean tmp0;
  tmp0 = Less(data->localData[0]->realVars[4] /* state STATE(1) */,1.5);
  data->localData[0]->booleanVars[4] /* $whenCondition4 DISCRETE */ = tmp0;
  TRACE_POP
}

/*
 equation index: 4
 type: SIMPLE_ASSIGN
 $whenCondition3 = state > 2.5 and state < 3.5
 */
void ThermostatMonitor_CentralMonitor_eqFunction_4(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,4};
  modelica_boolean tmp1;
  modelica_boolean tmp2;
  tmp1 = Greater(data->localData[0]->realVars[4] /* state STATE(1) */,2.5);
  tmp2 = Less(data->localData[0]->realVars[4] /* state STATE(1) */,3.5);
  data->localData[0]->booleanVars[3] /* $whenCondition3 DISCRETE */ = (tmp1 && tmp2);
  TRACE_POP
}

/*
 equation index: 5
 type: SIMPLE_ASSIGN
 $whenCondition2 = state > 3.5 and state < 4.5
 */
void ThermostatMonitor_CentralMonitor_eqFunction_5(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,5};
  modelica_boolean tmp3;
  modelica_boolean tmp4;
  tmp3 = Greater(data->localData[0]->realVars[4] /* state STATE(1) */,3.5);
  tmp4 = Less(data->localData[0]->realVars[4] /* state STATE(1) */,4.5);
  data->localData[0]->booleanVars[2] /* $whenCondition2 DISCRETE */ = (tmp3 && tmp4);
  TRACE_POP
}

/*
 equation index: 6
 type: SIMPLE_ASSIGN
 $whenCondition1 = state > 4.5
 */
void ThermostatMonitor_CentralMonitor_eqFunction_6(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,6};
  modelica_boolean tmp5;
  tmp5 = Greater(data->localData[0]->realVars[4] /* state STATE(1) */,4.5);
  data->localData[0]->booleanVars[0] /* $whenCondition1 DISCRETE */ = tmp5;
  TRACE_POP
}

/*
 equation index: 7
 type: SIMPLE_ASSIGN
 tempReq = if state > 3.5 and state < 4.5 then 1.0 else 0.0
 */
void ThermostatMonitor_CentralMonitor_eqFunction_7(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,7};
  modelica_boolean tmp6;
  modelica_boolean tmp7;
  tmp6 = Greater(data->localData[0]->realVars[4] /* state STATE(1) */,3.5);
  tmp7 = Less(data->localData[0]->realVars[4] /* state STATE(1) */,4.5);
  data->localData[0]->realVars[13] /* tempReq variable */ = ((tmp6 && tmp7)?1.0:0.0);
  TRACE_POP
}

/*
 equation index: 8
 type: SIMPLE_ASSIGN
 heatReq = if state > 2.5 and state < 3.5 then 1.0 else 0.0
 */
void ThermostatMonitor_CentralMonitor_eqFunction_8(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,8};
  modelica_boolean tmp8;
  modelica_boolean tmp9;
  tmp8 = Greater(data->localData[0]->realVars[4] /* state STATE(1) */,2.5);
  tmp9 = Less(data->localData[0]->realVars[4] /* state STATE(1) */,3.5);
  data->localData[0]->realVars[11] /* heatReq variable */ = ((tmp8 && tmp9)?1.0:0.0);
  TRACE_POP
}

/*
 equation index: 9
 type: SIMPLE_ASSIGN
 termReq = if state > 1.5 and state < 2.5 then 1.0 else 0.0
 */
void ThermostatMonitor_CentralMonitor_eqFunction_9(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,9};
  modelica_boolean tmp10;
  modelica_boolean tmp11;
  tmp10 = Greater(data->localData[0]->realVars[4] /* state STATE(1) */,1.5);
  tmp11 = Less(data->localData[0]->realVars[4] /* state STATE(1) */,2.5);
  data->localData[0]->realVars[15] /* termReq variable */ = ((tmp10 && tmp11)?1.0:0.0);
  TRACE_POP
}

/*
 equation index: 10
 type: SIMPLE_ASSIGN
 lastHeatReply = $START.lastHeatReply
 */
void ThermostatMonitor_CentralMonitor_eqFunction_10(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,10};
  data->localData[0]->realVars[0] /* lastHeatReply STATE(1) */ = data->modelData->realVarsData[0].attribute /* lastHeatReply STATE(1) */.start;
  TRACE_POP
}

/*
 equation index: 11
 type: SIMPLE_ASSIGN
 lastTermReply = $START.lastTermReply
 */
void ThermostatMonitor_CentralMonitor_eqFunction_11(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,11};
  data->localData[0]->realVars[2] /* lastTermReply STATE(1) */ = data->modelData->realVarsData[2].attribute /* lastTermReply STATE(1) */.start;
  TRACE_POP
}

/*
 equation index: 12
 type: SIMPLE_ASSIGN
 grant = lastTermReply + lastHeatReply + lastTempReply > 2.5
 */
void ThermostatMonitor_CentralMonitor_eqFunction_12(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,12};
  modelica_boolean tmp12;
  tmp12 = Greater(data->localData[0]->realVars[2] /* lastTermReply STATE(1) */ + data->localData[0]->realVars[0] /* lastHeatReply STATE(1) */ + data->localData[0]->realVars[1] /* lastTempReply STATE(1) */,2.5);
  data->localData[0]->booleanVars[10] /* grant DISCRETE */ = tmp12;
  TRACE_POP
}

/*
 equation index: 13
 type: SIMPLE_ASSIGN
 heatOnGrant = if state > 4.5 and grant then 1.0 else 0.0
 */
void ThermostatMonitor_CentralMonitor_eqFunction_13(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,13};
  modelica_boolean tmp13;
  tmp13 = Greater(data->localData[0]->realVars[4] /* state STATE(1) */,4.5);
  data->localData[0]->integerVars[0] /* heatOnGrant DISCRETE */ = ((tmp13 && data->localData[0]->booleanVars[10] /* grant DISCRETE */)?1.0:0.0);
  TRACE_POP
}

/*
 equation index: 14
 type: SIMPLE_ASSIGN
 der(state) = 0.0
 */
void ThermostatMonitor_CentralMonitor_eqFunction_14(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,14};
  data->localData[0]->realVars[9] /* der(state) STATE_DER */ = 0.0;
  TRACE_POP
}

/*
 equation index: 15
 type: SIMPLE_ASSIGN
 der(nextHeartBeat) = 0.0
 */
void ThermostatMonitor_CentralMonitor_eqFunction_15(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,15};
  data->localData[0]->realVars[8] /* der(nextHeartBeat) STATE_DER */ = 0.0;
  TRACE_POP
}

/*
 equation index: 16
 type: SIMPLE_ASSIGN
 der(lastTermReply) = 0.0
 */
void ThermostatMonitor_CentralMonitor_eqFunction_16(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,16};
  data->localData[0]->realVars[7] /* der(lastTermReply) STATE_DER */ = 0.0;
  TRACE_POP
}

/*
 equation index: 17
 type: SIMPLE_ASSIGN
 der(lastHeatReply) = 0.0
 */
void ThermostatMonitor_CentralMonitor_eqFunction_17(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,17};
  data->localData[0]->realVars[5] /* der(lastHeatReply) STATE_DER */ = 0.0;
  TRACE_POP
}

/*
 equation index: 18
 type: SIMPLE_ASSIGN
 der(lastTempReply) = 0.0
 */
void ThermostatMonitor_CentralMonitor_eqFunction_18(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,18};
  data->localData[0]->realVars[6] /* der(lastTempReply) STATE_DER */ = 0.0;
  TRACE_POP
}

/*
 equation index: 19
 type: SIMPLE_ASSIGN
 $whenCondition5 = tempReply < -0.5
 */
void ThermostatMonitor_CentralMonitor_eqFunction_19(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,19};
  modelica_boolean tmp14;
  tmp14 = Less(data->localData[0]->realVars[12] /* tempReply variable */,-0.5);
  data->localData[0]->booleanVars[5] /* $whenCondition5 DISCRETE */ = tmp14;
  TRACE_POP
}

/*
 equation index: 20
 type: SIMPLE_ASSIGN
 $whenCondition6 = tempReply > -0.5
 */
void ThermostatMonitor_CentralMonitor_eqFunction_20(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,20};
  modelica_boolean tmp15;
  tmp15 = Greater(data->localData[0]->realVars[12] /* tempReply variable */,-0.5);
  data->localData[0]->booleanVars[6] /* $whenCondition6 DISCRETE */ = tmp15;
  TRACE_POP
}

/*
 equation index: 21
 type: SIMPLE_ASSIGN
 $whenCondition7 = heatReply > -0.5
 */
void ThermostatMonitor_CentralMonitor_eqFunction_21(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,21};
  modelica_boolean tmp16;
  tmp16 = Greater(data->localData[0]->realVars[10] /* heatReply variable */,-0.5);
  data->localData[0]->booleanVars[7] /* $whenCondition7 DISCRETE */ = tmp16;
  TRACE_POP
}

/*
 equation index: 22
 type: SIMPLE_ASSIGN
 $whenCondition8 = termReply > -0.5
 */
void ThermostatMonitor_CentralMonitor_eqFunction_22(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,22};
  modelica_boolean tmp17;
  tmp17 = Greater(data->localData[0]->realVars[14] /* termReply variable */,-0.5);
  data->localData[0]->booleanVars[8] /* $whenCondition8 DISCRETE */ = tmp17;
  TRACE_POP
}

/*
 equation index: 23
 type: SIMPLE_ASSIGN
 nextHeartBeat = 180.0
 */
void ThermostatMonitor_CentralMonitor_eqFunction_23(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,23};
  data->localData[0]->realVars[3] /* nextHeartBeat STATE(1) */ = 180.0;
  TRACE_POP
}

/*
 equation index: 24
 type: SIMPLE_ASSIGN
 $whenCondition9 = time >= nextHeartBeat
 */
void ThermostatMonitor_CentralMonitor_eqFunction_24(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,24};
  modelica_boolean tmp18;
  tmp18 = GreaterEq(data->localData[0]->timeValue,data->localData[0]->realVars[3] /* nextHeartBeat STATE(1) */);
  data->localData[0]->booleanVars[9] /* $whenCondition9 DISCRETE */ = tmp18;
  TRACE_POP
}

/*
 equation index: 25
 type: SIMPLE_ASSIGN
 $whenCondition10 = (*Real*)(heatOnPermission) > 0.5
 */
void ThermostatMonitor_CentralMonitor_eqFunction_25(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,25};
  modelica_boolean tmp19;
  tmp19 = Greater(((modelica_real)((modelica_integer)data->localData[0]->integerVars[1] /* heatOnPermission variable */)),0.5);
  data->localData[0]->booleanVars[1] /* $whenCondition10 DISCRETE */ = tmp19;
  TRACE_POP
}
void ThermostatMonitor_CentralMonitor_functionInitialEquations_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  ThermostatMonitor_CentralMonitor_eqFunction_1(data, threadData);
  ThermostatMonitor_CentralMonitor_eqFunction_2(data, threadData);
  ThermostatMonitor_CentralMonitor_eqFunction_3(data, threadData);
  ThermostatMonitor_CentralMonitor_eqFunction_4(data, threadData);
  ThermostatMonitor_CentralMonitor_eqFunction_5(data, threadData);
  ThermostatMonitor_CentralMonitor_eqFunction_6(data, threadData);
  ThermostatMonitor_CentralMonitor_eqFunction_7(data, threadData);
  ThermostatMonitor_CentralMonitor_eqFunction_8(data, threadData);
  ThermostatMonitor_CentralMonitor_eqFunction_9(data, threadData);
  ThermostatMonitor_CentralMonitor_eqFunction_10(data, threadData);
  ThermostatMonitor_CentralMonitor_eqFunction_11(data, threadData);
  ThermostatMonitor_CentralMonitor_eqFunction_12(data, threadData);
  ThermostatMonitor_CentralMonitor_eqFunction_13(data, threadData);
  ThermostatMonitor_CentralMonitor_eqFunction_14(data, threadData);
  ThermostatMonitor_CentralMonitor_eqFunction_15(data, threadData);
  ThermostatMonitor_CentralMonitor_eqFunction_16(data, threadData);
  ThermostatMonitor_CentralMonitor_eqFunction_17(data, threadData);
  ThermostatMonitor_CentralMonitor_eqFunction_18(data, threadData);
  ThermostatMonitor_CentralMonitor_eqFunction_19(data, threadData);
  ThermostatMonitor_CentralMonitor_eqFunction_20(data, threadData);
  ThermostatMonitor_CentralMonitor_eqFunction_21(data, threadData);
  ThermostatMonitor_CentralMonitor_eqFunction_22(data, threadData);
  ThermostatMonitor_CentralMonitor_eqFunction_23(data, threadData);
  ThermostatMonitor_CentralMonitor_eqFunction_24(data, threadData);
  ThermostatMonitor_CentralMonitor_eqFunction_25(data, threadData);
  TRACE_POP
}


int ThermostatMonitor_CentralMonitor_functionInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  ThermostatMonitor_CentralMonitor_functionInitialEquations_0(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}


int ThermostatMonitor_CentralMonitor_functionInitialEquations_lambda0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}
int ThermostatMonitor_CentralMonitor_functionRemovedInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int *equationIndexes = NULL;
  double res = 0.0;

  res = data->localData[0]->realVars[13] /* tempReq variable */;
  if(fabs(res) > 1e-5)
  {
    errorStreamPrint(LOG_INIT, 0, "The initialization problem is inconsistent due to the following equation: 0 != %g = tempReq", res);
    return 1;
  }
  res = data->localData[0]->realVars[15] /* termReq variable */;
  if(fabs(res) > 1e-5)
  {
    errorStreamPrint(LOG_INIT, 0, "The initialization problem is inconsistent due to the following equation: 0 != %g = termReq", res);
    return 1;
  }
  
  TRACE_POP
  return 0;
}


#if defined(__cplusplus)
}
#endif

