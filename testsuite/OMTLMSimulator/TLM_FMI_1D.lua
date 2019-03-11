-- status: correct
-- teardown_command: rm -rf TLM_FMI_1D.log TLM_FMI_1D_tmp/ tlm1d.csv tlm1d.run tlm1d_res.mat TLMlogfile.log fmi1_1d.mat fmi2_1d.mat
-- linux: yes
-- mingw: no
-- mac: no

oms2_setLogFile("TLM_FMI_1D.log")
oms2_setTempDirectory("./TLM_FMI_1D_tmp")

oms2_newFMIModel("fmi1")
oms2_setCommunicationInterval("fmi1", 0.001)
oms2_setResultFile("fmi1", "fmi1_1d.mat")
oms2_addFMU("fmi1", "../FMUs/Mass.fmu", "mass")

oms2_newFMIModel("fmi2")
oms2_setCommunicationInterval("fmi2", 0.001);
oms2_setResultFile("fmi2", "fmi2_1d.mat")
oms2_addFMU("fmi2", "../FMUs/MassSpring.fmu", "mass")

oms2_newTLMModel("tlm1d")
oms2_addFMISubModel("tlm1d", "fmi1")
oms2_addFMISubModel("tlm1d", "fmi2")
oms2_addTLMInterface("tlm1d", "fmi1", "P", 1, bidirectional, "Mechanical", "mass:x", "mass:v", "mass:f")
oms2_addTLMInterface("tlm1d", "fmi2", "P", 1, bidirectional, "Mechanical", "mass:x", "mass:v", "mass:f")
oms2_addTLMConnection("tlm1d", "fmi1:P", "fmi2:P", 0.001, 0.5, 10, 0)

oms2_setTLMSocketData("tlm1d","127.0.1.1",11611,12611)

-- oms2_describe("tlm1d")

oms2_setStartTime("tlm1d", 0)
oms2_setStopTime("tlm1d", 2)
oms2_setLoggingInterval("tlm1d", 1e-4)

oms2_initialize("tlm1d")
oms2_simulate("tlm1d")

oms2_unloadModel("tlm1d")

vars = {"fmi1.P.v [m/s]","fmi2.P.v [m/s]","fmi1.P.F [N]","fmi2.P.F [N]"}
for _,var in ipairs(vars) do
  if 1 == oms2_compareSimulationResults("tlm1d.csv", "../ReferenceFiles/TLM_FMI_1D.csv", var, 1e-2, 1e-4) then
    print(var .. " is equal")
  else
    print(var .. " is not equal")
  end
end

-- Result:
-- Starting TLM simulation.
-- Monitoring thread finished.
-- Manager thread finished.
-- fmi1.P.v [m/s] is equal
-- fmi2.P.v [m/s] is equal
-- fmi1.P.F [N] is equal
-- fmi2.P.F [N] is equal
-- info:    Logging information has been saved to "TLM_FMI_1D.log"
-- info:    2 warnings
-- info:    0 errors
-- endResult
