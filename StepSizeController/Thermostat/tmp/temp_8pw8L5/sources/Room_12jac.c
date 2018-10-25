/* Jacobians */
#include "Room_model.h"
#include "Room_12jac.h"

int Room_initialAnalyticJacobianLSJac3(void* inData, threadData_t *threadData)
{
  TRACE_PUSH
  DATA* data = ((DATA*)inData);
  int index = Room_INDEX_JAC_LSJac3;
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  int i = 0;
  
  data->simulationInfo->analyticJacobians[index].sizeCols = 1;
  data->simulationInfo->analyticJacobians[index].sizeRows = 1;
  data->simulationInfo->analyticJacobians[index].sizeTmpVars = 5;
  data->simulationInfo->analyticJacobians[index].seedVars = (modelica_real*) calloc(1,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].resultVars = (modelica_real*) calloc(1,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].tmpVars = (modelica_real*) calloc(5,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex = (unsigned int*) malloc((1+1)*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.index = (unsigned int*) malloc(1*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.numberOfNoneZeros = 1;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols = (unsigned int*) malloc(1*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.maxColors = 1;
  data->simulationInfo->analyticJacobians[index].jacobian = NULL;
  
  /* write lead index of compressed sparse column */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex, colPtrIndex, (1+1)*sizeof(int));
  
  for(i=2;i<1+1;++i)
    data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i] += data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i-1];
  
  /* call sparse index */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.index, rowIndex, 1*sizeof(int));
  
  /* write color array */
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[0] = 1;
  TRACE_POP
  return 0;
}

int Room_initialAnalyticJacobianLSJac2(void* inData, threadData_t *threadData)
{
  TRACE_PUSH
  DATA* data = ((DATA*)inData);
  int index = Room_INDEX_JAC_LSJac2;
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  int i = 0;
  
  data->simulationInfo->analyticJacobians[index].sizeCols = 1;
  data->simulationInfo->analyticJacobians[index].sizeRows = 1;
  data->simulationInfo->analyticJacobians[index].sizeTmpVars = 6;
  data->simulationInfo->analyticJacobians[index].seedVars = (modelica_real*) calloc(1,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].resultVars = (modelica_real*) calloc(1,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].tmpVars = (modelica_real*) calloc(6,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex = (unsigned int*) malloc((1+1)*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.index = (unsigned int*) malloc(1*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.numberOfNoneZeros = 1;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols = (unsigned int*) malloc(1*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.maxColors = 1;
  data->simulationInfo->analyticJacobians[index].jacobian = NULL;
  
  /* write lead index of compressed sparse column */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex, colPtrIndex, (1+1)*sizeof(int));
  
  for(i=2;i<1+1;++i)
    data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i] += data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i-1];
  
  /* call sparse index */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.index, rowIndex, 1*sizeof(int));
  
  /* write color array */
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[0] = 1;
  TRACE_POP
  return 0;
}

int Room_initialAnalyticJacobianA(void* inData, threadData_t *threadData)
{
  TRACE_PUSH
  DATA* data = ((DATA*)inData);
  int index = Room_INDEX_JAC_A;
  const int colPtrIndex[1+3] = {0,2,2,1};
  const int rowIndex[5] = {1,2,1,2,2};
  int i = 0;
  
  data->simulationInfo->analyticJacobians[index].sizeCols = 3;
  data->simulationInfo->analyticJacobians[index].sizeRows = 3;
  data->simulationInfo->analyticJacobians[index].sizeTmpVars = 0;
  data->simulationInfo->analyticJacobians[index].seedVars = (modelica_real*) calloc(3,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].resultVars = (modelica_real*) calloc(3,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].tmpVars = (modelica_real*) calloc(0,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex = (unsigned int*) malloc((3+1)*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.index = (unsigned int*) malloc(5*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.numberOfNoneZeros = 5;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols = (unsigned int*) malloc(3*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.maxColors = 3;
  data->simulationInfo->analyticJacobians[index].jacobian = NULL;
  
  /* write lead index of compressed sparse column */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex, colPtrIndex, (3+1)*sizeof(int));
  
  for(i=2;i<3+1;++i)
    data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i] += data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i-1];
  
  /* call sparse index */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.index, rowIndex, 5*sizeof(int));
  
  /* write color array */
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[0] = 1;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[1] = 2;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[2] = 3;
  TRACE_POP
  return 0;
}

int Room_initialAnalyticJacobianB(void* inData, threadData_t *threadData)
{
  TRACE_PUSH
  DATA* data = ((DATA*)inData);
  int index = Room_INDEX_JAC_B;
  const int colPtrIndex[1+2] = {0,1,0};
  const int rowIndex[1] = {2};
  int i = 0;
  
  data->simulationInfo->analyticJacobians[index].sizeCols = 2;
  data->simulationInfo->analyticJacobians[index].sizeRows = 3;
  data->simulationInfo->analyticJacobians[index].sizeTmpVars = 0;
  data->simulationInfo->analyticJacobians[index].seedVars = (modelica_real*) calloc(2,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].resultVars = (modelica_real*) calloc(3,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].tmpVars = (modelica_real*) calloc(0,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex = (unsigned int*) malloc((2+1)*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.index = (unsigned int*) malloc(1*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.numberOfNoneZeros = 1;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols = (unsigned int*) malloc(2*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.maxColors = 1;
  data->simulationInfo->analyticJacobians[index].jacobian = NULL;
  
  /* write lead index of compressed sparse column */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex, colPtrIndex, (2+1)*sizeof(int));
  
  for(i=2;i<2+1;++i)
    data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i] += data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i-1];
  
  /* call sparse index */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.index, rowIndex, 1*sizeof(int));
  
  /* write color array */
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[0] = 1;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[1] = 1;
  TRACE_POP
  return 0;
}

int Room_initialAnalyticJacobianC(void* inData, threadData_t *threadData)
{
  TRACE_PUSH
  DATA* data = ((DATA*)inData);
  int index = Room_INDEX_JAC_C;
  const int colPtrIndex[1+3] = {0,0,1,1};
  const int rowIndex[2] = {3,3};
  int i = 0;
  
  data->simulationInfo->analyticJacobians[index].sizeCols = 3;
  data->simulationInfo->analyticJacobians[index].sizeRows = 14;
  data->simulationInfo->analyticJacobians[index].sizeTmpVars = 0;
  data->simulationInfo->analyticJacobians[index].seedVars = (modelica_real*) calloc(3,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].resultVars = (modelica_real*) calloc(14,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].tmpVars = (modelica_real*) calloc(0,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex = (unsigned int*) malloc((3+1)*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.index = (unsigned int*) malloc(2*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.numberOfNoneZeros = 2;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols = (unsigned int*) malloc(3*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.maxColors = 2;
  data->simulationInfo->analyticJacobians[index].jacobian = NULL;
  
  /* write lead index of compressed sparse column */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex, colPtrIndex, (3+1)*sizeof(int));
  
  for(i=2;i<3+1;++i)
    data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i] += data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i-1];
  
  /* call sparse index */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.index, rowIndex, 2*sizeof(int));
  
  /* write color array */
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[1] = 1;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[2] = 2;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[0] = 2;
  TRACE_POP
  return 0;
}

int Room_initialAnalyticJacobianD(void* inData, threadData_t *threadData)
{
  TRACE_PUSH
  DATA* data = ((DATA*)inData);
  int index = Room_INDEX_JAC_D;
  const int colPtrIndex[1+2] = {0,0,0};
  const int rowIndex[0] = {};
  int i = 0;
  
  data->simulationInfo->analyticJacobians[index].sizeCols = 2;
  data->simulationInfo->analyticJacobians[index].sizeRows = 14;
  data->simulationInfo->analyticJacobians[index].sizeTmpVars = 0;
  data->simulationInfo->analyticJacobians[index].seedVars = (modelica_real*) calloc(2,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].resultVars = (modelica_real*) calloc(14,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].tmpVars = (modelica_real*) calloc(0,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex = (unsigned int*) malloc((2+1)*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.index = (unsigned int*) malloc(0*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.numberOfNoneZeros = 0;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols = (unsigned int*) malloc(2*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.maxColors = 1;
  data->simulationInfo->analyticJacobians[index].jacobian = NULL;
  
  /* write lead index of compressed sparse column */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex, colPtrIndex, (2+1)*sizeof(int));
  
  for(i=2;i<2+1;++i)
    data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i] += data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i-1];
  
  /* call sparse index */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.index, rowIndex, 0*sizeof(int));
  
  /* write color array */
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[0] = 1;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[1] = 1;
  TRACE_POP
  return 0;
}


/*
 equation index: 176
 type: SIMPLE_ASSIGN
 heaCap._port._Q_flow._$pDERLSJac3._dummyVarLSJac3 = (-vol.dynBal.m) * $DER_vol_dynBal_medium_uSeedLSJac3
 */
void Room_eqFunction_176(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,176};
  $PheaCap$Pport$PQ_flow$P$pDERLSJac3$PdummyVarLSJac3 = ((-data->localData[0]->realVars[0] /* vol._dynBal._m STATE(1) */)) * ($P$DER_vol_dynBal_medium_uSeedLSJac3);
  TRACE_POP
}

/*
 equation index: 177
 type: SIMPLE_ASSIGN
 heaCap._der_T._$pDERLSJac3._dummyVarLSJac3 = heaCap.port.Q_flow.$pDERLSJac3.dummyVarLSJac3 / 434592.0
 */
void Room_eqFunction_177(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,177};
  modelica_real tmp245;
  tmp245 = 434592.0;
  if (tmp245 == 0) {throwStreamPrint(threadData, "Division by zero %s", "heaCap.port.Q_flow.$pDERLSJac3.dummyVarLSJac3 / 434592.0");}
  $PheaCap$Pder_T$P$pDERLSJac3$PdummyVarLSJac3 = ($PheaCap$Pport$PQ_flow$P$pDERLSJac3$PdummyVarLSJac3) / tmp245;
  TRACE_POP
}

/*
 equation index: 178
 type: SIMPLE_ASSIGN
 $res._1._$pDERLSJac3._dummyVarLSJac3 = $DER_vol_dynBal_medium_uSeedLSJac3 * (1006.0 * (1.0 - vol.dynBal.medium.Xi[1]) + 1860.0 * vol.dynBal.medium.Xi[1]) - heaCap.der_T.$pDERLSJac3.dummyVarLSJac3 * (1006.0 * (1.0 - vol.dynBal.medium.Xi[1]) + 1860.0 * vol.dynBal.medium.Xi[1]) ^ 2.0
 */
void Room_eqFunction_178(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,178};
  modelica_real tmp246;
  tmp246 = (1006.0) * (1.0 - data->localData[0]->realVars[1] /* vol._dynBal._medium._Xi[1] STATE(1) */) + (1860.0) * (data->localData[0]->realVars[1] /* vol._dynBal._medium._Xi[1] STATE(1) */);
  $P$res$P1$P$pDERLSJac3$PdummyVarLSJac3 = ($P$DER_vol_dynBal_medium_uSeedLSJac3) * ((1006.0) * (1.0 - data->localData[0]->realVars[1] /* vol._dynBal._medium._Xi[1] STATE(1) */) + (1860.0) * (data->localData[0]->realVars[1] /* vol._dynBal._medium._Xi[1] STATE(1) */)) - (($PheaCap$Pder_T$P$pDERLSJac3$PdummyVarLSJac3) * ((tmp246 * tmp246)));
  TRACE_POP
}
int Room_functionJacLSJac3_column(void* inData, threadData_t *threadData)
{
  TRACE_PUSH

  DATA* data = ((DATA*)inData);
  int index = Room_INDEX_JAC_LSJac3;
  Room_eqFunction_176(data, threadData);

  Room_eqFunction_177(data, threadData);

  Room_eqFunction_178(data, threadData);
  
  TRACE_POP
  return 0;
}

/*
 equation index: 53
 type: SIMPLE_ASSIGN
 der(vol._dynBal._U._$pDERLSJac2._dummyVarLSJac2) = vol.dynBal.m * $DER_vol_hOut_internalSeedLSJac2
 */
void Room_eqFunction_53(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,53};
  $P$DER$Pvol$PdynBal$PU$P$pDERLSJac2$PdummyVarLSJac2 = (data->localData[0]->realVars[0] /* vol._dynBal._m STATE(1) */) * ($P$DER_vol_hOut_internalSeedLSJac2);
  TRACE_POP
}

/*
 equation index: 54
 type: SIMPLE_ASSIGN
 heaCap._der_T._$pDERLSJac2._dummyVarLSJac2 = DIVISION($DER_vol_hOut_internalSeedLSJac2, 1006.0 * (1.0 - vol.dynBal.medium.Xi[1]) + 1860.0 * vol.dynBal.medium.Xi[1])
 */
void Room_eqFunction_54(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,54};
  $PheaCap$Pder_T$P$pDERLSJac2$PdummyVarLSJac2 = DIVISION_SIM($P$DER_vol_hOut_internalSeedLSJac2,(1006.0) * (1.0 - data->localData[0]->realVars[1] /* vol._dynBal._medium._Xi[1] STATE(1) */) + (1860.0) * (data->localData[0]->realVars[1] /* vol._dynBal._medium._Xi[1] STATE(1) */),"1006.0 * (1.0 - vol.dynBal.medium.Xi[1]) + 1860.0 * vol.dynBal.medium.Xi[1]",equationIndexes);
  TRACE_POP
}

/*
 equation index: 55
 type: SIMPLE_ASSIGN
 heaCap._port._Q_flow._$pDERLSJac2._dummyVarLSJac2 = 434592.0 * heaCap.der_T.$pDERLSJac2.dummyVarLSJac2
 */
void Room_eqFunction_55(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,55};
  $PheaCap$Pport$PQ_flow$P$pDERLSJac2$PdummyVarLSJac2 = (434592.0) * ($PheaCap$Pder_T$P$pDERLSJac2$PdummyVarLSJac2);
  TRACE_POP
}

/*
 equation index: 56
 type: SIMPLE_ASSIGN
 $res._1._$pDERLSJac2._dummyVarLSJac2 = (-heaCap.port.Q_flow.$pDERLSJac2.dummyVarLSJac2) - $DER.vol.dynBal.U.$pDERLSJac2.dummyVarLSJac2
 */
void Room_eqFunction_56(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,56};
  $P$res$P1$P$pDERLSJac2$PdummyVarLSJac2 = (-$PheaCap$Pport$PQ_flow$P$pDERLSJac2$PdummyVarLSJac2) - $P$DER$Pvol$PdynBal$PU$P$pDERLSJac2$PdummyVarLSJac2;
  TRACE_POP
}
int Room_functionJacLSJac2_column(void* inData, threadData_t *threadData)
{
  TRACE_PUSH

  DATA* data = ((DATA*)inData);
  int index = Room_INDEX_JAC_LSJac2;
  Room_eqFunction_53(data, threadData);

  Room_eqFunction_54(data, threadData);

  Room_eqFunction_55(data, threadData);

  Room_eqFunction_56(data, threadData);
  
  TRACE_POP
  return 0;
}
int Room_functionJacA_column(void* inData, threadData_t *threadData)
{
  TRACE_PUSH

  DATA* data = ((DATA*)inData);
  int index = Room_INDEX_JAC_A;
  
  TRACE_POP
  return 0;
}
int Room_functionJacB_column(void* inData, threadData_t *threadData)
{
  TRACE_PUSH

  DATA* data = ((DATA*)inData);
  int index = Room_INDEX_JAC_B;
  
  TRACE_POP
  return 0;
}
int Room_functionJacC_column(void* inData, threadData_t *threadData)
{
  TRACE_PUSH

  DATA* data = ((DATA*)inData);
  int index = Room_INDEX_JAC_C;
  
  TRACE_POP
  return 0;
}
int Room_functionJacD_column(void* inData, threadData_t *threadData)
{
  TRACE_PUSH

  DATA* data = ((DATA*)inData);
  int index = Room_INDEX_JAC_D;
  
  TRACE_POP
  return 0;
}


