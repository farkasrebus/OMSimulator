/* update bound parameters and variable attributes (start, nominal, min, max) */
#include "ThermostatMonitor_HeatingOnMonitor_model.h"
#if defined(__cplusplus)
extern "C" {
#endif

int ThermostatMonitor_HeatingOnMonitor_updateBoundVariableAttributes(DATA *data, threadData_t *threadData)
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

int ThermostatMonitor_HeatingOnMonitor_updateBoundParameters(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif

