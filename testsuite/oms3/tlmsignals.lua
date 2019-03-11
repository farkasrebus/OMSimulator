-- status: correct
-- teardown_command: rm -rf tlmsignals.log tlmsignals-lua/ tlmsignals.run tlmsignals.csv
-- linux: yes
-- mingw: no
-- mac: no

oms3_setLogFile("tlmsignals.log")
oms3_setTempDirectory("./tlmsignals-lua/")

oms3_newModel("model");

oms3_addSystem("model.tlmsignals", oms_system_tlm);

oms3_addSystem("model.tlmsignals.wc1", oms_system_wc);
oms3_setFixedStepSize("model.tlmsignals.wc1", 0.005);
oms3_addSubModel("model.tlmsignals.wc1.adder", "../FMUs/Modelica.Blocks.Math.Add.fmu");
oms3_addSubModel("model.tlmsignals.wc1.sine1", "../FMUs/sine.fmu");
oms3_addSubModel("model.tlmsignals.wc1.sine2", "../FMUs/sine.fmu");
oms3_addSubModel("model.tlmsignals.wc1.gain", "../FMUs/Modelica.Blocks.Math.Gain.fmu");
oms3_addConnection("model.tlmsignals.wc1.sine1.y", "model.tlmsignals.wc1.adder.u1");
oms3_addConnection("model.tlmsignals.wc1.sine2.y", "model.tlmsignals.wc1.adder.u2");
oms3_addTLMBus("model.tlmsignals.wc1.out","output",1);
oms3_addTLMBus("model.tlmsignals.wc1.in","input",1);
oms3_addConnector("model.tlmsignals.wc1.y",output,oms_signal_type_real);
oms3_addConnector("model.tlmsignals.wc1.u",input,oms_signal_type_real);
oms3_addConnection("model.tlmsignals.wc1.adder.y","model.tlmsignals.wc1.y");
oms3_addConnection("model.tlmsignals.wc1.u","model.tlmsignals.wc1.gain.u");
oms3_addConnectorToTLMBus("model.tlmsignals.wc1.out","model.tlmsignals.wc1.y", "value");
oms3_addConnectorToTLMBus("model.tlmsignals.wc1.in","model.tlmsignals.wc1.u", "value");

oms3_addSystem("model.tlmsignals.wc2", oms_system_wc);
oms3_setFixedStepSize("model.tlmsignals.wc2", 0.005);
oms3_addSubModel("model.tlmsignals.wc2.gain", "../FMUs/Modelica.Blocks.Math.Gain.fmu");
oms3_addTLMBus("model.tlmsignals.wc2.out","output",1);
oms3_addTLMBus("model.tlmsignals.wc2.in","input",1);
oms3_addConnector("model.tlmsignals.wc2.y",output,oms_signal_type_real);
oms3_addConnector("model.tlmsignals.wc2.u",input,oms_signal_type_real);
oms3_addConnection("model.tlmsignals.wc2.gain.y","model.tlmsignals.wc2.y");
oms3_addConnection("model.tlmsignals.wc2.u","model.tlmsignals.wc2.gain.u");
oms3_addConnectorToTLMBus("model.tlmsignals.wc2.out","model.tlmsignals.wc2.y", "value");
oms3_addConnectorToTLMBus("model.tlmsignals.wc2.in","model.tlmsignals.wc2.u", "value");

oms3_addTLMConnection("model.tlmsignals.wc1.out","model.tlmsignals.wc2.in", 0.01, 0, 0, 0);
oms3_addTLMConnection("model.tlmsignals.wc2.out","model.tlmsignals.wc1.in", 0.01, 0, 0, 0);

oms3_setTLMSocketData("model.tlmsignals","127.0.1.1",11111,12111)

oms3_setStartTime("model",0);
oms3_setStopTime("model",1);

oms3_instantiate("model");
oms3_setReal("model.tlmsignals.wc1.sine1.A",1);
oms3_setReal("model.tlmsignals.wc1.sine1.omega",8);
oms3_setReal("model.tlmsignals.wc1.sine2.A",0.3);
oms3_setReal("model.tlmsignals.wc1.sine2.omega",20);
oms3_setReal("model.tlmsignals.wc2.gain.k",2);

oms3_initialize("model");
oms3_simulate("model");
oms3_terminate("model");

vars = {"wc1.out","wc2.out"}
for _,var in ipairs(vars) do
  if 1 == oms2_compareSimulationResults("tlmsignals.csv", "../ReferenceFiles/tlmsignals.csv", var, 1e-2, 1e-4) then
    print(var .. " is equal")
  else
    print(var .. " is not equal")
  end
end

-- Result:
-- Starting TLM simulation.
-- Monitoring thread finished.
-- Manager thread finished.
-- wc1.out is equal
-- wc2.out is equal
-- info:    Logging information has been saved to "tlmsignals.log"
-- endResult
