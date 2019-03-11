-- status: correct
-- teardown_command: rm -rf tlm1dfg.log tlm1dfg-lua/ tlm1dfg.csv tlm1dfg.run 
-- linux: yes
-- mingw: no
-- mac: no

oms3_setLogFile("tlm1dfg.log")
oms3_setTempDirectory("./tlm1dfg-lua")

oms3_newModel("model");

oms3_addSystem("model.tlm1dfg", oms_system_tlm);

oms3_addSystem("model.tlm1dfg.wc1", oms_system_wc);
oms3_setFixedStepSize("model.tlm1dfg.wc1", 0.001);
oms3_addSubModel("model.tlm1dfg.wc1.fmu", "../FMUs/TLM_FineGrained1_1D.fmu");
oms3_addTLMBus("model.tlm1dfg.wc1.fmu.P","mechanical",1,finegrained);
oms3_addConnectorToTLMBus("model.tlm1dfg.wc1.fmu.P","model.tlm1dfg.wc1.fmu.position", "state");
oms3_addConnectorToTLMBus("model.tlm1dfg.wc1.fmu.P","model.tlm1dfg.wc1.fmu.velocity", "flow");
oms3_addConnectorToTLMBus("model.tlm1dfg.wc1.fmu.P","model.tlm1dfg.wc1.fmu.wave1", "wave1");
oms3_addConnectorToTLMBus("model.tlm1dfg.wc1.fmu.P","model.tlm1dfg.wc1.fmu.wave2", "wave2");
oms3_addConnectorToTLMBus("model.tlm1dfg.wc1.fmu.P","model.tlm1dfg.wc1.fmu.wave3", "wave3");
oms3_addConnectorToTLMBus("model.tlm1dfg.wc1.fmu.P","model.tlm1dfg.wc1.fmu.wave4", "wave4");
oms3_addConnectorToTLMBus("model.tlm1dfg.wc1.fmu.P","model.tlm1dfg.wc1.fmu.wave5", "wave5");
oms3_addConnectorToTLMBus("model.tlm1dfg.wc1.fmu.P","model.tlm1dfg.wc1.fmu.wave6", "wave6");
oms3_addConnectorToTLMBus("model.tlm1dfg.wc1.fmu.P","model.tlm1dfg.wc1.fmu.wave7", "wave7");
oms3_addConnectorToTLMBus("model.tlm1dfg.wc1.fmu.P","model.tlm1dfg.wc1.fmu.wave8", "wave8");
oms3_addConnectorToTLMBus("model.tlm1dfg.wc1.fmu.P","model.tlm1dfg.wc1.fmu.wave9", "wave9");
oms3_addConnectorToTLMBus("model.tlm1dfg.wc1.fmu.P","model.tlm1dfg.wc1.fmu.wave10", "wave10");
oms3_addConnectorToTLMBus("model.tlm1dfg.wc1.fmu.P","model.tlm1dfg.wc1.fmu.time1", "time1");
oms3_addConnectorToTLMBus("model.tlm1dfg.wc1.fmu.P","model.tlm1dfg.wc1.fmu.time2", "time2");
oms3_addConnectorToTLMBus("model.tlm1dfg.wc1.fmu.P","model.tlm1dfg.wc1.fmu.time3", "time3");
oms3_addConnectorToTLMBus("model.tlm1dfg.wc1.fmu.P","model.tlm1dfg.wc1.fmu.time4", "time4");
oms3_addConnectorToTLMBus("model.tlm1dfg.wc1.fmu.P","model.tlm1dfg.wc1.fmu.time5", "time5");
oms3_addConnectorToTLMBus("model.tlm1dfg.wc1.fmu.P","model.tlm1dfg.wc1.fmu.time6", "time6");
oms3_addConnectorToTLMBus("model.tlm1dfg.wc1.fmu.P","model.tlm1dfg.wc1.fmu.time7", "time7");
oms3_addConnectorToTLMBus("model.tlm1dfg.wc1.fmu.P","model.tlm1dfg.wc1.fmu.time8", "time8");
oms3_addConnectorToTLMBus("model.tlm1dfg.wc1.fmu.P","model.tlm1dfg.wc1.fmu.time9", "time9");
oms3_addConnectorToTLMBus("model.tlm1dfg.wc1.fmu.P","model.tlm1dfg.wc1.fmu.time10", "time10");
oms3_addConnectorToTLMBus("model.tlm1dfg.wc1.fmu.P","model.tlm1dfg.wc1.fmu.impedance", "impedance");
oms3_addTLMBus("model.tlm1dfg.wc1.P","mechanical",1,finegrained);
oms3_addConnection("model.tlm1dfg.wc1.fmu.P","model.tlm1dfg.wc1.P"); 

oms3_addSystem("model.tlm1dfg.wc2", oms_system_wc);
oms3_setFixedStepSize("model.tlm1dfg.wc2", 0.001);
oms3_addSubModel("model.tlm1dfg.wc2.fmu", "../FMUs/TLM_FineGrained2_1D.fmu");
oms3_addTLMBus("model.tlm1dfg.wc2.fmu.P","mechanical",1,finegrained);
oms3_addConnectorToTLMBus("model.tlm1dfg.wc2.fmu.P","model.tlm1dfg.wc2.fmu.position", "state");
oms3_addConnectorToTLMBus("model.tlm1dfg.wc2.fmu.P","model.tlm1dfg.wc2.fmu.velocity", "flow");
oms3_addConnectorToTLMBus("model.tlm1dfg.wc2.fmu.P","model.tlm1dfg.wc2.fmu.wave1", "wave1");
oms3_addConnectorToTLMBus("model.tlm1dfg.wc2.fmu.P","model.tlm1dfg.wc2.fmu.wave2", "wave2");
oms3_addConnectorToTLMBus("model.tlm1dfg.wc2.fmu.P","model.tlm1dfg.wc2.fmu.wave3", "wave3");
oms3_addConnectorToTLMBus("model.tlm1dfg.wc2.fmu.P","model.tlm1dfg.wc2.fmu.wave4", "wave4");
oms3_addConnectorToTLMBus("model.tlm1dfg.wc2.fmu.P","model.tlm1dfg.wc2.fmu.wave5", "wave5");
oms3_addConnectorToTLMBus("model.tlm1dfg.wc2.fmu.P","model.tlm1dfg.wc2.fmu.wave6", "wave6");
oms3_addConnectorToTLMBus("model.tlm1dfg.wc2.fmu.P","model.tlm1dfg.wc2.fmu.wave7", "wave7");
oms3_addConnectorToTLMBus("model.tlm1dfg.wc2.fmu.P","model.tlm1dfg.wc2.fmu.wave8", "wave8");
oms3_addConnectorToTLMBus("model.tlm1dfg.wc2.fmu.P","model.tlm1dfg.wc2.fmu.wave9", "wave9");
oms3_addConnectorToTLMBus("model.tlm1dfg.wc2.fmu.P","model.tlm1dfg.wc2.fmu.wave10", "wave10");
oms3_addConnectorToTLMBus("model.tlm1dfg.wc2.fmu.P","model.tlm1dfg.wc2.fmu.time1", "time1");
oms3_addConnectorToTLMBus("model.tlm1dfg.wc2.fmu.P","model.tlm1dfg.wc2.fmu.time2", "time2");
oms3_addConnectorToTLMBus("model.tlm1dfg.wc2.fmu.P","model.tlm1dfg.wc2.fmu.time3", "time3");
oms3_addConnectorToTLMBus("model.tlm1dfg.wc2.fmu.P","model.tlm1dfg.wc2.fmu.time4", "time4");
oms3_addConnectorToTLMBus("model.tlm1dfg.wc2.fmu.P","model.tlm1dfg.wc2.fmu.time5", "time5");
oms3_addConnectorToTLMBus("model.tlm1dfg.wc2.fmu.P","model.tlm1dfg.wc2.fmu.time6", "time6");
oms3_addConnectorToTLMBus("model.tlm1dfg.wc2.fmu.P","model.tlm1dfg.wc2.fmu.time7", "time7");
oms3_addConnectorToTLMBus("model.tlm1dfg.wc2.fmu.P","model.tlm1dfg.wc2.fmu.time8", "time8");
oms3_addConnectorToTLMBus("model.tlm1dfg.wc2.fmu.P","model.tlm1dfg.wc2.fmu.time9", "time9");
oms3_addConnectorToTLMBus("model.tlm1dfg.wc2.fmu.P","model.tlm1dfg.wc2.fmu.time10", "time10");
oms3_addConnectorToTLMBus("model.tlm1dfg.wc2.fmu.P","model.tlm1dfg.wc2.fmu.impedance", "impedance");
oms3_addTLMBus("model.tlm1dfg.wc2.P","mechanical",1,finegrained);
oms3_addConnection("model.tlm1dfg.wc2.fmu.P","model.tlm1dfg.wc2.P"); 

oms3_addTLMConnection("model.tlm1dfg.wc1.P","model.tlm1dfg.wc2.P", 0.001, 0.2, 0.1, 0);

oms3_setTLMSocketData("model.tlm1dfg","127.0.1.1",11311,12311)

oms3_setStartTime("model",0);
oms3_setStopTime("model",0.5);

oms3_instantiate("model");

oms3_setReal("model.tlm1dfg.wc1.fmu.M1",0.005);
oms3_setReal("model.tlm1dfg.wc1.fmu.B1",0.2);
oms3_setReal("model.tlm1dfg.wc1.fmu.K1",90);
oms3_setReal("model.tlm1dfg.wc1.fmu.M2",0.005);
oms3_setReal("model.tlm1dfg.wc1.fmu.B2",0.2);
oms3_setReal("model.tlm1dfg.wc1.fmu.K2",141);

oms3_setReal("model.tlm1dfg.wc2.fmu.t_step1",0.1);
oms3_setReal("model.tlm1dfg.wc2.fmu.F_y1",-100);
oms3_setReal("model.tlm1dfg.wc2.fmu.t_step2",2);
oms3_setReal("model.tlm1dfg.wc2.fmu.F_y2",-300);
oms3_setReal("model.tlm1dfg.wc2.fmu.M",0.005);
oms3_setReal("model.tlm1dfg.wc2.fmu.B",0.2);

oms3_initialize("model");
oms3_simulate("model");
oms3_terminate("model");

vars = {"wc1.P.v [m/s]","wc2.P.v [m/s]","wc1.P.F [N]","wc2.P.F [N]"}
for _,var in ipairs(vars) do
  if 1 == oms2_compareSimulationResults("tlm1dfg.csv", "../ReferenceFiles/tlm1dfg.csv", var, 1e-2, 1e-4) then
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
-- info:    Logging information has been saved to "tlm1dfg.log"
-- endResult
