/* update bound parameters and variable attributes (start, nominal, min, max) */
#include "ThermostatMonitor_CriticalTemperatureMonitor_model.h"
#if defined(__cplusplus)
extern "C" {
#endif

int ThermostatMonitor_CriticalTemperatureMonitor_updateBoundVariableAttributes(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  /* min ******************************************************** */
  
  infoStreamPrint(LOG_INIT, 1, "updating min-values");
  if (ACTIVE_STREAM(LOG_INIT)) messageClose(LOG_INIT);
  
  /* max ******************************************************** */
  
  infoStreamPrint(LOG_INIT, 1, "updating max-values");
  if (ACTIVE_STREAM(LOG_INIT)) messageClose(LOG_INIT);
  
  /* nominal **************************************************** */
  
  infoStreamPrint(LOG_INIT, 1, "updating nominal-values");
  if (ACTIVE_STREAM(LOG_INIT)) messageClose(LOG_INIT);
  
  /* start ****************************************************** */
  infoStreamPrint(LOG_INIT, 1, "updating primary start-values");
  if (ACTIVE_STREAM(LOG_INIT)) messageClose(LOG_INIT);
  
  TRACE_POP
  return 0;
}


/*
 equation index: 8
 type: SIMPLE_ASSIGN
 currentBandWith = 1.0
 */
void ThermostatMonitor_CriticalTemperatureMonitor_eqFunction_8(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,8};
  data->localData[0]->realVars[0] /* currentBandWith variable */ = 1.0;
  TRACE_POP
}
int ThermostatMonitor_CriticalTemperatureMonitor_updateBoundParameters(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  ThermostatMonitor_CriticalTemperatureMonitor_eqFunction_8(data, threadData);
  
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif

