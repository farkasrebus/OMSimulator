/* Jacobians */
#include "ThermostatMonitor_CentralMonitor_model.h"
#include "ThermostatMonitor_CentralMonitor_12jac.h"

int ThermostatMonitor_CentralMonitor_initialAnalyticJacobianA(void* inData, threadData_t *threadData)
{
  TRACE_PUSH
  DATA* data = ((DATA*)inData);
  int index = ThermostatMonitor_CentralMonitor_INDEX_JAC_A;
  const int colPtrIndex[1+5] = {0,0,0,0,0,0};
  const int rowIndex[0] = {};
  int i = 0;
  
  data->simulationInfo->analyticJacobians[index].sizeCols = 5;
  data->simulationInfo->analyticJacobians[index].sizeRows = 5;
  data->simulationInfo->analyticJacobians[index].sizeTmpVars = 0;
  data->simulationInfo->analyticJacobians[index].seedVars = (modelica_real*) calloc(5,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].resultVars = (modelica_real*) calloc(5,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].tmpVars = (modelica_real*) calloc(0,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex = (unsigned int*) malloc((5+1)*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.index = (unsigned int*) malloc(0*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.numberOfNoneZeros = 0;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols = (unsigned int*) malloc(5*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.maxColors = 1;
  data->simulationInfo->analyticJacobians[index].jacobian = NULL;
  
  /* write lead index of compressed sparse column */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex, colPtrIndex, (5+1)*sizeof(int));
  
  for(i=2;i<5+1;++i)
    data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i] += data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i-1];
  
  /* call sparse index */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.index, rowIndex, 0*sizeof(int));
  
  /* write color array */
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[4] = 1;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[3] = 1;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[2] = 1;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[0] = 1;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[1] = 1;
  TRACE_POP
  return 0;
}

int ThermostatMonitor_CentralMonitor_initialAnalyticJacobianB(void* inData, threadData_t *threadData)
{
  TRACE_PUSH
  DATA* data = ((DATA*)inData);
  int index = ThermostatMonitor_CentralMonitor_INDEX_JAC_B;
  const int colPtrIndex[1+4] = {0,0,0,0,0};
  const int rowIndex[0] = {};
  int i = 0;
  
  data->simulationInfo->analyticJacobians[index].sizeCols = 4;
  data->simulationInfo->analyticJacobians[index].sizeRows = 5;
  data->simulationInfo->analyticJacobians[index].sizeTmpVars = 0;
  data->simulationInfo->analyticJacobians[index].seedVars = (modelica_real*) calloc(4,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].resultVars = (modelica_real*) calloc(5,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].tmpVars = (modelica_real*) calloc(0,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex = (unsigned int*) malloc((4+1)*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.index = (unsigned int*) malloc(0*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.numberOfNoneZeros = 0;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols = (unsigned int*) malloc(4*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.maxColors = 1;
  data->simulationInfo->analyticJacobians[index].jacobian = NULL;
  
  /* write lead index of compressed sparse column */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex, colPtrIndex, (4+1)*sizeof(int));
  
  for(i=2;i<4+1;++i)
    data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i] += data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i-1];
  
  /* call sparse index */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.index, rowIndex, 0*sizeof(int));
  
  /* write color array */
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[1] = 1;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[0] = 1;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[2] = 1;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[3] = 1;
  TRACE_POP
  return 0;
}

int ThermostatMonitor_CentralMonitor_initialAnalyticJacobianC(void* inData, threadData_t *threadData)
{
  TRACE_PUSH
  DATA* data = ((DATA*)inData);
  int index = ThermostatMonitor_CentralMonitor_INDEX_JAC_C;
  const int colPtrIndex[1+5] = {0,1,1,1,4,0};
  const int rowIndex[7] = {7,7,7,4,5,6,7};
  int i = 0;
  
  data->simulationInfo->analyticJacobians[index].sizeCols = 5;
  data->simulationInfo->analyticJacobians[index].sizeRows = 8;
  data->simulationInfo->analyticJacobians[index].sizeTmpVars = 0;
  data->simulationInfo->analyticJacobians[index].seedVars = (modelica_real*) calloc(5,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].resultVars = (modelica_real*) calloc(8,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].tmpVars = (modelica_real*) calloc(0,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex = (unsigned int*) malloc((5+1)*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.index = (unsigned int*) malloc(7*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.numberOfNoneZeros = 7;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols = (unsigned int*) malloc(5*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.maxColors = 4;
  data->simulationInfo->analyticJacobians[index].jacobian = NULL;
  
  /* write lead index of compressed sparse column */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex, colPtrIndex, (5+1)*sizeof(int));
  
  for(i=2;i<5+1;++i)
    data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i] += data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i-1];
  
  /* call sparse index */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.index, rowIndex, 7*sizeof(int));
  
  /* write color array */
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[1] = 1;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[0] = 2;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[2] = 3;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[4] = 4;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[3] = 4;
  TRACE_POP
  return 0;
}

int ThermostatMonitor_CentralMonitor_initialAnalyticJacobianD(void* inData, threadData_t *threadData)
{
  TRACE_PUSH
  DATA* data = ((DATA*)inData);
  int index = ThermostatMonitor_CentralMonitor_INDEX_JAC_D;
  const int colPtrIndex[1+4] = {0,0,0,0,0};
  const int rowIndex[0] = {};
  int i = 0;
  
  data->simulationInfo->analyticJacobians[index].sizeCols = 4;
  data->simulationInfo->analyticJacobians[index].sizeRows = 8;
  data->simulationInfo->analyticJacobians[index].sizeTmpVars = 0;
  data->simulationInfo->analyticJacobians[index].seedVars = (modelica_real*) calloc(4,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].resultVars = (modelica_real*) calloc(8,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].tmpVars = (modelica_real*) calloc(0,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex = (unsigned int*) malloc((4+1)*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.index = (unsigned int*) malloc(0*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.numberOfNoneZeros = 0;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols = (unsigned int*) malloc(4*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.maxColors = 1;
  data->simulationInfo->analyticJacobians[index].jacobian = NULL;
  
  /* write lead index of compressed sparse column */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex, colPtrIndex, (4+1)*sizeof(int));
  
  for(i=2;i<4+1;++i)
    data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i] += data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i-1];
  
  /* call sparse index */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.index, rowIndex, 0*sizeof(int));
  
  /* write color array */
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[1] = 1;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[0] = 1;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[2] = 1;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[3] = 1;
  TRACE_POP
  return 0;
}

int ThermostatMonitor_CentralMonitor_functionJacA_column(void* inData, threadData_t *threadData)
{
  TRACE_PUSH

  DATA* data = ((DATA*)inData);
  int index = ThermostatMonitor_CentralMonitor_INDEX_JAC_A;
  
  TRACE_POP
  return 0;
}
int ThermostatMonitor_CentralMonitor_functionJacB_column(void* inData, threadData_t *threadData)
{
  TRACE_PUSH

  DATA* data = ((DATA*)inData);
  int index = ThermostatMonitor_CentralMonitor_INDEX_JAC_B;
  
  TRACE_POP
  return 0;
}
int ThermostatMonitor_CentralMonitor_functionJacC_column(void* inData, threadData_t *threadData)
{
  TRACE_PUSH

  DATA* data = ((DATA*)inData);
  int index = ThermostatMonitor_CentralMonitor_INDEX_JAC_C;
  
  TRACE_POP
  return 0;
}
int ThermostatMonitor_CentralMonitor_functionJacD_column(void* inData, threadData_t *threadData)
{
  TRACE_PUSH

  DATA* data = ((DATA*)inData);
  int index = ThermostatMonitor_CentralMonitor_INDEX_JAC_D;
  
  TRACE_POP
  return 0;
}


