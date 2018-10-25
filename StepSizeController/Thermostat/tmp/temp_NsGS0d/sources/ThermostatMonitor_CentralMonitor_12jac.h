/* Jacobians */
static const REAL_ATTRIBUTE dummyREAL_ATTRIBUTE = omc_dummyRealAttribute;
/* Jacobian Variables */
#if defined(__cplusplus)
extern "C" {
#endif
  #define ThermostatMonitor_CentralMonitor_INDEX_JAC_A 3
  int ThermostatMonitor_CentralMonitor_functionJacA_column(void* data, threadData_t *threadData);
  int ThermostatMonitor_CentralMonitor_initialAnalyticJacobianA(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* A */
#define $PlastHeatReplySeedA data->simulationInfo->analyticJacobians[3].seedVars[0]
#define $PlastTempReplySeedA data->simulationInfo->analyticJacobians[3].seedVars[1]
#define $PlastTermReplySeedA data->simulationInfo->analyticJacobians[3].seedVars[2]
#define $PnextHeartBeatSeedA data->simulationInfo->analyticJacobians[3].seedVars[3]
#define $PstateSeedA data->simulationInfo->analyticJacobians[3].seedVars[4]

#if defined(__cplusplus)
extern "C" {
#endif
  #define ThermostatMonitor_CentralMonitor_INDEX_JAC_B 2
  int ThermostatMonitor_CentralMonitor_functionJacB_column(void* data, threadData_t *threadData);
  int ThermostatMonitor_CentralMonitor_initialAnalyticJacobianB(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* B */
#define $PheatReplySeedB data->simulationInfo->analyticJacobians[2].seedVars[0]
#define $PtempReplySeedB data->simulationInfo->analyticJacobians[2].seedVars[1]
#define $PtermReplySeedB data->simulationInfo->analyticJacobians[2].seedVars[2]
#define $PheatOnPermissionSeedB data->simulationInfo->analyticJacobians[2].seedVars[3]

#if defined(__cplusplus)
extern "C" {
#endif
  #define ThermostatMonitor_CentralMonitor_INDEX_JAC_C 1
  int ThermostatMonitor_CentralMonitor_functionJacC_column(void* data, threadData_t *threadData);
  int ThermostatMonitor_CentralMonitor_initialAnalyticJacobianC(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* C */
#define $PlastHeatReplySeedC data->simulationInfo->analyticJacobians[1].seedVars[0]
#define $PlastTempReplySeedC data->simulationInfo->analyticJacobians[1].seedVars[1]
#define $PlastTermReplySeedC data->simulationInfo->analyticJacobians[1].seedVars[2]
#define $PnextHeartBeatSeedC data->simulationInfo->analyticJacobians[1].seedVars[3]
#define $PstateSeedC data->simulationInfo->analyticJacobians[1].seedVars[4]

#if defined(__cplusplus)
extern "C" {
#endif
  #define ThermostatMonitor_CentralMonitor_INDEX_JAC_D 0
  int ThermostatMonitor_CentralMonitor_functionJacD_column(void* data, threadData_t *threadData);
  int ThermostatMonitor_CentralMonitor_initialAnalyticJacobianD(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* D */
#define $PheatReplySeedD data->simulationInfo->analyticJacobians[0].seedVars[0]
#define $PtempReplySeedD data->simulationInfo->analyticJacobians[0].seedVars[1]
#define $PtermReplySeedD data->simulationInfo->analyticJacobians[0].seedVars[2]
#define $PheatOnPermissionSeedD data->simulationInfo->analyticJacobians[0].seedVars[3]


