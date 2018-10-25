/* Main Simulation File */
#include "ThermostatMonitor_CriticalTemperatureMonitor_model.h"


/* dummy VARINFO and FILEINFO */
const FILE_INFO dummyFILE_INFO = omc_dummyFileInfo;
const VAR_INFO dummyVAR_INFO = omc_dummyVarInfo;
#if defined(__cplusplus)
extern "C" {
#endif

int ThermostatMonitor_CriticalTemperatureMonitor_input_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->localData[0]->realVars[2] /* hysteresis variable */ = data->simulationInfo->inputVars[0];
  data->localData[0]->realVars[4] /* request variable */ = data->simulationInfo->inputVars[1];
  data->localData[0]->realVars[5] /* target variable */ = data->simulationInfo->inputVars[2];
  data->localData[0]->realVars[6] /* temperature variable */ = data->simulationInfo->inputVars[3];
  
  TRACE_POP
  return 0;
}

int ThermostatMonitor_CriticalTemperatureMonitor_input_function_init(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->inputVars[0] = data->modelData->realVarsData[2].attribute.start;
  data->simulationInfo->inputVars[1] = data->modelData->realVarsData[4].attribute.start;
  data->simulationInfo->inputVars[2] = data->modelData->realVarsData[5].attribute.start;
  data->simulationInfo->inputVars[3] = data->modelData->realVarsData[6].attribute.start;
  
  TRACE_POP
  return 0;
}

int ThermostatMonitor_CriticalTemperatureMonitor_input_function_updateStartValues(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->modelData->realVarsData[2].attribute.start = data->simulationInfo->inputVars[0];
  data->modelData->realVarsData[4].attribute.start = data->simulationInfo->inputVars[1];
  data->modelData->realVarsData[5].attribute.start = data->simulationInfo->inputVars[2];
  data->modelData->realVarsData[6].attribute.start = data->simulationInfo->inputVars[3];
  
  TRACE_POP
  return 0;
}

int ThermostatMonitor_CriticalTemperatureMonitor_inputNames(DATA *data, char ** names){
  TRACE_PUSH

  names[0] = (char *) data->modelData->realVarsData[2].info.name;
  names[1] = (char *) data->modelData->realVarsData[4].info.name;
  names[2] = (char *) data->modelData->realVarsData[5].info.name;
  names[3] = (char *) data->modelData->realVarsData[6].info.name;
  
  TRACE_POP
  return 0;
}

int ThermostatMonitor_CriticalTemperatureMonitor_output_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->outputVars[0] = data->localData[0]->realVars[3] /* reply variable */;
  
  TRACE_POP
  return 0;
}


/*
 equation index: 5
 type: SIMPLE_ASSIGN
 currentTarget = if target < temperature then target + hysteresis else target - hysteresis
 */
void ThermostatMonitor_CriticalTemperatureMonitor_eqFunction_5(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,5};
  modelica_boolean tmp4;
  RELATIONHYSTERESIS(tmp4, data->localData[0]->realVars[5] /* target variable */, data->localData[0]->realVars[6] /* temperature variable */, 0, Less);
  data->localData[0]->realVars[1] /* currentTarget variable */ = (tmp4?data->localData[0]->realVars[5] /* target variable */ + data->localData[0]->realVars[2] /* hysteresis variable */:data->localData[0]->realVars[5] /* target variable */ - data->localData[0]->realVars[2] /* hysteresis variable */);
  TRACE_POP
}
/*
 equation index: 6
 type: SIMPLE_ASSIGN
 critical = temperature < target - hysteresis
 */
void ThermostatMonitor_CriticalTemperatureMonitor_eqFunction_6(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,6};
  modelica_boolean tmp5;
  RELATIONHYSTERESIS(tmp5, data->localData[0]->realVars[6] /* temperature variable */, data->localData[0]->realVars[5] /* target variable */ - data->localData[0]->realVars[2] /* hysteresis variable */, 1, Less);
  data->localData[0]->booleanVars[0] /* critical DISCRETE */ = tmp5;
  TRACE_POP
}
/*
 equation index: 7
 type: SIMPLE_ASSIGN
 reply = if request < 0.5 then -1.0 else if critical then 1.0 else 0.0
 */
void ThermostatMonitor_CriticalTemperatureMonitor_eqFunction_7(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,7};
  modelica_boolean tmp6;
  RELATIONHYSTERESIS(tmp6, data->localData[0]->realVars[4] /* request variable */, 0.5, 2, Less);
  data->localData[0]->realVars[3] /* reply variable */ = (tmp6?-1.0:(data->localData[0]->booleanVars[0] /* critical DISCRETE */?1.0:0.0));
  TRACE_POP
}


int ThermostatMonitor_CriticalTemperatureMonitor_functionDAE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  int equationIndexes[1] = {0};
  
  data->simulationInfo->needToIterate = 0;
  data->simulationInfo->discreteCall = 1;
  ThermostatMonitor_CriticalTemperatureMonitor_functionLocalKnownVars(data, threadData);
  ThermostatMonitor_CriticalTemperatureMonitor_eqFunction_5(data, threadData);

  ThermostatMonitor_CriticalTemperatureMonitor_eqFunction_6(data, threadData);

  ThermostatMonitor_CriticalTemperatureMonitor_eqFunction_7(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}


int ThermostatMonitor_CriticalTemperatureMonitor_functionLocalKnownVars(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


int ThermostatMonitor_CriticalTemperatureMonitor_functionODE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  data->simulationInfo->callStatistics.functionODE++;
  
  ThermostatMonitor_CriticalTemperatureMonitor_functionLocalKnownVars(data, threadData);
  /* no ODE systems */

  
  TRACE_POP
  return 0;
}

#ifdef FMU_EXPERIMENTAL
#endif
/* forward the main in the simulation runtime */
extern int _main_SimulationRuntime(int argc, char**argv, DATA *data, threadData_t *threadData);

#include "ThermostatMonitor_CriticalTemperatureMonitor_12jac.h"
#include "ThermostatMonitor_CriticalTemperatureMonitor_13opt.h"

struct OpenModelicaGeneratedFunctionCallbacks ThermostatMonitor_CriticalTemperatureMonitor_callback = {
   NULL,
   NULL,
   NULL,
   ThermostatMonitor_CriticalTemperatureMonitor_callExternalObjectDestructors,
   NULL,
   NULL,
   NULL,
   #if !defined(OMC_NO_STATESELECTION)
   ThermostatMonitor_CriticalTemperatureMonitor_initializeStateSets,
   #else
   NULL,
   #endif
   ThermostatMonitor_CriticalTemperatureMonitor_initializeDAEmodeData,
   ThermostatMonitor_CriticalTemperatureMonitor_functionODE,
   ThermostatMonitor_CriticalTemperatureMonitor_functionAlgebraics,
   ThermostatMonitor_CriticalTemperatureMonitor_functionDAE,
   ThermostatMonitor_CriticalTemperatureMonitor_functionLocalKnownVars,
   ThermostatMonitor_CriticalTemperatureMonitor_input_function,
   ThermostatMonitor_CriticalTemperatureMonitor_input_function_init,
   ThermostatMonitor_CriticalTemperatureMonitor_input_function_updateStartValues,
   ThermostatMonitor_CriticalTemperatureMonitor_output_function,
   ThermostatMonitor_CriticalTemperatureMonitor_function_storeDelayed,
   ThermostatMonitor_CriticalTemperatureMonitor_updateBoundVariableAttributes,
   ThermostatMonitor_CriticalTemperatureMonitor_functionInitialEquations,
   0, /* useHomotopy - 0: no homotopy or local homotopy, 1: global homotopy, 2: new global homotopy approach */
   ThermostatMonitor_CriticalTemperatureMonitor_functionInitialEquations_lambda0,
   ThermostatMonitor_CriticalTemperatureMonitor_functionRemovedInitialEquations,
   ThermostatMonitor_CriticalTemperatureMonitor_updateBoundParameters,
   ThermostatMonitor_CriticalTemperatureMonitor_checkForAsserts,
   ThermostatMonitor_CriticalTemperatureMonitor_function_ZeroCrossingsEquations,
   ThermostatMonitor_CriticalTemperatureMonitor_function_ZeroCrossings,
   ThermostatMonitor_CriticalTemperatureMonitor_function_updateRelations,
   ThermostatMonitor_CriticalTemperatureMonitor_checkForDiscreteChanges,
   ThermostatMonitor_CriticalTemperatureMonitor_zeroCrossingDescription,
   ThermostatMonitor_CriticalTemperatureMonitor_relationDescription,
   ThermostatMonitor_CriticalTemperatureMonitor_function_initSample,
   ThermostatMonitor_CriticalTemperatureMonitor_INDEX_JAC_A,
   ThermostatMonitor_CriticalTemperatureMonitor_INDEX_JAC_B,
   ThermostatMonitor_CriticalTemperatureMonitor_INDEX_JAC_C,
   ThermostatMonitor_CriticalTemperatureMonitor_INDEX_JAC_D,
   ThermostatMonitor_CriticalTemperatureMonitor_initialAnalyticJacobianA,
   ThermostatMonitor_CriticalTemperatureMonitor_initialAnalyticJacobianB,
   ThermostatMonitor_CriticalTemperatureMonitor_initialAnalyticJacobianC,
   ThermostatMonitor_CriticalTemperatureMonitor_initialAnalyticJacobianD,
   ThermostatMonitor_CriticalTemperatureMonitor_functionJacA_column,
   ThermostatMonitor_CriticalTemperatureMonitor_functionJacB_column,
   ThermostatMonitor_CriticalTemperatureMonitor_functionJacC_column,
   ThermostatMonitor_CriticalTemperatureMonitor_functionJacD_column,
   ThermostatMonitor_CriticalTemperatureMonitor_linear_model_frame,
   ThermostatMonitor_CriticalTemperatureMonitor_linear_model_datarecovery_frame,
   ThermostatMonitor_CriticalTemperatureMonitor_mayer,
   ThermostatMonitor_CriticalTemperatureMonitor_lagrange,
   ThermostatMonitor_CriticalTemperatureMonitor_pickUpBoundsForInputsInOptimization,
   ThermostatMonitor_CriticalTemperatureMonitor_setInputData,
   ThermostatMonitor_CriticalTemperatureMonitor_getTimeGrid,
   ThermostatMonitor_CriticalTemperatureMonitor_symbolicInlineSystem,
   ThermostatMonitor_CriticalTemperatureMonitor_function_initSynchronous,
   ThermostatMonitor_CriticalTemperatureMonitor_function_updateSynchronous,
   ThermostatMonitor_CriticalTemperatureMonitor_function_equationsSynchronous,
   ThermostatMonitor_CriticalTemperatureMonitor_read_input_fmu,
   #ifdef FMU_EXPERIMENTAL
   ThermostatMonitor_CriticalTemperatureMonitor_functionODE_Partial,
   ThermostatMonitor_CriticalTemperatureMonitor_functionFMIJacobian,
   #endif
   ThermostatMonitor_CriticalTemperatureMonitor_inputNames
};

void ThermostatMonitor_CriticalTemperatureMonitor_setupDataStruc(DATA *data, threadData_t *threadData)
{
  assertStreamPrint(threadData,0!=data, "Error while initialize Data");
  data->callback = &ThermostatMonitor_CriticalTemperatureMonitor_callback;
  data->modelData->modelName = "ThermostatMonitor.CriticalTemperatureMonitor";
  data->modelData->modelFilePrefix = "ThermostatMonitor_CriticalTemperatureMonitor";
  data->modelData->resultFileName = NULL;
  data->modelData->modelDir = "/home/farkasr/git/OMSimulator/StepSizeController/Thermostat";
  data->modelData->modelGUID = "{6df79e30-aed2-4063-a9af-49dca9cb8927}";
  data->modelData->initXMLData = NULL;
  data->modelData->modelDataXml.infoXMLData =
  #if defined(OMC_MINIMAL_METADATA)
    NULL;
  #else
  #include "ThermostatMonitor_CriticalTemperatureMonitor_info.c"
  #endif
  ;
  
  data->modelData->nStates = 0;
  data->modelData->nVariablesReal = 7;
  data->modelData->nDiscreteReal = 0;
  data->modelData->nVariablesInteger = 0;
  data->modelData->nVariablesBoolean = 1;
  data->modelData->nVariablesString = 0;
  data->modelData->nParametersReal = 0;
  data->modelData->nParametersInteger = 0;
  data->modelData->nParametersBoolean = 0;
  data->modelData->nParametersString = 0;
  data->modelData->nInputVars = 4;
  data->modelData->nOutputVars = 1;
  
  data->modelData->nAliasReal = 0;
  data->modelData->nAliasInteger = 0;
  data->modelData->nAliasBoolean = 0;
  data->modelData->nAliasString = 0;
  
  data->modelData->nZeroCrossings = 3;
  data->modelData->nSamples = 0;
  data->modelData->nRelations = 3;
  data->modelData->nMathEvents = 0;
  data->modelData->nExtObjs = 0;
  data->modelData->modelDataXml.fileName = "ThermostatMonitor_CriticalTemperatureMonitor_info.json";
  data->modelData->modelDataXml.modelInfoXmlLength = 0;
  data->modelData->modelDataXml.nFunctions = 0;
  data->modelData->modelDataXml.nProfileBlocks = 0;
  data->modelData->modelDataXml.nEquations = 9;
  data->modelData->nMixedSystems = 0;
  data->modelData->nLinearSystems = 0;
  data->modelData->nNonLinearSystems = 0;
  data->modelData->nStateSets = 0;
  data->modelData->nJacobians = 4;
  data->modelData->nOptimizeConstraints = 0;
  data->modelData->nOptimizeFinalConstraints = 0;
  
  data->modelData->nDelayExpressions = 0;
  
  data->modelData->nClocks = 0;
  data->modelData->nSubClocks = 0;
  
  data->modelData->nSensitivityVars = 0;
  data->modelData->nSensitivityParamVars = 0;
}

#ifdef __cplusplus
}
#endif

static int rml_execution_failed()
{
  fflush(NULL);
  fprintf(stderr, "Execution failed!\n");
  fflush(NULL);
  return 1;
}

