/* Jacobians */
static const REAL_ATTRIBUTE dummyREAL_ATTRIBUTE = omc_dummyRealAttribute;
/* Jacobian Variables */
#if defined(__cplusplus)
extern "C" {
#endif
  #define ThermostatMonitor_CriticalTemperatureMonitor_INDEX_JAC_A 3
  int ThermostatMonitor_CriticalTemperatureMonitor_functionJacA_column(void* data, threadData_t *threadData);
  int ThermostatMonitor_CriticalTemperatureMonitor_initialAnalyticJacobianA(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* A */

#if defined(__cplusplus)
extern "C" {
#endif
  #define ThermostatMonitor_CriticalTemperatureMonitor_INDEX_JAC_B 2
  int ThermostatMonitor_CriticalTemperatureMonitor_functionJacB_column(void* data, threadData_t *threadData);
  int ThermostatMonitor_CriticalTemperatureMonitor_initialAnalyticJacobianB(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* B */

#if defined(__cplusplus)
extern "C" {
#endif
  #define ThermostatMonitor_CriticalTemperatureMonitor_INDEX_JAC_C 1
  int ThermostatMonitor_CriticalTemperatureMonitor_functionJacC_column(void* data, threadData_t *threadData);
  int ThermostatMonitor_CriticalTemperatureMonitor_initialAnalyticJacobianC(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* C */

#if defined(__cplusplus)
extern "C" {
#endif
  #define ThermostatMonitor_CriticalTemperatureMonitor_INDEX_JAC_D 0
  int ThermostatMonitor_CriticalTemperatureMonitor_functionJacD_column(void* data, threadData_t *threadData);
  int ThermostatMonitor_CriticalTemperatureMonitor_initialAnalyticJacobianD(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* D */
#define $PhysteresisSeedD data->simulationInfo->analyticJacobians[0].seedVars[0]
#define $PrequestSeedD data->simulationInfo->analyticJacobians[0].seedVars[1]
#define $PtargetSeedD data->simulationInfo->analyticJacobians[0].seedVars[2]
#define $PtemperatureSeedD data->simulationInfo->analyticJacobians[0].seedVars[3]


