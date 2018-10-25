/* Initialization */
#include "ThermostatMonitor_ThermostatOnMonitor_model.h"
#include "ThermostatMonitor_ThermostatOnMonitor_11mix.h"
#include "ThermostatMonitor_ThermostatOnMonitor_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

void ThermostatMonitor_ThermostatOnMonitor_functionInitialEquations_0(DATA *data, threadData_t *threadData);


/*
 equation index: 1
 type: SIMPLE_ASSIGN
 $PRE._turnedon = $START.turnedon
 */
void ThermostatMonitor_ThermostatOnMonitor_eqFunction_1(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1};
  data->simulationInfo->booleanVarsPre[0] /* turnedon DISCRETE */ = data->modelData->booleanVarsData[0].attribute /* turnedon DISCRETE */.start;
  TRACE_POP
}

/*
 equation index: 2
 type: SIMPLE_ASSIGN
 turnedon = turnOn > 0 or $PRE.turnedon and turnOff == 0
 */
void ThermostatMonitor_ThermostatOnMonitor_eqFunction_2(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2};
  modelica_boolean tmp0;
  tmp0 = Greater((modelica_integer)data->localData[0]->integerVars[1] /* turnOn variable */,((modelica_integer) 0));
  data->localData[0]->booleanVars[0] /* turnedon DISCRETE */ = (tmp0 || (data->simulationInfo->booleanVarsPre[0] /* turnedon DISCRETE */ && ((modelica_integer)data->localData[0]->integerVars[0] /* turnOff variable */ == ((modelica_integer) 0))));
  TRACE_POP
}

/*
 equation index: 3
 type: SIMPLE_ASSIGN
 reply = if request < 0.5 then -1.0 else if turnedon then 1.0 else 0.0
 */
void ThermostatMonitor_ThermostatOnMonitor_eqFunction_3(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3};
  modelica_boolean tmp2;
  tmp2 = Less(data->localData[0]->realVars[1] /* request variable */,0.5);
  data->localData[0]->realVars[0] /* reply variable */ = (tmp2?-1.0:(data->localData[0]->booleanVars[0] /* turnedon DISCRETE */?1.0:0.0));
  TRACE_POP
}
void ThermostatMonitor_ThermostatOnMonitor_functionInitialEquations_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  ThermostatMonitor_ThermostatOnMonitor_eqFunction_1(data, threadData);
  ThermostatMonitor_ThermostatOnMonitor_eqFunction_2(data, threadData);
  ThermostatMonitor_ThermostatOnMonitor_eqFunction_3(data, threadData);
  TRACE_POP
}


int ThermostatMonitor_ThermostatOnMonitor_functionInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  ThermostatMonitor_ThermostatOnMonitor_functionInitialEquations_0(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}


int ThermostatMonitor_ThermostatOnMonitor_functionInitialEquations_lambda0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}
int ThermostatMonitor_ThermostatOnMonitor_functionRemovedInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int *equationIndexes = NULL;
  double res = 0.0;

  
  TRACE_POP
  return 0;
}


#if defined(__cplusplus)
}
#endif

