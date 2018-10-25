/* Linearization */
#include "ThermostatMonitor_CriticalTemperatureMonitor_model.h"
#if defined(__cplusplus)
extern "C" {
#endif

const char *ThermostatMonitor_CriticalTemperatureMonitor_linear_model_frame()
{
  return "model linear_ThermostatMonitor_CriticalTemperatureMonitor\n  parameter Integer n = 0; // states\n  parameter Integer k = 4; // top-level inputs\n  parameter Integer l = 1; // top-level outputs\n"
  "  parameter Real x0[0] = {%s};\n"
  "  parameter Real u0[4] = {%s};\n"
  "  parameter Real A[0,0] = zeros(0,0);%s\n"
  "  parameter Real B[0,4] = zeros(0,4);%s\n"
  "  parameter Real C[1,0] = zeros(1,0);%s\n"
  "  parameter Real D[1,4] = [%s];\n"
  "  Real x[0];\n"
  "  input Real u[4](start= u0);\n"
  "  output Real y[1];\n"
  "\n    Real 'u_hysteresis' = u[1];\n  Real 'u_request' = u[2];\n  Real 'u_target' = u[3];\n  Real 'u_temperature' = u[4];\n  Real 'y_reply' = y[1];\n\n"
  "equation\n  der(x) = A * x + B * u;\n  y = C * x + D * u;\nend linear_ThermostatMonitor_CriticalTemperatureMonitor;\n";
}
const char *ThermostatMonitor_CriticalTemperatureMonitor_linear_model_datarecovery_frame()
{
  return "model linear_ThermostatMonitor_CriticalTemperatureMonitor\n  parameter Integer n = 0; // states\n  parameter Integer k = 4; // top-level inputs\n  parameter Integer l = 1; // top-level outputs\n  parameter Integer nz = 7; // data recovery variables\n"
  "  parameter Real x0[0] = {%s};\n"
  "  parameter Real u0[4] = {%s};\n"
  "  parameter Real z0[7] = {%s};\n"
  "  parameter Real A[0,0] = zeros(0,0);%s\n"
  "  parameter Real B[0,4] = zeros(0,4);%s\n"
  "  parameter Real C[1,0] = zeros(1,0);%s\n"
  "  parameter Real D[1,4] = [%s];\n"
  "  parameter Real Cz[7,0] = zeros(7,0);%s\n"
  "  parameter Real Dz[7,4] = [%s];\n"
  "  Real x[0];\n"
  "  input Real u[4](start= u0);\n"
  "  output Real y[1];\n"
  "  output Real z[7];\n"
  "\n  Real 'u_hysteresis' = u[1];\n  Real 'u_request' = u[2];\n  Real 'u_target' = u[3];\n  Real 'u_temperature' = u[4];\n  Real 'y_reply' = y[1];\n  Real 'z_currentBandWith' = z[1];\n  Real 'z_currentTarget' = z[2];\n  Real 'z_hysteresis' = z[3];\n  Real 'z_reply' = z[4];\n  Real 'z_request' = z[5];\n  Real 'z_target' = z[6];\n  Real 'z_temperature' = z[7];\n\n"
  "equation\n  der(x) = A * x + B * u;\n  y = C * x + D * u;\n  z = Cz * x + Dz * u;\nend linear_ThermostatMonitor_CriticalTemperatureMonitor;\n";
}
#if defined(__cplusplus)
}
#endif

