/* Algebraic */
#include "ThermostatMonitor_CriticalTemperatureMonitor_model.h"

#ifdef __cplusplus
extern "C" {
#endif


/* forwarded equations */
extern void ThermostatMonitor_CriticalTemperatureMonitor_eqFunction_6(DATA* data, threadData_t *threadData);
extern void ThermostatMonitor_CriticalTemperatureMonitor_eqFunction_7(DATA* data, threadData_t *threadData);
extern void ThermostatMonitor_CriticalTemperatureMonitor_eqFunction_5(DATA* data, threadData_t *threadData);

static void functionAlg_system0(DATA *data, threadData_t *threadData)
{
  ThermostatMonitor_CriticalTemperatureMonitor_eqFunction_6(data, threadData);

  ThermostatMonitor_CriticalTemperatureMonitor_eqFunction_7(data, threadData);

  ThermostatMonitor_CriticalTemperatureMonitor_eqFunction_5(data, threadData);
}
/* for continuous time variables */
int ThermostatMonitor_CriticalTemperatureMonitor_functionAlgebraics(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  
  data->simulationInfo->callStatistics.functionAlgebraics++;
  
  functionAlg_system0(data, threadData);

  ThermostatMonitor_CriticalTemperatureMonitor_function_savePreSynchronous(data, threadData);
  
  TRACE_POP
  return 0;
}

#ifdef __cplusplus
}
#endif
