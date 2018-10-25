/* Jacobians */
static const REAL_ATTRIBUTE dummyREAL_ATTRIBUTE = omc_dummyRealAttribute;
/* Jacobian Variables */
#if defined(__cplusplus)
extern "C" {
#endif
  #define ThermostatMonitor_HeatingOnMonitor_INDEX_JAC_A 3
  int ThermostatMonitor_HeatingOnMonitor_functionJacA_column(void* data, threadData_t *threadData);
  int ThermostatMonitor_HeatingOnMonitor_initialAnalyticJacobianA(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* A */

#if defined(__cplusplus)
extern "C" {
#endif
  #define ThermostatMonitor_HeatingOnMonitor_INDEX_JAC_B 2
  int ThermostatMonitor_HeatingOnMonitor_functionJacB_column(void* data, threadData_t *threadData);
  int ThermostatMonitor_HeatingOnMonitor_initialAnalyticJacobianB(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* B */

#if defined(__cplusplus)
extern "C" {
#endif
  #define ThermostatMonitor_HeatingOnMonitor_INDEX_JAC_C 1
  int ThermostatMonitor_HeatingOnMonitor_functionJacC_column(void* data, threadData_t *threadData);
  int ThermostatMonitor_HeatingOnMonitor_initialAnalyticJacobianC(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* C */

#if defined(__cplusplus)
extern "C" {
#endif
  #define ThermostatMonitor_HeatingOnMonitor_INDEX_JAC_D 0
  int ThermostatMonitor_HeatingOnMonitor_functionJacD_column(void* data, threadData_t *threadData);
  int ThermostatMonitor_HeatingOnMonitor_initialAnalyticJacobianD(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* D */
#define $PrequestSeedD data->simulationInfo->analyticJacobians[0].seedVars[0]
#define $PturnOffSeedD data->simulationInfo->analyticJacobians[0].seedVars[1]
#define $PturnOnSeedD data->simulationInfo->analyticJacobians[0].seedVars[2]


