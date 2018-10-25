/* Events: Sample, Zero Crossings, Relations, Discrete Changes */
#include "ThermostatMonitor_CriticalTemperatureMonitor_model.h"
#if defined(__cplusplus)
extern "C" {
#endif

/* Initializes the raw time events of the simulation using the now
   calcualted parameters. */
void ThermostatMonitor_CriticalTemperatureMonitor_function_initSample(DATA *data, threadData_t *threadData)
{
  long i=0;
}

const char *ThermostatMonitor_CriticalTemperatureMonitor_zeroCrossingDescription(int i, int **out_EquationIndexes)
{
  static const char *res[] = {"target < temperature",
  "temperature < target - hysteresis",
  "request < 0.5"};
  static const int occurEqs0[] = {1,5};
  static const int occurEqs1[] = {1,5};
  static const int occurEqs2[] = {1,7};
  static const int *occurEqs[] = {occurEqs0,occurEqs1,occurEqs2};
  *out_EquationIndexes = (int*) occurEqs[i];
  return res[i];
}

/* forwarded equations */

int ThermostatMonitor_CriticalTemperatureMonitor_function_ZeroCrossingsEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->callStatistics.functionZeroCrossingsEquations++;

  
  TRACE_POP
  return 0;
}

int ThermostatMonitor_CriticalTemperatureMonitor_function_ZeroCrossings(DATA *data, threadData_t *threadData, double *gout)
{
  TRACE_PUSH
  modelica_boolean tmp0;
  modelica_boolean tmp1;
  modelica_boolean tmp2;
  
  data->simulationInfo->callStatistics.functionZeroCrossings++;
  
  tmp0 = LessZC(data->localData[0]->realVars[5] /* target variable */, data->localData[0]->realVars[6] /* temperature variable */, data->simulationInfo->storedRelations[0]);
  gout[0] = (tmp0) ? 1 : -1;
  tmp1 = LessZC(data->localData[0]->realVars[6] /* temperature variable */, data->localData[0]->realVars[5] /* target variable */ - data->localData[0]->realVars[2] /* hysteresis variable */, data->simulationInfo->storedRelations[1]);
  gout[1] = (tmp1) ? 1 : -1;
  tmp2 = LessZC(data->localData[0]->realVars[4] /* request variable */, 0.5, data->simulationInfo->storedRelations[2]);
  gout[2] = (tmp2) ? 1 : -1;
  
  TRACE_POP
  return 0;
}

const char *ThermostatMonitor_CriticalTemperatureMonitor_relationDescription(int i)
{
  const char *res[] = {"target < temperature",
  "temperature < target - hysteresis",
  "request < 0.5"};
  return res[i];
}

int ThermostatMonitor_CriticalTemperatureMonitor_function_updateRelations(DATA *data, threadData_t *threadData, int evalforZeroCross)
{
  TRACE_PUSH
  modelica_boolean tmp3;
  modelica_boolean tmp4;
  modelica_boolean tmp5;
  
  if(evalforZeroCross) {
    tmp3 = LessZC(data->localData[0]->realVars[5] /* target variable */, data->localData[0]->realVars[6] /* temperature variable */, data->simulationInfo->storedRelations[0]);
    data->simulationInfo->relations[0] = tmp3;
    tmp4 = LessZC(data->localData[0]->realVars[6] /* temperature variable */, data->localData[0]->realVars[5] /* target variable */ - data->localData[0]->realVars[2] /* hysteresis variable */, data->simulationInfo->storedRelations[1]);
    data->simulationInfo->relations[1] = tmp4;
    tmp5 = LessZC(data->localData[0]->realVars[4] /* request variable */, 0.5, data->simulationInfo->storedRelations[2]);
    data->simulationInfo->relations[2] = tmp5;
  } else {
    data->simulationInfo->relations[0] = (data->localData[0]->realVars[5] /* target variable */ < data->localData[0]->realVars[6] /* temperature variable */);
    data->simulationInfo->relations[1] = (data->localData[0]->realVars[6] /* temperature variable */ < data->localData[0]->realVars[5] /* target variable */ - data->localData[0]->realVars[2] /* hysteresis variable */);
    data->simulationInfo->relations[2] = (data->localData[0]->realVars[4] /* request variable */ < 0.5);
  }
  
  TRACE_POP
  return 0;
}

int ThermostatMonitor_CriticalTemperatureMonitor_checkForDiscreteChanges(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  int needToIterate = 0;

  infoStreamPrint(LOG_EVENTS_V, 1, "check for discrete changes at time=%.12g", data->localData[0]->timeValue);
  if(data->localData[0]->booleanVars[0] /* critical DISCRETE */ != data->simulationInfo->booleanVarsPre[0] /* critical DISCRETE */)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: %s from %d to %d", data->modelData->booleanVarsData[0].info /* critical */.name, data->simulationInfo->booleanVarsPre[0] /* critical DISCRETE */, data->localData[0]->booleanVars[0] /* critical DISCRETE */);
    needToIterate = 1;
  }
  if (ACTIVE_STREAM(LOG_EVENTS_V)) messageClose(LOG_EVENTS_V);
  
  TRACE_POP
  return needToIterate;
}

#if defined(__cplusplus)
}
#endif

