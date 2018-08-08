/* Jacobians */
static const REAL_ATTRIBUTE dummyREAL_ATTRIBUTE = omc_dummyRealAttribute;
/* Jacobian Variables */
#if defined(__cplusplus)
extern "C" {
#endif
  #define Room_INDEX_JAC_LSJac3 1
  int Room_functionJacLSJac3_column(void* data, threadData_t *threadData);
  int Room_initialAnalyticJacobianLSJac3(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* LSJac3 */
#define $P$DER_vol_dynBal_medium_uSeedLSJac3 data->simulationInfo->analyticJacobians[1].seedVars[0]
#define _$P$DER$Pvol$PhOut_internal$P$pDERLSJac3$PdummyVarLSJac3(i) data->simulationInfo->analyticJacobians[1].tmpVars[0]
#define $P$DER$Pvol$PhOut_internal$P$pDERLSJac3$PdummyVarLSJac3 _$P$DER$Pvol$PhOut_internal$P$pDERLSJac3$PdummyVarLSJac3(0)

#define _$PheaCap$Pder_T$P$pDERLSJac3$PdummyVarLSJac3(i) data->simulationInfo->analyticJacobians[1].tmpVars[1]
#define $PheaCap$Pder_T$P$pDERLSJac3$PdummyVarLSJac3 _$PheaCap$Pder_T$P$pDERLSJac3$PdummyVarLSJac3(0)

#define _$PheaCap$Pport$PQ_flow$P$pDERLSJac3$PdummyVarLSJac3(i) data->simulationInfo->analyticJacobians[1].tmpVars[2]
#define $PheaCap$Pport$PQ_flow$P$pDERLSJac3$PdummyVarLSJac3 _$PheaCap$Pport$PQ_flow$P$pDERLSJac3$PdummyVarLSJac3(0)

#define _$Pvol$PheatPort$PQ_flow$P$pDERLSJac3$PdummyVarLSJac3(i) data->simulationInfo->analyticJacobians[1].tmpVars[3]
#define $Pvol$PheatPort$PQ_flow$P$pDERLSJac3$PdummyVarLSJac3 _$Pvol$PheatPort$PQ_flow$P$pDERLSJac3$PdummyVarLSJac3(0)

#define _$P$res$P1$P$pDERLSJac3$PdummyVarLSJac3(i) data->simulationInfo->analyticJacobians[1].resultVars[0]
#define $P$res$P1$P$pDERLSJac3$PdummyVarLSJac3 _$P$res$P1$P$pDERLSJac3$PdummyVarLSJac3(0)

#if defined(__cplusplus)
extern "C" {
#endif
  #define Room_INDEX_JAC_LSJac2 0
  int Room_functionJacLSJac2_column(void* data, threadData_t *threadData);
  int Room_initialAnalyticJacobianLSJac2(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* LSJac2 */
#define $P$DER_vol_hOut_internalSeedLSJac2 data->simulationInfo->analyticJacobians[0].seedVars[0]
#define _$P$DER$Pvol$PdynBal$PU$P$pDERLSJac2$PdummyVarLSJac2(i) data->simulationInfo->analyticJacobians[0].tmpVars[0]
#define $P$DER$Pvol$PdynBal$PU$P$pDERLSJac2$PdummyVarLSJac2 _$P$DER$Pvol$PdynBal$PU$P$pDERLSJac2$PdummyVarLSJac2(0)

#define _$P$DER$Pvol$PdynBal$Pmedium$Pu$P$pDERLSJac2$PdummyVarLSJac2(i) data->simulationInfo->analyticJacobians[0].tmpVars[1]
#define $P$DER$Pvol$PdynBal$Pmedium$Pu$P$pDERLSJac2$PdummyVarLSJac2 _$P$DER$Pvol$PdynBal$Pmedium$Pu$P$pDERLSJac2$PdummyVarLSJac2(0)

#define _$Pvol$PheatPort$PQ_flow$P$pDERLSJac2$PdummyVarLSJac2(i) data->simulationInfo->analyticJacobians[0].tmpVars[2]
#define $Pvol$PheatPort$PQ_flow$P$pDERLSJac2$PdummyVarLSJac2 _$Pvol$PheatPort$PQ_flow$P$pDERLSJac2$PdummyVarLSJac2(0)

#define _$PheaCap$Pport$PQ_flow$P$pDERLSJac2$PdummyVarLSJac2(i) data->simulationInfo->analyticJacobians[0].tmpVars[3]
#define $PheaCap$Pport$PQ_flow$P$pDERLSJac2$PdummyVarLSJac2 _$PheaCap$Pport$PQ_flow$P$pDERLSJac2$PdummyVarLSJac2(0)

#define _$PheaCap$Pder_T$P$pDERLSJac2$PdummyVarLSJac2(i) data->simulationInfo->analyticJacobians[0].tmpVars[4]
#define $PheaCap$Pder_T$P$pDERLSJac2$PdummyVarLSJac2 _$PheaCap$Pder_T$P$pDERLSJac2$PdummyVarLSJac2(0)

#define _$P$res$P1$P$pDERLSJac2$PdummyVarLSJac2(i) data->simulationInfo->analyticJacobians[0].resultVars[0]
#define $P$res$P1$P$pDERLSJac2$PdummyVarLSJac2 _$P$res$P1$P$pDERLSJac2$PdummyVarLSJac2(0)

#if defined(__cplusplus)
extern "C" {
#endif
  #define Room_INDEX_JAC_A 5
  int Room_functionJacA_column(void* data, threadData_t *threadData);
  int Room_initialAnalyticJacobianA(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* A */
#define $Pvol_dynBal_mSeedA data->simulationInfo->analyticJacobians[5].seedVars[0]
#define $Pvol_dynBal_medium_Xi_1SeedA data->simulationInfo->analyticJacobians[5].seedVars[1]
#define $Pvol_hOut_internalSeedA data->simulationInfo->analyticJacobians[5].seedVars[2]

#if defined(__cplusplus)
extern "C" {
#endif
  #define Room_INDEX_JAC_B 4
  int Room_functionJacB_column(void* data, threadData_t *threadData);
  int Room_initialAnalyticJacobianB(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* B */
#define $PheatingControlPort1_turn_heating_off1_counterSeedB data->simulationInfo->analyticJacobians[4].seedVars[0]
#define $PheatingControlPort1_turn_heating_on1_counterSeedB data->simulationInfo->analyticJacobians[4].seedVars[1]

#if defined(__cplusplus)
extern "C" {
#endif
  #define Room_INDEX_JAC_C 3
  int Room_functionJacC_column(void* data, threadData_t *threadData);
  int Room_initialAnalyticJacobianC(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* C */
#define $Pvol_dynBal_mSeedC data->simulationInfo->analyticJacobians[3].seedVars[0]
#define $Pvol_dynBal_medium_Xi_1SeedC data->simulationInfo->analyticJacobians[3].seedVars[1]
#define $Pvol_hOut_internalSeedC data->simulationInfo->analyticJacobians[3].seedVars[2]

#if defined(__cplusplus)
extern "C" {
#endif
  #define Room_INDEX_JAC_D 2
  int Room_functionJacD_column(void* data, threadData_t *threadData);
  int Room_initialAnalyticJacobianD(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* D */
#define $PheatingControlPort1_turn_heating_off1_counterSeedD data->simulationInfo->analyticJacobians[2].seedVars[0]
#define $PheatingControlPort1_turn_heating_on1_counterSeedD data->simulationInfo->analyticJacobians[2].seedVars[1]


