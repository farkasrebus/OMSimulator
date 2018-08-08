/* Main Simulation File */
#include "Room_model.h"


/* dummy VARINFO and FILEINFO */
const FILE_INFO dummyFILE_INFO = omc_dummyFileInfo;
const VAR_INFO dummyVAR_INFO = omc_dummyVarInfo;
#if defined(__cplusplus)
extern "C" {
#endif

int Room_input_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->localData[0]->integerVars[2] /* heatingControlPort1._turn_heating_off1._counter variable */ = data->simulationInfo->inputVars[0];
  data->localData[0]->integerVars[3] /* heatingControlPort1._turn_heating_on1._counter variable */ = data->simulationInfo->inputVars[1];
  
  TRACE_POP
  return 0;
}

int Room_input_function_init(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->inputVars[0] = data->modelData->integerVarsData[2].attribute.start;
  data->simulationInfo->inputVars[1] = data->modelData->integerVarsData[3].attribute.start;
  
  TRACE_POP
  return 0;
}

int Room_input_function_updateStartValues(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->modelData->integerVarsData[2].attribute.start = data->simulationInfo->inputVars[0];
  data->modelData->integerVarsData[3].attribute.start = data->simulationInfo->inputVars[1];
  
  TRACE_POP
  return 0;
}

int Room_inputNames(DATA *data, char ** names){
  TRACE_PUSH

  names[0] = (char *) data->modelData->integerVarsData[2].info.name;
  names[1] = (char *) data->modelData->integerVarsData[3].info.name;
  
  TRACE_POP
  return 0;
}

int Room_output_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->outputVars[0] = data->localData[0]->integerVars[1] /* heatingControlPort1._set_hysteresis_intervallum1._counter DISCRETE */;
  data->simulationInfo->outputVars[1] = data->localData[0]->realVars[14] /* heatingControlPort1._set_hysteresis_intervallum1._hysteresis_intervallum[1] variable */;
  data->simulationInfo->outputVars[2] = data->localData[0]->realVars[15] /* heatingControlPort1._set_hysteresis_intervallum1._hysteresis_intervallum[2] variable */;
  data->simulationInfo->outputVars[3] = data->localData[0]->realVars[16] /* heatingControlPort1._set_hysteresis_intervallum1._hysteresis_intervallum[3] variable */;
  data->simulationInfo->outputVars[4] = data->localData[0]->integerVars[4] /* temperatureStreamPort1._measured_temperature1._counter DISCRETE */;
  data->simulationInfo->outputVars[5] = data->localData[0]->realVars[18] /* temperatureStreamPort1._measured_temperature1._measured_temperature[1] variable */;
  data->simulationInfo->outputVars[6] = data->localData[0]->realVars[19] /* temperatureStreamPort1._measured_temperature1._measured_temperature[2] variable */;
  data->simulationInfo->outputVars[7] = data->localData[0]->realVars[20] /* temperatureStreamPort1._measured_temperature1._measured_temperature[3] variable */;
  data->simulationInfo->outputVars[8] = data->localData[0]->integerVars[6] /* thermostatControlPort1._set_target_temperature1._counter DISCRETE */;
  data->simulationInfo->outputVars[9] = data->localData[0]->realVars[23] /* thermostatControlPort1._set_target_temperature1._target_temperature[1] variable */;
  data->simulationInfo->outputVars[10] = data->localData[0]->realVars[24] /* thermostatControlPort1._set_target_temperature1._target_temperature[2] variable */;
  data->simulationInfo->outputVars[11] = data->localData[0]->realVars[25] /* thermostatControlPort1._set_target_temperature1._target_temperature[3] variable */;
  data->simulationInfo->outputVars[12] = data->localData[0]->integerVars[7] /* thermostatControlPort1._turn_thermostat_off1._counter DISCRETE */;
  data->simulationInfo->outputVars[13] = data->localData[0]->integerVars[8] /* thermostatControlPort1._turn_thermostat_on1._counter DISCRETE */;
  
  TRACE_POP
  return 0;
}


/*
 equation index: 109
 type: SIMPLE_ASSIGN
 der(vol._dynBal._mXi[1]) = 0.0
 */
void Room_eqFunction_109(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,109};
  data->localData[0]->realVars[8] /* der(vol._dynBal._mXi[1]) DUMMY_DER */ = 0.0;
  TRACE_POP
}
/*
 equation index: 110
 type: SIMPLE_ASSIGN
 $whenCondition11 = time > 1800.0
 */
void Room_eqFunction_110(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,110};
  modelica_boolean tmp259;
  RELATIONHYSTERESIS(tmp259, data->localData[0]->timeValue, 1800.0, 3, Greater);
  data->localData[0]->booleanVars[2] /* $whenCondition11 DISCRETE */ = tmp259;
  TRACE_POP
}
/*
 equation index: 111
 type: SIMPLE_ASSIGN
 $whenCondition12 = time > 5400.0
 */
void Room_eqFunction_111(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,111};
  modelica_boolean tmp260;
  RELATIONHYSTERESIS(tmp260, data->localData[0]->timeValue, 5400.0, 2, Greater);
  data->localData[0]->booleanVars[3] /* $whenCondition12 DISCRETE */ = tmp260;
  TRACE_POP
}
/*
 equation index: 112
 type: SIMPLE_ASSIGN
 $whenCondition13 = time > 9000.0
 */
void Room_eqFunction_112(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,112};
  modelica_boolean tmp261;
  RELATIONHYSTERESIS(tmp261, data->localData[0]->timeValue, 9000.0, 1, Greater);
  data->localData[0]->booleanVars[4] /* $whenCondition13 DISCRETE */ = tmp261;
  TRACE_POP
}
/*
 equation index: 113
 type: SIMPLE_ASSIGN
 $whenCondition14 = time > 12600.0
 */
void Room_eqFunction_113(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,113};
  modelica_boolean tmp262;
  RELATIONHYSTERESIS(tmp262, data->localData[0]->timeValue, 12600.0, 0, Greater);
  data->localData[0]->booleanVars[5] /* $whenCondition14 DISCRETE */ = tmp262;
  TRACE_POP
}
/*
 equation index: 114
 type: WHEN
 
 when {$whenCondition14, $whenCondition13, $whenCondition12, $whenCondition11} then
   set_hysteresis_intervallum_tester1._y = -0.5 + pre(set_hysteresis_intervallum_tester1.y);
 end when;
 */
void Room_eqFunction_114(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,114};
  if((data->localData[0]->booleanVars[5] /* $whenCondition14 DISCRETE */ && !data->simulationInfo->booleanVarsPre[5] /* $whenCondition14 DISCRETE */ /* edge */) || (data->localData[0]->booleanVars[4] /* $whenCondition13 DISCRETE */ && !data->simulationInfo->booleanVarsPre[4] /* $whenCondition13 DISCRETE */ /* edge */) || (data->localData[0]->booleanVars[3] /* $whenCondition12 DISCRETE */ && !data->simulationInfo->booleanVarsPre[3] /* $whenCondition12 DISCRETE */ /* edge */) || (data->localData[0]->booleanVars[2] /* $whenCondition11 DISCRETE */ && !data->simulationInfo->booleanVarsPre[2] /* $whenCondition11 DISCRETE */ /* edge */))
  {
    data->localData[0]->realVars[43] /* set_hysteresis_intervallum_tester1._y DISCRETE */ = -0.5 + data->simulationInfo->realVarsPre[43] /* set_hysteresis_intervallum_tester1._y DISCRETE */;
  }
  TRACE_POP
}
/*
 equation index: 115
 type: SIMPLE_ASSIGN
 heatingControlPort1._set_hysteresis_intervallum1._hysteresis_intervallum[1] = set_hysteresis_intervallum_tester1.y
 */
void Room_eqFunction_115(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,115};
  data->localData[0]->realVars[14] /* heatingControlPort1._set_hysteresis_intervallum1._hysteresis_intervallum[1] variable */ = data->localData[0]->realVars[43] /* set_hysteresis_intervallum_tester1._y DISCRETE */;
  TRACE_POP
}
/*
 equation index: 116
 type: SIMPLE_ASSIGN
 HeatingControlPortTransformer1._set_hysteresis_intervallumSignalHolder._u = sample(1, set_hysteresis_intervallum_tester1.sampleTrigger1.startTime, set_hysteresis_intervallum_tester1.sampleTrigger1.period)
 */
void Room_eqFunction_116(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,116};
  data->localData[0]->booleanVars[14] /* HeatingControlPortTransformer1._set_hysteresis_intervallumSignalHolder._u DISCRETE */ = data->simulationInfo->samples[0];
  TRACE_POP
}
/*
 equation index: 117
 type: SIMPLE_ASSIGN
 $whenCondition9 = HeatingControlPortTransformer1.set_hysteresis_intervallumSignalHolder.u and not pre(HeatingControlPortTransformer1.set_hysteresis_intervallumSignalHolder.u)
 */
void Room_eqFunction_117(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,117};
  data->localData[0]->booleanVars[13] /* $whenCondition9 DISCRETE */ = (data->localData[0]->booleanVars[14] /* HeatingControlPortTransformer1._set_hysteresis_intervallumSignalHolder._u DISCRETE */ && (!data->simulationInfo->booleanVarsPre[14] /* HeatingControlPortTransformer1._set_hysteresis_intervallumSignalHolder._u DISCRETE */));
  TRACE_POP
}
/*
 equation index: 118
 type: WHEN
 
 when {$whenCondition9} then
   HeatingControlPortTransformer1._set_hysteresis_intervallumSignalHolder._entryTime = time;
 end when;
 */
void Room_eqFunction_118(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,118};
  if((data->localData[0]->booleanVars[13] /* $whenCondition9 DISCRETE */ && !data->simulationInfo->booleanVarsPre[13] /* $whenCondition9 DISCRETE */ /* edge */))
  {
    data->localData[0]->realVars[42] /* HeatingControlPortTransformer1._set_hysteresis_intervallumSignalHolder._entryTime DISCRETE */ = data->localData[0]->timeValue;
  }
  TRACE_POP
}
/*
 equation index: 119
 type: SIMPLE_ASSIGN
 $whenCondition10 = 10.0 + HeatingControlPortTransformer1.set_hysteresis_intervallumSignalHolder.entryTime < time
 */
void Room_eqFunction_119(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,119};
  modelica_boolean tmp263;
  RELATIONHYSTERESIS(tmp263, 10.0 + data->localData[0]->realVars[42] /* HeatingControlPortTransformer1._set_hysteresis_intervallumSignalHolder._entryTime DISCRETE */, data->localData[0]->timeValue, 4, Less);
  data->localData[0]->booleanVars[1] /* $whenCondition10 DISCRETE */ = tmp263;
  TRACE_POP
}
/*
 equation index: 120
 type: WHEN
 
 when {$whenCondition9} then
   HeatingControlPortTransformer1._set_hysteresis_intervallumSignalHolder._y = true;
 end when;
 */
void Room_eqFunction_120(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,120};
  if((data->localData[0]->booleanVars[13] /* $whenCondition9 DISCRETE */ && !data->simulationInfo->booleanVarsPre[13] /* $whenCondition9 DISCRETE */ /* edge */))
  {
    data->localData[0]->booleanVars[15] /* HeatingControlPortTransformer1._set_hysteresis_intervallumSignalHolder._y DISCRETE */ = 1;
  }
  else if((data->localData[0]->booleanVars[1] /* $whenCondition10 DISCRETE */ && !data->simulationInfo->booleanVarsPre[1] /* $whenCondition10 DISCRETE */ /* edge */))
  {
    data->localData[0]->booleanVars[15] /* HeatingControlPortTransformer1._set_hysteresis_intervallumSignalHolder._y DISCRETE */ = 0;
  }
  TRACE_POP
}
/*
 equation index: 122
 type: SIMPLE_ASSIGN
 thermostatControlPortTransformer1._set_target_temperatureSignalHolder._u = booleanConstant1.k
 */
void Room_eqFunction_122(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,122};
  data->localData[0]->booleanVars[23] /* thermostatControlPortTransformer1._set_target_temperatureSignalHolder._u DISCRETE */ = data->simulationInfo->booleanParameter[0];
  TRACE_POP
}
/*
 equation index: 123
 type: SIMPLE_ASSIGN
 $whenCondition6 = thermostatControlPortTransformer1.set_target_temperatureSignalHolder.u and not pre(thermostatControlPortTransformer1.set_target_temperatureSignalHolder.u)
 */
void Room_eqFunction_123(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,123};
  data->localData[0]->booleanVars[10] /* $whenCondition6 DISCRETE */ = (data->localData[0]->booleanVars[23] /* thermostatControlPortTransformer1._set_target_temperatureSignalHolder._u DISCRETE */ && (!data->simulationInfo->booleanVarsPre[23] /* thermostatControlPortTransformer1._set_target_temperatureSignalHolder._u DISCRETE */));
  TRACE_POP
}
/*
 equation index: 124
 type: WHEN
 
 when {$whenCondition6} then
   thermostatControlPortTransformer1._set_target_temperatureSignalHolder._entryTime = time;
 end when;
 */
void Room_eqFunction_124(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,124};
  if((data->localData[0]->booleanVars[10] /* $whenCondition6 DISCRETE */ && !data->simulationInfo->booleanVarsPre[10] /* $whenCondition6 DISCRETE */ /* edge */))
  {
    data->localData[0]->realVars[45] /* thermostatControlPortTransformer1._set_target_temperatureSignalHolder._entryTime DISCRETE */ = data->localData[0]->timeValue;
  }
  TRACE_POP
}
/*
 equation index: 125
 type: SIMPLE_ASSIGN
 $whenCondition5 = 10.0 + thermostatControlPortTransformer1.set_target_temperatureSignalHolder.entryTime < time
 */
void Room_eqFunction_125(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,125};
  modelica_boolean tmp264;
  RELATIONHYSTERESIS(tmp264, 10.0 + data->localData[0]->realVars[45] /* thermostatControlPortTransformer1._set_target_temperatureSignalHolder._entryTime DISCRETE */, data->localData[0]->timeValue, 5, Less);
  data->localData[0]->booleanVars[9] /* $whenCondition5 DISCRETE */ = tmp264;
  TRACE_POP
}
/*
 equation index: 126
 type: WHEN
 
 when {$whenCondition6} then
   thermostatControlPortTransformer1._set_target_temperatureSignalHolder._y = true;
 end when;
 */
void Room_eqFunction_126(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,126};
  if((data->localData[0]->booleanVars[10] /* $whenCondition6 DISCRETE */ && !data->simulationInfo->booleanVarsPre[10] /* $whenCondition6 DISCRETE */ /* edge */))
  {
    data->localData[0]->booleanVars[24] /* thermostatControlPortTransformer1._set_target_temperatureSignalHolder._y DISCRETE */ = 1;
  }
  else if((data->localData[0]->booleanVars[9] /* $whenCondition5 DISCRETE */ && !data->simulationInfo->booleanVarsPre[9] /* $whenCondition5 DISCRETE */ /* edge */))
  {
    data->localData[0]->booleanVars[24] /* thermostatControlPortTransformer1._set_target_temperatureSignalHolder._y DISCRETE */ = 0;
  }
  TRACE_POP
}
/*
 equation index: 128
 type: SIMPLE_ASSIGN
 temperatureStreamPortTransformer1._measured_temperatureSignalHolder._u = booleanConstant1.k
 */
void Room_eqFunction_128(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,128};
  data->localData[0]->booleanVars[21] /* temperatureStreamPortTransformer1._measured_temperatureSignalHolder._u DISCRETE */ = data->simulationInfo->booleanParameter[0];
  TRACE_POP
}
/*
 equation index: 129
 type: SIMPLE_ASSIGN
 $whenCondition8 = temperatureStreamPortTransformer1.measured_temperatureSignalHolder.u and not pre(temperatureStreamPortTransformer1.measured_temperatureSignalHolder.u)
 */
void Room_eqFunction_129(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,129};
  data->localData[0]->booleanVars[12] /* $whenCondition8 DISCRETE */ = (data->localData[0]->booleanVars[21] /* temperatureStreamPortTransformer1._measured_temperatureSignalHolder._u DISCRETE */ && (!data->simulationInfo->booleanVarsPre[21] /* temperatureStreamPortTransformer1._measured_temperatureSignalHolder._u DISCRETE */));
  TRACE_POP
}
/*
 equation index: 130
 type: WHEN
 
 when {$whenCondition8} then
   temperatureStreamPortTransformer1._measured_temperatureSignalHolder._entryTime = time;
 end when;
 */
void Room_eqFunction_130(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,130};
  if((data->localData[0]->booleanVars[12] /* $whenCondition8 DISCRETE */ && !data->simulationInfo->booleanVarsPre[12] /* $whenCondition8 DISCRETE */ /* edge */))
  {
    data->localData[0]->realVars[44] /* temperatureStreamPortTransformer1._measured_temperatureSignalHolder._entryTime DISCRETE */ = data->localData[0]->timeValue;
  }
  TRACE_POP
}
/*
 equation index: 131
 type: SIMPLE_ASSIGN
 $whenCondition7 = 10.0 + temperatureStreamPortTransformer1.measured_temperatureSignalHolder.entryTime < time
 */
void Room_eqFunction_131(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,131};
  modelica_boolean tmp265;
  RELATIONHYSTERESIS(tmp265, 10.0 + data->localData[0]->realVars[44] /* temperatureStreamPortTransformer1._measured_temperatureSignalHolder._entryTime DISCRETE */, data->localData[0]->timeValue, 6, Less);
  data->localData[0]->booleanVars[11] /* $whenCondition7 DISCRETE */ = tmp265;
  TRACE_POP
}
/*
 equation index: 132
 type: WHEN
 
 when {$whenCondition8} then
   temperatureStreamPortTransformer1._measured_temperatureSignalHolder._y = true;
 end when;
 */
void Room_eqFunction_132(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,132};
  if((data->localData[0]->booleanVars[12] /* $whenCondition8 DISCRETE */ && !data->simulationInfo->booleanVarsPre[12] /* $whenCondition8 DISCRETE */ /* edge */))
  {
    data->localData[0]->booleanVars[22] /* temperatureStreamPortTransformer1._measured_temperatureSignalHolder._y DISCRETE */ = 1;
  }
  else if((data->localData[0]->booleanVars[11] /* $whenCondition7 DISCRETE */ && !data->simulationInfo->booleanVarsPre[11] /* $whenCondition7 DISCRETE */ /* edge */))
  {
    data->localData[0]->booleanVars[22] /* temperatureStreamPortTransformer1._measured_temperatureSignalHolder._y DISCRETE */ = 0;
  }
  TRACE_POP
}
/*
 equation index: 134
 type: SIMPLE_ASSIGN
 thermostatControlPortTransformer1._turn_thermostat_onSignalHolder._u = sample(3, sampleTrigger1.startTime, sampleTrigger1.period)
 */
void Room_eqFunction_134(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,134};
  data->localData[0]->booleanVars[27] /* thermostatControlPortTransformer1._turn_thermostat_onSignalHolder._u DISCRETE */ = data->simulationInfo->samples[2];
  TRACE_POP
}
/*
 equation index: 135
 type: SIMPLE_ASSIGN
 $whenCondition3 = thermostatControlPortTransformer1.turn_thermostat_onSignalHolder.u and not pre(thermostatControlPortTransformer1.turn_thermostat_onSignalHolder.u)
 */
void Room_eqFunction_135(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,135};
  data->localData[0]->booleanVars[7] /* $whenCondition3 DISCRETE */ = (data->localData[0]->booleanVars[27] /* thermostatControlPortTransformer1._turn_thermostat_onSignalHolder._u DISCRETE */ && (!data->simulationInfo->booleanVarsPre[27] /* thermostatControlPortTransformer1._turn_thermostat_onSignalHolder._u DISCRETE */));
  TRACE_POP
}
/*
 equation index: 136
 type: WHEN
 
 when {$whenCondition3} then
   thermostatControlPortTransformer1._turn_thermostat_onSignalHolder._entryTime = time;
 end when;
 */
void Room_eqFunction_136(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,136};
  if((data->localData[0]->booleanVars[7] /* $whenCondition3 DISCRETE */ && !data->simulationInfo->booleanVarsPre[7] /* $whenCondition3 DISCRETE */ /* edge */))
  {
    data->localData[0]->realVars[47] /* thermostatControlPortTransformer1._turn_thermostat_onSignalHolder._entryTime DISCRETE */ = data->localData[0]->timeValue;
  }
  TRACE_POP
}
/*
 equation index: 137
 type: SIMPLE_ASSIGN
 $whenCondition4 = 10.0 + thermostatControlPortTransformer1.turn_thermostat_onSignalHolder.entryTime < time
 */
void Room_eqFunction_137(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,137};
  modelica_boolean tmp266;
  RELATIONHYSTERESIS(tmp266, 10.0 + data->localData[0]->realVars[47] /* thermostatControlPortTransformer1._turn_thermostat_onSignalHolder._entryTime DISCRETE */, data->localData[0]->timeValue, 7, Less);
  data->localData[0]->booleanVars[8] /* $whenCondition4 DISCRETE */ = tmp266;
  TRACE_POP
}
/*
 equation index: 138
 type: WHEN
 
 when {$whenCondition3} then
   thermostatControlPortTransformer1._turn_thermostat_onSignalHolder._y = true;
 end when;
 */
void Room_eqFunction_138(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,138};
  if((data->localData[0]->booleanVars[7] /* $whenCondition3 DISCRETE */ && !data->simulationInfo->booleanVarsPre[7] /* $whenCondition3 DISCRETE */ /* edge */))
  {
    data->localData[0]->booleanVars[28] /* thermostatControlPortTransformer1._turn_thermostat_onSignalHolder._y DISCRETE */ = 1;
  }
  else if((data->localData[0]->booleanVars[8] /* $whenCondition4 DISCRETE */ && !data->simulationInfo->booleanVarsPre[8] /* $whenCondition4 DISCRETE */ /* edge */))
  {
    data->localData[0]->booleanVars[28] /* thermostatControlPortTransformer1._turn_thermostat_onSignalHolder._y DISCRETE */ = 0;
  }
  TRACE_POP
}
/*
 equation index: 140
 type: SIMPLE_ASSIGN
 thermostatControlPort1._turn_thermostat_on1._counter = if thermostatControlPortTransformer1.turn_thermostat_onSignalHolder.y then 1 else 0
 */
void Room_eqFunction_140(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,140};
  data->localData[0]->integerVars[8] /* thermostatControlPort1._turn_thermostat_on1._counter DISCRETE */ = (data->localData[0]->booleanVars[28] /* thermostatControlPortTransformer1._turn_thermostat_onSignalHolder._y DISCRETE */?((modelica_integer) 1):((modelica_integer) 0));
  TRACE_POP
}
/*
 equation index: 141
 type: SIMPLE_ASSIGN
 thermostatControlPortTransformer1._turn_thermostat_offSignalHolder._u = sample(2, sampleTrigger2.startTime, sampleTrigger2.period)
 */
void Room_eqFunction_141(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,141};
  data->localData[0]->booleanVars[25] /* thermostatControlPortTransformer1._turn_thermostat_offSignalHolder._u DISCRETE */ = data->simulationInfo->samples[1];
  TRACE_POP
}
/*
 equation index: 142
 type: SIMPLE_ASSIGN
 $whenCondition1 = thermostatControlPortTransformer1.turn_thermostat_offSignalHolder.u and not pre(thermostatControlPortTransformer1.turn_thermostat_offSignalHolder.u)
 */
void Room_eqFunction_142(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,142};
  data->localData[0]->booleanVars[0] /* $whenCondition1 DISCRETE */ = (data->localData[0]->booleanVars[25] /* thermostatControlPortTransformer1._turn_thermostat_offSignalHolder._u DISCRETE */ && (!data->simulationInfo->booleanVarsPre[25] /* thermostatControlPortTransformer1._turn_thermostat_offSignalHolder._u DISCRETE */));
  TRACE_POP
}
/*
 equation index: 143
 type: WHEN
 
 when {$whenCondition1} then
   thermostatControlPortTransformer1._turn_thermostat_offSignalHolder._entryTime = time;
 end when;
 */
void Room_eqFunction_143(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,143};
  if((data->localData[0]->booleanVars[0] /* $whenCondition1 DISCRETE */ && !data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */ /* edge */))
  {
    data->localData[0]->realVars[46] /* thermostatControlPortTransformer1._turn_thermostat_offSignalHolder._entryTime DISCRETE */ = data->localData[0]->timeValue;
  }
  TRACE_POP
}
/*
 equation index: 144
 type: SIMPLE_ASSIGN
 $whenCondition2 = 10.0 + thermostatControlPortTransformer1.turn_thermostat_offSignalHolder.entryTime < time
 */
void Room_eqFunction_144(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,144};
  modelica_boolean tmp267;
  RELATIONHYSTERESIS(tmp267, 10.0 + data->localData[0]->realVars[46] /* thermostatControlPortTransformer1._turn_thermostat_offSignalHolder._entryTime DISCRETE */, data->localData[0]->timeValue, 8, Less);
  data->localData[0]->booleanVars[6] /* $whenCondition2 DISCRETE */ = tmp267;
  TRACE_POP
}
/*
 equation index: 145
 type: WHEN
 
 when {$whenCondition1} then
   thermostatControlPortTransformer1._turn_thermostat_offSignalHolder._y = true;
 end when;
 */
void Room_eqFunction_145(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,145};
  if((data->localData[0]->booleanVars[0] /* $whenCondition1 DISCRETE */ && !data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */ /* edge */))
  {
    data->localData[0]->booleanVars[26] /* thermostatControlPortTransformer1._turn_thermostat_offSignalHolder._y DISCRETE */ = 1;
  }
  else if((data->localData[0]->booleanVars[6] /* $whenCondition2 DISCRETE */ && !data->simulationInfo->booleanVarsPre[6] /* $whenCondition2 DISCRETE */ /* edge */))
  {
    data->localData[0]->booleanVars[26] /* thermostatControlPortTransformer1._turn_thermostat_offSignalHolder._y DISCRETE */ = 0;
  }
  TRACE_POP
}
/*
 equation index: 147
 type: SIMPLE_ASSIGN
 thermostatControlPort1._turn_thermostat_off1._counter = if thermostatControlPortTransformer1.turn_thermostat_offSignalHolder.y then 1 else 0
 */
void Room_eqFunction_147(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,147};
  data->localData[0]->integerVars[7] /* thermostatControlPort1._turn_thermostat_off1._counter DISCRETE */ = (data->localData[0]->booleanVars[26] /* thermostatControlPortTransformer1._turn_thermostat_offSignalHolder._y DISCRETE */?((modelica_integer) 1):((modelica_integer) 0));
  TRACE_POP
}
/*
 equation index: 148
 type: SIMPLE_ASSIGN
 HeatingControlPortTransformer1._turn_heating_off = heatingControlPort1.turn_heating_off1.counter >= 1
 */
void Room_eqFunction_148(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,148};
  modelica_boolean tmp268;
  RELATION(tmp268, (modelica_integer)data->localData[0]->integerVars[2] /* heatingControlPort1._turn_heating_off1._counter variable */, ((modelica_integer) 1), 10, GreaterEq);
  data->localData[0]->booleanVars[16] /* HeatingControlPortTransformer1._turn_heating_off DISCRETE */ = tmp268;
  TRACE_POP
}
/*
 equation index: 149
 type: SIMPLE_ASSIGN
 HeatingControlPortTransformer1._turn_heating_on = heatingControlPort1.turn_heating_on1.counter >= 1
 */
void Room_eqFunction_149(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,149};
  modelica_boolean tmp269;
  RELATION(tmp269, (modelica_integer)data->localData[0]->integerVars[3] /* heatingControlPort1._turn_heating_on1._counter variable */, ((modelica_integer) 1), 9, GreaterEq);
  data->localData[0]->booleanVars[17] /* HeatingControlPortTransformer1._turn_heating_on DISCRETE */ = tmp269;
  TRACE_POP
}
/*
 equation index: 150
 type: SIMPLE_ASSIGN
 rSFlipFlop._QI = pre(rSFlipFlop.pre.u)
 */
void Room_eqFunction_150(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,150};
  data->localData[0]->booleanVars[19] /* rSFlipFlop._QI DISCRETE */ = data->simulationInfo->booleanVarsPre[20] /* rSFlipFlop._pre._u DISCRETE */;
  TRACE_POP
}
/*
 equation index: 151
 type: SIMPLE_ASSIGN
 booleanToReal1._u = not (rSFlipFlop.QI or HeatingControlPortTransformer1.turn_heating_off)
 */
void Room_eqFunction_151(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,151};
  data->localData[0]->booleanVars[18] /* booleanToReal1._u DISCRETE */ = (!(data->localData[0]->booleanVars[19] /* rSFlipFlop._QI DISCRETE */ || data->localData[0]->booleanVars[16] /* HeatingControlPortTransformer1._turn_heating_off DISCRETE */));
  TRACE_POP
}
/*
 equation index: 152
 type: SIMPLE_ASSIGN
 rSFlipFlop._pre._u = not (HeatingControlPortTransformer1.turn_heating_on or booleanToReal1.u)
 */
void Room_eqFunction_152(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,152};
  data->localData[0]->booleanVars[20] /* rSFlipFlop._pre._u DISCRETE */ = (!(data->localData[0]->booleanVars[17] /* HeatingControlPortTransformer1._turn_heating_on DISCRETE */ || data->localData[0]->booleanVars[18] /* booleanToReal1._u DISCRETE */));
  TRACE_POP
}
/*
 equation index: 153
 type: SIMPLE_ASSIGN
 booleanToReal1._y = if booleanToReal1.u then booleanToReal1.realTrue else booleanToReal1.realFalse
 */
void Room_eqFunction_153(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,153};
  data->localData[0]->realVars[10] /* booleanToReal1._y variable */ = (data->localData[0]->booleanVars[18] /* booleanToReal1._u DISCRETE */?data->simulationInfo->realParameter[5]:data->simulationInfo->realParameter[4]);
  TRACE_POP
}
/*
 equation index: 154
 type: SIMPLE_ASSIGN
 der(vol._dynBal._m) = 0.0
 */
void Room_eqFunction_154(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,154};
  data->localData[0]->realVars[3] /* der(vol._dynBal._m) STATE_DER */ = 0.0;
  TRACE_POP
}
/*
 equation index: 155
 type: SIMPLE_ASSIGN
 der(vol._dynBal._medium._Xi[1]) = DIVISION((-vol.dynBal.medium.Xi[1]) * der(vol.dynBal.m), vol.dynBal.m)
 */
void Room_eqFunction_155(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,155};
  data->localData[0]->realVars[4] /* der(vol._dynBal._medium._Xi[1]) STATE_DER */ = DIVISION_SIM(((-data->localData[0]->realVars[1] /* vol._dynBal._medium._Xi[1] STATE(1) */)) * (data->localData[0]->realVars[3] /* der(vol._dynBal._m) STATE_DER */),data->localData[0]->realVars[0] /* vol._dynBal._m STATE(1) */,"vol.dynBal.m",equationIndexes);
  TRACE_POP
}
/*
 equation index: 156
 type: SIMPLE_ASSIGN
 vol._dynBal._medium._p = (-vol.dynBal.m) / -0.002131754256106588
 */
void Room_eqFunction_156(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,156};
  modelica_real tmp270;
  tmp270 = -0.002131754256106588;
  if (tmp270 == 0) {throwStreamPrint(threadData, "Division by zero %s", "(-vol.dynBal.m) / -0.002131754256106588");}
  data->localData[0]->realVars[38] /* vol._dynBal._medium._p variable */ = ((-data->localData[0]->realVars[0] /* vol._dynBal._m STATE(1) */)) / tmp270;
  TRACE_POP
}
/*
 equation index: 157
 type: SIMPLE_ASSIGN
 vol._dynBal._medium._p_bar = 1e-05 * vol.dynBal.medium.p
 */
void Room_eqFunction_157(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,157};
  data->localData[0]->realVars[39] /* vol._dynBal._medium._p_bar variable */ = (1e-05) * (data->localData[0]->realVars[38] /* vol._dynBal._medium._p variable */);
  TRACE_POP
}
/*
 equation index: 158
 type: SIMPLE_ASSIGN
 vol._dynBal._medium._d = 1.184307920059215 * vol.dynBal.medium.p_bar
 */
void Room_eqFunction_158(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,158};
  data->localData[0]->realVars[36] /* vol._dynBal._medium._d variable */ = (1.184307920059215) * (data->localData[0]->realVars[39] /* vol._dynBal._medium._p_bar variable */);
  TRACE_POP
}
/*
 equation index: 159
 type: SIMPLE_ASSIGN
 vol._dynBal._medium._MM = DIVISION(1.0, 34.52428788658843 + 20.98414717520355 * vol.dynBal.medium.Xi[1])
 */
void Room_eqFunction_159(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,159};
  data->localData[0]->realVars[32] /* vol._dynBal._medium._MM variable */ = DIVISION_SIM(1.0,34.52428788658843 + (20.98414717520355) * (data->localData[0]->realVars[1] /* vol._dynBal._medium._Xi[1] STATE(1) */),"34.52428788658843 + 20.98414717520355 * vol.dynBal.medium.Xi[1]",equationIndexes);
  TRACE_POP
}
/*
 equation index: 160
 type: SIMPLE_ASSIGN
 vol._dynBal._medium._X[2] = 1.0 - (DIVISION(1.0, vol.dynBal.medium.MM * 20.98414717520355) - 1.645255706526159)
 */
void Room_eqFunction_160(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,160};
  data->localData[0]->realVars[35] /* vol._dynBal._medium._X[2] variable */ = 1.0 - (DIVISION_SIM(1.0,(data->localData[0]->realVars[32] /* vol._dynBal._medium._MM variable */) * (20.98414717520355),"vol.dynBal.medium.MM * 20.98414717520355",equationIndexes) - 1.645255706526159);
  TRACE_POP
}
/*
 equation index: 161
 type: SIMPLE_ASSIGN
 vol._dynBal._medium._dT = DIVISION(vol.hOut_internal - vol.dynBal.medium.Xi[1] * 2501014.5, 1006.0 * vol.dynBal.medium.X[2] + vol.dynBal.medium.Xi[1] * 1860.0)
 */
void Room_eqFunction_161(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,161};
  data->localData[0]->realVars[37] /* vol._dynBal._medium._dT variable */ = DIVISION_SIM(data->localData[0]->realVars[2] /* vol._hOut_internal STATE(1) */ - ((data->localData[0]->realVars[1] /* vol._dynBal._medium._Xi[1] STATE(1) */) * (2501014.5)),(1006.0) * (data->localData[0]->realVars[35] /* vol._dynBal._medium._X[2] variable */) + (data->localData[0]->realVars[1] /* vol._dynBal._medium._Xi[1] STATE(1) */) * (1860.0),"1006.0 * vol.dynBal.medium.X[2] + vol.dynBal.medium.Xi[1] * 1860.0",equationIndexes);
  TRACE_POP
}
/*
 equation index: 162
 type: SIMPLE_ASSIGN
 vol._dynBal._medium._T = vol.dynBal.medium.dT - -273.15
 */
void Room_eqFunction_162(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,162};
  data->localData[0]->realVars[34] /* vol._dynBal._medium._T variable */ = data->localData[0]->realVars[37] /* vol._dynBal._medium._dT variable */ - (-273.15);
  TRACE_POP
}
/*
 equation index: 163
 type: SIMPLE_ASSIGN
 vol._dynBal._medium._R = 287.0512249529787 * vol.dynBal.medium.X[2] + 461.5233290850878 * vol.dynBal.medium.Xi[1]
 */
void Room_eqFunction_163(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,163};
  data->localData[0]->realVars[33] /* vol._dynBal._medium._R variable */ = (287.0512249529787) * (data->localData[0]->realVars[35] /* vol._dynBal._medium._X[2] variable */) + (461.5233290850878) * (data->localData[0]->realVars[1] /* vol._dynBal._medium._Xi[1] STATE(1) */);
  TRACE_POP
}
/*
 equation index: 164
 type: SIMPLE_ASSIGN
 heaCap._T = 273.15 + DIVISION(vol.hOut_internal + -2501014.5 * vol.dynBal.medium.Xi[1], 1006.0 * (1.0 - vol.dynBal.medium.Xi[1]) + 1860.0 * vol.dynBal.medium.Xi[1])
 */
void Room_eqFunction_164(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,164};
  data->localData[0]->realVars[11] /* heaCap._T DUMMY_STATE */ = 273.15 + DIVISION_SIM(data->localData[0]->realVars[2] /* vol._hOut_internal STATE(1) */ + (-2501014.5) * (data->localData[0]->realVars[1] /* vol._dynBal._medium._Xi[1] STATE(1) */),(1006.0) * (1.0 - data->localData[0]->realVars[1] /* vol._dynBal._medium._Xi[1] STATE(1) */) + (1860.0) * (data->localData[0]->realVars[1] /* vol._dynBal._medium._Xi[1] STATE(1) */),"1006.0 * (1.0 - vol.dynBal.medium.Xi[1]) + 1860.0 * vol.dynBal.medium.Xi[1]",equationIndexes);
  TRACE_POP
}
/*
 equation index: 165
 type: SIMPLE_ASSIGN
 theCon._dT = TOut.T - heaCap.T
 */
void Room_eqFunction_165(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,165};
  data->localData[0]->realVars[22] /* theCon._dT variable */ = data->simulationInfo->realParameter[2] - data->localData[0]->realVars[11] /* heaCap._T DUMMY_STATE */;
  TRACE_POP
}
/*
 equation index: 166
 type: SIMPLE_ASSIGN
 theCon._Q_flow = theCon.G * theCon.dT
 */
void Room_eqFunction_166(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,166};
  data->localData[0]->realVars[21] /* theCon._Q_flow variable */ = (data->simulationInfo->realParameter[21]) * (data->localData[0]->realVars[22] /* theCon._dT variable */);
  TRACE_POP
}
/*
 equation index: 167
 type: SIMPLE_ASSIGN
 preHea._port._Q_flow = (-booleanToReal1.y) * (1.0 + preHea.alpha * (heaCap.T - preHea.T_ref))
 */
void Room_eqFunction_167(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,167};
  data->localData[0]->realVars[17] /* preHea._port._Q_flow variable */ = ((-data->localData[0]->realVars[10] /* booleanToReal1._y variable */)) * (1.0 + (data->simulationInfo->realParameter[10]) * (data->localData[0]->realVars[11] /* heaCap._T DUMMY_STATE */ - data->simulationInfo->realParameter[9]));
  TRACE_POP
}
/*
 equation index: 168
 type: SIMPLE_ASSIGN
 temperatureStreamPort1._measured_temperature1._measured_temperature[1] = -273.15 + heaCap.T
 */
void Room_eqFunction_168(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,168};
  data->localData[0]->realVars[18] /* temperatureStreamPort1._measured_temperature1._measured_temperature[1] variable */ = -273.15 + data->localData[0]->realVars[11] /* heaCap._T DUMMY_STATE */;
  TRACE_POP
}
/*
 equation index: 169
 type: SIMPLE_ASSIGN
 vol._dynBal._medium._u = -84437.5 + vol.hOut_internal
 */
void Room_eqFunction_169(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,169};
  data->localData[0]->realVars[40] /* vol._dynBal._medium._u DUMMY_STATE */ = -84437.5 + data->localData[0]->realVars[2] /* vol._hOut_internal STATE(1) */;
  TRACE_POP
}
/*
 equation index: 170
 type: SIMPLE_ASSIGN
 vol._dynBal._U = vol.dynBal.m * vol.dynBal.medium.u
 */
void Room_eqFunction_170(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,170};
  data->localData[0]->realVars[27] /* vol._dynBal._U DUMMY_STATE */ = (data->localData[0]->realVars[0] /* vol._dynBal._m STATE(1) */) * (data->localData[0]->realVars[40] /* vol._dynBal._medium._u DUMMY_STATE */);
  TRACE_POP
}
/*
 equation index: 179
 type: LINEAR
 
 <var>der(vol._dynBal._medium._u)</var>
 <row>

 </row>
 <matrix>
 </matrix>
 */
void Room_eqFunction_179(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,179};
  /* Linear equation system */
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving linear system 179 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  data->simulationInfo->linearSystemData[1].x[0] = data->localData[1]->realVars[9] /* der(vol._dynBal._medium._u) DUMMY_DER */;
  retValue = solve_linear_system(data, threadData, 1);
  
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,179};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving linear system 179 failed at time=%.15g.\nFor more information please use -lv LOG_LS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[9] /* der(vol._dynBal._medium._u) DUMMY_DER */ = data->simulationInfo->linearSystemData[1].x[0];
  TRACE_POP
}
/*
 equation index: 180
 type: SIMPLE_ASSIGN
 der(vol._dynBal._U) = vol.heatPort.Q_flow
 */
void Room_eqFunction_180(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,180};
  data->localData[0]->realVars[7] /* der(vol._dynBal._U) DUMMY_DER */ = data->localData[0]->realVars[41] /* vol._heatPort._Q_flow variable */;
  TRACE_POP
}
/*
 equation index: 181
 type: SIMPLE_ASSIGN
 der(heaCap._T) = heaCap.der_T
 */
void Room_eqFunction_181(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,181};
  data->localData[0]->realVars[6] /* der(heaCap._T) DUMMY_DER */ = data->localData[0]->realVars[12] /* heaCap._der_T variable */;
  TRACE_POP
}
/*
 equation index: 182
 type: SIMPLE_ASSIGN
 vol._dynBal._mXi[1] = vol.dynBal.medium.Xi[1] * vol.dynBal.m
 */
void Room_eqFunction_182(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,182};
  data->localData[0]->realVars[29] /* vol._dynBal._mXi[1] DUMMY_STATE */ = (data->localData[0]->realVars[1] /* vol._dynBal._medium._Xi[1] STATE(1) */) * (data->localData[0]->realVars[0] /* vol._dynBal._m STATE(1) */);
  TRACE_POP
}
/*
 equation index: 183
 type: SIMPLE_ASSIGN
 thermostatControlPort1._set_target_temperature1._target_temperature[1] = step1.offset + (if time < step1.startTime then 0.0 else step1.height)
 */
void Room_eqFunction_183(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,183};
  modelica_boolean tmp271;
  RELATIONHYSTERESIS(tmp271, data->localData[0]->timeValue, data->simulationInfo->realParameter[19], 11, Less);
  data->localData[0]->realVars[23] /* thermostatControlPort1._set_target_temperature1._target_temperature[1] variable */ = data->simulationInfo->realParameter[18] + (tmp271?0.0:data->simulationInfo->realParameter[17]);
  TRACE_POP
}
/*
 equation index: 184
 type: SIMPLE_ASSIGN
 heatingControlPort1._set_hysteresis_intervallum1._hysteresis_intervallum[3] = HeatingControlPortTransformer1.set_hysteresis_intervallum_hysteresis_intervallum_initial
 */
void Room_eqFunction_184(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,184};
  data->localData[0]->realVars[16] /* heatingControlPort1._set_hysteresis_intervallum1._hysteresis_intervallum[3] variable */ = data->simulationInfo->realParameter[0];
  TRACE_POP
}
/*
 equation index: 185
 type: SIMPLE_ASSIGN
 heatingControlPort1._set_hysteresis_intervallum1._hysteresis_intervallum[2] = HeatingControlPortTransformer1.set_hysteresis_intervallum_hysteresis_intervallum_initial
 */
void Room_eqFunction_185(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,185};
  data->localData[0]->realVars[15] /* heatingControlPort1._set_hysteresis_intervallum1._hysteresis_intervallum[2] variable */ = data->simulationInfo->realParameter[0];
  TRACE_POP
}
/*
 equation index: 186
 type: SIMPLE_ASSIGN
 heatingControlPort1._set_hysteresis_intervallum1._counter = 1
 */
void Room_eqFunction_186(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,186};
  data->localData[0]->integerVars[1] /* heatingControlPort1._set_hysteresis_intervallum1._counter DISCRETE */ = ((modelica_integer) 1);
  TRACE_POP
}
/*
 equation index: 187
 type: SIMPLE_ASSIGN
 temperatureStreamPort1._measured_temperature1._measured_temperature[3] = temperatureStreamPortTransformer1.measured_temperature_measured_temperature_initial
 */
void Room_eqFunction_187(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,187};
  data->localData[0]->realVars[20] /* temperatureStreamPort1._measured_temperature1._measured_temperature[3] variable */ = data->simulationInfo->realParameter[20];
  TRACE_POP
}
/*
 equation index: 188
 type: SIMPLE_ASSIGN
 temperatureStreamPort1._measured_temperature1._measured_temperature[2] = temperatureStreamPortTransformer1.measured_temperature_measured_temperature_initial
 */
void Room_eqFunction_188(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,188};
  data->localData[0]->realVars[19] /* temperatureStreamPort1._measured_temperature1._measured_temperature[2] variable */ = data->simulationInfo->realParameter[20];
  TRACE_POP
}
/*
 equation index: 189
 type: SIMPLE_ASSIGN
 temperatureStreamPort1._measured_temperature1._counter = 1
 */
void Room_eqFunction_189(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,189};
  data->localData[0]->integerVars[4] /* temperatureStreamPort1._measured_temperature1._counter DISCRETE */ = ((modelica_integer) 1);
  TRACE_POP
}
/*
 equation index: 190
 type: SIMPLE_ASSIGN
 thermostatControlPort1._set_target_temperature1._target_temperature[3] = thermostatControlPortTransformer1.set_target_temperature_target_temperature_initial
 */
void Room_eqFunction_190(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,190};
  data->localData[0]->realVars[25] /* thermostatControlPort1._set_target_temperature1._target_temperature[3] variable */ = data->simulationInfo->realParameter[22];
  TRACE_POP
}
/*
 equation index: 191
 type: SIMPLE_ASSIGN
 thermostatControlPort1._set_target_temperature1._target_temperature[2] = thermostatControlPortTransformer1.set_target_temperature_target_temperature_initial
 */
void Room_eqFunction_191(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,191};
  data->localData[0]->realVars[24] /* thermostatControlPort1._set_target_temperature1._target_temperature[2] variable */ = data->simulationInfo->realParameter[22];
  TRACE_POP
}
/*
 equation index: 192
 type: SIMPLE_ASSIGN
 thermostatControlPort1._set_target_temperature1._counter = 1
 */
void Room_eqFunction_192(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,192};
  data->localData[0]->integerVars[6] /* thermostatControlPort1._set_target_temperature1._counter DISCRETE */ = ((modelica_integer) 1);
  TRACE_POP
}
/*
 equation index: 196
 type: ALGORITHM
 
   assert(vol.dynBal.medium.p >= 0.0, "Pressure (= " + String(vol.dynBal.medium.p, 0, true, 6) + " Pa) of medium \"" + "Air" + "\" is negative
 (Temperature = " + String(vol.dynBal.medium.T, 0, true, 6) + " K)");
 */
void Room_eqFunction_196(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,196};
  modelica_boolean tmp272;
  static const MMC_DEFSTRINGLIT(tmp273,12,"Pressure (= ");
  modelica_string tmp274;
  static const MMC_DEFSTRINGLIT(tmp275,16," Pa) of medium \"");
  static const MMC_DEFSTRINGLIT(tmp276,3,"Air");
  static const MMC_DEFSTRINGLIT(tmp277,29,"\" is negative\n(Temperature = ");
  modelica_string tmp278;
  static const MMC_DEFSTRINGLIT(tmp279,3," K)");
  static int tmp280 = 0;
  modelica_metatype tmpMeta[6] __attribute__((unused)) = {0};
  {
    tmp272 = GreaterEq(data->localData[0]->realVars[38] /* vol._dynBal._medium._p variable */,0.0);
    if(!tmp272)
    {
      tmp274 = modelica_real_to_modelica_string(data->localData[0]->realVars[38] /* vol._dynBal._medium._p variable */, ((modelica_integer) 0), 1, ((modelica_integer) 6));
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp273),tmp274);
      tmpMeta[1] = stringAppend(tmpMeta[0],MMC_REFSTRINGLIT(tmp275));
      tmpMeta[2] = stringAppend(tmpMeta[1],MMC_REFSTRINGLIT(tmp276));
      tmpMeta[3] = stringAppend(tmpMeta[2],MMC_REFSTRINGLIT(tmp277));
      tmp278 = modelica_real_to_modelica_string(data->localData[0]->realVars[34] /* vol._dynBal._medium._T variable */, ((modelica_integer) 0), 1, ((modelica_integer) 6));
      tmpMeta[4] = stringAppend(tmpMeta[3],tmp278);
      tmpMeta[5] = stringAppend(tmpMeta[4],MMC_REFSTRINGLIT(tmp279));
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.2/Media/package.mo",4529,7,4530,76,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nvol.dynBal.medium.p >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_withEquationIndexes(threadData, info, equationIndexes, MMC_STRINGDATA(tmpMeta[5]));
      }
    }
  }
  TRACE_POP
}
/*
 equation index: 195
 type: ALGORITHM
 
   assert(vol.dynBal.medium.X[2] >= -1e-05 and vol.dynBal.medium.X[2] <= 1.00001, "Mass fraction X[2] = " + String(vol.dynBal.medium.X[2], 0, true, 6) + "of substance " + "air" + "
 of medium " + "Air" + " is not in the range 0..1");
 */
void Room_eqFunction_195(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,195};
  modelica_boolean tmp281;
  modelica_boolean tmp282;
  static const MMC_DEFSTRINGLIT(tmp283,21,"Mass fraction X[2] = ");
  modelica_string tmp284;
  static const MMC_DEFSTRINGLIT(tmp285,13,"of substance ");
  static const MMC_DEFSTRINGLIT(tmp286,3,"air");
  static const MMC_DEFSTRINGLIT(tmp287,11,"\nof medium ");
  static const MMC_DEFSTRINGLIT(tmp288,3,"Air");
  static const MMC_DEFSTRINGLIT(tmp289,25," is not in the range 0..1");
  static int tmp290 = 0;
  modelica_metatype tmpMeta[6] __attribute__((unused)) = {0};
  {
    tmp281 = GreaterEq(data->localData[0]->realVars[35] /* vol._dynBal._medium._X[2] variable */,-1e-05);
    tmp282 = LessEq(data->localData[0]->realVars[35] /* vol._dynBal._medium._X[2] variable */,1.00001);
    if(!(tmp281 && tmp282))
    {
      tmp284 = modelica_real_to_modelica_string(data->localData[0]->realVars[35] /* vol._dynBal._medium._X[2] variable */, ((modelica_integer) 0), 1, ((modelica_integer) 6));
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp283),tmp284);
      tmpMeta[1] = stringAppend(tmpMeta[0],MMC_REFSTRINGLIT(tmp285));
      tmpMeta[2] = stringAppend(tmpMeta[1],MMC_REFSTRINGLIT(tmp286));
      tmpMeta[3] = stringAppend(tmpMeta[2],MMC_REFSTRINGLIT(tmp287));
      tmpMeta[4] = stringAppend(tmpMeta[3],MMC_REFSTRINGLIT(tmp288));
      tmpMeta[5] = stringAppend(tmpMeta[4],MMC_REFSTRINGLIT(tmp289));
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.2/Media/package.mo",4521,11,4524,41,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nvol.dynBal.medium.X[2] >= -1e-05 and vol.dynBal.medium.X[2] <= 1.00001", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_withEquationIndexes(threadData, info, equationIndexes, MMC_STRINGDATA(tmpMeta[5]));
      }
    }
  }
  TRACE_POP
}
/*
 equation index: 194
 type: ALGORITHM
 
   assert(vol.dynBal.medium.Xi[1] >= -1e-05 and vol.dynBal.medium.Xi[1] <= 1.00001, "Mass fraction X[1] = " + String(vol.dynBal.medium.Xi[1], 0, true, 6) + "of substance " + "water" + "
 of medium " + "Air" + " is not in the range 0..1");
 */
void Room_eqFunction_194(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,194};
  modelica_boolean tmp291;
  modelica_boolean tmp292;
  static const MMC_DEFSTRINGLIT(tmp293,21,"Mass fraction X[1] = ");
  modelica_string tmp294;
  static const MMC_DEFSTRINGLIT(tmp295,13,"of substance ");
  static const MMC_DEFSTRINGLIT(tmp296,5,"water");
  static const MMC_DEFSTRINGLIT(tmp297,11,"\nof medium ");
  static const MMC_DEFSTRINGLIT(tmp298,3,"Air");
  static const MMC_DEFSTRINGLIT(tmp299,25," is not in the range 0..1");
  static int tmp300 = 0;
  modelica_metatype tmpMeta[6] __attribute__((unused)) = {0};
  {
    tmp291 = GreaterEq(data->localData[0]->realVars[1] /* vol._dynBal._medium._Xi[1] STATE(1) */,-1e-05);
    tmp292 = LessEq(data->localData[0]->realVars[1] /* vol._dynBal._medium._Xi[1] STATE(1) */,1.00001);
    if(!(tmp291 && tmp292))
    {
      tmp294 = modelica_real_to_modelica_string(data->localData[0]->realVars[1] /* vol._dynBal._medium._Xi[1] STATE(1) */, ((modelica_integer) 0), 1, ((modelica_integer) 6));
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp293),tmp294);
      tmpMeta[1] = stringAppend(tmpMeta[0],MMC_REFSTRINGLIT(tmp295));
      tmpMeta[2] = stringAppend(tmpMeta[1],MMC_REFSTRINGLIT(tmp296));
      tmpMeta[3] = stringAppend(tmpMeta[2],MMC_REFSTRINGLIT(tmp297));
      tmpMeta[4] = stringAppend(tmpMeta[3],MMC_REFSTRINGLIT(tmp298));
      tmpMeta[5] = stringAppend(tmpMeta[4],MMC_REFSTRINGLIT(tmp299));
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.2/Media/package.mo",4521,11,4524,41,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nvol.dynBal.medium.Xi[1] >= -1e-05 and vol.dynBal.medium.Xi[1] <= 1.00001", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_withEquationIndexes(threadData, info, equationIndexes, MMC_STRINGDATA(tmpMeta[5]));
      }
    }
  }
  TRACE_POP
}
/*
 equation index: 193
 type: ALGORITHM
 
   assert(vol.dynBal.medium.T >= 200.0 and vol.dynBal.medium.T <= 423.15, "
 Temperature T is not in the allowed range
 200.0 K <= (T =" + String(vol.dynBal.medium.T, 0, true, 6) + " K) <= 423.15 K
 required from medium model \"" + "Air" + "\".");
 */
void Room_eqFunction_193(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,193};
  modelica_boolean tmp301;
  modelica_boolean tmp302;
  static const MMC_DEFSTRINGLIT(tmp303,58,"\nTemperature T is not in the allowed range\n200.0 K <= (T =");
  modelica_string tmp304;
  static const MMC_DEFSTRINGLIT(tmp305,44," K) <= 423.15 K\nrequired from medium model \"");
  static const MMC_DEFSTRINGLIT(tmp306,3,"Air");
  static const MMC_DEFSTRINGLIT(tmp307,2,"\".");
  static int tmp308 = 0;
  modelica_metatype tmpMeta[4] __attribute__((unused)) = {0};
  {
    tmp301 = GreaterEq(data->localData[0]->realVars[34] /* vol._dynBal._medium._T variable */,200.0);
    tmp302 = LessEq(data->localData[0]->realVars[34] /* vol._dynBal._medium._T variable */,423.15);
    if(!(tmp301 && tmp302))
    {
      tmp304 = modelica_real_to_modelica_string(data->localData[0]->realVars[34] /* vol._dynBal._medium._T variable */, ((modelica_integer) 0), 1, ((modelica_integer) 6));
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp303),tmp304);
      tmpMeta[1] = stringAppend(tmpMeta[0],MMC_REFSTRINGLIT(tmp305));
      tmpMeta[2] = stringAppend(tmpMeta[1],MMC_REFSTRINGLIT(tmp306));
      tmpMeta[3] = stringAppend(tmpMeta[2],MMC_REFSTRINGLIT(tmp307));
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Buildings latest/Media/Air.mo",63,5,67,57,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nvol.dynBal.medium.T >= 200.0 and vol.dynBal.medium.T <= 423.15", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_withEquationIndexes(threadData, info, equationIndexes, MMC_STRINGDATA(tmpMeta[3]));
      }
    }
  }
  TRACE_POP
}


int Room_functionDAE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  int equationIndexes[1] = {0};
  modelica_metatype tmpMeta[4] __attribute__((unused)) = {0};
  
  data->simulationInfo->needToIterate = 0;
  data->simulationInfo->discreteCall = 1;
  Room_functionLocalKnownVars(data, threadData);
  Room_eqFunction_109(data, threadData);

  Room_eqFunction_110(data, threadData);

  Room_eqFunction_111(data, threadData);

  Room_eqFunction_112(data, threadData);

  Room_eqFunction_113(data, threadData);

  Room_eqFunction_114(data, threadData);

  Room_eqFunction_115(data, threadData);

  Room_eqFunction_116(data, threadData);

  Room_eqFunction_117(data, threadData);

  Room_eqFunction_118(data, threadData);

  Room_eqFunction_119(data, threadData);

  Room_eqFunction_120(data, threadData);

  Room_eqFunction_122(data, threadData);

  Room_eqFunction_123(data, threadData);

  Room_eqFunction_124(data, threadData);

  Room_eqFunction_125(data, threadData);

  Room_eqFunction_126(data, threadData);

  Room_eqFunction_128(data, threadData);

  Room_eqFunction_129(data, threadData);

  Room_eqFunction_130(data, threadData);

  Room_eqFunction_131(data, threadData);

  Room_eqFunction_132(data, threadData);

  Room_eqFunction_134(data, threadData);

  Room_eqFunction_135(data, threadData);

  Room_eqFunction_136(data, threadData);

  Room_eqFunction_137(data, threadData);

  Room_eqFunction_138(data, threadData);

  Room_eqFunction_140(data, threadData);

  Room_eqFunction_141(data, threadData);

  Room_eqFunction_142(data, threadData);

  Room_eqFunction_143(data, threadData);

  Room_eqFunction_144(data, threadData);

  Room_eqFunction_145(data, threadData);

  Room_eqFunction_147(data, threadData);

  Room_eqFunction_148(data, threadData);

  Room_eqFunction_149(data, threadData);

  Room_eqFunction_150(data, threadData);

  Room_eqFunction_151(data, threadData);

  Room_eqFunction_152(data, threadData);

  Room_eqFunction_153(data, threadData);

  Room_eqFunction_154(data, threadData);

  Room_eqFunction_155(data, threadData);

  Room_eqFunction_156(data, threadData);

  Room_eqFunction_157(data, threadData);

  Room_eqFunction_158(data, threadData);

  Room_eqFunction_159(data, threadData);

  Room_eqFunction_160(data, threadData);

  Room_eqFunction_161(data, threadData);

  Room_eqFunction_162(data, threadData);

  Room_eqFunction_163(data, threadData);

  Room_eqFunction_164(data, threadData);

  Room_eqFunction_165(data, threadData);

  Room_eqFunction_166(data, threadData);

  Room_eqFunction_167(data, threadData);

  Room_eqFunction_168(data, threadData);

  Room_eqFunction_169(data, threadData);

  Room_eqFunction_170(data, threadData);

  Room_eqFunction_179(data, threadData);

  Room_eqFunction_180(data, threadData);

  Room_eqFunction_181(data, threadData);

  Room_eqFunction_182(data, threadData);

  Room_eqFunction_183(data, threadData);

  Room_eqFunction_184(data, threadData);

  Room_eqFunction_185(data, threadData);

  Room_eqFunction_186(data, threadData);

  Room_eqFunction_187(data, threadData);

  Room_eqFunction_188(data, threadData);

  Room_eqFunction_189(data, threadData);

  Room_eqFunction_190(data, threadData);

  Room_eqFunction_191(data, threadData);

  Room_eqFunction_192(data, threadData);

  Room_eqFunction_196(data, threadData);

  Room_eqFunction_195(data, threadData);

  Room_eqFunction_194(data, threadData);

  Room_eqFunction_193(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}


int Room_functionLocalKnownVars(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


/* forwarded equations */
extern void Room_eqFunction_148(DATA* data, threadData_t *threadData);
extern void Room_eqFunction_150(DATA* data, threadData_t *threadData);
extern void Room_eqFunction_151(DATA* data, threadData_t *threadData);
extern void Room_eqFunction_153(DATA* data, threadData_t *threadData);
extern void Room_eqFunction_154(DATA* data, threadData_t *threadData);
extern void Room_eqFunction_155(DATA* data, threadData_t *threadData);
extern void Room_eqFunction_164(DATA* data, threadData_t *threadData);
extern void Room_eqFunction_165(DATA* data, threadData_t *threadData);
extern void Room_eqFunction_166(DATA* data, threadData_t *threadData);
extern void Room_eqFunction_167(DATA* data, threadData_t *threadData);
extern void Room_eqFunction_169(DATA* data, threadData_t *threadData);
extern void Room_eqFunction_179(DATA* data, threadData_t *threadData);

static void functionODE_system0(DATA *data, threadData_t *threadData)
{
  Room_eqFunction_148(data, threadData);

  Room_eqFunction_150(data, threadData);

  Room_eqFunction_151(data, threadData);

  Room_eqFunction_153(data, threadData);

  Room_eqFunction_154(data, threadData);

  Room_eqFunction_155(data, threadData);

  Room_eqFunction_164(data, threadData);

  Room_eqFunction_165(data, threadData);

  Room_eqFunction_166(data, threadData);

  Room_eqFunction_167(data, threadData);

  Room_eqFunction_169(data, threadData);

  Room_eqFunction_179(data, threadData);
}

int Room_functionODE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  data->simulationInfo->callStatistics.functionODE++;
  
  Room_functionLocalKnownVars(data, threadData);
  functionODE_system0(data, threadData);

  
  TRACE_POP
  return 0;
}

#ifdef FMU_EXPERIMENTAL
#endif
/* forward the main in the simulation runtime */
extern int _main_SimulationRuntime(int argc, char**argv, DATA *data, threadData_t *threadData);

#include "Room_12jac.h"
#include "Room_13opt.h"

struct OpenModelicaGeneratedFunctionCallbacks Room_callback = {
   NULL,
   NULL,
   NULL,
   Room_callExternalObjectDestructors,
   NULL,
   Room_initialLinearSystem,
   NULL,
   #if !defined(OMC_NO_STATESELECTION)
   Room_initializeStateSets,
   #else
   NULL,
   #endif
   Room_initializeDAEmodeData,
   Room_functionODE,
   Room_functionAlgebraics,
   Room_functionDAE,
   Room_functionLocalKnownVars,
   Room_input_function,
   Room_input_function_init,
   Room_input_function_updateStartValues,
   Room_output_function,
   Room_function_storeDelayed,
   Room_updateBoundVariableAttributes,
   Room_functionInitialEquations,
   0,
   Room_functionInitialEquations_lambda0,
   Room_functionRemovedInitialEquations,
   Room_updateBoundParameters,
   Room_checkForAsserts,
   Room_function_ZeroCrossingsEquations,
   Room_function_ZeroCrossings,
   Room_function_updateRelations,
   Room_checkForDiscreteChanges,
   Room_zeroCrossingDescription,
   Room_relationDescription,
   Room_function_initSample,
   Room_INDEX_JAC_A,
   Room_INDEX_JAC_B,
   Room_INDEX_JAC_C,
   Room_INDEX_JAC_D,
   Room_initialAnalyticJacobianA,
   Room_initialAnalyticJacobianB,
   Room_initialAnalyticJacobianC,
   Room_initialAnalyticJacobianD,
   Room_functionJacA_column,
   Room_functionJacB_column,
   Room_functionJacC_column,
   Room_functionJacD_column,
   Room_linear_model_frame,
   Room_linear_model_datarecovery_frame,
   Room_mayer,
   Room_lagrange,
   Room_pickUpBoundsForInputsInOptimization,
   Room_setInputData,
   Room_getTimeGrid,
   Room_symbolicInlineSystem,
   Room_function_initSynchronous,
   Room_function_updateSynchronous,
   Room_function_equationsSynchronous,
   Room_read_input_fmu
   #ifdef FMU_EXPERIMENTAL
   ,Room_functionODE_Partial
   ,Room_functionFMIJacobian
   #endif
   ,Room_inputNames


};

void Room_setupDataStruc(DATA *data, threadData_t *threadData)
{
  assertStreamPrint(threadData,0!=data, "Error while initialize Data");
  data->callback = &Room_callback;
  data->modelData->modelName = "Room";
  data->modelData->modelFilePrefix = "Room";
  data->modelData->resultFileName = NULL;
  data->modelData->modelDir = "/media/m_krisztian/Data/M_Krisztian/git/opencps-hungary/models/modelica/room_controller";
  data->modelData->modelGUID = "{6fd3eb57-df28-464a-834f-1522aa2e2e69}";
  data->modelData->initXMLData = NULL;
  data->modelData->modelDataXml.infoXMLData =
  #if defined(OMC_MINIMAL_METADATA)
    NULL;
  #else
  #include "Room_info.c"
  #endif
  ;
  
  data->modelData->nStates = 3;
  data->modelData->nVariablesReal = 48;
  data->modelData->nDiscreteReal = 6;
  data->modelData->nVariablesInteger = 10;
  data->modelData->nVariablesBoolean = 29;
  data->modelData->nVariablesString = 0;
  data->modelData->nParametersReal = 57;
  data->modelData->nParametersInteger = 10;
  data->modelData->nParametersBoolean = 11;
  data->modelData->nParametersString = 0;
  data->modelData->nInputVars = 2;
  data->modelData->nOutputVars = 14;
  
  data->modelData->nAliasReal = 54;
  data->modelData->nAliasInteger = 4;
  data->modelData->nAliasBoolean = 20;
  data->modelData->nAliasString = 0;
  
  data->modelData->nZeroCrossings = 12;
  data->modelData->nSamples = 3;
  data->modelData->nRelations = 12;
  data->modelData->nMathEvents = 0;
  data->modelData->nExtObjs = 0;
  data->modelData->modelDataXml.fileName = "Room_info.json";
  data->modelData->modelDataXml.modelInfoXmlLength = 0;
  data->modelData->modelDataXml.nFunctions = 61;
  data->modelData->modelDataXml.nProfileBlocks = 0;
  data->modelData->modelDataXml.nEquations = 312;
  data->modelData->nMixedSystems = 0;
  data->modelData->nLinearSystems = 2;
  data->modelData->nNonLinearSystems = 0;
  data->modelData->nStateSets = 0;
  data->modelData->nJacobians = 6;
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

