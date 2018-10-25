/* Initialization */
#include "ThermostatMonitor_CriticalTemperatureMonitor_model.h"
#include "ThermostatMonitor_CriticalTemperatureMonitor_11mix.h"
#include "ThermostatMonitor_CriticalTemperatureMonitor_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

void ThermostatMonitor_CriticalTemperatureMonitor_functionInitialEquations_0(DATA *data, threadData_t *threadData);


/*
 equation index: 1
 type: SIMPLE_ASSIGN
 currentBandWith = 1.0
 */
void ThermostatMonitor_CriticalTemperatureMonitor_eqFunction_1(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1};
  data->localData[0]->realVars[0] /* currentBandWith variable */ = 1.0;
  TRACE_POP
}

/*
 equation index: 2
 type: SIMPLE_ASSIGN
 currentTarget = if target < temperature then target + hysteresis else target - hysteresis
 */
void ThermostatMonitor_CriticalTemperatureMonitor_eqFunction_2(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2};
  modelica_boolean tmp0;
  tmp0 = Less(data->localData[0]->realVars[5] /* target variable */,data->localData[0]->realVars[6] /* temperature variable */);
  data->localData[0]->realVars[1] /* currentTarget variable */ = (tmp0?data->localData[0]->realVars[5] /* target variable */ + data->localData[0]->realVars[2] /* hysteresis variable */:data->localData[0]->realVars[5] /* target variable */ - data->localData[0]->realVars[2] /* hysteresis variable */);
  TRACE_POP
}

/*
 equation index: 3
 type: SIMPLE_ASSIGN
 critical = temperature < target - hysteresis
 */
void ThermostatMonitor_CriticalTemperatureMonitor_eqFunction_3(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3};
  modelica_boolean tmp1;
  tmp1 = Less(data->localData[0]->realVars[6] /* temperature variable */,data->localData[0]->realVars[5] /* target variable */ - data->localData[0]->realVars[2] /* hysteresis variable */);
  data->localData[0]->booleanVars[0] /* critical DISCRETE */ = tmp1;
  TRACE_POP
}

/*
 equation index: 4
 type: SIMPLE_ASSIGN
 reply = if request < 0.5 then -1.0 else if critical then 1.0 else 0.0
 */
void ThermostatMonitor_CriticalTemperatureMonitor_eqFunction_4(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,4};
  modelica_boolean tmp2;
  tmp2 = Less(data->localData[0]->realVars[4] /* request variable */,0.5);
  data->localData[0]->realVars[3] /* reply variable */ = (tmp2?-1.0:(data->localData[0]->booleanVars[0] /* critical DISCRETE */?1.0:0.0));
  TRACE_POP
}
void ThermostatMonitor_CriticalTemperatureMonitor_functionInitialEquations_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  ThermostatMonitor_CriticalTemperatureMonitor_eqFunction_1(data, threadData);
  ThermostatMonitor_CriticalTemperatureMonitor_eqFunction_2(data, threadData);
  ThermostatMonitor_CriticalTemperatureMonitor_eqFunction_3(data, threadData);
  ThermostatMonitor_CriticalTemperatureMonitor_eqFunction_4(data, threadData);
  TRACE_POP
}


int ThermostatMonitor_CriticalTemperatureMonitor_functionInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  ThermostatMonitor_CriticalTemperatureMonitor_functionInitialEquations_0(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}


int ThermostatMonitor_CriticalTemperatureMonitor_functionInitialEquations_lambda0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}
int ThermostatMonitor_CriticalTemperatureMonitor_functionRemovedInitialEquations(DATA *data, threadData_t *threadData)
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

