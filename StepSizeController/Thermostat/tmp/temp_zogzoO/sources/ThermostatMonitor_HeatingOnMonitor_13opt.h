#if defined(__cplusplus)
  extern "C" {
#endif
  int ThermostatMonitor_HeatingOnMonitor_mayer(DATA* data, modelica_real** res, short*);
  int ThermostatMonitor_HeatingOnMonitor_lagrange(DATA* data, modelica_real** res, short *, short *);
  int ThermostatMonitor_HeatingOnMonitor_pickUpBoundsForInputsInOptimization(DATA* data, modelica_real* min, modelica_real* max, modelica_real*nominal, modelica_boolean *useNominal, char ** name, modelica_real * start, modelica_real * startTimeOpt);
  int ThermostatMonitor_HeatingOnMonitor_setInputData(DATA *data, const modelica_boolean file);
  int ThermostatMonitor_HeatingOnMonitor_getTimeGrid(DATA *data, modelica_integer * nsi, modelica_real**t);
#if defined(__cplusplus)
}
#endif