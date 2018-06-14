oms2_setLogFile("EventChain.log")
oms2_setTempDirectory("./tmp")
oms2_newFMIModel("EventChain")

oms2_addFMU("EventChain", "EventChain_DummyEventGenerator.fmu", "Gen")
oms2_addFMU("EventChain", "EventChain_EventChainLink.fmu", "Link1")
oms2_addFMU("EventChain", "EventChain_InverterEventChainLink.fmu", "Inv")
oms2_addFMU("EventChain", "EventChain_EventChainLink2.fmu", "Link2")

oms2_addConnection("EventChain", "Link1:eventInput", "Gen:event")
oms2_addConnection("EventChain", "Inv:eventInput","Link1:eventOutput")
oms2_addConnection("EventChain", "Link2:eventInput","Inv:eventOutput")

oms2_setResultFile("EventChain", "EventChain.mat")

oms2_setStopTime("EventChain", 1.0)
oms2_setCommunicationInterval("EventChain", 0.01)

oms2_initialize("EventChain")
oms2_exportDependencyGraphs("EventChain","x.dot","dependency.dot")
oms2_simulate("EventChain")

oms2_terminate("EventChain")
oms2_unloadModel("EventChain")
