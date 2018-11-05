#include <simulation_data.h>

void ThermostatMonitor_HeatingOnMonitor_read_input_fmu(MODEL_DATA* modelData, SIMULATION_INFO* simulationInfo)
{
  simulationInfo->startTime = 0.0;
  simulationInfo->stopTime = 1.0;
  simulationInfo->stepSize = 0.002;
  simulationInfo->tolerance = 1e-06;
  simulationInfo->solverMethod = "dassl";
  simulationInfo->outputFormat = "mat";
  simulationInfo->variableFilter = ".*";
  simulationInfo->OPENMODELICAHOME = "/usr";
  modelData->realVarsData[0].info.id = 1000;
  modelData->realVarsData[0].info.name = "reply";
  modelData->realVarsData[0].info.comment = "";
  modelData->realVarsData[0].info.info.filename = "/home/farkasr/git/OMSimulator/StepSizeController/Thermostat/ThermostatMonitor.mo";
  modelData->realVarsData[0].info.info.lineStart = 32;
  modelData->realVarsData[0].info.info.colStart = 5;
  modelData->realVarsData[0].info.info.lineEnd = 32;
  modelData->realVarsData[0].info.info.colEnd = 48;
  modelData->realVarsData[0].info.info.readonly = 0;
  modelData->realVarsData[0].attribute.unit = "";
  modelData->realVarsData[0].attribute.displayUnit = "";
  modelData->realVarsData[0].attribute.min = -DBL_MAX;
  modelData->realVarsData[0].attribute.max = DBL_MAX;
  modelData->realVarsData[0].attribute.fixed = 0;
  modelData->realVarsData[0].attribute.useNominal = 0;
  modelData->realVarsData[0].attribute.nominal = 1.0;
  modelData->realVarsData[0].attribute.start = 0.0;
  modelData->realVarsData[1].info.id = 1001;
  modelData->realVarsData[1].info.name = "request";
  modelData->realVarsData[1].info.comment = "";
  modelData->realVarsData[1].info.info.filename = "/home/farkasr/git/OMSimulator/StepSizeController/Thermostat/ThermostatMonitor.mo";
  modelData->realVarsData[1].info.info.lineStart = 31;
  modelData->realVarsData[1].info.info.colStart = 5;
  modelData->realVarsData[1].info.info.lineEnd = 31;
  modelData->realVarsData[1].info.info.colEnd = 49;
  modelData->realVarsData[1].info.info.readonly = 0;
  modelData->realVarsData[1].attribute.unit = "";
  modelData->realVarsData[1].attribute.displayUnit = "";
  modelData->realVarsData[1].attribute.min = -DBL_MAX;
  modelData->realVarsData[1].attribute.max = DBL_MAX;
  modelData->realVarsData[1].attribute.fixed = 1;
  modelData->realVarsData[1].attribute.useNominal = 0;
  modelData->realVarsData[1].attribute.nominal = 1.0;
  modelData->realVarsData[1].attribute.start = 0.0;
  modelData->integerVarsData[0].info.id = 1002;
  modelData->integerVarsData[0].info.name = "turnOff";
  modelData->integerVarsData[0].info.comment = "";
  modelData->integerVarsData[0].info.info.filename = "/home/farkasr/git/OMSimulator/StepSizeController/Thermostat/ThermostatMonitor.mo";
  modelData->integerVarsData[0].info.info.lineStart = 30;
  modelData->integerVarsData[0].info.info.colStart = 5;
  modelData->integerVarsData[0].info.info.lineEnd = 30;
  modelData->integerVarsData[0].info.info.colEnd = 52;
  modelData->integerVarsData[0].info.info.readonly = 0;
  modelData->integerVarsData[0].attribute.min = -DBL_MAX;
  modelData->integerVarsData[0].attribute.max = DBL_MAX;
  modelData->integerVarsData[0].attribute.fixed = 1;
  modelData->integerVarsData[0].attribute.start = 0;
  modelData->integerVarsData[1].info.id = 1003;
  modelData->integerVarsData[1].info.name = "turnOn";
  modelData->integerVarsData[1].info.comment = "";
  modelData->integerVarsData[1].info.info.filename = "/home/farkasr/git/OMSimulator/StepSizeController/Thermostat/ThermostatMonitor.mo";
  modelData->integerVarsData[1].info.info.lineStart = 29;
  modelData->integerVarsData[1].info.info.colStart = 5;
  modelData->integerVarsData[1].info.info.lineEnd = 29;
  modelData->integerVarsData[1].info.info.colEnd = 51;
  modelData->integerVarsData[1].info.info.readonly = 0;
  modelData->integerVarsData[1].attribute.min = -DBL_MAX;
  modelData->integerVarsData[1].attribute.max = DBL_MAX;
  modelData->integerVarsData[1].attribute.fixed = 1;
  modelData->integerVarsData[1].attribute.start = 0;
  modelData->booleanVarsData[0].info.id = 1004;
  modelData->booleanVarsData[0].info.name = "turnedon";
  modelData->booleanVarsData[0].info.comment = "";
  modelData->booleanVarsData[0].info.info.filename = "/home/farkasr/git/OMSimulator/StepSizeController/Thermostat/ThermostatMonitor.mo";
  modelData->booleanVarsData[0].info.info.lineStart = 33;
  modelData->booleanVarsData[0].info.info.colStart = 5;
  modelData->booleanVarsData[0].info.info.lineEnd = 33;
  modelData->booleanVarsData[0].info.info.colEnd = 21;
  modelData->booleanVarsData[0].info.info.readonly = 0;
  modelData->booleanVarsData[0].attribute.fixed = 0;
  modelData->booleanVarsData[0].attribute.start = 0;
}