/* Initialization */
#include "Room_model.h"
#include "Room_11mix.h"
#include "Room_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

void Room_functionInitialEquations_0(DATA *data, threadData_t *threadData);


/*
 equation index: 1
 type: SIMPLE_ASSIGN
 vol._dynBal._Hb_flow = 0.0
 */
void Room_eqFunction_1(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1};
  data->localData[0]->realVars[26] /* vol._dynBal._Hb_flow variable */ = 0.0;
  TRACE_POP
}

/*
 equation index: 2
 type: SIMPLE_ASSIGN
 vol._dynBal._mb_flow = 0.0
 */
void Room_eqFunction_2(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2};
  data->localData[0]->realVars[31] /* vol._dynBal._mb_flow variable */ = 0.0;
  TRACE_POP
}

/*
 equation index: 3
 type: SIMPLE_ASSIGN
 vol._dynBal._mbXi_flow[1] = 0.0
 */
void Room_eqFunction_3(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3};
  data->localData[0]->realVars[30] /* vol._dynBal._mbXi_flow[1] variable */ = 0.0;
  TRACE_POP
}

/*
 equation index: 4
 type: SIMPLE_ASSIGN
 vol._dynBal._mWat_flow_internal = 0.0
 */
void Room_eqFunction_4(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,4};
  data->localData[0]->realVars[28] /* vol._dynBal._mWat_flow_internal variable */ = 0.0;
  TRACE_POP
}

/*
 equation index: 5
 type: SIMPLE_ASSIGN
 HeatingControlPortTransformer1._HeatingControlPort1._set_hysteresis_intervallum1._counter = 1
 */
void Room_eqFunction_5(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,5};
  data->localData[0]->integerVars[0] /* HeatingControlPortTransformer1._HeatingControlPort1._set_hysteresis_intervallum1._counter DISCRETE */ = ((modelica_integer) 1);
  TRACE_POP
}

/*
 equation index: 6
 type: SIMPLE_ASSIGN
 temperatureStreamPortTransformer1._TemperatureStreamPort1._measured_temperature1._counter = 1
 */
void Room_eqFunction_6(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,6};
  data->localData[0]->integerVars[5] /* temperatureStreamPortTransformer1._TemperatureStreamPort1._measured_temperature1._counter DISCRETE */ = ((modelica_integer) 1);
  TRACE_POP
}

/*
 equation index: 7
 type: SIMPLE_ASSIGN
 thermostatControlPortTransformer1._ThermostatControlPort1._set_target_temperature1._counter = 1
 */
void Room_eqFunction_7(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,7};
  data->localData[0]->integerVars[9] /* thermostatControlPortTransformer1._ThermostatControlPort1._set_target_temperature1._counter DISCRETE */ = ((modelica_integer) 1);
  TRACE_POP
}

/*
 equation index: 8
 type: SIMPLE_ASSIGN
 thermostatControlPort1._set_target_temperature1._counter = 1
 */
void Room_eqFunction_8(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,8};
  data->localData[0]->integerVars[6] /* thermostatControlPort1._set_target_temperature1._counter DISCRETE */ = ((modelica_integer) 1);
  TRACE_POP
}

/*
 equation index: 9
 type: SIMPLE_ASSIGN
 thermostatControlPort1._set_target_temperature1._target_temperature[2] = thermostatControlPortTransformer1.set_target_temperature_target_temperature_initial
 */
void Room_eqFunction_9(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,9};
  data->localData[0]->realVars[24] /* thermostatControlPort1._set_target_temperature1._target_temperature[2] variable */ = data->simulationInfo->realParameter[22];
  TRACE_POP
}

/*
 equation index: 10
 type: SIMPLE_ASSIGN
 thermostatControlPort1._set_target_temperature1._target_temperature[3] = thermostatControlPortTransformer1.set_target_temperature_target_temperature_initial
 */
void Room_eqFunction_10(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,10};
  data->localData[0]->realVars[25] /* thermostatControlPort1._set_target_temperature1._target_temperature[3] variable */ = data->simulationInfo->realParameter[22];
  TRACE_POP
}

/*
 equation index: 11
 type: SIMPLE_ASSIGN
 temperatureStreamPort1._measured_temperature1._counter = 1
 */
void Room_eqFunction_11(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,11};
  data->localData[0]->integerVars[4] /* temperatureStreamPort1._measured_temperature1._counter DISCRETE */ = ((modelica_integer) 1);
  TRACE_POP
}

/*
 equation index: 12
 type: SIMPLE_ASSIGN
 temperatureStreamPort1._measured_temperature1._measured_temperature[2] = temperatureStreamPortTransformer1.measured_temperature_measured_temperature_initial
 */
void Room_eqFunction_12(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,12};
  data->localData[0]->realVars[19] /* temperatureStreamPort1._measured_temperature1._measured_temperature[2] variable */ = data->simulationInfo->realParameter[20];
  TRACE_POP
}

/*
 equation index: 13
 type: SIMPLE_ASSIGN
 temperatureStreamPort1._measured_temperature1._measured_temperature[3] = temperatureStreamPortTransformer1.measured_temperature_measured_temperature_initial
 */
void Room_eqFunction_13(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,13};
  data->localData[0]->realVars[20] /* temperatureStreamPort1._measured_temperature1._measured_temperature[3] variable */ = data->simulationInfo->realParameter[20];
  TRACE_POP
}

/*
 equation index: 14
 type: SIMPLE_ASSIGN
 heatingControlPort1._set_hysteresis_intervallum1._counter = 1
 */
void Room_eqFunction_14(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,14};
  data->localData[0]->integerVars[1] /* heatingControlPort1._set_hysteresis_intervallum1._counter DISCRETE */ = ((modelica_integer) 1);
  TRACE_POP
}

/*
 equation index: 15
 type: SIMPLE_ASSIGN
 heatingControlPort1._set_hysteresis_intervallum1._hysteresis_intervallum[2] = HeatingControlPortTransformer1.set_hysteresis_intervallum_hysteresis_intervallum_initial
 */
void Room_eqFunction_15(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,15};
  data->localData[0]->realVars[15] /* heatingControlPort1._set_hysteresis_intervallum1._hysteresis_intervallum[2] variable */ = data->simulationInfo->realParameter[0];
  TRACE_POP
}

/*
 equation index: 16
 type: SIMPLE_ASSIGN
 heatingControlPort1._set_hysteresis_intervallum1._hysteresis_intervallum[3] = HeatingControlPortTransformer1.set_hysteresis_intervallum_hysteresis_intervallum_initial
 */
void Room_eqFunction_16(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,16};
  data->localData[0]->realVars[16] /* heatingControlPort1._set_hysteresis_intervallum1._hysteresis_intervallum[3] variable */ = data->simulationInfo->realParameter[0];
  TRACE_POP
}

/*
 equation index: 17
 type: SIMPLE_ASSIGN
 thermostatControlPort1._set_target_temperature1._target_temperature[1] = step1.offset + (if time < step1.startTime then 0.0 else step1.height)
 */
void Room_eqFunction_17(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,17};
  modelica_boolean tmp0;
  tmp0 = Less(data->localData[0]->timeValue,data->simulationInfo->realParameter[19]);
  data->localData[0]->realVars[23] /* thermostatControlPort1._set_target_temperature1._target_temperature[1] variable */ = data->simulationInfo->realParameter[18] + (tmp0?0.0:data->simulationInfo->realParameter[17]);
  TRACE_POP
}

/*
 equation index: 18
 type: SIMPLE_ASSIGN
 HeatingControlPortTransformer1._turn_heating_off = heatingControlPort1.turn_heating_off1.counter >= 1
 */
void Room_eqFunction_18(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,18};
  modelica_boolean tmp1;
  tmp1 = GreaterEq((modelica_integer)data->localData[0]->integerVars[2] /* heatingControlPort1._turn_heating_off1._counter variable */,((modelica_integer) 1));
  data->localData[0]->booleanVars[16] /* HeatingControlPortTransformer1._turn_heating_off DISCRETE */ = tmp1;
  TRACE_POP
}

/*
 equation index: 19
 type: SIMPLE_ASSIGN
 HeatingControlPortTransformer1._turn_heating_on = heatingControlPort1.turn_heating_on1.counter >= 1
 */
void Room_eqFunction_19(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,19};
  modelica_boolean tmp2;
  tmp2 = GreaterEq((modelica_integer)data->localData[0]->integerVars[3] /* heatingControlPort1._turn_heating_on1._counter variable */,((modelica_integer) 1));
  data->localData[0]->booleanVars[17] /* HeatingControlPortTransformer1._turn_heating_on DISCRETE */ = tmp2;
  TRACE_POP
}

/*
 equation index: 20
 type: SIMPLE_ASSIGN
 der(vol._dynBal._mXi[1]) = 0.0
 */
void Room_eqFunction_20(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,20};
  data->localData[0]->realVars[8] /* der(vol._dynBal._mXi[1]) DUMMY_DER */ = 0.0;
  TRACE_POP
}

/*
 equation index: 21
 type: SIMPLE_ASSIGN
 der(vol._dynBal._m) = 0.0
 */
void Room_eqFunction_21(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,21};
  data->localData[0]->realVars[3] /* der(vol._dynBal._m) STATE_DER */ = 0.0;
  TRACE_POP
}

/*
 equation index: 22
 type: SIMPLE_ASSIGN
 $PRE._rSFlipFlop._pre._u = rSFlipFlop.pre.pre_u_start
 */
void Room_eqFunction_22(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,22};
  data->simulationInfo->booleanVarsPre[20] /* rSFlipFlop._pre._u DISCRETE */ = data->simulationInfo->booleanParameter[2];
  TRACE_POP
}

/*
 equation index: 23
 type: SIMPLE_ASSIGN
 rSFlipFlop._QI = $PRE.rSFlipFlop.pre.u
 */
void Room_eqFunction_23(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,23};
  data->localData[0]->booleanVars[19] /* rSFlipFlop._QI DISCRETE */ = data->simulationInfo->booleanVarsPre[20] /* rSFlipFlop._pre._u DISCRETE */;
  TRACE_POP
}

/*
 equation index: 24
 type: SIMPLE_ASSIGN
 booleanToReal1._u = not (rSFlipFlop.QI or HeatingControlPortTransformer1.turn_heating_off)
 */
void Room_eqFunction_24(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,24};
  data->localData[0]->booleanVars[18] /* booleanToReal1._u DISCRETE */ = (!(data->localData[0]->booleanVars[19] /* rSFlipFlop._QI DISCRETE */ || data->localData[0]->booleanVars[16] /* HeatingControlPortTransformer1._turn_heating_off DISCRETE */));
  TRACE_POP
}

/*
 equation index: 25
 type: SIMPLE_ASSIGN
 booleanToReal1._y = if booleanToReal1.u then booleanToReal1.realTrue else booleanToReal1.realFalse
 */
void Room_eqFunction_25(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,25};
  data->localData[0]->realVars[10] /* booleanToReal1._y variable */ = (data->localData[0]->booleanVars[18] /* booleanToReal1._u DISCRETE */?data->simulationInfo->realParameter[5]:data->simulationInfo->realParameter[4]);
  TRACE_POP
}

/*
 equation index: 26
 type: SIMPLE_ASSIGN
 rSFlipFlop._pre._u = not (HeatingControlPortTransformer1.turn_heating_on or booleanToReal1.u)
 */
void Room_eqFunction_26(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,26};
  data->localData[0]->booleanVars[20] /* rSFlipFlop._pre._u DISCRETE */ = (!(data->localData[0]->booleanVars[17] /* HeatingControlPortTransformer1._turn_heating_on DISCRETE */ || data->localData[0]->booleanVars[18] /* booleanToReal1._u DISCRETE */));
  TRACE_POP
}

/*
 equation index: 27
 type: SIMPLE_ASSIGN
 vol._dynBal._medium._Xi[1] = vol.dynBal.X_start[1]
 */
void Room_eqFunction_27(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,27};
  data->localData[0]->realVars[1] /* vol._dynBal._medium._Xi[1] STATE(1) */ = data->simulationInfo->realParameter[29];
  TRACE_POP
}

/*
 equation index: 28
 type: SIMPLE_ASSIGN
 vol._dynBal._medium._MM = DIVISION(1.0, 34.52428788658843 + 20.98414717520355 * vol.dynBal.medium.Xi[1])
 */
void Room_eqFunction_28(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,28};
  data->localData[0]->realVars[32] /* vol._dynBal._medium._MM variable */ = DIVISION_SIM(1.0,34.52428788658843 + (20.98414717520355) * (data->localData[0]->realVars[1] /* vol._dynBal._medium._Xi[1] STATE(1) */),"34.52428788658843 + 20.98414717520355 * vol.dynBal.medium.Xi[1]",equationIndexes);
  TRACE_POP
}

/*
 equation index: 29
 type: SIMPLE_ASSIGN
 vol._dynBal._medium._X[2] = 1.0 - (DIVISION(1.0, vol.dynBal.medium.MM * 20.98414717520355) - 1.645255706526159)
 */
void Room_eqFunction_29(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,29};
  data->localData[0]->realVars[35] /* vol._dynBal._medium._X[2] variable */ = 1.0 - (DIVISION_SIM(1.0,(data->localData[0]->realVars[32] /* vol._dynBal._medium._MM variable */) * (20.98414717520355),"vol.dynBal.medium.MM * 20.98414717520355",equationIndexes) - 1.645255706526159);
  TRACE_POP
}

/*
 equation index: 30
 type: SIMPLE_ASSIGN
 vol._dynBal._medium._R = 287.0512249529787 * vol.dynBal.medium.X[2] + 461.5233290850878 * vol.dynBal.medium.Xi[1]
 */
void Room_eqFunction_30(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,30};
  data->localData[0]->realVars[33] /* vol._dynBal._medium._R variable */ = (287.0512249529787) * (data->localData[0]->realVars[35] /* vol._dynBal._medium._X[2] variable */) + (461.5233290850878) * (data->localData[0]->realVars[1] /* vol._dynBal._medium._Xi[1] STATE(1) */);
  TRACE_POP
}

/*
 equation index: 31
 type: SIMPLE_ASSIGN
 vol._dynBal._medium._p = vol.dynBal.p_start
 */
void Room_eqFunction_31(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,31};
  data->localData[0]->realVars[38] /* vol._dynBal._medium._p variable */ = data->simulationInfo->realParameter[35];
  TRACE_POP
}

/*
 equation index: 32
 type: SIMPLE_ASSIGN
 vol._dynBal._medium._p_bar = 1e-05 * vol.dynBal.medium.p
 */
void Room_eqFunction_32(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,32};
  data->localData[0]->realVars[39] /* vol._dynBal._medium._p_bar variable */ = (1e-05) * (data->localData[0]->realVars[38] /* vol._dynBal._medium._p variable */);
  TRACE_POP
}

/*
 equation index: 33
 type: SIMPLE_ASSIGN
 vol._dynBal._medium._d = 1.184307920059215 * vol.dynBal.medium.p_bar
 */
void Room_eqFunction_33(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,33};
  data->localData[0]->realVars[36] /* vol._dynBal._medium._d variable */ = (1.184307920059215) * (data->localData[0]->realVars[39] /* vol._dynBal._medium._p_bar variable */);
  TRACE_POP
}

/*
 equation index: 34
 type: SIMPLE_ASSIGN
 vol._dynBal._m = 0.002131754256106588 * vol.dynBal.medium.p
 */
void Room_eqFunction_34(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,34};
  data->localData[0]->realVars[0] /* vol._dynBal._m STATE(1) */ = (0.002131754256106588) * (data->localData[0]->realVars[38] /* vol._dynBal._medium._p variable */);
  TRACE_POP
}

/*
 equation index: 35
 type: SIMPLE_ASSIGN
 vol._dynBal._mXi[1] = vol.dynBal.medium.Xi[1] * vol.dynBal.m
 */
void Room_eqFunction_35(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,35};
  data->localData[0]->realVars[29] /* vol._dynBal._mXi[1] DUMMY_STATE */ = (data->localData[0]->realVars[1] /* vol._dynBal._medium._Xi[1] STATE(1) */) * (data->localData[0]->realVars[0] /* vol._dynBal._m STATE(1) */);
  TRACE_POP
}

/*
 equation index: 36
 type: SIMPLE_ASSIGN
 der(vol._dynBal._medium._Xi[1]) = DIVISION($DER.vol.dynBal.mXi[1] - vol.dynBal.medium.Xi[1] * $DER.vol.dynBal.m, vol.dynBal.m)
 */
void Room_eqFunction_36(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,36};
  data->localData[0]->realVars[4] /* der(vol._dynBal._medium._Xi[1]) STATE_DER */ = DIVISION_SIM(data->localData[0]->realVars[8] /* der(vol._dynBal._mXi[1]) DUMMY_DER */ - ((data->localData[0]->realVars[1] /* vol._dynBal._medium._Xi[1] STATE(1) */) * (data->localData[0]->realVars[3] /* der(vol._dynBal._m) STATE_DER */)),data->localData[0]->realVars[0] /* vol._dynBal._m STATE(1) */,"vol.dynBal.m",equationIndexes);
  TRACE_POP
}

/*
 equation index: 37
 type: SIMPLE_ASSIGN
 vol._dynBal._medium._T = vol.dynBal.T_start
 */
void Room_eqFunction_37(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,37};
  data->localData[0]->realVars[34] /* vol._dynBal._medium._T variable */ = data->simulationInfo->realParameter[28];
  TRACE_POP
}

/*
 equation index: 38
 type: SIMPLE_ASSIGN
 vol._dynBal._medium._dT = -273.15 + vol.dynBal.medium.T
 */
void Room_eqFunction_38(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,38};
  data->localData[0]->realVars[37] /* vol._dynBal._medium._dT variable */ = -273.15 + data->localData[0]->realVars[34] /* vol._dynBal._medium._T variable */;
  TRACE_POP
}

/*
 equation index: 39
 type: SIMPLE_ASSIGN
 vol._hOut_internal = 1006.0 * vol.dynBal.medium.dT * vol.dynBal.medium.X[2] + (2501014.5 + 1860.0 * vol.dynBal.medium.dT) * vol.dynBal.medium.Xi[1]
 */
void Room_eqFunction_39(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,39};
  data->localData[0]->realVars[2] /* vol._hOut_internal STATE(1) */ = (1006.0) * ((data->localData[0]->realVars[37] /* vol._dynBal._medium._dT variable */) * (data->localData[0]->realVars[35] /* vol._dynBal._medium._X[2] variable */)) + (2501014.5 + (1860.0) * (data->localData[0]->realVars[37] /* vol._dynBal._medium._dT variable */)) * (data->localData[0]->realVars[1] /* vol._dynBal._medium._Xi[1] STATE(1) */);
  TRACE_POP
}

/*
 equation index: 40
 type: SIMPLE_ASSIGN
 vol._dynBal._medium._u = -84437.5 + vol.hOut_internal
 */
void Room_eqFunction_40(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,40};
  data->localData[0]->realVars[40] /* vol._dynBal._medium._u DUMMY_STATE */ = -84437.5 + data->localData[0]->realVars[2] /* vol._hOut_internal STATE(1) */;
  TRACE_POP
}

/*
 equation index: 41
 type: SIMPLE_ASSIGN
 vol._dynBal._U = vol.dynBal.m * vol.dynBal.medium.u
 */
void Room_eqFunction_41(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,41};
  data->localData[0]->realVars[27] /* vol._dynBal._U DUMMY_STATE */ = (data->localData[0]->realVars[0] /* vol._dynBal._m STATE(1) */) * (data->localData[0]->realVars[40] /* vol._dynBal._medium._u DUMMY_STATE */);
  TRACE_POP
}

/*
 equation index: 42
 type: SIMPLE_ASSIGN
 heaCap._T = 273.15 + DIVISION(vol.hOut_internal + -2501014.5 * vol.dynBal.medium.Xi[1], 1006.0 * (1.0 - vol.dynBal.medium.Xi[1]) + 1860.0 * vol.dynBal.medium.Xi[1])
 */
void Room_eqFunction_42(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,42};
  data->localData[0]->realVars[11] /* heaCap._T DUMMY_STATE */ = 273.15 + DIVISION_SIM(data->localData[0]->realVars[2] /* vol._hOut_internal STATE(1) */ + (-2501014.5) * (data->localData[0]->realVars[1] /* vol._dynBal._medium._Xi[1] STATE(1) */),(1006.0) * (1.0 - data->localData[0]->realVars[1] /* vol._dynBal._medium._Xi[1] STATE(1) */) + (1860.0) * (data->localData[0]->realVars[1] /* vol._dynBal._medium._Xi[1] STATE(1) */),"1006.0 * (1.0 - vol.dynBal.medium.Xi[1]) + 1860.0 * vol.dynBal.medium.Xi[1]",equationIndexes);
  TRACE_POP
}

/*
 equation index: 43
 type: SIMPLE_ASSIGN
 theCon._dT = TOut.T - heaCap.T
 */
void Room_eqFunction_43(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,43};
  data->localData[0]->realVars[22] /* theCon._dT variable */ = data->simulationInfo->realParameter[2] - data->localData[0]->realVars[11] /* heaCap._T DUMMY_STATE */;
  TRACE_POP
}

/*
 equation index: 44
 type: SIMPLE_ASSIGN
 theCon._Q_flow = theCon.G * theCon.dT
 */
void Room_eqFunction_44(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,44};
  data->localData[0]->realVars[21] /* theCon._Q_flow variable */ = (data->simulationInfo->realParameter[21]) * (data->localData[0]->realVars[22] /* theCon._dT variable */);
  TRACE_POP
}

/*
 equation index: 45
 type: SIMPLE_ASSIGN
 preHea._port._Q_flow = (-booleanToReal1.y) * (1.0 + preHea.alpha * (heaCap.T - preHea.T_ref))
 */
void Room_eqFunction_45(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,45};
  data->localData[0]->realVars[17] /* preHea._port._Q_flow variable */ = ((-data->localData[0]->realVars[10] /* booleanToReal1._y variable */)) * (1.0 + (data->simulationInfo->realParameter[10]) * (data->localData[0]->realVars[11] /* heaCap._T DUMMY_STATE */ - data->simulationInfo->realParameter[9]));
  TRACE_POP
}

/*
 equation index: 46
 type: SIMPLE_ASSIGN
 temperatureStreamPort1._measured_temperature1._measured_temperature[1] = -273.15 + heaCap.T
 */
void Room_eqFunction_46(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,46};
  data->localData[0]->realVars[18] /* temperatureStreamPort1._measured_temperature1._measured_temperature[1] variable */ = -273.15 + data->localData[0]->realVars[11] /* heaCap._T DUMMY_STATE */;
  TRACE_POP
}

/*
 equation index: 57
 type: LINEAR
 
 <var>der(vol._hOut_internal)</var>
 <row>

 </row>
 <matrix>
 </matrix>
 */
void Room_eqFunction_57(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,57};
  /* Linear equation system */
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving linear system 57 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  data->simulationInfo->linearSystemData[0].x[0] = data->localData[1]->realVars[5] /* der(vol._hOut_internal) STATE_DER */;
  retValue = solve_linear_system(data, threadData, 0);
  
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,57};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving linear system 57 failed at time=%.15g.\nFor more information please use -lv LOG_LS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[5] /* der(vol._hOut_internal) STATE_DER */ = data->simulationInfo->linearSystemData[0].x[0];
  TRACE_POP
}

/*
 equation index: 58
 type: SIMPLE_ASSIGN
 der(heaCap._T) = heaCap.der_T
 */
void Room_eqFunction_58(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,58};
  data->localData[0]->realVars[6] /* der(heaCap._T) DUMMY_DER */ = data->localData[0]->realVars[12] /* heaCap._der_T variable */;
  TRACE_POP
}

/*
 equation index: 59
 type: SIMPLE_ASSIGN
 $PRE._thermostatControlPortTransformer1._turn_thermostat_offSignalHolder._u = $START.thermostatControlPortTransformer1.turn_thermostat_offSignalHolder.u
 */
void Room_eqFunction_59(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,59};
  data->simulationInfo->booleanVarsPre[25] /* thermostatControlPortTransformer1._turn_thermostat_offSignalHolder._u DISCRETE */ = data->modelData->booleanVarsData[25].attribute /* thermostatControlPortTransformer1._turn_thermostat_offSignalHolder._u DISCRETE */.start;
  TRACE_POP
}

/*
 equation index: 60
 type: SIMPLE_ASSIGN
 thermostatControlPortTransformer1._turn_thermostat_offSignalHolder._u = false
 */
void Room_eqFunction_60(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,60};
  data->localData[0]->booleanVars[25] /* thermostatControlPortTransformer1._turn_thermostat_offSignalHolder._u DISCRETE */ = 0;
  TRACE_POP
}

/*
 equation index: 61
 type: SIMPLE_ASSIGN
 $whenCondition1 = thermostatControlPortTransformer1.turn_thermostat_offSignalHolder.u and not $PRE.thermostatControlPortTransformer1.turn_thermostat_offSignalHolder.u
 */
void Room_eqFunction_61(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,61};
  data->localData[0]->booleanVars[0] /* $whenCondition1 DISCRETE */ = (data->localData[0]->booleanVars[25] /* thermostatControlPortTransformer1._turn_thermostat_offSignalHolder._u DISCRETE */ && (!data->simulationInfo->booleanVarsPre[25] /* thermostatControlPortTransformer1._turn_thermostat_offSignalHolder._u DISCRETE */));
  TRACE_POP
}

/*
 equation index: 62
 type: SIMPLE_ASSIGN
 thermostatControlPortTransformer1._turn_thermostat_offSignalHolder._y = false
 */
void Room_eqFunction_62(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,62};
  data->localData[0]->booleanVars[26] /* thermostatControlPortTransformer1._turn_thermostat_offSignalHolder._y DISCRETE */ = 0;
  TRACE_POP
}

/*
 equation index: 63
 type: SIMPLE_ASSIGN
 $PRE._thermostatControlPortTransformer1._turn_thermostat_offSignalHolder._y = thermostatControlPortTransformer1.turn_thermostat_offSignalHolder.y
 */
void Room_eqFunction_63(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,63};
  data->simulationInfo->booleanVarsPre[26] /* thermostatControlPortTransformer1._turn_thermostat_offSignalHolder._y DISCRETE */ = data->localData[0]->booleanVars[26] /* thermostatControlPortTransformer1._turn_thermostat_offSignalHolder._y DISCRETE */;
  TRACE_POP
}

/*
 equation index: 64
 type: SIMPLE_ASSIGN
 thermostatControlPort1._turn_thermostat_off1._counter = if thermostatControlPortTransformer1.turn_thermostat_offSignalHolder.y then 1 else 0
 */
void Room_eqFunction_64(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,64};
  data->localData[0]->integerVars[7] /* thermostatControlPort1._turn_thermostat_off1._counter DISCRETE */ = (data->localData[0]->booleanVars[26] /* thermostatControlPortTransformer1._turn_thermostat_offSignalHolder._y DISCRETE */?((modelica_integer) 1):((modelica_integer) 0));
  TRACE_POP
}

/*
 equation index: 65
 type: SIMPLE_ASSIGN
 thermostatControlPortTransformer1._turn_thermostat_offSignalHolder._entryTime = 0.0
 */
void Room_eqFunction_65(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,65};
  data->localData[0]->realVars[46] /* thermostatControlPortTransformer1._turn_thermostat_offSignalHolder._entryTime DISCRETE */ = 0.0;
  TRACE_POP
}

/*
 equation index: 66
 type: SIMPLE_ASSIGN
 $PRE._thermostatControlPortTransformer1._turn_thermostat_offSignalHolder._entryTime = thermostatControlPortTransformer1.turn_thermostat_offSignalHolder.entryTime
 */
void Room_eqFunction_66(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,66};
  data->simulationInfo->realVarsPre[46] /* thermostatControlPortTransformer1._turn_thermostat_offSignalHolder._entryTime DISCRETE */ = data->localData[0]->realVars[46] /* thermostatControlPortTransformer1._turn_thermostat_offSignalHolder._entryTime DISCRETE */;
  TRACE_POP
}

/*
 equation index: 67
 type: SIMPLE_ASSIGN
 $whenCondition2 = 10.0 + thermostatControlPortTransformer1.turn_thermostat_offSignalHolder.entryTime < time
 */
void Room_eqFunction_67(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,67};
  modelica_boolean tmp3;
  tmp3 = Less(10.0 + data->localData[0]->realVars[46] /* thermostatControlPortTransformer1._turn_thermostat_offSignalHolder._entryTime DISCRETE */,data->localData[0]->timeValue);
  data->localData[0]->booleanVars[6] /* $whenCondition2 DISCRETE */ = tmp3;
  TRACE_POP
}

/*
 equation index: 68
 type: SIMPLE_ASSIGN
 $PRE._thermostatControlPortTransformer1._turn_thermostat_onSignalHolder._u = $START.thermostatControlPortTransformer1.turn_thermostat_onSignalHolder.u
 */
void Room_eqFunction_68(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,68};
  data->simulationInfo->booleanVarsPre[27] /* thermostatControlPortTransformer1._turn_thermostat_onSignalHolder._u DISCRETE */ = data->modelData->booleanVarsData[27].attribute /* thermostatControlPortTransformer1._turn_thermostat_onSignalHolder._u DISCRETE */.start;
  TRACE_POP
}

/*
 equation index: 69
 type: SIMPLE_ASSIGN
 thermostatControlPortTransformer1._turn_thermostat_onSignalHolder._u = false
 */
void Room_eqFunction_69(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,69};
  data->localData[0]->booleanVars[27] /* thermostatControlPortTransformer1._turn_thermostat_onSignalHolder._u DISCRETE */ = 0;
  TRACE_POP
}

/*
 equation index: 70
 type: SIMPLE_ASSIGN
 $whenCondition3 = thermostatControlPortTransformer1.turn_thermostat_onSignalHolder.u and not $PRE.thermostatControlPortTransformer1.turn_thermostat_onSignalHolder.u
 */
void Room_eqFunction_70(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,70};
  data->localData[0]->booleanVars[7] /* $whenCondition3 DISCRETE */ = (data->localData[0]->booleanVars[27] /* thermostatControlPortTransformer1._turn_thermostat_onSignalHolder._u DISCRETE */ && (!data->simulationInfo->booleanVarsPre[27] /* thermostatControlPortTransformer1._turn_thermostat_onSignalHolder._u DISCRETE */));
  TRACE_POP
}

/*
 equation index: 71
 type: SIMPLE_ASSIGN
 thermostatControlPortTransformer1._turn_thermostat_onSignalHolder._y = false
 */
void Room_eqFunction_71(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,71};
  data->localData[0]->booleanVars[28] /* thermostatControlPortTransformer1._turn_thermostat_onSignalHolder._y DISCRETE */ = 0;
  TRACE_POP
}

/*
 equation index: 72
 type: SIMPLE_ASSIGN
 $PRE._thermostatControlPortTransformer1._turn_thermostat_onSignalHolder._y = thermostatControlPortTransformer1.turn_thermostat_onSignalHolder.y
 */
void Room_eqFunction_72(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,72};
  data->simulationInfo->booleanVarsPre[28] /* thermostatControlPortTransformer1._turn_thermostat_onSignalHolder._y DISCRETE */ = data->localData[0]->booleanVars[28] /* thermostatControlPortTransformer1._turn_thermostat_onSignalHolder._y DISCRETE */;
  TRACE_POP
}

/*
 equation index: 73
 type: SIMPLE_ASSIGN
 thermostatControlPort1._turn_thermostat_on1._counter = if thermostatControlPortTransformer1.turn_thermostat_onSignalHolder.y then 1 else 0
 */
void Room_eqFunction_73(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,73};
  data->localData[0]->integerVars[8] /* thermostatControlPort1._turn_thermostat_on1._counter DISCRETE */ = (data->localData[0]->booleanVars[28] /* thermostatControlPortTransformer1._turn_thermostat_onSignalHolder._y DISCRETE */?((modelica_integer) 1):((modelica_integer) 0));
  TRACE_POP
}

/*
 equation index: 74
 type: SIMPLE_ASSIGN
 thermostatControlPortTransformer1._turn_thermostat_onSignalHolder._entryTime = 0.0
 */
void Room_eqFunction_74(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,74};
  data->localData[0]->realVars[47] /* thermostatControlPortTransformer1._turn_thermostat_onSignalHolder._entryTime DISCRETE */ = 0.0;
  TRACE_POP
}

/*
 equation index: 75
 type: SIMPLE_ASSIGN
 $PRE._thermostatControlPortTransformer1._turn_thermostat_onSignalHolder._entryTime = thermostatControlPortTransformer1.turn_thermostat_onSignalHolder.entryTime
 */
void Room_eqFunction_75(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,75};
  data->simulationInfo->realVarsPre[47] /* thermostatControlPortTransformer1._turn_thermostat_onSignalHolder._entryTime DISCRETE */ = data->localData[0]->realVars[47] /* thermostatControlPortTransformer1._turn_thermostat_onSignalHolder._entryTime DISCRETE */;
  TRACE_POP
}

/*
 equation index: 76
 type: SIMPLE_ASSIGN
 $whenCondition4 = 10.0 + thermostatControlPortTransformer1.turn_thermostat_onSignalHolder.entryTime < time
 */
void Room_eqFunction_76(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,76};
  modelica_boolean tmp4;
  tmp4 = Less(10.0 + data->localData[0]->realVars[47] /* thermostatControlPortTransformer1._turn_thermostat_onSignalHolder._entryTime DISCRETE */,data->localData[0]->timeValue);
  data->localData[0]->booleanVars[8] /* $whenCondition4 DISCRETE */ = tmp4;
  TRACE_POP
}

/*
 equation index: 77
 type: SIMPLE_ASSIGN
 $PRE._temperatureStreamPortTransformer1._measured_temperatureSignalHolder._u = $START.temperatureStreamPortTransformer1.measured_temperatureSignalHolder.u
 */
void Room_eqFunction_77(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,77};
  data->simulationInfo->booleanVarsPre[21] /* temperatureStreamPortTransformer1._measured_temperatureSignalHolder._u DISCRETE */ = data->modelData->booleanVarsData[21].attribute /* temperatureStreamPortTransformer1._measured_temperatureSignalHolder._u DISCRETE */.start;
  TRACE_POP
}

/*
 equation index: 78
 type: SIMPLE_ASSIGN
 temperatureStreamPortTransformer1._measured_temperatureSignalHolder._u = booleanConstant1.k
 */
void Room_eqFunction_78(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,78};
  data->localData[0]->booleanVars[21] /* temperatureStreamPortTransformer1._measured_temperatureSignalHolder._u DISCRETE */ = data->simulationInfo->booleanParameter[0];
  TRACE_POP
}

/*
 equation index: 79
 type: SIMPLE_ASSIGN
 $whenCondition8 = temperatureStreamPortTransformer1.measured_temperatureSignalHolder.u and not $PRE.temperatureStreamPortTransformer1.measured_temperatureSignalHolder.u
 */
void Room_eqFunction_79(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,79};
  data->localData[0]->booleanVars[12] /* $whenCondition8 DISCRETE */ = (data->localData[0]->booleanVars[21] /* temperatureStreamPortTransformer1._measured_temperatureSignalHolder._u DISCRETE */ && (!data->simulationInfo->booleanVarsPre[21] /* temperatureStreamPortTransformer1._measured_temperatureSignalHolder._u DISCRETE */));
  TRACE_POP
}

/*
 equation index: 80
 type: SIMPLE_ASSIGN
 temperatureStreamPortTransformer1._measured_temperatureSignalHolder._entryTime = 0.0
 */
void Room_eqFunction_80(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,80};
  data->localData[0]->realVars[44] /* temperatureStreamPortTransformer1._measured_temperatureSignalHolder._entryTime DISCRETE */ = 0.0;
  TRACE_POP
}

/*
 equation index: 81
 type: SIMPLE_ASSIGN
 $PRE._temperatureStreamPortTransformer1._measured_temperatureSignalHolder._entryTime = temperatureStreamPortTransformer1.measured_temperatureSignalHolder.entryTime
 */
void Room_eqFunction_81(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,81};
  data->simulationInfo->realVarsPre[44] /* temperatureStreamPortTransformer1._measured_temperatureSignalHolder._entryTime DISCRETE */ = data->localData[0]->realVars[44] /* temperatureStreamPortTransformer1._measured_temperatureSignalHolder._entryTime DISCRETE */;
  TRACE_POP
}

/*
 equation index: 82
 type: SIMPLE_ASSIGN
 $whenCondition7 = 10.0 + temperatureStreamPortTransformer1.measured_temperatureSignalHolder.entryTime < time
 */
void Room_eqFunction_82(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,82};
  modelica_boolean tmp5;
  tmp5 = Less(10.0 + data->localData[0]->realVars[44] /* temperatureStreamPortTransformer1._measured_temperatureSignalHolder._entryTime DISCRETE */,data->localData[0]->timeValue);
  data->localData[0]->booleanVars[11] /* $whenCondition7 DISCRETE */ = tmp5;
  TRACE_POP
}

/*
 equation index: 83
 type: SIMPLE_ASSIGN
 temperatureStreamPortTransformer1._measured_temperatureSignalHolder._y = false
 */
void Room_eqFunction_83(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,83};
  data->localData[0]->booleanVars[22] /* temperatureStreamPortTransformer1._measured_temperatureSignalHolder._y DISCRETE */ = 0;
  TRACE_POP
}

/*
 equation index: 84
 type: SIMPLE_ASSIGN
 $PRE._temperatureStreamPortTransformer1._measured_temperatureSignalHolder._y = temperatureStreamPortTransformer1.measured_temperatureSignalHolder.y
 */
void Room_eqFunction_84(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,84};
  data->simulationInfo->booleanVarsPre[22] /* temperatureStreamPortTransformer1._measured_temperatureSignalHolder._y DISCRETE */ = data->localData[0]->booleanVars[22] /* temperatureStreamPortTransformer1._measured_temperatureSignalHolder._y DISCRETE */;
  TRACE_POP
}

/*
 equation index: 85
 type: SIMPLE_ASSIGN
 $PRE._thermostatControlPortTransformer1._set_target_temperatureSignalHolder._u = $START.thermostatControlPortTransformer1.set_target_temperatureSignalHolder.u
 */
void Room_eqFunction_85(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,85};
  data->simulationInfo->booleanVarsPre[23] /* thermostatControlPortTransformer1._set_target_temperatureSignalHolder._u DISCRETE */ = data->modelData->booleanVarsData[23].attribute /* thermostatControlPortTransformer1._set_target_temperatureSignalHolder._u DISCRETE */.start;
  TRACE_POP
}

/*
 equation index: 86
 type: SIMPLE_ASSIGN
 thermostatControlPortTransformer1._set_target_temperatureSignalHolder._u = booleanConstant1.k
 */
void Room_eqFunction_86(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,86};
  data->localData[0]->booleanVars[23] /* thermostatControlPortTransformer1._set_target_temperatureSignalHolder._u DISCRETE */ = data->simulationInfo->booleanParameter[0];
  TRACE_POP
}

/*
 equation index: 87
 type: SIMPLE_ASSIGN
 $whenCondition6 = thermostatControlPortTransformer1.set_target_temperatureSignalHolder.u and not $PRE.thermostatControlPortTransformer1.set_target_temperatureSignalHolder.u
 */
void Room_eqFunction_87(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,87};
  data->localData[0]->booleanVars[10] /* $whenCondition6 DISCRETE */ = (data->localData[0]->booleanVars[23] /* thermostatControlPortTransformer1._set_target_temperatureSignalHolder._u DISCRETE */ && (!data->simulationInfo->booleanVarsPre[23] /* thermostatControlPortTransformer1._set_target_temperatureSignalHolder._u DISCRETE */));
  TRACE_POP
}

/*
 equation index: 88
 type: SIMPLE_ASSIGN
 thermostatControlPortTransformer1._set_target_temperatureSignalHolder._entryTime = 0.0
 */
void Room_eqFunction_88(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,88};
  data->localData[0]->realVars[45] /* thermostatControlPortTransformer1._set_target_temperatureSignalHolder._entryTime DISCRETE */ = 0.0;
  TRACE_POP
}

/*
 equation index: 89
 type: SIMPLE_ASSIGN
 $PRE._thermostatControlPortTransformer1._set_target_temperatureSignalHolder._entryTime = thermostatControlPortTransformer1.set_target_temperatureSignalHolder.entryTime
 */
void Room_eqFunction_89(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,89};
  data->simulationInfo->realVarsPre[45] /* thermostatControlPortTransformer1._set_target_temperatureSignalHolder._entryTime DISCRETE */ = data->localData[0]->realVars[45] /* thermostatControlPortTransformer1._set_target_temperatureSignalHolder._entryTime DISCRETE */;
  TRACE_POP
}

/*
 equation index: 90
 type: SIMPLE_ASSIGN
 $whenCondition5 = 10.0 + thermostatControlPortTransformer1.set_target_temperatureSignalHolder.entryTime < time
 */
void Room_eqFunction_90(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,90};
  modelica_boolean tmp6;
  tmp6 = Less(10.0 + data->localData[0]->realVars[45] /* thermostatControlPortTransformer1._set_target_temperatureSignalHolder._entryTime DISCRETE */,data->localData[0]->timeValue);
  data->localData[0]->booleanVars[9] /* $whenCondition5 DISCRETE */ = tmp6;
  TRACE_POP
}

/*
 equation index: 91
 type: SIMPLE_ASSIGN
 thermostatControlPortTransformer1._set_target_temperatureSignalHolder._y = false
 */
void Room_eqFunction_91(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,91};
  data->localData[0]->booleanVars[24] /* thermostatControlPortTransformer1._set_target_temperatureSignalHolder._y DISCRETE */ = 0;
  TRACE_POP
}

/*
 equation index: 92
 type: SIMPLE_ASSIGN
 $PRE._thermostatControlPortTransformer1._set_target_temperatureSignalHolder._y = thermostatControlPortTransformer1.set_target_temperatureSignalHolder.y
 */
void Room_eqFunction_92(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,92};
  data->simulationInfo->booleanVarsPre[24] /* thermostatControlPortTransformer1._set_target_temperatureSignalHolder._y DISCRETE */ = data->localData[0]->booleanVars[24] /* thermostatControlPortTransformer1._set_target_temperatureSignalHolder._y DISCRETE */;
  TRACE_POP
}

/*
 equation index: 93
 type: SIMPLE_ASSIGN
 $PRE._HeatingControlPortTransformer1._set_hysteresis_intervallumSignalHolder._u = $START.HeatingControlPortTransformer1.set_hysteresis_intervallumSignalHolder.u
 */
void Room_eqFunction_93(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,93};
  data->simulationInfo->booleanVarsPre[14] /* HeatingControlPortTransformer1._set_hysteresis_intervallumSignalHolder._u DISCRETE */ = data->modelData->booleanVarsData[14].attribute /* HeatingControlPortTransformer1._set_hysteresis_intervallumSignalHolder._u DISCRETE */.start;
  TRACE_POP
}

/*
 equation index: 94
 type: SIMPLE_ASSIGN
 HeatingControlPortTransformer1._set_hysteresis_intervallumSignalHolder._u = false
 */
void Room_eqFunction_94(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,94};
  data->localData[0]->booleanVars[14] /* HeatingControlPortTransformer1._set_hysteresis_intervallumSignalHolder._u DISCRETE */ = 0;
  TRACE_POP
}

/*
 equation index: 95
 type: SIMPLE_ASSIGN
 $whenCondition9 = HeatingControlPortTransformer1.set_hysteresis_intervallumSignalHolder.u and not $PRE.HeatingControlPortTransformer1.set_hysteresis_intervallumSignalHolder.u
 */
void Room_eqFunction_95(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,95};
  data->localData[0]->booleanVars[13] /* $whenCondition9 DISCRETE */ = (data->localData[0]->booleanVars[14] /* HeatingControlPortTransformer1._set_hysteresis_intervallumSignalHolder._u DISCRETE */ && (!data->simulationInfo->booleanVarsPre[14] /* HeatingControlPortTransformer1._set_hysteresis_intervallumSignalHolder._u DISCRETE */));
  TRACE_POP
}

/*
 equation index: 96
 type: SIMPLE_ASSIGN
 HeatingControlPortTransformer1._set_hysteresis_intervallumSignalHolder._entryTime = 0.0
 */
void Room_eqFunction_96(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,96};
  data->localData[0]->realVars[42] /* HeatingControlPortTransformer1._set_hysteresis_intervallumSignalHolder._entryTime DISCRETE */ = 0.0;
  TRACE_POP
}

/*
 equation index: 97
 type: SIMPLE_ASSIGN
 $PRE._HeatingControlPortTransformer1._set_hysteresis_intervallumSignalHolder._entryTime = HeatingControlPortTransformer1.set_hysteresis_intervallumSignalHolder.entryTime
 */
void Room_eqFunction_97(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,97};
  data->simulationInfo->realVarsPre[42] /* HeatingControlPortTransformer1._set_hysteresis_intervallumSignalHolder._entryTime DISCRETE */ = data->localData[0]->realVars[42] /* HeatingControlPortTransformer1._set_hysteresis_intervallumSignalHolder._entryTime DISCRETE */;
  TRACE_POP
}

/*
 equation index: 98
 type: SIMPLE_ASSIGN
 $whenCondition10 = 10.0 + HeatingControlPortTransformer1.set_hysteresis_intervallumSignalHolder.entryTime < time
 */
void Room_eqFunction_98(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,98};
  modelica_boolean tmp7;
  tmp7 = Less(10.0 + data->localData[0]->realVars[42] /* HeatingControlPortTransformer1._set_hysteresis_intervallumSignalHolder._entryTime DISCRETE */,data->localData[0]->timeValue);
  data->localData[0]->booleanVars[1] /* $whenCondition10 DISCRETE */ = tmp7;
  TRACE_POP
}

/*
 equation index: 99
 type: SIMPLE_ASSIGN
 HeatingControlPortTransformer1._set_hysteresis_intervallumSignalHolder._y = false
 */
void Room_eqFunction_99(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,99};
  data->localData[0]->booleanVars[15] /* HeatingControlPortTransformer1._set_hysteresis_intervallumSignalHolder._y DISCRETE */ = 0;
  TRACE_POP
}

/*
 equation index: 100
 type: SIMPLE_ASSIGN
 $PRE._HeatingControlPortTransformer1._set_hysteresis_intervallumSignalHolder._y = HeatingControlPortTransformer1.set_hysteresis_intervallumSignalHolder.y
 */
void Room_eqFunction_100(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,100};
  data->simulationInfo->booleanVarsPre[15] /* HeatingControlPortTransformer1._set_hysteresis_intervallumSignalHolder._y DISCRETE */ = data->localData[0]->booleanVars[15] /* HeatingControlPortTransformer1._set_hysteresis_intervallumSignalHolder._y DISCRETE */;
  TRACE_POP
}

/*
 equation index: 101
 type: SIMPLE_ASSIGN
 set_hysteresis_intervallum_tester1._y = 3.0
 */
void Room_eqFunction_101(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,101};
  data->localData[0]->realVars[43] /* set_hysteresis_intervallum_tester1._y DISCRETE */ = 3.0;
  TRACE_POP
}

/*
 equation index: 102
 type: SIMPLE_ASSIGN
 $PRE._set_hysteresis_intervallum_tester1._y = set_hysteresis_intervallum_tester1.y
 */
void Room_eqFunction_102(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,102};
  data->simulationInfo->realVarsPre[43] /* set_hysteresis_intervallum_tester1._y DISCRETE */ = data->localData[0]->realVars[43] /* set_hysteresis_intervallum_tester1._y DISCRETE */;
  TRACE_POP
}

/*
 equation index: 103
 type: SIMPLE_ASSIGN
 heatingControlPort1._set_hysteresis_intervallum1._hysteresis_intervallum[1] = set_hysteresis_intervallum_tester1.y
 */
void Room_eqFunction_103(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,103};
  data->localData[0]->realVars[14] /* heatingControlPort1._set_hysteresis_intervallum1._hysteresis_intervallum[1] variable */ = data->localData[0]->realVars[43] /* set_hysteresis_intervallum_tester1._y DISCRETE */;
  TRACE_POP
}

/*
 equation index: 104
 type: SIMPLE_ASSIGN
 $whenCondition11 = time > 1800.0
 */
void Room_eqFunction_104(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,104};
  modelica_boolean tmp8;
  tmp8 = Greater(data->localData[0]->timeValue,1800.0);
  data->localData[0]->booleanVars[2] /* $whenCondition11 DISCRETE */ = tmp8;
  TRACE_POP
}

/*
 equation index: 105
 type: SIMPLE_ASSIGN
 $whenCondition12 = time > 5400.0
 */
void Room_eqFunction_105(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,105};
  modelica_boolean tmp9;
  tmp9 = Greater(data->localData[0]->timeValue,5400.0);
  data->localData[0]->booleanVars[3] /* $whenCondition12 DISCRETE */ = tmp9;
  TRACE_POP
}

/*
 equation index: 106
 type: SIMPLE_ASSIGN
 $whenCondition13 = time > 9000.0
 */
void Room_eqFunction_106(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,106};
  modelica_boolean tmp10;
  tmp10 = Greater(data->localData[0]->timeValue,9000.0);
  data->localData[0]->booleanVars[4] /* $whenCondition13 DISCRETE */ = tmp10;
  TRACE_POP
}

/*
 equation index: 107
 type: SIMPLE_ASSIGN
 $whenCondition14 = time > 12600.0
 */
void Room_eqFunction_107(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,107};
  modelica_boolean tmp11;
  tmp11 = Greater(data->localData[0]->timeValue,12600.0);
  data->localData[0]->booleanVars[5] /* $whenCondition14 DISCRETE */ = tmp11;
  TRACE_POP
}

/*
 equation index: 108
 type: ALGORITHM
 
   assert(true, "If Medium.nXi > 1, then substance 'water' must be present for one component.'Air'.
 Check medium model.");
 */
void Room_eqFunction_108(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,108};
  static const MMC_DEFSTRINGLIT(tmp12,102,"If Medium.nXi > 1, then substance 'water' must be present for one component.'Air'.\nCheck medium model.");
  static int tmp13 = 0;
  {
    if(!1)
    {
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Buildings latest/Fluid/Interfaces/ConservationEquation.mo",166,3,169,34,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\ntrue", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_withEquationIndexes(threadData, info, equationIndexes, MMC_STRINGDATA(MMC_REFSTRINGLIT(tmp12)));
      }
    }
  }
  TRACE_POP
}
void Room_functionInitialEquations_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  Room_eqFunction_1(data, threadData);
  Room_eqFunction_2(data, threadData);
  Room_eqFunction_3(data, threadData);
  Room_eqFunction_4(data, threadData);
  Room_eqFunction_5(data, threadData);
  Room_eqFunction_6(data, threadData);
  Room_eqFunction_7(data, threadData);
  Room_eqFunction_8(data, threadData);
  Room_eqFunction_9(data, threadData);
  Room_eqFunction_10(data, threadData);
  Room_eqFunction_11(data, threadData);
  Room_eqFunction_12(data, threadData);
  Room_eqFunction_13(data, threadData);
  Room_eqFunction_14(data, threadData);
  Room_eqFunction_15(data, threadData);
  Room_eqFunction_16(data, threadData);
  Room_eqFunction_17(data, threadData);
  Room_eqFunction_18(data, threadData);
  Room_eqFunction_19(data, threadData);
  Room_eqFunction_20(data, threadData);
  Room_eqFunction_21(data, threadData);
  Room_eqFunction_22(data, threadData);
  Room_eqFunction_23(data, threadData);
  Room_eqFunction_24(data, threadData);
  Room_eqFunction_25(data, threadData);
  Room_eqFunction_26(data, threadData);
  Room_eqFunction_27(data, threadData);
  Room_eqFunction_28(data, threadData);
  Room_eqFunction_29(data, threadData);
  Room_eqFunction_30(data, threadData);
  Room_eqFunction_31(data, threadData);
  Room_eqFunction_32(data, threadData);
  Room_eqFunction_33(data, threadData);
  Room_eqFunction_34(data, threadData);
  Room_eqFunction_35(data, threadData);
  Room_eqFunction_36(data, threadData);
  Room_eqFunction_37(data, threadData);
  Room_eqFunction_38(data, threadData);
  Room_eqFunction_39(data, threadData);
  Room_eqFunction_40(data, threadData);
  Room_eqFunction_41(data, threadData);
  Room_eqFunction_42(data, threadData);
  Room_eqFunction_43(data, threadData);
  Room_eqFunction_44(data, threadData);
  Room_eqFunction_45(data, threadData);
  Room_eqFunction_46(data, threadData);
  Room_eqFunction_57(data, threadData);
  Room_eqFunction_58(data, threadData);
  Room_eqFunction_59(data, threadData);
  Room_eqFunction_60(data, threadData);
  Room_eqFunction_61(data, threadData);
  Room_eqFunction_62(data, threadData);
  Room_eqFunction_63(data, threadData);
  Room_eqFunction_64(data, threadData);
  Room_eqFunction_65(data, threadData);
  Room_eqFunction_66(data, threadData);
  Room_eqFunction_67(data, threadData);
  Room_eqFunction_68(data, threadData);
  Room_eqFunction_69(data, threadData);
  Room_eqFunction_70(data, threadData);
  Room_eqFunction_71(data, threadData);
  Room_eqFunction_72(data, threadData);
  Room_eqFunction_73(data, threadData);
  Room_eqFunction_74(data, threadData);
  Room_eqFunction_75(data, threadData);
  Room_eqFunction_76(data, threadData);
  Room_eqFunction_77(data, threadData);
  Room_eqFunction_78(data, threadData);
  Room_eqFunction_79(data, threadData);
  Room_eqFunction_80(data, threadData);
  Room_eqFunction_81(data, threadData);
  Room_eqFunction_82(data, threadData);
  Room_eqFunction_83(data, threadData);
  Room_eqFunction_84(data, threadData);
  Room_eqFunction_85(data, threadData);
  Room_eqFunction_86(data, threadData);
  Room_eqFunction_87(data, threadData);
  Room_eqFunction_88(data, threadData);
  Room_eqFunction_89(data, threadData);
  Room_eqFunction_90(data, threadData);
  Room_eqFunction_91(data, threadData);
  Room_eqFunction_92(data, threadData);
  Room_eqFunction_93(data, threadData);
  Room_eqFunction_94(data, threadData);
  Room_eqFunction_95(data, threadData);
  Room_eqFunction_96(data, threadData);
  Room_eqFunction_97(data, threadData);
  Room_eqFunction_98(data, threadData);
  Room_eqFunction_99(data, threadData);
  Room_eqFunction_100(data, threadData);
  Room_eqFunction_101(data, threadData);
  Room_eqFunction_102(data, threadData);
  Room_eqFunction_103(data, threadData);
  Room_eqFunction_104(data, threadData);
  Room_eqFunction_105(data, threadData);
  Room_eqFunction_106(data, threadData);
  Room_eqFunction_107(data, threadData);
  Room_eqFunction_108(data, threadData);
  TRACE_POP
}


int Room_functionInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  Room_functionInitialEquations_0(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}


int Room_functionInitialEquations_lambda0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}
int Room_functionRemovedInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int *equationIndexes = NULL;
  double res = 0.0;

  
  TRACE_POP
  return 0;
}


#if defined(__cplusplus)
}
#endif

