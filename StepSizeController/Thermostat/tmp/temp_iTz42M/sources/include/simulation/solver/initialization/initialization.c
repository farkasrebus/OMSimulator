/*
 * This file is part of OpenModelica.
 *
 * Copyright (c) 1998-2014, Open Source Modelica Consortium (OSMC),
 * c/o Linköpings universitet, Department of Computer and Information Science,
 * SE-58183 Linköping, Sweden.
 *
 * All rights reserved.
 *
 * THIS PROGRAM IS PROVIDED UNDER THE TERMS OF THE BSD NEW LICENSE OR THE
 * GPL VERSION 3 LICENSE OR THE OSMC PUBLIC LICENSE (OSMC-PL) VERSION 1.2.
 * ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS PROGRAM CONSTITUTES
 * RECIPIENT'S ACCEPTANCE OF THE OSMC PUBLIC LICENSE OR THE GPL VERSION 3,
 * ACCORDING TO RECIPIENTS CHOICE.
 *
 * The OpenModelica software and the OSMC (Open Source Modelica Consortium)
 * Public License (OSMC-PL) are obtained from OSMC, either from the above
 * address, from the URLs: http://www.openmodelica.org or
 * http://www.ida.liu.se/projects/OpenModelica, and in the OpenModelica
 * distribution. GNU version 3 is obtained from:
 * http://www.gnu.org/copyleft/gpl.html. The New BSD License is obtained from:
 * http://www.opensource.org/licenses/BSD-3-Clause.
 *
 * This program is distributed WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE, EXCEPT AS
 * EXPRESSLY SET FORTH IN THE BY RECIPIENT SELECTED SUBSIDIARY LICENSE
 * CONDITIONS OF OSMC-PL.
 *
 */

/*! \file initialization.c
 */

#include "initialization.h"

#include "simulation_data.h"
#include "util/omc_error.h"
#include "openmodelica.h"
#include "openmodelica_func.h"
#include "simulation/options.h"
#include "simulation/solver/model_help.h"
#if !defined(OMC_MINIMAL_RUNTIME)
#include "util/read_matlab4.h"
#endif
#include "simulation/solver/events.h"
#include "simulation/solver/stateset.h"
#include "meta/meta_modelica.h"

#if defined(OMC_NUM_MIXED_SYSTEMS) && OMC_NUM_MIXED_SYSTEMS==0
#define check_mixed_solutions(X,Y) 0
#else
#include "simulation/solver/mixedSystem.h"
#endif

#if defined(OMC_NUM_LINEAR_SYSTEMS) && OMC_NUM_LINEAR_SYSTEMS==0
#define check_linear_solutions(X,Y) 0
#define updateStaticDataOfLinearSystems(X,Y)
#else
#include "simulation/solver/linearSystem.h"
#endif

#if defined(OMC_NUM_NONLINEAR_SYSTEMS) && OMC_NUM_NONLINEAR_SYSTEMS==0
#define check_nonlinear_solutions(X,Y) 0
#define updateStaticDataOfNonlinearSystems(X,Y)
#else
#include "simulation/solver/nonlinearSystem.h"
#endif

#include "simulation/solver/delay.h"
#include "simulation/solver/synchronous.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int init_lambda_steps = 4;

/*! \fn void dumpInitializationStatus(DATA *data)
 *
 *  \param [in]  [data]
 *
 *  \author lochel
 */
void dumpInitialSolution(DATA *simData)
{
  long i, j;

  const MODEL_DATA      *mData = simData->modelData;
  const SIMULATION_INFO *sInfo = simData->simulationInfo;

  if (ACTIVE_STREAM(LOG_INIT))
    printParameters(simData, LOG_INIT);

  if (!ACTIVE_STREAM(LOG_SOTI)) return;
  infoStreamPrint(LOG_SOTI, 1, "### SOLUTION OF THE INITIALIZATION ###");

  if (0 < mData->nStates)
  {
    infoStreamPrint(LOG_SOTI, 1, "states variables");
    for(i=0; i<mData->nStates; ++i)
      infoStreamPrint(LOG_SOTI, 0, "[%ld] Real %s(start=%g, nominal=%g) = %g (pre: %g)", i+1,
                                   mData->realVarsData[i].info.name,
                                   mData->realVarsData[i].attribute.start,
                                   mData->realVarsData[i].attribute.nominal,
                                   simData->localData[0]->realVars[i],
                                   sInfo->realVarsPre[i]);
    messageClose(LOG_SOTI);
  }

  if (0 < mData->nStates)
  {
    infoStreamPrint(LOG_SOTI, 1, "derivatives variables");
    for(i=mData->nStates; i<2*mData->nStates; ++i)
      infoStreamPrint(LOG_SOTI, 0, "[%ld] Real %s = %g (pre: %g)", i+1,
                                   mData->realVarsData[i].info.name,
                                   simData->localData[0]->realVars[i],
                                   sInfo->realVarsPre[i]);
    messageClose(LOG_SOTI);
  }

  if (2*mData->nStates < mData->nVariablesReal)
  {
    infoStreamPrint(LOG_SOTI, 1, "other real variables");
    for(i=2*mData->nStates; i<mData->nVariablesReal; ++i)
      infoStreamPrint(LOG_SOTI, 0, "[%ld] Real %s(start=%g, nominal=%g) = %g (pre: %g)", i+1,
                                   mData->realVarsData[i].info.name,
                                   mData->realVarsData[i].attribute.start,
                                   mData->realVarsData[i].attribute.nominal,
                                   simData->localData[0]->realVars[i],
                                   sInfo->realVarsPre[i]);
    messageClose(LOG_SOTI);
  }

  if (0 < mData->nVariablesInteger)
  {
    infoStreamPrint(LOG_SOTI, 1, "integer variables");
    for(i=0; i<mData->nVariablesInteger; ++i)
      infoStreamPrint(LOG_SOTI, 0, "[%ld] Integer %s(start=%ld) = %ld (pre: %ld)", i+1,
                                   mData->integerVarsData[i].info.name,
                                   mData->integerVarsData[i].attribute.start,
                                   simData->localData[0]->integerVars[i],
                                   sInfo->integerVarsPre[i]);
    messageClose(LOG_SOTI);
  }

  if (0 < mData->nVariablesBoolean)
  {
    infoStreamPrint(LOG_SOTI, 1, "boolean variables");
    for(i=0; i<mData->nVariablesBoolean; ++i)
      infoStreamPrint(LOG_SOTI, 0, "[%ld] Boolean %s(start=%s) = %s (pre: %s)", i+1,
                                   mData->booleanVarsData[i].info.name,
                                   mData->booleanVarsData[i].attribute.start ? "true" : "false",
                                   simData->localData[0]->booleanVars[i] ? "true" : "false",
                                   sInfo->booleanVarsPre[i] ? "true" : "false");
    messageClose(LOG_SOTI);
  }

  if (0 < mData->nVariablesString)
  {
    infoStreamPrint(LOG_SOTI, 1, "string variables");
    for(i=0; i<mData->nVariablesString; ++i)
      infoStreamPrint(LOG_SOTI, 0, "[%ld] String %s(start=\"%s\") = \"%s\" (pre: \"%s\")", i+1,
                                   mData->stringVarsData[i].info.name,
                                   MMC_STRINGDATA(mData->stringVarsData[i].attribute.start),
                                   MMC_STRINGDATA(simData->localData[0]->stringVars[i]),
                                   MMC_STRINGDATA(sInfo->stringVarsPre[i]));
    messageClose(LOG_SOTI);
  }

  messageClose(LOG_SOTI);
}

/*! \fn static int symbolic_initialization(DATA *data, threadData_t *threadData)
 *
 *  \param [ref] [data]
 *  \param [ref] [threadData]
 *
 *  \author lochel
 */
static int symbolic_initialization(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  int retVal;
  FILE *pFile = NULL;
  long i;
  MODEL_DATA *mData = data->modelData;
  int solveWithGlobalHomotopy = data->callback->useHomotopy == 0 || (data->callback->useHomotopy != 2 && init_lambda_steps < 2) ? 0 : 1;
  data->simulationInfo->homotopyUsed = 0;

#if !defined(OMC_NDELAY_EXPRESSIONS) || OMC_NDELAY_EXPRESSIONS>0
  /* initial sample and delay before initial the system */
  initDelay(data, data->simulationInfo->startTime);
#endif
  /* initialize all relations that are ZeroCrossings */
  storePreValues(data);
  overwriteOldSimulationData(data);

  /* If there is no homotopy in the model or local homotopy is activated
     or homotopy is disabled by runtime flag '-ils=<lambda_steps>',
     solve WITHOUT HOMOTOPY. */
  if (!solveWithGlobalHomotopy){
    data->simulationInfo->lambda = 1.0;
    data->callback->functionInitialEquations(data, threadData);

  /* If there is homotopy in the model and global homotopy is activated
     and homotopy on first try is deactivated,
     TRY TO SOLVE WITHOUT HOMOTOPY FIRST.
     To-Do: Activate trying without homotopy first also for the new global homotopy approach */
  } else if (!omc_flag[FLAG_HOMOTOPY_ON_FIRST_TRY] && data->callback->useHomotopy != 2) {
    /* try */
#ifndef OMC_EMCC
  MMC_TRY_INTERNAL(simulationJumpBuffer)
#endif

    data->simulationInfo->lambda = 1.0;
    infoStreamPrint(LOG_INIT, 0, "Try to solve the initialization problem without homotopy first.");
    data->callback->functionInitialEquations(data, threadData);
    solveWithGlobalHomotopy = 0;

    /* catch */
#ifndef OMC_EMCC
  MMC_CATCH_INTERNAL(simulationJumpBuffer)
#endif
    if(solveWithGlobalHomotopy)
      warningStreamPrint(LOG_ASSERT, 0, "Failed to solve the initialization problem without homotopy method. If homotopy is available the homotopy method is used now.");
  }

  /* If there is homotopy in the model and global homotopy is activated
     and solving without homotopy failed or is not wanted,
     use GLOBAL HOMOTOPY METHOD. */
  if (data->callback->useHomotopy == 1 && solveWithGlobalHomotopy)
  {
    long step;
    char buffer[4096];

#if !defined(OMC_NO_FILESYSTEM)
    if(ACTIVE_STREAM(LOG_INIT))
    {
      sprintf(buffer, "%s_global_homotopy.csv", mData->modelFilePrefix);
      infoStreamPrint(LOG_INIT, 0, "The homotopy path will be exported to %s.", buffer);
      pFile = fopen(buffer, "wt");
      fprintf(pFile, "\"sep=,\"\n%s", "lambda");
      for(i=0; i<mData->nVariablesReal; ++i)
        fprintf(pFile, ",%s", mData->realVarsData[i].info.name);
      fprintf(pFile, "\n");
    }
#endif

    infoStreamPrint(LOG_INIT, 1, "homotopy process\n---------------------------");
    for(step=0; step<init_lambda_steps; ++step)
    {
      data->simulationInfo->lambda = ((double)step)/(init_lambda_steps-1);
      infoStreamPrint(LOG_INIT, 0, "homotopy parameter lambda = %g", data->simulationInfo->lambda);

      if(data->simulationInfo->lambda > 1.0) {
        data->simulationInfo->lambda = 1.0;
      }

      if(0 == step)
        data->callback->functionInitialEquations_lambda0(data, threadData);
      else
        data->callback->functionInitialEquations(data, threadData);

      infoStreamPrint(LOG_INIT, 0, "homotopy parameter lambda = %g done\n---------------------------", data->simulationInfo->lambda);

#if !defined(OMC_NO_FILESYSTEM)
      if(ACTIVE_STREAM(LOG_INIT))
      {
        fprintf(pFile, "%.16g", data->simulationInfo->lambda);
        for(i=0; i<mData->nVariablesReal; ++i)
          fprintf(pFile, ",%.16g", data->localData[0]->realVars[i]);
        fprintf(pFile, "\n");
      }
#endif

      if (check_nonlinear_solutions(data, 0) ||
          check_linear_solutions(data, 0) ||
          check_mixed_solutions(data, 0))
        break;
    }
    data->simulationInfo->homotopyUsed = 1;
    messageClose(LOG_INIT);

#if !defined(OMC_NO_FILESYSTEM)
    if(ACTIVE_STREAM(LOG_INIT))
      fclose(pFile);
#endif
  }

  /* If there is homotopy in the model and the new global homotopy approach is activated
     and solving without homotopy failed or is not wanted,
     use NEW GLOBAL HOMOTOPY APPROACH. */
  if (data->callback->useHomotopy == 2 && solveWithGlobalHomotopy)
  {
    infoStreamPrint(LOG_INIT, 1, "homotopy process\n---------------------------");

    // Solve lambda0-DAE
    data->simulationInfo->lambda = 0;
    infoStreamPrint(LOG_INIT, 0, "solve simplified lambda0-DAE");
    data->callback->functionInitialEquations_lambda0(data, threadData);
    infoStreamPrint(LOG_INIT, 0, "solving simplified lambda0-DAE done\n---------------------------");

    // Run along the homotopy path and solve the actual system
    infoStreamPrint(LOG_INIT, 0, "run along the homotopy path and solve the actual system");
    data->callback->functionInitialEquations(data, threadData);

    data->simulationInfo->homotopyUsed = 1;
    messageClose(LOG_INIT);
  }

  storeRelations(data);

  /* check for over-determined systems */
  retVal = data->callback->functionRemovedInitialEquations(data, threadData);

  if (!retVal)
    infoStreamPrint(LOG_STDOUT, 0, "The initialization finished successfully %s homotopy method.", data->simulationInfo->homotopyUsed ? "with" : "without");

  TRACE_POP
  return retVal;
}

/*! \fn static char *mapToDymolaVars(const char *varname)
 *
 *  \param [in]  [varname]
 *
 *  converts a given variable name into dymola style
 *  ** der(foo.foo2) -> foo.der(foo2)
 *  ** foo.foo2[1,2,3] -> foo.foo2[1, 2, 3]
 *
 *  \author lochel
 */
static char *mapToDymolaVars(const char *varname)
{
  unsigned int varnameSize = strlen(varname);
  unsigned int level = 0;
  unsigned int i=0, j=0, pos=0;
  char* newVarname = NULL;
  unsigned int newVarnameSize = 0;

  newVarnameSize = varnameSize;
  for(i=0; i<varnameSize; i++)
  {
    if(varname[i] == '[')
      level++;
    else if(varname[i] == ']')
      level--;

    if(level > 0 && varname[i] == ',' && varname[i+1] != ' ')
      newVarnameSize++;
  }

  newVarname = (char*)malloc((newVarnameSize+1) * sizeof(char));
  for(i=0,j=0; i<newVarnameSize; i++,j++)
  {
    if(varname[j] == '[')
      level++;
    else if(varname[j] == ']')
      level--;

    newVarname[i] = varname[j];
    if(level > 0 && varname[j] == ',' && varname[j+1] != ' ')
    {
      i++;
      newVarname[i] = ' ';
    }
  }
  newVarname[newVarnameSize] = '\0';

  while(!memcmp((const void*)newVarname, (const void*)"der(", 4*sizeof(char)))
  {
    for(pos=newVarnameSize; pos>=4; pos--)
      if(newVarname[pos] == '.')
        break;

    if(pos == 3)
      break;

    memcpy((void*)newVarname, (const void*)(newVarname+4), (pos-3)*sizeof(char));
    memcpy((void*)(newVarname+pos-3), (const void*)"der(", 4*sizeof(char));
  }

  return newVarname;
}

#if !defined(OMC_MINIMAL_RUNTIME)
/*! \fn int importStartValues(DATA *data, const char *pInitFile, const double initTime)
 *
 *  \param [ref] [data]
 *  \param [in]  [pInitFile]
 *  \param [in]  [initTime]
 *
 *  \author lochel
 */
int importStartValues(DATA *data, threadData_t *threadData, const char *pInitFile, const double initTime)
{
  ModelicaMatReader reader;
  ModelicaMatVariable_t *pVar = NULL;
  double value;
  const char *pError = NULL;
  char* newVarname = NULL;

  MODEL_DATA *mData = data->modelData;
  long i;

  infoStreamPrint(LOG_INIT, 0, "import start values\nfile: %s\ntime: %g", pInitFile, initTime);

  if(!strcmp(data->modelData->resultFileName, pInitFile))
  {
    errorStreamPrint(LOG_INIT, 0, "Cannot import a result file for initialization that is also the current output file <%s>.\nConsider redirecting the output result file (-r=<new_res.mat>) or renaming the result file that is used for initialization import.", pInitFile);
    return 1;
  }

  pError = omc_new_matlab4_reader(pInitFile, &reader);
  if(pError)
  {
    throwStreamPrint(threadData, "unable to read input-file <%s> [%s]", pInitFile, pError);
    return 1;
  }
  else
  {
    infoStreamPrint(LOG_INIT, 0, "import real variables");
    for(i=0; i<mData->nVariablesReal; ++i) {
      pVar = omc_matlab4_find_var(&reader, mData->realVarsData[i].info.name);

      if(!pVar) {
        newVarname = mapToDymolaVars(mData->realVarsData[i].info.name);
        pVar = omc_matlab4_find_var(&reader, newVarname);
        free(newVarname);
      }

      if(pVar) {
        omc_matlab4_val(&(mData->realVarsData[i].attribute.start), &reader, pVar, initTime);
        infoStreamPrint(LOG_INIT, 0, "| %s(start=%g)", mData->realVarsData[i].info.name, mData->realVarsData[i].attribute.start);
      } else if((strlen(mData->realVarsData[i].info.name) > 0) &&
              (mData->realVarsData[i].info.name[0] != '$') &&
              (strncmp(mData->realVarsData[i].info.name, "der($", 5) != 0)) {
        /* skip warnings about self-generated variables */
        warningStreamPrint(LOG_INIT, 0, "unable to import real variable %s from given file", mData->realVarsData[i].info.name);
      }
    }

    infoStreamPrint(LOG_INIT, 0, "import real parameters");
    for(i=0; i<mData->nParametersReal; ++i) {
      pVar = omc_matlab4_find_var(&reader, mData->realParameterData[i].info.name);

      if(!pVar) {
        newVarname = mapToDymolaVars(mData->realParameterData[i].info.name);
        pVar = omc_matlab4_find_var(&reader, newVarname);
        free(newVarname);
      }

      if(pVar) {
        omc_matlab4_val(&(mData->realParameterData[i].attribute.start), &reader, pVar, initTime);
        data->simulationInfo->realParameter[i] = mData->realParameterData[i].attribute.start;
        infoStreamPrint(LOG_INIT, 0, "| %s(start=%g)", mData->realParameterData[i].info.name, mData->realParameterData[i].attribute.start);
      } else {
        warningStreamPrint(LOG_INIT, 0, "unable to import real parameter %s from given file", mData->realParameterData[i].info.name);
      }
    }

    infoStreamPrint(LOG_INIT, 0, "import real discrete");
    for(i=mData->nVariablesReal-mData->nDiscreteReal; i<mData->nDiscreteReal; ++i) {
      pVar = omc_matlab4_find_var(&reader, mData->realParameterData[i].info.name);

      if(!pVar) {
        newVarname = mapToDymolaVars(mData->realParameterData[i].info.name);
        pVar = omc_matlab4_find_var(&reader, newVarname);
        free(newVarname);
      }

      if(pVar) {
        omc_matlab4_val(&(mData->realParameterData[i].attribute.start), &reader, pVar, initTime);
        infoStreamPrint(LOG_INIT, 0, "| %s(start=%g)", mData->realParameterData[i].info.name, mData->realParameterData[i].attribute.start);
      } else {
        warningStreamPrint(LOG_INIT, 0, "unable to import real parameter %s from given file", mData->realParameterData[i].info.name);
      }
    }

    infoStreamPrint(LOG_INIT, 0, "import integer parameters");
    for(i=0; i<mData->nParametersInteger; ++i)
    {
      pVar = omc_matlab4_find_var(&reader, mData->integerParameterData[i].info.name);

      if (!pVar) {
        newVarname = mapToDymolaVars(mData->integerParameterData[i].info.name);
        pVar = omc_matlab4_find_var(&reader, newVarname);
        free(newVarname);
      }

      if (pVar) {
        omc_matlab4_val(&value, &reader, pVar, initTime);
        mData->integerParameterData[i].attribute.start = (modelica_integer)value;
        data->simulationInfo->integerParameter[i] = (modelica_integer)value;
        infoStreamPrint(LOG_INIT, 0, "| %s(start=%ld)", mData->integerParameterData[i].info.name, mData->integerParameterData[i].attribute.start);
      } else {
        warningStreamPrint(LOG_INIT, 0, "unable to import integer parameter %s from given file", mData->integerParameterData[i].info.name);
      }
    }

    infoStreamPrint(LOG_INIT, 0, "import boolean parameters");
    for(i=0; i<mData->nParametersBoolean; ++i) {
      pVar = omc_matlab4_find_var(&reader, mData->booleanParameterData[i].info.name);

      if(!pVar) {
        newVarname = mapToDymolaVars(mData->booleanParameterData[i].info.name);
        pVar = omc_matlab4_find_var(&reader, newVarname);
        free(newVarname);
      }

      if(pVar) {
        omc_matlab4_val(&value, &reader, pVar, initTime);
        mData->booleanParameterData[i].attribute.start = (modelica_boolean)value;
        data->simulationInfo->booleanParameter[i] = (modelica_boolean)value;
        infoStreamPrint(LOG_INIT, 0, "| %s(start=%s)", mData->booleanParameterData[i].info.name, mData->booleanParameterData[i].attribute.start ? "true" : "false");
      } else {
        warningStreamPrint(LOG_INIT, 0, "unable to import boolean parameter %s from given file", mData->booleanParameterData[i].info.name);
      }
    }
    omc_free_matlab4_reader(&reader);
  }

  return 0;
}
#endif

/*! \fn initSample
 *
 *  \param [ref] [data]
 *  \param [in]  [startTime]
 *  \param [in]  [stopTime]
 *
 *  This function initializes sample-events.
 */
void initSample(DATA* data, threadData_t *threadData, double startTime, double stopTime)
{
  TRACE_PUSH
  long i;

  data->callback->function_initSample(data, threadData);              /* set-up sample */
  data->simulationInfo->nextSampleEvent = NAN;  /* should never be reached */
  for(i=0; i<data->modelData->nSamples; ++i) {
    if(startTime < data->modelData->samplesInfo[i].start) {
      data->simulationInfo->nextSampleTimes[i] = data->modelData->samplesInfo[i].start;
    } else {
      data->simulationInfo->nextSampleTimes[i] = data->modelData->samplesInfo[i].start + ceil((startTime-data->modelData->samplesInfo[i].start) / data->modelData->samplesInfo[i].interval) * data->modelData->samplesInfo[i].interval;
    }

    if((i == 0) || (data->simulationInfo->nextSampleTimes[i] < data->simulationInfo->nextSampleEvent)) {
      data->simulationInfo->nextSampleEvent = data->simulationInfo->nextSampleTimes[i];
    }
  }

  if(stopTime < data->simulationInfo->nextSampleEvent) {
    debugStreamPrint(LOG_EVENTS, 0, "there are no sample-events");
  } else {
    debugStreamPrint(LOG_EVENTS, 0, "first sample-event at t = %g", data->simulationInfo->nextSampleEvent);
  }

  TRACE_POP
}

/*! \fn int initialization(DATA *data, const char* pInitMethod, const char* pOptiMethod, const char* pInitFile, double initTime)
 *
 *  \param [ref] [data]
 *  \param [in]  [pInitMethod] user defined initialization method
 *  \param [in]  [pInitFile] extra argument for initialization-method "file"
 *  \param [in]  [initTime] extra argument for initialization-method "file"
 *
 *  \author lochel
 */
int initialization(DATA *data, threadData_t *threadData, const char* pInitMethod, const char* pInitFile, double initTime)
{
  TRACE_PUSH
  int initMethod = IIM_SYMBOLIC; /* default method */
  int retVal = -1;
  int i;

  infoStreamPrint(LOG_INIT, 0, "### START INITIALIZATION ###");

  setAllParamsToStart(data);

#if !defined(OMC_MINIMAL_RUNTIME)
  /* import start values from extern mat-file */
  if(pInitFile && strcmp(pInitFile, ""))
  {
    data->callback->updateBoundParameters(data, threadData);
    data->callback->updateBoundVariableAttributes(data, threadData);

    if(importStartValues(data, threadData, pInitFile, initTime)) {
      TRACE_POP
      return 1;
    }
  }
#endif
  /* set up all variables with their start-values */
  setAllVarsToStart(data);

  if(!(pInitFile && strcmp(pInitFile, ""))) {
    data->callback->updateBoundParameters(data, threadData);
    data->callback->updateBoundVariableAttributes(data, threadData);
  }

  /* update static data of linear/non-linear system solvers */
  updateStaticDataOfLinearSystems(data, threadData);
  updateStaticDataOfNonlinearSystems(data, threadData);

  /* if there are user-specified options, use them! */
  if (pInitMethod && strcmp(pInitMethod, "")) {
    initMethod = IIM_UNKNOWN;

    for (i=1; i<IIM_MAX; ++i) {
      if(!strcmp(pInitMethod, INIT_METHOD_NAME[i])) {
        initMethod = i;
      }
    }

    if(initMethod == IIM_UNKNOWN) {
      warningStreamPrint(LOG_STDOUT, 0, "unrecognized option -iim %s", pInitMethod);
      warningStreamPrint(LOG_STDOUT, 0, "current options are:");
      for (i=1; i<IIM_MAX; ++i) {
        warningStreamPrint(LOG_STDOUT, 0, "| %-15s [%s]", INIT_METHOD_NAME[i], INIT_METHOD_DESC[i]);
      }
      throwStreamPrint(threadData, "see last warning");
    }
  }

  infoStreamPrint(LOG_INIT, 0, "initialization method: %-15s [%s]", INIT_METHOD_NAME[initMethod], INIT_METHOD_DESC[initMethod]);

  /* start with the real initialization */
  data->simulationInfo->initial = 1;             /* to evaluate when-equations with initial()-conditions */

  /* initialize all (nonlinear|linear|mixed) systems
   * This is a workaround and should be removed as soon as possible.
   */
#if !defined(OMC_NUM_NONLINEAR_SYSTEMS) || OMC_NUM_NONLINEAR_SYSTEMS>0
  for(i=0; i<data->modelData->nNonLinearSystems; ++i) {
    data->simulationInfo->nonlinearSystemData[i].solved = 1;
  }
#endif
#if !defined(OMC_NUM_LINEAR_SYSTEMS) || OMC_NUM_LINEAR_SYSTEMS>0
  for(i=0; i<data->modelData->nLinearSystems; ++i) {
    data->simulationInfo->linearSystemData[i].solved = 1;
  }
#endif
#if !defined(OMC_NUM_MIXED_SYSTEMS) || OMC_NUM_MIXED_SYSTEMS>0
  for(i=0; i<data->modelData->nMixedSystems; ++i) {
    data->simulationInfo->mixedSystemData[i].solved = 1;
  }
#endif
  /* end workaround */

  /* select the right initialization-method */
  if(IIM_NONE == initMethod) {
    retVal = 0;
  } else if(IIM_SYMBOLIC == initMethod) {
    retVal = symbolic_initialization(data, threadData);
  } else {
    throwStreamPrint(threadData, "unsupported option -iim");
  }

  /* check for unsolved (nonlinear|linear|mixed) systems
   * This is a workaround and should be removed as soon as possible.
   */
  if(check_nonlinear_solutions(data, 1)) {
    retVal = -2;
  } else if(check_linear_solutions(data, 1)) {
    retVal = -3;
  } else if(check_mixed_solutions(data, 1)) {
    retVal = -4;
  }
  /* end workaround */

#if !defined(OMC_MINIMAL_LOGGING)
  dumpInitialSolution(data);
  infoStreamPrint(LOG_INIT, 0, "### END INITIALIZATION ###");
#endif

  overwriteOldSimulationData(data);       /* overwrite the whole ring-buffer with initialized values */
  storePreValues(data);                   /* save pre-values */
  updateDiscreteSystem(data, threadData); /* evaluate discrete variables (event iteration) */
  saveZeroCrossings(data, threadData);

  /* do pivoting for dynamic state selection if selection changed try again */
#if !defined(OMC_NO_STATESELECTION)
  if(stateSelection(data, threadData, 0, 1) == 1) {
    if(stateSelection(data, threadData, 1, 1) == 1) {
      /* report a warning about strange start values */
      warningStreamPrint(LOG_STDOUT, 0, "Cannot initialize the dynamic state selection in an unique way. Use -lv LOG_DSS to see the switching state set.");
    }
  }
#endif

  data->simulationInfo->initial = 0;
  /* initialization is done */

  initSample(data, threadData, data->simulationInfo->startTime, data->simulationInfo->stopTime);
  data->callback->function_storeDelayed(data, threadData);
  data->callback->function_updateRelations(data, threadData, 1);
  initSynchronous(data, threadData, data->simulationInfo->startTime);

#if !defined(OMC_MINIMAL_LOGGING)
  printRelations(data, LOG_EVENTS);
  printZeroCrossings(data, LOG_EVENTS);
#endif

  /* valid system for the first time! */
  TRACE_POP
  return retVal;
}