## status: correct
## teardown_command: rm -rf connections-py/
## linux: yes
## mingw: yes
## win: no
## mac: no

from OMSimulator import OMSimulator
session=OMSimulator()

session.oms3_setCommandLineOption("--suppressPath=true")

def printStatus(status, expected):
  cmp = ""
  if status == expected:
    cmp = "correct"
  else:
    cmp = "wrong"

  if 0 == status:
    status = "ok"
  elif 1 == status:
    status = "warning"
  elif 3 == status:
    status = "error"
  print "status:  [%s] %s" % (cmp, status)

status = session.oms3_setTempDirectory("./connections-py/")
printStatus(status, 0)

status = session.oms3_newModel("model")
printStatus(status, 0)

status = session.oms3_addSystem("model.wc", session.oms_system_wc)
printStatus(status, 0)

status = session.oms3_addSystem("model.wc.sc1", session.oms_system_sc)
printStatus(status, 0)

status = session.oms3_addSystem("model.wc.sc2", session.oms_system_sc)
printStatus(status, 0)

status = session.oms3_addConnector("model.wc.sc1.u1", session.input, session.oms_signal_type_real)
status = session.oms3_addConnector("model.wc.sc1.u2", session.input, session.oms_signal_type_real)
status = session.oms3_addConnector("model.wc.sc1.y", session.output, session.oms_signal_type_real)
printStatus(status, 0)

status = session.oms3_addConnector("model.wc.sc2.y1", session.output, session.oms_signal_type_real)
status = session.oms3_addConnector("model.wc.sc2.y2", session.output, session.oms_signal_type_integer)
status = session.oms3_addConnector("model.wc.sc2.y3", session.output, session.oms_signal_type_real)
printStatus(status, 0)

status = session.oms3_addConnection("model.wc.sc1.u1", "model.wc.sc2.y1")
printStatus(status, 0)

## Connecting input to input (illegal)
status = session.oms3_addConnection("model.wc.sc1.y", "model.wc.sc2.y3")
printStatus(status, 3)

## Connecting Real to Integer (illegal)
status = session.oms3_addConnection("model.wc.sc1.u2", "model.wc.sc2.y2")
printStatus(status, 3)

## Connecting to already connected connector (illegal)
status = session.oms3_addConnection("model.wc.sc1.u1", "model.wc.sc2.y3")
printStatus(status, 3)

status, src = session.oms3_list("model.wc")
print(src)

status = session.oms3_deleteConnection("model.wc.sc1.u1", "model.wc.sc2.y1")
printStatus(status, 0)

status, src = session.oms3_list("model.wc")
print(src)

status = session.oms3_delete("model")
printStatus(status, 0)

## Result:
## status:  [correct] ok
## status:  [correct] ok
## status:  [correct] ok
## status:  [correct] ok
## status:  [correct] ok
## status:  [correct] ok
## status:  [correct] ok
## status:  [correct] ok
## error:   [addConnection] Causality mismatch in connection: sc1.y -> sc2.y3
## status:  [correct] error
## error:   [addConnection] Type mismatch in connection: sc1.u2 -> sc2.y2
## status:  [correct] error
## error:   [addConnection] Connector is already connected: sc1.u1
## status:  [correct] error
## <?xml version="1.0"?>
## <ssd:System name="wc">
## 	<ssd:SimulationInformation>
## 		<FixedStepMaster description="oms-ma" stepSize="0.100000" />
## 	</ssd:SimulationInformation>
## 	<ssd:Elements>
## 		<ssd:System name="sc2">
## 			<ssd:SimulationInformation>
## 				<VariableStepSolver description="cvode" absoluteTolerance="0.000100" relativeTolerance="0.000100" minimumStepSize="0.000100" maximumStepSize="0.100000" initialStepSize="0.000100" />
## 			</ssd:SimulationInformation>
## 			<ssd:Elements />
## 			<ssd:Connectors>
## 				<ssd:Connector name="y1" kind="output" type="Real" />
## 				<ssd:Connector name="y2" kind="output" type="Integer" />
## 				<ssd:Connector name="y3" kind="output" type="Real" />
## 			</ssd:Connectors>
## 			<ssd:Connections />
## 		</ssd:System>
## 		<ssd:System name="sc1">
## 			<ssd:SimulationInformation>
## 				<VariableStepSolver description="cvode" absoluteTolerance="0.000100" relativeTolerance="0.000100" minimumStepSize="0.000100" maximumStepSize="0.100000" initialStepSize="0.000100" />
## 			</ssd:SimulationInformation>
## 			<ssd:Elements />
## 			<ssd:Connectors>
## 				<ssd:Connector name="u1" kind="input" type="Real" />
## 				<ssd:Connector name="u2" kind="input" type="Real" />
## 				<ssd:Connector name="y" kind="output" type="Real" />
## 			</ssd:Connectors>
## 			<ssd:Connections />
## 		</ssd:System>
## 	</ssd:Elements>
## 	<ssd:Connectors />
## 	<ssd:Connections>
## 		<ssd:Connection startElement="sc2" startConnector="y1" endElement="sc1" endConnector="u1" />
## 	</ssd:Connections>
## </ssd:System>
##
## status:  [correct] ok
## <?xml version="1.0"?>
## <ssd:System name="wc">
## 	<ssd:SimulationInformation>
## 		<FixedStepMaster description="oms-ma" stepSize="0.100000" />
## 	</ssd:SimulationInformation>
## 	<ssd:Elements>
## 		<ssd:System name="sc2">
## 			<ssd:SimulationInformation>
## 				<VariableStepSolver description="cvode" absoluteTolerance="0.000100" relativeTolerance="0.000100" minimumStepSize="0.000100" maximumStepSize="0.100000" initialStepSize="0.000100" />
## 			</ssd:SimulationInformation>
## 			<ssd:Elements />
## 			<ssd:Connectors>
## 				<ssd:Connector name="y1" kind="output" type="Real" />
## 				<ssd:Connector name="y2" kind="output" type="Integer" />
## 				<ssd:Connector name="y3" kind="output" type="Real" />
## 			</ssd:Connectors>
## 			<ssd:Connections />
## 		</ssd:System>
## 		<ssd:System name="sc1">
## 			<ssd:SimulationInformation>
## 				<VariableStepSolver description="cvode" absoluteTolerance="0.000100" relativeTolerance="0.000100" minimumStepSize="0.000100" maximumStepSize="0.100000" initialStepSize="0.000100" />
## 			</ssd:SimulationInformation>
## 			<ssd:Elements />
## 			<ssd:Connectors>
## 				<ssd:Connector name="u1" kind="input" type="Real" />
## 				<ssd:Connector name="u2" kind="input" type="Real" />
## 				<ssd:Connector name="y" kind="output" type="Real" />
## 			</ssd:Connectors>
## 			<ssd:Connections />
## 		</ssd:System>
## 	</ssd:Elements>
## 	<ssd:Connectors />
## 	<ssd:Connections />
## </ssd:System>
##
## status:  [correct] ok
## info:    0 warnings
## info:    3 errors
## endResult
