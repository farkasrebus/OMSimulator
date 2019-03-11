## status: correct
## teardown_command: rm -rf tlmbuses-py/
## linux: yes
## mingw: yes
## win: no
## mac: no

from OMSimulator import OMSimulator
session=OMSimulator()

session.oms3_setCommandLineOption("--suppressPath=true")
session.oms3_setTempDirectory("./tlmbuses-py/")

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

session.oms3_newModel("model")
session.oms3_addSystem("model.tlm", session.oms_system_tlm)
session.oms3_setTLMSocketData("model.tlm", "127.0.1.1", 11111, 11121)
session.oms3_addSystem("model.tlm.wc1", session.oms_system_wc)
session.oms3_addConnector("model.tlm.wc1.y", session.output, session.oms_signal_type_real)
session.oms3_addConnector("model.tlm.wc1.x", session.output, session.oms_signal_type_real)
session.oms3_addConnector("model.tlm.wc1.v", session.output, session.oms_signal_type_real)
session.oms3_addConnector("model.tlm.wc1.f", session.input, session.oms_signal_type_real)

session.oms3_addSystem("model.tlm.wc2", session.oms_system_wc)
session.oms3_addConnector("model.tlm.wc2.y", session.input, session.oms_signal_type_real)
session.oms3_addConnector("model.tlm.wc2.x", session.output, session.oms_signal_type_real)
session.oms3_addConnector("model.tlm.wc2.v", session.output, session.oms_signal_type_real)
session.oms3_addConnector("model.tlm.wc2.f", session.input, session.oms_signal_type_real)

status = session.oms3_addTLMBus("model.tlm.wc1.bus1", "input", 1, session.default)
printStatus(status, 0)

status = session.oms3_addConnectorToTLMBus("model.tlm.wc1.bus1","model.tlm.wc1.y", "value")
printStatus(status, 0)

## Test adding non-existing connector
status = session.oms3_addConnectorToTLMBus("model.tlm.wc1.bus1","model.tlm.wc1.z", "value")
printStatus(status, 3)

## Test adding connector with illegal type
status = session.oms3_addConnectorToTLMBus("model.tlm.wc1.bus1","model.tlm.wc1.y", "effort")
printStatus(status, 3)

status = session.oms3_addTLMBus("model.tlm.wc1.bus2", "mechanical", 1, session.default)
printStatus(status, 0)

status = session.oms3_addConnectorToTLMBus("model.tlm.wc1.bus2","model.tlm.wc1.x", "state")
printStatus(status, 0)

status = session.oms3_addConnectorToTLMBus("model.tlm.wc1.bus2","model.tlm.wc1.v", "flow")
printStatus(status, 0)

status = session.oms3_addConnectorToTLMBus("model.tlm.wc1.bus2","model.tlm.wc1.f", "effort")
printStatus(status, 0)

status = session.oms3_addTLMBus("model.tlm.wc2.bus2", "output", 1, session.default)
printStatus(status, 0)

status = session.oms3_addConnectorToTLMBus("model.tlm.wc2.bus2","model.tlm.wc2.y", "value")
printStatus(status, 0)

status = session.oms3_addTLMConnection("model.tlm.wc1.bus1","model.tlm.wc2.bus2", 0.001,0.3,100,0)
printStatus(status, 0)

src, status = session.oms3_list("model.tlm")
print src

status = session.oms3_deleteConnectorFromTLMBus("model.tlm.wc1.bus2","model.tlm.wc1.x")
printStatus(status, 0)

status, src = session.oms3_list("model.tlm")
print src

status = session.oms3_delete("model")
printStatus(status, 0)

## Result:
## status:  [correct] ok
## status:  [correct] ok
## error:   [addConnectorToTLMBus] Connector "z" not found in system "model.tlm.wc1"
## status:  [correct] error
## error:   [addConnector] Unknown TLM variable type: effort
## status:  [correct] error
## status:  [correct] ok
## status:  [correct] ok
## status:  [correct] ok
## status:  [correct] ok
## status:  [correct] ok
## status:  [correct] ok
## status:  [correct] ok
## 0
## status:  [correct] ok
## <?xml version="1.0"?>
## <ssd:System name="tlm">
## 	<ssd:SimulationInformation>
## 		<ssd:Annotations>
## 			<ssd:Annotation type="org.openmodelica">
## 				<oms:TlmMaster ip="127.0.1.1" managerport="11111" monitorport="11121" />
## 			</ssd:Annotation>
## 		</ssd:Annotations>
## 	</ssd:SimulationInformation>
## 	<ssd:Elements>
## 		<ssd:System name="wc2">
## 			<ssd:SimulationInformation>
## 				<FixedStepMaster description="oms-ma" stepSize="0.100000" />
## 			</ssd:SimulationInformation>
## 			<ssd:Elements />
## 			<ssd:Connectors>
## 				<ssd:Connector name="y" kind="input" type="Real" />
## 				<ssd:Connector name="x" kind="output" type="Real" />
## 				<ssd:Connector name="v" kind="output" type="Real" />
## 				<ssd:Connector name="f" kind="input" type="Real" />
## 			</ssd:Connectors>
## 			<ssd:Connections />
## 			<ssd:Annotations>
## 				<ssd:Annotation type="org.openmodelica">
## 					<oms:Bus name="bus2" type="tlm" domain="output" dimensions="1" interpolation="none">
## 						<oms:Signals>
## 							<oms:Signal name="y" type="value" />
## 						</oms:Signals>
## 					</oms:Bus>
## 				</ssd:Annotation>
## 			</ssd:Annotations>
## 		</ssd:System>
## 		<ssd:System name="wc1">
## 			<ssd:SimulationInformation>
## 				<FixedStepMaster description="oms-ma" stepSize="0.100000" />
## 			</ssd:SimulationInformation>
## 			<ssd:Elements />
## 			<ssd:Connectors>
## 				<ssd:Connector name="y" kind="output" type="Real" />
## 				<ssd:Connector name="x" kind="output" type="Real" />
## 				<ssd:Connector name="v" kind="output" type="Real" />
## 				<ssd:Connector name="f" kind="input" type="Real" />
## 			</ssd:Connectors>
## 			<ssd:Connections />
## 			<ssd:Annotations>
## 				<ssd:Annotation type="org.openmodelica">
## 					<oms:Bus name="bus1" type="tlm" domain="input" dimensions="1" interpolation="none">
## 						<oms:Signals>
## 							<oms:Signal name="y" type="value" />
## 						</oms:Signals>
## 					</oms:Bus>
## 					<oms:Bus name="bus2" type="tlm" domain="mechanical" dimensions="1" interpolation="none">
## 						<oms:Signals>
## 							<oms:Signal name="f" type="effort" />
## 							<oms:Signal name="v" type="flow" />
## 						</oms:Signals>
## 					</oms:Bus>
## 				</ssd:Annotation>
## 			</ssd:Annotations>
## 		</ssd:System>
## 	</ssd:Elements>
## 	<ssd:Connectors />
## 	<ssd:Connections />
## 	<ssd:Annotations>
## 		<ssd:Annotation type="org.openmodelica">
## 			<oms:Connections>
## 				<oms:Connection startElement="wc1" startConnector="bus1" endElement="wc2" endConnector="bus2" delay="0.001000" alpha="0.300000" linearimpedance="100.000000" angularimpedance="0.000000" />
## 			</oms:Connections>
## 		</ssd:Annotation>
## 	</ssd:Annotations>
## </ssd:System>
##
## status:  [correct] ok
## info:    0 warnings
## info:    2 errors
## endResult
