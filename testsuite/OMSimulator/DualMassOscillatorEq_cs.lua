-- status: correct
-- teardown_command: rm DualMassOscillatorEq_cs.log DualMassOscillatorEq_cs.mat

oms2_setLogFile("DualMassOscillatorEq_cs.log")
oms2_setTempDirectory("./DualMassOscillatorEq_me_tmp")
oms2_newFMIModel("DualMassOscillatorEq")

-- instantiate FMUs
oms2_addFMU("DualMassOscillatorEq", "../FMUs/DualMassOscillator.System1Eq_cs.fmu", "System1")
oms2_addFMU("DualMassOscillatorEq", "../FMUs/DualMassOscillator.System2Eq_cs.fmu", "System2")

-- add connections
oms2_addConnection("DualMassOscillatorEq", "System1:in_F", "System2:out_F")
oms2_addConnection("DualMassOscillatorEq", "System1:out_s1", "System2:in_s1")
oms2_addConnection("DualMassOscillatorEq", "System1:out_v1", "System2:in_v1")

oms2_setResultFile("DualMassOscillatorEq", "DualMassOscillatorEq_cs.mat")

oms2_setStopTime("DualMassOscillatorEq", 0.1)
oms2_setCommunicationInterval("DualMassOscillatorEq", 1e-5)

oms2_initialize("DualMassOscillatorEq")
oms2_simulate("DualMassOscillatorEq")

tcur = oms2_getCurrentTime("DualMassOscillatorEq")
vars = {"DualMassOscillatorEq.System1:s1", "DualMassOscillatorEq.System2:s2"}
for _,var in ipairs(vars) do
  print(var .. " at " .. tcur .. ": " .. oms2_getReal(var))
end

oms2_unloadModel("DualMassOscillatorEq")

-- Result:
-- DualMassOscillatorEq.System1:s1 at 0.1: -0.45012153166449
-- DualMassOscillatorEq.System2:s2 at 0.1: -0.30237070431675
-- info:    Logging information has been saved to "DualMassOscillatorEq_cs.log"
-- info:    2 warnings
-- info:    0 errors
-- endResult
