-- status: correct
-- teardown_command: rm -rf tlm1d.log tlm1d-lua/ tlm1d.csv tlm1d.run 
-- linux: yes
-- mingw: no
-- mac: no

oms3_setLogFile("tlm1d.log")
oms3_setTempDirectory("./tlm1d-lua")

oms3_newModel("model");

oms3_addSystem("model.tlm1d", oms_system_tlm);

oms3_addSystem("model.tlm1d.wc1", oms_system_wc);
oms3_setFixedStepSize("model.tlm1d.wc1", 0.001);
oms3_addSubModel("model.tlm1d.wc1.mass", "../FMUs/Mass.fmu");
oms3_addConnector("model.tlm1d.wc1.x",output,oms_signal_type_real);
oms3_addConnector("model.tlm1d.wc1.v",output,oms_signal_type_real);
oms3_addConnector("model.tlm1d.wc1.f",input,oms_signal_type_real);
oms3_addConnection("model.tlm1d.wc1.x","model.tlm1d.wc1.mass.x"); 
oms3_addConnection("model.tlm1d.wc1.v","model.tlm1d.wc1.mass.v"); 
oms3_addConnection("model.tlm1d.wc1.f","model.tlm1d.wc1.mass.f"); 
oms3_addTLMBus("model.tlm1d.wc1.P","mechanical",1);
oms3_addConnectorToTLMBus("model.tlm1d.wc1.P","model.tlm1d.wc1.x", "state");
oms3_addConnectorToTLMBus("model.tlm1d.wc1.P","model.tlm1d.wc1.v", "flow");
oms3_addConnectorToTLMBus("model.tlm1d.wc1.P","model.tlm1d.wc1.f", "effort");

oms3_addSystem("model.tlm1d.wc2", oms_system_wc);
oms3_setFixedStepSize("model.tlm1d.wc2", 0.001);
oms3_addSubModel("model.tlm1d.wc2.mass", "../FMUs/MassSpring.fmu");
oms3_addConnector("model.tlm1d.wc2.x",output,oms_signal_type_real);
oms3_addConnector("model.tlm1d.wc2.v",output,oms_signal_type_real);
oms3_addConnector("model.tlm1d.wc2.f",input,oms_signal_type_real);
oms3_addConnection("model.tlm1d.wc2.x","model.tlm1d.wc2.mass.x"); 
oms3_addConnection("model.tlm1d.wc2.v","model.tlm1d.wc2.mass.v"); 
oms3_addConnection("model.tlm1d.wc2.f","model.tlm1d.wc2.mass.f"); 
oms3_addTLMBus("model.tlm1d.wc2.P","mechanical",1);
oms3_addConnectorToTLMBus("model.tlm1d.wc2.P","model.tlm1d.wc2.x", "state");
oms3_addConnectorToTLMBus("model.tlm1d.wc2.P","model.tlm1d.wc2.v", "flow");
oms3_addConnectorToTLMBus("model.tlm1d.wc2.P","model.tlm1d.wc2.f", "effort");

oms3_addTLMConnection("model.tlm1d.wc1.P","model.tlm1d.wc2.P", 0.001, 0.5, 10, 0);

oms3_setTLMSocketData("model.tlm1d","127.0.1.1",11211,12211)

oms3_setStartTime("model",0);
oms3_setStopTime("model",2);

oms3_instantiate("model");
oms3_initialize("model");
oms3_simulate("model");
oms3_terminate("model");

vars = {"wc1.P.v [m/s]","wc2.P.v [m/s]","wc1.P.F [N]","wc2.P.F [N]"}
for _,var in ipairs(vars) do
  if 1 == oms2_compareSimulationResults("tlm1d.csv", "../ReferenceFiles/tlm1d.csv", var, 1e-2, 1e-4) then
    print(var .. " is equal")
  else
    print(var .. " is not equal")
  end
end

-- Result:
-- Starting TLM simulation.
-- Monitoring thread finished.
-- Manager thread finished.
-- wc1.P.v [m/s] is equal
-- wc2.P.v [m/s] is equal
-- wc1.P.F [N] is equal
-- wc2.P.F [N] is equal
-- info:    Logging information has been saved to "tlm1d.log"
-- endResult
