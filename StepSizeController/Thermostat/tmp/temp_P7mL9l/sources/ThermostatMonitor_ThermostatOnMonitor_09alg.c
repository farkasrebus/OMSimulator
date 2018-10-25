/* Algebraic */
#include "ThermostatMonitor_ThermostatOnMonitor_model.h"

#ifdef __cplusplus
extern "C" {
#endif


/* forwarded equations */
extern void ThermostatMonitor_ThermostatOnMonitor_eqFunction_4(DATA* data, threadData_t *threadData);
extern void ThermostatMonitor_ThermostatOnMonitor_eqFunction_5(DATA* data, threadData_t *threadData);

static void functionAlg_system0(DATA *data, threadData_t *threadData)
{
  ThermostatMonitor_ThermostatOnMonitor_eqFunction_4(data, threadData);

  ThermostatMonitor_ThermostatOnMonitor_eqFunction_5(data, threadData);
}
/* for continuous time variables */
int ThermostatMonitor_ThermostatOnMonitor_functionAlgebraics(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  
  data->simulationInfo->callStatistics.functionAlgebraics++;
  
  functionAlg_system0(data, threadData);

  ThermostatMonitor_ThermostatOnMonitor_function_savePreSynchronous(data, threadData);
  
  TRACE_POP
  return 0;
}

#ifdef __cplusplus
}
#endif
