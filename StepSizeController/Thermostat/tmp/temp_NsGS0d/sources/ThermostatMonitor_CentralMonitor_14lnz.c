/* Linearization */
#include "ThermostatMonitor_CentralMonitor_model.h"
#if defined(__cplusplus)
extern "C" {
#endif

const char *ThermostatMonitor_CentralMonitor_linear_model_frame()
{
  return "model linear_ThermostatMonitor_CentralMonitor\n  parameter Integer n = 5; // states\n  parameter Integer k = 4; // top-level inputs\n  parameter Integer l = 8; // top-level outputs\n"
  "  parameter Real x0[5] = {%s};\n"
  "  parameter Real u0[4] = {%s};\n"
  "  parameter Real A[5,5] = [%s];\n"
  "  parameter Real B[5,4] = [%s];\n"
  "  parameter Real C[8,5] = [%s];\n"
  "  parameter Real D[8,4] = [%s];\n"
  "  Real x[5](start=x0);\n"
  "  input Real u[4](start= u0);\n"
  "  output Real y[8];\n"
  "\n    Real 'x_lastHeatReply' = x[1];\n  Real 'x_lastTempReply' = x[2];\n  Real 'x_lastTermReply' = x[3];\n  Real 'x_nextHeartBeat' = x[4];\n  Real 'x_state' = x[5];\n  Real 'u_heatOnPermission' = u[1];\n  Real 'u_heatReply' = u[2];\n  Real 'u_tempReply' = u[3];\n  Real 'u_termReply' = u[4];\n  Real 'y_heatOnGrant' = y[1];\n  Real 'y_heatReq' = y[2];\n  Real 'y_lastHeatReply' = y[3];\n  Real 'y_lastTempReply' = y[4];\n  Real 'y_lastTermReply' = y[5];\n  Real 'y_state' = y[6];\n  Real 'y_tempReq' = y[7];\n  Real 'y_termReq' = y[8];\n\n"
  "equation\n  der(x) = A * x + B * u;\n  y = C * x + D * u;\nend linear_ThermostatMonitor_CentralMonitor;\n";
}
const char *ThermostatMonitor_CentralMonitor_linear_model_datarecovery_frame()
{
  return "model linear_ThermostatMonitor_CentralMonitor\n  parameter Integer n = 5; // states\n  parameter Integer k = 4; // top-level inputs\n  parameter Integer l = 8; // top-level outputs\n  parameter Integer nz = 6; // data recovery variables\n"
  "  parameter Real x0[5] = {%s};\n"
  "  parameter Real u0[4] = {%s};\n"
  "  parameter Real z0[6] = {%s};\n"
  "  parameter Real A[5,5] = [%s];\n"
  "  parameter Real B[5,4] = [%s];\n"
  "  parameter Real C[8,5] = [%s];\n"
  "  parameter Real D[8,4] = [%s];\n"
  "  parameter Real Cz[6,5] = [%s];\n"
  "  parameter Real Dz[6,4] = [%s];\n"
  "  Real x[5](start=x0);\n"
  "  input Real u[4](start= u0);\n"
  "  output Real y[8];\n"
  "  output Real z[6];\n"
  "\n  Real 'x_lastHeatReply' = x[1];\n  Real 'x_lastTempReply' = x[2];\n  Real 'x_lastTermReply' = x[3];\n  Real 'x_nextHeartBeat' = x[4];\n  Real 'x_state' = x[5];\n  Real 'u_heatOnPermission' = u[1];\n  Real 'u_heatReply' = u[2];\n  Real 'u_tempReply' = u[3];\n  Real 'u_termReply' = u[4];\n  Real 'y_heatOnGrant' = y[1];\n  Real 'y_heatReq' = y[2];\n  Real 'y_lastHeatReply' = y[3];\n  Real 'y_lastTempReply' = y[4];\n  Real 'y_lastTermReply' = y[5];\n  Real 'y_state' = y[6];\n  Real 'y_tempReq' = y[7];\n  Real 'y_termReq' = y[8];\n  Real 'z_heatReply' = z[1];\n  Real 'z_heatReq' = z[2];\n  Real 'z_tempReply' = z[3];\n  Real 'z_tempReq' = z[4];\n  Real 'z_termReply' = z[5];\n  Real 'z_termReq' = z[6];\n\n"
  "equation\n  der(x) = A * x + B * u;\n  y = C * x + D * u;\n  z = Cz * x + Dz * u;\nend linear_ThermostatMonitor_CentralMonitor;\n";
}
#if defined(__cplusplus)
}
#endif

