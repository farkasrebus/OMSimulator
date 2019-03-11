-- status: correct
-- teardown_command: rm -rf TLM_FMI_Submodels.log TLM_FMI_Submodels_tmp/ tlm.run tlm_res.mat tlm.csv fmi1.mat fmi2.mat
-- linux: yes
-- mingw: no
-- mac: no

oms2_setLogFile("TLM_FMI_Submodels.log")
oms2_setTempDirectory("./TLM_FMI_Submodels_tmp")

oms2_newFMIModel("fmi1")
oms2_setResultFile("fmi1", "fmi1.mat")
oms2_addFMU("fmi1", "../FMUs/Modelica.Blocks.Math.Add.fmu", "adder")
oms2_addFMU("fmi1", "../FMUs/sine.fmu", "sine1")
oms2_addFMU("fmi1", "../FMUs/sine.fmu", "sine2")
oms2_addFMU("fmi1", "../FMUs/Modelica.Blocks.Math.Gain.fmu", "gain")
oms2_addConnection("fmi1", "sine1:y", "adder:u1")
oms2_addConnection("fmi1", "sine2:y", "adder:u2")
oms2_setRealParameter("fmi1.sine1:A",1);
oms2_setRealParameter("fmi1.sine1:omega",8);
oms2_setRealParameter("fmi1.sine2:A",0.3);
oms2_setRealParameter("fmi1.sine2:omega",20);

oms2_newFMIModel("fmi2")
oms2_setResultFile("fmi2", "fmi2.mat")
oms2_addFMU("fmi2", "../FMUs/Modelica.Blocks.Math.Gain.fmu", "gain")
oms2_setRealParameter("fmi2.gain:k",2);

oms2_newTLMModel("tlm")
oms2_addFMISubModel("tlm", "fmi1")
oms2_addFMISubModel("tlm", "fmi2")
oms2_addTLMInterface("tlm", "fmi1", "out", 1, output, "Signal", "adder:y")
oms2_addTLMInterface("tlm", "fmi1", "in", 1, input, "Signal", "gain:u")
oms2_addTLMInterface("tlm", "fmi2", "in", 1, input, "Signal", "gain:u")
oms2_addTLMInterface("tlm", "fmi2", "out", 1, output, "Signal", "gain:y")
oms2_addTLMConnection("tlm", "fmi1:out", "fmi2:in", 0.01, 0, 0, 0)
oms2_addTLMConnection("tlm", "fmi2:out", "fmi1:in", 0.01, 0, 0, 0)

oms2_setTLMSocketData("tlm","127.0.1.1",11411,12411)

-- oms2_describe("tlm")

oms2_setStartTime("tlm", 0)
oms2_setStopTime("tlm", 1)
oms2_setLoggingInterval("tlm", 1e-4)

oms2_initialize("tlm")
oms2_simulate("tlm")

oms2_unloadModel("fmi1")
oms2_unloadModel("fmi2")
oms2_unloadModel("tlm")

vars = {"fmi1.out","fmi2.out"}
for _,var in ipairs(vars) do
  if 1 == oms2_compareSimulationResults("tlm.csv", "../ReferenceFiles/TLM_FMI_Submodels.csv", var, 1e-2, 1e-4) then
    print(var .. " is equal")
  else
    print(var .. " is not equal")
  end
end

-- Result:
-- Starting TLM simulation.
-- Monitoring thread finished.
-- Manager thread finished.
-- fmi1.out is equal
-- fmi2.out is equal
-- info:    Logging information has been saved to "TLM_FMI_Submodels.log"
-- info:    5 warnings
-- info:    0 errors
-- endResult
