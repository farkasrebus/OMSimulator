-- status: correct
-- teardown_command: rm -rf TLM_FMI_3D.log TLM_FMI_3D_tmp/ tlm3d.csv tlm3d.run tlm3d_res.mat fmi1_3d.mat fmi2_3d.mat
-- linux: yes
-- mingw: no
-- mac: no

oms2_setLogFile("TLM_FMI_3D.log")
oms2_setTempDirectory("./TLM_FMI_3D_tmp")

oms2_newFMIModel("fmi1")
oms2_setCommunicationInterval("fmi1", 0.00001)
oms2_setResultFile("fmi1", "fmi1_3d.mat")
oms2_addFMU("fmi1", "../FMUs/UpperPendulum.fmu", "pendulum")

oms2_newFMIModel("fmi2")
oms2_setCommunicationInterval("fmi2", 0.00001)
oms2_setResultFile("fmi2", "fmi2_3d.mat")
oms2_addFMU("fmi2", "../FMUs/LowerPendulum.fmu", "pendulum")

oms2_newTLMModel("tlm3d")
oms2_addFMISubModel("tlm3d", "fmi1")
oms2_addFMISubModel("tlm3d", "fmi2")
oms2_addTLMInterface("tlm3d", "fmi1", "P", 3, bidirectional, "Mechanical", "pendulum:fmi.r[1]", "pendulum:fmi.r[2]", "pendulum:fmi.r[3]",
                     "pendulum:fmi.A[1,1]", "pendulum:fmi.A[1,2]", "pendulum:fmi.A[1,3]",
                     "pendulum:fmi.A[2,1]", "pendulum:fmi.A[2,2]", "pendulum:fmi.A[2,3]",
                     "pendulum:fmi.A[3,1]", "pendulum:fmi.A[3,2]", "pendulum:fmi.A[3,3]",
                     "pendulum:fmi.v[1]", "pendulum:fmi.v[2]", "pendulum:fmi.v[3]",
                     "pendulum:fmi.w[1]", "pendulum:fmi.w[2]", "pendulum:fmi.w[3]",
                     "pendulum:fmi.f[1]", "pendulum:fmi.f[2]", "pendulum:fmi.f[3]",
                     "pendulum:fmi.t[1]", "pendulum:fmi.t[2]", "pendulum:fmi.t[3]");
oms2_addTLMInterface("tlm3d", "fmi2", "P", 3, bidirectional, "Mechanical", "pendulum:fmi.r[1]", "pendulum:fmi.r[2]", "pendulum:fmi.r[3]",
                     "pendulum:fmi.A[1,1]", "pendulum:fmi.A[1,2]", "pendulum:fmi.A[1,3]",
                     "pendulum:fmi.A[2,1]", "pendulum:fmi.A[2,2]", "pendulum:fmi.A[2,3]",
                     "pendulum:fmi.A[3,1]", "pendulum:fmi.A[3,2]", "pendulum:fmi.A[3,3]",
                     "pendulum:fmi.v[1]", "pendulum:fmi.v[2]", "pendulum:fmi.v[3]",
                     "pendulum:fmi.w[1]", "pendulum:fmi.w[2]", "pendulum:fmi.w[3]",
                     "pendulum:fmi.f[1]", "pendulum:fmi.f[2]", "pendulum:fmi.f[3]",
                     "pendulum:fmi.t[1]", "pendulum:fmi.t[2]", "pendulum:fmi.t[3]");
oms2_addTLMConnection("tlm3d", "fmi1:P", "fmi2:P", 0.00001, 0.2, 10000, 100)

oms2_setTLMSocketData("tlm3d","127.0.1.1",12011,13011)

-- oms2_describe("tlm3d")

oms2_setStartTime("tlm3d", 0)
oms2_setStopTime("tlm3d", 0.1)
oms2_setLoggingInterval("tlm3d", 1e-4)

oms2_initialize("tlm3d")
oms2_simulate("tlm3d")

oms2_unloadModel("tlm3d")

vars = {"fmi1.P.R[cG][cG](1) [m]","fmi1.P.R[cG][cG](2) [m]","fmi1.P.R[cG][cG](3) [m]","fmi2.P.R[cG][cG](1) [m]","fmi2.P.R[cG][cG](2) [m]","fmi2.P.R[cG][cG](3) [m]"}
 for _,var in ipairs(vars) do
   if 1 == oms2_compareSimulationResults("tlm3d.csv", "../ReferenceFiles/TLM_FMI_3D.csv", var, 1e-2, 1e-4) then
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
-- fmi1.P.R[cG][cG](3) [m] is equal
-- fmi2.P.R[cG][cG](1) [m] is equal
-- fmi2.P.R[cG][cG](2) [m] is equal
-- fmi2.P.R[cG][cG](3) [m] is equal
-- info:    Logging information has been saved to "TLM_FMI_3D.log"
-- endResult
