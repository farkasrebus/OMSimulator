package.path = package.path .. ";../StepSizeController.lua"
require("StepSizeController")

oms2_setLogFile("ECwithSCC.log")
oms2_setTempDirectory("./tmp")
oms2_newFMIModel("EventChain")
-- instantiate FMU
oms2_addFMU("EventChain", "EventChain_DummyEventGenerator.fmu", "Gen")
oms2_addFMU("EventChain", "EventChain_InverterEventChainLink.fmu", "Link1")
oms2_addFMU("EventChain", "EventChain_InverterEventChainLink2.fmu", "Link2")
-- add connections
oms2_addConnection("EventChain", "Link1:eventInput", "Gen:event")
oms2_addConnection("EventChain", "Link2:eventInput","Link1:eventOutput")

oms2_setResultFile("EventChain", "ECwithSCC.mat")
-- simulation configuration
oms2_setStopTime("EventChain", 1.0)
oms2_setCommunicationInterval("EventChain", 0.01)
oms2_initialize("EventChain")

-- sensitivity model

sm=SensitivityModel:create()
sm.events["EventChain.Gen:event"]=true
sm.events["EventChain.Link1:eventOutput"]=true
sm.events["EventChain.Link2:eventOutput"]=true

oms2_simulateWithASSC("EventChain",0.01,sm,0.001,1.0)

oms2_unloadModel("EventChain")
