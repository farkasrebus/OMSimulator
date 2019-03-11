-- status: correct
-- teardown_command: rm -rf TLM_FMI_3D_FineGrained.log tlm3d_fg.csv tlm3d_fg.run tlm3d_fg_res.mat TLMlogfile.log TLM_FMI_3D_FineGrained_tmp/ fmi1_3d_fg.mat fmi2_3d_fg.mat
-- linux: yes
-- mingw: no
-- mac: no

oms2_setLogFile("TLM_FMI_3D_FineGrained.log")
oms2_setTempDirectory("./TLM_FMI_3D_FineGrained_tmp")

oms2_newFMIModel("fmi1")
oms2_setCommunicationInterval("fmi1", 0.004)
oms2_setResultFile("fmi1", "fmi1_3d_fg.mat")
oms2_addFMU("fmi1", "../FMUs/UpperPendulumFG.fmu", "pendulum")

oms2_newFMIModel("fmi2")
oms2_setCommunicationInterval("fmi2", 0.004)
oms2_setResultFile("fmi2", "fmi2_3d_fg.mat")
oms2_addFMU("fmi2", "../FMUs/LowerPendulumFG.fmu", "pendulum")

oms2_newTLMModel("tlm3d_fg")
oms2_addFMISubModel("tlm3d_fg", "fmi1")
oms2_addFMISubModel("tlm3d_fg", "fmi2")
oms2_addTLMInterface("tlm3d_fg", "fmi1", "P", 3, bidirectional, "Mechanical", finegrained,
                     "pendulum:r[0]", "pendulum:r[1]", "pendulum:r[2]",
                     "pendulum:phi[0]", "pendulum:phi[1]", "pendulum:phi[2]",
                     "pendulum:phi[0]", "pendulum:phi[1]", "pendulum:phi[2]",
                     "pendulum:phi[0]", "pendulum:phi[1]", "pendulum:phi[2]",
                     "pendulum:v[0]", "pendulum:v[1]", "pendulum:v[2]",
                     "pendulum:w[0]", "pendulum:w[1]", "pendulum:w[2]",
                     "pendulum:ci1[0]", "pendulum:ci1[1]", "pendulum:ci1[2]", "pendulum:ci1[3]", "pendulum:ci1[4]", "pendulum:ci1[5]", "pendulum:ci1[6]", "pendulum:ci1[7]", "pendulum:ci1[8]", "pendulum:ci1[9]",
                     "pendulum:ci2[0]", "pendulum:ci2[1]", "pendulum:ci2[2]", "pendulum:ci2[3]", "pendulum:ci2[4]", "pendulum:ci2[5]", "pendulum:ci2[6]", "pendulum:ci2[7]", "pendulum:ci2[8]", "pendulum:ci2[9]",
                     "pendulum:ci3[0]", "pendulum:ci3[1]", "pendulum:ci3[2]", "pendulum:ci3[3]", "pendulum:ci3[4]", "pendulum:ci3[5]", "pendulum:ci3[6]", "pendulum:ci3[7]", "pendulum:ci3[8]", "pendulum:ci3[9]",
                     "pendulum:ci4[0]", "pendulum:ci4[1]", "pendulum:ci4[2]", "pendulum:ci4[3]", "pendulum:ci4[4]", "pendulum:ci4[5]", "pendulum:ci4[6]", "pendulum:ci4[7]", "pendulum:ci4[8]", "pendulum:ci4[9]",
                     "pendulum:ci5[0]", "pendulum:ci5[1]", "pendulum:ci5[2]", "pendulum:ci5[3]", "pendulum:ci5[4]", "pendulum:ci5[5]", "pendulum:ci5[6]", "pendulum:ci5[7]", "pendulum:ci5[8]", "pendulum:ci5[9]",
                     "pendulum:ci6[0]", "pendulum:ci6[1]", "pendulum:ci6[2]", "pendulum:ci6[3]", "pendulum:ci6[4]", "pendulum:ci6[5]", "pendulum:ci6[6]", "pendulum:ci6[7]", "pendulum:ci6[8]", "pendulum:ci6[9]",
                     "pendulum:ti[0]", "pendulum:ti[1]", "pendulum:ti[2]", "pendulum:ti[3]", "pendulum:ti[4]", "pendulum:ti[5]", "pendulum:ti[6]", "pendulum:ti[7]", "pendulum:ti[8]", "pendulum:ti[9]",
										 "pendulum:Zt", "pendulum:Zr");
oms2_addTLMInterface("tlm3d_fg", "fmi2", "P", 3, bidirectional, "Mechanical", finegrained,
                      "pendulum:r[0]", "pendulum:r[1]", "pendulum:r[2]",
                     "pendulum:phi[0]", "pendulum:phi[1]", "pendulum:phi[2]",
                     "pendulum:phi[0]", "pendulum:phi[1]", "pendulum:phi[2]",
                     "pendulum:phi[0]", "pendulum:phi[1]", "pendulum:phi[2]",
                     "pendulum:v[0]", "pendulum:v[1]", "pendulum:v[2]",
                     "pendulum:w[0]", "pendulum:w[1]", "pendulum:w[2]",
                     "pendulum:ci1[0]", "pendulum:ci1[1]", "pendulum:ci1[2]", "pendulum:ci1[3]", "pendulum:ci1[4]", "pendulum:ci1[5]", "pendulum:ci1[6]", "pendulum:ci1[7]", "pendulum:ci1[8]", "pendulum:ci1[9]",
                     "pendulum:ci2[0]", "pendulum:ci2[1]", "pendulum:ci2[2]", "pendulum:ci2[3]", "pendulum:ci2[4]", "pendulum:ci2[5]", "pendulum:ci2[6]", "pendulum:ci2[7]", "pendulum:ci2[8]", "pendulum:ci2[9]",
                     "pendulum:ci3[0]", "pendulum:ci3[1]", "pendulum:ci3[2]", "pendulum:ci3[3]", "pendulum:ci3[4]", "pendulum:ci3[5]", "pendulum:ci3[6]", "pendulum:ci3[7]", "pendulum:ci3[8]", "pendulum:ci3[9]",
                     "pendulum:ci4[0]", "pendulum:ci4[1]", "pendulum:ci4[2]", "pendulum:ci4[3]", "pendulum:ci4[4]", "pendulum:ci4[5]", "pendulum:ci4[6]", "pendulum:ci4[7]", "pendulum:ci4[8]", "pendulum:ci4[9]",
                     "pendulum:ci5[0]", "pendulum:ci5[1]", "pendulum:ci5[2]", "pendulum:ci5[3]", "pendulum:ci5[4]", "pendulum:ci5[5]", "pendulum:ci5[6]", "pendulum:ci5[7]", "pendulum:ci5[8]", "pendulum:ci5[9]",
                     "pendulum:ci6[0]", "pendulum:ci6[1]", "pendulum:ci6[2]", "pendulum:ci6[3]", "pendulum:ci6[4]", "pendulum:ci6[5]", "pendulum:ci6[6]", "pendulum:ci6[7]", "pendulum:ci6[8]", "pendulum:ci6[9]",
                     "pendulum:ti[0]", "pendulum:ti[1]", "pendulum:ti[2]", "pendulum:ti[3]", "pendulum:ti[4]", "pendulum:ti[5]", "pendulum:ti[6]", "pendulum:ti[7]", "pendulum:ti[8]", "pendulum:ti[9]",
										 "pendulum:Zt", "pendulum:Zr");
oms2_addTLMConnection("tlm3d_fg", "fmi1:P", "fmi2:P", 0.001, 0.3, 100000, 0)

oms2_setTLMSocketData("tlm3d_fg","127.0.1.1",13211,13111)

-- oms2_describe("tlm3d_fg")

oms2_setStartTime("tlm3d_fg", 0)
oms2_setStopTime("tlm3d_fg", 1)
oms2_setLoggingInterval("tlm3d_fg", 1e-4)

oms2_initialize("tlm3d_fg")
oms2_simulate("tlm3d_fg")

oms2_unloadModel("tlm3d_fg")

vars = {"fmi1.P.R[cG][cG](1) [m]","fmi1.P.R[cG][cG](2) [m]"}  for _,var in ipairs(vars) do
   if 1 == oms2_compareSimulationResults("tlm3d_fg.csv", "../ReferenceFiles/TLM_FMI_3D_FineGrained.csv", var, 1e-2, 1e-4) then
     print(var .. " is equal")
  else
    print(var .. " is not equal")
  end
end

-- Result:
-- Starting TLM simulation.
-- Monitoring thread finished.
-- Manager thread finished.
-- fmi1.P.R[cG][cG](1) [m] is equal
-- fmi1.P.R[cG][cG](2) [m] is equal
-- info:    Logging information has been saved to "TLM_FMI_3D_FineGrained.log"
-- info:    2 warnings
-- info:    0 errors
-- endResult
