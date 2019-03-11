-- status: correct
-- teardown_command: rm -rf tlm_ext.run tlm_ext_res.mat tlm_ext.csv TLM_External_Tools.log TLM_External_Tools_tmp/
-- linux: yes
-- mingw: no
-- mac: no

oms2_setLogFile("TLM_External_Tools.log")
oms2_newTLMModel("tlm_ext")
oms2_setTempDirectory("./TLM_External_Tools_tmp")

oms2_addExternalModel("tlm_ext", "adder", "../FMUs/adder.fmu", "./StartTLMFmiWrapper")
oms2_addExternalModel("tlm_ext", "source1", "../FMUs/source.fmu", "./StartTLMFmiWrapper")
oms2_addExternalModel("tlm_ext", "source2", "../FMUs/source.fmu", "./StartTLMFmiWrapper")
oms2_addExternalModel("tlm_ext", "gain", "../FMUs/gain.fmu", "./StartTLMFmiWrapper")

oms2_addTLMInterface("tlm_ext", "adder",  "x1", 1, input,  "Signal")
oms2_addTLMInterface("tlm_ext", "adder",  "x2", 1, input,  "Signal")
oms2_addTLMInterface("tlm_ext", "adder",  "y",  1, output, "Signal")
oms2_addTLMInterface("tlm_ext", "source1","y",  1, output, "Signal")
oms2_addTLMInterface("tlm_ext", "source2","y",  1, output, "Signal")
oms2_addTLMInterface("tlm_ext", "gain",   "y",  1, input,  "Signal")
oms2_addTLMInterface("tlm_ext", "gain",   "u",  1, output, "Signal")

oms2_addTLMConnection("tlm_ext", "adder:x1", "source2:y", 0,0,0,0)
oms2_addTLMConnection("tlm_ext", "adder:x2", "source1:y", 0,0,0,0)
oms2_addTLMConnection("tlm_ext", "gain:y", "adder:y",     0,0,0,0)

oms2_setTLMSocketData("tlm_ext","127.0.1.1",11511,12511)

-- oms2_describe("tlm_ext")

oms2_setStartTime("tlm_ext", 0.5)
oms2_setStopTime("tlm_ext", 4)
oms2_setLoggingInterval("tlm_ext", 1e-4)

oms2_initialize("tlm_ext")
oms2_simulate("tlm_ext")

oms2_unloadModel("tlm_ext")

vars = {"adder.y","source1.y","source2.y"}
for _,var in ipairs(vars) do
  if 1 == oms2_compareSimulationResults("tlm_ext.csv", "../ReferenceFiles/TLM_External_Tools.csv", var, 1e-2, 1e-4) then
    print(var .. " is equal")
  else
    print(var .. " is not equal")
  end
end

-- Result:
-- Starting FMIWrapper. Debug output will be written to "TLMlogfile.log".
-- Starting FMIWrapper. Debug output will be written to "TLMlogfile.log".
-- Starting FMIWrapper. Debug output will be written to "TLMlogfile.log".
-- Starting FMIWrapper. Debug output will be written to "TLMlogfile.log".
-- Starting TLM simulation.
-- Monitoring thread finished.
-- Manager thread finished.
-- adder.y is equal
-- source1.y is equal
-- source2.y is equal
-- info:    Logging information has been saved to "TLM_External_Tools.log"
-- endResult
