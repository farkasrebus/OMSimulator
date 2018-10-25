/* Main Simulation File */
#include "ThermostatMonitor_ThermostatOnMonitor_model.h"


/* dummy VARINFO and FILEINFO */
const FILE_INFO dummyFILE_INFO = omc_dummyFileInfo;
const VAR_INFO dummyVAR_INFO = omc_dummyVarInfo;
#if defined(__cplusplus)
extern "C" {
#endif

int ThermostatMonitor_ThermostatOnMonitor_input_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->localData[0]->realVars[1] /* request variable */ = data->simulationInfo->inputVars[0];
  data->localData[0]->integerVars[0] /* turnOff variable */ = data->simulationInfo->inputVars[1];
  data->localData[0]->integerVars[1] /* turnOn variable */ = data->simulationInfo->inputVars[2];
  
  TRACE_POP
  return 0;
}

int ThermostatMonitor_ThermostatOnMonitor_input_function_init(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->inputVars[0] = data->modelData->realVarsData[1].attribute.start;
  data->simulationInfo->inputVars[1] = data->modelData->integerVarsData[0].attribute.start;
  data->simulationInfo->inputVars[2] = data->modelData->integerVarsData[1].attribute.start;
  
  TRACE_POP
  return 0;
}

int ThermostatMonitor_ThermostatOnMonitor_input_function_updateStartValues(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->modelData->realVarsData[1].attribute.start = data->simulationInfo->inputVars[0];
  data->modelData->integerVarsData[0].attribute.start = data->simulationInfo->inputVars[1];
  data->modelData->integerVarsData[1].attribute.start = data->simulationInfo->inputVars[2];
  
  TRACE_POP
  return 0;
}

int ThermostatMonitor_ThermostatOnMonitor_inputNames(DATA *data, char ** names){
  TRACE_PUSH

  names[0] = (char *) data->modelData->realVarsData[1].info.name;
  names[1] = (char *) data->modelData->integerVarsData[0].info.name;
  names[2] = (char *) data->modelData->integerVarsData[1].info.name;
  
  TRACE_POP
  return 0;
}

int ThermostatMonitor_ThermostatOnMonitor_output_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->outputVars[0] = data->localData[0]->realVars[0] /* reply variable */;
  
  TRACE_POP
  return 0;
}


/*
 equation index: 4
 type: SIMPLE_ASSIGN
 turnedon = turnOn > 0 or pre(turnedon) and turnOff == 0
 */
void ThermostatMonitor_ThermostatOnMonitor_eqFunction_4(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,4};
  modelica_boolean tmp3;
  RELATION(tmp3, (modelica_integer)data->localData[0]->integerVars[1] /* turnOn variable */, ((modelica_integer) 0), 0, Greater);
  data->localData[0]->booleanVars[0] /* turnedon DISCRETE */ = (tmp3 || (data->simulationInfo->booleanVarsPre[0] /* turnedon DISCRETE */ && ((modelica_integer)data->localData[0]->integerVars[0] /* turnOff variable */ == ((modelica_integer) 0))));
  TRACE_POP
}
/*
 equation index: 5
 type: SIMPLE_ASSIGN
 reply = if request < 0.5 then -1.0 else if turnedon then 1.0 else 0.0
 */
void ThermostatMonitor_ThermostatOnMonitor_eqFunction_5(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,5};
  modelica_boolean tmp5;
  RELATIONHYSTERESIS(tmp5, data->localData[0]->realVars[1] /* request variable */, 0.5, 2, Less);
  data->localData[0]->realVars[0] /* reply variable */ = (tmp5?-1.0:(data->localData[0]->booleanVars[0] /* turnedon DISCRETE */?1.0:0.0));
  TRACE_POP
}


int ThermostatMonitor_ThermostatOnMonitor_functionDAE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  int equationIndexes[1] = {0};
  
  data->simulationInfo->needToIterate = 0;
  data->simulationInfo->discreteCall = 1;
  ThermostatMonitor_ThermostatOnMonitor_functionLocalKnownVars(data, threadData);
  ThermostatMonitor_ThermostatOnMonitor_eqFunction_4(data, threadData);

  ThermostatMonitor_ThermostatOnMonitor_eqFunction_5(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}


int ThermostatMonitor_ThermostatOnMonitor_functionLocalKnownVars(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


int ThermostatMonitor_ThermostatOnMonitor_functionODE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  data->simulationInfo->callStatistics.functionODE++;
  
  ThermostatMonitor_ThermostatOnMonitor_functionLocalKnownVars(data, threadData);
  /* no ODE systems */

  
  TRACE_POP
  return 0;
}

#ifdef FMU_EXPERIMENTAL
#endif
/* forward the main in the simulation runtime */
extern int _main_SimulationRuntime(int argc, char**argv, DATA *data, threadData_t *threadData);

#include "ThermostatMonitor_ThermostatOnMonitor_12jac.h"
#include "ThermostatMonitor_ThermostatOnMonitor_13opt.h"

struct OpenModelicaGeneratedFunctionCallbacks ThermostatMonitor_ThermostatOnMonitor_callback = {
   NULL,
   NULL,
   NULL,
   ThermostatMonitor_ThermostatOnMonitor_callExternalObjectDestructors,
   NULL,
   NULL,
   NULL,
   #if !defined(OMC_NO_STATESELECTION)
   ThermostatMonitor_ThermostatOnMonitor_initializeStateSets,
   #else
   NULL,
   #endif
   ThermostatMonitor_ThermostatOnMonitor_initializeDAEmodeData,
   ThermostatMonitor_ThermostatOnMonitor_functionODE,
   ThermostatMonitor_ThermostatOnMonitor_functionAlgebraics,
   ThermostatMonitor_ThermostatOnMonitor_functionDAE,
   ThermostatMonitor_ThermostatOnMonitor_functionLocalKnownVars,
   ThermostatMonitor_ThermostatOnMonitor_input_function,
   ThermostatMonitor_ThermostatOnMonitor_input_function_init,
   ThermostatMonitor_ThermostatOnMonitor_input_function_updateStartValues,
   ThermostatMonitor_ThermostatOnMonitor_output_function,
   ThermostatMonitor_ThermostatOnMonitor_function_storeDelayed,
   ThermostatMonitor_ThermostatOnMonitor_updateBoundVariableAttributes,
   ThermostatMonitor_ThermostatOnMonitor_functionInitialEquations,
   0, /* useHomotopy - 0: no homotopy or local homotopy, 1: global homotopy, 2: new global homotopy approach */
   ThermostatMonitor_ThermostatOnMonitor_functionInitialEquations_lambda0,
   ThermostatMonitor_ThermostatOnMonitor_functionRemovedInitialEquations,
   ThermostatMonitor_ThermostatOnMonitor_updateBoundParameters,
   ThermostatMonitor_ThermostatOnMonitor_checkForAsserts,
   ThermostatMonitor_ThermostatOnMonitor_function_ZeroCrossingsEquations,
   ThermostatMonitor_ThermostatOnMonitor_function_ZeroCrossings,
   ThermostatMonitor_ThermostatOnMonitor_function_updateRelations,
   ThermostatMonitor_ThermostatOnMonitor_checkForDiscreteChanges,
   ThermostatMonitor_ThermostatOnMonitor_zeroCrossingDescription,
   ThermostatMonitor_ThermostatOnMonitor_relationDescription,
   ThermostatMonitor_ThermostatOnMonitor_function_initSample,
   ThermostatMonitor_ThermostatOnMonitor_INDEX_JAC_A,
   ThermostatMonitor_ThermostatOnMonitor_INDEX_JAC_B,
   ThermostatMonitor_ThermostatOnMonitor_INDEX_JAC_C,
   ThermostatMonitor_ThermostatOnMonitor_INDEX_JAC_D,
   ThermostatMonitor_ThermostatOnMonitor_initialAnalyticJacobianA,
   ThermostatMonitor_ThermostatOnMonitor_initialAnalyticJacobianB,
   ThermostatMonitor_ThermostatOnMonitor_initialAnalyticJacobianC,
   ThermostatMonitor_ThermostatOnMonitor_initialAnalyticJacobianD,
   ThermostatMonitor_ThermostatOnMonitor_functionJacA_column,
   ThermostatMonitor_ThermostatOnMonitor_functionJacB_column,
   ThermostatMonitor_ThermostatOnMonitor_functionJacC_column,
   ThermostatMonitor_ThermostatOnMonitor_functionJacD_column,
   ThermostatMonitor_ThermostatOnMonitor_linear_model_frame,
   ThermostatMonitor_ThermostatOnMonitor_linear_model_datarecovery_frame,
   ThermostatMonitor_ThermostatOnMonitor_mayer,
   ThermostatMonitor_ThermostatOnMonitor_lagrange,
   ThermostatMonitor_ThermostatOnMonitor_pickUpBoundsForInputsInOptimization,
   ThermostatMonitor_ThermostatOnMonitor_setInputData,
   ThermostatMonitor_ThermostatOnMonitor_getTimeGrid,
   ThermostatMonitor_ThermostatOnMonitor_symbolicInlineSystem,
   ThermostatMonitor_ThermostatOnMonitor_function_initSynchronous,
   ThermostatMonitor_ThermostatOnMonitor_function_updateSynchronous,
   ThermostatMonitor_ThermostatOnMonitor_function_equationsSynchronous,
   ThermostatMonitor_ThermostatOnMonitor_read_input_fmu,
   #ifdef FMU_EXPERIMENTAL
   ThermostatMonitor_ThermostatOnMonitor_functionODE_Partial,
   ThermostatMonitor_ThermostatOnMonitor_functionFMIJacobian,
   #endif
   ThermostatMonitor_ThermostatOnMonitor_inputNames
};

void ThermostatMonitor_ThermostatOnMonitor_setupDataStruc(DATA *data, threadData_t *threadData)
{
  assertStreamPrint(threadData,0!=data, "Error while initialize Data");
  data->callback = &ThermostatMonitor_ThermostatOnMonitor_callback;
  data->modelData->modelName = "ThermostatMonitor.ThermostatOnMonitor";
  data->modelData->modelFilePrefix = "ThermostatMonitor_ThermostatOnMonitor";
  data->modelData->resultFileName = NULL;
  data->modelData->modelDir = "/home/farkasr/git/OMSimulator/StepSizeController/Thermostat";
  data->modelData->modelGUID = "{55315148-79cb-4f7c-86db-0269bfc53883}";
  data->modelData->initXMLData = NULL;
  data->modelData->modelDataXml.infoXMLData =
  #if defined(OMC_MINIMAL_METADATA)
    NULL;
  #else
  #include "ThermostatMonitor_ThermostatOnMonitor_info.c"
  #endif
  ;
  
  data->modelData->nStates = 0;
  data->modelData->nVariablesReal = 2;
  data->modelData->nDiscreteReal = 0;
  data->modelData->nVariablesInteger = 2;
  data->modelData->nVariablesBoolean = 1;
  data->modelData->nVariablesString = 0;
  data->modelData->nParametersReal = 0;
  data->modelData->nParametersInteger = 0;
  data->modelData->nParametersBoolean = 0;
  data->modelData->nParametersString = 0;
  data->modelData->nInputVars = 3;
  data->modelData->nOutputVars = 1;
  
  data->modelData->nAliasReal = 0;
  data->modelData->nAliasInteger = 0;
  data->modelData->nAliasBoolean = 0;
  data->modelData->nAliasString = 0;
  
  data->modelData->nZeroCrossings = 2;
  data->modelData->nSamples = 0;
  data->modelData->nRelations = 3;
  data->modelData->nMathEvents = 0;
  data->modelData->nExtObjs = 0;
  data->modelData->modelDataXml.fileName = "ThermostatMonitor_ThermostatOnMonitor_info.json";
  data->modelData->modelDataXml.modelInfoXmlLength = 0;
  data->modelData->modelDataXml.nFunctions = 0;
  data->modelData->modelDataXml.nProfileBlocks = 0;
  data->modelData->modelDataXml.nEquations = 6;
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

