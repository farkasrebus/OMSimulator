/* Linear Systems */
#include "Room_model.h"
#include "Room_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

/* initial linear systems */

/*
 equation index: 47
 type: SIMPLE_ASSIGN
 heaCap._der_T = DIVISION(($DER.vol.hOut_internal + -2501014.5 * $DER.vol.dynBal.medium.Xi[1]) * (1006.0 * (1.0 - vol.dynBal.medium.Xi[1]) + 1860.0 * vol.dynBal.medium.Xi[1]) + 854.0 * ((-vol.hOut_internal) - -2501014.5 * vol.dynBal.medium.Xi[1]) * $DER.vol.dynBal.medium.Xi[1], (1006.0 * (1.0 - vol.dynBal.medium.Xi[1]) + 1860.0 * vol.dynBal.medium.Xi[1]) ^ 2.0)
 */
void Room_eqFunction_47(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,47};
  modelica_real tmp0;
  tmp0 = (1006.0) * (1.0 - data->localData[0]->realVars[1] /* vol._dynBal._medium._Xi[1] STATE(1) */) + (1860.0) * (data->localData[0]->realVars[1] /* vol._dynBal._medium._Xi[1] STATE(1) */);
  data->localData[0]->realVars[12] /* heaCap._der_T variable */ = DIVISION_SIM((data->localData[0]->realVars[5] /* der(vol._hOut_internal) STATE_DER */ + (-2501014.5) * (data->localData[0]->realVars[4] /* der(vol._dynBal._medium._Xi[1]) STATE_DER */)) * ((1006.0) * (1.0 - data->localData[0]->realVars[1] /* vol._dynBal._medium._Xi[1] STATE(1) */) + (1860.0) * (data->localData[0]->realVars[1] /* vol._dynBal._medium._Xi[1] STATE(1) */)) + (854.0) * (((-data->localData[0]->realVars[2] /* vol._hOut_internal STATE(1) */) - ((-2501014.5) * (data->localData[0]->realVars[1] /* vol._dynBal._medium._Xi[1] STATE(1) */))) * (data->localData[0]->realVars[4] /* der(vol._dynBal._medium._Xi[1]) STATE_DER */)),(tmp0 * tmp0),"(1006.0 * (1.0 - vol.dynBal.medium.Xi[1]) + 1860.0 * vol.dynBal.medium.Xi[1]) ^ 2.0",equationIndexes);
  TRACE_POP
}
/*
 equation index: 48
 type: SIMPLE_ASSIGN
 heaCap._port._Q_flow = 434592.0 * heaCap.der_T
 */
void Room_eqFunction_48(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,48};
  data->localData[0]->realVars[13] /* heaCap._port._Q_flow variable */ = (434592.0) * (data->localData[0]->realVars[12] /* heaCap._der_T variable */);
  TRACE_POP
}
/*
 equation index: 49
 type: SIMPLE_ASSIGN
 vol._heatPort._Q_flow = theCon.Q_flow - (preHea.port.Q_flow + heaCap.port.Q_flow)
 */
void Room_eqFunction_49(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,49};
  data->localData[0]->realVars[41] /* vol._heatPort._Q_flow variable */ = data->localData[0]->realVars[21] /* theCon._Q_flow variable */ - (data->localData[0]->realVars[17] /* preHea._port._Q_flow variable */ + data->localData[0]->realVars[13] /* heaCap._port._Q_flow variable */);
  TRACE_POP
}
/*
 equation index: 50
 type: SIMPLE_ASSIGN
 der(vol._dynBal._medium._u) = $DER.vol.hOut_internal
 */
void Room_eqFunction_50(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,50};
  data->localData[0]->realVars[9] /* der(vol._dynBal._medium._u) DUMMY_DER */ = data->localData[0]->realVars[5] /* der(vol._hOut_internal) STATE_DER */;
  TRACE_POP
}
/*
 equation index: 51
 type: SIMPLE_ASSIGN
 der(vol._dynBal._U) = vol.dynBal.m * $DER.vol.dynBal.medium.u + $DER.vol.dynBal.m * vol.dynBal.medium.u
 */
void Room_eqFunction_51(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,51};
  data->localData[0]->realVars[7] /* der(vol._dynBal._U) DUMMY_DER */ = (data->localData[0]->realVars[0] /* vol._dynBal._m STATE(1) */) * (data->localData[0]->realVars[9] /* der(vol._dynBal._medium._u) DUMMY_DER */) + (data->localData[0]->realVars[3] /* der(vol._dynBal._m) STATE_DER */) * (data->localData[0]->realVars[40] /* vol._dynBal._medium._u DUMMY_STATE */);
  TRACE_POP
}

void residualFunc57(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,57};
  data->localData[0]->realVars[5] /* der(vol._hOut_internal) STATE_DER */ = xloc[0];
  /* local constraints */
  Room_eqFunction_47(data, threadData);

  /* local constraints */
  Room_eqFunction_48(data, threadData);

  /* local constraints */
  Room_eqFunction_49(data, threadData);

  /* local constraints */
  Room_eqFunction_50(data, threadData);

  /* local constraints */
  Room_eqFunction_51(data, threadData);
  res[0] = data->localData[0]->realVars[41] /* vol._heatPort._Q_flow variable */ - data->localData[0]->realVars[7] /* der(vol._dynBal._U) DUMMY_DER */;
  TRACE_POP
}
void initializeStaticLSData57(void *inData, threadData_t *threadData, void *systemData)
{
  DATA* data = (DATA*) inData;
  LINEAR_SYSTEM_DATA* linearSystemData = (LINEAR_SYSTEM_DATA*) systemData;
  int i=0;
  /* static ls data for der(vol.hOut_internal) */
  linearSystemData->nominal[i] = data->modelData->realVarsData[5].attribute /* der(vol._hOut_internal) */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[5].attribute /* der(vol._hOut_internal) */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[5].attribute /* der(vol._hOut_internal) */.max;
}
/* initial_lambda0 linear systems */
/* parameter linear systems */
/* model linear systems */

/*
 equation index: 171
 type: SIMPLE_ASSIGN
 vol._heatPort._Q_flow = vol.dynBal.m * $DER.vol.dynBal.medium.u + der(vol.dynBal.m) * vol.dynBal.medium.u
 */
void Room_eqFunction_171(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,171};
  data->localData[0]->realVars[41] /* vol._heatPort._Q_flow variable */ = (data->localData[0]->realVars[0] /* vol._dynBal._m STATE(1) */) * (data->localData[0]->realVars[9] /* der(vol._dynBal._medium._u) DUMMY_DER */) + (data->localData[0]->realVars[3] /* der(vol._dynBal._m) STATE_DER */) * (data->localData[0]->realVars[40] /* vol._dynBal._medium._u DUMMY_STATE */);
  TRACE_POP
}
/*
 equation index: 172
 type: SIMPLE_ASSIGN
 heaCap._port._Q_flow = theCon.Q_flow - (preHea.port.Q_flow + vol.heatPort.Q_flow)
 */
void Room_eqFunction_172(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,172};
  data->localData[0]->realVars[13] /* heaCap._port._Q_flow variable */ = data->localData[0]->realVars[21] /* theCon._Q_flow variable */ - (data->localData[0]->realVars[17] /* preHea._port._Q_flow variable */ + data->localData[0]->realVars[41] /* vol._heatPort._Q_flow variable */);
  TRACE_POP
}
/*
 equation index: 173
 type: SIMPLE_ASSIGN
 heaCap._der_T = heaCap.port.Q_flow / 434592.0
 */
void Room_eqFunction_173(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,173};
  modelica_real tmp0;
  tmp0 = 434592.0;
  if (tmp0 == 0) {throwStreamPrint(threadData, "Division by zero %s", "heaCap.port.Q_flow / 434592.0");}
  data->localData[0]->realVars[12] /* heaCap._der_T variable */ = (data->localData[0]->realVars[13] /* heaCap._port._Q_flow variable */) / tmp0;
  TRACE_POP
}
/*
 equation index: 174
 type: SIMPLE_ASSIGN
 der(vol._hOut_internal) = $DER.vol.dynBal.medium.u
 */
void Room_eqFunction_174(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,174};
  data->localData[0]->realVars[5] /* der(vol._hOut_internal) STATE_DER */ = data->localData[0]->realVars[9] /* der(vol._dynBal._medium._u) DUMMY_DER */;
  TRACE_POP
}

void residualFunc179(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,179};
  modelica_real tmp0;
  data->localData[0]->realVars[9] /* der(vol._dynBal._medium._u) DUMMY_DER */ = xloc[0];
  /* local constraints */
  Room_eqFunction_171(data, threadData);

  /* local constraints */
  Room_eqFunction_172(data, threadData);

  /* local constraints */
  Room_eqFunction_173(data, threadData);

  /* local constraints */
  Room_eqFunction_174(data, threadData);
  tmp0 = (1006.0) * (1.0 - data->localData[0]->realVars[1] /* vol._dynBal._medium._Xi[1] STATE(1) */) + (1860.0) * (data->localData[0]->realVars[1] /* vol._dynBal._medium._Xi[1] STATE(1) */);
  res[0] = (data->localData[0]->realVars[5] /* der(vol._hOut_internal) STATE_DER */ + (-2501014.5) * (data->localData[0]->realVars[4] /* der(vol._dynBal._medium._Xi[1]) STATE_DER */)) * ((1006.0) * (1.0 - data->localData[0]->realVars[1] /* vol._dynBal._medium._Xi[1] STATE(1) */) + (1860.0) * (data->localData[0]->realVars[1] /* vol._dynBal._medium._Xi[1] STATE(1) */)) + (854.0) * (((2501014.5) * (data->localData[0]->realVars[1] /* vol._dynBal._medium._Xi[1] STATE(1) */) - data->localData[0]->realVars[2] /* vol._hOut_internal STATE(1) */) * (data->localData[0]->realVars[4] /* der(vol._dynBal._medium._Xi[1]) STATE_DER */)) - ((data->localData[0]->realVars[12] /* heaCap._der_T variable */) * ((tmp0 * tmp0)));
  TRACE_POP
}
void initializeStaticLSData179(void *inData, threadData_t *threadData, void *systemData)
{
  DATA* data = (DATA*) inData;
  LINEAR_SYSTEM_DATA* linearSystemData = (LINEAR_SYSTEM_DATA*) systemData;
  int i=0;
  /* static ls data for der(vol.dynBal.medium.u) */
  linearSystemData->nominal[i] = data->modelData->realVarsData[9].attribute /* der(vol._dynBal._medium._u) */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[9].attribute /* der(vol._dynBal._medium._u) */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[9].attribute /* der(vol._dynBal._medium._u) */.max;
}
/* inline linear systems */
/* jacobians linear systems */

/* Prototypes for the strict sets (Dynamic Tearing) */

/* Global constraints for the casual sets */
/* function initialize linear systems */
void Room_initialLinearSystem(int nLinearSystems, LINEAR_SYSTEM_DATA* linearSystemData)
{
  /* initial linear systems */
  assertStreamPrint(NULL, nLinearSystems > 0, "Internal Error: indexlinearSystem mismatch!");
  linearSystemData[0].equationIndex = 57;
  linearSystemData[0].size = 1;
  linearSystemData[0].nnz = 0;
  linearSystemData[0].method = 1;
  linearSystemData[0].residualFunc = residualFunc57;
  linearSystemData[0].strictTearingFunctionCall = NULL;
  linearSystemData[0].analyticalJacobianColumn = Room_functionJacLSJac2_column;
  linearSystemData[0].initialAnalyticalJacobian = Room_initialAnalyticJacobianLSJac2;
  linearSystemData[0].jacobianIndex = 0;
  linearSystemData[0].setA = NULL;//setLinearMatrixA57;
  linearSystemData[0].setb = NULL; //setLinearVectorb57;
  linearSystemData[0].initializeStaticLSData = initializeStaticLSData57;
  /* initial_lambda0 linear systems */
  /* parameter linear systems */
  /* model linear systems */
  assertStreamPrint(NULL, nLinearSystems > 1, "Internal Error: indexlinearSystem mismatch!");
  linearSystemData[1].equationIndex = 179;
  linearSystemData[1].size = 1;
  linearSystemData[1].nnz = 0;
  linearSystemData[1].method = 1;
  linearSystemData[1].residualFunc = residualFunc179;
  linearSystemData[1].strictTearingFunctionCall = NULL;
  linearSystemData[1].analyticalJacobianColumn = Room_functionJacLSJac3_column;
  linearSystemData[1].initialAnalyticalJacobian = Room_initialAnalyticJacobianLSJac3;
  linearSystemData[1].jacobianIndex = 1;
  linearSystemData[1].setA = NULL;//setLinearMatrixA179;
  linearSystemData[1].setb = NULL; //setLinearVectorb179;
  linearSystemData[1].initializeStaticLSData = initializeStaticLSData179;
  /* inline linear systems */
  /* jacobians linear systems */
}

#if defined(__cplusplus)
}
#endif

