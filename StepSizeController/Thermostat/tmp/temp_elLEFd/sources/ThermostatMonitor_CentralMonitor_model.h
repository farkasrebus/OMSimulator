/* Simulation code for ThermostatMonitor.CentralMonitor generated by the OpenModelica Compiler OpenModelica 1.12.0~7-g6d56dda. */
#if !defined(ThermostatMonitor_CentralMonitor__MODEL_H)
#define ThermostatMonitor_CentralMonitor__MODEL_H
#include "openmodelica.h"
#include "openmodelica_func.h"
#include "simulation_data.h"
#include "simulation/simulation_info_json.h"
#include "simulation/simulation_runtime.h"
#include "util/omc_error.h"
#include "simulation/solver/model_help.h"
#include "simulation/solver/delay.h"
#include "simulation/solver/linearSystem.h"
#include "simulation/solver/nonlinearSystem.h"
#include "simulation/solver/mixedSystem.h"

#include <string.h>

#include "ThermostatMonitor_CentralMonitor_functions.h"


extern void ThermostatMonitor_CentralMonitor_callExternalObjectDestructors(DATA *_data, threadData_t *threadData);
#if !defined(OMC_NUM_NONLINEAR_SYSTEMS) || OMC_NUM_NONLINEAR_SYSTEMS>0
#endif
#if !defined(OMC_NUM_LINEAR_SYSTEMS) || OMC_NUM_LINEAR_SYSTEMS>0
#endif
#if !defined(OMC_NUM_MIXED_SYSTEMS) || OMC_NUM_MIXED_SYSTEMS>0
#endif
#if !defined(OMC_NO_STATESELECTION)
extern void ThermostatMonitor_CentralMonitor_initializeStateSets(int nStateSets, STATE_SET_DATA* statesetData, DATA *data);
#endif
extern int ThermostatMonitor_CentralMonitor_functionAlgebraics(DATA *data, threadData_t *threadData);
extern int ThermostatMonitor_CentralMonitor_function_storeDelayed(DATA *data, threadData_t *threadData);
extern int ThermostatMonitor_CentralMonitor_updateBoundVariableAttributes(DATA *data, threadData_t *threadData);
extern int ThermostatMonitor_CentralMonitor_functionInitialEquations(DATA *data, threadData_t *threadData);
extern int ThermostatMonitor_CentralMonitor_functionInitialEquations_lambda0(DATA *data, threadData_t *threadData);
extern int ThermostatMonitor_CentralMonitor_functionRemovedInitialEquations(DATA *data, threadData_t *threadData);
extern int ThermostatMonitor_CentralMonitor_updateBoundParameters(DATA *data, threadData_t *threadData);
extern int ThermostatMonitor_CentralMonitor_checkForAsserts(DATA *data, threadData_t *threadData);
extern int ThermostatMonitor_CentralMonitor_function_ZeroCrossingsEquations(DATA *data, threadData_t *threadData);
extern int ThermostatMonitor_CentralMonitor_function_ZeroCrossings(DATA *data, threadData_t *threadData, double* gout);
extern int ThermostatMonitor_CentralMonitor_function_updateRelations(DATA *data, threadData_t *threadData, int evalZeroCross);
extern int ThermostatMonitor_CentralMonitor_checkForDiscreteChanges(DATA *data, threadData_t *threadData);
extern const char* ThermostatMonitor_CentralMonitor_zeroCrossingDescription(int i, int **out_EquationIndexes);
extern const char* ThermostatMonitor_CentralMonitor_relationDescription(int i);
extern void ThermostatMonitor_CentralMonitor_function_initSample(DATA *data, threadData_t *threadData);
extern int ThermostatMonitor_CentralMonitor_initialAnalyticJacobianG(void* data, threadData_t *threadData);
extern int ThermostatMonitor_CentralMonitor_initialAnalyticJacobianA(void* data, threadData_t *threadData);
extern int ThermostatMonitor_CentralMonitor_initialAnalyticJacobianB(void* data, threadData_t *threadData);
extern int ThermostatMonitor_CentralMonitor_initialAnalyticJacobianC(void* data, threadData_t *threadData);
extern int ThermostatMonitor_CentralMonitor_initialAnalyticJacobianD(void* data, threadData_t *threadData);
extern int ThermostatMonitor_CentralMonitor_functionJacG_column(void* data, threadData_t *threadData);
extern int ThermostatMonitor_CentralMonitor_functionJacA_column(void* data, threadData_t *threadData);
extern int ThermostatMonitor_CentralMonitor_functionJacB_column(void* data, threadData_t *threadData);
extern int ThermostatMonitor_CentralMonitor_functionJacC_column(void* data, threadData_t *threadData);
extern int ThermostatMonitor_CentralMonitor_functionJacD_column(void* data, threadData_t *threadData);
extern const char* ThermostatMonitor_CentralMonitor_linear_model_frame(void);
extern const char* ThermostatMonitor_CentralMonitor_linear_model_datarecovery_frame(void);
extern int ThermostatMonitor_CentralMonitor_mayer(DATA* data, modelica_real** res, short *);
extern int ThermostatMonitor_CentralMonitor_lagrange(DATA* data, modelica_real** res, short *, short *);
extern int ThermostatMonitor_CentralMonitor_pickUpBoundsForInputsInOptimization(DATA* data, modelica_real* min, modelica_real* max, modelica_real*nominal, modelica_boolean *useNominal, char ** name, modelica_real * start, modelica_real * startTimeOpt);
extern int ThermostatMonitor_CentralMonitor_setInputData(DATA *data, const modelica_boolean file);
extern int ThermostatMonitor_CentralMonitor_getTimeGrid(DATA *data, modelica_integer * nsi, modelica_real**t);
extern void ThermostatMonitor_CentralMonitor_function_initSynchronous(DATA * data, threadData_t *threadData);
extern void ThermostatMonitor_CentralMonitor_function_updateSynchronous(DATA * data, threadData_t *threadData, long i);
extern int ThermostatMonitor_CentralMonitor_function_equationsSynchronous(DATA * data, threadData_t *threadData, long i);
extern void ThermostatMonitor_CentralMonitor_read_input_fmu(MODEL_DATA* modelData, SIMULATION_INFO* simulationData);
extern void ThermostatMonitor_CentralMonitor_function_savePreSynchronous(DATA *data, threadData_t *threadData);
extern int ThermostatMonitor_CentralMonitor_inputNames(DATA* data, char ** names);
extern int ThermostatMonitor_CentralMonitor_initializeDAEmodeData(DATA *data, DAEMODE_DATA*);
extern int ThermostatMonitor_CentralMonitor_functionLocalKnownVars(DATA*, threadData_t*);
extern int ThermostatMonitor_CentralMonitor_symbolicInlineSystem(DATA*, threadData_t*);

#include "ThermostatMonitor_CentralMonitor_literals.h"




#if defined(HPCOM) && !defined(_OPENMP)
  #error "HPCOM requires OpenMP or the results are wrong"
#endif
#if defined(_OPENMP)
  #include <omp.h>
#else
  /* dummy omp defines */
  #define omp_get_max_threads() 1
#endif

#endif

