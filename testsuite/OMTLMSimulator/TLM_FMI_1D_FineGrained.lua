-- status: correct
-- teardown_command: rm -rf TLM_FMI_1D_FineGrained.log TLM_FMI_1D_FineGrained_tmp/ tlm1d_fg.csv tlm1d_fg.run tlm1d_fg_res.mat TLMlogfile.log fmi1_1d_fg.mat fmi2_1d_fg.mat
-- linux: yes
-- mingw: no
-- mac: no

oms2_setLogFile("TLM_FMI_1D_FineGrained.log")
oms2_setTempDirectory("./TLM_FMI_1D_FineGrained_tmp")

oms2_newFMIModel("fmi1")
oms2_setCommunicationInterval("fmi1", 0.001)
oms2_setResultFile("fmi1", "fmi1_1d_fg.mat")
oms2_addFMU("fmi1", "../FMUs/TLM_FineGrained1_1D.fmu", "fmu")
oms2_setRealParameter("fmi1.fmu:M1",0.005);
oms2_setRealParameter("fmi1.fmu:B1",0.2);
oms2_setRealParameter("fmi1.fmu:K1",90);
oms2_setRealParameter("fmi1.fmu:M2",0.005);
oms2_setRealParameter("fmi1.fmu:B2",0.2);
oms2_setRealParameter("fmi1.fmu:K2",141);

oms2_newFMIModel("fmi2")
oms2_setCommunicationInterval("fmi2", 0.001);
oms2_setResultFile("fmi2", "fmi2_1d_fg.mat")
oms2_addFMU("fmi2", "../FMUs/TLM_FineGrained2_1D.fmu", "fmu")
oms2_setRealParameter("fmi2.fmu:t_step1",0.1);
oms2_setRealParameter("fmi2.fmu:F_y1",-100);
oms2_setRealParameter("fmi2.fmu:t_step2",2);
oms2_setRealParameter("fmi2.fmu:F_y2",-300);
oms2_setRealParameter("fmi2.fmu:M",0.005);
oms2_setRealParameter("fmi2.fmu:B",0.2);

oms2_newTLMModel("tlm1d_fg")
oms2_addFMISubModel("tlm1d_fg", "fmi1")
oms2_addFMISubModel("tlm1d_fg", "fmi2")
oms2_addTLMInterface("tlm1d_fg", "fmi1", "P", 1, bidirectional, "Mechanical", finegrained,
                     "fmu:position", "fmu:velocity",
                     "fmu:wave1", "fmu:wave2", "fmu:wave3", "fmu:wave4", "fmu:wave5",
                     "fmu:wave6", "fmu:wave7", "fmu:wave8", "fmu:wave9", "fmu:wave10",
                     "fmu:time1", "fmu:time2", "fmu:time3", "fmu:time4", "fmu:time5",
                     "fmu:time6", "fmu:time7", "fmu:time8", "fmu:time9", "fmu:time10",
                     "fmu:impedance")
oms2_addTLMInterface("tlm1d_fg", "fmi2", "P", 1, bidirectional, "Mechanical", finegrained,
                     "fmu:position", "fmu:velocity",
                     "fmu:wave1", "fmu:wave2", "fmu:wave3", "fmu:wave4", "fmu:wave5",
                     "fmu:wave6", "fmu:wave7", "fmu:wave8", "fmu:wave9", "fmu:wave10",
                     "fmu:time1", "fmu:time2", "fmu:time3", "fmu:time4", "fmu:time5",
                     "fmu:time6", "fmu:time7", "fmu:time8", "fmu:time9", "fmu:time10",
                     "fmu:impedance")
oms2_addTLMConnection("tlm1d_fg", "fmi1:P", "fmi2:P", 1e-3, 0.0, 0.1, 0)
oms2_setTLMSocketData("tlm1d_fg","127.0.1.1",11911,12911)

-- oms2_describe("tlm1d_fg")

oms2_setStartTime("tlm1d_fg", 0)
oms2_setStopTime("tlm1d_fg", 0.5)
oms2_setLoggingInterval("tlm1d_fg", 1e-4)

oms2_initialize("tlm1d_fg")
oms2_simulate("tlm1d_fg")

oms2_unloadModel("tlm1d_fg")

vars = {"fmi1.P.v [m/s]","fmi2.P.v [m/s]","fmi1.P.F [N]","fmi2.P.F [N]"}
for _,var in ipairs(vars) do
  if 1 == oms2_compareSimulationResults("tlm1d_fg.csv", "../ReferenceFiles/TLM_FMI_1D_FineGrained.csv", var, 1e-2, 1e-4) then
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
-- info:    Logging information has been saved to "TLM_FMI_1D_FineGrained.log"
-- info:    2 warnings
-- info:    0 errors
-- endResult
