/* Events: Sample, Zero Crossings, Relations, Discrete Changes */
#include "ThermostatMonitor_ThermostatOnMonitor_model.h"
#if defined(__cplusplus)
extern "C" {
#endif

/* Initializes the raw time events of the simulation using the now
   calcualted parameters. */
void ThermostatMonitor_ThermostatOnMonitor_function_initSample(DATA *data, threadData_t *threadData)
{
  long i=0;
}

const char *ThermostatMonitor_ThermostatOnMonitor_zeroCrossingDescription(int i, int **out_EquationIndexes)
{
  static const char *res[] = {"turnOn > 0 or pre(turnedon) and turnOff == 0",
  "request < 0.5"};
  static const int occurEqs0[] = {1,4};
  static const int occurEqs1[] = {1,5};
  static const int *occurEqs[] = {occurEqs0,occurEqs1};
  *out_EquationIndexes = (int*) occurEqs[i];
  return res[i];
}

/* forwarded equations */

int ThermostatMonitor_ThermostatOnMonitor_function_ZeroCrossingsEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->callStatistics.functionZeroCrossingsEquations++;

  
  TRACE_POP
  return 0;
}

int ThermostatMonitor_ThermostatOnMonitor_function_ZeroCrossings(DATA *data, threadData_t *threadData, double *gout)
{
  TRACE_PUSH
  modelica_boolean tmp0;
  modelica_boolean tmp2;
  
  data->simulationInfo->callStatistics.functionZeroCrossings++;
  
  tmp0 = Greater((modelica_integer)data->localData[0]->integerVars[1] /* turnOn variable */,((modelica_integer) 0));
  gout[0] = ((tmp0 || (data->simulationInfo->booleanVarsPre[0] /* turnedon DISCRETE */ && ((modelica_integer)data->localData[0]->integerVars[0] /* turnOff variable */ == ((modelica_integer) 0))))) ? 1 : -1;
  tmp2 = LessZC(data->localData[0]->realVars[1] /* request variable */, 0.5, data->simulationInfo->storedRelations[2]);
  gout[1] = (tmp2) ? 1 : -1;
  
  TRACE_POP
  return 0;
}

const char *ThermostatMonitor_ThermostatOnMonitor_relationDescription(int i)
{
  const char *res[] = {"turnOn > 0",
  "turnOff == 0",
  "request < 0.5"};
  return res[i];
}

int ThermostatMonitor_ThermostatOnMonitor_function_updateRelations(DATA *data, threadData_t *threadData, int evalforZeroCross)
{
  TRACE_PUSH
  modelica_boolean tmp3;
  modelica_boolean tmp5;
  
  if(evalforZeroCross) {
    tmp3 = Greater((modelica_integer)data->localData[0]->integerVars[1] /* turnOn variable */,((modelica_integer) 0));
    data->simulationInfo->relations[0] = tmp3;
    data->simulationInfo->relations[1] = ((modelica_integer)data->localData[0]->integerVars[0] /* turnOff variable */ == ((modelica_integer) 0));
    tmp5 = LessZC(data->localData[0]->realVars[1] /* request variable */, 0.5, data->simulationInfo->storedRelations[2]);
    data->simulationInfo->relations[2] = tmp5;
  } else {
    data->simulationInfo->relations[0] = ((modelica_integer)data->localData[0]->integerVars[1] /* turnOn variable */ > ((modelica_integer) 0));
    data->simulationInfo->relations[1] = ((modelica_integer)data->localData[0]->integerVars[0] /* turnOff variable */ == ((modelica_integer) 0));
    data->simulationInfo->relations[2] = (data->localData[0]->realVars[1] /* request variable */ < 0.5);
  }
  
  TRACE_POP
  return 0;
}

int ThermostatMonitor_ThermostatOnMonitor_checkForDiscreteChanges(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  int needToIterate = 0;

  infoStreamPrint(LOG_EVENTS_V, 1, "check for discrete changes at time=%.12g", data->localData[0]->timeValue);
  if(data->localData[0]->booleanVars[0] /* turnedon DISCRETE */ != data->simulationInfo->booleanVarsPre[0] /* turnedon DISCRETE */)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: %s from %d to %d", data->modelData->booleanVarsData[0].info /* turnedon */.name, data->simulationInfo->booleanVarsPre[0] /* turnedon DISCRETE */, data->localData[0]->booleanVars[0] /* turnedon DISCRETE */);
    needToIterate = 1;
  }
  if (ACTIVE_STREAM(LOG_EVENTS_V)) messageClose(LOG_EVENTS_V);
  
  TRACE_POP
  return needToIterate;
}

#if defined(__cplusplus)
}
#endif

