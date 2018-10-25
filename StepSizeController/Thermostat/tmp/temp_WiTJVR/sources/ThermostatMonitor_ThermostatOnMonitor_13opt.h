#if defined(__cplusplus)
  extern "C" {
#endif
  int ThermostatMonitor_ThermostatOnMonitor_mayer(DATA* data, modelica_real** res, short*);
  int ThermostatMonitor_ThermostatOnMonitor_lagrange(DATA* data, modelica_real** res, short *, short *);
  int ThermostatMonitor_ThermostatOnMonitor_pickUpBoundsForInputsInOptimization(DATA* data, modelica_real* min, modelica_real* max, modelica_real*nominal, modelica_boolean *useNominal, char ** name, modelica_real * start, modelica_real * startTimeOpt);
  int ThermostatMonitor_ThermostatOnMonitor_setInputData(DATA *data, const modelica_boolean file);
  int ThermostatMonitor_ThermostatOnMonitor_getTimeGrid(DATA *data, modelica_integer * nsi, modelica_real**t);
#if defined(__cplusplus)
}
#endif