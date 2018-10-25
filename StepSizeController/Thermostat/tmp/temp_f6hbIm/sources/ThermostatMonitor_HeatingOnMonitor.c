/* Main Simulation File */
#include "ThermostatMonitor_HeatingOnMonitor_model.h"


/* dummy VARINFO and FILEINFO */
const FILE_INFO dummyFILE_INFO = omc_dummyFileInfo;
const VAR_INFO dummyVAR_INFO = omc_dummyVarInfo;
#if defined(__cplusplus)
extern "C" {
#endif

int ThermostatMonitor_HeatingOnMonitor_input_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->localData[0]->realVars[1] /* request variable */ = data->simulationInfo->inputVars[0];
  data->localData[0]->integerVars[0] /* turnOff variable */ = data->simulationInfo->inputVars[1];
  data->localData[0]->integerVars[1] /* turnOn variable */ = data->simulationInfo->inputVars[2];
  
  TRACE_POP
  return 0;
}

int ThermostatMonitor_HeatingOnMonitor_input_function_init(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->inputVars[0] = data->modelData->realVarsData[1].attribute.start;
  data->simulationInfo->inputVars[1] = data->modelData->integerVarsData[0].attribute.start;
  data->simulationInfo->inputVars[2] = data->modelData->integerVarsData[1].attribute.start;
  
  TRACE_POP
  return 0;
}

int ThermostatMonitor_HeatingOnMonitor_input_function_updateStartValues(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->modelData->realVarsData[1].attribute.start = data->simulationInfo->inputVars[0];
  data->modelData->integerVarsData[0].attribute.start = data->simulationInfo->inputVars[1];
  data->modelData->integerVarsData[1].attribute.start = data->simulationInfo->inputVars[2];
  
  TRACE_POP
  return 0;
}

int ThermostatMonitor_HeatingOnMonitor_inputNames(DATA *data, char ** names){
  TRACE_PUSH

  names[0] = (char *) data->modelData->realVarsData[1].info.name;
  names[1] = (char *) data->modelData->integerVarsData[0].info.name;
  names[2] = (char *) data->modelData->integerVarsData[1].info.name;
  
  TRACE_POP
  return 0;
}

int ThermostatMonitor_HeatingOnMonitor_output_function(DATA *data, threadData_t *threadData)
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
void ThermostatMonitor_HeatingOnMonitor_eqFunction_4(DATA *data, threadData_t *threadData)
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
 reply = if request < 0.5 then -1.0 else if turnedon then 0.0 else 1.0
 */
void ThermostatMonitor_HeatingOnMonitor_eqFunction_5(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,5};
  modelica_boolean tmp5;
  RELATIONHYSTERESIS(tmp5, data->localData[0]->realVars[1] /* request variable */, 0.5, 2, Less);
  data->localData[0]->realVars[0] /* reply variable */ = (tmp5?-1.0:(data->localData[0]->booleanVars[0] /* turnedon DISCRETE */?0.0:1.0));
  TRACE_POP
}


int ThermostatMonitor_HeatingOnMonitor_functionDAE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  int equationIndexes[1] = {0};
  
  data->simulationInfo->needToIterate = 0;
  data->simulationInfo->discreteCall = 1;
  ThermostatMonitor_HeatingOnMonitor_functionLocalKnownVars(data, threadData);
  ThermostatMonitor_HeatingOnMonitor_eqFunction_4(data, threadData);

  ThermostatMonitor_HeatingOnMonitor_eqFunction_5(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}


int ThermostatMonitor_HeatingOnMonitor_functionLocalKnownVars(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


int ThermostatMonitor_HeatingOnMonitor_functionODE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  data->simulationInfo->callStatistics.functionODE++;
  
  ThermostatMonitor_HeatingOnMonitor_functionLocalKnownVars(data, threadData);
  /* no ODE systems */

  
  TRACE_POP
  return 0;
}

#ifdef FMU_EXPERIMENTAL
#endif
/* forward the main in the simulation runtime */
extern int _main_SimulationRuntime(int argc, char**argv, DATA *data, threadData_t *threadData);

#include "ThermostatMonitor_HeatingOnMonitor_12jac.h"
#include "ThermostatMonitor_HeatingOnMonitor_13opt.h"

struct OpenModelicaGeneratedFunctionCallbacks ThermostatMonitor_HeatingOnMonitor_callback = {
   NULL,
   NULL,
   NULL,
   ThermostatMonitor_HeatingOnMonitor_callExternalObjectDestructors,
   NULL,
   NULL,
   NULL,
   #if !defined(OMC_NO_STATESELECTION)
   ThermostatMonitor_HeatingOnMonitor_initializeStateSets,
   #else
   NULL,
   #endif
   ThermostatMonitor_HeatingOnMonitor_initializeDAEmodeData,
   ThermostatMonitor_HeatingOnMonitor_functionODE,
   ThermostatMonitor_HeatingOnMonitor_functionAlgebraics,
   ThermostatMonitor_HeatingOnMonitor_functionDAE,
   ThermostatMonitor_HeatingOnMonitor_functionLocalKnownVars,
   ThermostatMonitor_HeatingOnMonitor_input_function,
   ThermostatMonitor_HeatingOnMonitor_input_function_init,
   ThermostatMonitor_HeatingOnMonitor_input_function_updateStartValues,
   ThermostatMonitor_HeatingOnMonitor_output_function,
   ThermostatMonitor_HeatingOnMonitor_function_storeDelayed,
   ThermostatMonitor_HeatingOnMonitor_updateBoundVariableAttributes,
   ThermostatMonitor_HeatingOnMonitor_functionInitialEquations,
   0, /* useHomotopy - 0: no homotopy or local homotopy, 1: global homotopy, 2: new global homotopy approach */
   ThermostatMonitor_HeatingOnMonitor_functionInitialEquations_lambda0,
   ThermostatMonitor_HeatingOnMonitor_functionRemovedInitialEquations,
   ThermostatMonitor_HeatingOnMonitor_updateBoundParameters,
   ThermostatMonitor_HeatingOnMonitor_checkForAsserts,
   ThermostatMonitor_HeatingOnMonitor_function_ZeroCrossingsEquations,
   ThermostatMonitor_HeatingOnMonitor_function_ZeroCrossings,
   ThermostatMonitor_HeatingOnMonitor_function_updateRelations,
   ThermostatMonitor_HeatingOnMonitor_checkForDiscreteChanges,
   ThermostatMonitor_HeatingOnMonitor_zeroCrossingDescription,
   ThermostatMonitor_HeatingOnMonitor_relationDescription,
   ThermostatMonitor_HeatingOnMonitor_function_initSample,
   ThermostatMonitor_HeatingOnMonitor_INDEX_JAC_A,
   ThermostatMonitor_HeatingOnMonitor_INDEX_JAC_B,
   ThermostatMonitor_HeatingOnMonitor_INDEX_JAC_C,
   ThermostatMonitor_HeatingOnMonitor_INDEX_JAC_D,
   ThermostatMonitor_HeatingOnMonitor_initialAnalyticJacobianA,
   ThermostatMonitor_HeatingOnMonitor_initialAnalyticJacobianB,
   ThermostatMonitor_HeatingOnMonitor_initialAnalyticJacobianC,
   ThermostatMonitor_HeatingOnMonitor_initialAnalyticJacobianD,
   ThermostatMonitor_HeatingOnMonitor_functionJacA_column,
   ThermostatMonitor_HeatingOnMonitor_functionJacB_column,
   ThermostatMonitor_HeatingOnMonitor_functionJacC_column,
   ThermostatMonitor_HeatingOnMonitor_functionJacD_column,
   ThermostatMonitor_HeatingOnMonitor_linear_model_frame,
   ThermostatMonitor_HeatingOnMonitor_linear_model_datarecovery_frame,
   ThermostatMonitor_HeatingOnMonitor_mayer,
   ThermostatMonitor_HeatingOnMonitor_lagrange,
   ThermostatMonitor_HeatingOnMonitor_pickUpBoundsForInputsInOptimization,
   ThermostatMonitor_HeatingOnMonitor_setInputData,
   ThermostatMonitor_HeatingOnMonitor_getTimeGrid,
   ThermostatMonitor_HeatingOnMonitor_symbolicInlineSystem,
   ThermostatMonitor_HeatingOnMonitor_function_initSynchronous,
   ThermostatMonitor_HeatingOnMonitor_function_updateSynchronous,
   ThermostatMonitor_HeatingOnMonitor_function_equationsSynchronous,
   ThermostatMonitor_HeatingOnMonitor_read_input_fmu,
   #ifdef FMU_EXPERIMENTAL
   ThermostatMonitor_HeatingOnMonitor_functionODE_Partial,
   ThermostatMonitor_HeatingOnMonitor_functionFMIJacobian,
   #endif
   ThermostatMonitor_HeatingOnMonitor_inputNames
};

void ThermostatMonitor_HeatingOnMonitor_setupDataStruc(DATA *data, threadData_t *threadData)
{
  assertStreamPrint(threadData,0!=data, "Error while initialize Data");
  data->callback = &ThermostatMonitor_HeatingOnMonitor_callback;
  data->modelData->modelName = "ThermostatMonitor.HeatingOnMonitor";
  data->modelData->modelFilePrefix = "ThermostatMonitor_HeatingOnMonitor";
  data->modelData->resultFileName = NULL;
  data->modelData->modelDir = "/home/farkasr/git/OMSimulator/StepSizeController/Thermostat";
  data->modelData->modelGUID = "{d8f86733-647a-4b59-8a31-3d7ff510ca12}";
  data->modelData->initXMLData = NULL;
  data->modelData->modelDataXml.infoXMLData =
  #if defined(OMC_MINIMAL_METADATA)
    NULL;
  #else
  #include "ThermostatMonitor_HeatingOnMonitor_info.c"
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
  data->modelData->modelDataXml.fileName = "ThermostatMonitor_HeatingOnMonitor_info.json";
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

