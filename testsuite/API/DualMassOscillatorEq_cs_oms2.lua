-- status: correct
-- teardown_command: rm -rf DualMassOscillatorEq_cs_oms2.log DualMassOscillatorEq_cs_oms2_tmp/ DualMassOscillatorEq_cs_oms2.mat DualMassInit.dot DualMassSim.dot
-- linux: yes

oms2_setLogFile("DualMassOscillatorEq_cs_oms2.log")

status = oms2_setTempDirectory("./DualMassOscillatorEq_cs_oms2_tmp")

status = oms2_newFMIModel("DualMass")

-- add FMUs
status = oms2_addFMU("DualMass", "../FMUs/DualMassOscillator.System1Eq_cs.fmu", "System1")
status = oms2_addFMU("DualMass", "../FMUs/DualMassOscillator.System2Eq_cs.fmu", "System2")

-- add solver
oms2_addSolver("DualMass", "solver1", "internal")

-- connect solver
oms2_addConnection("DualMass", "System1", "solver1")
oms2_deleteConnection("DualMass", "System1", "solver1")
oms2_addConnection("DualMass", "System1", "solver1")
oms2_addConnection("DualMass", "System2", "solver1")

-- add connections
status = oms2_addConnection("DualMass", "System1:in_F", "System2:out_F")
status = oms2_addConnection("DualMass", "System1:out_s1", "System2:in_s1")
status = oms2_addConnection("DualMass", "System1:out_v1", "System2:in_v1")

status = oms2_setResultFile("DualMass", "DualMassOscillatorEq_cs_oms2.mat")

stopTime = 0.1
status = oms2_setStopTime("DualMass", stopTime)
status = oms2_setCommunicationInterval("DualMass", 1e-5)

-- Master algorithm variants:
-- standard : The single-task standard
-- pctpl : task pool approach using CTPL library (https://github.com/vit-vit/CTPL)
-- pmrchannela : Channel based approach using atomic variables for synchronization
-- pmrchannelcv : Channel based approach using condition variables for synchronization
-- pmrchannelm : Channel based approach using mutexes for synchronization
status = oms2_setMasterAlgorithm("DualMass", "pctpl")
-- Experimental idea for multi-rate execution. Has only an effect for the channel based master algorithms!
status = experimental_setActivationRatio("DualMass.System1", 1)
status = experimental_setActivationRatio("DualMass.System2", 1)

status = oms2_initialize("DualMass")

oms2_exportDependencyGraphs("DualMass", "DualMassInit.dot", "DualMassSim.dot")

status = oms2_simulate("DualMass")

vars = {"DualMass.System1:s1", "DualMass.System2:s2"}
for _,var in ipairs(vars) do
  print(var .. " at " .. stopTime .. ": " .. oms2_getReal(var))
end

oms2_unloadModel("DualMass")

-- Result:
-- DualMass.System1:s1 at 0.1: -0.45012153166449
-- DualMass.System2:s2 at 0.1: -0.30237070431675
-- info:    Logging information has been saved to "DualMassOscillatorEq_cs_oms2.log"
-- endResult
