/* Linearization */
#include "Room_model.h"
#if defined(__cplusplus)
extern "C" {
#endif

const char *Room_linear_model_frame()
{
  return "model linear_Room\n  parameter Integer n = 3; // states\n  parameter Integer k = 2; // top-level inputs\n  parameter Integer l = 14; // top-level outputs\n"
  "  parameter Real x0[3] = {%s};\n"
  "  parameter Real u0[2] = {%s};\n"
  "  parameter Real A[3,3] = [%s];\n"
  "  parameter Real B[3,2] = [%s];\n"
  "  parameter Real C[14,3] = [%s];\n"
  "  parameter Real D[14,2] = [%s];\n"
  "  Real x[3](start=x0);\n"
  "  input Real u[2](start= u0);\n"
  "  output Real y[14];\n"
  "\n    Real 'x_vol.dynBal.m' = x[1];\n  Real 'x_vol.dynBal.medium.Xi[1]' = x[2];\n  Real 'x_vol.hOut_internal' = x[3];\n  Real 'u_heatingControlPort1.turn_heating_off1.counter' = u[1];\n  Real 'u_heatingControlPort1.turn_heating_on1.counter' = u[2];\n  Real 'y_heatingControlPort1.set_hysteresis_intervallum1.counter' = y[1];\n  Real 'y_heatingControlPort1.set_hysteresis_intervallum1.hysteresis_intervallum[1]' = y[2];\n  Real 'y_heatingControlPort1.set_hysteresis_intervallum1.hysteresis_intervallum[2]' = y[3];\n  Real 'y_heatingControlPort1.set_hysteresis_intervallum1.hysteresis_intervallum[3]' = y[4];\n  Real 'y_temperatureStreamPort1.measured_temperature1.counter' = y[5];\n  Real 'y_temperatureStreamPort1.measured_temperature1.measured_temperature[1]' = y[6];\n  Real 'y_temperatureStreamPort1.measured_temperature1.measured_temperature[2]' = y[7];\n  Real 'y_temperatureStreamPort1.measured_temperature1.measured_temperature[3]' = y[8];\n  Real 'y_thermostatControlPort1.set_target_temperature1.counter' = y[9];\n  Real 'y_thermostatControlPort1.set_target_temperature1.target_temperature[1]' = y[10];\n  Real 'y_thermostatControlPort1.set_target_temperature1.target_temperature[2]' = y[11];\n  Real 'y_thermostatControlPort1.set_target_temperature1.target_temperature[3]' = y[12];\n  Real 'y_thermostatControlPort1.turn_thermostat_off1.counter' = y[13];\n  Real 'y_thermostatControlPort1.turn_thermostat_on1.counter' = y[14];\n\n"
  "equation\n  der(x) = A * x + B * u;\n  y = C * x + D * u;\nend linear_Room;\n";
}
const char *Room_linear_model_datarecovery_frame()
{
  return "model linear_Room\n  parameter Integer n = 3; // states\n  parameter Integer k = 2; // top-level inputs\n  parameter Integer l = 14; // top-level outputs\n  parameter Integer nz = 36; // data recovery variables\n"
  "  parameter Real x0[3] = {%s};\n"
  "  parameter Real u0[2] = {%s};\n"
  "  parameter Real z0[36] = {%s};\n"
  "  parameter Real A[3,3] = [%s];\n"
  "  parameter Real B[3,2] = [%s];\n"
  "  parameter Real C[14,3] = [%s];\n"
  "  parameter Real D[14,2] = [%s];\n"
  "  parameter Real Cz[36,3] = [%s];\n"
  "  parameter Real Dz[36,2] = [%s];\n"
  "  Real x[3](start=x0);\n"
  "  input Real u[2](start= u0);\n"
  "  output Real y[14];\n"
  "  output Real z[36];\n"
  "\n  Real 'x_vol.dynBal.m' = x[1];\n  Real 'x_vol.dynBal.medium.Xi[1]' = x[2];\n  Real 'x_vol.hOut_internal' = x[3];\n  Real 'u_heatingControlPort1.turn_heating_off1.counter' = u[1];\n  Real 'u_heatingControlPort1.turn_heating_on1.counter' = u[2];\n  Real 'y_heatingControlPort1.set_hysteresis_intervallum1.counter' = y[1];\n  Real 'y_heatingControlPort1.set_hysteresis_intervallum1.hysteresis_intervallum[1]' = y[2];\n  Real 'y_heatingControlPort1.set_hysteresis_intervallum1.hysteresis_intervallum[2]' = y[3];\n  Real 'y_heatingControlPort1.set_hysteresis_intervallum1.hysteresis_intervallum[3]' = y[4];\n  Real 'y_temperatureStreamPort1.measured_temperature1.counter' = y[5];\n  Real 'y_temperatureStreamPort1.measured_temperature1.measured_temperature[1]' = y[6];\n  Real 'y_temperatureStreamPort1.measured_temperature1.measured_temperature[2]' = y[7];\n  Real 'y_temperatureStreamPort1.measured_temperature1.measured_temperature[3]' = y[8];\n  Real 'y_thermostatControlPort1.set_target_temperature1.counter' = y[9];\n  Real 'y_thermostatControlPort1.set_target_temperature1.target_temperature[1]' = y[10];\n  Real 'y_thermostatControlPort1.set_target_temperature1.target_temperature[2]' = y[11];\n  Real 'y_thermostatControlPort1.set_target_temperature1.target_temperature[3]' = y[12];\n  Real 'y_thermostatControlPort1.turn_thermostat_off1.counter' = y[13];\n  Real 'y_thermostatControlPort1.turn_thermostat_on1.counter' = y[14];\n  Real 'z_der(heaCap.T)' = z[1];\n  Real 'z_der(vol.dynBal.U)' = z[2];\n  Real 'z_der(vol.dynBal.mXi[1])' = z[3];\n  Real 'z_der(vol.dynBal.medium.u)' = z[4];\n  Real 'z_booleanToReal1.y' = z[5];\n  Real 'z_heaCap.T' = z[6];\n  Real 'z_heaCap.der_T' = z[7];\n  Real 'z_heaCap.port.Q_flow' = z[8];\n  Real 'z_heatingControlPort1.set_hysteresis_intervallum1.hysteresis_intervallum[1]' = z[9];\n  Real 'z_heatingControlPort1.set_hysteresis_intervallum1.hysteresis_intervallum[2]' = z[10];\n  Real 'z_heatingControlPort1.set_hysteresis_intervallum1.hysteresis_intervallum[3]' = z[11];\n  Real 'z_preHea.port.Q_flow' = z[12];\n  Real 'z_temperatureStreamPort1.measured_temperature1.measured_temperature[1]' = z[13];\n  Real 'z_temperatureStreamPort1.measured_temperature1.measured_temperature[2]' = z[14];\n  Real 'z_temperatureStreamPort1.measured_temperature1.measured_temperature[3]' = z[15];\n  Real 'z_theCon.Q_flow' = z[16];\n  Real 'z_theCon.dT' = z[17];\n  Real 'z_thermostatControlPort1.set_target_temperature1.target_temperature[1]' = z[18];\n  Real 'z_thermostatControlPort1.set_target_temperature1.target_temperature[2]' = z[19];\n  Real 'z_thermostatControlPort1.set_target_temperature1.target_temperature[3]' = z[20];\n  Real 'z_vol.dynBal.Hb_flow' = z[21];\n  Real 'z_vol.dynBal.U' = z[22];\n  Real 'z_vol.dynBal.mWat_flow_internal' = z[23];\n  Real 'z_vol.dynBal.mXi[1]' = z[24];\n  Real 'z_vol.dynBal.mbXi_flow[1]' = z[25];\n  Real 'z_vol.dynBal.mb_flow' = z[26];\n  Real 'z_vol.dynBal.medium.MM' = z[27];\n  Real 'z_vol.dynBal.medium.R' = z[28];\n  Real 'z_vol.dynBal.medium.T' = z[29];\n  Real 'z_vol.dynBal.medium.X[2]' = z[30];\n  Real 'z_vol.dynBal.medium.d' = z[31];\n  Real 'z_vol.dynBal.medium.dT' = z[32];\n  Real 'z_vol.dynBal.medium.p' = z[33];\n  Real 'z_vol.dynBal.medium.p_bar' = z[34];\n  Real 'z_vol.dynBal.medium.u' = z[35];\n  Real 'z_vol.heatPort.Q_flow' = z[36];\n\n"
  "equation\n  der(x) = A * x + B * u;\n  y = C * x + D * u;\n  z = Cz * x + Dz * u;\nend linear_Room;\n";
}
#if defined(__cplusplus)
}
#endif

