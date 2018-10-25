/* Events: Sample, Zero Crossings, Relations, Discrete Changes */
#include "Room_model.h"
#if defined(__cplusplus)
extern "C" {
#endif

/* Initializes the raw time events of the simulation using the now
   calcualted parameters. */
void Room_function_initSample(DATA *data, threadData_t *threadData)
{
  long i=0;
  /* sample 1 */
  data->modelData->samplesInfo[i].index = 1;
  data->modelData->samplesInfo[i].start = data->simulationInfo->realParameter[16];
  data->modelData->samplesInfo[i].interval = data->simulationInfo->realParameter[15];
  assertStreamPrint(threadData,data->modelData->samplesInfo[i].interval > 0.0, "sample-interval <= 0.0");
  i++;
  /* sample 2 */
  data->modelData->samplesInfo[i].index = 2;
  data->modelData->samplesInfo[i].start = data->simulationInfo->realParameter[14];
  data->modelData->samplesInfo[i].interval = data->simulationInfo->realParameter[13];
  assertStreamPrint(threadData,data->modelData->samplesInfo[i].interval > 0.0, "sample-interval <= 0.0");
  i++;
  /* sample 3 */
  data->modelData->samplesInfo[i].index = 3;
  data->modelData->samplesInfo[i].start = data->simulationInfo->realParameter[12];
  data->modelData->samplesInfo[i].interval = data->simulationInfo->realParameter[11];
  assertStreamPrint(threadData,data->modelData->samplesInfo[i].interval > 0.0, "sample-interval <= 0.0");
  i++;
}

const char *Room_zeroCrossingDescription(int i, int **out_EquationIndexes)
{
  static const char *res[] = {"time > 12600.0",
  "time > 9000.0",
  "time > 5400.0",
  "time > 1800.0",
  "10.0 + HeatingControlPortTransformer1.set_hysteresis_intervallumSignalHolder.entryTime < time",
  "10.0 + thermostatControlPortTransformer1.set_target_temperatureSignalHolder.entryTime < time",
  "10.0 + temperatureStreamPortTransformer1.measured_temperatureSignalHolder.entryTime < time",
  "10.0 + thermostatControlPortTransformer1.turn_thermostat_onSignalHolder.entryTime < time",
  "10.0 + thermostatControlPortTransformer1.turn_thermostat_offSignalHolder.entryTime < time",
  "heatingControlPort1.turn_heating_on1.counter >= 1",
  "heatingControlPort1.turn_heating_off1.counter >= 1",
  "time < step1.startTime"};
  static const int occurEqs0[] = {1,109};
  static const int occurEqs1[] = {1,112};
  static const int occurEqs2[] = {1,111};
  static const int occurEqs3[] = {1,110};
  static const int occurEqs4[] = {1,114};
  static const int occurEqs5[] = {1,110};
  static const int occurEqs6[] = {1,110};
  static const int occurEqs7[] = {1,115};
  static const int occurEqs8[] = {1,115};
  static const int occurEqs9[] = {1,149};
  static const int occurEqs10[] = {1,148};
  static const int occurEqs11[] = {1,109};
  static const int *occurEqs[] = {occurEqs0,occurEqs1,occurEqs2,occurEqs3,occurEqs4,occurEqs5,occurEqs6,occurEqs7,occurEqs8,occurEqs9,occurEqs10,occurEqs11};
  *out_EquationIndexes = (int*) occurEqs[i];
  return res[i];
}

/* forwarded equations */
extern void Room_eqFunction_116(DATA* data, threadData_t *threadData);
extern void Room_eqFunction_117(DATA* data, threadData_t *threadData);
extern void Room_eqFunction_122(DATA* data, threadData_t *threadData);
extern void Room_eqFunction_123(DATA* data, threadData_t *threadData);
extern void Room_eqFunction_128(DATA* data, threadData_t *threadData);
extern void Room_eqFunction_129(DATA* data, threadData_t *threadData);
extern void Room_eqFunction_134(DATA* data, threadData_t *threadData);
extern void Room_eqFunction_135(DATA* data, threadData_t *threadData);
extern void Room_eqFunction_141(DATA* data, threadData_t *threadData);
extern void Room_eqFunction_142(DATA* data, threadData_t *threadData);

int Room_function_ZeroCrossingsEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->callStatistics.functionZeroCrossingsEquations++;

  Room_eqFunction_116(data, threadData);

  Room_eqFunction_117(data, threadData);

  Room_eqFunction_122(data, threadData);

  Room_eqFunction_123(data, threadData);

  Room_eqFunction_128(data, threadData);

  Room_eqFunction_129(data, threadData);

  Room_eqFunction_134(data, threadData);

  Room_eqFunction_135(data, threadData);

  Room_eqFunction_141(data, threadData);

  Room_eqFunction_142(data, threadData);
  
  TRACE_POP
  return 0;
}

int Room_function_ZeroCrossings(DATA *data, threadData_t *threadData, double *gout)
{
  TRACE_PUSH
  modelica_boolean tmp1;
  modelica_boolean tmp2;
  modelica_boolean tmp3;
  modelica_boolean tmp4;
  modelica_boolean tmp5;
  modelica_boolean tmp6;
  modelica_boolean tmp7;
  modelica_boolean tmp8;
  modelica_boolean tmp9;
  modelica_boolean tmp10;
  modelica_boolean tmp11;
  modelica_boolean tmp12;
  
  data->simulationInfo->callStatistics.functionZeroCrossings++;
  
  tmp1 = GreaterZC(data->localData[0]->timeValue, 12600.0, data->simulationInfo->storedRelations[0]);
  gout[0] = (tmp1) ? 1 : -1;
  tmp2 = GreaterZC(data->localData[0]->timeValue, 9000.0, data->simulationInfo->storedRelations[1]);
  gout[1] = (tmp2) ? 1 : -1;
  tmp3 = GreaterZC(data->localData[0]->timeValue, 5400.0, data->simulationInfo->storedRelations[2]);
  gout[2] = (tmp3) ? 1 : -1;
  tmp4 = GreaterZC(data->localData[0]->timeValue, 1800.0, data->simulationInfo->storedRelations[3]);
  gout[3] = (tmp4) ? 1 : -1;
  tmp5 = LessZC(10.0 + data->localData[0]->realVars[42] /* HeatingControlPortTransformer1._set_hysteresis_intervallumSignalHolder._entryTime DISCRETE */, data->localData[0]->timeValue, data->simulationInfo->storedRelations[4]);
  gout[4] = (tmp5) ? 1 : -1;
  tmp6 = LessZC(10.0 + data->localData[0]->realVars[45] /* thermostatControlPortTransformer1._set_target_temperatureSignalHolder._entryTime DISCRETE */, data->localData[0]->timeValue, data->simulationInfo->storedRelations[5]);
  gout[5] = (tmp6) ? 1 : -1;
  tmp7 = LessZC(10.0 + data->localData[0]->realVars[44] /* temperatureStreamPortTransformer1._measured_temperatureSignalHolder._entryTime DISCRETE */, data->localData[0]->timeValue, data->simulationInfo->storedRelations[6]);
  gout[6] = (tmp7) ? 1 : -1;
  tmp8 = LessZC(10.0 + data->localData[0]->realVars[47] /* thermostatControlPortTransformer1._turn_thermostat_onSignalHolder._entryTime DISCRETE */, data->localData[0]->timeValue, data->simulationInfo->storedRelations[7]);
  gout[7] = (tmp8) ? 1 : -1;
  tmp9 = LessZC(10.0 + data->localData[0]->realVars[46] /* thermostatControlPortTransformer1._turn_thermostat_offSignalHolder._entryTime DISCRETE */, data->localData[0]->timeValue, data->simulationInfo->storedRelations[8]);
  gout[8] = (tmp9) ? 1 : -1;
  tmp10 = GreaterEq((modelica_integer)data->localData[0]->integerVars[3] /* heatingControlPort1._turn_heating_on1._counter variable */,((modelica_integer) 1));
  gout[9] = (tmp10) ? 1 : -1;
  tmp11 = GreaterEq((modelica_integer)data->localData[0]->integerVars[2] /* heatingControlPort1._turn_heating_off1._counter variable */,((modelica_integer) 1));
  gout[10] = (tmp11) ? 1 : -1;
  tmp12 = LessZC(data->localData[0]->timeValue, data->simulationInfo->realParameter[19], data->simulationInfo->storedRelations[11]);
  gout[11] = (tmp12) ? 1 : -1;
  
  TRACE_POP
  return 0;
}

const char *Room_relationDescription(int i)
{
  const char *res[] = {"time > 12600.0",
  "time > 9000.0",
  "time > 5400.0",
  "time > 1800.0",
  "10.0 + HeatingControlPortTransformer1.set_hysteresis_intervallumSignalHolder.entryTime < time",
  "10.0 + thermostatControlPortTransformer1.set_target_temperatureSignalHolder.entryTime < time",
  "10.0 + temperatureStreamPortTransformer1.measured_temperatureSignalHolder.entryTime < time",
  "10.0 + thermostatControlPortTransformer1.turn_thermostat_onSignalHolder.entryTime < time",
  "10.0 + thermostatControlPortTransformer1.turn_thermostat_offSignalHolder.entryTime < time",
  "heatingControlPort1.turn_heating_on1.counter >= 1",
  "heatingControlPort1.turn_heating_off1.counter >= 1",
  "time < step1.startTime"};
  return res[i];
}

int Room_function_updateRelations(DATA *data, threadData_t *threadData, int evalforZeroCross)
{
  TRACE_PUSH
  modelica_boolean tmp13;
  modelica_boolean tmp14;
  modelica_boolean tmp15;
  modelica_boolean tmp16;
  modelica_boolean tmp17;
  modelica_boolean tmp18;
  modelica_boolean tmp19;
  modelica_boolean tmp20;
  modelica_boolean tmp21;
  modelica_boolean tmp22;
  modelica_boolean tmp23;
  modelica_boolean tmp24;
  
  if(evalforZeroCross) {
    tmp13 = GreaterZC(data->localData[0]->timeValue, 12600.0, data->simulationInfo->storedRelations[0]);
    data->simulationInfo->relations[0] = tmp13;
    tmp14 = GreaterZC(data->localData[0]->timeValue, 9000.0, data->simulationInfo->storedRelations[1]);
    data->simulationInfo->relations[1] = tmp14;
    tmp15 = GreaterZC(data->localData[0]->timeValue, 5400.0, data->simulationInfo->storedRelations[2]);
    data->simulationInfo->relations[2] = tmp15;
    tmp16 = GreaterZC(data->localData[0]->timeValue, 1800.0, data->simulationInfo->storedRelations[3]);
    data->simulationInfo->relations[3] = tmp16;
    tmp17 = LessZC(10.0 + data->localData[0]->realVars[42] /* HeatingControlPortTransformer1._set_hysteresis_intervallumSignalHolder._entryTime DISCRETE */, data->localData[0]->timeValue, data->simulationInfo->storedRelations[4]);
    data->simulationInfo->relations[4] = tmp17;
    tmp18 = LessZC(10.0 + data->localData[0]->realVars[45] /* thermostatControlPortTransformer1._set_target_temperatureSignalHolder._entryTime DISCRETE */, data->localData[0]->timeValue, data->simulationInfo->storedRelations[5]);
    data->simulationInfo->relations[5] = tmp18;
    tmp19 = LessZC(10.0 + data->localData[0]->realVars[44] /* temperatureStreamPortTransformer1._measured_temperatureSignalHolder._entryTime DISCRETE */, data->localData[0]->timeValue, data->simulationInfo->storedRelations[6]);
    data->simulationInfo->relations[6] = tmp19;
    tmp20 = LessZC(10.0 + data->localData[0]->realVars[47] /* thermostatControlPortTransformer1._turn_thermostat_onSignalHolder._entryTime DISCRETE */, data->localData[0]->timeValue, data->simulationInfo->storedRelations[7]);
    data->simulationInfo->relations[7] = tmp20;
    tmp21 = LessZC(10.0 + data->localData[0]->realVars[46] /* thermostatControlPortTransformer1._turn_thermostat_offSignalHolder._entryTime DISCRETE */, data->localData[0]->timeValue, data->simulationInfo->storedRelations[8]);
    data->simulationInfo->relations[8] = tmp21;
    tmp22 = GreaterEq((modelica_integer)data->localData[0]->integerVars[3] /* heatingControlPort1._turn_heating_on1._counter variable */,((modelica_integer) 1));
    data->simulationInfo->relations[9] = tmp22;
    tmp23 = GreaterEq((modelica_integer)data->localData[0]->integerVars[2] /* heatingControlPort1._turn_heating_off1._counter variable */,((modelica_integer) 1));
    data->simulationInfo->relations[10] = tmp23;
    tmp24 = LessZC(data->localData[0]->timeValue, data->simulationInfo->realParameter[19], data->simulationInfo->storedRelations[11]);
    data->simulationInfo->relations[11] = tmp24;
  } else {
    data->simulationInfo->relations[0] = (data->localData[0]->timeValue > 12600.0);
    data->simulationInfo->relations[1] = (data->localData[0]->timeValue > 9000.0);
    data->simulationInfo->relations[2] = (data->localData[0]->timeValue > 5400.0);
    data->simulationInfo->relations[3] = (data->localData[0]->timeValue > 1800.0);
    data->simulationInfo->relations[4] = (10.0 + data->localData[0]->realVars[42] /* HeatingControlPortTransformer1._set_hysteresis_intervallumSignalHolder._entryTime DISCRETE */ < data->localData[0]->timeValue);
    data->simulationInfo->relations[5] = (10.0 + data->localData[0]->realVars[45] /* thermostatControlPortTransformer1._set_target_temperatureSignalHolder._entryTime DISCRETE */ < data->localData[0]->timeValue);
    data->simulationInfo->relations[6] = (10.0 + data->localData[0]->realVars[44] /* temperatureStreamPortTransformer1._measured_temperatureSignalHolder._entryTime DISCRETE */ < data->localData[0]->timeValue);
    data->simulationInfo->relations[7] = (10.0 + data->localData[0]->realVars[47] /* thermostatControlPortTransformer1._turn_thermostat_onSignalHolder._entryTime DISCRETE */ < data->localData[0]->timeValue);
    data->simulationInfo->relations[8] = (10.0 + data->localData[0]->realVars[46] /* thermostatControlPortTransformer1._turn_thermostat_offSignalHolder._entryTime DISCRETE */ < data->localData[0]->timeValue);
    data->simulationInfo->relations[9] = ((modelica_integer)data->localData[0]->integerVars[3] /* heatingControlPort1._turn_heating_on1._counter variable */ >= ((modelica_integer) 1));
    data->simulationInfo->relations[10] = ((modelica_integer)data->localData[0]->integerVars[2] /* heatingControlPort1._turn_heating_off1._counter variable */ >= ((modelica_integer) 1));
    data->simulationInfo->relations[11] = (data->localData[0]->timeValue < data->simulationInfo->realParameter[19]);
  }
  
  TRACE_POP
  return 0;
}

int Room_checkForDiscreteChanges(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  int needToIterate = 0;

  infoStreamPrint(LOG_EVENTS_V, 1, "check for discrete changes at time=%.12g", data->localData[0]->timeValue);
  if(data->localData[0]->integerVars[6] /* thermostatControlPort1._set_target_temperature1._counter DISCRETE */ != data->simulationInfo->integerVarsPre[6] /* thermostatControlPort1._set_target_temperature1._counter DISCRETE */)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: %s from %ld to %ld", data->modelData->integerVarsData[6].info /* thermostatControlPort1._set_target_temperature1._counter */.name, data->simulationInfo->integerVarsPre[6] /* thermostatControlPort1._set_target_temperature1._counter DISCRETE */, data->localData[0]->integerVars[6] /* thermostatControlPort1._set_target_temperature1._counter DISCRETE */);
    needToIterate = 1;
  }
  if(data->localData[0]->integerVars[4] /* temperatureStreamPort1._measured_temperature1._counter DISCRETE */ != data->simulationInfo->integerVarsPre[4] /* temperatureStreamPort1._measured_temperature1._counter DISCRETE */)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: %s from %ld to %ld", data->modelData->integerVarsData[4].info /* temperatureStreamPort1._measured_temperature1._counter */.name, data->simulationInfo->integerVarsPre[4] /* temperatureStreamPort1._measured_temperature1._counter DISCRETE */, data->localData[0]->integerVars[4] /* temperatureStreamPort1._measured_temperature1._counter DISCRETE */);
    needToIterate = 1;
  }
  if(data->localData[0]->integerVars[1] /* heatingControlPort1._set_hysteresis_intervallum1._counter DISCRETE */ != data->simulationInfo->integerVarsPre[1] /* heatingControlPort1._set_hysteresis_intervallum1._counter DISCRETE */)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: %s from %ld to %ld", data->modelData->integerVarsData[1].info /* heatingControlPort1._set_hysteresis_intervallum1._counter */.name, data->simulationInfo->integerVarsPre[1] /* heatingControlPort1._set_hysteresis_intervallum1._counter DISCRETE */, data->localData[0]->integerVars[1] /* heatingControlPort1._set_hysteresis_intervallum1._counter DISCRETE */);
    needToIterate = 1;
  }
  if(data->localData[0]->booleanVars[18] /* booleanToReal1._u DISCRETE */ != data->simulationInfo->booleanVarsPre[18] /* booleanToReal1._u DISCRETE */)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: %s from %d to %d", data->modelData->booleanVarsData[18].info /* booleanToReal1._u */.name, data->simulationInfo->booleanVarsPre[18] /* booleanToReal1._u DISCRETE */, data->localData[0]->booleanVars[18] /* booleanToReal1._u DISCRETE */);
    needToIterate = 1;
  }
  if(data->localData[0]->booleanVars[19] /* rSFlipFlop._QI DISCRETE */ != data->simulationInfo->booleanVarsPre[19] /* rSFlipFlop._QI DISCRETE */)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: %s from %d to %d", data->modelData->booleanVarsData[19].info /* rSFlipFlop._QI */.name, data->simulationInfo->booleanVarsPre[19] /* rSFlipFlop._QI DISCRETE */, data->localData[0]->booleanVars[19] /* rSFlipFlop._QI DISCRETE */);
    needToIterate = 1;
  }
  if(data->localData[0]->booleanVars[20] /* rSFlipFlop._pre._u DISCRETE */ != data->simulationInfo->booleanVarsPre[20] /* rSFlipFlop._pre._u DISCRETE */)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: %s from %d to %d", data->modelData->booleanVarsData[20].info /* rSFlipFlop._pre._u */.name, data->simulationInfo->booleanVarsPre[20] /* rSFlipFlop._pre._u DISCRETE */, data->localData[0]->booleanVars[20] /* rSFlipFlop._pre._u DISCRETE */);
    needToIterate = 1;
  }
  if(data->localData[0]->booleanVars[17] /* HeatingControlPortTransformer1._turn_heating_on DISCRETE */ != data->simulationInfo->booleanVarsPre[17] /* HeatingControlPortTransformer1._turn_heating_on DISCRETE */)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: %s from %d to %d", data->modelData->booleanVarsData[17].info /* HeatingControlPortTransformer1._turn_heating_on */.name, data->simulationInfo->booleanVarsPre[17] /* HeatingControlPortTransformer1._turn_heating_on DISCRETE */, data->localData[0]->booleanVars[17] /* HeatingControlPortTransformer1._turn_heating_on DISCRETE */);
    needToIterate = 1;
  }
  if(data->localData[0]->booleanVars[16] /* HeatingControlPortTransformer1._turn_heating_off DISCRETE */ != data->simulationInfo->booleanVarsPre[16] /* HeatingControlPortTransformer1._turn_heating_off DISCRETE */)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: %s from %d to %d", data->modelData->booleanVarsData[16].info /* HeatingControlPortTransformer1._turn_heating_off */.name, data->simulationInfo->booleanVarsPre[16] /* HeatingControlPortTransformer1._turn_heating_off DISCRETE */, data->localData[0]->booleanVars[16] /* HeatingControlPortTransformer1._turn_heating_off DISCRETE */);
    needToIterate = 1;
  }
  if(data->localData[0]->booleanVars[6] /* $whenCondition2 DISCRETE */ != data->simulationInfo->booleanVarsPre[6] /* $whenCondition2 DISCRETE */)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: %s from %d to %d", data->modelData->booleanVarsData[6].info /* $whenCondition2 */.name, data->simulationInfo->booleanVarsPre[6] /* $whenCondition2 DISCRETE */, data->localData[0]->booleanVars[6] /* $whenCondition2 DISCRETE */);
    needToIterate = 1;
  }
  if(data->localData[0]->booleanVars[0] /* $whenCondition1 DISCRETE */ != data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: %s from %d to %d", data->modelData->booleanVarsData[0].info /* $whenCondition1 */.name, data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */, data->localData[0]->booleanVars[0] /* $whenCondition1 DISCRETE */);
    needToIterate = 1;
  }
  if(data->localData[0]->integerVars[7] /* thermostatControlPort1._turn_thermostat_off1._counter DISCRETE */ != data->simulationInfo->integerVarsPre[7] /* thermostatControlPort1._turn_thermostat_off1._counter DISCRETE */)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: %s from %ld to %ld", data->modelData->integerVarsData[7].info /* thermostatControlPort1._turn_thermostat_off1._counter */.name, data->simulationInfo->integerVarsPre[7] /* thermostatControlPort1._turn_thermostat_off1._counter DISCRETE */, data->localData[0]->integerVars[7] /* thermostatControlPort1._turn_thermostat_off1._counter DISCRETE */);
    needToIterate = 1;
  }
  if(data->localData[0]->booleanVars[26] /* thermostatControlPortTransformer1._turn_thermostat_offSignalHolder._y DISCRETE */ != data->simulationInfo->booleanVarsPre[26] /* thermostatControlPortTransformer1._turn_thermostat_offSignalHolder._y DISCRETE */)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: %s from %d to %d", data->modelData->booleanVarsData[26].info /* thermostatControlPortTransformer1._turn_thermostat_offSignalHolder._y */.name, data->simulationInfo->booleanVarsPre[26] /* thermostatControlPortTransformer1._turn_thermostat_offSignalHolder._y DISCRETE */, data->localData[0]->booleanVars[26] /* thermostatControlPortTransformer1._turn_thermostat_offSignalHolder._y DISCRETE */);
    needToIterate = 1;
  }
  if(data->localData[0]->booleanVars[25] /* thermostatControlPortTransformer1._turn_thermostat_offSignalHolder._u DISCRETE */ != data->simulationInfo->booleanVarsPre[25] /* thermostatControlPortTransformer1._turn_thermostat_offSignalHolder._u DISCRETE */)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: %s from %d to %d", data->modelData->booleanVarsData[25].info /* thermostatControlPortTransformer1._turn_thermostat_offSignalHolder._u */.name, data->simulationInfo->booleanVarsPre[25] /* thermostatControlPortTransformer1._turn_thermostat_offSignalHolder._u DISCRETE */, data->localData[0]->booleanVars[25] /* thermostatControlPortTransformer1._turn_thermostat_offSignalHolder._u DISCRETE */);
    needToIterate = 1;
  }
  if(data->localData[0]->realVars[46] /* thermostatControlPortTransformer1._turn_thermostat_offSignalHolder._entryTime DISCRETE */ != data->simulationInfo->realVarsPre[46] /* thermostatControlPortTransformer1._turn_thermostat_offSignalHolder._entryTime DISCRETE */)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: %s from %g to %g", data->modelData->realVarsData[46].info /* thermostatControlPortTransformer1._turn_thermostat_offSignalHolder._entryTime */.name, data->simulationInfo->realVarsPre[46] /* thermostatControlPortTransformer1._turn_thermostat_offSignalHolder._entryTime DISCRETE */, data->localData[0]->realVars[46] /* thermostatControlPortTransformer1._turn_thermostat_offSignalHolder._entryTime DISCRETE */);
    needToIterate = 1;
  }
  if(data->localData[0]->booleanVars[8] /* $whenCondition4 DISCRETE */ != data->simulationInfo->booleanVarsPre[8] /* $whenCondition4 DISCRETE */)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: %s from %d to %d", data->modelData->booleanVarsData[8].info /* $whenCondition4 */.name, data->simulationInfo->booleanVarsPre[8] /* $whenCondition4 DISCRETE */, data->localData[0]->booleanVars[8] /* $whenCondition4 DISCRETE */);
    needToIterate = 1;
  }
  if(data->localData[0]->booleanVars[7] /* $whenCondition3 DISCRETE */ != data->simulationInfo->booleanVarsPre[7] /* $whenCondition3 DISCRETE */)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: %s from %d to %d", data->modelData->booleanVarsData[7].info /* $whenCondition3 */.name, data->simulationInfo->booleanVarsPre[7] /* $whenCondition3 DISCRETE */, data->localData[0]->booleanVars[7] /* $whenCondition3 DISCRETE */);
    needToIterate = 1;
  }
  if(data->localData[0]->integerVars[8] /* thermostatControlPort1._turn_thermostat_on1._counter DISCRETE */ != data->simulationInfo->integerVarsPre[8] /* thermostatControlPort1._turn_thermostat_on1._counter DISCRETE */)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: %s from %ld to %ld", data->modelData->integerVarsData[8].info /* thermostatControlPort1._turn_thermostat_on1._counter */.name, data->simulationInfo->integerVarsPre[8] /* thermostatControlPort1._turn_thermostat_on1._counter DISCRETE */, data->localData[0]->integerVars[8] /* thermostatControlPort1._turn_thermostat_on1._counter DISCRETE */);
    needToIterate = 1;
  }
  if(data->localData[0]->booleanVars[28] /* thermostatControlPortTransformer1._turn_thermostat_onSignalHolder._y DISCRETE */ != data->simulationInfo->booleanVarsPre[28] /* thermostatControlPortTransformer1._turn_thermostat_onSignalHolder._y DISCRETE */)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: %s from %d to %d", data->modelData->booleanVarsData[28].info /* thermostatControlPortTransformer1._turn_thermostat_onSignalHolder._y */.name, data->simulationInfo->booleanVarsPre[28] /* thermostatControlPortTransformer1._turn_thermostat_onSignalHolder._y DISCRETE */, data->localData[0]->booleanVars[28] /* thermostatControlPortTransformer1._turn_thermostat_onSignalHolder._y DISCRETE */);
    needToIterate = 1;
  }
  if(data->localData[0]->booleanVars[27] /* thermostatControlPortTransformer1._turn_thermostat_onSignalHolder._u DISCRETE */ != data->simulationInfo->booleanVarsPre[27] /* thermostatControlPortTransformer1._turn_thermostat_onSignalHolder._u DISCRETE */)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: %s from %d to %d", data->modelData->booleanVarsData[27].info /* thermostatControlPortTransformer1._turn_thermostat_onSignalHolder._u */.name, data->simulationInfo->booleanVarsPre[27] /* thermostatControlPortTransformer1._turn_thermostat_onSignalHolder._u DISCRETE */, data->localData[0]->booleanVars[27] /* thermostatControlPortTransformer1._turn_thermostat_onSignalHolder._u DISCRETE */);
    needToIterate = 1;
  }
  if(data->localData[0]->realVars[47] /* thermostatControlPortTransformer1._turn_thermostat_onSignalHolder._entryTime DISCRETE */ != data->simulationInfo->realVarsPre[47] /* thermostatControlPortTransformer1._turn_thermostat_onSignalHolder._entryTime DISCRETE */)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: %s from %g to %g", data->modelData->realVarsData[47].info /* thermostatControlPortTransformer1._turn_thermostat_onSignalHolder._entryTime */.name, data->simulationInfo->realVarsPre[47] /* thermostatControlPortTransformer1._turn_thermostat_onSignalHolder._entryTime DISCRETE */, data->localData[0]->realVars[47] /* thermostatControlPortTransformer1._turn_thermostat_onSignalHolder._entryTime DISCRETE */);
    needToIterate = 1;
  }
  if(data->localData[0]->booleanVars[11] /* $whenCondition7 DISCRETE */ != data->simulationInfo->booleanVarsPre[11] /* $whenCondition7 DISCRETE */)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: %s from %d to %d", data->modelData->booleanVarsData[11].info /* $whenCondition7 */.name, data->simulationInfo->booleanVarsPre[11] /* $whenCondition7 DISCRETE */, data->localData[0]->booleanVars[11] /* $whenCondition7 DISCRETE */);
    needToIterate = 1;
  }
  if(data->localData[0]->booleanVars[12] /* $whenCondition8 DISCRETE */ != data->simulationInfo->booleanVarsPre[12] /* $whenCondition8 DISCRETE */)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: %s from %d to %d", data->modelData->booleanVarsData[12].info /* $whenCondition8 */.name, data->simulationInfo->booleanVarsPre[12] /* $whenCondition8 DISCRETE */, data->localData[0]->booleanVars[12] /* $whenCondition8 DISCRETE */);
    needToIterate = 1;
  }
  if(data->localData[0]->booleanVars[22] /* temperatureStreamPortTransformer1._measured_temperatureSignalHolder._y DISCRETE */ != data->simulationInfo->booleanVarsPre[22] /* temperatureStreamPortTransformer1._measured_temperatureSignalHolder._y DISCRETE */)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: %s from %d to %d", data->modelData->booleanVarsData[22].info /* temperatureStreamPortTransformer1._measured_temperatureSignalHolder._y */.name, data->simulationInfo->booleanVarsPre[22] /* temperatureStreamPortTransformer1._measured_temperatureSignalHolder._y DISCRETE */, data->localData[0]->booleanVars[22] /* temperatureStreamPortTransformer1._measured_temperatureSignalHolder._y DISCRETE */);
    needToIterate = 1;
  }
  if(data->localData[0]->booleanVars[21] /* temperatureStreamPortTransformer1._measured_temperatureSignalHolder._u DISCRETE */ != data->simulationInfo->booleanVarsPre[21] /* temperatureStreamPortTransformer1._measured_temperatureSignalHolder._u DISCRETE */)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: %s from %d to %d", data->modelData->booleanVarsData[21].info /* temperatureStreamPortTransformer1._measured_temperatureSignalHolder._u */.name, data->simulationInfo->booleanVarsPre[21] /* temperatureStreamPortTransformer1._measured_temperatureSignalHolder._u DISCRETE */, data->localData[0]->booleanVars[21] /* temperatureStreamPortTransformer1._measured_temperatureSignalHolder._u DISCRETE */);
    needToIterate = 1;
  }
  if(data->localData[0]->realVars[44] /* temperatureStreamPortTransformer1._measured_temperatureSignalHolder._entryTime DISCRETE */ != data->simulationInfo->realVarsPre[44] /* temperatureStreamPortTransformer1._measured_temperatureSignalHolder._entryTime DISCRETE */)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: %s from %g to %g", data->modelData->realVarsData[44].info /* temperatureStreamPortTransformer1._measured_temperatureSignalHolder._entryTime */.name, data->simulationInfo->realVarsPre[44] /* temperatureStreamPortTransformer1._measured_temperatureSignalHolder._entryTime DISCRETE */, data->localData[0]->realVars[44] /* temperatureStreamPortTransformer1._measured_temperatureSignalHolder._entryTime DISCRETE */);
    needToIterate = 1;
  }
  if(data->localData[0]->booleanVars[9] /* $whenCondition5 DISCRETE */ != data->simulationInfo->booleanVarsPre[9] /* $whenCondition5 DISCRETE */)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: %s from %d to %d", data->modelData->booleanVarsData[9].info /* $whenCondition5 */.name, data->simulationInfo->booleanVarsPre[9] /* $whenCondition5 DISCRETE */, data->localData[0]->booleanVars[9] /* $whenCondition5 DISCRETE */);
    needToIterate = 1;
  }
  if(data->localData[0]->booleanVars[10] /* $whenCondition6 DISCRETE */ != data->simulationInfo->booleanVarsPre[10] /* $whenCondition6 DISCRETE */)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: %s from %d to %d", data->modelData->booleanVarsData[10].info /* $whenCondition6 */.name, data->simulationInfo->booleanVarsPre[10] /* $whenCondition6 DISCRETE */, data->localData[0]->booleanVars[10] /* $whenCondition6 DISCRETE */);
    needToIterate = 1;
  }
  if(data->localData[0]->booleanVars[24] /* thermostatControlPortTransformer1._set_target_temperatureSignalHolder._y DISCRETE */ != data->simulationInfo->booleanVarsPre[24] /* thermostatControlPortTransformer1._set_target_temperatureSignalHolder._y DISCRETE */)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: %s from %d to %d", data->modelData->booleanVarsData[24].info /* thermostatControlPortTransformer1._set_target_temperatureSignalHolder._y */.name, data->simulationInfo->booleanVarsPre[24] /* thermostatControlPortTransformer1._set_target_temperatureSignalHolder._y DISCRETE */, data->localData[0]->booleanVars[24] /* thermostatControlPortTransformer1._set_target_temperatureSignalHolder._y DISCRETE */);
    needToIterate = 1;
  }
  if(data->localData[0]->booleanVars[23] /* thermostatControlPortTransformer1._set_target_temperatureSignalHolder._u DISCRETE */ != data->simulationInfo->booleanVarsPre[23] /* thermostatControlPortTransformer1._set_target_temperatureSignalHolder._u DISCRETE */)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: %s from %d to %d", data->modelData->booleanVarsData[23].info /* thermostatControlPortTransformer1._set_target_temperatureSignalHolder._u */.name, data->simulationInfo->booleanVarsPre[23] /* thermostatControlPortTransformer1._set_target_temperatureSignalHolder._u DISCRETE */, data->localData[0]->booleanVars[23] /* thermostatControlPortTransformer1._set_target_temperatureSignalHolder._u DISCRETE */);
    needToIterate = 1;
  }
  if(data->localData[0]->realVars[45] /* thermostatControlPortTransformer1._set_target_temperatureSignalHolder._entryTime DISCRETE */ != data->simulationInfo->realVarsPre[45] /* thermostatControlPortTransformer1._set_target_temperatureSignalHolder._entryTime DISCRETE */)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: %s from %g to %g", data->modelData->realVarsData[45].info /* thermostatControlPortTransformer1._set_target_temperatureSignalHolder._entryTime */.name, data->simulationInfo->realVarsPre[45] /* thermostatControlPortTransformer1._set_target_temperatureSignalHolder._entryTime DISCRETE */, data->localData[0]->realVars[45] /* thermostatControlPortTransformer1._set_target_temperatureSignalHolder._entryTime DISCRETE */);
    needToIterate = 1;
  }
  if(data->localData[0]->booleanVars[1] /* $whenCondition10 DISCRETE */ != data->simulationInfo->booleanVarsPre[1] /* $whenCondition10 DISCRETE */)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: %s from %d to %d", data->modelData->booleanVarsData[1].info /* $whenCondition10 */.name, data->simulationInfo->booleanVarsPre[1] /* $whenCondition10 DISCRETE */, data->localData[0]->booleanVars[1] /* $whenCondition10 DISCRETE */);
    needToIterate = 1;
  }
  if(data->localData[0]->booleanVars[13] /* $whenCondition9 DISCRETE */ != data->simulationInfo->booleanVarsPre[13] /* $whenCondition9 DISCRETE */)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: %s from %d to %d", data->modelData->booleanVarsData[13].info /* $whenCondition9 */.name, data->simulationInfo->booleanVarsPre[13] /* $whenCondition9 DISCRETE */, data->localData[0]->booleanVars[13] /* $whenCondition9 DISCRETE */);
    needToIterate = 1;
  }
  if(data->localData[0]->booleanVars[15] /* HeatingControlPortTransformer1._set_hysteresis_intervallumSignalHolder._y DISCRETE */ != data->simulationInfo->booleanVarsPre[15] /* HeatingControlPortTransformer1._set_hysteresis_intervallumSignalHolder._y DISCRETE */)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: %s from %d to %d", data->modelData->booleanVarsData[15].info /* HeatingControlPortTransformer1._set_hysteresis_intervallumSignalHolder._y */.name, data->simulationInfo->booleanVarsPre[15] /* HeatingControlPortTransformer1._set_hysteresis_intervallumSignalHolder._y DISCRETE */, data->localData[0]->booleanVars[15] /* HeatingControlPortTransformer1._set_hysteresis_intervallumSignalHolder._y DISCRETE */);
    needToIterate = 1;
  }
  if(data->localData[0]->booleanVars[14] /* HeatingControlPortTransformer1._set_hysteresis_intervallumSignalHolder._u DISCRETE */ != data->simulationInfo->booleanVarsPre[14] /* HeatingControlPortTransformer1._set_hysteresis_intervallumSignalHolder._u DISCRETE */)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: %s from %d to %d", data->modelData->booleanVarsData[14].info /* HeatingControlPortTransformer1._set_hysteresis_intervallumSignalHolder._u */.name, data->simulationInfo->booleanVarsPre[14] /* HeatingControlPortTransformer1._set_hysteresis_intervallumSignalHolder._u DISCRETE */, data->localData[0]->booleanVars[14] /* HeatingControlPortTransformer1._set_hysteresis_intervallumSignalHolder._u DISCRETE */);
    needToIterate = 1;
  }
  if(data->localData[0]->realVars[42] /* HeatingControlPortTransformer1._set_hysteresis_intervallumSignalHolder._entryTime DISCRETE */ != data->simulationInfo->realVarsPre[42] /* HeatingControlPortTransformer1._set_hysteresis_intervallumSignalHolder._entryTime DISCRETE */)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: %s from %g to %g", data->modelData->realVarsData[42].info /* HeatingControlPortTransformer1._set_hysteresis_intervallumSignalHolder._entryTime */.name, data->simulationInfo->realVarsPre[42] /* HeatingControlPortTransformer1._set_hysteresis_intervallumSignalHolder._entryTime DISCRETE */, data->localData[0]->realVars[42] /* HeatingControlPortTransformer1._set_hysteresis_intervallumSignalHolder._entryTime DISCRETE */);
    needToIterate = 1;
  }
  if(data->localData[0]->booleanVars[5] /* $whenCondition14 DISCRETE */ != data->simulationInfo->booleanVarsPre[5] /* $whenCondition14 DISCRETE */)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: %s from %d to %d", data->modelData->booleanVarsData[5].info /* $whenCondition14 */.name, data->simulationInfo->booleanVarsPre[5] /* $whenCondition14 DISCRETE */, data->localData[0]->booleanVars[5] /* $whenCondition14 DISCRETE */);
    needToIterate = 1;
  }
  if(data->localData[0]->booleanVars[4] /* $whenCondition13 DISCRETE */ != data->simulationInfo->booleanVarsPre[4] /* $whenCondition13 DISCRETE */)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: %s from %d to %d", data->modelData->booleanVarsData[4].info /* $whenCondition13 */.name, data->simulationInfo->booleanVarsPre[4] /* $whenCondition13 DISCRETE */, data->localData[0]->booleanVars[4] /* $whenCondition13 DISCRETE */);
    needToIterate = 1;
  }
  if(data->localData[0]->booleanVars[3] /* $whenCondition12 DISCRETE */ != data->simulationInfo->booleanVarsPre[3] /* $whenCondition12 DISCRETE */)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: %s from %d to %d", data->modelData->booleanVarsData[3].info /* $whenCondition12 */.name, data->simulationInfo->booleanVarsPre[3] /* $whenCondition12 DISCRETE */, data->localData[0]->booleanVars[3] /* $whenCondition12 DISCRETE */);
    needToIterate = 1;
  }
  if(data->localData[0]->booleanVars[2] /* $whenCondition11 DISCRETE */ != data->simulationInfo->booleanVarsPre[2] /* $whenCondition11 DISCRETE */)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: %s from %d to %d", data->modelData->booleanVarsData[2].info /* $whenCondition11 */.name, data->simulationInfo->booleanVarsPre[2] /* $whenCondition11 DISCRETE */, data->localData[0]->booleanVars[2] /* $whenCondition11 DISCRETE */);
    needToIterate = 1;
  }
  if(data->localData[0]->realVars[43] /* set_hysteresis_intervallum_tester1._y DISCRETE */ != data->simulationInfo->realVarsPre[43] /* set_hysteresis_intervallum_tester1._y DISCRETE */)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: %s from %g to %g", data->modelData->realVarsData[43].info /* set_hysteresis_intervallum_tester1._y */.name, data->simulationInfo->realVarsPre[43] /* set_hysteresis_intervallum_tester1._y DISCRETE */, data->localData[0]->realVars[43] /* set_hysteresis_intervallum_tester1._y DISCRETE */);
    needToIterate = 1;
  }
  if (ACTIVE_STREAM(LOG_EVENTS_V)) messageClose(LOG_EVENTS_V);
  
  TRACE_POP
  return needToIterate;
}

#if defined(__cplusplus)
}
#endif

