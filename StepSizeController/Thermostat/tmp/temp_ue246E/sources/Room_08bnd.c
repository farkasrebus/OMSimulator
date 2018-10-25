/* update bound parameters and variable attributes (start, nominal, min, max) */
#include "Room_model.h"
#if defined(__cplusplus)
extern "C" {
#endif


/*
 equation index: 197
 type: SIMPLE_ASSIGN
 $START._vol._dynBal._U = 180.0 * vol.dynBal.rho_start * (-84437.5 + 1006.0 * (-273.15 + vol.dynBal.T_start) * (1.0 - vol.dynBal.X_start[1]) + (2501014.5 + 1860.0 * (-273.15 + vol.dynBal.T_start)) * vol.dynBal.X_start[1])
 */
void Room_eqFunction_197(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,197};
  data->modelData->realVarsData[27].attribute /* vol._dynBal._U DUMMY_STATE */.start = (180.0) * ((data->simulationInfo->realParameter[37]) * (-84437.5 + (1006.0) * ((-273.15 + data->simulationInfo->realParameter[28]) * (1.0 - data->simulationInfo->realParameter[29])) + (2501014.5 + (1860.0) * (-273.15 + data->simulationInfo->realParameter[28])) * (data->simulationInfo->realParameter[29])));
    data->localData[0]->realVars[27] /* vol._dynBal._U DUMMY_STATE */ = data->modelData->realVarsData[27].attribute /* vol._dynBal._U DUMMY_STATE */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[27].info /* vol._dynBal._U */.name, (modelica_real) data->localData[0]->realVars[27] /* vol._dynBal._U DUMMY_STATE */);
  TRACE_POP
}

/*
 equation index: 198
 type: SIMPLE_ASSIGN
 $START._vol._dynBal._medium._d = vol.dynBal.rho_start
 */
void Room_eqFunction_198(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,198};
  data->modelData->realVarsData[36].attribute /* vol._dynBal._medium._d variable */.start = data->simulationInfo->realParameter[37];
    data->localData[0]->realVars[36] /* vol._dynBal._medium._d variable */ = data->modelData->realVarsData[36].attribute /* vol._dynBal._medium._d variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[36].info /* vol._dynBal._medium._d */.name, (modelica_real) data->localData[0]->realVars[36] /* vol._dynBal._medium._d variable */);
  TRACE_POP
}

/*
 equation index: 199
 type: SIMPLE_ASSIGN
 $START._vol._hOut_internal = vol.dynBal.hStart
 */
void Room_eqFunction_199(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,199};
  data->modelData->realVarsData[2].attribute /* vol._hOut_internal STATE(1) */.start = data->simulationInfo->realParameter[33];
    data->localData[0]->realVars[2] /* vol._hOut_internal STATE(1) */ = data->modelData->realVarsData[2].attribute /* vol._hOut_internal STATE(1) */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[2].info /* vol._hOut_internal */.name, (modelica_real) data->localData[0]->realVars[2] /* vol._hOut_internal STATE(1) */);
  TRACE_POP
}
int Room_updateBoundVariableAttributes(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  /* min ******************************************************** */
  
  infoStreamPrint(LOG_INIT, 1, "updating min-values");
  if (ACTIVE_STREAM(LOG_INIT)) messageClose(LOG_INIT);
  
  /* max ******************************************************** */
  
  infoStreamPrint(LOG_INIT, 1, "updating max-values");
  if (ACTIVE_STREAM(LOG_INIT)) messageClose(LOG_INIT);
  
  /* nominal **************************************************** */
  
  infoStreamPrint(LOG_INIT, 1, "updating nominal-values");
  if (ACTIVE_STREAM(LOG_INIT)) messageClose(LOG_INIT);
  
  /* start ****************************************************** */
  infoStreamPrint(LOG_INIT, 1, "updating primary start-values");
  Room_eqFunction_197(data, threadData);

  Room_eqFunction_198(data, threadData);

  Room_eqFunction_199(data, threadData);
  if (ACTIVE_STREAM(LOG_INIT)) messageClose(LOG_INIT);
  
  TRACE_POP
  return 0;
}


/*
 equation index: 200
 type: SIMPLE_ASSIGN
 rSFlipFlop._pre._pre_u_start = not rSFlipFlop.Qini
 */
void Room_eqFunction_200(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,200};
  data->simulationInfo->booleanParameter[2] = (!data->simulationInfo->booleanParameter[1]);
  TRACE_POP
}

/*
 equation index: 201
 type: SIMPLE_ASSIGN
 booleanToReal1._realTrue = heatingFactor
 */
void Room_eqFunction_201(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,201};
  data->simulationInfo->realParameter[5] = data->simulationInfo->realParameter[7];
  TRACE_POP
}

/*
 equation index: 202
 type: SIMPLE_ASSIGN
 heaCap._C = 434592.0
 */
void Room_eqFunction_202(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,202};
  data->simulationInfo->realParameter[6] = 434592.0;
  TRACE_POP
}

/*
 equation index: 203
 type: SIMPLE_ASSIGN
 mA_flow_nominal = 0.3
 */
void Room_eqFunction_203(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,203};
  data->simulationInfo->realParameter[8] = 0.3;
  TRACE_POP
}

/*
 equation index: 204
 type: SIMPLE_ASSIGN
 V = 180.0
 */
void Room_eqFunction_204(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,204};
  data->simulationInfo->realParameter[3] = 180.0;
  TRACE_POP
}

/*
 equation index: 205
 type: SIMPLE_ASSIGN
 vol._dynBal._T_start = vol.T_start
 */
void Room_eqFunction_205(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,205};
  data->simulationInfo->realParameter[28] = data->simulationInfo->realParameter[23];
  TRACE_POP
}

/*
 equation index: 206
 type: SIMPLE_ASSIGN
 vol._dynBal._X_start[1] = vol.X_start[1]
 */
void Room_eqFunction_206(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,206};
  data->simulationInfo->realParameter[29] = data->simulationInfo->realParameter[25];
  TRACE_POP
}

/*
 equation index: 207
 type: SIMPLE_ASSIGN
 vol._dynBal._hStart = 1006.0 * (-273.15 + vol.dynBal.T_start) * (1.0 - vol.dynBal.X_start[1]) + (2501014.5 + 1860.0 * (-273.15 + vol.dynBal.T_start)) * vol.dynBal.X_start[1]
 */
void Room_eqFunction_207(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,207};
  data->simulationInfo->realParameter[33] = (1006.0) * ((-273.15 + data->simulationInfo->realParameter[28]) * (1.0 - data->simulationInfo->realParameter[29])) + (2501014.5 + (1860.0) * (-273.15 + data->simulationInfo->realParameter[28])) * (data->simulationInfo->realParameter[29]);
  TRACE_POP
}

/*
 equation index: 208
 type: SIMPLE_ASSIGN
 vol._dynBal._s[1] = 1.0
 */
void Room_eqFunction_208(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,208};
  data->simulationInfo->realParameter[38] = 1.0;
  TRACE_POP
}

/*
 equation index: 209
 type: SIMPLE_ASSIGN
 vol._dynBal._rho_default = 1.2
 */
void Room_eqFunction_209(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,209};
  data->simulationInfo->realParameter[36] = 1.2;
  TRACE_POP
}

/*
 equation index: 210
 type: SIMPLE_ASSIGN
 vol._dynBal._state_default._X[2] = 0.99
 */
void Room_eqFunction_210(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,210};
  data->simulationInfo->realParameter[41] = 0.99;
  TRACE_POP
}

/*
 equation index: 211
 type: SIMPLE_ASSIGN
 vol._dynBal._state_default._X[1] = 0.01
 */
void Room_eqFunction_211(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,211};
  data->simulationInfo->realParameter[40] = 0.01;
  TRACE_POP
}

/*
 equation index: 212
 type: SIMPLE_ASSIGN
 vol._dynBal._state_default._T = 293.15
 */
void Room_eqFunction_212(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,212};
  data->simulationInfo->realParameter[39] = 293.15;
  TRACE_POP
}

/*
 equation index: 213
 type: SIMPLE_ASSIGN
 vol._dynBal._state_default._p = 101325.0
 */
void Room_eqFunction_213(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,213};
  data->simulationInfo->realParameter[42] = 101325.0;
  TRACE_POP
}

/*
 equation index: 214
 type: SIMPLE_ASSIGN
 vol._dynBal._computeCSen = false
 */
void Room_eqFunction_214(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,214};
  data->simulationInfo->booleanParameter[4] = 0;
  TRACE_POP
}

/*
 equation index: 215
 type: SIMPLE_ASSIGN
 vol._dynBal._p_start = vol.p_start
 */
void Room_eqFunction_215(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,215};
  data->simulationInfo->realParameter[35] = data->simulationInfo->realParameter[46];
  TRACE_POP
}

/*
 equation index: 216
 type: SIMPLE_ASSIGN
 vol._dynBal._rho_start = 1.184307920059215e-05 * vol.dynBal.p_start
 */
void Room_eqFunction_216(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,216};
  data->simulationInfo->realParameter[37] = (1.184307920059215e-05) * (data->simulationInfo->realParameter[35]);
  TRACE_POP
}

/*
 equation index: 217
 type: SIMPLE_ASSIGN
 vol._dynBal._cp_default = 1014.54
 */
void Room_eqFunction_217(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,217};
  data->simulationInfo->realParameter[31] = 1014.54;
  TRACE_POP
}

/*
 equation index: 218
 type: SIMPLE_ASSIGN
 vol._dynBal._CSen = 0.0
 */
void Room_eqFunction_218(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,218};
  data->simulationInfo->realParameter[27] = 0.0;
  TRACE_POP
}

/*
 equation index: 219
 type: SIMPLE_ASSIGN
 vol._dynBal._fluidVolume = 180.0
 */
void Room_eqFunction_219(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,219};
  data->simulationInfo->realParameter[32] = 180.0;
  TRACE_POP
}

/*
 equation index: 220
 type: SIMPLE_ASSIGN
 vol._dynBal._medium._standardOrderComponents = true
 */
void Room_eqFunction_220(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,220};
  data->simulationInfo->booleanParameter[6] = 1;
  TRACE_POP
}

/*
 equation index: 221
 type: SIMPLE_ASSIGN
 vol._dynBal._medium._preferredMediumStates = false
 */
void Room_eqFunction_221(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,221};
  data->simulationInfo->booleanParameter[5] = 0;
  TRACE_POP
}

/*
 equation index: 222
 type: SIMPLE_ASSIGN
 vol._dynBal._use_C_flow = false
 */
void Room_eqFunction_222(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,222};
  data->simulationInfo->booleanParameter[7] = 0;
  TRACE_POP
}

/*
 equation index: 223
 type: SIMPLE_ASSIGN
 vol._dynBal._use_mWat_flow = false
 */
void Room_eqFunction_223(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,223};
  data->simulationInfo->booleanParameter[8] = 0;
  TRACE_POP
}

/*
 equation index: 224
 type: SIMPLE_ASSIGN
 vol._dynBal._nPorts = 0
 */
void Room_eqFunction_224(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,224};
  data->simulationInfo->integerParameter[2] = ((modelica_integer) 0);
  TRACE_POP
}

/*
 equation index: 225
 type: SIMPLE_ASSIGN
 vol._dynBal._mSenFac = 1.0
 */
void Room_eqFunction_225(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,225};
  data->simulationInfo->realParameter[34] = 1.0;
  TRACE_POP
}

/*
 equation index: 226
 type: SIMPLE_ASSIGN
 vol._dynBal._X_start[2] = vol.X_start[2]
 */
void Room_eqFunction_226(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,226};
  data->simulationInfo->realParameter[30] = data->simulationInfo->realParameter[26];
  TRACE_POP
}

/*
 equation index: 227
 type: SIMPLE_ASSIGN
 vol._dynBal._traceDynamics = Modelica.Fluid.Types.Dynamics.FixedInitial
 */
void Room_eqFunction_227(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,227};
  data->simulationInfo->integerParameter[4] = 2;
  TRACE_POP
}

/*
 equation index: 228
 type: SIMPLE_ASSIGN
 vol._dynBal._substanceDynamics = Modelica.Fluid.Types.Dynamics.FixedInitial
 */
void Room_eqFunction_228(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,228};
  data->simulationInfo->integerParameter[3] = 2;
  TRACE_POP
}

/*
 equation index: 229
 type: SIMPLE_ASSIGN
 vol._dynBal._massDynamics = Modelica.Fluid.Types.Dynamics.FixedInitial
 */
void Room_eqFunction_229(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,229};
  data->simulationInfo->integerParameter[1] = 2;
  TRACE_POP
}

/*
 equation index: 230
 type: SIMPLE_ASSIGN
 vol._dynBal._energyDynamics = Modelica.Fluid.Types.Dynamics.FixedInitial
 */
void Room_eqFunction_230(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,230};
  data->simulationInfo->integerParameter[0] = 2;
  TRACE_POP
}

/*
 equation index: 231
 type: SIMPLE_ASSIGN
 vol._useSteadyStateTwoPort = false
 */
void Room_eqFunction_231(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,231};
  data->simulationInfo->booleanParameter[9] = 0;
  TRACE_POP
}

/*
 equation index: 232
 type: SIMPLE_ASSIGN
 vol._state_start._X[2] = 0.99
 */
void Room_eqFunction_232(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,232};
  data->simulationInfo->realParameter[55] = 0.99;
  TRACE_POP
}

/*
 equation index: 233
 type: SIMPLE_ASSIGN
 vol._state_start._X[1] = 0.01
 */
void Room_eqFunction_233(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,233};
  data->simulationInfo->realParameter[54] = 0.01;
  TRACE_POP
}

/*
 equation index: 234
 type: SIMPLE_ASSIGN
 vol._state_start._T = 293.15
 */
void Room_eqFunction_234(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,234};
  data->simulationInfo->realParameter[53] = 293.15;
  TRACE_POP
}

/*
 equation index: 235
 type: SIMPLE_ASSIGN
 vol._state_start._p = 101325.0
 */
void Room_eqFunction_235(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,235};
  data->simulationInfo->realParameter[56] = 101325.0;
  TRACE_POP
}

/*
 equation index: 236
 type: SIMPLE_ASSIGN
 vol._rho_default = 1.2
 */
void Room_eqFunction_236(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,236};
  data->simulationInfo->realParameter[47] = 1.2;
  TRACE_POP
}

/*
 equation index: 237
 type: SIMPLE_ASSIGN
 vol._state_default._X[2] = 0.99
 */
void Room_eqFunction_237(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,237};
  data->simulationInfo->realParameter[51] = 0.99;
  TRACE_POP
}

/*
 equation index: 238
 type: SIMPLE_ASSIGN
 vol._state_default._X[1] = 0.01
 */
void Room_eqFunction_238(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,238};
  data->simulationInfo->realParameter[50] = 0.01;
  TRACE_POP
}

/*
 equation index: 239
 type: SIMPLE_ASSIGN
 vol._state_default._T = 293.15
 */
void Room_eqFunction_239(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,239};
  data->simulationInfo->realParameter[49] = 293.15;
  TRACE_POP
}

/*
 equation index: 240
 type: SIMPLE_ASSIGN
 vol._state_default._p = 101325.0
 */
void Room_eqFunction_240(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,240};
  data->simulationInfo->realParameter[52] = 101325.0;
  TRACE_POP
}

/*
 equation index: 241
 type: SIMPLE_ASSIGN
 vol._rho_start = 1.2
 */
void Room_eqFunction_241(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,241};
  data->simulationInfo->realParameter[48] = 1.2;
  TRACE_POP
}

/*
 equation index: 242
 type: SIMPLE_ASSIGN
 vol._V = 180.0
 */
void Room_eqFunction_242(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,242};
  data->simulationInfo->realParameter[24] = 180.0;
  TRACE_POP
}

/*
 equation index: 243
 type: SIMPLE_ASSIGN
 vol._allowFlowReversal = true
 */
void Room_eqFunction_243(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,243};
  data->simulationInfo->booleanParameter[3] = 1;
  TRACE_POP
}

/*
 equation index: 244
 type: SIMPLE_ASSIGN
 vol._m_flow_small = 3.000000000000001e-05
 */
void Room_eqFunction_244(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,244};
  data->simulationInfo->realParameter[45] = 3.000000000000001e-05;
  TRACE_POP
}

/*
 equation index: 245
 type: SIMPLE_ASSIGN
 vol._nPorts = 0
 */
void Room_eqFunction_245(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,245};
  data->simulationInfo->integerParameter[7] = ((modelica_integer) 0);
  TRACE_POP
}

/*
 equation index: 246
 type: SIMPLE_ASSIGN
 vol._m_flow_nominal = 0.3
 */
void Room_eqFunction_246(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,246};
  data->simulationInfo->realParameter[44] = 0.3;
  TRACE_POP
}

/*
 equation index: 247
 type: SIMPLE_ASSIGN
 vol._use_C_flow = false
 */
void Room_eqFunction_247(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,247};
  data->simulationInfo->booleanParameter[10] = 0;
  TRACE_POP
}

/*
 equation index: 248
 type: SIMPLE_ASSIGN
 vol._mSenFac = 1.0
 */
void Room_eqFunction_248(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,248};
  data->simulationInfo->realParameter[43] = 1.0;
  TRACE_POP
}

/*
 equation index: 249
 type: SIMPLE_ASSIGN
 vol._traceDynamics = Modelica.Fluid.Types.Dynamics.FixedInitial
 */
void Room_eqFunction_249(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,249};
  data->simulationInfo->integerParameter[9] = 2;
  TRACE_POP
}

/*
 equation index: 250
 type: SIMPLE_ASSIGN
 vol._substanceDynamics = Modelica.Fluid.Types.Dynamics.FixedInitial
 */
void Room_eqFunction_250(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,250};
  data->simulationInfo->integerParameter[8] = 2;
  TRACE_POP
}

/*
 equation index: 251
 type: SIMPLE_ASSIGN
 vol._massDynamics = Modelica.Fluid.Types.Dynamics.FixedInitial
 */
void Room_eqFunction_251(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,251};
  data->simulationInfo->integerParameter[6] = 2;
  TRACE_POP
}

/*
 equation index: 252
 type: SIMPLE_ASSIGN
 vol._energyDynamics = Modelica.Fluid.Types.Dynamics.FixedInitial
 */
void Room_eqFunction_252(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,252};
  data->simulationInfo->integerParameter[5] = 2;
  TRACE_POP
}

/*
 equation index: 253
 type: SIMPLE_ASSIGN
 vol._dynBal._Hb_flow = 0.0
 */
void Room_eqFunction_253(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,253};
  data->localData[0]->realVars[26] /* vol._dynBal._Hb_flow variable */ = 0.0;
  TRACE_POP
}

/*
 equation index: 254
 type: SIMPLE_ASSIGN
 vol._dynBal._mb_flow = 0.0
 */
void Room_eqFunction_254(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,254};
  data->localData[0]->realVars[31] /* vol._dynBal._mb_flow variable */ = 0.0;
  TRACE_POP
}

/*
 equation index: 255
 type: SIMPLE_ASSIGN
 vol._dynBal._mbXi_flow[1] = 0.0
 */
void Room_eqFunction_255(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,255};
  data->localData[0]->realVars[30] /* vol._dynBal._mbXi_flow[1] variable */ = 0.0;
  TRACE_POP
}

/*
 equation index: 256
 type: SIMPLE_ASSIGN
 vol._dynBal._mWat_flow_internal = 0.0
 */
void Room_eqFunction_256(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,256};
  data->localData[0]->realVars[28] /* vol._dynBal._mWat_flow_internal variable */ = 0.0;
  TRACE_POP
}

/*
 equation index: 257
 type: SIMPLE_ASSIGN
 HeatingControlPortTransformer1._HeatingControlPort1._set_hysteresis_intervallum1._counter = 1
 */
void Room_eqFunction_257(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,257};
  data->localData[0]->integerVars[0] /* HeatingControlPortTransformer1._HeatingControlPort1._set_hysteresis_intervallum1._counter DISCRETE */ = ((modelica_integer) 1);
  TRACE_POP
}

/*
 equation index: 258
 type: SIMPLE_ASSIGN
 temperatureStreamPortTransformer1._TemperatureStreamPort1._measured_temperature1._counter = 1
 */
void Room_eqFunction_258(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,258};
  data->localData[0]->integerVars[5] /* temperatureStreamPortTransformer1._TemperatureStreamPort1._measured_temperature1._counter DISCRETE */ = ((modelica_integer) 1);
  TRACE_POP
}

/*
 equation index: 259
 type: SIMPLE_ASSIGN
 thermostatControlPortTransformer1._ThermostatControlPort1._set_target_temperature1._counter = 1
 */
void Room_eqFunction_259(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,259};
  data->localData[0]->integerVars[9] /* thermostatControlPortTransformer1._ThermostatControlPort1._set_target_temperature1._counter DISCRETE */ = ((modelica_integer) 1);
  TRACE_POP
}

/*
 equation index: 260
 type: ALGORITHM
 
   assert(sampleTrigger1.period >= 1e-60, "Variable violating min constraint: 1e-60 <= sampleTrigger1.period, has value: " + String(sampleTrigger1.period, "g"));
 */
void Room_eqFunction_260(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,260};
  modelica_boolean tmp0;
  static const MMC_DEFSTRINGLIT(tmp1,78,"Variable violating min constraint: 1e-60 <= sampleTrigger1.period, has value: ");
  modelica_string tmp2;
  static int tmp3 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp3)
  {
    tmp0 = GreaterEq(data->simulationInfo->realParameter[11],1e-60);
    if(!tmp0)
    {
      tmp2 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[11], (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp1),tmp2);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.2/Blocks/Sources.mo",2932,5,2933,36,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nsampleTrigger1.period >= 1e-60", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp3 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 261
 type: ALGORITHM
 
   assert(sampleTrigger2.period >= 1e-60, "Variable violating min constraint: 1e-60 <= sampleTrigger2.period, has value: " + String(sampleTrigger2.period, "g"));
 */
void Room_eqFunction_261(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,261};
  modelica_boolean tmp4;
  static const MMC_DEFSTRINGLIT(tmp5,78,"Variable violating min constraint: 1e-60 <= sampleTrigger2.period, has value: ");
  modelica_string tmp6;
  static int tmp7 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp7)
  {
    tmp4 = GreaterEq(data->simulationInfo->realParameter[13],1e-60);
    if(!tmp4)
    {
      tmp6 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[13], (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp5),tmp6);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.2/Blocks/Sources.mo",2932,5,2933,36,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nsampleTrigger2.period >= 1e-60", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp7 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 262
 type: ALGORITHM
 
   assert(set_hysteresis_intervallum_tester1.sampleTrigger1.period >= 1e-60, "Variable violating min constraint: 1e-60 <= set_hysteresis_intervallum_tester1.sampleTrigger1.period, has value: " + String(set_hysteresis_intervallum_tester1.sampleTrigger1.period, "g"));
 */
void Room_eqFunction_262(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,262};
  modelica_boolean tmp8;
  static const MMC_DEFSTRINGLIT(tmp9,113,"Variable violating min constraint: 1e-60 <= set_hysteresis_intervallum_tester1.sampleTrigger1.period, has value: ");
  modelica_string tmp10;
  static int tmp11 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp11)
  {
    tmp8 = GreaterEq(data->simulationInfo->realParameter[15],1e-60);
    if(!tmp8)
    {
      tmp10 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[15], (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp9),tmp10);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.2/Blocks/Sources.mo",2932,5,2933,36,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nset_hysteresis_intervallum_tester1.sampleTrigger1.period >= 1e-60", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp11 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 263
 type: ALGORITHM
 
   assert(preHea.T_ref >= 0.0, "Variable violating min constraint: 0.0 <= preHea.T_ref, has value: " + String(preHea.T_ref, "g"));
 */
void Room_eqFunction_263(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,263};
  modelica_boolean tmp12;
  static const MMC_DEFSTRINGLIT(tmp13,67,"Variable violating min constraint: 0.0 <= preHea.T_ref, has value: ");
  modelica_string tmp14;
  static int tmp15 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp15)
  {
    tmp12 = GreaterEq(data->simulationInfo->realParameter[9],0.0);
    if(!tmp12)
    {
      tmp14 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[9], (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp13),tmp14);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.2/Thermal/HeatTransfer.mo",1577,7,1578,32,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\npreHea.T_ref >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp15 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 264
 type: ALGORITHM
 
   assert(TOut.T >= 0.0, "Variable violating min constraint: 0.0 <= TOut.T, has value: " + String(TOut.T, "g"));
 */
void Room_eqFunction_264(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,264};
  modelica_boolean tmp16;
  static const MMC_DEFSTRINGLIT(tmp17,61,"Variable violating min constraint: 0.0 <= TOut.T, has value: ");
  modelica_string tmp18;
  static int tmp19 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp19)
  {
    tmp16 = GreaterEq(data->simulationInfo->realParameter[2],0.0);
    if(!tmp16)
    {
      tmp18 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[2], (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp17),tmp18);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.2/Thermal/HeatTransfer.mo",1363,7,1363,75,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nTOut.T >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp19 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 265
 type: ALGORITHM
 
   assert(vol.T_start >= 1.0 and vol.T_start <= 10000.0, "Variable violating min/max constraint: 1.0 <= vol.T_start <= 10000.0, has value: " + String(vol.T_start, "g"));
 */
void Room_eqFunction_265(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,265};
  modelica_boolean tmp20;
  modelica_boolean tmp21;
  static const MMC_DEFSTRINGLIT(tmp22,81,"Variable violating min/max constraint: 1.0 <= vol.T_start <= 10000.0, has value: ");
  modelica_string tmp23;
  static int tmp24 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp24)
  {
    tmp20 = GreaterEq(data->simulationInfo->realParameter[23],1.0);
    tmp21 = LessEq(data->simulationInfo->realParameter[23],10000.0);
    if(!(tmp20 && tmp21))
    {
      tmp23 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[23], (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp22),tmp23);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Buildings latest/Fluid/Interfaces/LumpedVolumeDeclarations.mo",25,3,27,47,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nvol.T_start >= 1.0 and vol.T_start <= 10000.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp24 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 266
 type: ALGORITHM
 
   assert(vol.dynBal.T_start >= 1.0 and vol.dynBal.T_start <= 10000.0, "Variable violating min/max constraint: 1.0 <= vol.dynBal.T_start <= 10000.0, has value: " + String(vol.dynBal.T_start, "g"));
 */
void Room_eqFunction_266(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,266};
  modelica_boolean tmp25;
  modelica_boolean tmp26;
  static const MMC_DEFSTRINGLIT(tmp27,88,"Variable violating min/max constraint: 1.0 <= vol.dynBal.T_start <= 10000.0, has value: ");
  modelica_string tmp28;
  static int tmp29 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp29)
  {
    tmp25 = GreaterEq(data->simulationInfo->realParameter[28],1.0);
    tmp26 = LessEq(data->simulationInfo->realParameter[28],10000.0);
    if(!(tmp25 && tmp26))
    {
      tmp28 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[28], (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp27),tmp28);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Buildings latest/Fluid/Interfaces/LumpedVolumeDeclarations.mo",25,3,27,47,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nvol.dynBal.T_start >= 1.0 and vol.dynBal.T_start <= 10000.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp29 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 267
 type: ALGORITHM
 
   assert(vol.X_start[1] >= 0.0 and vol.X_start[1] <= 1.0, "Variable violating min/max constraint: 0.0 <= vol.X_start[1] <= 1.0, has value: " + String(vol.X_start[1], "g"));
 */
void Room_eqFunction_267(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,267};
  modelica_boolean tmp30;
  modelica_boolean tmp31;
  static const MMC_DEFSTRINGLIT(tmp32,80,"Variable violating min/max constraint: 0.0 <= vol.X_start[1] <= 1.0, has value: ");
  modelica_string tmp33;
  static int tmp34 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp34)
  {
    tmp30 = GreaterEq(data->simulationInfo->realParameter[25],0.0);
    tmp31 = LessEq(data->simulationInfo->realParameter[25],1.0);
    if(!(tmp30 && tmp31))
    {
      tmp33 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[25], (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp32),tmp33);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Buildings latest/Fluid/Interfaces/LumpedVolumeDeclarations.mo",28,3,31,69,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nvol.X_start[1] >= 0.0 and vol.X_start[1] <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp34 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 268
 type: ALGORITHM
 
   assert(vol.dynBal.X_start[1] >= 0.0 and vol.dynBal.X_start[1] <= 1.0, "Variable violating min/max constraint: 0.0 <= vol.dynBal.X_start[1] <= 1.0, has value: " + String(vol.dynBal.X_start[1], "g"));
 */
void Room_eqFunction_268(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,268};
  modelica_boolean tmp35;
  modelica_boolean tmp36;
  static const MMC_DEFSTRINGLIT(tmp37,87,"Variable violating min/max constraint: 0.0 <= vol.dynBal.X_start[1] <= 1.0, has value: ");
  modelica_string tmp38;
  static int tmp39 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp39)
  {
    tmp35 = GreaterEq(data->simulationInfo->realParameter[29],0.0);
    tmp36 = LessEq(data->simulationInfo->realParameter[29],1.0);
    if(!(tmp35 && tmp36))
    {
      tmp38 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[29], (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp37),tmp38);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Buildings latest/Fluid/Interfaces/LumpedVolumeDeclarations.mo",28,3,31,69,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nvol.dynBal.X_start[1] >= 0.0 and vol.dynBal.X_start[1] <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp39 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 269
 type: ALGORITHM
 
   assert(vol.dynBal.rho_default >= 0.0, "Variable violating min constraint: 0.0 <= vol.dynBal.rho_default, has value: " + String(vol.dynBal.rho_default, "g"));
 */
void Room_eqFunction_269(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,269};
  modelica_boolean tmp40;
  static const MMC_DEFSTRINGLIT(tmp41,77,"Variable violating min constraint: 0.0 <= vol.dynBal.rho_default, has value: ");
  modelica_string tmp42;
  static int tmp43 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp43)
  {
    tmp40 = GreaterEq(data->simulationInfo->realParameter[36],0.0);
    if(!tmp40)
    {
      tmp42 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[36], (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp41),tmp42);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Buildings latest/Fluid/Interfaces/ConservationEquation.mo",145,3,146,63,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nvol.dynBal.rho_default >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp43 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 270
 type: ALGORITHM
 
   assert(vol.dynBal.state_default.X[2] >= 0.0 and vol.dynBal.state_default.X[2] <= 1.0, "Variable violating min/max constraint: 0.0 <= vol.dynBal.state_default.X[2] <= 1.0, has value: " + String(vol.dynBal.state_default.X[2], "g"));
 */
void Room_eqFunction_270(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,270};
  modelica_boolean tmp44;
  modelica_boolean tmp45;
  static const MMC_DEFSTRINGLIT(tmp46,95,"Variable violating min/max constraint: 0.0 <= vol.dynBal.state_default.X[2] <= 1.0, has value: ");
  modelica_string tmp47;
  static int tmp48 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp48)
  {
    tmp44 = GreaterEq(data->simulationInfo->realParameter[41],0.0);
    tmp45 = LessEq(data->simulationInfo->realParameter[41],1.0);
    if(!(tmp44 && tmp45))
    {
      tmp47 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[41], (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp46),tmp47);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.2/Media/package.mo",5597,7,5598,64,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nvol.dynBal.state_default.X[2] >= 0.0 and vol.dynBal.state_default.X[2] <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp48 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 271
 type: ALGORITHM
 
   assert(vol.dynBal.state_default.X[1] >= 0.0 and vol.dynBal.state_default.X[1] <= 1.0, "Variable violating min/max constraint: 0.0 <= vol.dynBal.state_default.X[1] <= 1.0, has value: " + String(vol.dynBal.state_default.X[1], "g"));
 */
void Room_eqFunction_271(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,271};
  modelica_boolean tmp49;
  modelica_boolean tmp50;
  static const MMC_DEFSTRINGLIT(tmp51,95,"Variable violating min/max constraint: 0.0 <= vol.dynBal.state_default.X[1] <= 1.0, has value: ");
  modelica_string tmp52;
  static int tmp53 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp53)
  {
    tmp49 = GreaterEq(data->simulationInfo->realParameter[40],0.0);
    tmp50 = LessEq(data->simulationInfo->realParameter[40],1.0);
    if(!(tmp49 && tmp50))
    {
      tmp52 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[40], (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp51),tmp52);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.2/Media/package.mo",5597,7,5598,64,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nvol.dynBal.state_default.X[1] >= 0.0 and vol.dynBal.state_default.X[1] <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp53 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 272
 type: ALGORITHM
 
   assert(vol.dynBal.state_default.T >= 1.0 and vol.dynBal.state_default.T <= 10000.0, "Variable violating min/max constraint: 1.0 <= vol.dynBal.state_default.T <= 10000.0, has value: " + String(vol.dynBal.state_default.T, "g"));
 */
void Room_eqFunction_272(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,272};
  modelica_boolean tmp54;
  modelica_boolean tmp55;
  static const MMC_DEFSTRINGLIT(tmp56,96,"Variable violating min/max constraint: 1.0 <= vol.dynBal.state_default.T <= 10000.0, has value: ");
  modelica_string tmp57;
  static int tmp58 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp58)
  {
    tmp54 = GreaterEq(data->simulationInfo->realParameter[39],1.0);
    tmp55 = LessEq(data->simulationInfo->realParameter[39],10000.0);
    if(!(tmp54 && tmp55))
    {
      tmp57 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[39], (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp56),tmp57);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.2/Media/package.mo",5596,7,5596,44,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nvol.dynBal.state_default.T >= 1.0 and vol.dynBal.state_default.T <= 10000.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp58 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 273
 type: ALGORITHM
 
   assert(vol.dynBal.state_default.p >= 0.0 and vol.dynBal.state_default.p <= 100000000.0, "Variable violating min/max constraint: 0.0 <= vol.dynBal.state_default.p <= 100000000.0, has value: " + String(vol.dynBal.state_default.p, "g"));
 */
void Room_eqFunction_273(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,273};
  modelica_boolean tmp59;
  modelica_boolean tmp60;
  static const MMC_DEFSTRINGLIT(tmp61,100,"Variable violating min/max constraint: 0.0 <= vol.dynBal.state_default.p <= 100000000.0, has value: ");
  modelica_string tmp62;
  static int tmp63 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp63)
  {
    tmp59 = GreaterEq(data->simulationInfo->realParameter[42],0.0);
    tmp60 = LessEq(data->simulationInfo->realParameter[42],100000000.0);
    if(!(tmp59 && tmp60))
    {
      tmp62 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[42], (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp61),tmp62);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.2/Media/package.mo",5595,7,5595,55,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nvol.dynBal.state_default.p >= 0.0 and vol.dynBal.state_default.p <= 100000000.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp63 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 274
 type: ALGORITHM
 
   assert(vol.p_start >= 0.0 and vol.p_start <= 100000000.0, "Variable violating min/max constraint: 0.0 <= vol.p_start <= 100000000.0, has value: " + String(vol.p_start, "g"));
 */
void Room_eqFunction_274(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,274};
  modelica_boolean tmp64;
  modelica_boolean tmp65;
  static const MMC_DEFSTRINGLIT(tmp66,85,"Variable violating min/max constraint: 0.0 <= vol.p_start <= 100000000.0, has value: ");
  modelica_string tmp67;
  static int tmp68 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp68)
  {
    tmp64 = GreaterEq(data->simulationInfo->realParameter[46],0.0);
    tmp65 = LessEq(data->simulationInfo->realParameter[46],100000000.0);
    if(!(tmp64 && tmp65))
    {
      tmp67 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[46], (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp66),tmp67);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Buildings latest/Fluid/Interfaces/LumpedVolumeDeclarations.mo",22,3,24,47,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nvol.p_start >= 0.0 and vol.p_start <= 100000000.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp68 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 275
 type: ALGORITHM
 
   assert(vol.dynBal.p_start >= 0.0 and vol.dynBal.p_start <= 100000000.0, "Variable violating min/max constraint: 0.0 <= vol.dynBal.p_start <= 100000000.0, has value: " + String(vol.dynBal.p_start, "g"));
 */
void Room_eqFunction_275(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,275};
  modelica_boolean tmp69;
  modelica_boolean tmp70;
  static const MMC_DEFSTRINGLIT(tmp71,92,"Variable violating min/max constraint: 0.0 <= vol.dynBal.p_start <= 100000000.0, has value: ");
  modelica_string tmp72;
  static int tmp73 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp73)
  {
    tmp69 = GreaterEq(data->simulationInfo->realParameter[35],0.0);
    tmp70 = LessEq(data->simulationInfo->realParameter[35],100000000.0);
    if(!(tmp69 && tmp70))
    {
      tmp72 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[35], (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp71),tmp72);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Buildings latest/Fluid/Interfaces/LumpedVolumeDeclarations.mo",22,3,24,47,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nvol.dynBal.p_start >= 0.0 and vol.dynBal.p_start <= 100000000.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp73 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 276
 type: ALGORITHM
 
   assert(vol.dynBal.rho_start >= 0.0, "Variable violating min constraint: 0.0 <= vol.dynBal.rho_start, has value: " + String(vol.dynBal.rho_start, "g"));
 */
void Room_eqFunction_276(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,276};
  modelica_boolean tmp74;
  static const MMC_DEFSTRINGLIT(tmp75,75,"Variable violating min constraint: 0.0 <= vol.dynBal.rho_start, has value: ");
  modelica_string tmp76;
  static int tmp77 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp77)
  {
    tmp74 = GreaterEq(data->simulationInfo->realParameter[37],0.0);
    if(!tmp74)
    {
      tmp76 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[37], (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp75),tmp76);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Buildings latest/Fluid/Interfaces/ConservationEquation.mo",131,3,135,69,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nvol.dynBal.rho_start >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp77 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 277
 type: ALGORITHM
 
   assert(vol.dynBal.mSenFac >= 1.0, "Variable violating min constraint: 1.0 <= vol.dynBal.mSenFac, has value: " + String(vol.dynBal.mSenFac, "g"));
 */
void Room_eqFunction_277(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,277};
  modelica_boolean tmp78;
  static const MMC_DEFSTRINGLIT(tmp79,73,"Variable violating min constraint: 1.0 <= vol.dynBal.mSenFac, has value: ");
  modelica_string tmp80;
  static int tmp81 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp81)
  {
    tmp78 = GreaterEq(data->simulationInfo->realParameter[34],1.0);
    if(!tmp78)
    {
      tmp80 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[34], (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp79),tmp80);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Buildings latest/Fluid/Interfaces/LumpedVolumeDeclarations.mo",40,3,42,39,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nvol.dynBal.mSenFac >= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp81 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 278
 type: ALGORITHM
 
   assert(vol.X_start[2] >= 0.0 and vol.X_start[2] <= 1.0, "Variable violating min/max constraint: 0.0 <= vol.X_start[2] <= 1.0, has value: " + String(vol.X_start[2], "g"));
 */
void Room_eqFunction_278(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,278};
  modelica_boolean tmp82;
  modelica_boolean tmp83;
  static const MMC_DEFSTRINGLIT(tmp84,80,"Variable violating min/max constraint: 0.0 <= vol.X_start[2] <= 1.0, has value: ");
  modelica_string tmp85;
  static int tmp86 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp86)
  {
    tmp82 = GreaterEq(data->simulationInfo->realParameter[26],0.0);
    tmp83 = LessEq(data->simulationInfo->realParameter[26],1.0);
    if(!(tmp82 && tmp83))
    {
      tmp85 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[26], (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp84),tmp85);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Buildings latest/Fluid/Interfaces/LumpedVolumeDeclarations.mo",28,3,31,69,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nvol.X_start[2] >= 0.0 and vol.X_start[2] <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp86 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 279
 type: ALGORITHM
 
   assert(vol.dynBal.X_start[2] >= 0.0 and vol.dynBal.X_start[2] <= 1.0, "Variable violating min/max constraint: 0.0 <= vol.dynBal.X_start[2] <= 1.0, has value: " + String(vol.dynBal.X_start[2], "g"));
 */
void Room_eqFunction_279(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,279};
  modelica_boolean tmp87;
  modelica_boolean tmp88;
  static const MMC_DEFSTRINGLIT(tmp89,87,"Variable violating min/max constraint: 0.0 <= vol.dynBal.X_start[2] <= 1.0, has value: ");
  modelica_string tmp90;
  static int tmp91 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp91)
  {
    tmp87 = GreaterEq(data->simulationInfo->realParameter[30],0.0);
    tmp88 = LessEq(data->simulationInfo->realParameter[30],1.0);
    if(!(tmp87 && tmp88))
    {
      tmp90 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[30], (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp89),tmp90);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Buildings latest/Fluid/Interfaces/LumpedVolumeDeclarations.mo",28,3,31,69,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nvol.dynBal.X_start[2] >= 0.0 and vol.dynBal.X_start[2] <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp91 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 280
 type: ALGORITHM
 
   assert(vol.dynBal.traceDynamics >= Modelica.Fluid.Types.Dynamics.DynamicFreeInitial and vol.dynBal.traceDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState, "Variable violating min/max constraint: Modelica.Fluid.Types.Dynamics.DynamicFreeInitial <= vol.dynBal.traceDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState, has value: " + String(vol.dynBal.traceDynamics, "d"));
 */
void Room_eqFunction_280(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,280};
  modelica_boolean tmp92;
  modelica_boolean tmp93;
  static const MMC_DEFSTRINGLIT(tmp94,173,"Variable violating min/max constraint: Modelica.Fluid.Types.Dynamics.DynamicFreeInitial <= vol.dynBal.traceDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState, has value: ");
  modelica_string tmp95;
  static int tmp96 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp96)
  {
    tmp92 = GreaterEq((modelica_integer)data->simulationInfo->integerParameter[4],1);
    tmp93 = LessEq((modelica_integer)data->simulationInfo->integerParameter[4],4);
    if(!(tmp92 && tmp93))
    {
      tmp95 = modelica_integer_to_modelica_string_format((modelica_integer)data->simulationInfo->integerParameter[4], (modelica_string) mmc_strings_len1[100]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp94),tmp95);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Buildings latest/Fluid/Interfaces/LumpedVolumeDeclarations.mo",17,3,19,75,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nvol.dynBal.traceDynamics >= Modelica.Fluid.Types.Dynamics.DynamicFreeInitial and vol.dynBal.traceDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp96 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 281
 type: ALGORITHM
 
   assert(vol.dynBal.substanceDynamics >= Modelica.Fluid.Types.Dynamics.DynamicFreeInitial and vol.dynBal.substanceDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState, "Variable violating min/max constraint: Modelica.Fluid.Types.Dynamics.DynamicFreeInitial <= vol.dynBal.substanceDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState, has value: " + String(vol.dynBal.substanceDynamics, "d"));
 */
void Room_eqFunction_281(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,281};
  modelica_boolean tmp97;
  modelica_boolean tmp98;
  static const MMC_DEFSTRINGLIT(tmp99,177,"Variable violating min/max constraint: Modelica.Fluid.Types.Dynamics.DynamicFreeInitial <= vol.dynBal.substanceDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState, has value: ");
  modelica_string tmp100;
  static int tmp101 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp101)
  {
    tmp97 = GreaterEq((modelica_integer)data->simulationInfo->integerParameter[3],1);
    tmp98 = LessEq((modelica_integer)data->simulationInfo->integerParameter[3],4);
    if(!(tmp97 && tmp98))
    {
      tmp100 = modelica_integer_to_modelica_string_format((modelica_integer)data->simulationInfo->integerParameter[3], (modelica_string) mmc_strings_len1[100]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp99),tmp100);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Buildings latest/Fluid/Interfaces/LumpedVolumeDeclarations.mo",14,3,16,75,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nvol.dynBal.substanceDynamics >= Modelica.Fluid.Types.Dynamics.DynamicFreeInitial and vol.dynBal.substanceDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp101 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 282
 type: ALGORITHM
 
   assert(vol.dynBal.massDynamics >= Modelica.Fluid.Types.Dynamics.DynamicFreeInitial and vol.dynBal.massDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState, "Variable violating min/max constraint: Modelica.Fluid.Types.Dynamics.DynamicFreeInitial <= vol.dynBal.massDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState, has value: " + String(vol.dynBal.massDynamics, "d"));
 */
void Room_eqFunction_282(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,282};
  modelica_boolean tmp102;
  modelica_boolean tmp103;
  static const MMC_DEFSTRINGLIT(tmp104,172,"Variable violating min/max constraint: Modelica.Fluid.Types.Dynamics.DynamicFreeInitial <= vol.dynBal.massDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState, has value: ");
  modelica_string tmp105;
  static int tmp106 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp106)
  {
    tmp102 = GreaterEq((modelica_integer)data->simulationInfo->integerParameter[1],1);
    tmp103 = LessEq((modelica_integer)data->simulationInfo->integerParameter[1],4);
    if(!(tmp102 && tmp103))
    {
      tmp105 = modelica_integer_to_modelica_string_format((modelica_integer)data->simulationInfo->integerParameter[1], (modelica_string) mmc_strings_len1[100]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp104),tmp105);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Buildings latest/Fluid/Interfaces/LumpedVolumeDeclarations.mo",11,3,13,75,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nvol.dynBal.massDynamics >= Modelica.Fluid.Types.Dynamics.DynamicFreeInitial and vol.dynBal.massDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp106 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 283
 type: ALGORITHM
 
   assert(vol.dynBal.energyDynamics >= Modelica.Fluid.Types.Dynamics.DynamicFreeInitial and vol.dynBal.energyDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState, "Variable violating min/max constraint: Modelica.Fluid.Types.Dynamics.DynamicFreeInitial <= vol.dynBal.energyDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState, has value: " + String(vol.dynBal.energyDynamics, "d"));
 */
void Room_eqFunction_283(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,283};
  modelica_boolean tmp107;
  modelica_boolean tmp108;
  static const MMC_DEFSTRINGLIT(tmp109,174,"Variable violating min/max constraint: Modelica.Fluid.Types.Dynamics.DynamicFreeInitial <= vol.dynBal.energyDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState, has value: ");
  modelica_string tmp110;
  static int tmp111 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp111)
  {
    tmp107 = GreaterEq((modelica_integer)data->simulationInfo->integerParameter[0],1);
    tmp108 = LessEq((modelica_integer)data->simulationInfo->integerParameter[0],4);
    if(!(tmp107 && tmp108))
    {
      tmp110 = modelica_integer_to_modelica_string_format((modelica_integer)data->simulationInfo->integerParameter[0], (modelica_string) mmc_strings_len1[100]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp109),tmp110);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Buildings latest/Fluid/Interfaces/LumpedVolumeDeclarations.mo",8,3,10,75,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nvol.dynBal.energyDynamics >= Modelica.Fluid.Types.Dynamics.DynamicFreeInitial and vol.dynBal.energyDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp111 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 284
 type: ALGORITHM
 
   assert(vol.state_start.X[2] >= 0.0 and vol.state_start.X[2] <= 1.0, "Variable violating min/max constraint: 0.0 <= vol.state_start.X[2] <= 1.0, has value: " + String(vol.state_start.X[2], "g"));
 */
void Room_eqFunction_284(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,284};
  modelica_boolean tmp112;
  modelica_boolean tmp113;
  static const MMC_DEFSTRINGLIT(tmp114,86,"Variable violating min/max constraint: 0.0 <= vol.state_start.X[2] <= 1.0, has value: ");
  modelica_string tmp115;
  static int tmp116 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp116)
  {
    tmp112 = GreaterEq(data->simulationInfo->realParameter[55],0.0);
    tmp113 = LessEq(data->simulationInfo->realParameter[55],1.0);
    if(!(tmp112 && tmp113))
    {
      tmp115 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[55], (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp114),tmp115);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.2/Media/package.mo",5597,7,5598,64,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nvol.state_start.X[2] >= 0.0 and vol.state_start.X[2] <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp116 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 285
 type: ALGORITHM
 
   assert(vol.state_start.X[1] >= 0.0 and vol.state_start.X[1] <= 1.0, "Variable violating min/max constraint: 0.0 <= vol.state_start.X[1] <= 1.0, has value: " + String(vol.state_start.X[1], "g"));
 */
void Room_eqFunction_285(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,285};
  modelica_boolean tmp117;
  modelica_boolean tmp118;
  static const MMC_DEFSTRINGLIT(tmp119,86,"Variable violating min/max constraint: 0.0 <= vol.state_start.X[1] <= 1.0, has value: ");
  modelica_string tmp120;
  static int tmp121 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp121)
  {
    tmp117 = GreaterEq(data->simulationInfo->realParameter[54],0.0);
    tmp118 = LessEq(data->simulationInfo->realParameter[54],1.0);
    if(!(tmp117 && tmp118))
    {
      tmp120 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[54], (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp119),tmp120);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.2/Media/package.mo",5597,7,5598,64,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nvol.state_start.X[1] >= 0.0 and vol.state_start.X[1] <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp121 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 286
 type: ALGORITHM
 
   assert(vol.state_start.T >= 1.0 and vol.state_start.T <= 10000.0, "Variable violating min/max constraint: 1.0 <= vol.state_start.T <= 10000.0, has value: " + String(vol.state_start.T, "g"));
 */
void Room_eqFunction_286(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,286};
  modelica_boolean tmp122;
  modelica_boolean tmp123;
  static const MMC_DEFSTRINGLIT(tmp124,87,"Variable violating min/max constraint: 1.0 <= vol.state_start.T <= 10000.0, has value: ");
  modelica_string tmp125;
  static int tmp126 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp126)
  {
    tmp122 = GreaterEq(data->simulationInfo->realParameter[53],1.0);
    tmp123 = LessEq(data->simulationInfo->realParameter[53],10000.0);
    if(!(tmp122 && tmp123))
    {
      tmp125 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[53], (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp124),tmp125);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.2/Media/package.mo",5596,7,5596,44,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nvol.state_start.T >= 1.0 and vol.state_start.T <= 10000.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp126 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 287
 type: ALGORITHM
 
   assert(vol.state_start.p >= 0.0 and vol.state_start.p <= 100000000.0, "Variable violating min/max constraint: 0.0 <= vol.state_start.p <= 100000000.0, has value: " + String(vol.state_start.p, "g"));
 */
void Room_eqFunction_287(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,287};
  modelica_boolean tmp127;
  modelica_boolean tmp128;
  static const MMC_DEFSTRINGLIT(tmp129,91,"Variable violating min/max constraint: 0.0 <= vol.state_start.p <= 100000000.0, has value: ");
  modelica_string tmp130;
  static int tmp131 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp131)
  {
    tmp127 = GreaterEq(data->simulationInfo->realParameter[56],0.0);
    tmp128 = LessEq(data->simulationInfo->realParameter[56],100000000.0);
    if(!(tmp127 && tmp128))
    {
      tmp130 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[56], (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp129),tmp130);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.2/Media/package.mo",5595,7,5595,55,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nvol.state_start.p >= 0.0 and vol.state_start.p <= 100000000.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp131 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 288
 type: ALGORITHM
 
   assert(vol.rho_default >= 0.0, "Variable violating min constraint: 0.0 <= vol.rho_default, has value: " + String(vol.rho_default, "g"));
 */
void Room_eqFunction_288(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,288};
  modelica_boolean tmp132;
  static const MMC_DEFSTRINGLIT(tmp133,70,"Variable violating min constraint: 0.0 <= vol.rho_default, has value: ");
  modelica_string tmp134;
  static int tmp135 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp135)
  {
    tmp132 = GreaterEq(data->simulationInfo->realParameter[47],0.0);
    if(!tmp132)
    {
      tmp134 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[47], (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp133),tmp134);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Buildings latest/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo",97,3,98,63,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nvol.rho_default >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp135 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 289
 type: ALGORITHM
 
   assert(vol.state_default.X[2] >= 0.0 and vol.state_default.X[2] <= 1.0, "Variable violating min/max constraint: 0.0 <= vol.state_default.X[2] <= 1.0, has value: " + String(vol.state_default.X[2], "g"));
 */
void Room_eqFunction_289(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,289};
  modelica_boolean tmp136;
  modelica_boolean tmp137;
  static const MMC_DEFSTRINGLIT(tmp138,88,"Variable violating min/max constraint: 0.0 <= vol.state_default.X[2] <= 1.0, has value: ");
  modelica_string tmp139;
  static int tmp140 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp140)
  {
    tmp136 = GreaterEq(data->simulationInfo->realParameter[51],0.0);
    tmp137 = LessEq(data->simulationInfo->realParameter[51],1.0);
    if(!(tmp136 && tmp137))
    {
      tmp139 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[51], (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp138),tmp139);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.2/Media/package.mo",5597,7,5598,64,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nvol.state_default.X[2] >= 0.0 and vol.state_default.X[2] <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp140 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 290
 type: ALGORITHM
 
   assert(vol.state_default.X[1] >= 0.0 and vol.state_default.X[1] <= 1.0, "Variable violating min/max constraint: 0.0 <= vol.state_default.X[1] <= 1.0, has value: " + String(vol.state_default.X[1], "g"));
 */
void Room_eqFunction_290(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,290};
  modelica_boolean tmp141;
  modelica_boolean tmp142;
  static const MMC_DEFSTRINGLIT(tmp143,88,"Variable violating min/max constraint: 0.0 <= vol.state_default.X[1] <= 1.0, has value: ");
  modelica_string tmp144;
  static int tmp145 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp145)
  {
    tmp141 = GreaterEq(data->simulationInfo->realParameter[50],0.0);
    tmp142 = LessEq(data->simulationInfo->realParameter[50],1.0);
    if(!(tmp141 && tmp142))
    {
      tmp144 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[50], (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp143),tmp144);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.2/Media/package.mo",5597,7,5598,64,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nvol.state_default.X[1] >= 0.0 and vol.state_default.X[1] <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp145 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 291
 type: ALGORITHM
 
   assert(vol.state_default.T >= 1.0 and vol.state_default.T <= 10000.0, "Variable violating min/max constraint: 1.0 <= vol.state_default.T <= 10000.0, has value: " + String(vol.state_default.T, "g"));
 */
void Room_eqFunction_291(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,291};
  modelica_boolean tmp146;
  modelica_boolean tmp147;
  static const MMC_DEFSTRINGLIT(tmp148,89,"Variable violating min/max constraint: 1.0 <= vol.state_default.T <= 10000.0, has value: ");
  modelica_string tmp149;
  static int tmp150 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp150)
  {
    tmp146 = GreaterEq(data->simulationInfo->realParameter[49],1.0);
    tmp147 = LessEq(data->simulationInfo->realParameter[49],10000.0);
    if(!(tmp146 && tmp147))
    {
      tmp149 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[49], (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp148),tmp149);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.2/Media/package.mo",5596,7,5596,44,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nvol.state_default.T >= 1.0 and vol.state_default.T <= 10000.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp150 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 292
 type: ALGORITHM
 
   assert(vol.state_default.p >= 0.0 and vol.state_default.p <= 100000000.0, "Variable violating min/max constraint: 0.0 <= vol.state_default.p <= 100000000.0, has value: " + String(vol.state_default.p, "g"));
 */
void Room_eqFunction_292(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,292};
  modelica_boolean tmp151;
  modelica_boolean tmp152;
  static const MMC_DEFSTRINGLIT(tmp153,93,"Variable violating min/max constraint: 0.0 <= vol.state_default.p <= 100000000.0, has value: ");
  modelica_string tmp154;
  static int tmp155 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp155)
  {
    tmp151 = GreaterEq(data->simulationInfo->realParameter[52],0.0);
    tmp152 = LessEq(data->simulationInfo->realParameter[52],100000000.0);
    if(!(tmp151 && tmp152))
    {
      tmp154 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[52], (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp153),tmp154);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.2/Media/package.mo",5595,7,5595,55,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nvol.state_default.p >= 0.0 and vol.state_default.p <= 100000000.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp155 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 293
 type: ALGORITHM
 
   assert(vol.rho_start >= 0.0, "Variable violating min constraint: 0.0 <= vol.rho_start, has value: " + String(vol.rho_start, "g"));
 */
void Room_eqFunction_293(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,293};
  modelica_boolean tmp156;
  static const MMC_DEFSTRINGLIT(tmp157,68,"Variable violating min constraint: 0.0 <= vol.rho_start, has value: ");
  modelica_string tmp158;
  static int tmp159 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp159)
  {
    tmp156 = GreaterEq(data->simulationInfo->realParameter[48],0.0);
    if(!tmp156)
    {
      tmp158 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[48], (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp157),tmp158);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Buildings latest/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo",90,3,91,72,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nvol.rho_start >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp159 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 294
 type: ALGORITHM
 
   assert(vol.m_flow_small >= 0.0, "Variable violating min constraint: 0.0 <= vol.m_flow_small, has value: " + String(vol.m_flow_small, "g"));
 */
void Room_eqFunction_294(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,294};
  modelica_boolean tmp160;
  static const MMC_DEFSTRINGLIT(tmp161,71,"Variable violating min constraint: 0.0 <= vol.m_flow_small, has value: ");
  modelica_string tmp162;
  static int tmp163 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp163)
  {
    tmp160 = GreaterEq(data->simulationInfo->realParameter[45],0.0);
    if(!tmp160)
    {
      tmp162 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[45], (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp161),tmp162);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Buildings latest/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo",28,3,30,41,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nvol.m_flow_small >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp163 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 295
 type: ALGORITHM
 
   assert(vol.m_flow_nominal >= 0.0, "Variable violating min constraint: 0.0 <= vol.m_flow_nominal, has value: " + String(vol.m_flow_nominal, "g"));
 */
void Room_eqFunction_295(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,295};
  modelica_boolean tmp164;
  static const MMC_DEFSTRINGLIT(tmp165,73,"Variable violating min constraint: 0.0 <= vol.m_flow_nominal, has value: ");
  modelica_string tmp166;
  static int tmp167 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp167)
  {
    tmp164 = GreaterEq(data->simulationInfo->realParameter[44],0.0);
    if(!tmp164)
    {
      tmp166 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[44], (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp165),tmp166);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Buildings latest/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo",22,3,24,52,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nvol.m_flow_nominal >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp167 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 296
 type: ALGORITHM
 
   assert(vol.mSenFac >= 1.0, "Variable violating min constraint: 1.0 <= vol.mSenFac, has value: " + String(vol.mSenFac, "g"));
 */
void Room_eqFunction_296(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,296};
  modelica_boolean tmp168;
  static const MMC_DEFSTRINGLIT(tmp169,66,"Variable violating min constraint: 1.0 <= vol.mSenFac, has value: ");
  modelica_string tmp170;
  static int tmp171 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp171)
  {
    tmp168 = GreaterEq(data->simulationInfo->realParameter[43],1.0);
    if(!tmp168)
    {
      tmp170 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[43], (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp169),tmp170);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Buildings latest/Fluid/Interfaces/LumpedVolumeDeclarations.mo",40,3,42,39,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nvol.mSenFac >= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp171 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 297
 type: ALGORITHM
 
   assert(vol.traceDynamics >= Modelica.Fluid.Types.Dynamics.DynamicFreeInitial and vol.traceDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState, "Variable violating min/max constraint: Modelica.Fluid.Types.Dynamics.DynamicFreeInitial <= vol.traceDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState, has value: " + String(vol.traceDynamics, "d"));
 */
void Room_eqFunction_297(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,297};
  modelica_boolean tmp172;
  modelica_boolean tmp173;
  static const MMC_DEFSTRINGLIT(tmp174,166,"Variable violating min/max constraint: Modelica.Fluid.Types.Dynamics.DynamicFreeInitial <= vol.traceDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState, has value: ");
  modelica_string tmp175;
  static int tmp176 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp176)
  {
    tmp172 = GreaterEq((modelica_integer)data->simulationInfo->integerParameter[9],1);
    tmp173 = LessEq((modelica_integer)data->simulationInfo->integerParameter[9],4);
    if(!(tmp172 && tmp173))
    {
      tmp175 = modelica_integer_to_modelica_string_format((modelica_integer)data->simulationInfo->integerParameter[9], (modelica_string) mmc_strings_len1[100]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp174),tmp175);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Buildings latest/Fluid/Interfaces/LumpedVolumeDeclarations.mo",17,3,19,75,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nvol.traceDynamics >= Modelica.Fluid.Types.Dynamics.DynamicFreeInitial and vol.traceDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp176 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 298
 type: ALGORITHM
 
   assert(vol.substanceDynamics >= Modelica.Fluid.Types.Dynamics.DynamicFreeInitial and vol.substanceDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState, "Variable violating min/max constraint: Modelica.Fluid.Types.Dynamics.DynamicFreeInitial <= vol.substanceDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState, has value: " + String(vol.substanceDynamics, "d"));
 */
void Room_eqFunction_298(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,298};
  modelica_boolean tmp177;
  modelica_boolean tmp178;
  static const MMC_DEFSTRINGLIT(tmp179,170,"Variable violating min/max constraint: Modelica.Fluid.Types.Dynamics.DynamicFreeInitial <= vol.substanceDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState, has value: ");
  modelica_string tmp180;
  static int tmp181 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp181)
  {
    tmp177 = GreaterEq((modelica_integer)data->simulationInfo->integerParameter[8],1);
    tmp178 = LessEq((modelica_integer)data->simulationInfo->integerParameter[8],4);
    if(!(tmp177 && tmp178))
    {
      tmp180 = modelica_integer_to_modelica_string_format((modelica_integer)data->simulationInfo->integerParameter[8], (modelica_string) mmc_strings_len1[100]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp179),tmp180);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Buildings latest/Fluid/Interfaces/LumpedVolumeDeclarations.mo",14,3,16,75,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nvol.substanceDynamics >= Modelica.Fluid.Types.Dynamics.DynamicFreeInitial and vol.substanceDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp181 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 299
 type: ALGORITHM
 
   assert(vol.massDynamics >= Modelica.Fluid.Types.Dynamics.DynamicFreeInitial and vol.massDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState, "Variable violating min/max constraint: Modelica.Fluid.Types.Dynamics.DynamicFreeInitial <= vol.massDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState, has value: " + String(vol.massDynamics, "d"));
 */
void Room_eqFunction_299(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,299};
  modelica_boolean tmp182;
  modelica_boolean tmp183;
  static const MMC_DEFSTRINGLIT(tmp184,165,"Variable violating min/max constraint: Modelica.Fluid.Types.Dynamics.DynamicFreeInitial <= vol.massDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState, has value: ");
  modelica_string tmp185;
  static int tmp186 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp186)
  {
    tmp182 = GreaterEq((modelica_integer)data->simulationInfo->integerParameter[6],1);
    tmp183 = LessEq((modelica_integer)data->simulationInfo->integerParameter[6],4);
    if(!(tmp182 && tmp183))
    {
      tmp185 = modelica_integer_to_modelica_string_format((modelica_integer)data->simulationInfo->integerParameter[6], (modelica_string) mmc_strings_len1[100]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp184),tmp185);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Buildings latest/Fluid/Interfaces/LumpedVolumeDeclarations.mo",11,3,13,75,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nvol.massDynamics >= Modelica.Fluid.Types.Dynamics.DynamicFreeInitial and vol.massDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp186 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 300
 type: ALGORITHM
 
   assert(vol.energyDynamics >= Modelica.Fluid.Types.Dynamics.DynamicFreeInitial and vol.energyDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState, "Variable violating min/max constraint: Modelica.Fluid.Types.Dynamics.DynamicFreeInitial <= vol.energyDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState, has value: " + String(vol.energyDynamics, "d"));
 */
void Room_eqFunction_300(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,300};
  modelica_boolean tmp187;
  modelica_boolean tmp188;
  static const MMC_DEFSTRINGLIT(tmp189,167,"Variable violating min/max constraint: Modelica.Fluid.Types.Dynamics.DynamicFreeInitial <= vol.energyDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState, has value: ");
  modelica_string tmp190;
  static int tmp191 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp191)
  {
    tmp187 = GreaterEq((modelica_integer)data->simulationInfo->integerParameter[5],1);
    tmp188 = LessEq((modelica_integer)data->simulationInfo->integerParameter[5],4);
    if(!(tmp187 && tmp188))
    {
      tmp190 = modelica_integer_to_modelica_string_format((modelica_integer)data->simulationInfo->integerParameter[5], (modelica_string) mmc_strings_len1[100]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp189),tmp190);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Buildings latest/Fluid/Interfaces/LumpedVolumeDeclarations.mo",8,3,10,75,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nvol.energyDynamics >= Modelica.Fluid.Types.Dynamics.DynamicFreeInitial and vol.energyDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp191 = 1;
    }
  }
  TRACE_POP
}
int Room_updateBoundParameters(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  Room_eqFunction_200(data, threadData);

  Room_eqFunction_201(data, threadData);

  Room_eqFunction_202(data, threadData);

  Room_eqFunction_203(data, threadData);

  Room_eqFunction_204(data, threadData);

  Room_eqFunction_205(data, threadData);

  Room_eqFunction_206(data, threadData);

  Room_eqFunction_207(data, threadData);

  Room_eqFunction_208(data, threadData);

  Room_eqFunction_209(data, threadData);

  Room_eqFunction_210(data, threadData);

  Room_eqFunction_211(data, threadData);

  Room_eqFunction_212(data, threadData);

  Room_eqFunction_213(data, threadData);

  Room_eqFunction_214(data, threadData);

  Room_eqFunction_215(data, threadData);

  Room_eqFunction_216(data, threadData);

  Room_eqFunction_217(data, threadData);

  Room_eqFunction_218(data, threadData);

  Room_eqFunction_219(data, threadData);

  Room_eqFunction_220(data, threadData);

  Room_eqFunction_221(data, threadData);

  Room_eqFunction_222(data, threadData);

  Room_eqFunction_223(data, threadData);

  Room_eqFunction_224(data, threadData);

  Room_eqFunction_225(data, threadData);

  Room_eqFunction_226(data, threadData);

  Room_eqFunction_227(data, threadData);

  Room_eqFunction_228(data, threadData);

  Room_eqFunction_229(data, threadData);

  Room_eqFunction_230(data, threadData);

  Room_eqFunction_231(data, threadData);

  Room_eqFunction_232(data, threadData);

  Room_eqFunction_233(data, threadData);

  Room_eqFunction_234(data, threadData);

  Room_eqFunction_235(data, threadData);

  Room_eqFunction_236(data, threadData);

  Room_eqFunction_237(data, threadData);

  Room_eqFunction_238(data, threadData);

  Room_eqFunction_239(data, threadData);

  Room_eqFunction_240(data, threadData);

  Room_eqFunction_241(data, threadData);

  Room_eqFunction_242(data, threadData);

  Room_eqFunction_243(data, threadData);

  Room_eqFunction_244(data, threadData);

  Room_eqFunction_245(data, threadData);

  Room_eqFunction_246(data, threadData);

  Room_eqFunction_247(data, threadData);

  Room_eqFunction_248(data, threadData);

  Room_eqFunction_249(data, threadData);

  Room_eqFunction_250(data, threadData);

  Room_eqFunction_251(data, threadData);

  Room_eqFunction_252(data, threadData);

  Room_eqFunction_253(data, threadData);

  Room_eqFunction_254(data, threadData);

  Room_eqFunction_255(data, threadData);

  Room_eqFunction_256(data, threadData);

  Room_eqFunction_257(data, threadData);

  Room_eqFunction_258(data, threadData);

  Room_eqFunction_259(data, threadData);

  Room_eqFunction_260(data, threadData);

  Room_eqFunction_261(data, threadData);

  Room_eqFunction_262(data, threadData);

  Room_eqFunction_263(data, threadData);

  Room_eqFunction_264(data, threadData);

  Room_eqFunction_265(data, threadData);

  Room_eqFunction_266(data, threadData);

  Room_eqFunction_267(data, threadData);

  Room_eqFunction_268(data, threadData);

  Room_eqFunction_269(data, threadData);

  Room_eqFunction_270(data, threadData);

  Room_eqFunction_271(data, threadData);

  Room_eqFunction_272(data, threadData);

  Room_eqFunction_273(data, threadData);

  Room_eqFunction_274(data, threadData);

  Room_eqFunction_275(data, threadData);

  Room_eqFunction_276(data, threadData);

  Room_eqFunction_277(data, threadData);

  Room_eqFunction_278(data, threadData);

  Room_eqFunction_279(data, threadData);

  Room_eqFunction_280(data, threadData);

  Room_eqFunction_281(data, threadData);

  Room_eqFunction_282(data, threadData);

  Room_eqFunction_283(data, threadData);

  Room_eqFunction_284(data, threadData);

  Room_eqFunction_285(data, threadData);

  Room_eqFunction_286(data, threadData);

  Room_eqFunction_287(data, threadData);

  Room_eqFunction_288(data, threadData);

  Room_eqFunction_289(data, threadData);

  Room_eqFunction_290(data, threadData);

  Room_eqFunction_291(data, threadData);

  Room_eqFunction_292(data, threadData);

  Room_eqFunction_293(data, threadData);

  Room_eqFunction_294(data, threadData);

  Room_eqFunction_295(data, threadData);

  Room_eqFunction_296(data, threadData);

  Room_eqFunction_297(data, threadData);

  Room_eqFunction_298(data, threadData);

  Room_eqFunction_299(data, threadData);

  Room_eqFunction_300(data, threadData);
  
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif

