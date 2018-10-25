// define class name and unique id
#define MODEL_IDENTIFIER Room
#define MODEL_GUID "{6fd3eb57-df28-464a-834f-1522aa2e2e69}"

// include fmu header files, typedefs and macros
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "openmodelica.h"
#include "openmodelica_func.h"
#include "simulation_data.h"
#include "util/omc_error.h"
#include "Room_functions.h"
#include "simulation/solver/initialization/initialization.h"
#include "simulation/solver/events.h"
#include "fmu2_model_interface.h"

#ifdef __cplusplus
extern "C" {
#endif

void setStartValues(ModelInstance *comp);
void setDefaultStartValues(ModelInstance *comp);
void eventUpdate(ModelInstance* comp, fmi2EventInfo* eventInfo);
fmi2Real getReal(ModelInstance* comp, const fmi2ValueReference vr);
fmi2Status setReal(ModelInstance* comp, const fmi2ValueReference vr, const fmi2Real value);
fmi2Integer getInteger(ModelInstance* comp, const fmi2ValueReference vr);
fmi2Status setInteger(ModelInstance* comp, const fmi2ValueReference vr, const fmi2Integer value);
fmi2Boolean getBoolean(ModelInstance* comp, const fmi2ValueReference vr);
fmi2Status setBoolean(ModelInstance* comp, const fmi2ValueReference vr, const fmi2Boolean value);
fmi2String getString(ModelInstance* comp, const fmi2ValueReference vr);
fmi2Status setString(ModelInstance* comp, const fmi2ValueReference vr, fmi2String value);
fmi2Status setExternalFunction(ModelInstance* c, const fmi2ValueReference vr, const void* value);

// define model size
#define NUMBER_OF_STATES 3
#define NUMBER_OF_EVENT_INDICATORS 12
#define NUMBER_OF_REALS 159
#define NUMBER_OF_INTEGERS 24
#define NUMBER_OF_STRINGS 0
#define NUMBER_OF_BOOLEANS 60
#define NUMBER_OF_EXTERNALFUNCTIONS 0

// define variable data for model
#define $Pvol$PdynBal$Pm_vr 0 // "Mass of fluid"
#define $Pvol$PdynBal$Pmedium$PXi$lB1$rB_vr 1 // "Structurally independent mass fractions"
#define $Pvol$PhOut_internal_vr 2 // "Internal connector for leaving temperature of the component"
#define $P$DER$Pvol$PdynBal$Pm_vr 3 // "der(Mass of fluid)"
#define $P$DER$Pvol$PdynBal$Pmedium$PXi$lB1$rB_vr 4 // "der(Structurally independent mass fractions)"
#define $P$DER$Pvol$PhOut_internal_vr 5 // "der(Internal connector for leaving temperature of the component)"
#define $P$DER$PheaCap$PT_vr 6 // "Temperature of element"
#define $P$DER$Pvol$PdynBal$PU_vr 7 // "Internal energy of fluid"
#define $P$DER$Pvol$PdynBal$PmXi$lB1$rB_vr 8 // "Masses of independent components in the fluid"
#define $P$DER$Pvol$PdynBal$Pmedium$Pu_vr 9 // "Specific internal energy of medium"
#define $PbooleanToReal1$Py_vr 10 // "Connector of Real output signal"
#define $PheaCap$PT_vr 11 // "Temperature of element"
#define $PheaCap$Pder_T_vr 12 // "Time derivative of temperature (= der(T))"
#define $PheaCap$Pport$PQ_flow_vr 13 // "Heat flow rate (positive if flowing from outside into the component)"
#define $PheatingControlPort1$Pset_hysteresis_intervallum1$Physteresis_intervallum$lB1$rB_vr 14 
#define $PheatingControlPort1$Pset_hysteresis_intervallum1$Physteresis_intervallum$lB2$rB_vr 15 
#define $PheatingControlPort1$Pset_hysteresis_intervallum1$Physteresis_intervallum$lB3$rB_vr 16 
#define $PpreHea$Pport$PQ_flow_vr 17 // "Heat flow rate (positive if flowing from outside into the component)"
#define $PtemperatureStreamPort1$Pmeasured_temperature1$Pmeasured_temperature$lB1$rB_vr 18 
#define $PtemperatureStreamPort1$Pmeasured_temperature1$Pmeasured_temperature$lB2$rB_vr 19 
#define $PtemperatureStreamPort1$Pmeasured_temperature1$Pmeasured_temperature$lB3$rB_vr 20 
#define $PtheCon$PQ_flow_vr 21 // "Heat flow rate from port_a -> port_b"
#define $PtheCon$PdT_vr 22 // "port_a.T - port_b.T"
#define $PthermostatControlPort1$Pset_target_temperature1$Ptarget_temperature$lB1$rB_vr 23 
#define $PthermostatControlPort1$Pset_target_temperature1$Ptarget_temperature$lB2$rB_vr 24 
#define $PthermostatControlPort1$Pset_target_temperature1$Ptarget_temperature$lB3$rB_vr 25 
#define $Pvol$PdynBal$PHb_flow_vr 26 // "Enthalpy flow across boundaries or energy source/sink"
#define $Pvol$PdynBal$PU_vr 27 // "Internal energy of fluid"
#define $Pvol$PdynBal$PmWat_flow_internal_vr 28 // "Needed to connect to conditional connector"
#define $Pvol$PdynBal$PmXi$lB1$rB_vr 29 // "Masses of independent components in the fluid"
#define $Pvol$PdynBal$PmbXi_flow$lB1$rB_vr 30 // "Substance mass flows across boundaries"
#define $Pvol$PdynBal$Pmb_flow_vr 31 // "Mass flows across boundaries"
#define $Pvol$PdynBal$Pmedium$PMM_vr 32 // "Molar mass (of mixture or single fluid)"
#define $Pvol$PdynBal$Pmedium$PR_vr 33 // "Gas constant (of mixture if applicable)"
#define $Pvol$PdynBal$Pmedium$PT_vr 34 // "Temperature of medium"
#define $Pvol$PdynBal$Pmedium$PX$lB2$rB_vr 35 // "Mass fractions (= (component mass)/total mass  m_i/m)"
#define $Pvol$PdynBal$Pmedium$Pd_vr 36 // "Density of medium"
#define $Pvol$PdynBal$Pmedium$PdT_vr 37 // "Temperature difference used to compute enthalpy"
#define $Pvol$PdynBal$Pmedium$Pp_vr 38 // "Absolute pressure of medium"
#define $Pvol$PdynBal$Pmedium$Pp_bar_vr 39 // "Absolute pressure of medium in [bar]"
#define $Pvol$PdynBal$Pmedium$Pu_vr 40 // "Specific internal energy of medium"
#define $Pvol$PheatPort$PQ_flow_vr 41 // "Heat flow rate (positive if flowing from outside into the component)"
#define $PHeatingControlPortTransformer1$Pset_hysteresis_intervallumSignalHolder$PentryTime_vr 42 
#define $Pset_hysteresis_intervallum_tester1$Py_vr 43 
#define $PtemperatureStreamPortTransformer1$Pmeasured_temperatureSignalHolder$PentryTime_vr 44 
#define $PthermostatControlPortTransformer1$Pset_target_temperatureSignalHolder$PentryTime_vr 45 
#define $PthermostatControlPortTransformer1$Pturn_thermostat_offSignalHolder$PentryTime_vr 46 
#define $PthermostatControlPortTransformer1$Pturn_thermostat_onSignalHolder$PentryTime_vr 47 
#define $PHeatingControlPortTransformer1$Pset_hysteresis_intervallum_hysteresis_intervallum_initial_vr 48 
#define $PQRooInt_flow_vr 49 // "Internal heat gains of the room"
#define $PTOut$PT_vr 50 // "Fixed temperature at port"
#define $PV_vr 51 // "Room volume"
#define $PbooleanToReal1$PrealFalse_vr 52 // "Output signal for false Boolean input"
#define $PbooleanToReal1$PrealTrue_vr 53 // "Output signal for true Boolean input"
#define $PheaCap$PC_vr 54 // "Heat capacity of element (= cp*m)"
#define $PheatingFactor_vr 55 
#define $PmA_flow_nominal_vr 56 // "Nominal mass flow rate"
#define $PpreHea$PT_ref_vr 57 // "Reference temperature"
#define $PpreHea$Palpha_vr 58 // "Temperature coefficient of heat flow rate"
#define $PsampleTrigger1$Pperiod_vr 59 // "Sample period"
#define $PsampleTrigger1$PstartTime_vr 60 // "Time instant of first sample trigger"
#define $PsampleTrigger2$Pperiod_vr 61 // "Sample period"
#define $PsampleTrigger2$PstartTime_vr 62 // "Time instant of first sample trigger"
#define $Pset_hysteresis_intervallum_tester1$PsampleTrigger1$Pperiod_vr 63 // "Sample period"
#define $Pset_hysteresis_intervallum_tester1$PsampleTrigger1$PstartTime_vr 64 // "Time instant of first sample trigger"
#define $Pstep1$Pheight_vr 65 // "Height of step"
#define $Pstep1$Poffset_vr 66 // "Offset of output signal y"
#define $Pstep1$PstartTime_vr 67 // "Output y = offset for time < startTime"
#define $PtemperatureStreamPortTransformer1$Pmeasured_temperature_measured_temperature_initial_vr 68 
#define $PtheCon$PG_vr 69 // "Constant thermal conductance of material"
#define $PthermostatControlPortTransformer1$Pset_target_temperature_target_temperature_initial_vr 70 
#define $Pvol$PT_start_vr 71 // "Start value of temperature"
#define $Pvol$PV_vr 72 // "Volume"
#define $Pvol$PX_start$lB1$rB_vr 73 // "Start value of mass fractions m_i/m"
#define $Pvol$PX_start$lB2$rB_vr 74 // "Start value of mass fractions m_i/m"
#define $Pvol$PdynBal$PCSen_vr 75 // "Aditional heat capacity for implementing mFactor"
#define $Pvol$PdynBal$PT_start_vr 76 // "Start value of temperature"
#define $Pvol$PdynBal$PX_start$lB1$rB_vr 77 // "Start value of mass fractions m_i/m"
#define $Pvol$PdynBal$PX_start$lB2$rB_vr 78 // "Start value of mass fractions m_i/m"
#define $Pvol$PdynBal$Pcp_default_vr 79 // "Heat capacity, to compute additional dry mass"
#define $Pvol$PdynBal$PfluidVolume_vr 80 // "Volume"
#define $Pvol$PdynBal$PhStart_vr 81 // "Start value for specific enthalpy"
#define $Pvol$PdynBal$PmSenFac_vr 82 // "Factor for scaling the sensible thermal mass of the volume"
#define $Pvol$PdynBal$Pp_start_vr 83 // "Start value of pressure"
#define $Pvol$PdynBal$Prho_default_vr 84 // "Density, used to compute fluid mass"
#define $Pvol$PdynBal$Prho_start_vr 85 // "Density, used to compute fluid mass"
#define $Pvol$PdynBal$Ps$lB1$rB_vr 86 // "Vector with zero everywhere except where species is"
#define $Pvol$PdynBal$Pstate_default$PT_vr 87 // "Temperature of medium"
#define $Pvol$PdynBal$Pstate_default$PX$lB1$rB_vr 88 // "Mass fractions (= (component mass)/total mass  m_i/m)"
#define $Pvol$PdynBal$Pstate_default$PX$lB2$rB_vr 89 // "Mass fractions (= (component mass)/total mass  m_i/m)"
#define $Pvol$PdynBal$Pstate_default$Pp_vr 90 // "Absolute pressure of medium"
#define $Pvol$PmSenFac_vr 91 // "Factor for scaling the sensible thermal mass of the volume"
#define $Pvol$Pm_flow_nominal_vr 92 // "Nominal mass flow rate"
#define $Pvol$Pm_flow_small_vr 93 // "Small mass flow rate for regularization of zero flow"
#define $Pvol$Pp_start_vr 94 // "Start value of pressure"
#define $Pvol$Prho_default_vr 95 // "Density, used to compute fluid mass"
#define $Pvol$Prho_start_vr 96 // "Density, used to compute start and guess values"
#define $Pvol$Pstate_default$PT_vr 97 // "Temperature of medium"
#define $Pvol$Pstate_default$PX$lB1$rB_vr 98 // "Mass fractions (= (component mass)/total mass  m_i/m)"
#define $Pvol$Pstate_default$PX$lB2$rB_vr 99 // "Mass fractions (= (component mass)/total mass  m_i/m)"
#define $Pvol$Pstate_default$Pp_vr 100 // "Absolute pressure of medium"
#define $Pvol$Pstate_start$PT_vr 101 // "Temperature of medium"
#define $Pvol$Pstate_start$PX$lB1$rB_vr 102 // "Mass fractions (= (component mass)/total mass  m_i/m)"
#define $Pvol$Pstate_start$PX$lB2$rB_vr 103 // "Mass fractions (= (component mass)/total mass  m_i/m)"
#define $Pvol$Pstate_start$Pp_vr 104 // "Absolute pressure of medium"
#define $PHeatingControlPortTransformer1$PHeatingControlPort1$Pset_hysteresis_intervallum1$Physteresis_intervallum$lB1$rB_vr 105 
#define $PHeatingControlPortTransformer1$PHeatingControlPort1$Pset_hysteresis_intervallum1$Physteresis_intervallum$lB2$rB_vr 106 
#define $PHeatingControlPortTransformer1$PHeatingControlPort1$Pset_hysteresis_intervallum1$Physteresis_intervallum$lB3$rB_vr 107 
#define $PHeatingControlPortTransformer1$Pset_hysteresis_intervallum_hysteresis_intervallum_vr 108 
#define $PTOut$Pport$PQ_flow_vr 109 // "Heat flow rate (positive if flowing from outside into the component)"
#define $PTOut$Pport$PT_vr 110 // "Port temperature"
#define $PheaCap$Pport$PT_vr 111 // "Port temperature"
#define $PpreHea$PQ_flow_vr 112 
#define $PpreHea$Pport$PT_vr 113 // "Port temperature"
#define $Pstep1$Py_vr 114 // "Connector of Real output signal"
#define $PtemperatureStreamPortTransformer1$PTemperatureStreamPort1$Pmeasured_temperature1$Pmeasured_temperature$lB1$rB_vr 115 
#define $PtemperatureStreamPortTransformer1$PTemperatureStreamPort1$Pmeasured_temperature1$Pmeasured_temperature$lB2$rB_vr 116 
#define $PtemperatureStreamPortTransformer1$PTemperatureStreamPort1$Pmeasured_temperature1$Pmeasured_temperature$lB3$rB_vr 117 
#define $PtemperatureStreamPortTransformer1$Pmeasured_temperature_measured_temperature_vr 118 
#define $PtheCon$Pport_a$PQ_flow_vr 119 // "Heat flow rate (positive if flowing from outside into the component)"
#define $PtheCon$Pport_a$PT_vr 120 // "Port temperature"
#define $PtheCon$Pport_b$PQ_flow_vr 121 // "Heat flow rate (positive if flowing from outside into the component)"
#define $PtheCon$Pport_b$PT_vr 122 // "Port temperature"
#define $PthermostatControlPortTransformer1$PThermostatControlPort1$Pset_target_temperature1$Ptarget_temperature$lB1$rB_vr 123 
#define $PthermostatControlPortTransformer1$PThermostatControlPort1$Pset_target_temperature1$Ptarget_temperature$lB2$rB_vr 124 
#define $PthermostatControlPortTransformer1$PThermostatControlPort1$Pset_target_temperature1$Ptarget_temperature$lB3$rB_vr 125 
#define $PthermostatControlPortTransformer1$Pset_target_temperature_target_temperature_vr 126 
#define $Pvol$PT_vr 127 // "Temperature of the fluid"
#define $Pvol$PU_vr 128 // "Internal energy of the component"
#define $Pvol$PXi$lB1$rB_vr 129 // "Species concentration of the fluid"
#define $Pvol$PXiOut_internal$lB1$rB_vr 130 // "Internal connector for leaving species concentration of the component"
#define $Pvol$PdynBal$PQ_flow_vr 131 // "Sensible plus latent heat flow rate transferred into the medium"
#define $Pvol$PdynBal$PUOut_vr 132 // "Internal energy of the component"
#define $Pvol$PdynBal$PXiOut$lB1$rB_vr 133 // "Leaving species concentration of the component"
#define $Pvol$PdynBal$PhOut_vr 134 // "Leaving specific enthalpy of the component"
#define $Pvol$PdynBal$PmOut_vr 135 // "Mass of the component"
#define $Pvol$PdynBal$PmXiOut$lB1$rB_vr 136 // "Species mass of the component"
#define $Pvol$PdynBal$Pmedium$PT_degC_vr 137 // "Temperature of medium in [degC]"
#define $Pvol$PdynBal$Pmedium$PX$lB1$rB_vr 138 // "Mass fractions (= (component mass)/total mass  m_i/m)"
#define $Pvol$PdynBal$Pmedium$PX_air_vr 139 // "Mass fraction of air"
#define $Pvol$PdynBal$Pmedium$PX_steam_vr 140 // "Mass fraction of steam water"
#define $Pvol$PdynBal$Pmedium$Ph_vr 141 // "Specific enthalpy of medium"
#define $Pvol$PdynBal$Pmedium$Pstate$PT_vr 142 // "Temperature of medium"
#define $Pvol$PdynBal$Pmedium$Pstate$PX$lB1$rB_vr 143 // "Mass fractions (= (component mass)/total mass  m_i/m)"
#define $Pvol$PdynBal$Pmedium$Pstate$PX$lB2$rB_vr 144 // "Mass fractions (= (component mass)/total mass  m_i/m)"
#define $Pvol$PdynBal$Pmedium$Pstate$Pp_vr 145 // "Absolute pressure of medium"
#define $Pvol$PheaFloSen$PQ_flow_vr 146 // "Heat flow from port_a to port_b as output signal"
#define $Pvol$PheaFloSen$Pport_a$PQ_flow_vr 147 // "Heat flow rate (positive if flowing from outside into the component)"
#define $Pvol$PheaFloSen$Pport_a$PT_vr 148 // "Port temperature"
#define $Pvol$PheaFloSen$Pport_b$PQ_flow_vr 149 // "Heat flow rate (positive if flowing from outside into the component)"
#define $Pvol$PheaFloSen$Pport_b$PT_vr 150 // "Port temperature"
#define $Pvol$PheatPort$PT_vr 151 // "Port temperature"
#define $Pvol$Pm_vr 152 // "Mass of the component"
#define $Pvol$PmXi$lB1$rB_vr 153 // "Species mass of the component"
#define $Pvol$Pp_vr 154 // "Pressure of the fluid"
#define $Pvol$PportT$Py_vr 155 // "Value of Real output"
#define $Pvol$PpreTem$PT_vr 156 
#define $Pvol$PpreTem$Pport$PQ_flow_vr 157 // "Heat flow rate (positive if flowing from outside into the component)"
#define $Pvol$PpreTem$Pport$PT_vr 158 // "Port temperature"
#define $PHeatingControlPortTransformer1$PHeatingControlPort1$Pset_hysteresis_intervallum1$Pcounter_vr 0 
#define $PheatingControlPort1$Pset_hysteresis_intervallum1$Pcounter_vr 1 
#define $PheatingControlPort1$Pturn_heating_off1$Pcounter_vr 2 
#define $PheatingControlPort1$Pturn_heating_on1$Pcounter_vr 3 
#define $PtemperatureStreamPort1$Pmeasured_temperature1$Pcounter_vr 4 
#define $PtemperatureStreamPortTransformer1$PTemperatureStreamPort1$Pmeasured_temperature1$Pcounter_vr 5 
#define $PthermostatControlPort1$Pset_target_temperature1$Pcounter_vr 6 
#define $PthermostatControlPort1$Pturn_thermostat_off1$Pcounter_vr 7 
#define $PthermostatControlPort1$Pturn_thermostat_on1$Pcounter_vr 8 
#define $PthermostatControlPortTransformer1$PThermostatControlPort1$Pset_target_temperature1$Pcounter_vr 9 
#define $Pvol$PdynBal$PenergyDynamics_vr 10 // "Type of energy balance: dynamic (3 initialization options) or steady state"
#define $Pvol$PdynBal$PmassDynamics_vr 11 // "Type of mass balance: dynamic (3 initialization options) or steady state"
#define $Pvol$PdynBal$PnPorts_vr 12 // "Number of ports"
#define $Pvol$PdynBal$PsubstanceDynamics_vr 13 // "Type of independent mass fraction balance: dynamic (3 initialization options) or steady state"
#define $Pvol$PdynBal$PtraceDynamics_vr 14 // "Type of trace substance balance: dynamic (3 initialization options) or steady state"
#define $Pvol$PenergyDynamics_vr 15 // "Type of energy balance: dynamic (3 initialization options) or steady state"
#define $Pvol$PmassDynamics_vr 16 // "Type of mass balance: dynamic (3 initialization options) or steady state"
#define $Pvol$PnPorts_vr 17 // "Number of ports"
#define $Pvol$PsubstanceDynamics_vr 18 // "Type of independent mass fraction balance: dynamic (3 initialization options) or steady state"
#define $Pvol$PtraceDynamics_vr 19 // "Type of trace substance balance: dynamic (3 initialization options) or steady state"
#define $PHeatingControlPortTransformer1$PHeatingControlPort1$Pturn_heating_off1$Pcounter_vr 20 
#define $PHeatingControlPortTransformer1$PHeatingControlPort1$Pturn_heating_on1$Pcounter_vr 21 
#define $PthermostatControlPortTransformer1$PThermostatControlPort1$Pturn_thermostat_off1$Pcounter_vr 22 
#define $PthermostatControlPortTransformer1$PThermostatControlPort1$Pturn_thermostat_on1$Pcounter_vr 23 
#define $P$whenCondition1_vr 0 
#define $P$whenCondition10_vr 1 
#define $P$whenCondition11_vr 2 
#define $P$whenCondition12_vr 3 
#define $P$whenCondition13_vr 4 
#define $P$whenCondition14_vr 5 
#define $P$whenCondition2_vr 6 
#define $P$whenCondition3_vr 7 
#define $P$whenCondition4_vr 8 
#define $P$whenCondition5_vr 9 
#define $P$whenCondition6_vr 10 
#define $P$whenCondition7_vr 11 
#define $P$whenCondition8_vr 12 
#define $P$whenCondition9_vr 13 
#define $PHeatingControlPortTransformer1$Pset_hysteresis_intervallumSignalHolder$Pu_vr 14 
#define $PHeatingControlPortTransformer1$Pset_hysteresis_intervallumSignalHolder$Py_vr 15 
#define $PHeatingControlPortTransformer1$Pturn_heating_off_vr 16 
#define $PHeatingControlPortTransformer1$Pturn_heating_on_vr 17 
#define $PbooleanToReal1$Pu_vr 18 // "Connector of Boolean input signal"
#define $PrSFlipFlop$PQI_vr 19 
#define $PrSFlipFlop$Ppre$Pu_vr 20 // "Connector of Boolean input signal"
#define $PtemperatureStreamPortTransformer1$Pmeasured_temperatureSignalHolder$Pu_vr 21 
#define $PtemperatureStreamPortTransformer1$Pmeasured_temperatureSignalHolder$Py_vr 22 
#define $PthermostatControlPortTransformer1$Pset_target_temperatureSignalHolder$Pu_vr 23 
#define $PthermostatControlPortTransformer1$Pset_target_temperatureSignalHolder$Py_vr 24 
#define $PthermostatControlPortTransformer1$Pturn_thermostat_offSignalHolder$Pu_vr 25 
#define $PthermostatControlPortTransformer1$Pturn_thermostat_offSignalHolder$Py_vr 26 
#define $PthermostatControlPortTransformer1$Pturn_thermostat_onSignalHolder$Pu_vr 27 
#define $PthermostatControlPortTransformer1$Pturn_thermostat_onSignalHolder$Py_vr 28 
#define $PbooleanConstant1$Pk_vr 29 // "Constant output value"
#define $PrSFlipFlop$PQini_vr 30 // "Start value of Q at initial time"
#define $PrSFlipFlop$Ppre$Ppre_u_start_vr 31 // "Start value of pre(u) at initial time"
#define $Pvol$PallowFlowReversal_vr 32 // "= false to simplify equations, assuming, but not enforcing, no flow reversal. Used only if model has two ports."
#define $Pvol$PdynBal$PcomputeCSen_vr 33 
#define $Pvol$PdynBal$Pmedium$PpreferredMediumStates_vr 34 // "= true if StateSelect.prefer shall be used for the independent property variables of the medium"
#define $Pvol$PdynBal$Pmedium$PstandardOrderComponents_vr 35 // "If true, and reducedX = true, the last element of X will be computed from the other ones"
#define $Pvol$PdynBal$Puse_C_flow_vr 36 // "Set to true to enable input connector for trace substance"
#define $Pvol$PdynBal$Puse_mWat_flow_vr 37 // "Set to true to enable input connector for moisture mass flow rate"
#define $Pvol$PuseSteadyStateTwoPort_vr 38 // "Flag, true if the model has two ports only and uses a steady state balance"
#define $Pvol$Puse_C_flow_vr 39 // "Set to true to enable input connector for trace substance"
#define $PHeatingControlPortTransformer1$Pset_hysteresis_intervallum_vr 40 
#define $PbooleanConstant1$Py_vr 41 // "Connector of Boolean output signal"
#define $PrSFlipFlop$PQ_vr 42 
#define $PrSFlipFlop$PR_vr 43 
#define $PrSFlipFlop$PS_vr 44 
#define $PrSFlipFlop$Pnor$Pu1_vr 45 // "Connector of first Boolean input signal"
#define $PrSFlipFlop$Pnor$Pu2_vr 46 // "Connector of second Boolean input signal"
#define $PrSFlipFlop$Pnor$Py_vr 47 // "Connector of Boolean output signal"
#define $PrSFlipFlop$Pnor1$Pu1_vr 48 // "Connector of first Boolean input signal"
#define $PrSFlipFlop$Pnor1$Pu2_vr 49 // "Connector of second Boolean input signal"
#define $PrSFlipFlop$Pnor1$Py_vr 50 // "Connector of Boolean output signal"
#define $PrSFlipFlop$Ppre$Py_vr 51 // "Connector of Boolean output signal"
#define $PsampleTrigger1$Py_vr 52 // "Connector of Boolean output signal"
#define $PsampleTrigger2$Py_vr 53 // "Connector of Boolean output signal"
#define $Pset_hysteresis_intervallum_tester1$PsampleTrigger1$Py_vr 54 // "Connector of Boolean output signal"
#define $Pset_hysteresis_intervallum_tester1$Py1_vr 55 
#define $PtemperatureStreamPortTransformer1$Pmeasured_temperature_vr 56 
#define $PthermostatControlPortTransformer1$Pset_target_temperature_vr 57 
#define $PthermostatControlPortTransformer1$Pturn_thermostat_off_vr 58 
#define $PthermostatControlPortTransformer1$Pturn_thermostat_on_vr 59 


// define initial state vector as vector of value references
#define STATES { $Pvol$PdynBal$Pm_vr, $Pvol$PdynBal$Pmedium$PXi$lB1$rB_vr, $Pvol$PhOut_internal_vr }
#define STATESDERIVATIVES { $P$DER$Pvol$PdynBal$Pm_vr, $P$DER$Pvol$PdynBal$Pmedium$PXi$lB1$rB_vr, $P$DER$Pvol$PhOut_internal_vr }


// implementation of the Model Exchange functions
extern void Room_setupDataStruc(DATA *data);
#define fmu2_model_interface_setupDataStruc Room_setupDataStruc
#include "fmu2_model_interface.c"

// Set values for all variables that define a start value
void setDefaultStartValues(ModelInstance *comp) {
  comp->fmuData->modelData->realVarsData[0].attribute.start = 216.0;
  comp->fmuData->modelData->realVarsData[1].attribute.start = 0.01;
  comp->fmuData->modelData->realVarsData[2].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[3].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[4].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[5].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[6].attribute.start = 0.0;
  comp->fmuData->modelData->realVarsData[7].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[8].attribute.start = 0.0;
  comp->fmuData->modelData->realVarsData[9].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[10].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[11].attribute.start = 293.15;
  comp->fmuData->modelData->realVarsData[12].attribute.start = 0.0;
  comp->fmuData->modelData->realVarsData[13].attribute.start = 0.0;
  comp->fmuData->modelData->realVarsData[14].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[15].attribute.start = 1.0;
  comp->fmuData->modelData->realVarsData[16].attribute.start = 1.0;
  comp->fmuData->modelData->realVarsData[17].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[18].attribute.start = 20.0;
  comp->fmuData->modelData->realVarsData[19].attribute.start = 0.0;
  comp->fmuData->modelData->realVarsData[20].attribute.start = 0.0;
  comp->fmuData->modelData->realVarsData[21].attribute.start = -2000.0;
  comp->fmuData->modelData->realVarsData[22].attribute.start = -10.0;
  comp->fmuData->modelData->realVarsData[23].attribute.start = 22.0;
  comp->fmuData->modelData->realVarsData[24].attribute.start = 0.0;
  comp->fmuData->modelData->realVarsData[25].attribute.start = 0.0;
  comp->fmuData->modelData->realVarsData[26].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[27].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[28].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[29].attribute.start = 2.16;
  comp->fmuData->modelData->realVarsData[30].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[31].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[32].attribute.start = 0.02879012713067693;
  comp->fmuData->modelData->realVarsData[33].attribute.start = 1000.0;
  comp->fmuData->modelData->realVarsData[34].attribute.start = 293.15;
  comp->fmuData->modelData->realVarsData[35].attribute.start = 0.99;
  comp->fmuData->modelData->realVarsData[36].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[37].attribute.start = 20.0;
  comp->fmuData->modelData->realVarsData[38].attribute.start = 101325.0;
  comp->fmuData->modelData->realVarsData[39].attribute.start = 1.01325;
  comp->fmuData->modelData->realVarsData[40].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[41].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[42].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[43].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[44].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[45].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[46].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[47].attribute.start = 0;
  comp->fmuData->modelData->integerVarsData[0].attribute.start = 0;
  comp->fmuData->modelData->integerVarsData[1].attribute.start = 1;
  comp->fmuData->modelData->integerVarsData[2].attribute.start = 0;
  comp->fmuData->modelData->integerVarsData[3].attribute.start = 0;
  comp->fmuData->modelData->integerVarsData[4].attribute.start = 1;
  comp->fmuData->modelData->integerVarsData[5].attribute.start = 0;
  comp->fmuData->modelData->integerVarsData[6].attribute.start = 1;
  comp->fmuData->modelData->integerVarsData[7].attribute.start = 0;
  comp->fmuData->modelData->integerVarsData[8].attribute.start = 0;
  comp->fmuData->modelData->integerVarsData[9].attribute.start = 0;
  comp->fmuData->modelData->booleanVarsData[0].attribute.start = 0;
  comp->fmuData->modelData->booleanVarsData[1].attribute.start = 0;
  comp->fmuData->modelData->booleanVarsData[2].attribute.start = 0;
  comp->fmuData->modelData->booleanVarsData[3].attribute.start = 0;
  comp->fmuData->modelData->booleanVarsData[4].attribute.start = 0;
  comp->fmuData->modelData->booleanVarsData[5].attribute.start = 0;
  comp->fmuData->modelData->booleanVarsData[6].attribute.start = 0;
  comp->fmuData->modelData->booleanVarsData[7].attribute.start = 0;
  comp->fmuData->modelData->booleanVarsData[8].attribute.start = 0;
  comp->fmuData->modelData->booleanVarsData[9].attribute.start = 0;
  comp->fmuData->modelData->booleanVarsData[10].attribute.start = 0;
  comp->fmuData->modelData->booleanVarsData[11].attribute.start = 0;
  comp->fmuData->modelData->booleanVarsData[12].attribute.start = 0;
  comp->fmuData->modelData->booleanVarsData[13].attribute.start = 0;
  comp->fmuData->modelData->booleanVarsData[14].attribute.start = 0;
  comp->fmuData->modelData->booleanVarsData[15].attribute.start = 0;
  comp->fmuData->modelData->booleanVarsData[16].attribute.start = 0;
  comp->fmuData->modelData->booleanVarsData[17].attribute.start = 0;
  comp->fmuData->modelData->booleanVarsData[18].attribute.start = 0;
  comp->fmuData->modelData->booleanVarsData[19].attribute.start = 0;
  comp->fmuData->modelData->booleanVarsData[20].attribute.start = 0;
  comp->fmuData->modelData->booleanVarsData[21].attribute.start = 1;
  comp->fmuData->modelData->booleanVarsData[22].attribute.start = 0;
  comp->fmuData->modelData->booleanVarsData[23].attribute.start = 1;
  comp->fmuData->modelData->booleanVarsData[24].attribute.start = 0;
  comp->fmuData->modelData->booleanVarsData[25].attribute.start = 0;
  comp->fmuData->modelData->booleanVarsData[26].attribute.start = 0;
  comp->fmuData->modelData->booleanVarsData[27].attribute.start = 0;
  comp->fmuData->modelData->booleanVarsData[28].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[0].attribute.start = 1.0;
  comp->fmuData->modelData->realParameterData[1].attribute.start = 4000.0;
  comp->fmuData->modelData->realParameterData[2].attribute.start = 283.15;
  comp->fmuData->modelData->realParameterData[3].attribute.start = 180.0;
  comp->fmuData->modelData->realParameterData[4].attribute.start = 0.0;
  comp->fmuData->modelData->realParameterData[6].attribute.start = 434592.0;
  comp->fmuData->modelData->realParameterData[7].attribute.start = 4000.0;
  comp->fmuData->modelData->realParameterData[8].attribute.start = 0.3;
  comp->fmuData->modelData->realParameterData[9].attribute.start = 293.15;
  comp->fmuData->modelData->realParameterData[10].attribute.start = 0.0;
  comp->fmuData->modelData->realParameterData[11].attribute.start = 7200.0;
  comp->fmuData->modelData->realParameterData[12].attribute.start = 10.0;
  comp->fmuData->modelData->realParameterData[13].attribute.start = 7200.0;
  comp->fmuData->modelData->realParameterData[14].attribute.start = 7020.0;
  comp->fmuData->modelData->realParameterData[15].attribute.start = 3600.0;
  comp->fmuData->modelData->realParameterData[16].attribute.start = 3600.0;
  comp->fmuData->modelData->realParameterData[17].attribute.start = 3.0;
  comp->fmuData->modelData->realParameterData[18].attribute.start = 22.0;
  comp->fmuData->modelData->realParameterData[19].attribute.start = 6000.0;
  comp->fmuData->modelData->realParameterData[20].attribute.start = 0.0;
  comp->fmuData->modelData->realParameterData[21].attribute.start = 200.0;
  comp->fmuData->modelData->realParameterData[22].attribute.start = 0.0;
  comp->fmuData->modelData->realParameterData[23].attribute.start = 293.15;
  comp->fmuData->modelData->realParameterData[24].attribute.start = 180.0;
  comp->fmuData->modelData->realParameterData[25].attribute.start = 0.01;
  comp->fmuData->modelData->realParameterData[26].attribute.start = 0.99;
  comp->fmuData->modelData->realParameterData[27].attribute.start = 0.0;
  comp->fmuData->modelData->realParameterData[28].attribute.start = 293.15;
  comp->fmuData->modelData->realParameterData[31].attribute.start = 1014.54;
  comp->fmuData->modelData->realParameterData[32].attribute.start = 180.0;
  comp->fmuData->modelData->realParameterData[34].attribute.start = 1.0;
  comp->fmuData->modelData->realParameterData[35].attribute.start = 101325.0;
  comp->fmuData->modelData->realParameterData[36].attribute.start = 1.2;
  comp->fmuData->modelData->realParameterData[38].attribute.start = 1.0;
  comp->fmuData->modelData->realParameterData[39].attribute.start = 293.15;
  comp->fmuData->modelData->realParameterData[40].attribute.start = 0.01;
  comp->fmuData->modelData->realParameterData[41].attribute.start = 0.99;
  comp->fmuData->modelData->realParameterData[42].attribute.start = 101325.0;
  comp->fmuData->modelData->realParameterData[43].attribute.start = 1.0;
  comp->fmuData->modelData->realParameterData[44].attribute.start = 0.3;
  comp->fmuData->modelData->realParameterData[45].attribute.start = 3.000000000000001e-05;
  comp->fmuData->modelData->realParameterData[46].attribute.start = 101325.0;
  comp->fmuData->modelData->realParameterData[47].attribute.start = 1.2;
  comp->fmuData->modelData->realParameterData[48].attribute.start = 1.2;
  comp->fmuData->modelData->realParameterData[49].attribute.start = 293.15;
  comp->fmuData->modelData->realParameterData[50].attribute.start = 0.01;
  comp->fmuData->modelData->realParameterData[51].attribute.start = 0.99;
  comp->fmuData->modelData->realParameterData[52].attribute.start = 101325.0;
  comp->fmuData->modelData->realParameterData[53].attribute.start = 293.15;
  comp->fmuData->modelData->realParameterData[54].attribute.start = 0.01;
  comp->fmuData->modelData->realParameterData[55].attribute.start = 0.99;
  comp->fmuData->modelData->realParameterData[56].attribute.start = 101325.0;
  comp->fmuData->modelData->integerParameterData[0].attribute.start = 2;
  comp->fmuData->modelData->integerParameterData[1].attribute.start = 2;
  comp->fmuData->modelData->integerParameterData[2].attribute.start = 0;
  comp->fmuData->modelData->integerParameterData[3].attribute.start = 2;
  comp->fmuData->modelData->integerParameterData[4].attribute.start = 2;
  comp->fmuData->modelData->integerParameterData[5].attribute.start = 2;
  comp->fmuData->modelData->integerParameterData[6].attribute.start = 2;
  comp->fmuData->modelData->integerParameterData[7].attribute.start = 0;
  comp->fmuData->modelData->integerParameterData[8].attribute.start = 2;
  comp->fmuData->modelData->integerParameterData[9].attribute.start = 2;
  comp->fmuData->modelData->booleanParameterData[0].attribute.start = 1;
  comp->fmuData->modelData->booleanParameterData[1].attribute.start = 0;
  comp->fmuData->modelData->booleanParameterData[3].attribute.start = 1;
  comp->fmuData->modelData->booleanParameterData[4].attribute.start = 0;
  comp->fmuData->modelData->booleanParameterData[5].attribute.start = 0;
  comp->fmuData->modelData->booleanParameterData[6].attribute.start = 1;
  comp->fmuData->modelData->booleanParameterData[7].attribute.start = 0;
  comp->fmuData->modelData->booleanParameterData[8].attribute.start = 0;
  comp->fmuData->modelData->booleanParameterData[9].attribute.start = 0;
  comp->fmuData->modelData->booleanParameterData[10].attribute.start = 0;
}
// Set values for all variables that define a start value
void setStartValues(ModelInstance *comp) {
  comp->fmuData->modelData->realVarsData[0].attribute.start =  comp->fmuData->localData[0]->realVars[0];
  comp->fmuData->modelData->realVarsData[1].attribute.start =  comp->fmuData->localData[0]->realVars[1];
  comp->fmuData->modelData->realVarsData[2].attribute.start =  comp->fmuData->localData[0]->realVars[2];
  comp->fmuData->modelData->realVarsData[3].attribute.start =  comp->fmuData->localData[0]->realVars[3];
  comp->fmuData->modelData->realVarsData[4].attribute.start =  comp->fmuData->localData[0]->realVars[4];
  comp->fmuData->modelData->realVarsData[5].attribute.start =  comp->fmuData->localData[0]->realVars[5];
  comp->fmuData->modelData->realVarsData[6].attribute.start =  comp->fmuData->localData[0]->realVars[6];
  comp->fmuData->modelData->realVarsData[7].attribute.start =  comp->fmuData->localData[0]->realVars[7];
  comp->fmuData->modelData->realVarsData[8].attribute.start =  comp->fmuData->localData[0]->realVars[8];
  comp->fmuData->modelData->realVarsData[9].attribute.start =  comp->fmuData->localData[0]->realVars[9];
  comp->fmuData->modelData->realVarsData[10].attribute.start =  comp->fmuData->localData[0]->realVars[10];
  comp->fmuData->modelData->realVarsData[11].attribute.start =  comp->fmuData->localData[0]->realVars[11];
  comp->fmuData->modelData->realVarsData[12].attribute.start =  comp->fmuData->localData[0]->realVars[12];
  comp->fmuData->modelData->realVarsData[13].attribute.start =  comp->fmuData->localData[0]->realVars[13];
  comp->fmuData->modelData->realVarsData[14].attribute.start =  comp->fmuData->localData[0]->realVars[14];
  comp->fmuData->modelData->realVarsData[15].attribute.start =  comp->fmuData->localData[0]->realVars[15];
  comp->fmuData->modelData->realVarsData[16].attribute.start =  comp->fmuData->localData[0]->realVars[16];
  comp->fmuData->modelData->realVarsData[17].attribute.start =  comp->fmuData->localData[0]->realVars[17];
  comp->fmuData->modelData->realVarsData[18].attribute.start =  comp->fmuData->localData[0]->realVars[18];
  comp->fmuData->modelData->realVarsData[19].attribute.start =  comp->fmuData->localData[0]->realVars[19];
  comp->fmuData->modelData->realVarsData[20].attribute.start =  comp->fmuData->localData[0]->realVars[20];
  comp->fmuData->modelData->realVarsData[21].attribute.start =  comp->fmuData->localData[0]->realVars[21];
  comp->fmuData->modelData->realVarsData[22].attribute.start =  comp->fmuData->localData[0]->realVars[22];
  comp->fmuData->modelData->realVarsData[23].attribute.start =  comp->fmuData->localData[0]->realVars[23];
  comp->fmuData->modelData->realVarsData[24].attribute.start =  comp->fmuData->localData[0]->realVars[24];
  comp->fmuData->modelData->realVarsData[25].attribute.start =  comp->fmuData->localData[0]->realVars[25];
  comp->fmuData->modelData->realVarsData[26].attribute.start =  comp->fmuData->localData[0]->realVars[26];
  comp->fmuData->modelData->realVarsData[27].attribute.start =  comp->fmuData->localData[0]->realVars[27];
  comp->fmuData->modelData->realVarsData[28].attribute.start =  comp->fmuData->localData[0]->realVars[28];
  comp->fmuData->modelData->realVarsData[29].attribute.start =  comp->fmuData->localData[0]->realVars[29];
  comp->fmuData->modelData->realVarsData[30].attribute.start =  comp->fmuData->localData[0]->realVars[30];
  comp->fmuData->modelData->realVarsData[31].attribute.start =  comp->fmuData->localData[0]->realVars[31];
  comp->fmuData->modelData->realVarsData[32].attribute.start =  comp->fmuData->localData[0]->realVars[32];
  comp->fmuData->modelData->realVarsData[33].attribute.start =  comp->fmuData->localData[0]->realVars[33];
  comp->fmuData->modelData->realVarsData[34].attribute.start =  comp->fmuData->localData[0]->realVars[34];
  comp->fmuData->modelData->realVarsData[35].attribute.start =  comp->fmuData->localData[0]->realVars[35];
  comp->fmuData->modelData->realVarsData[36].attribute.start =  comp->fmuData->localData[0]->realVars[36];
  comp->fmuData->modelData->realVarsData[37].attribute.start =  comp->fmuData->localData[0]->realVars[37];
  comp->fmuData->modelData->realVarsData[38].attribute.start =  comp->fmuData->localData[0]->realVars[38];
  comp->fmuData->modelData->realVarsData[39].attribute.start =  comp->fmuData->localData[0]->realVars[39];
  comp->fmuData->modelData->realVarsData[40].attribute.start =  comp->fmuData->localData[0]->realVars[40];
  comp->fmuData->modelData->realVarsData[41].attribute.start =  comp->fmuData->localData[0]->realVars[41];
  comp->fmuData->modelData->realVarsData[42].attribute.start =  comp->fmuData->localData[0]->realVars[42];
  comp->fmuData->modelData->realVarsData[43].attribute.start =  comp->fmuData->localData[0]->realVars[43];
  comp->fmuData->modelData->realVarsData[44].attribute.start =  comp->fmuData->localData[0]->realVars[44];
  comp->fmuData->modelData->realVarsData[45].attribute.start =  comp->fmuData->localData[0]->realVars[45];
  comp->fmuData->modelData->realVarsData[46].attribute.start =  comp->fmuData->localData[0]->realVars[46];
  comp->fmuData->modelData->realVarsData[47].attribute.start =  comp->fmuData->localData[0]->realVars[47];
  comp->fmuData->modelData->integerVarsData[0].attribute.start =  comp->fmuData->localData[0]->integerVars[0];
  comp->fmuData->modelData->integerVarsData[1].attribute.start =  comp->fmuData->localData[0]->integerVars[1];
  comp->fmuData->modelData->integerVarsData[2].attribute.start =  comp->fmuData->localData[0]->integerVars[2];
  comp->fmuData->modelData->integerVarsData[3].attribute.start =  comp->fmuData->localData[0]->integerVars[3];
  comp->fmuData->modelData->integerVarsData[4].attribute.start =  comp->fmuData->localData[0]->integerVars[4];
  comp->fmuData->modelData->integerVarsData[5].attribute.start =  comp->fmuData->localData[0]->integerVars[5];
  comp->fmuData->modelData->integerVarsData[6].attribute.start =  comp->fmuData->localData[0]->integerVars[6];
  comp->fmuData->modelData->integerVarsData[7].attribute.start =  comp->fmuData->localData[0]->integerVars[7];
  comp->fmuData->modelData->integerVarsData[8].attribute.start =  comp->fmuData->localData[0]->integerVars[8];
  comp->fmuData->modelData->integerVarsData[9].attribute.start =  comp->fmuData->localData[0]->integerVars[9];
  comp->fmuData->modelData->booleanVarsData[0].attribute.start =  comp->fmuData->localData[0]->booleanVars[0];
  comp->fmuData->modelData->booleanVarsData[1].attribute.start =  comp->fmuData->localData[0]->booleanVars[1];
  comp->fmuData->modelData->booleanVarsData[2].attribute.start =  comp->fmuData->localData[0]->booleanVars[2];
  comp->fmuData->modelData->booleanVarsData[3].attribute.start =  comp->fmuData->localData[0]->booleanVars[3];
  comp->fmuData->modelData->booleanVarsData[4].attribute.start =  comp->fmuData->localData[0]->booleanVars[4];
  comp->fmuData->modelData->booleanVarsData[5].attribute.start =  comp->fmuData->localData[0]->booleanVars[5];
  comp->fmuData->modelData->booleanVarsData[6].attribute.start =  comp->fmuData->localData[0]->booleanVars[6];
  comp->fmuData->modelData->booleanVarsData[7].attribute.start =  comp->fmuData->localData[0]->booleanVars[7];
  comp->fmuData->modelData->booleanVarsData[8].attribute.start =  comp->fmuData->localData[0]->booleanVars[8];
  comp->fmuData->modelData->booleanVarsData[9].attribute.start =  comp->fmuData->localData[0]->booleanVars[9];
  comp->fmuData->modelData->booleanVarsData[10].attribute.start =  comp->fmuData->localData[0]->booleanVars[10];
  comp->fmuData->modelData->booleanVarsData[11].attribute.start =  comp->fmuData->localData[0]->booleanVars[11];
  comp->fmuData->modelData->booleanVarsData[12].attribute.start =  comp->fmuData->localData[0]->booleanVars[12];
  comp->fmuData->modelData->booleanVarsData[13].attribute.start =  comp->fmuData->localData[0]->booleanVars[13];
  comp->fmuData->modelData->booleanVarsData[14].attribute.start =  comp->fmuData->localData[0]->booleanVars[14];
  comp->fmuData->modelData->booleanVarsData[15].attribute.start =  comp->fmuData->localData[0]->booleanVars[15];
  comp->fmuData->modelData->booleanVarsData[16].attribute.start =  comp->fmuData->localData[0]->booleanVars[16];
  comp->fmuData->modelData->booleanVarsData[17].attribute.start =  comp->fmuData->localData[0]->booleanVars[17];
  comp->fmuData->modelData->booleanVarsData[18].attribute.start =  comp->fmuData->localData[0]->booleanVars[18];
  comp->fmuData->modelData->booleanVarsData[19].attribute.start =  comp->fmuData->localData[0]->booleanVars[19];
  comp->fmuData->modelData->booleanVarsData[20].attribute.start =  comp->fmuData->localData[0]->booleanVars[20];
  comp->fmuData->modelData->booleanVarsData[21].attribute.start =  comp->fmuData->localData[0]->booleanVars[21];
  comp->fmuData->modelData->booleanVarsData[22].attribute.start =  comp->fmuData->localData[0]->booleanVars[22];
  comp->fmuData->modelData->booleanVarsData[23].attribute.start =  comp->fmuData->localData[0]->booleanVars[23];
  comp->fmuData->modelData->booleanVarsData[24].attribute.start =  comp->fmuData->localData[0]->booleanVars[24];
  comp->fmuData->modelData->booleanVarsData[25].attribute.start =  comp->fmuData->localData[0]->booleanVars[25];
  comp->fmuData->modelData->booleanVarsData[26].attribute.start =  comp->fmuData->localData[0]->booleanVars[26];
  comp->fmuData->modelData->booleanVarsData[27].attribute.start =  comp->fmuData->localData[0]->booleanVars[27];
  comp->fmuData->modelData->booleanVarsData[28].attribute.start =  comp->fmuData->localData[0]->booleanVars[28];
  comp->fmuData->modelData->realParameterData[0].attribute.start = comp->fmuData->simulationInfo->realParameter[0];
  comp->fmuData->modelData->realParameterData[1].attribute.start = comp->fmuData->simulationInfo->realParameter[1];
  comp->fmuData->modelData->realParameterData[2].attribute.start = comp->fmuData->simulationInfo->realParameter[2];
  comp->fmuData->modelData->realParameterData[3].attribute.start = comp->fmuData->simulationInfo->realParameter[3];
  comp->fmuData->modelData->realParameterData[4].attribute.start = comp->fmuData->simulationInfo->realParameter[4];
  comp->fmuData->modelData->realParameterData[5].attribute.start = comp->fmuData->simulationInfo->realParameter[5];
  comp->fmuData->modelData->realParameterData[6].attribute.start = comp->fmuData->simulationInfo->realParameter[6];
  comp->fmuData->modelData->realParameterData[7].attribute.start = comp->fmuData->simulationInfo->realParameter[7];
  comp->fmuData->modelData->realParameterData[8].attribute.start = comp->fmuData->simulationInfo->realParameter[8];
  comp->fmuData->modelData->realParameterData[9].attribute.start = comp->fmuData->simulationInfo->realParameter[9];
  comp->fmuData->modelData->realParameterData[10].attribute.start = comp->fmuData->simulationInfo->realParameter[10];
  comp->fmuData->modelData->realParameterData[11].attribute.start = comp->fmuData->simulationInfo->realParameter[11];
  comp->fmuData->modelData->realParameterData[12].attribute.start = comp->fmuData->simulationInfo->realParameter[12];
  comp->fmuData->modelData->realParameterData[13].attribute.start = comp->fmuData->simulationInfo->realParameter[13];
  comp->fmuData->modelData->realParameterData[14].attribute.start = comp->fmuData->simulationInfo->realParameter[14];
  comp->fmuData->modelData->realParameterData[15].attribute.start = comp->fmuData->simulationInfo->realParameter[15];
  comp->fmuData->modelData->realParameterData[16].attribute.start = comp->fmuData->simulationInfo->realParameter[16];
  comp->fmuData->modelData->realParameterData[17].attribute.start = comp->fmuData->simulationInfo->realParameter[17];
  comp->fmuData->modelData->realParameterData[18].attribute.start = comp->fmuData->simulationInfo->realParameter[18];
  comp->fmuData->modelData->realParameterData[19].attribute.start = comp->fmuData->simulationInfo->realParameter[19];
  comp->fmuData->modelData->realParameterData[20].attribute.start = comp->fmuData->simulationInfo->realParameter[20];
  comp->fmuData->modelData->realParameterData[21].attribute.start = comp->fmuData->simulationInfo->realParameter[21];
  comp->fmuData->modelData->realParameterData[22].attribute.start = comp->fmuData->simulationInfo->realParameter[22];
  comp->fmuData->modelData->realParameterData[23].attribute.start = comp->fmuData->simulationInfo->realParameter[23];
  comp->fmuData->modelData->realParameterData[24].attribute.start = comp->fmuData->simulationInfo->realParameter[24];
  comp->fmuData->modelData->realParameterData[25].attribute.start = comp->fmuData->simulationInfo->realParameter[25];
  comp->fmuData->modelData->realParameterData[26].attribute.start = comp->fmuData->simulationInfo->realParameter[26];
  comp->fmuData->modelData->realParameterData[27].attribute.start = comp->fmuData->simulationInfo->realParameter[27];
  comp->fmuData->modelData->realParameterData[28].attribute.start = comp->fmuData->simulationInfo->realParameter[28];
  comp->fmuData->modelData->realParameterData[29].attribute.start = comp->fmuData->simulationInfo->realParameter[29];
  comp->fmuData->modelData->realParameterData[30].attribute.start = comp->fmuData->simulationInfo->realParameter[30];
  comp->fmuData->modelData->realParameterData[31].attribute.start = comp->fmuData->simulationInfo->realParameter[31];
  comp->fmuData->modelData->realParameterData[32].attribute.start = comp->fmuData->simulationInfo->realParameter[32];
  comp->fmuData->modelData->realParameterData[33].attribute.start = comp->fmuData->simulationInfo->realParameter[33];
  comp->fmuData->modelData->realParameterData[34].attribute.start = comp->fmuData->simulationInfo->realParameter[34];
  comp->fmuData->modelData->realParameterData[35].attribute.start = comp->fmuData->simulationInfo->realParameter[35];
  comp->fmuData->modelData->realParameterData[36].attribute.start = comp->fmuData->simulationInfo->realParameter[36];
  comp->fmuData->modelData->realParameterData[37].attribute.start = comp->fmuData->simulationInfo->realParameter[37];
  comp->fmuData->modelData->realParameterData[38].attribute.start = comp->fmuData->simulationInfo->realParameter[38];
  comp->fmuData->modelData->realParameterData[39].attribute.start = comp->fmuData->simulationInfo->realParameter[39];
  comp->fmuData->modelData->realParameterData[40].attribute.start = comp->fmuData->simulationInfo->realParameter[40];
  comp->fmuData->modelData->realParameterData[41].attribute.start = comp->fmuData->simulationInfo->realParameter[41];
  comp->fmuData->modelData->realParameterData[42].attribute.start = comp->fmuData->simulationInfo->realParameter[42];
  comp->fmuData->modelData->realParameterData[43].attribute.start = comp->fmuData->simulationInfo->realParameter[43];
  comp->fmuData->modelData->realParameterData[44].attribute.start = comp->fmuData->simulationInfo->realParameter[44];
  comp->fmuData->modelData->realParameterData[45].attribute.start = comp->fmuData->simulationInfo->realParameter[45];
  comp->fmuData->modelData->realParameterData[46].attribute.start = comp->fmuData->simulationInfo->realParameter[46];
  comp->fmuData->modelData->realParameterData[47].attribute.start = comp->fmuData->simulationInfo->realParameter[47];
  comp->fmuData->modelData->realParameterData[48].attribute.start = comp->fmuData->simulationInfo->realParameter[48];
  comp->fmuData->modelData->realParameterData[49].attribute.start = comp->fmuData->simulationInfo->realParameter[49];
  comp->fmuData->modelData->realParameterData[50].attribute.start = comp->fmuData->simulationInfo->realParameter[50];
  comp->fmuData->modelData->realParameterData[51].attribute.start = comp->fmuData->simulationInfo->realParameter[51];
  comp->fmuData->modelData->realParameterData[52].attribute.start = comp->fmuData->simulationInfo->realParameter[52];
  comp->fmuData->modelData->realParameterData[53].attribute.start = comp->fmuData->simulationInfo->realParameter[53];
  comp->fmuData->modelData->realParameterData[54].attribute.start = comp->fmuData->simulationInfo->realParameter[54];
  comp->fmuData->modelData->realParameterData[55].attribute.start = comp->fmuData->simulationInfo->realParameter[55];
  comp->fmuData->modelData->realParameterData[56].attribute.start = comp->fmuData->simulationInfo->realParameter[56];
  comp->fmuData->modelData->integerParameterData[0].attribute.start = comp->fmuData->simulationInfo->integerParameter[0];
  comp->fmuData->modelData->integerParameterData[1].attribute.start = comp->fmuData->simulationInfo->integerParameter[1];
  comp->fmuData->modelData->integerParameterData[2].attribute.start = comp->fmuData->simulationInfo->integerParameter[2];
  comp->fmuData->modelData->integerParameterData[3].attribute.start = comp->fmuData->simulationInfo->integerParameter[3];
  comp->fmuData->modelData->integerParameterData[4].attribute.start = comp->fmuData->simulationInfo->integerParameter[4];
  comp->fmuData->modelData->integerParameterData[5].attribute.start = comp->fmuData->simulationInfo->integerParameter[5];
  comp->fmuData->modelData->integerParameterData[6].attribute.start = comp->fmuData->simulationInfo->integerParameter[6];
  comp->fmuData->modelData->integerParameterData[7].attribute.start = comp->fmuData->simulationInfo->integerParameter[7];
  comp->fmuData->modelData->integerParameterData[8].attribute.start = comp->fmuData->simulationInfo->integerParameter[8];
  comp->fmuData->modelData->integerParameterData[9].attribute.start = comp->fmuData->simulationInfo->integerParameter[9];
  comp->fmuData->modelData->booleanParameterData[0].attribute.start = comp->fmuData->simulationInfo->booleanParameter[0];
  comp->fmuData->modelData->booleanParameterData[1].attribute.start = comp->fmuData->simulationInfo->booleanParameter[1];
  comp->fmuData->modelData->booleanParameterData[2].attribute.start = comp->fmuData->simulationInfo->booleanParameter[2];
  comp->fmuData->modelData->booleanParameterData[3].attribute.start = comp->fmuData->simulationInfo->booleanParameter[3];
  comp->fmuData->modelData->booleanParameterData[4].attribute.start = comp->fmuData->simulationInfo->booleanParameter[4];
  comp->fmuData->modelData->booleanParameterData[5].attribute.start = comp->fmuData->simulationInfo->booleanParameter[5];
  comp->fmuData->modelData->booleanParameterData[6].attribute.start = comp->fmuData->simulationInfo->booleanParameter[6];
  comp->fmuData->modelData->booleanParameterData[7].attribute.start = comp->fmuData->simulationInfo->booleanParameter[7];
  comp->fmuData->modelData->booleanParameterData[8].attribute.start = comp->fmuData->simulationInfo->booleanParameter[8];
  comp->fmuData->modelData->booleanParameterData[9].attribute.start = comp->fmuData->simulationInfo->booleanParameter[9];
  comp->fmuData->modelData->booleanParameterData[10].attribute.start = comp->fmuData->simulationInfo->booleanParameter[10];
}

// Used to set the next time event, if any.
void eventUpdate(ModelInstance* comp, fmi2EventInfo* eventInfo) {
}

fmi2Real getReal(ModelInstance* comp, const fmi2ValueReference vr) {
  switch (vr) {
    case $Pvol$PdynBal$Pm_vr : return comp->fmuData->localData[0]->realVars[0]; break;
    case $Pvol$PdynBal$Pmedium$PXi$lB1$rB_vr : return comp->fmuData->localData[0]->realVars[1]; break;
    case $Pvol$PhOut_internal_vr : return comp->fmuData->localData[0]->realVars[2]; break;
    case $P$DER$Pvol$PdynBal$Pm_vr : return comp->fmuData->localData[0]->realVars[3]; break;
    case $P$DER$Pvol$PdynBal$Pmedium$PXi$lB1$rB_vr : return comp->fmuData->localData[0]->realVars[4]; break;
    case $P$DER$Pvol$PhOut_internal_vr : return comp->fmuData->localData[0]->realVars[5]; break;
    case $P$DER$PheaCap$PT_vr : return comp->fmuData->localData[0]->realVars[6]; break;
    case $P$DER$Pvol$PdynBal$PU_vr : return comp->fmuData->localData[0]->realVars[7]; break;
    case $P$DER$Pvol$PdynBal$PmXi$lB1$rB_vr : return comp->fmuData->localData[0]->realVars[8]; break;
    case $P$DER$Pvol$PdynBal$Pmedium$Pu_vr : return comp->fmuData->localData[0]->realVars[9]; break;
    case $PbooleanToReal1$Py_vr : return comp->fmuData->localData[0]->realVars[10]; break;
    case $PheaCap$PT_vr : return comp->fmuData->localData[0]->realVars[11]; break;
    case $PheaCap$Pder_T_vr : return comp->fmuData->localData[0]->realVars[12]; break;
    case $PheaCap$Pport$PQ_flow_vr : return comp->fmuData->localData[0]->realVars[13]; break;
    case $PheatingControlPort1$Pset_hysteresis_intervallum1$Physteresis_intervallum$lB1$rB_vr : return comp->fmuData->localData[0]->realVars[14]; break;
    case $PheatingControlPort1$Pset_hysteresis_intervallum1$Physteresis_intervallum$lB2$rB_vr : return comp->fmuData->localData[0]->realVars[15]; break;
    case $PheatingControlPort1$Pset_hysteresis_intervallum1$Physteresis_intervallum$lB3$rB_vr : return comp->fmuData->localData[0]->realVars[16]; break;
    case $PpreHea$Pport$PQ_flow_vr : return comp->fmuData->localData[0]->realVars[17]; break;
    case $PtemperatureStreamPort1$Pmeasured_temperature1$Pmeasured_temperature$lB1$rB_vr : return comp->fmuData->localData[0]->realVars[18]; break;
    case $PtemperatureStreamPort1$Pmeasured_temperature1$Pmeasured_temperature$lB2$rB_vr : return comp->fmuData->localData[0]->realVars[19]; break;
    case $PtemperatureStreamPort1$Pmeasured_temperature1$Pmeasured_temperature$lB3$rB_vr : return comp->fmuData->localData[0]->realVars[20]; break;
    case $PtheCon$PQ_flow_vr : return comp->fmuData->localData[0]->realVars[21]; break;
    case $PtheCon$PdT_vr : return comp->fmuData->localData[0]->realVars[22]; break;
    case $PthermostatControlPort1$Pset_target_temperature1$Ptarget_temperature$lB1$rB_vr : return comp->fmuData->localData[0]->realVars[23]; break;
    case $PthermostatControlPort1$Pset_target_temperature1$Ptarget_temperature$lB2$rB_vr : return comp->fmuData->localData[0]->realVars[24]; break;
    case $PthermostatControlPort1$Pset_target_temperature1$Ptarget_temperature$lB3$rB_vr : return comp->fmuData->localData[0]->realVars[25]; break;
    case $Pvol$PdynBal$PHb_flow_vr : return comp->fmuData->localData[0]->realVars[26]; break;
    case $Pvol$PdynBal$PU_vr : return comp->fmuData->localData[0]->realVars[27]; break;
    case $Pvol$PdynBal$PmWat_flow_internal_vr : return comp->fmuData->localData[0]->realVars[28]; break;
    case $Pvol$PdynBal$PmXi$lB1$rB_vr : return comp->fmuData->localData[0]->realVars[29]; break;
    case $Pvol$PdynBal$PmbXi_flow$lB1$rB_vr : return comp->fmuData->localData[0]->realVars[30]; break;
    case $Pvol$PdynBal$Pmb_flow_vr : return comp->fmuData->localData[0]->realVars[31]; break;
    case $Pvol$PdynBal$Pmedium$PMM_vr : return comp->fmuData->localData[0]->realVars[32]; break;
    case $Pvol$PdynBal$Pmedium$PR_vr : return comp->fmuData->localData[0]->realVars[33]; break;
    case $Pvol$PdynBal$Pmedium$PT_vr : return comp->fmuData->localData[0]->realVars[34]; break;
    case $Pvol$PdynBal$Pmedium$PX$lB2$rB_vr : return comp->fmuData->localData[0]->realVars[35]; break;
    case $Pvol$PdynBal$Pmedium$Pd_vr : return comp->fmuData->localData[0]->realVars[36]; break;
    case $Pvol$PdynBal$Pmedium$PdT_vr : return comp->fmuData->localData[0]->realVars[37]; break;
    case $Pvol$PdynBal$Pmedium$Pp_vr : return comp->fmuData->localData[0]->realVars[38]; break;
    case $Pvol$PdynBal$Pmedium$Pp_bar_vr : return comp->fmuData->localData[0]->realVars[39]; break;
    case $Pvol$PdynBal$Pmedium$Pu_vr : return comp->fmuData->localData[0]->realVars[40]; break;
    case $Pvol$PheatPort$PQ_flow_vr : return comp->fmuData->localData[0]->realVars[41]; break;
    case $PHeatingControlPortTransformer1$Pset_hysteresis_intervallumSignalHolder$PentryTime_vr : return comp->fmuData->localData[0]->realVars[42]; break;
    case $Pset_hysteresis_intervallum_tester1$Py_vr : return comp->fmuData->localData[0]->realVars[43]; break;
    case $PtemperatureStreamPortTransformer1$Pmeasured_temperatureSignalHolder$PentryTime_vr : return comp->fmuData->localData[0]->realVars[44]; break;
    case $PthermostatControlPortTransformer1$Pset_target_temperatureSignalHolder$PentryTime_vr : return comp->fmuData->localData[0]->realVars[45]; break;
    case $PthermostatControlPortTransformer1$Pturn_thermostat_offSignalHolder$PentryTime_vr : return comp->fmuData->localData[0]->realVars[46]; break;
    case $PthermostatControlPortTransformer1$Pturn_thermostat_onSignalHolder$PentryTime_vr : return comp->fmuData->localData[0]->realVars[47]; break;
    case $PHeatingControlPortTransformer1$Pset_hysteresis_intervallum_hysteresis_intervallum_initial_vr : return comp->fmuData->simulationInfo->realParameter[0]; break;
    case $PQRooInt_flow_vr : return comp->fmuData->simulationInfo->realParameter[1]; break;
    case $PTOut$PT_vr : return comp->fmuData->simulationInfo->realParameter[2]; break;
    case $PV_vr : return comp->fmuData->simulationInfo->realParameter[3]; break;
    case $PbooleanToReal1$PrealFalse_vr : return comp->fmuData->simulationInfo->realParameter[4]; break;
    case $PbooleanToReal1$PrealTrue_vr : return comp->fmuData->simulationInfo->realParameter[5]; break;
    case $PheaCap$PC_vr : return comp->fmuData->simulationInfo->realParameter[6]; break;
    case $PheatingFactor_vr : return comp->fmuData->simulationInfo->realParameter[7]; break;
    case $PmA_flow_nominal_vr : return comp->fmuData->simulationInfo->realParameter[8]; break;
    case $PpreHea$PT_ref_vr : return comp->fmuData->simulationInfo->realParameter[9]; break;
    case $PpreHea$Palpha_vr : return comp->fmuData->simulationInfo->realParameter[10]; break;
    case $PsampleTrigger1$Pperiod_vr : return comp->fmuData->simulationInfo->realParameter[11]; break;
    case $PsampleTrigger1$PstartTime_vr : return comp->fmuData->simulationInfo->realParameter[12]; break;
    case $PsampleTrigger2$Pperiod_vr : return comp->fmuData->simulationInfo->realParameter[13]; break;
    case $PsampleTrigger2$PstartTime_vr : return comp->fmuData->simulationInfo->realParameter[14]; break;
    case $Pset_hysteresis_intervallum_tester1$PsampleTrigger1$Pperiod_vr : return comp->fmuData->simulationInfo->realParameter[15]; break;
    case $Pset_hysteresis_intervallum_tester1$PsampleTrigger1$PstartTime_vr : return comp->fmuData->simulationInfo->realParameter[16]; break;
    case $Pstep1$Pheight_vr : return comp->fmuData->simulationInfo->realParameter[17]; break;
    case $Pstep1$Poffset_vr : return comp->fmuData->simulationInfo->realParameter[18]; break;
    case $Pstep1$PstartTime_vr : return comp->fmuData->simulationInfo->realParameter[19]; break;
    case $PtemperatureStreamPortTransformer1$Pmeasured_temperature_measured_temperature_initial_vr : return comp->fmuData->simulationInfo->realParameter[20]; break;
    case $PtheCon$PG_vr : return comp->fmuData->simulationInfo->realParameter[21]; break;
    case $PthermostatControlPortTransformer1$Pset_target_temperature_target_temperature_initial_vr : return comp->fmuData->simulationInfo->realParameter[22]; break;
    case $Pvol$PT_start_vr : return comp->fmuData->simulationInfo->realParameter[23]; break;
    case $Pvol$PV_vr : return comp->fmuData->simulationInfo->realParameter[24]; break;
    case $Pvol$PX_start$lB1$rB_vr : return comp->fmuData->simulationInfo->realParameter[25]; break;
    case $Pvol$PX_start$lB2$rB_vr : return comp->fmuData->simulationInfo->realParameter[26]; break;
    case $Pvol$PdynBal$PCSen_vr : return comp->fmuData->simulationInfo->realParameter[27]; break;
    case $Pvol$PdynBal$PT_start_vr : return comp->fmuData->simulationInfo->realParameter[28]; break;
    case $Pvol$PdynBal$PX_start$lB1$rB_vr : return comp->fmuData->simulationInfo->realParameter[29]; break;
    case $Pvol$PdynBal$PX_start$lB2$rB_vr : return comp->fmuData->simulationInfo->realParameter[30]; break;
    case $Pvol$PdynBal$Pcp_default_vr : return comp->fmuData->simulationInfo->realParameter[31]; break;
    case $Pvol$PdynBal$PfluidVolume_vr : return comp->fmuData->simulationInfo->realParameter[32]; break;
    case $Pvol$PdynBal$PhStart_vr : return comp->fmuData->simulationInfo->realParameter[33]; break;
    case $Pvol$PdynBal$PmSenFac_vr : return comp->fmuData->simulationInfo->realParameter[34]; break;
    case $Pvol$PdynBal$Pp_start_vr : return comp->fmuData->simulationInfo->realParameter[35]; break;
    case $Pvol$PdynBal$Prho_default_vr : return comp->fmuData->simulationInfo->realParameter[36]; break;
    case $Pvol$PdynBal$Prho_start_vr : return comp->fmuData->simulationInfo->realParameter[37]; break;
    case $Pvol$PdynBal$Ps$lB1$rB_vr : return comp->fmuData->simulationInfo->realParameter[38]; break;
    case $Pvol$PdynBal$Pstate_default$PT_vr : return comp->fmuData->simulationInfo->realParameter[39]; break;
    case $Pvol$PdynBal$Pstate_default$PX$lB1$rB_vr : return comp->fmuData->simulationInfo->realParameter[40]; break;
    case $Pvol$PdynBal$Pstate_default$PX$lB2$rB_vr : return comp->fmuData->simulationInfo->realParameter[41]; break;
    case $Pvol$PdynBal$Pstate_default$Pp_vr : return comp->fmuData->simulationInfo->realParameter[42]; break;
    case $Pvol$PmSenFac_vr : return comp->fmuData->simulationInfo->realParameter[43]; break;
    case $Pvol$Pm_flow_nominal_vr : return comp->fmuData->simulationInfo->realParameter[44]; break;
    case $Pvol$Pm_flow_small_vr : return comp->fmuData->simulationInfo->realParameter[45]; break;
    case $Pvol$Pp_start_vr : return comp->fmuData->simulationInfo->realParameter[46]; break;
    case $Pvol$Prho_default_vr : return comp->fmuData->simulationInfo->realParameter[47]; break;
    case $Pvol$Prho_start_vr : return comp->fmuData->simulationInfo->realParameter[48]; break;
    case $Pvol$Pstate_default$PT_vr : return comp->fmuData->simulationInfo->realParameter[49]; break;
    case $Pvol$Pstate_default$PX$lB1$rB_vr : return comp->fmuData->simulationInfo->realParameter[50]; break;
    case $Pvol$Pstate_default$PX$lB2$rB_vr : return comp->fmuData->simulationInfo->realParameter[51]; break;
    case $Pvol$Pstate_default$Pp_vr : return comp->fmuData->simulationInfo->realParameter[52]; break;
    case $Pvol$Pstate_start$PT_vr : return comp->fmuData->simulationInfo->realParameter[53]; break;
    case $Pvol$Pstate_start$PX$lB1$rB_vr : return comp->fmuData->simulationInfo->realParameter[54]; break;
    case $Pvol$Pstate_start$PX$lB2$rB_vr : return comp->fmuData->simulationInfo->realParameter[55]; break;
    case $Pvol$Pstate_start$Pp_vr : return comp->fmuData->simulationInfo->realParameter[56]; break;
    case $PHeatingControlPortTransformer1$PHeatingControlPort1$Pset_hysteresis_intervallum1$Physteresis_intervallum$lB1$rB_vr : return getReal(comp, $PheatingControlPort1$Pset_hysteresis_intervallum1$Physteresis_intervallum$lB1$rB_vr); break;
    case $PHeatingControlPortTransformer1$PHeatingControlPort1$Pset_hysteresis_intervallum1$Physteresis_intervallum$lB2$rB_vr : return getReal(comp, $PHeatingControlPortTransformer1$Pset_hysteresis_intervallum_hysteresis_intervallum_initial_vr); break;
    case $PHeatingControlPortTransformer1$PHeatingControlPort1$Pset_hysteresis_intervallum1$Physteresis_intervallum$lB3$rB_vr : return getReal(comp, $PHeatingControlPortTransformer1$Pset_hysteresis_intervallum_hysteresis_intervallum_initial_vr); break;
    case $PHeatingControlPortTransformer1$Pset_hysteresis_intervallum_hysteresis_intervallum_vr : return getReal(comp, $PheatingControlPort1$Pset_hysteresis_intervallum1$Physteresis_intervallum$lB1$rB_vr); break;
    case $PTOut$Pport$PQ_flow_vr : return (- getReal(comp, $PtheCon$PQ_flow_vr)); break;
    case $PTOut$Pport$PT_vr : return getReal(comp, $PTOut$PT_vr); break;
    case $PheaCap$Pport$PT_vr : return getReal(comp, $PheaCap$PT_vr); break;
    case $PpreHea$PQ_flow_vr : return getReal(comp, $PbooleanToReal1$Py_vr); break;
    case $PpreHea$Pport$PT_vr : return getReal(comp, $PheaCap$PT_vr); break;
    case $Pstep1$Py_vr : return getReal(comp, $PthermostatControlPort1$Pset_target_temperature1$Ptarget_temperature$lB1$rB_vr); break;
    case $PtemperatureStreamPortTransformer1$PTemperatureStreamPort1$Pmeasured_temperature1$Pmeasured_temperature$lB1$rB_vr : return getReal(comp, $PtemperatureStreamPort1$Pmeasured_temperature1$Pmeasured_temperature$lB1$rB_vr); break;
    case $PtemperatureStreamPortTransformer1$PTemperatureStreamPort1$Pmeasured_temperature1$Pmeasured_temperature$lB2$rB_vr : return getReal(comp, $PtemperatureStreamPortTransformer1$Pmeasured_temperature_measured_temperature_initial_vr); break;
    case $PtemperatureStreamPortTransformer1$PTemperatureStreamPort1$Pmeasured_temperature1$Pmeasured_temperature$lB3$rB_vr : return getReal(comp, $PtemperatureStreamPortTransformer1$Pmeasured_temperature_measured_temperature_initial_vr); break;
    case $PtemperatureStreamPortTransformer1$Pmeasured_temperature_measured_temperature_vr : return getReal(comp, $PtemperatureStreamPort1$Pmeasured_temperature1$Pmeasured_temperature$lB1$rB_vr); break;
    case $PtheCon$Pport_a$PQ_flow_vr : return getReal(comp, $PtheCon$PQ_flow_vr); break;
    case $PtheCon$Pport_a$PT_vr : return getReal(comp, $PTOut$PT_vr); break;
    case $PtheCon$Pport_b$PQ_flow_vr : return (- getReal(comp, $PtheCon$PQ_flow_vr)); break;
    case $PtheCon$Pport_b$PT_vr : return getReal(comp, $PheaCap$PT_vr); break;
    case $PthermostatControlPortTransformer1$PThermostatControlPort1$Pset_target_temperature1$Ptarget_temperature$lB1$rB_vr : return getReal(comp, $PthermostatControlPort1$Pset_target_temperature1$Ptarget_temperature$lB1$rB_vr); break;
    case $PthermostatControlPortTransformer1$PThermostatControlPort1$Pset_target_temperature1$Ptarget_temperature$lB2$rB_vr : return getReal(comp, $PthermostatControlPortTransformer1$Pset_target_temperature_target_temperature_initial_vr); break;
    case $PthermostatControlPortTransformer1$PThermostatControlPort1$Pset_target_temperature1$Ptarget_temperature$lB3$rB_vr : return getReal(comp, $PthermostatControlPortTransformer1$Pset_target_temperature_target_temperature_initial_vr); break;
    case $PthermostatControlPortTransformer1$Pset_target_temperature_target_temperature_vr : return getReal(comp, $PthermostatControlPort1$Pset_target_temperature1$Ptarget_temperature$lB1$rB_vr); break;
    case $Pvol$PT_vr : return getReal(comp, $PheaCap$PT_vr); break;
    case $Pvol$PU_vr : return getReal(comp, $Pvol$PdynBal$PU_vr); break;
    case $Pvol$PXi$lB1$rB_vr : return getReal(comp, $Pvol$PdynBal$Pmedium$PXi$lB1$rB_vr); break;
    case $Pvol$PXiOut_internal$lB1$rB_vr : return getReal(comp, $Pvol$PdynBal$Pmedium$PXi$lB1$rB_vr); break;
    case $Pvol$PdynBal$PQ_flow_vr : return getReal(comp, $Pvol$PheatPort$PQ_flow_vr); break;
    case $Pvol$PdynBal$PUOut_vr : return getReal(comp, $Pvol$PdynBal$PU_vr); break;
    case $Pvol$PdynBal$PXiOut$lB1$rB_vr : return getReal(comp, $Pvol$PdynBal$Pmedium$PXi$lB1$rB_vr); break;
    case $Pvol$PdynBal$PhOut_vr : return getReal(comp, $Pvol$PhOut_internal_vr); break;
    case $Pvol$PdynBal$PmOut_vr : return getReal(comp, $Pvol$PdynBal$Pm_vr); break;
    case $Pvol$PdynBal$PmXiOut$lB1$rB_vr : return getReal(comp, $Pvol$PdynBal$PmXi$lB1$rB_vr); break;
    case $Pvol$PdynBal$Pmedium$PT_degC_vr : return getReal(comp, $Pvol$PdynBal$Pmedium$PdT_vr); break;
    case $Pvol$PdynBal$Pmedium$PX$lB1$rB_vr : return getReal(comp, $Pvol$PdynBal$Pmedium$PXi$lB1$rB_vr); break;
    case $Pvol$PdynBal$Pmedium$PX_air_vr : return getReal(comp, $Pvol$PdynBal$Pmedium$PX$lB2$rB_vr); break;
    case $Pvol$PdynBal$Pmedium$PX_steam_vr : return getReal(comp, $Pvol$PdynBal$Pmedium$PXi$lB1$rB_vr); break;
    case $Pvol$PdynBal$Pmedium$Ph_vr : return getReal(comp, $Pvol$PhOut_internal_vr); break;
    case $Pvol$PdynBal$Pmedium$Pstate$PT_vr : return getReal(comp, $Pvol$PdynBal$Pmedium$PT_vr); break;
    case $Pvol$PdynBal$Pmedium$Pstate$PX$lB1$rB_vr : return getReal(comp, $Pvol$PdynBal$Pmedium$PXi$lB1$rB_vr); break;
    case $Pvol$PdynBal$Pmedium$Pstate$PX$lB2$rB_vr : return getReal(comp, $Pvol$PdynBal$Pmedium$PX$lB2$rB_vr); break;
    case $Pvol$PdynBal$Pmedium$Pstate$Pp_vr : return getReal(comp, $Pvol$PdynBal$Pmedium$Pp_vr); break;
    case $Pvol$PheaFloSen$PQ_flow_vr : return getReal(comp, $Pvol$PheatPort$PQ_flow_vr); break;
    case $Pvol$PheaFloSen$Pport_a$PQ_flow_vr : return getReal(comp, $Pvol$PheatPort$PQ_flow_vr); break;
    case $Pvol$PheaFloSen$Pport_a$PT_vr : return getReal(comp, $PheaCap$PT_vr); break;
    case $Pvol$PheaFloSen$Pport_b$PQ_flow_vr : return (- getReal(comp, $Pvol$PheatPort$PQ_flow_vr)); break;
    case $Pvol$PheaFloSen$Pport_b$PT_vr : return getReal(comp, $PheaCap$PT_vr); break;
    case $Pvol$PheatPort$PT_vr : return getReal(comp, $PheaCap$PT_vr); break;
    case $Pvol$Pm_vr : return getReal(comp, $Pvol$PdynBal$Pm_vr); break;
    case $Pvol$PmXi$lB1$rB_vr : return getReal(comp, $Pvol$PdynBal$PmXi$lB1$rB_vr); break;
    case $Pvol$Pp_vr : return getReal(comp, $Pvol$Pp_start_vr); break;
    case $Pvol$PportT$Py_vr : return getReal(comp, $PheaCap$PT_vr); break;
    case $Pvol$PpreTem$PT_vr : return getReal(comp, $PheaCap$PT_vr); break;
    case $Pvol$PpreTem$Pport$PQ_flow_vr : return getReal(comp, $Pvol$PheatPort$PQ_flow_vr); break;
    case $Pvol$PpreTem$Pport$PT_vr : return getReal(comp, $PheaCap$PT_vr); break;
    default:
      return 0;
  }
}

fmi2Status setReal(ModelInstance* comp, const fmi2ValueReference vr, const fmi2Real value) {
  switch (vr) {
    case $Pvol$PdynBal$Pm_vr : comp->fmuData->localData[0]->realVars[0] = value; break;
    case $Pvol$PdynBal$Pmedium$PXi$lB1$rB_vr : comp->fmuData->localData[0]->realVars[1] = value; break;
    case $Pvol$PhOut_internal_vr : comp->fmuData->localData[0]->realVars[2] = value; break;
    case $P$DER$Pvol$PdynBal$Pm_vr : comp->fmuData->localData[0]->realVars[3] = value; break;
    case $P$DER$Pvol$PdynBal$Pmedium$PXi$lB1$rB_vr : comp->fmuData->localData[0]->realVars[4] = value; break;
    case $P$DER$Pvol$PhOut_internal_vr : comp->fmuData->localData[0]->realVars[5] = value; break;
    case $P$DER$PheaCap$PT_vr : comp->fmuData->localData[0]->realVars[6] = value; break;
    case $P$DER$Pvol$PdynBal$PU_vr : comp->fmuData->localData[0]->realVars[7] = value; break;
    case $P$DER$Pvol$PdynBal$PmXi$lB1$rB_vr : comp->fmuData->localData[0]->realVars[8] = value; break;
    case $P$DER$Pvol$PdynBal$Pmedium$Pu_vr : comp->fmuData->localData[0]->realVars[9] = value; break;
    case $PbooleanToReal1$Py_vr : comp->fmuData->localData[0]->realVars[10] = value; break;
    case $PheaCap$PT_vr : comp->fmuData->localData[0]->realVars[11] = value; break;
    case $PheaCap$Pder_T_vr : comp->fmuData->localData[0]->realVars[12] = value; break;
    case $PheaCap$Pport$PQ_flow_vr : comp->fmuData->localData[0]->realVars[13] = value; break;
    case $PheatingControlPort1$Pset_hysteresis_intervallum1$Physteresis_intervallum$lB1$rB_vr : comp->fmuData->localData[0]->realVars[14] = value; break;
    case $PheatingControlPort1$Pset_hysteresis_intervallum1$Physteresis_intervallum$lB2$rB_vr : comp->fmuData->localData[0]->realVars[15] = value; break;
    case $PheatingControlPort1$Pset_hysteresis_intervallum1$Physteresis_intervallum$lB3$rB_vr : comp->fmuData->localData[0]->realVars[16] = value; break;
    case $PpreHea$Pport$PQ_flow_vr : comp->fmuData->localData[0]->realVars[17] = value; break;
    case $PtemperatureStreamPort1$Pmeasured_temperature1$Pmeasured_temperature$lB1$rB_vr : comp->fmuData->localData[0]->realVars[18] = value; break;
    case $PtemperatureStreamPort1$Pmeasured_temperature1$Pmeasured_temperature$lB2$rB_vr : comp->fmuData->localData[0]->realVars[19] = value; break;
    case $PtemperatureStreamPort1$Pmeasured_temperature1$Pmeasured_temperature$lB3$rB_vr : comp->fmuData->localData[0]->realVars[20] = value; break;
    case $PtheCon$PQ_flow_vr : comp->fmuData->localData[0]->realVars[21] = value; break;
    case $PtheCon$PdT_vr : comp->fmuData->localData[0]->realVars[22] = value; break;
    case $PthermostatControlPort1$Pset_target_temperature1$Ptarget_temperature$lB1$rB_vr : comp->fmuData->localData[0]->realVars[23] = value; break;
    case $PthermostatControlPort1$Pset_target_temperature1$Ptarget_temperature$lB2$rB_vr : comp->fmuData->localData[0]->realVars[24] = value; break;
    case $PthermostatControlPort1$Pset_target_temperature1$Ptarget_temperature$lB3$rB_vr : comp->fmuData->localData[0]->realVars[25] = value; break;
    case $Pvol$PdynBal$PHb_flow_vr : comp->fmuData->localData[0]->realVars[26] = value; break;
    case $Pvol$PdynBal$PU_vr : comp->fmuData->localData[0]->realVars[27] = value; break;
    case $Pvol$PdynBal$PmWat_flow_internal_vr : comp->fmuData->localData[0]->realVars[28] = value; break;
    case $Pvol$PdynBal$PmXi$lB1$rB_vr : comp->fmuData->localData[0]->realVars[29] = value; break;
    case $Pvol$PdynBal$PmbXi_flow$lB1$rB_vr : comp->fmuData->localData[0]->realVars[30] = value; break;
    case $Pvol$PdynBal$Pmb_flow_vr : comp->fmuData->localData[0]->realVars[31] = value; break;
    case $Pvol$PdynBal$Pmedium$PMM_vr : comp->fmuData->localData[0]->realVars[32] = value; break;
    case $Pvol$PdynBal$Pmedium$PR_vr : comp->fmuData->localData[0]->realVars[33] = value; break;
    case $Pvol$PdynBal$Pmedium$PT_vr : comp->fmuData->localData[0]->realVars[34] = value; break;
    case $Pvol$PdynBal$Pmedium$PX$lB2$rB_vr : comp->fmuData->localData[0]->realVars[35] = value; break;
    case $Pvol$PdynBal$Pmedium$Pd_vr : comp->fmuData->localData[0]->realVars[36] = value; break;
    case $Pvol$PdynBal$Pmedium$PdT_vr : comp->fmuData->localData[0]->realVars[37] = value; break;
    case $Pvol$PdynBal$Pmedium$Pp_vr : comp->fmuData->localData[0]->realVars[38] = value; break;
    case $Pvol$PdynBal$Pmedium$Pp_bar_vr : comp->fmuData->localData[0]->realVars[39] = value; break;
    case $Pvol$PdynBal$Pmedium$Pu_vr : comp->fmuData->localData[0]->realVars[40] = value; break;
    case $Pvol$PheatPort$PQ_flow_vr : comp->fmuData->localData[0]->realVars[41] = value; break;
    case $PHeatingControlPortTransformer1$Pset_hysteresis_intervallumSignalHolder$PentryTime_vr : comp->fmuData->localData[0]->realVars[42] = value; break;
    case $Pset_hysteresis_intervallum_tester1$Py_vr : comp->fmuData->localData[0]->realVars[43] = value; break;
    case $PtemperatureStreamPortTransformer1$Pmeasured_temperatureSignalHolder$PentryTime_vr : comp->fmuData->localData[0]->realVars[44] = value; break;
    case $PthermostatControlPortTransformer1$Pset_target_temperatureSignalHolder$PentryTime_vr : comp->fmuData->localData[0]->realVars[45] = value; break;
    case $PthermostatControlPortTransformer1$Pturn_thermostat_offSignalHolder$PentryTime_vr : comp->fmuData->localData[0]->realVars[46] = value; break;
    case $PthermostatControlPortTransformer1$Pturn_thermostat_onSignalHolder$PentryTime_vr : comp->fmuData->localData[0]->realVars[47] = value; break;
    case $PHeatingControlPortTransformer1$Pset_hysteresis_intervallum_hysteresis_intervallum_initial_vr : comp->fmuData->simulationInfo->realParameter[0] = value; break;
    case $PQRooInt_flow_vr : comp->fmuData->simulationInfo->realParameter[1] = value; break;
    case $PTOut$PT_vr : comp->fmuData->simulationInfo->realParameter[2] = value; break;
    case $PV_vr : comp->fmuData->simulationInfo->realParameter[3] = value; break;
    case $PbooleanToReal1$PrealFalse_vr : comp->fmuData->simulationInfo->realParameter[4] = value; break;
    case $PbooleanToReal1$PrealTrue_vr : comp->fmuData->simulationInfo->realParameter[5] = value; break;
    case $PheaCap$PC_vr : comp->fmuData->simulationInfo->realParameter[6] = value; break;
    case $PheatingFactor_vr : comp->fmuData->simulationInfo->realParameter[7] = value; break;
    case $PmA_flow_nominal_vr : comp->fmuData->simulationInfo->realParameter[8] = value; break;
    case $PpreHea$PT_ref_vr : comp->fmuData->simulationInfo->realParameter[9] = value; break;
    case $PpreHea$Palpha_vr : comp->fmuData->simulationInfo->realParameter[10] = value; break;
    case $PsampleTrigger1$Pperiod_vr : comp->fmuData->simulationInfo->realParameter[11] = value; break;
    case $PsampleTrigger1$PstartTime_vr : comp->fmuData->simulationInfo->realParameter[12] = value; break;
    case $PsampleTrigger2$Pperiod_vr : comp->fmuData->simulationInfo->realParameter[13] = value; break;
    case $PsampleTrigger2$PstartTime_vr : comp->fmuData->simulationInfo->realParameter[14] = value; break;
    case $Pset_hysteresis_intervallum_tester1$PsampleTrigger1$Pperiod_vr : comp->fmuData->simulationInfo->realParameter[15] = value; break;
    case $Pset_hysteresis_intervallum_tester1$PsampleTrigger1$PstartTime_vr : comp->fmuData->simulationInfo->realParameter[16] = value; break;
    case $Pstep1$Pheight_vr : comp->fmuData->simulationInfo->realParameter[17] = value; break;
    case $Pstep1$Poffset_vr : comp->fmuData->simulationInfo->realParameter[18] = value; break;
    case $Pstep1$PstartTime_vr : comp->fmuData->simulationInfo->realParameter[19] = value; break;
    case $PtemperatureStreamPortTransformer1$Pmeasured_temperature_measured_temperature_initial_vr : comp->fmuData->simulationInfo->realParameter[20] = value; break;
    case $PtheCon$PG_vr : comp->fmuData->simulationInfo->realParameter[21] = value; break;
    case $PthermostatControlPortTransformer1$Pset_target_temperature_target_temperature_initial_vr : comp->fmuData->simulationInfo->realParameter[22] = value; break;
    case $Pvol$PT_start_vr : comp->fmuData->simulationInfo->realParameter[23] = value; break;
    case $Pvol$PV_vr : comp->fmuData->simulationInfo->realParameter[24] = value; break;
    case $Pvol$PX_start$lB1$rB_vr : comp->fmuData->simulationInfo->realParameter[25] = value; break;
    case $Pvol$PX_start$lB2$rB_vr : comp->fmuData->simulationInfo->realParameter[26] = value; break;
    case $Pvol$PdynBal$PCSen_vr : comp->fmuData->simulationInfo->realParameter[27] = value; break;
    case $Pvol$PdynBal$PT_start_vr : comp->fmuData->simulationInfo->realParameter[28] = value; break;
    case $Pvol$PdynBal$PX_start$lB1$rB_vr : comp->fmuData->simulationInfo->realParameter[29] = value; break;
    case $Pvol$PdynBal$PX_start$lB2$rB_vr : comp->fmuData->simulationInfo->realParameter[30] = value; break;
    case $Pvol$PdynBal$Pcp_default_vr : comp->fmuData->simulationInfo->realParameter[31] = value; break;
    case $Pvol$PdynBal$PfluidVolume_vr : comp->fmuData->simulationInfo->realParameter[32] = value; break;
    case $Pvol$PdynBal$PhStart_vr : comp->fmuData->simulationInfo->realParameter[33] = value; break;
    case $Pvol$PdynBal$PmSenFac_vr : comp->fmuData->simulationInfo->realParameter[34] = value; break;
    case $Pvol$PdynBal$Pp_start_vr : comp->fmuData->simulationInfo->realParameter[35] = value; break;
    case $Pvol$PdynBal$Prho_default_vr : comp->fmuData->simulationInfo->realParameter[36] = value; break;
    case $Pvol$PdynBal$Prho_start_vr : comp->fmuData->simulationInfo->realParameter[37] = value; break;
    case $Pvol$PdynBal$Ps$lB1$rB_vr : comp->fmuData->simulationInfo->realParameter[38] = value; break;
    case $Pvol$PdynBal$Pstate_default$PT_vr : comp->fmuData->simulationInfo->realParameter[39] = value; break;
    case $Pvol$PdynBal$Pstate_default$PX$lB1$rB_vr : comp->fmuData->simulationInfo->realParameter[40] = value; break;
    case $Pvol$PdynBal$Pstate_default$PX$lB2$rB_vr : comp->fmuData->simulationInfo->realParameter[41] = value; break;
    case $Pvol$PdynBal$Pstate_default$Pp_vr : comp->fmuData->simulationInfo->realParameter[42] = value; break;
    case $Pvol$PmSenFac_vr : comp->fmuData->simulationInfo->realParameter[43] = value; break;
    case $Pvol$Pm_flow_nominal_vr : comp->fmuData->simulationInfo->realParameter[44] = value; break;
    case $Pvol$Pm_flow_small_vr : comp->fmuData->simulationInfo->realParameter[45] = value; break;
    case $Pvol$Pp_start_vr : comp->fmuData->simulationInfo->realParameter[46] = value; break;
    case $Pvol$Prho_default_vr : comp->fmuData->simulationInfo->realParameter[47] = value; break;
    case $Pvol$Prho_start_vr : comp->fmuData->simulationInfo->realParameter[48] = value; break;
    case $Pvol$Pstate_default$PT_vr : comp->fmuData->simulationInfo->realParameter[49] = value; break;
    case $Pvol$Pstate_default$PX$lB1$rB_vr : comp->fmuData->simulationInfo->realParameter[50] = value; break;
    case $Pvol$Pstate_default$PX$lB2$rB_vr : comp->fmuData->simulationInfo->realParameter[51] = value; break;
    case $Pvol$Pstate_default$Pp_vr : comp->fmuData->simulationInfo->realParameter[52] = value; break;
    case $Pvol$Pstate_start$PT_vr : comp->fmuData->simulationInfo->realParameter[53] = value; break;
    case $Pvol$Pstate_start$PX$lB1$rB_vr : comp->fmuData->simulationInfo->realParameter[54] = value; break;
    case $Pvol$Pstate_start$PX$lB2$rB_vr : comp->fmuData->simulationInfo->realParameter[55] = value; break;
    case $Pvol$Pstate_start$Pp_vr : comp->fmuData->simulationInfo->realParameter[56] = value; break;
    case $PHeatingControlPortTransformer1$PHeatingControlPort1$Pset_hysteresis_intervallum1$Physteresis_intervallum$lB1$rB_vr : return setReal(comp, $PheatingControlPort1$Pset_hysteresis_intervallum1$Physteresis_intervallum$lB1$rB_vr, value); break;
    case $PHeatingControlPortTransformer1$PHeatingControlPort1$Pset_hysteresis_intervallum1$Physteresis_intervallum$lB2$rB_vr : return setReal(comp, $PHeatingControlPortTransformer1$Pset_hysteresis_intervallum_hysteresis_intervallum_initial_vr, value); break;
    case $PHeatingControlPortTransformer1$PHeatingControlPort1$Pset_hysteresis_intervallum1$Physteresis_intervallum$lB3$rB_vr : return setReal(comp, $PHeatingControlPortTransformer1$Pset_hysteresis_intervallum_hysteresis_intervallum_initial_vr, value); break;
    case $PHeatingControlPortTransformer1$Pset_hysteresis_intervallum_hysteresis_intervallum_vr : return setReal(comp, $PheatingControlPort1$Pset_hysteresis_intervallum1$Physteresis_intervallum$lB1$rB_vr, value); break;
    case $PTOut$Pport$PQ_flow_vr : return setReal(comp, $PtheCon$PQ_flow_vr, (- value)); break;
    case $PTOut$Pport$PT_vr : return setReal(comp, $PTOut$PT_vr, value); break;
    case $PheaCap$Pport$PT_vr : return setReal(comp, $PheaCap$PT_vr, value); break;
    case $PpreHea$PQ_flow_vr : return setReal(comp, $PbooleanToReal1$Py_vr, value); break;
    case $PpreHea$Pport$PT_vr : return setReal(comp, $PheaCap$PT_vr, value); break;
    case $Pstep1$Py_vr : return setReal(comp, $PthermostatControlPort1$Pset_target_temperature1$Ptarget_temperature$lB1$rB_vr, value); break;
    case $PtemperatureStreamPortTransformer1$PTemperatureStreamPort1$Pmeasured_temperature1$Pmeasured_temperature$lB1$rB_vr : return setReal(comp, $PtemperatureStreamPort1$Pmeasured_temperature1$Pmeasured_temperature$lB1$rB_vr, value); break;
    case $PtemperatureStreamPortTransformer1$PTemperatureStreamPort1$Pmeasured_temperature1$Pmeasured_temperature$lB2$rB_vr : return setReal(comp, $PtemperatureStreamPortTransformer1$Pmeasured_temperature_measured_temperature_initial_vr, value); break;
    case $PtemperatureStreamPortTransformer1$PTemperatureStreamPort1$Pmeasured_temperature1$Pmeasured_temperature$lB3$rB_vr : return setReal(comp, $PtemperatureStreamPortTransformer1$Pmeasured_temperature_measured_temperature_initial_vr, value); break;
    case $PtemperatureStreamPortTransformer1$Pmeasured_temperature_measured_temperature_vr : return setReal(comp, $PtemperatureStreamPort1$Pmeasured_temperature1$Pmeasured_temperature$lB1$rB_vr, value); break;
    case $PtheCon$Pport_a$PQ_flow_vr : return setReal(comp, $PtheCon$PQ_flow_vr, value); break;
    case $PtheCon$Pport_a$PT_vr : return setReal(comp, $PTOut$PT_vr, value); break;
    case $PtheCon$Pport_b$PQ_flow_vr : return setReal(comp, $PtheCon$PQ_flow_vr, (- value)); break;
    case $PtheCon$Pport_b$PT_vr : return setReal(comp, $PheaCap$PT_vr, value); break;
    case $PthermostatControlPortTransformer1$PThermostatControlPort1$Pset_target_temperature1$Ptarget_temperature$lB1$rB_vr : return setReal(comp, $PthermostatControlPort1$Pset_target_temperature1$Ptarget_temperature$lB1$rB_vr, value); break;
    case $PthermostatControlPortTransformer1$PThermostatControlPort1$Pset_target_temperature1$Ptarget_temperature$lB2$rB_vr : return setReal(comp, $PthermostatControlPortTransformer1$Pset_target_temperature_target_temperature_initial_vr, value); break;
    case $PthermostatControlPortTransformer1$PThermostatControlPort1$Pset_target_temperature1$Ptarget_temperature$lB3$rB_vr : return setReal(comp, $PthermostatControlPortTransformer1$Pset_target_temperature_target_temperature_initial_vr, value); break;
    case $PthermostatControlPortTransformer1$Pset_target_temperature_target_temperature_vr : return setReal(comp, $PthermostatControlPort1$Pset_target_temperature1$Ptarget_temperature$lB1$rB_vr, value); break;
    case $Pvol$PT_vr : return setReal(comp, $PheaCap$PT_vr, value); break;
    case $Pvol$PU_vr : return setReal(comp, $Pvol$PdynBal$PU_vr, value); break;
    case $Pvol$PXi$lB1$rB_vr : return setReal(comp, $Pvol$PdynBal$Pmedium$PXi$lB1$rB_vr, value); break;
    case $Pvol$PXiOut_internal$lB1$rB_vr : return setReal(comp, $Pvol$PdynBal$Pmedium$PXi$lB1$rB_vr, value); break;
    case $Pvol$PdynBal$PQ_flow_vr : return setReal(comp, $Pvol$PheatPort$PQ_flow_vr, value); break;
    case $Pvol$PdynBal$PUOut_vr : return setReal(comp, $Pvol$PdynBal$PU_vr, value); break;
    case $Pvol$PdynBal$PXiOut$lB1$rB_vr : return setReal(comp, $Pvol$PdynBal$Pmedium$PXi$lB1$rB_vr, value); break;
    case $Pvol$PdynBal$PhOut_vr : return setReal(comp, $Pvol$PhOut_internal_vr, value); break;
    case $Pvol$PdynBal$PmOut_vr : return setReal(comp, $Pvol$PdynBal$Pm_vr, value); break;
    case $Pvol$PdynBal$PmXiOut$lB1$rB_vr : return setReal(comp, $Pvol$PdynBal$PmXi$lB1$rB_vr, value); break;
    case $Pvol$PdynBal$Pmedium$PT_degC_vr : return setReal(comp, $Pvol$PdynBal$Pmedium$PdT_vr, value); break;
    case $Pvol$PdynBal$Pmedium$PX$lB1$rB_vr : return setReal(comp, $Pvol$PdynBal$Pmedium$PXi$lB1$rB_vr, value); break;
    case $Pvol$PdynBal$Pmedium$PX_air_vr : return setReal(comp, $Pvol$PdynBal$Pmedium$PX$lB2$rB_vr, value); break;
    case $Pvol$PdynBal$Pmedium$PX_steam_vr : return setReal(comp, $Pvol$PdynBal$Pmedium$PXi$lB1$rB_vr, value); break;
    case $Pvol$PdynBal$Pmedium$Ph_vr : return setReal(comp, $Pvol$PhOut_internal_vr, value); break;
    case $Pvol$PdynBal$Pmedium$Pstate$PT_vr : return setReal(comp, $Pvol$PdynBal$Pmedium$PT_vr, value); break;
    case $Pvol$PdynBal$Pmedium$Pstate$PX$lB1$rB_vr : return setReal(comp, $Pvol$PdynBal$Pmedium$PXi$lB1$rB_vr, value); break;
    case $Pvol$PdynBal$Pmedium$Pstate$PX$lB2$rB_vr : return setReal(comp, $Pvol$PdynBal$Pmedium$PX$lB2$rB_vr, value); break;
    case $Pvol$PdynBal$Pmedium$Pstate$Pp_vr : return setReal(comp, $Pvol$PdynBal$Pmedium$Pp_vr, value); break;
    case $Pvol$PheaFloSen$PQ_flow_vr : return setReal(comp, $Pvol$PheatPort$PQ_flow_vr, value); break;
    case $Pvol$PheaFloSen$Pport_a$PQ_flow_vr : return setReal(comp, $Pvol$PheatPort$PQ_flow_vr, value); break;
    case $Pvol$PheaFloSen$Pport_a$PT_vr : return setReal(comp, $PheaCap$PT_vr, value); break;
    case $Pvol$PheaFloSen$Pport_b$PQ_flow_vr : return setReal(comp, $Pvol$PheatPort$PQ_flow_vr, (- value)); break;
    case $Pvol$PheaFloSen$Pport_b$PT_vr : return setReal(comp, $PheaCap$PT_vr, value); break;
    case $Pvol$PheatPort$PT_vr : return setReal(comp, $PheaCap$PT_vr, value); break;
    case $Pvol$Pm_vr : return setReal(comp, $Pvol$PdynBal$Pm_vr, value); break;
    case $Pvol$PmXi$lB1$rB_vr : return setReal(comp, $Pvol$PdynBal$PmXi$lB1$rB_vr, value); break;
    case $Pvol$Pp_vr : return setReal(comp, $Pvol$Pp_start_vr, value); break;
    case $Pvol$PportT$Py_vr : return setReal(comp, $PheaCap$PT_vr, value); break;
    case $Pvol$PpreTem$PT_vr : return setReal(comp, $PheaCap$PT_vr, value); break;
    case $Pvol$PpreTem$Pport$PQ_flow_vr : return setReal(comp, $Pvol$PheatPort$PQ_flow_vr, value); break;
    case $Pvol$PpreTem$Pport$PT_vr : return setReal(comp, $PheaCap$PT_vr, value); break;
    default:
      return fmi2Error;
  }
  return fmi2OK;
}

fmi2Integer getInteger(ModelInstance* comp, const fmi2ValueReference vr) {
  switch (vr) {
    case $PHeatingControlPortTransformer1$PHeatingControlPort1$Pset_hysteresis_intervallum1$Pcounter_vr : return comp->fmuData->localData[0]->integerVars[0]; break;
    case $PheatingControlPort1$Pset_hysteresis_intervallum1$Pcounter_vr : return comp->fmuData->localData[0]->integerVars[1]; break;
    case $PheatingControlPort1$Pturn_heating_off1$Pcounter_vr : return comp->fmuData->localData[0]->integerVars[2]; break;
    case $PheatingControlPort1$Pturn_heating_on1$Pcounter_vr : return comp->fmuData->localData[0]->integerVars[3]; break;
    case $PtemperatureStreamPort1$Pmeasured_temperature1$Pcounter_vr : return comp->fmuData->localData[0]->integerVars[4]; break;
    case $PtemperatureStreamPortTransformer1$PTemperatureStreamPort1$Pmeasured_temperature1$Pcounter_vr : return comp->fmuData->localData[0]->integerVars[5]; break;
    case $PthermostatControlPort1$Pset_target_temperature1$Pcounter_vr : return comp->fmuData->localData[0]->integerVars[6]; break;
    case $PthermostatControlPort1$Pturn_thermostat_off1$Pcounter_vr : return comp->fmuData->localData[0]->integerVars[7]; break;
    case $PthermostatControlPort1$Pturn_thermostat_on1$Pcounter_vr : return comp->fmuData->localData[0]->integerVars[8]; break;
    case $PthermostatControlPortTransformer1$PThermostatControlPort1$Pset_target_temperature1$Pcounter_vr : return comp->fmuData->localData[0]->integerVars[9]; break;
    case $Pvol$PdynBal$PenergyDynamics_vr : return comp->fmuData->simulationInfo->integerParameter[0]; break;
    case $Pvol$PdynBal$PmassDynamics_vr : return comp->fmuData->simulationInfo->integerParameter[1]; break;
    case $Pvol$PdynBal$PnPorts_vr : return comp->fmuData->simulationInfo->integerParameter[2]; break;
    case $Pvol$PdynBal$PsubstanceDynamics_vr : return comp->fmuData->simulationInfo->integerParameter[3]; break;
    case $Pvol$PdynBal$PtraceDynamics_vr : return comp->fmuData->simulationInfo->integerParameter[4]; break;
    case $Pvol$PenergyDynamics_vr : return comp->fmuData->simulationInfo->integerParameter[5]; break;
    case $Pvol$PmassDynamics_vr : return comp->fmuData->simulationInfo->integerParameter[6]; break;
    case $Pvol$PnPorts_vr : return comp->fmuData->simulationInfo->integerParameter[7]; break;
    case $Pvol$PsubstanceDynamics_vr : return comp->fmuData->simulationInfo->integerParameter[8]; break;
    case $Pvol$PtraceDynamics_vr : return comp->fmuData->simulationInfo->integerParameter[9]; break;
    case $PHeatingControlPortTransformer1$PHeatingControlPort1$Pturn_heating_off1$Pcounter_vr : return getInteger(comp, $PheatingControlPort1$Pturn_heating_off1$Pcounter_vr); break;
    case $PHeatingControlPortTransformer1$PHeatingControlPort1$Pturn_heating_on1$Pcounter_vr : return getInteger(comp, $PheatingControlPort1$Pturn_heating_on1$Pcounter_vr); break;
    case $PthermostatControlPortTransformer1$PThermostatControlPort1$Pturn_thermostat_off1$Pcounter_vr : return getInteger(comp, $PthermostatControlPort1$Pturn_thermostat_off1$Pcounter_vr); break;
    case $PthermostatControlPortTransformer1$PThermostatControlPort1$Pturn_thermostat_on1$Pcounter_vr : return getInteger(comp, $PthermostatControlPort1$Pturn_thermostat_on1$Pcounter_vr); break;
    default:
      return 0;
  }
}
fmi2Status setInteger(ModelInstance* comp, const fmi2ValueReference vr, const fmi2Integer value) {
  switch (vr) {
    case $PHeatingControlPortTransformer1$PHeatingControlPort1$Pset_hysteresis_intervallum1$Pcounter_vr : comp->fmuData->localData[0]->integerVars[0] = value; break;
    case $PheatingControlPort1$Pset_hysteresis_intervallum1$Pcounter_vr : comp->fmuData->localData[0]->integerVars[1] = value; break;
    case $PheatingControlPort1$Pturn_heating_off1$Pcounter_vr : comp->fmuData->localData[0]->integerVars[2] = value; break;
    case $PheatingControlPort1$Pturn_heating_on1$Pcounter_vr : comp->fmuData->localData[0]->integerVars[3] = value; break;
    case $PtemperatureStreamPort1$Pmeasured_temperature1$Pcounter_vr : comp->fmuData->localData[0]->integerVars[4] = value; break;
    case $PtemperatureStreamPortTransformer1$PTemperatureStreamPort1$Pmeasured_temperature1$Pcounter_vr : comp->fmuData->localData[0]->integerVars[5] = value; break;
    case $PthermostatControlPort1$Pset_target_temperature1$Pcounter_vr : comp->fmuData->localData[0]->integerVars[6] = value; break;
    case $PthermostatControlPort1$Pturn_thermostat_off1$Pcounter_vr : comp->fmuData->localData[0]->integerVars[7] = value; break;
    case $PthermostatControlPort1$Pturn_thermostat_on1$Pcounter_vr : comp->fmuData->localData[0]->integerVars[8] = value; break;
    case $PthermostatControlPortTransformer1$PThermostatControlPort1$Pset_target_temperature1$Pcounter_vr : comp->fmuData->localData[0]->integerVars[9] = value; break;
    case $Pvol$PdynBal$PenergyDynamics_vr : comp->fmuData->simulationInfo->integerParameter[0] = value; break;
    case $Pvol$PdynBal$PmassDynamics_vr : comp->fmuData->simulationInfo->integerParameter[1] = value; break;
    case $Pvol$PdynBal$PnPorts_vr : comp->fmuData->simulationInfo->integerParameter[2] = value; break;
    case $Pvol$PdynBal$PsubstanceDynamics_vr : comp->fmuData->simulationInfo->integerParameter[3] = value; break;
    case $Pvol$PdynBal$PtraceDynamics_vr : comp->fmuData->simulationInfo->integerParameter[4] = value; break;
    case $Pvol$PenergyDynamics_vr : comp->fmuData->simulationInfo->integerParameter[5] = value; break;
    case $Pvol$PmassDynamics_vr : comp->fmuData->simulationInfo->integerParameter[6] = value; break;
    case $Pvol$PnPorts_vr : comp->fmuData->simulationInfo->integerParameter[7] = value; break;
    case $Pvol$PsubstanceDynamics_vr : comp->fmuData->simulationInfo->integerParameter[8] = value; break;
    case $Pvol$PtraceDynamics_vr : comp->fmuData->simulationInfo->integerParameter[9] = value; break;
    case $PHeatingControlPortTransformer1$PHeatingControlPort1$Pturn_heating_off1$Pcounter_vr : return setInteger(comp, $PheatingControlPort1$Pturn_heating_off1$Pcounter_vr, value); break;
    case $PHeatingControlPortTransformer1$PHeatingControlPort1$Pturn_heating_on1$Pcounter_vr : return setInteger(comp, $PheatingControlPort1$Pturn_heating_on1$Pcounter_vr, value); break;
    case $PthermostatControlPortTransformer1$PThermostatControlPort1$Pturn_thermostat_off1$Pcounter_vr : return setInteger(comp, $PthermostatControlPort1$Pturn_thermostat_off1$Pcounter_vr, value); break;
    case $PthermostatControlPortTransformer1$PThermostatControlPort1$Pturn_thermostat_on1$Pcounter_vr : return setInteger(comp, $PthermostatControlPort1$Pturn_thermostat_on1$Pcounter_vr, value); break;
    default:
      return fmi2Error;
  }
  return fmi2OK;
}
fmi2Boolean getBoolean(ModelInstance* comp, const fmi2ValueReference vr) {
  switch (vr) {
    case $P$whenCondition1_vr : return comp->fmuData->localData[0]->booleanVars[0]; break;
    case $P$whenCondition10_vr : return comp->fmuData->localData[0]->booleanVars[1]; break;
    case $P$whenCondition11_vr : return comp->fmuData->localData[0]->booleanVars[2]; break;
    case $P$whenCondition12_vr : return comp->fmuData->localData[0]->booleanVars[3]; break;
    case $P$whenCondition13_vr : return comp->fmuData->localData[0]->booleanVars[4]; break;
    case $P$whenCondition14_vr : return comp->fmuData->localData[0]->booleanVars[5]; break;
    case $P$whenCondition2_vr : return comp->fmuData->localData[0]->booleanVars[6]; break;
    case $P$whenCondition3_vr : return comp->fmuData->localData[0]->booleanVars[7]; break;
    case $P$whenCondition4_vr : return comp->fmuData->localData[0]->booleanVars[8]; break;
    case $P$whenCondition5_vr : return comp->fmuData->localData[0]->booleanVars[9]; break;
    case $P$whenCondition6_vr : return comp->fmuData->localData[0]->booleanVars[10]; break;
    case $P$whenCondition7_vr : return comp->fmuData->localData[0]->booleanVars[11]; break;
    case $P$whenCondition8_vr : return comp->fmuData->localData[0]->booleanVars[12]; break;
    case $P$whenCondition9_vr : return comp->fmuData->localData[0]->booleanVars[13]; break;
    case $PHeatingControlPortTransformer1$Pset_hysteresis_intervallumSignalHolder$Pu_vr : return comp->fmuData->localData[0]->booleanVars[14]; break;
    case $PHeatingControlPortTransformer1$Pset_hysteresis_intervallumSignalHolder$Py_vr : return comp->fmuData->localData[0]->booleanVars[15]; break;
    case $PHeatingControlPortTransformer1$Pturn_heating_off_vr : return comp->fmuData->localData[0]->booleanVars[16]; break;
    case $PHeatingControlPortTransformer1$Pturn_heating_on_vr : return comp->fmuData->localData[0]->booleanVars[17]; break;
    case $PbooleanToReal1$Pu_vr : return comp->fmuData->localData[0]->booleanVars[18]; break;
    case $PrSFlipFlop$PQI_vr : return comp->fmuData->localData[0]->booleanVars[19]; break;
    case $PrSFlipFlop$Ppre$Pu_vr : return comp->fmuData->localData[0]->booleanVars[20]; break;
    case $PtemperatureStreamPortTransformer1$Pmeasured_temperatureSignalHolder$Pu_vr : return comp->fmuData->localData[0]->booleanVars[21]; break;
    case $PtemperatureStreamPortTransformer1$Pmeasured_temperatureSignalHolder$Py_vr : return comp->fmuData->localData[0]->booleanVars[22]; break;
    case $PthermostatControlPortTransformer1$Pset_target_temperatureSignalHolder$Pu_vr : return comp->fmuData->localData[0]->booleanVars[23]; break;
    case $PthermostatControlPortTransformer1$Pset_target_temperatureSignalHolder$Py_vr : return comp->fmuData->localData[0]->booleanVars[24]; break;
    case $PthermostatControlPortTransformer1$Pturn_thermostat_offSignalHolder$Pu_vr : return comp->fmuData->localData[0]->booleanVars[25]; break;
    case $PthermostatControlPortTransformer1$Pturn_thermostat_offSignalHolder$Py_vr : return comp->fmuData->localData[0]->booleanVars[26]; break;
    case $PthermostatControlPortTransformer1$Pturn_thermostat_onSignalHolder$Pu_vr : return comp->fmuData->localData[0]->booleanVars[27]; break;
    case $PthermostatControlPortTransformer1$Pturn_thermostat_onSignalHolder$Py_vr : return comp->fmuData->localData[0]->booleanVars[28]; break;
    case $PbooleanConstant1$Pk_vr : return comp->fmuData->simulationInfo->booleanParameter[0]; break;
    case $PrSFlipFlop$PQini_vr : return comp->fmuData->simulationInfo->booleanParameter[1]; break;
    case $PrSFlipFlop$Ppre$Ppre_u_start_vr : return comp->fmuData->simulationInfo->booleanParameter[2]; break;
    case $Pvol$PallowFlowReversal_vr : return comp->fmuData->simulationInfo->booleanParameter[3]; break;
    case $Pvol$PdynBal$PcomputeCSen_vr : return comp->fmuData->simulationInfo->booleanParameter[4]; break;
    case $Pvol$PdynBal$Pmedium$PpreferredMediumStates_vr : return comp->fmuData->simulationInfo->booleanParameter[5]; break;
    case $Pvol$PdynBal$Pmedium$PstandardOrderComponents_vr : return comp->fmuData->simulationInfo->booleanParameter[6]; break;
    case $Pvol$PdynBal$Puse_C_flow_vr : return comp->fmuData->simulationInfo->booleanParameter[7]; break;
    case $Pvol$PdynBal$Puse_mWat_flow_vr : return comp->fmuData->simulationInfo->booleanParameter[8]; break;
    case $Pvol$PuseSteadyStateTwoPort_vr : return comp->fmuData->simulationInfo->booleanParameter[9]; break;
    case $Pvol$Puse_C_flow_vr : return comp->fmuData->simulationInfo->booleanParameter[10]; break;
    case $PHeatingControlPortTransformer1$Pset_hysteresis_intervallum_vr : return getBoolean(comp, $PHeatingControlPortTransformer1$Pset_hysteresis_intervallumSignalHolder$Pu_vr); break;
    case $PbooleanConstant1$Py_vr : return getBoolean(comp, $PbooleanConstant1$Pk_vr); break;
    case $PrSFlipFlop$PQ_vr : return getBoolean(comp, $PbooleanToReal1$Pu_vr); break;
    case $PrSFlipFlop$PR_vr : return getBoolean(comp, $PHeatingControlPortTransformer1$Pturn_heating_off_vr); break;
    case $PrSFlipFlop$PS_vr : return getBoolean(comp, $PHeatingControlPortTransformer1$Pturn_heating_on_vr); break;
    case $PrSFlipFlop$Pnor$Pu1_vr : return getBoolean(comp, $PHeatingControlPortTransformer1$Pturn_heating_on_vr); break;
    case $PrSFlipFlop$Pnor$Pu2_vr : return getBoolean(comp, $PbooleanToReal1$Pu_vr); break;
    case $PrSFlipFlop$Pnor$Py_vr : return getBoolean(comp, $PrSFlipFlop$Ppre$Pu_vr); break;
    case $PrSFlipFlop$Pnor1$Pu1_vr : return getBoolean(comp, $PrSFlipFlop$PQI_vr); break;
    case $PrSFlipFlop$Pnor1$Pu2_vr : return getBoolean(comp, $PHeatingControlPortTransformer1$Pturn_heating_off_vr); break;
    case $PrSFlipFlop$Pnor1$Py_vr : return getBoolean(comp, $PbooleanToReal1$Pu_vr); break;
    case $PrSFlipFlop$Ppre$Py_vr : return getBoolean(comp, $PrSFlipFlop$PQI_vr); break;
    case $PsampleTrigger1$Py_vr : return getBoolean(comp, $PthermostatControlPortTransformer1$Pturn_thermostat_onSignalHolder$Pu_vr); break;
    case $PsampleTrigger2$Py_vr : return getBoolean(comp, $PthermostatControlPortTransformer1$Pturn_thermostat_offSignalHolder$Pu_vr); break;
    case $Pset_hysteresis_intervallum_tester1$PsampleTrigger1$Py_vr : return getBoolean(comp, $PHeatingControlPortTransformer1$Pset_hysteresis_intervallumSignalHolder$Pu_vr); break;
    case $Pset_hysteresis_intervallum_tester1$Py1_vr : return getBoolean(comp, $PHeatingControlPortTransformer1$Pset_hysteresis_intervallumSignalHolder$Pu_vr); break;
    case $PtemperatureStreamPortTransformer1$Pmeasured_temperature_vr : return getBoolean(comp, $PbooleanConstant1$Pk_vr); break;
    case $PthermostatControlPortTransformer1$Pset_target_temperature_vr : return getBoolean(comp, $PbooleanConstant1$Pk_vr); break;
    case $PthermostatControlPortTransformer1$Pturn_thermostat_off_vr : return getBoolean(comp, $PthermostatControlPortTransformer1$Pturn_thermostat_offSignalHolder$Pu_vr); break;
    case $PthermostatControlPortTransformer1$Pturn_thermostat_on_vr : return getBoolean(comp, $PthermostatControlPortTransformer1$Pturn_thermostat_onSignalHolder$Pu_vr); break;
    default:
      return fmi2False;
  }
}

fmi2Status setBoolean(ModelInstance* comp, const fmi2ValueReference vr, const fmi2Boolean value) {
  switch (vr) {
    case $P$whenCondition1_vr : comp->fmuData->localData[0]->booleanVars[0] = value; break;
    case $P$whenCondition10_vr : comp->fmuData->localData[0]->booleanVars[1] = value; break;
    case $P$whenCondition11_vr : comp->fmuData->localData[0]->booleanVars[2] = value; break;
    case $P$whenCondition12_vr : comp->fmuData->localData[0]->booleanVars[3] = value; break;
    case $P$whenCondition13_vr : comp->fmuData->localData[0]->booleanVars[4] = value; break;
    case $P$whenCondition14_vr : comp->fmuData->localData[0]->booleanVars[5] = value; break;
    case $P$whenCondition2_vr : comp->fmuData->localData[0]->booleanVars[6] = value; break;
    case $P$whenCondition3_vr : comp->fmuData->localData[0]->booleanVars[7] = value; break;
    case $P$whenCondition4_vr : comp->fmuData->localData[0]->booleanVars[8] = value; break;
    case $P$whenCondition5_vr : comp->fmuData->localData[0]->booleanVars[9] = value; break;
    case $P$whenCondition6_vr : comp->fmuData->localData[0]->booleanVars[10] = value; break;
    case $P$whenCondition7_vr : comp->fmuData->localData[0]->booleanVars[11] = value; break;
    case $P$whenCondition8_vr : comp->fmuData->localData[0]->booleanVars[12] = value; break;
    case $P$whenCondition9_vr : comp->fmuData->localData[0]->booleanVars[13] = value; break;
    case $PHeatingControlPortTransformer1$Pset_hysteresis_intervallumSignalHolder$Pu_vr : comp->fmuData->localData[0]->booleanVars[14] = value; break;
    case $PHeatingControlPortTransformer1$Pset_hysteresis_intervallumSignalHolder$Py_vr : comp->fmuData->localData[0]->booleanVars[15] = value; break;
    case $PHeatingControlPortTransformer1$Pturn_heating_off_vr : comp->fmuData->localData[0]->booleanVars[16] = value; break;
    case $PHeatingControlPortTransformer1$Pturn_heating_on_vr : comp->fmuData->localData[0]->booleanVars[17] = value; break;
    case $PbooleanToReal1$Pu_vr : comp->fmuData->localData[0]->booleanVars[18] = value; break;
    case $PrSFlipFlop$PQI_vr : comp->fmuData->localData[0]->booleanVars[19] = value; break;
    case $PrSFlipFlop$Ppre$Pu_vr : comp->fmuData->localData[0]->booleanVars[20] = value; break;
    case $PtemperatureStreamPortTransformer1$Pmeasured_temperatureSignalHolder$Pu_vr : comp->fmuData->localData[0]->booleanVars[21] = value; break;
    case $PtemperatureStreamPortTransformer1$Pmeasured_temperatureSignalHolder$Py_vr : comp->fmuData->localData[0]->booleanVars[22] = value; break;
    case $PthermostatControlPortTransformer1$Pset_target_temperatureSignalHolder$Pu_vr : comp->fmuData->localData[0]->booleanVars[23] = value; break;
    case $PthermostatControlPortTransformer1$Pset_target_temperatureSignalHolder$Py_vr : comp->fmuData->localData[0]->booleanVars[24] = value; break;
    case $PthermostatControlPortTransformer1$Pturn_thermostat_offSignalHolder$Pu_vr : comp->fmuData->localData[0]->booleanVars[25] = value; break;
    case $PthermostatControlPortTransformer1$Pturn_thermostat_offSignalHolder$Py_vr : comp->fmuData->localData[0]->booleanVars[26] = value; break;
    case $PthermostatControlPortTransformer1$Pturn_thermostat_onSignalHolder$Pu_vr : comp->fmuData->localData[0]->booleanVars[27] = value; break;
    case $PthermostatControlPortTransformer1$Pturn_thermostat_onSignalHolder$Py_vr : comp->fmuData->localData[0]->booleanVars[28] = value; break;
    case $PbooleanConstant1$Pk_vr : comp->fmuData->simulationInfo->booleanParameter[0] = value; break;
    case $PrSFlipFlop$PQini_vr : comp->fmuData->simulationInfo->booleanParameter[1] = value; break;
    case $PrSFlipFlop$Ppre$Ppre_u_start_vr : comp->fmuData->simulationInfo->booleanParameter[2] = value; break;
    case $Pvol$PallowFlowReversal_vr : comp->fmuData->simulationInfo->booleanParameter[3] = value; break;
    case $Pvol$PdynBal$PcomputeCSen_vr : comp->fmuData->simulationInfo->booleanParameter[4] = value; break;
    case $Pvol$PdynBal$Pmedium$PpreferredMediumStates_vr : comp->fmuData->simulationInfo->booleanParameter[5] = value; break;
    case $Pvol$PdynBal$Pmedium$PstandardOrderComponents_vr : comp->fmuData->simulationInfo->booleanParameter[6] = value; break;
    case $Pvol$PdynBal$Puse_C_flow_vr : comp->fmuData->simulationInfo->booleanParameter[7] = value; break;
    case $Pvol$PdynBal$Puse_mWat_flow_vr : comp->fmuData->simulationInfo->booleanParameter[8] = value; break;
    case $Pvol$PuseSteadyStateTwoPort_vr : comp->fmuData->simulationInfo->booleanParameter[9] = value; break;
    case $Pvol$Puse_C_flow_vr : comp->fmuData->simulationInfo->booleanParameter[10] = value; break;
    case $PHeatingControlPortTransformer1$Pset_hysteresis_intervallum_vr : return setBoolean(comp, $PHeatingControlPortTransformer1$Pset_hysteresis_intervallumSignalHolder$Pu_vr, value); break;
    case $PbooleanConstant1$Py_vr : return setBoolean(comp, $PbooleanConstant1$Pk_vr, value); break;
    case $PrSFlipFlop$PQ_vr : return setBoolean(comp, $PbooleanToReal1$Pu_vr, value); break;
    case $PrSFlipFlop$PR_vr : return setBoolean(comp, $PHeatingControlPortTransformer1$Pturn_heating_off_vr, value); break;
    case $PrSFlipFlop$PS_vr : return setBoolean(comp, $PHeatingControlPortTransformer1$Pturn_heating_on_vr, value); break;
    case $PrSFlipFlop$Pnor$Pu1_vr : return setBoolean(comp, $PHeatingControlPortTransformer1$Pturn_heating_on_vr, value); break;
    case $PrSFlipFlop$Pnor$Pu2_vr : return setBoolean(comp, $PbooleanToReal1$Pu_vr, value); break;
    case $PrSFlipFlop$Pnor$Py_vr : return setBoolean(comp, $PrSFlipFlop$Ppre$Pu_vr, value); break;
    case $PrSFlipFlop$Pnor1$Pu1_vr : return setBoolean(comp, $PrSFlipFlop$PQI_vr, value); break;
    case $PrSFlipFlop$Pnor1$Pu2_vr : return setBoolean(comp, $PHeatingControlPortTransformer1$Pturn_heating_off_vr, value); break;
    case $PrSFlipFlop$Pnor1$Py_vr : return setBoolean(comp, $PbooleanToReal1$Pu_vr, value); break;
    case $PrSFlipFlop$Ppre$Py_vr : return setBoolean(comp, $PrSFlipFlop$PQI_vr, value); break;
    case $PsampleTrigger1$Py_vr : return setBoolean(comp, $PthermostatControlPortTransformer1$Pturn_thermostat_onSignalHolder$Pu_vr, value); break;
    case $PsampleTrigger2$Py_vr : return setBoolean(comp, $PthermostatControlPortTransformer1$Pturn_thermostat_offSignalHolder$Pu_vr, value); break;
    case $Pset_hysteresis_intervallum_tester1$PsampleTrigger1$Py_vr : return setBoolean(comp, $PHeatingControlPortTransformer1$Pset_hysteresis_intervallumSignalHolder$Pu_vr, value); break;
    case $Pset_hysteresis_intervallum_tester1$Py1_vr : return setBoolean(comp, $PHeatingControlPortTransformer1$Pset_hysteresis_intervallumSignalHolder$Pu_vr, value); break;
    case $PtemperatureStreamPortTransformer1$Pmeasured_temperature_vr : return setBoolean(comp, $PbooleanConstant1$Pk_vr, value); break;
    case $PthermostatControlPortTransformer1$Pset_target_temperature_vr : return setBoolean(comp, $PbooleanConstant1$Pk_vr, value); break;
    case $PthermostatControlPortTransformer1$Pturn_thermostat_off_vr : return setBoolean(comp, $PthermostatControlPortTransformer1$Pturn_thermostat_offSignalHolder$Pu_vr, value); break;
    case $PthermostatControlPortTransformer1$Pturn_thermostat_on_vr : return setBoolean(comp, $PthermostatControlPortTransformer1$Pturn_thermostat_onSignalHolder$Pu_vr, value); break;
    default:
      return fmi2Error;
  }
  return fmi2OK;
}

fmi2String getString(ModelInstance* comp, const fmi2ValueReference vr) {
  switch (vr) {
    default:
      return "";
  }
}

fmi2Status setString(ModelInstance* comp, const fmi2ValueReference vr, fmi2String value) {
  switch (vr) {
    default:
      return fmi2Error;
  }
  return fmi2OK;
}

fmi2Status setExternalFunction(ModelInstance* c, const fmi2ValueReference vr, const void* value){
  switch (vr) {
    default:
      return fmi2Error;
  }
  return fmi2OK;
}


#ifdef __cplusplus
}
#endif

