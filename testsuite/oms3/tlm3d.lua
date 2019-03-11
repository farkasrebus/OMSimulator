-- status: correct
-- teardown_command: rm -rf tlm3d.log tlm3d-lua/ tlm3d.csv tlm3d.run 
-- linux: yes
-- mingw: no
-- mac: no

oms3_setLogFile("tlm3d.log")
oms3_setTempDirectory("./tlm3d-lua")

oms3_newModel("model");

oms3_addSystem("model.tlm3d", oms_system_tlm);

oms3_addSystem("model.tlm3d.wc1", oms_system_wc);
oms3_setFixedStepSize("model.tlm3d.wc1", 0.00001);
oms3_addSubModel("model.tlm3d.wc1.pendulum", "../FMUs/UpperPendulum.fmu");
oms3_addConnector("model.tlm3d.wc1.x1",output,oms_signal_type_real);
oms3_addConnector("model.tlm3d.wc1.x2",output,oms_signal_type_real);
oms3_addConnector("model.tlm3d.wc1.x3",output,oms_signal_type_real);
oms3_addConnector("model.tlm3d.wc1.A11",output,oms_signal_type_real);
oms3_addConnector("model.tlm3d.wc1.A12",output,oms_signal_type_real);
oms3_addConnector("model.tlm3d.wc1.A13",output,oms_signal_type_real);
oms3_addConnector("model.tlm3d.wc1.A21",output,oms_signal_type_real);
oms3_addConnector("model.tlm3d.wc1.A22",output,oms_signal_type_real);
oms3_addConnector("model.tlm3d.wc1.A23",output,oms_signal_type_real);
oms3_addConnector("model.tlm3d.wc1.A31",output,oms_signal_type_real);
oms3_addConnector("model.tlm3d.wc1.A32",output,oms_signal_type_real);
oms3_addConnector("model.tlm3d.wc1.A33",output,oms_signal_type_real);
oms3_addConnector("model.tlm3d.wc1.v1",output,oms_signal_type_real);
oms3_addConnector("model.tlm3d.wc1.v2",output,oms_signal_type_real);
oms3_addConnector("model.tlm3d.wc1.v3",output,oms_signal_type_real);
oms3_addConnector("model.tlm3d.wc1.w1",output,oms_signal_type_real);
oms3_addConnector("model.tlm3d.wc1.w2",output,oms_signal_type_real);
oms3_addConnector("model.tlm3d.wc1.w3",output,oms_signal_type_real);
oms3_addConnector("model.tlm3d.wc1.f1",input,oms_signal_type_real);
oms3_addConnector("model.tlm3d.wc1.f2",input,oms_signal_type_real);
oms3_addConnector("model.tlm3d.wc1.f3",input,oms_signal_type_real);
oms3_addConnector("model.tlm3d.wc1.t1",input,oms_signal_type_real);
oms3_addConnector("model.tlm3d.wc1.t2",input,oms_signal_type_real);
oms3_addConnector("model.tlm3d.wc1.t3",input,oms_signal_type_real);
oms3_addConnection("model.tlm3d.wc1.x1","model.tlm3d.wc1.pendulum.r[1]"); 
oms3_addConnection("model.tlm3d.wc1.x2","model.tlm3d.wc1.pendulum.r[2]"); 
oms3_addConnection("model.tlm3d.wc1.x3","model.tlm3d.wc1.pendulum.r[3]"); 
oms3_addConnection("model.tlm3d.wc1.A11","model.tlm3d.wc1.pendulum.A[1,1]"); 
oms3_addConnection("model.tlm3d.wc1.A12","model.tlm3d.wc1.pendulum.A[1,2]"); 
oms3_addConnection("model.tlm3d.wc1.A13","model.tlm3d.wc1.pendulum.A[1,3]"); 
oms3_addConnection("model.tlm3d.wc1.A21","model.tlm3d.wc1.pendulum.A[2,1]"); 
oms3_addConnection("model.tlm3d.wc1.A22","model.tlm3d.wc1.pendulum.A[2,2]"); 
oms3_addConnection("model.tlm3d.wc1.A23","model.tlm3d.wc1.pendulum.A[2,3]"); 
oms3_addConnection("model.tlm3d.wc1.A31","model.tlm3d.wc1.pendulum.A[3,1]"); 
oms3_addConnection("model.tlm3d.wc1.A32","model.tlm3d.wc1.pendulum.A[3,2]"); 
oms3_addConnection("model.tlm3d.wc1.A33","model.tlm3d.wc1.pendulum.A[3,3]");
oms3_addConnection("model.tlm3d.wc1.v1","model.tlm3d.wc1.pendulum.v[1]"); 
oms3_addConnection("model.tlm3d.wc1.v2","model.tlm3d.wc1.pendulum.v[2]");
oms3_addConnection("model.tlm3d.wc1.v3","model.tlm3d.wc1.pendulum.v[3]"); 
oms3_addConnection("model.tlm3d.wc1.w1","model.tlm3d.wc1.pendulum.w[1]"); 
oms3_addConnection("model.tlm3d.wc1.w2","model.tlm3d.wc1.pendulum.w[2]"); 
oms3_addConnection("model.tlm3d.wc1.w3","model.tlm3d.wc1.pendulum.w[3]"); 
oms3_addConnection("model.tlm3d.wc1.f1","model.tlm3d.wc1.pendulum.f[1]"); 
oms3_addConnection("model.tlm3d.wc1.f2","model.tlm3d.wc1.pendulum.f[2]"); 
oms3_addConnection("model.tlm3d.wc1.f3","model.tlm3d.wc1.pendulum.f[3]"); 
oms3_addConnection("model.tlm3d.wc1.t1","model.tlm3d.wc1.pendulum.t[1]"); 
oms3_addConnection("model.tlm3d.wc1.t2","model.tlm3d.wc1.pendulum.t[2]"); 
oms3_addConnection("model.tlm3d.wc1.t3","model.tlm3d.wc1.pendulum.t[3]"); 
oms3_addTLMBus("model.tlm3d.wc1.P","mechanical",3);
oms3_addConnectorToTLMBus("model.tlm3d.wc1.P","model.tlm3d.wc1.x1", "state1");
oms3_addConnectorToTLMBus("model.tlm3d.wc1.P","model.tlm3d.wc1.x2", "state2");
oms3_addConnectorToTLMBus("model.tlm3d.wc1.P","model.tlm3d.wc1.x3", "state3");
oms3_addConnectorToTLMBus("model.tlm3d.wc1.P","model.tlm3d.wc1.A11", "A11");
oms3_addConnectorToTLMBus("model.tlm3d.wc1.P","model.tlm3d.wc1.A12", "A12");
oms3_addConnectorToTLMBus("model.tlm3d.wc1.P","model.tlm3d.wc1.A13", "A13");
oms3_addConnectorToTLMBus("model.tlm3d.wc1.P","model.tlm3d.wc1.A21", "A21");
oms3_addConnectorToTLMBus("model.tlm3d.wc1.P","model.tlm3d.wc1.A22", "A22");
oms3_addConnectorToTLMBus("model.tlm3d.wc1.P","model.tlm3d.wc1.A23", "A23");
oms3_addConnectorToTLMBus("model.tlm3d.wc1.P","model.tlm3d.wc1.A31", "A31");
oms3_addConnectorToTLMBus("model.tlm3d.wc1.P","model.tlm3d.wc1.A32", "A32");
oms3_addConnectorToTLMBus("model.tlm3d.wc1.P","model.tlm3d.wc1.A33", "A33");
oms3_addConnectorToTLMBus("model.tlm3d.wc1.P","model.tlm3d.wc1.v1", "flow1");
oms3_addConnectorToTLMBus("model.tlm3d.wc1.P","model.tlm3d.wc1.v2", "flow2");
oms3_addConnectorToTLMBus("model.tlm3d.wc1.P","model.tlm3d.wc1.v3", "flow3");
oms3_addConnectorToTLMBus("model.tlm3d.wc1.P","model.tlm3d.wc1.w1", "flow4");
oms3_addConnectorToTLMBus("model.tlm3d.wc1.P","model.tlm3d.wc1.w2", "flow5");
oms3_addConnectorToTLMBus("model.tlm3d.wc1.P","model.tlm3d.wc1.w3", "flow6");
oms3_addConnectorToTLMBus("model.tlm3d.wc1.P","model.tlm3d.wc1.f1", "effort1");
oms3_addConnectorToTLMBus("model.tlm3d.wc1.P","model.tlm3d.wc1.f2", "effort2");
oms3_addConnectorToTLMBus("model.tlm3d.wc1.P","model.tlm3d.wc1.f3", "effort3");
oms3_addConnectorToTLMBus("model.tlm3d.wc1.P","model.tlm3d.wc1.t1", "effort4");
oms3_addConnectorToTLMBus("model.tlm3d.wc1.P","model.tlm3d.wc1.t2", "effort5");
oms3_addConnectorToTLMBus("model.tlm3d.wc1.P","model.tlm3d.wc1.t3", "effort6");


oms3_addSystem("model.tlm3d.wc2", oms_system_wc);
oms3_setFixedStepSize("model.tlm3d.wc2", 0.00001);
oms3_addSubModel("model.tlm3d.wc2.pendulum", "../FMUs/LowerPendulum.fmu");
oms3_addConnector("model.tlm3d.wc2.x1",output,oms_signal_type_real);
oms3_addConnector("model.tlm3d.wc2.x2",output,oms_signal_type_real);
oms3_addConnector("model.tlm3d.wc2.x3",output,oms_signal_type_real);
oms3_addConnector("model.tlm3d.wc2.A11",output,oms_signal_type_real);
oms3_addConnector("model.tlm3d.wc2.A12",output,oms_signal_type_real);
oms3_addConnector("model.tlm3d.wc2.A13",output,oms_signal_type_real);
oms3_addConnector("model.tlm3d.wc2.A21",output,oms_signal_type_real);
oms3_addConnector("model.tlm3d.wc2.A22",output,oms_signal_type_real);
oms3_addConnector("model.tlm3d.wc2.A23",output,oms_signal_type_real);
oms3_addConnector("model.tlm3d.wc2.A31",output,oms_signal_type_real);
oms3_addConnector("model.tlm3d.wc2.A32",output,oms_signal_type_real);
oms3_addConnector("model.tlm3d.wc2.A33",output,oms_signal_type_real);
oms3_addConnector("model.tlm3d.wc2.v1",output,oms_signal_type_real);
oms3_addConnector("model.tlm3d.wc2.v2",output,oms_signal_type_real);
oms3_addConnector("model.tlm3d.wc2.v3",output,oms_signal_type_real);
oms3_addConnector("model.tlm3d.wc2.w1",output,oms_signal_type_real);
oms3_addConnector("model.tlm3d.wc2.w2",output,oms_signal_type_real);
oms3_addConnector("model.tlm3d.wc2.w3",output,oms_signal_type_real);
oms3_addConnector("model.tlm3d.wc2.f1",input,oms_signal_type_real);
oms3_addConnector("model.tlm3d.wc2.f2",input,oms_signal_type_real);
oms3_addConnector("model.tlm3d.wc2.f3",input,oms_signal_type_real);
oms3_addConnector("model.tlm3d.wc2.t1",input,oms_signal_type_real);
oms3_addConnector("model.tlm3d.wc2.t2",input,oms_signal_type_real);
oms3_addConnector("model.tlm3d.wc2.t3",input,oms_signal_type_real);
oms3_addConnection("model.tlm3d.wc2.x1","model.tlm3d.wc2.pendulum.r[1]"); 
oms3_addConnection("model.tlm3d.wc2.x2","model.tlm3d.wc2.pendulum.r[2]"); 
oms3_addConnection("model.tlm3d.wc2.x3","model.tlm3d.wc2.pendulum.r[3]"); 
oms3_addConnection("model.tlm3d.wc2.A11","model.tlm3d.wc2.pendulum.A[1,1]"); 
oms3_addConnection("model.tlm3d.wc2.A12","model.tlm3d.wc2.pendulum.A[1,2]"); 
oms3_addConnection("model.tlm3d.wc2.A13","model.tlm3d.wc2.pendulum.A[1,3]"); 
oms3_addConnection("model.tlm3d.wc2.A21","model.tlm3d.wc2.pendulum.A[2,1]"); 
oms3_addConnection("model.tlm3d.wc2.A22","model.tlm3d.wc2.pendulum.A[2,2]"); 
oms3_addConnection("model.tlm3d.wc2.A23","model.tlm3d.wc2.pendulum.A[2,3]"); 
oms3_addConnection("model.tlm3d.wc2.A31","model.tlm3d.wc2.pendulum.A[3,1]"); 
oms3_addConnection("model.tlm3d.wc2.A32","model.tlm3d.wc2.pendulum.A[3,2]"); 
oms3_addConnection("model.tlm3d.wc2.A33","model.tlm3d.wc2.pendulum.A[3,3]");
oms3_addConnection("model.tlm3d.wc2.v1","model.tlm3d.wc2.pendulum.v[1]"); 
oms3_addConnection("model.tlm3d.wc2.v2","model.tlm3d.wc2.pendulum.v[2]");
oms3_addConnection("model.tlm3d.wc2.v3","model.tlm3d.wc2.pendulum.v[3]"); 
oms3_addConnection("model.tlm3d.wc2.w1","model.tlm3d.wc2.pendulum.w[1]"); 
oms3_addConnection("model.tlm3d.wc2.w2","model.tlm3d.wc2.pendulum.w[2]"); 
oms3_addConnection("model.tlm3d.wc2.w3","model.tlm3d.wc2.pendulum.w[3]"); 
oms3_addConnection("model.tlm3d.wc2.f1","model.tlm3d.wc2.pendulum.f[1]"); 
oms3_addConnection("model.tlm3d.wc2.f2","model.tlm3d.wc2.pendulum.f[2]"); 
oms3_addConnection("model.tlm3d.wc2.f3","model.tlm3d.wc2.pendulum.f[3]"); 
oms3_addConnection("model.tlm3d.wc2.t1","model.tlm3d.wc2.pendulum.t[1]"); 
oms3_addConnection("model.tlm3d.wc2.t2","model.tlm3d.wc2.pendulum.t[2]"); 
oms3_addConnection("model.tlm3d.wc2.t3","model.tlm3d.wc2.pendulum.t[3]"); 
oms3_addTLMBus("model.tlm3d.wc2.P","mechanical",3);
oms3_addConnectorToTLMBus("model.tlm3d.wc2.P","model.tlm3d.wc2.x1", "state1");
oms3_addConnectorToTLMBus("model.tlm3d.wc2.P","model.tlm3d.wc2.x2", "state2");
oms3_addConnectorToTLMBus("model.tlm3d.wc2.P","model.tlm3d.wc2.x3", "state3");
oms3_addConnectorToTLMBus("model.tlm3d.wc2.P","model.tlm3d.wc2.A11", "A11");
oms3_addConnectorToTLMBus("model.tlm3d.wc2.P","model.tlm3d.wc2.A12", "A12");
oms3_addConnectorToTLMBus("model.tlm3d.wc2.P","model.tlm3d.wc2.A13", "A13");
oms3_addConnectorToTLMBus("model.tlm3d.wc2.P","model.tlm3d.wc2.A21", "A21");
oms3_addConnectorToTLMBus("model.tlm3d.wc2.P","model.tlm3d.wc2.A22", "A22");
oms3_addConnectorToTLMBus("model.tlm3d.wc2.P","model.tlm3d.wc2.A23", "A23");
oms3_addConnectorToTLMBus("model.tlm3d.wc2.P","model.tlm3d.wc2.A31", "A31");
oms3_addConnectorToTLMBus("model.tlm3d.wc2.P","model.tlm3d.wc2.A32", "A32");
oms3_addConnectorToTLMBus("model.tlm3d.wc2.P","model.tlm3d.wc2.A33", "A33");
oms3_addConnectorToTLMBus("model.tlm3d.wc2.P","model.tlm3d.wc2.v1", "flow1");
oms3_addConnectorToTLMBus("model.tlm3d.wc2.P","model.tlm3d.wc2.v2", "flow2");
oms3_addConnectorToTLMBus("model.tlm3d.wc2.P","model.tlm3d.wc2.v3", "flow3");
oms3_addConnectorToTLMBus("model.tlm3d.wc2.P","model.tlm3d.wc2.w1", "flow4");
oms3_addConnectorToTLMBus("model.tlm3d.wc2.P","model.tlm3d.wc2.w2", "flow5");
oms3_addConnectorToTLMBus("model.tlm3d.wc2.P","model.tlm3d.wc2.w3", "flow6");
oms3_addConnectorToTLMBus("model.tlm3d.wc2.P","model.tlm3d.wc2.f1", "effort1");
oms3_addConnectorToTLMBus("model.tlm3d.wc2.P","model.tlm3d.wc2.f2", "effort2");
oms3_addConnectorToTLMBus("model.tlm3d.wc2.P","model.tlm3d.wc2.f3", "effort3");
oms3_addConnectorToTLMBus("model.tlm3d.wc2.P","model.tlm3d.wc2.t1", "effort4");
oms3_addConnectorToTLMBus("model.tlm3d.wc2.P","model.tlm3d.wc2.t2", "effort5");
oms3_addConnectorToTLMBus("model.tlm3d.wc2.P","model.tlm3d.wc2.t3", "effort6");

oms3_addTLMConnection("model.tlm3d.wc1.P","model.tlm3d.wc2.P", 0.00001, 0.9, 10000, 100);

oms3_setTLMSocketData("model.tlm3d","127.0.1.1",11127,12127)

oms3_setStartTime("model",0);
oms3_setStopTime("model",0.1);

oms3_instantiate("model");
oms3_initialize("model");
oms3_simulate("model");
oms3_terminate("model");

vars = {"wc1.P.v [m/s]","wc2.P.v [m/s]","wc1.P.F [N]","wc2.P.F [N]"}
vars = {"wc1.P.R[cG][cG](1) [m]","wc1.P.R[cG][cG](2) [m]","wc1.P.R[cG][cG](3) [m]","wc2.P.R[cG][cG](1) [m]","wc2.P.R[cG][cG](2) [m]","wc2.P.R[cG][cG](3) [m]"}
for _,var in ipairs(vars) do
  if 1 == oms2_compareSimulationResults("tlm3d.csv", "../ReferenceFiles/tlm3d.csv", var, 1e-2, 1e-4) then
    print(var .. " is equal")
  else
    print(var .. " is not equal")
  end
end


-- Result:
-- Starting TLM simulation.
-- Monitoring thread finished.
-- Manager thread finished.
-- wc1.P.R[cG][cG](1) [m] is equal
-- wc1.P.R[cG][cG](2) [m] is equal
-- wc1.P.R[cG][cG](3) [m] is equal
-- wc2.P.R[cG][cG](1) [m] is equal
-- wc2.P.R[cG][cG](2) [m] is equal
-- wc2.P.R[cG][cG](3) [m] is equal
-- info:    Logging information has been saved to "tlm3d.log"
-- endResult
