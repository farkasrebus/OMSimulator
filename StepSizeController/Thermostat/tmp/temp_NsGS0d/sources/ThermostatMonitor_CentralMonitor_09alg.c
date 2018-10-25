/* Algebraic */
#include "ThermostatMonitor_CentralMonitor_model.h"

#ifdef __cplusplus
extern "C" {
#endif


/* forwarded equations */
extern void ThermostatMonitor_CentralMonitor_eqFunction_28(DATA* data, threadData_t *threadData);
extern void ThermostatMonitor_CentralMonitor_eqFunction_29(DATA* data, threadData_t *threadData);
extern void ThermostatMonitor_CentralMonitor_eqFunction_30(DATA* data, threadData_t *threadData);
extern void ThermostatMonitor_CentralMonitor_eqFunction_31(DATA* data, threadData_t *threadData);
extern void ThermostatMonitor_CentralMonitor_eqFunction_32(DATA* data, threadData_t *threadData);
extern void ThermostatMonitor_CentralMonitor_eqFunction_33(DATA* data, threadData_t *threadData);
extern void ThermostatMonitor_CentralMonitor_eqFunction_34(DATA* data, threadData_t *threadData);
extern void ThermostatMonitor_CentralMonitor_eqFunction_35(DATA* data, threadData_t *threadData);
extern void ThermostatMonitor_CentralMonitor_eqFunction_36(DATA* data, threadData_t *threadData);
extern void ThermostatMonitor_CentralMonitor_eqFunction_37(DATA* data, threadData_t *threadData);
extern void ThermostatMonitor_CentralMonitor_eqFunction_38(DATA* data, threadData_t *threadData);
extern void ThermostatMonitor_CentralMonitor_eqFunction_39(DATA* data, threadData_t *threadData);
extern void ThermostatMonitor_CentralMonitor_eqFunction_45(DATA* data, threadData_t *threadData);
extern void ThermostatMonitor_CentralMonitor_eqFunction_46(DATA* data, threadData_t *threadData);
extern void ThermostatMonitor_CentralMonitor_eqFunction_47(DATA* data, threadData_t *threadData);
extern void ThermostatMonitor_CentralMonitor_eqFunction_57(DATA* data, threadData_t *threadData);
extern void ThermostatMonitor_CentralMonitor_eqFunction_56(DATA* data, threadData_t *threadData);
extern void ThermostatMonitor_CentralMonitor_eqFunction_55(DATA* data, threadData_t *threadData);
extern void ThermostatMonitor_CentralMonitor_eqFunction_54(DATA* data, threadData_t *threadData);
extern void ThermostatMonitor_CentralMonitor_eqFunction_53(DATA* data, threadData_t *threadData);
extern void ThermostatMonitor_CentralMonitor_eqFunction_52(DATA* data, threadData_t *threadData);
extern void ThermostatMonitor_CentralMonitor_eqFunction_51(DATA* data, threadData_t *threadData);
extern void ThermostatMonitor_CentralMonitor_eqFunction_50(DATA* data, threadData_t *threadData);
extern void ThermostatMonitor_CentralMonitor_eqFunction_49(DATA* data, threadData_t *threadData);
extern void ThermostatMonitor_CentralMonitor_eqFunction_48(DATA* data, threadData_t *threadData);

static void functionAlg_system0(DATA *data, threadData_t *threadData)
{
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
}
/* for continuous time variables */
int ThermostatMonitor_CentralMonitor_functionAlgebraics(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  
  data->simulationInfo->callStatistics.functionAlgebraics++;
  
  functionAlg_system0(data, threadData);

  ThermostatMonitor_CentralMonitor_function_savePreSynchronous(data, threadData);
  
  TRACE_POP
  return 0;
}

#ifdef __cplusplus
}
#endif
