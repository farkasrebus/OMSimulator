/* Asserts */
#include "Room_model.h"
#if defined(__cplusplus)
extern "C" {
#endif


/*
 equation index: 301
 type: ALGORITHM
 
   assert(vol.dynBal.medium.p >= 0.0 and vol.dynBal.medium.p <= 100000000.0, "Variable violating min/max constraint: 0.0 <= vol.dynBal.medium.p <= 100000000.0, has value: " + String(vol.dynBal.medium.p, "g"));
 */
void Room_eqFunction_301(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,301};
  modelica_boolean tmp192;
  modelica_boolean tmp193;
  static const MMC_DEFSTRINGLIT(tmp194,93,"Variable violating min/max constraint: 0.0 <= vol.dynBal.medium.p <= 100000000.0, has value: ");
  modelica_string tmp195;
  static int tmp196 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp196)
  {
    tmp192 = GreaterEq(data->localData[0]->realVars[38] /* vol._dynBal._medium._p variable */,0.0);
    tmp193 = LessEq(data->localData[0]->realVars[38] /* vol._dynBal._medium._p variable */,100000000.0);
    if(!(tmp192 && tmp193))
    {
      tmp195 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[38] /* vol._dynBal._medium._p variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp194),tmp195);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.2/Media/package.mo",4477,7,4477,60,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nvol.dynBal.medium.p >= 0.0 and vol.dynBal.medium.p <= 100000000.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp196 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 302
 type: ALGORITHM
 
   assert(vol.dynBal.medium.Xi[1] >= 0.0 and vol.dynBal.medium.Xi[1] <= 1.0, "Variable violating min/max constraint: 0.0 <= vol.dynBal.medium.Xi[1] <= 1.0, has value: " + String(vol.dynBal.medium.Xi[1], "g"));
 */
void Room_eqFunction_302(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,302};
  modelica_boolean tmp197;
  modelica_boolean tmp198;
  static const MMC_DEFSTRINGLIT(tmp199,89,"Variable violating min/max constraint: 0.0 <= vol.dynBal.medium.Xi[1] <= 1.0, has value: ");
  modelica_string tmp200;
  static int tmp201 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp201)
  {
    tmp197 = GreaterEq(data->localData[0]->realVars[1] /* vol._dynBal._medium._Xi[1] STATE(1) */,0.0);
    tmp198 = LessEq(data->localData[0]->realVars[1] /* vol._dynBal._medium._Xi[1] STATE(1) */,1.0);
    if(!(tmp197 && tmp198))
    {
      tmp200 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[1] /* vol._dynBal._medium._Xi[1] STATE(1) */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp199),tmp200);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.2/Media/package.mo",4478,7,4479,50,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nvol.dynBal.medium.Xi[1] >= 0.0 and vol.dynBal.medium.Xi[1] <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp201 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 303
 type: ALGORITHM
 
   assert(vol.dynBal.medium.d >= 0.0 and vol.dynBal.medium.d <= 100000.0, "Variable violating min/max constraint: 0.0 <= vol.dynBal.medium.d <= 100000.0, has value: " + String(vol.dynBal.medium.d, "g"));
 */
void Room_eqFunction_303(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,303};
  modelica_boolean tmp202;
  modelica_boolean tmp203;
  static const MMC_DEFSTRINGLIT(tmp204,90,"Variable violating min/max constraint: 0.0 <= vol.dynBal.medium.d <= 100000.0, has value: ");
  modelica_string tmp205;
  static int tmp206 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp206)
  {
    tmp202 = GreaterEq(data->localData[0]->realVars[36] /* vol._dynBal._medium._d variable */,0.0);
    tmp203 = LessEq(data->localData[0]->realVars[36] /* vol._dynBal._medium._d variable */,100000.0);
    if(!(tmp202 && tmp203))
    {
      tmp205 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[36] /* vol._dynBal._medium._d variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp204),tmp205);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.2/Media/package.mo",4481,7,4481,36,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nvol.dynBal.medium.d >= 0.0 and vol.dynBal.medium.d <= 100000.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp206 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 304
 type: ALGORITHM
 
   assert(vol.dynBal.medium.T >= 1.0 and vol.dynBal.medium.T <= 10000.0, "Variable violating min/max constraint: 1.0 <= vol.dynBal.medium.T <= 10000.0, has value: " + String(vol.dynBal.medium.T, "g"));
 */
void Room_eqFunction_304(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,304};
  modelica_boolean tmp207;
  modelica_boolean tmp208;
  static const MMC_DEFSTRINGLIT(tmp209,89,"Variable violating min/max constraint: 1.0 <= vol.dynBal.medium.T <= 10000.0, has value: ");
  modelica_string tmp210;
  static int tmp211 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp211)
  {
    tmp207 = GreaterEq(data->localData[0]->realVars[34] /* vol._dynBal._medium._T variable */,1.0);
    tmp208 = LessEq(data->localData[0]->realVars[34] /* vol._dynBal._medium._T variable */,10000.0);
    if(!(tmp207 && tmp208))
    {
      tmp210 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[34] /* vol._dynBal._medium._T variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp209),tmp210);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.2/Media/package.mo",4482,7,4482,44,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nvol.dynBal.medium.T >= 1.0 and vol.dynBal.medium.T <= 10000.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp211 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 305
 type: ALGORITHM
 
   assert(vol.dynBal.medium.X[2] >= 0.0 and vol.dynBal.medium.X[2] <= 1.0, "Variable violating min/max constraint: 0.0 <= vol.dynBal.medium.X[2] <= 1.0, has value: " + String(vol.dynBal.medium.X[2], "g"));
 */
void Room_eqFunction_305(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,305};
  modelica_boolean tmp212;
  modelica_boolean tmp213;
  static const MMC_DEFSTRINGLIT(tmp214,88,"Variable violating min/max constraint: 0.0 <= vol.dynBal.medium.X[2] <= 1.0, has value: ");
  modelica_string tmp215;
  static int tmp216 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp216)
  {
    tmp212 = GreaterEq(data->localData[0]->realVars[35] /* vol._dynBal._medium._X[2] variable */,0.0);
    tmp213 = LessEq(data->localData[0]->realVars[35] /* vol._dynBal._medium._X[2] variable */,1.0);
    if(!(tmp212 && tmp213))
    {
      tmp215 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[35] /* vol._dynBal._medium._X[2] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp214),tmp215);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.2/Media/package.mo",4483,7,4484,64,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nvol.dynBal.medium.X[2] >= 0.0 and vol.dynBal.medium.X[2] <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp216 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 306
 type: ALGORITHM
 
   assert(vol.dynBal.medium.u >= -100000000.0 and vol.dynBal.medium.u <= 100000000.0, "Variable violating min/max constraint: -100000000.0 <= vol.dynBal.medium.u <= 100000000.0, has value: " + String(vol.dynBal.medium.u, "g"));
 */
void Room_eqFunction_306(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,306};
  modelica_boolean tmp217;
  modelica_boolean tmp218;
  static const MMC_DEFSTRINGLIT(tmp219,102,"Variable violating min/max constraint: -100000000.0 <= vol.dynBal.medium.u <= 100000000.0, has value: ");
  modelica_string tmp220;
  static int tmp221 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp221)
  {
    tmp217 = GreaterEq(data->localData[0]->realVars[40] /* vol._dynBal._medium._u DUMMY_STATE */,-100000000.0);
    tmp218 = LessEq(data->localData[0]->realVars[40] /* vol._dynBal._medium._u DUMMY_STATE */,100000000.0);
    if(!(tmp217 && tmp218))
    {
      tmp220 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[40] /* vol._dynBal._medium._u DUMMY_STATE */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp219),tmp220);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.2/Media/package.mo",4485,7,4485,68,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nvol.dynBal.medium.u >= -100000000.0 and vol.dynBal.medium.u <= 100000000.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp221 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 307
 type: ALGORITHM
 
   assert(vol.dynBal.medium.R >= 0.0 and vol.dynBal.medium.R <= 10000000.0, "Variable violating min/max constraint: 0.0 <= vol.dynBal.medium.R <= 10000000.0, has value: " + String(vol.dynBal.medium.R, "g"));
 */
void Room_eqFunction_307(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,307};
  modelica_boolean tmp222;
  modelica_boolean tmp223;
  static const MMC_DEFSTRINGLIT(tmp224,92,"Variable violating min/max constraint: 0.0 <= vol.dynBal.medium.R <= 10000000.0, has value: ");
  modelica_string tmp225;
  static int tmp226 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp226)
  {
    tmp222 = GreaterEq(data->localData[0]->realVars[33] /* vol._dynBal._medium._R variable */,0.0);
    tmp223 = LessEq(data->localData[0]->realVars[33] /* vol._dynBal._medium._R variable */,10000000.0);
    if(!(tmp222 && tmp223))
    {
      tmp225 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[33] /* vol._dynBal._medium._R variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp224),tmp225);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.2/Media/package.mo",4486,7,4486,71,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nvol.dynBal.medium.R >= 0.0 and vol.dynBal.medium.R <= 10000000.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp226 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 308
 type: ALGORITHM
 
   assert(vol.dynBal.medium.MM >= 0.001 and vol.dynBal.medium.MM <= 0.25, "Variable violating min/max constraint: 0.001 <= vol.dynBal.medium.MM <= 0.25, has value: " + String(vol.dynBal.medium.MM, "g"));
 */
void Room_eqFunction_308(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,308};
  modelica_boolean tmp227;
  modelica_boolean tmp228;
  static const MMC_DEFSTRINGLIT(tmp229,89,"Variable violating min/max constraint: 0.001 <= vol.dynBal.medium.MM <= 0.25, has value: ");
  modelica_string tmp230;
  static int tmp231 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp231)
  {
    tmp227 = GreaterEq(data->localData[0]->realVars[32] /* vol._dynBal._medium._MM variable */,0.001);
    tmp228 = LessEq(data->localData[0]->realVars[32] /* vol._dynBal._medium._MM variable */,0.25);
    if(!(tmp227 && tmp228))
    {
      tmp230 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[32] /* vol._dynBal._medium._MM variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp229),tmp230);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.2/Media/package.mo",4487,7,4487,61,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nvol.dynBal.medium.MM >= 0.001 and vol.dynBal.medium.MM <= 0.25", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp231 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 309
 type: ALGORITHM
 
   assert(vol.dynBal.m >= 0.0, "Variable violating min constraint: 0.0 <= vol.dynBal.m, has value: " + String(vol.dynBal.m, "g"));
 */
void Room_eqFunction_309(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,309};
  modelica_boolean tmp232;
  static const MMC_DEFSTRINGLIT(tmp233,67,"Variable violating min constraint: 0.0 <= vol.dynBal.m, has value: ");
  modelica_string tmp234;
  static int tmp235 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp235)
  {
    tmp232 = GreaterEq(data->localData[0]->realVars[0] /* vol._dynBal._m STATE(1) */,0.0);
    if(!tmp232)
    {
      tmp234 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[0] /* vol._dynBal._m STATE(1) */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp233),tmp234);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Buildings latest/Fluid/Interfaces/ConservationEquation.mo",98,3,101,20,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nvol.dynBal.m >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp235 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 310
 type: ALGORITHM
 
   assert(vol.dynBal.mXi[1] >= 0.0, "Variable violating min constraint: 0.0 <= vol.dynBal.mXi[1], has value: " + String(vol.dynBal.mXi[1], "g"));
 */
void Room_eqFunction_310(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,310};
  modelica_boolean tmp236;
  static const MMC_DEFSTRINGLIT(tmp237,72,"Variable violating min constraint: 0.0 <= vol.dynBal.mXi[1], has value: ");
  modelica_string tmp238;
  static int tmp239 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp239)
  {
    tmp236 = GreaterEq(data->localData[0]->realVars[29] /* vol._dynBal._mXi[1] DUMMY_STATE */,0.0);
    if(!tmp236)
    {
      tmp238 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[29] /* vol._dynBal._mXi[1] DUMMY_STATE */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp237),tmp238);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Buildings latest/Fluid/Interfaces/ConservationEquation.mo",103,3,104,52,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nvol.dynBal.mXi[1] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp239 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 311
 type: ALGORITHM
 
   assert(heaCap.T >= 1.0 and heaCap.T <= 10000.0, "Variable violating min/max constraint: 1.0 <= heaCap.T <= 10000.0, has value: " + String(heaCap.T, "g"));
 */
void Room_eqFunction_311(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,311};
  modelica_boolean tmp240;
  modelica_boolean tmp241;
  static const MMC_DEFSTRINGLIT(tmp242,78,"Variable violating min/max constraint: 1.0 <= heaCap.T <= 10000.0, has value: ");
  modelica_string tmp243;
  static int tmp244 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp244)
  {
    tmp240 = GreaterEq(data->localData[0]->realVars[11] /* heaCap._T DUMMY_STATE */,1.0);
    tmp241 = LessEq(data->localData[0]->realVars[11] /* heaCap._T DUMMY_STATE */,10000.0);
    if(!(tmp240 && tmp241))
    {
      tmp243 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[11] /* heaCap._T DUMMY_STATE */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp242),tmp243);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.2/Thermal/HeatTransfer.mo",284,7,285,33,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nheaCap.T >= 1.0 and heaCap.T <= 10000.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp244 = 1;
    }
  }
  TRACE_POP
}
/* function to check assert after a step is done */
int Room_checkForAsserts(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  Room_eqFunction_301(data, threadData);

  Room_eqFunction_302(data, threadData);

  Room_eqFunction_303(data, threadData);

  Room_eqFunction_304(data, threadData);

  Room_eqFunction_305(data, threadData);

  Room_eqFunction_306(data, threadData);

  Room_eqFunction_307(data, threadData);

  Room_eqFunction_308(data, threadData);

  Room_eqFunction_309(data, threadData);

  Room_eqFunction_310(data, threadData);

  Room_eqFunction_311(data, threadData);
  
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif

