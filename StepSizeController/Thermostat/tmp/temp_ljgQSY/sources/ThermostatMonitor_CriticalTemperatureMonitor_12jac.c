/* Jacobians */
#include "ThermostatMonitor_CriticalTemperatureMonitor_model.h"
#include "ThermostatMonitor_CriticalTemperatureMonitor_12jac.h"
int ThermostatMonitor_CriticalTemperatureMonitor_initialAnalyticJacobianA(void* inData, threadData_t *threadData)
{
  TRACE_PUSH
  TRACE_POP
  return 1;
}
int ThermostatMonitor_CriticalTemperatureMonitor_initialAnalyticJacobianB(void* inData, threadData_t *threadData)
{
  TRACE_PUSH
  TRACE_POP
  return 1;
}
int ThermostatMonitor_CriticalTemperatureMonitor_initialAnalyticJacobianC(void* inData, threadData_t *threadData)
{
  TRACE_PUSH
  TRACE_POP
  return 1;
}

int ThermostatMonitor_CriticalTemperatureMonitor_initialAnalyticJacobianD(void* inData, threadData_t *threadData)
{
  TRACE_PUSH
  DATA* data = ((DATA*)inData);
  int index = ThermostatMonitor_CriticalTemperatureMonitor_INDEX_JAC_D;
  const int colPtrIndex[1+4] = {0,1,1,1,1};
  const int rowIndex[4] = {0,0,0,0};
  int i = 0;
  
  data->simulationInfo->analyticJacobians[index].sizeCols = 4;
  data->simulationInfo->analyticJacobians[index].sizeRows = 1;
  data->simulationInfo->analyticJacobians[index].sizeTmpVars = 0;
  data->simulationInfo->analyticJacobians[index].seedVars = (modelica_real*) calloc(4,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].resultVars = (modelica_real*) calloc(1,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].tmpVars = (modelica_real*) calloc(0,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex = (unsigned int*) malloc((4+1)*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.index = (unsigned int*) malloc(4*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.numberOfNoneZeros = 4;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols = (unsigned int*) malloc(4*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.maxColors = 4;
  data->simulationInfo->analyticJacobians[index].jacobian = NULL;
  
  /* write lead index of compressed sparse column */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex, colPtrIndex, (4+1)*sizeof(int));
  
  for(i=2;i<4+1;++i)
    data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i] += data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i-1];
  
  /* call sparse index */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.index, rowIndex, 4*sizeof(int));
  
  /* write color array */
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[3] = 1;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[2] = 2;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[0] = 3;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[1] = 4;
  TRACE_POP
  return 0;
}

int ThermostatMonitor_CriticalTemperatureMonitor_functionJacA_column(void* data, threadData_t *threadData)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
int ThermostatMonitor_CriticalTemperatureMonitor_functionJacB_column(void* data, threadData_t *threadData)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
int ThermostatMonitor_CriticalTemperatureMonitor_functionJacC_column(void* data, threadData_t *threadData)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
int ThermostatMonitor_CriticalTemperatureMonitor_functionJacD_column(void* inData, threadData_t *threadData)
{
  TRACE_PUSH

  DATA* data = ((DATA*)inData);
  int index = ThermostatMonitor_CriticalTemperatureMonitor_INDEX_JAC_D;
  
  TRACE_POP
  return 0;
}


