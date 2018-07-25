oms2_setLogFile("EventChain.log")
oms2_setTempDirectory("./tmp")
oms2_newFMIModel("EventChain")

oms2_addFMU("EventChain", "EventChain_DummyEventGenerator.fmu", "Gen")
oms2_addFMU("EventChain", "EventChain_EventChainLink2.fmu", "Link1")
oms2_addFMU("EventChain", "EventChain_EventChainLink.fmu", "Link2")
oms2_addFMU("EventChain", "EventChain_DummyInverter.fmu", "Inv")

oms2_addConnection("EventChain", "Link1:leftIn", "Gen:event")
oms2_addConnection("EventChain", "Gen:reaction","Link1:leftOut")
oms2_addConnection("EventChain", "Link2:leftIn","Link1:rightOut")
oms2_addConnection("EventChain", "Link1:rightIn","Link2:leftOut")
oms2_addConnection("EventChain", "Inv:original","Link2:rightOut")
oms2_addConnection("EventChain", "Link2:rightIn", "Inv:inverted")

oms2_setResultFile("EventChain", "EventChain.mat")

oms2_setStopTime("EventChain", 1.0)
oms2_setCommunicationInterval("EventChain", 0.01)

oms2_initialize("EventChain")
oms2_exportDependencyGraphs("EventChain","in.dot","out.dot")
oms2_simulate("EventChain")

oms2_unloadModel("EventChain")
