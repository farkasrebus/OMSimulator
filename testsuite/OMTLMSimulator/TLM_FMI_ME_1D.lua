-- status: correct
-- teardown_command: rm -rf TLM_FMI_ME_1D.log TLM_FMI_ME_1D_tmp/ tlm1d_me.csv tlm1d_me.run tlm1d_me_res.mat TLMlogfile.log fmi1_me_1d.mat fmi2_me_1d.mat
-- linux: yes
-- mingw: no
-- mac: no

oms2_setLogFile("TLM_FMI_ME_1D.log")
oms2_setTempDirectory("./TLM_FMI_ME_1D_tmp")

oms2_newFMIModel("fmi1")
oms2_setCommunicationInterval("fmi1", 0.0005)
--oms2_setResultFile("fmi1", "fmi1_me_1d.mat")
oms2_addFMU("fmi1", "../FMUs/Mass_me.fmu", "mass1")

oms2_newFMIModel("fmi2")
oms2_setCommunicationInterval("fmi2", 0.0005);
--oms2_setResultFile("fmi2", "fmi2_me_1d.mat")
oms2_addFMU("fmi2", "../FMUs/MassSpring_me.fmu", "mass2")

oms2_newTLMModel("tlm1d_me")
oms2_addFMISubModel("tlm1d_me", "fmi1")
oms2_addFMISubModel("tlm1d_me", "fmi2")
oms2_addTLMInterface("tlm1d_me", "fmi1", "P", 1, bidirectional, "Mechanical", "mass1:x", "mass1:v", "mass1:f")
oms2_addTLMInterface("tlm1d_me", "fmi2", "P", 1, bidirectional, "Mechanical", "mass2:x", "mass2:v", "mass2:f")
oms2_addTLMConnection("tlm1d_me", "fmi1:P", "fmi2:P", 0.001, 0.5, 10, 0)

oms2_addSolver("fmi1", "solver1", "cvode")
oms2_addConnection("fmi1", "mass1", "solver1")

oms2_addSolver("fmi2", "solver2", "cvode")
oms2_addConnection("fmi2", "mass2", "solver2")

oms2_setTLMSocketData("tlm1d_me","127.0.1.1",11711,12711)

-- oms2_describe("tlm1d_me")

oms2_setStartTime("tlm1d_me", 0)
oms2_setStopTime("tlm1d_me", 2)
oms2_setLoggingInterval("tlm1d_me", 1e-4)

oms2_initialize("tlm1d_me")
oms2_simulate("tlm1d_me")

oms2_deleteSubModel("fmi1", "solver1")
oms2_deleteSubModel("fmi2", "solver2")

oms2_unloadModel("tlm1d_me")

vars = {"fmi1.P.v [m/s]","fmi2.P.v [m/s]","fmi1.P.F [N]","fmi2.P.F [N]"}
for _,var in ipairs(vars) do
  if 1 == oms2_compareSimulationResults("tlm1d_me.csv", "../ReferenceFiles/TLM_FMI_ME_1D.csv", var, 1e-2, 1e-4) then
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
-- info:    Logging information has been saved to "TLM_FMI_ME_1D.log"
-- endResult
