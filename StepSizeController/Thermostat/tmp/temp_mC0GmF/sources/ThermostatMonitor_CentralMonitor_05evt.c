/* Events: Sample, Zero Crossings, Relations, Discrete Changes */
#include "ThermostatMonitor_CentralMonitor_model.h"
#if defined(__cplusplus)
extern "C" {
#endif

/* Initializes the raw time events of the simulation using the now
   calcualted parameters. */
void ThermostatMonitor_CentralMonitor_function_initSample(DATA *data, threadData_t *threadData)
{
  long i=0;
}

const char *ThermostatMonitor_CentralMonitor_zeroCrossingDescription(int i, int **out_EquationIndexes)
{
  static const char *res[] = {"state > 1.5 and state < 2.5",
  "state > 2.5 and state < 3.5",
  "state > 3.5 and state < 4.5",
  "lastTermReply + lastHeatReply + lastTempReply > 2.5",
  "state > 4.5 and grant",
  "state > 4.5",
  "state > 3.5",
  "state < 4.5",
  "state > 2.5",
  "state < 3.5",
  "state < 1.5",
  "tempReply < -0.5",
  "tempReply > -0.5",
  "heatReply > -0.5",
  "termReply > -0.5",
  "time >= nextHeartBeat",
  "/*Real*/(heatOnPermission) > 0.5"};
  static const int occurEqs0[] = {1,47};
  static const int occurEqs1[] = {1,46};
  static const int occurEqs2[] = {1,45};
  static const int occurEqs3[] = {1,38};
  static const int occurEqs4[] = {1,39};
  static const int occurEqs5[] = {1,37};
  static const int occurEqs6[] = {1,36};
  static const int occurEqs7[] = {1,36};
  static const int occurEqs8[] = {1,35};
  static const int occurEqs9[] = {1,35};
  static const int occurEqs10[] = {1,34};
  static const int occurEqs11[] = {1,33};
  static const int occurEqs12[] = {1,32};
  static const int occurEqs13[] = {1,31};
  static const int occurEqs14[] = {1,30};
  static const int occurEqs15[] = {1,29};
  static const int occurEqs16[] = {1,28};
  static const int *occurEqs[] = {occurEqs0,occurEqs1,occurEqs2,occurEqs3,occurEqs4,occurEqs5,occurEqs6,occurEqs7,occurEqs8,occurEqs9,occurEqs10,occurEqs11,occurEqs12,occurEqs13,occurEqs14,occurEqs15,occurEqs16};
  *out_EquationIndexes = (int*) occurEqs[i];
  return res[i];
}

/* forwarded equations */
extern void ThermostatMonitor_CentralMonitor_eqFunction_38(DATA* data, threadData_t *threadData);
extern void ThermostatMonitor_CentralMonitor_eqFunction_40(DATA* data, threadData_t *threadData);
extern void ThermostatMonitor_CentralMonitor_eqFunction_41(DATA* data, threadData_t *threadData);
extern void ThermostatMonitor_CentralMonitor_eqFunction_42(DATA* data, threadData_t *threadData);
extern void ThermostatMonitor_CentralMonitor_eqFunction_43(DATA* data, threadData_t *threadData);
extern void ThermostatMonitor_CentralMonitor_eqFunction_44(DATA* data, threadData_t *threadData);

int ThermostatMonitor_CentralMonitor_function_ZeroCrossingsEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->callStatistics.functionZeroCrossingsEquations++;

  ThermostatMonitor_CentralMonitor_eqFunction_38(data, threadData);

  ThermostatMonitor_CentralMonitor_eqFunction_40(data, threadData);

  ThermostatMonitor_CentralMonitor_eqFunction_41(data, threadData);

  ThermostatMonitor_CentralMonitor_eqFunction_42(data, threadData);

  ThermostatMonitor_CentralMonitor_eqFunction_43(data, threadData);

  ThermostatMonitor_CentralMonitor_eqFunction_44(data, threadData);
  
  TRACE_POP
  return 0;
}

int ThermostatMonitor_CentralMonitor_function_ZeroCrossings(DATA *data, threadData_t *threadData, double *gout)
{
  TRACE_PUSH
  modelica_boolean tmp0;
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
  modelica_boolean tmp13;
  modelica_boolean tmp14;
  modelica_boolean tmp15;
  modelica_boolean tmp16;
  modelica_boolean tmp17;
  modelica_boolean tmp18;
  modelica_boolean tmp19;
  
  data->simulationInfo->callStatistics.functionZeroCrossings++;
  
  tmp0 = GreaterZC(data->localData[0]->realVars[4] /* state STATE(1) */, 1.5, data->simulationInfo->storedRelations[0]);
  tmp1 = LessZC(data->localData[0]->realVars[4] /* state STATE(1) */, 2.5, data->simulationInfo->storedRelations[1]);
  gout[0] = ((tmp0 && tmp1)) ? 1 : -1;
  tmp2 = GreaterZC(data->localData[0]->realVars[4] /* state STATE(1) */, 2.5, data->simulationInfo->storedRelations[2]);
  tmp3 = LessZC(data->localData[0]->realVars[4] /* state STATE(1) */, 3.5, data->simulationInfo->storedRelations[3]);
  gout[1] = ((tmp2 && tmp3)) ? 1 : -1;
  tmp4 = GreaterZC(data->localData[0]->realVars[4] /* state STATE(1) */, 3.5, data->simulationInfo->storedRelations[4]);
  tmp5 = LessZC(data->localData[0]->realVars[4] /* state STATE(1) */, 4.5, data->simulationInfo->storedRelations[5]);
  gout[2] = ((tmp4 && tmp5)) ? 1 : -1;
  tmp6 = GreaterZC(data->localData[0]->realVars[2] /* lastTermReply STATE(1) */ + data->localData[0]->realVars[0] /* lastHeatReply STATE(1) */ + data->localData[0]->realVars[1] /* lastTempReply STATE(1) */, 2.5, data->simulationInfo->storedRelations[6]);
  gout[3] = (tmp6) ? 1 : -1;
  tmp7 = GreaterZC(data->localData[0]->realVars[4] /* state STATE(1) */, 4.5, data->simulationInfo->storedRelations[7]);
  gout[4] = ((tmp7 && data->localData[0]->booleanVars[10] /* grant DISCRETE */)) ? 1 : -1;
  tmp8 = GreaterZC(data->localData[0]->realVars[4] /* state STATE(1) */, 4.5, data->simulationInfo->storedRelations[7]);
  gout[5] = (tmp8) ? 1 : -1;
  tmp9 = GreaterZC(data->localData[0]->realVars[4] /* state STATE(1) */, 3.5, data->simulationInfo->storedRelations[4]);
  gout[6] = (tmp9) ? 1 : -1;
  tmp10 = LessZC(data->localData[0]->realVars[4] /* state STATE(1) */, 4.5, data->simulationInfo->storedRelations[5]);
  gout[7] = (tmp10) ? 1 : -1;
  tmp11 = GreaterZC(data->localData[0]->realVars[4] /* state STATE(1) */, 2.5, data->simulationInfo->storedRelations[2]);
  gout[8] = (tmp11) ? 1 : -1;
  tmp12 = LessZC(data->localData[0]->realVars[4] /* state STATE(1) */, 3.5, data->simulationInfo->storedRelations[3]);
  gout[9] = (tmp12) ? 1 : -1;
  tmp13 = LessZC(data->localData[0]->realVars[4] /* state STATE(1) */, 1.5, data->simulationInfo->storedRelations[8]);
  gout[10] = (tmp13) ? 1 : -1;
  tmp14 = LessZC(data->localData[0]->realVars[12] /* tempReply variable */, -0.5, data->simulationInfo->storedRelations[9]);
  gout[11] = (tmp14) ? 1 : -1;
  tmp15 = GreaterZC(data->localData[0]->realVars[12] /* tempReply variable */, -0.5, data->simulationInfo->storedRelations[10]);
  gout[12] = (tmp15) ? 1 : -1;
  tmp16 = GreaterZC(data->localData[0]->realVars[10] /* heatReply variable */, -0.5, data->simulationInfo->storedRelations[11]);
  gout[13] = (tmp16) ? 1 : -1;
  tmp17 = GreaterZC(data->localData[0]->realVars[14] /* termReply variable */, -0.5, data->simulationInfo->storedRelations[12]);
  gout[14] = (tmp17) ? 1 : -1;
  tmp18 = GreaterEqZC(data->localData[0]->timeValue, data->localData[0]->realVars[3] /* nextHeartBeat STATE(1) */, data->simulationInfo->storedRelations[13]);
  gout[15] = (tmp18) ? 1 : -1;
  tmp19 = GreaterZC(((modelica_real)((modelica_integer)data->localData[0]->integerVars[1] /* heatOnPermission variable */)), 0.5, data->simulationInfo->storedRelations[14]);
  gout[16] = (tmp19) ? 1 : -1;
  
  TRACE_POP
  return 0;
}

const char *ThermostatMonitor_CentralMonitor_relationDescription(int i)
{
  const char *res[] = {"state > 1.5",
  "state < 2.5",
  "state > 2.5",
  "state < 3.5",
  "state > 3.5",
  "state < 4.5",
  "lastTermReply + lastHeatReply + lastTempReply > 2.5",
  "state > 4.5",
  "state < 1.5",
  "tempReply < -0.5",
  "tempReply > -0.5",
  "heatReply > -0.5",
  "termReply > -0.5",
  "time >= nextHeartBeat",
  "/*Real*/(heatOnPermission) > 0.5"};
  return res[i];
}

int ThermostatMonitor_CentralMonitor_function_updateRelations(DATA *data, threadData_t *threadData, int evalforZeroCross)
{
  TRACE_PUSH
  modelica_boolean tmp20;
  modelica_boolean tmp21;
  modelica_boolean tmp22;
  modelica_boolean tmp23;
  modelica_boolean tmp24;
  modelica_boolean tmp25;
  modelica_boolean tmp26;
  modelica_boolean tmp27;
  modelica_boolean tmp28;
  modelica_boolean tmp29;
  modelica_boolean tmp30;
  modelica_boolean tmp31;
  modelica_boolean tmp32;
  modelica_boolean tmp33;
  modelica_boolean tmp34;
  
  if(evalforZeroCross) {
    tmp20 = GreaterZC(data->localData[0]->realVars[4] /* state STATE(1) */, 1.5, data->simulationInfo->storedRelations[0]);
    data->simulationInfo->relations[0] = tmp20;
    tmp21 = LessZC(data->localData[0]->realVars[4] /* state STATE(1) */, 2.5, data->simulationInfo->storedRelations[1]);
    data->simulationInfo->relations[1] = tmp21;
    tmp22 = GreaterZC(data->localData[0]->realVars[4] /* state STATE(1) */, 2.5, data->simulationInfo->storedRelations[2]);
    data->simulationInfo->relations[2] = tmp22;
    tmp23 = LessZC(data->localData[0]->realVars[4] /* state STATE(1) */, 3.5, data->simulationInfo->storedRelations[3]);
    data->simulationInfo->relations[3] = tmp23;
    tmp24 = GreaterZC(data->localData[0]->realVars[4] /* state STATE(1) */, 3.5, data->simulationInfo->storedRelations[4]);
    data->simulationInfo->relations[4] = tmp24;
    tmp25 = LessZC(data->localData[0]->realVars[4] /* state STATE(1) */, 4.5, data->simulationInfo->storedRelations[5]);
    data->simulationInfo->relations[5] = tmp25;
    tmp26 = GreaterZC(data->localData[0]->realVars[2] /* lastTermReply STATE(1) */ + data->localData[0]->realVars[0] /* lastHeatReply STATE(1) */ + data->localData[0]->realVars[1] /* lastTempReply STATE(1) */, 2.5, data->simulationInfo->storedRelations[6]);
    data->simulationInfo->relations[6] = tmp26;
    tmp27 = GreaterZC(data->localData[0]->realVars[4] /* state STATE(1) */, 4.5, data->simulationInfo->storedRelations[7]);
    data->simulationInfo->relations[7] = tmp27;
    tmp28 = LessZC(data->localData[0]->realVars[4] /* state STATE(1) */, 1.5, data->simulationInfo->storedRelations[8]);
    data->simulationInfo->relations[8] = tmp28;
    tmp29 = LessZC(data->localData[0]->realVars[12] /* tempReply variable */, -0.5, data->simulationInfo->storedRelations[9]);
    data->simulationInfo->relations[9] = tmp29;
    tmp30 = GreaterZC(data->localData[0]->realVars[12] /* tempReply variable */, -0.5, data->simulationInfo->storedRelations[10]);
    data->simulationInfo->relations[10] = tmp30;
    tmp31 = GreaterZC(data->localData[0]->realVars[10] /* heatReply variable */, -0.5, data->simulationInfo->storedRelations[11]);
    data->simulationInfo->relations[11] = tmp31;
    tmp32 = GreaterZC(data->localData[0]->realVars[14] /* termReply variable */, -0.5, data->simulationInfo->storedRelations[12]);
    data->simulationInfo->relations[12] = tmp32;
    tmp33 = GreaterEqZC(data->localData[0]->timeValue, data->localData[0]->realVars[3] /* nextHeartBeat STATE(1) */, data->simulationInfo->storedRelations[13]);
    data->simulationInfo->relations[13] = tmp33;
    tmp34 = GreaterZC(((modelica_real)((modelica_integer)data->localData[0]->integerVars[1] /* heatOnPermission variable */)), 0.5, data->simulationInfo->storedRelations[14]);
    data->simulationInfo->relations[14] = tmp34;
  } else {
    data->simulationInfo->relations[0] = (data->localData[0]->realVars[4] /* state STATE(1) */ > 1.5);
    data->simulationInfo->relations[1] = (data->localData[0]->realVars[4] /* state STATE(1) */ < 2.5);
    data->simulationInfo->relations[2] = (data->localData[0]->realVars[4] /* state STATE(1) */ > 2.5);
    data->simulationInfo->relations[3] = (data->localData[0]->realVars[4] /* state STATE(1) */ < 3.5);
    data->simulationInfo->relations[4] = (data->localData[0]->realVars[4] /* state STATE(1) */ > 3.5);
    data->simulationInfo->relations[5] = (data->localData[0]->realVars[4] /* state STATE(1) */ < 4.5);
    data->simulationInfo->relations[6] = (data->localData[0]->realVars[2] /* lastTermReply STATE(1) */ + data->localData[0]->realVars[0] /* lastHeatReply STATE(1) */ + data->localData[0]->realVars[1] /* lastTempReply STATE(1) */ > 2.5);
    data->simulationInfo->relations[7] = (data->localData[0]->realVars[4] /* state STATE(1) */ > 4.5);
    data->simulationInfo->relations[8] = (data->localData[0]->realVars[4] /* state STATE(1) */ < 1.5);
    data->simulationInfo->relations[9] = (data->localData[0]->realVars[12] /* tempReply variable */ < -0.5);
    data->simulationInfo->relations[10] = (data->localData[0]->realVars[12] /* tempReply variable */ > -0.5);
    data->simulationInfo->relations[11] = (data->localData[0]->realVars[10] /* heatReply variable */ > -0.5);
    data->simulationInfo->relations[12] = (data->localData[0]->realVars[14] /* termReply variable */ > -0.5);
    data->simulationInfo->relations[13] = (data->localData[0]->timeValue >= data->localData[0]->realVars[3] /* nextHeartBeat STATE(1) */);
    data->simulationInfo->relations[14] = (((modelica_real)((modelica_integer)data->localData[0]->integerVars[1] /* heatOnPermission variable */)) > 0.5);
  }
  
  TRACE_POP
  return 0;
}

int ThermostatMonitor_CentralMonitor_checkForDiscreteChanges(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  int needToIterate = 0;

  infoStreamPrint(LOG_EVENTS_V, 1, "check for discrete changes at time=%.12g", data->localData[0]->timeValue);
  if(data->localData[0]->booleanVars[1] /* $whenCondition10 DISCRETE */ != data->simulationInfo->booleanVarsPre[1] /* $whenCondition10 DISCRETE */)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: %s from %d to %d", data->modelData->booleanVarsData[1].info /* $whenCondition10 */.name, data->simulationInfo->booleanVarsPre[1] /* $whenCondition10 DISCRETE */, data->localData[0]->booleanVars[1] /* $whenCondition10 DISCRETE */);
    needToIterate = 1;
  }
  if(data->localData[0]->booleanVars[9] /* $whenCondition9 DISCRETE */ != data->simulationInfo->booleanVarsPre[9] /* $whenCondition9 DISCRETE */)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: %s from %d to %d", data->modelData->booleanVarsData[9].info /* $whenCondition9 */.name, data->simulationInfo->booleanVarsPre[9] /* $whenCondition9 DISCRETE */, data->localData[0]->booleanVars[9] /* $whenCondition9 DISCRETE */);
    needToIterate = 1;
  }
  if(data->localData[0]->booleanVars[8] /* $whenCondition8 DISCRETE */ != data->simulationInfo->booleanVarsPre[8] /* $whenCondition8 DISCRETE */)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: %s from %d to %d", data->modelData->booleanVarsData[8].info /* $whenCondition8 */.name, data->simulationInfo->booleanVarsPre[8] /* $whenCondition8 DISCRETE */, data->localData[0]->booleanVars[8] /* $whenCondition8 DISCRETE */);
    needToIterate = 1;
  }
  if(data->localData[0]->booleanVars[7] /* $whenCondition7 DISCRETE */ != data->simulationInfo->booleanVarsPre[7] /* $whenCondition7 DISCRETE */)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: %s from %d to %d", data->modelData->booleanVarsData[7].info /* $whenCondition7 */.name, data->simulationInfo->booleanVarsPre[7] /* $whenCondition7 DISCRETE */, data->localData[0]->booleanVars[7] /* $whenCondition7 DISCRETE */);
    needToIterate = 1;
  }
  if(data->localData[0]->booleanVars[6] /* $whenCondition6 DISCRETE */ != data->simulationInfo->booleanVarsPre[6] /* $whenCondition6 DISCRETE */)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: %s from %d to %d", data->modelData->booleanVarsData[6].info /* $whenCondition6 */.name, data->simulationInfo->booleanVarsPre[6] /* $whenCondition6 DISCRETE */, data->localData[0]->booleanVars[6] /* $whenCondition6 DISCRETE */);
    needToIterate = 1;
  }
  if(data->localData[0]->booleanVars[5] /* $whenCondition5 DISCRETE */ != data->simulationInfo->booleanVarsPre[5] /* $whenCondition5 DISCRETE */)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: %s from %d to %d", data->modelData->booleanVarsData[5].info /* $whenCondition5 */.name, data->simulationInfo->booleanVarsPre[5] /* $whenCondition5 DISCRETE */, data->localData[0]->booleanVars[5] /* $whenCondition5 DISCRETE */);
    needToIterate = 1;
  }
  if(data->localData[0]->booleanVars[4] /* $whenCondition4 DISCRETE */ != data->simulationInfo->booleanVarsPre[4] /* $whenCondition4 DISCRETE */)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: %s from %d to %d", data->modelData->booleanVarsData[4].info /* $whenCondition4 */.name, data->simulationInfo->booleanVarsPre[4] /* $whenCondition4 DISCRETE */, data->localData[0]->booleanVars[4] /* $whenCondition4 DISCRETE */);
    needToIterate = 1;
  }
  if(data->localData[0]->booleanVars[3] /* $whenCondition3 DISCRETE */ != data->simulationInfo->booleanVarsPre[3] /* $whenCondition3 DISCRETE */)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: %s from %d to %d", data->modelData->booleanVarsData[3].info /* $whenCondition3 */.name, data->simulationInfo->booleanVarsPre[3] /* $whenCondition3 DISCRETE */, data->localData[0]->booleanVars[3] /* $whenCondition3 DISCRETE */);
    needToIterate = 1;
  }
  if(data->localData[0]->booleanVars[2] /* $whenCondition2 DISCRETE */ != data->simulationInfo->booleanVarsPre[2] /* $whenCondition2 DISCRETE */)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: %s from %d to %d", data->modelData->booleanVarsData[2].info /* $whenCondition2 */.name, data->simulationInfo->booleanVarsPre[2] /* $whenCondition2 DISCRETE */, data->localData[0]->booleanVars[2] /* $whenCondition2 DISCRETE */);
    needToIterate = 1;
  }
  if(data->localData[0]->booleanVars[0] /* $whenCondition1 DISCRETE */ != data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: %s from %d to %d", data->modelData->booleanVarsData[0].info /* $whenCondition1 */.name, data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */, data->localData[0]->booleanVars[0] /* $whenCondition1 DISCRETE */);
    needToIterate = 1;
  }
  if(data->localData[0]->integerVars[0] /* heatOnGrant DISCRETE */ != data->simulationInfo->integerVarsPre[0] /* heatOnGrant DISCRETE */)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: %s from %ld to %ld", data->modelData->integerVarsData[0].info /* heatOnGrant */.name, data->simulationInfo->integerVarsPre[0] /* heatOnGrant DISCRETE */, data->localData[0]->integerVars[0] /* heatOnGrant DISCRETE */);
    needToIterate = 1;
  }
  if(data->localData[0]->booleanVars[10] /* grant DISCRETE */ != data->simulationInfo->booleanVarsPre[10] /* grant DISCRETE */)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: %s from %d to %d", data->modelData->booleanVarsData[10].info /* grant */.name, data->simulationInfo->booleanVarsPre[10] /* grant DISCRETE */, data->localData[0]->booleanVars[10] /* grant DISCRETE */);
    needToIterate = 1;
  }
  if (ACTIVE_STREAM(LOG_EVENTS_V)) messageClose(LOG_EVENTS_V);
  
  TRACE_POP
  return needToIterate;
}

#if defined(__cplusplus)
}
#endif

