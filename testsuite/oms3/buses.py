## status: correct
## teardown_command: rm -rf buses-py/
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

status = session.oms3_setTempDirectory("./buses-py/")
printStatus(status, 0)

status = session.oms3_newModel("model")
status = session.oms3_addSystem("model.tlm", session.oms_system_tlm)
status = session.oms3_addSystem("model.tlm.wc1", session.oms_system_wc)
status = session.oms3_addSystem("model.tlm.wc2", session.oms_system_wc)
status = session.oms3_addConnector("model.tlm.wc1.u1", session.input, session.oms_signal_type_real)
status = session.oms3_addConnector("model.tlm.wc1.u2", session.input, session.oms_signal_type_real)
status = session.oms3_addConnector("model.tlm.wc1.y", session.output, session.oms_signal_type_real)
status = session.oms3_addConnector("model.tlm.wc2.y1", session.output, session.oms_signal_type_real)
status = session.oms3_addConnector("model.tlm.wc2.y2", session.output, session.oms_signal_type_real)
status = session.oms3_addConnector("model.tlm.wc2.y3", session.output, session.oms_signal_type_real)
status = session.oms3_addBus("model.tlm.wc1.bus1")
printStatus(status, 0)

status = session.oms3_addConnectorToBus("model.tlm.wc1.bus1","model.tlm.wc1.u1")
printStatus(status, 0)

status = session.oms3_addConnectorToBus("model.tlm.wc1.bus1","model.tlm.wc1.u2")
printStatus(status, 0)

status = session.oms3_addConnectorToBus("model.tlm.wc1.bus1","model.tlm.wc2.y1")
printStatus(status, 3)

status = session.oms3_addConnectorToBus("model.tlm.wc1.bus1","model.tlm.wc1.y")
printStatus(status, 0)

status = session.oms3_addBus("model.tlm.wc2.bus2")
printStatus(status, 0)

status = session.oms3_addConnectorToBus("model.tlm.wc2.bus2","model.tlm.wc2.y1")
printStatus(status, 0)

status = session.oms3_addConnectorToBus("model.tlm.wc2.bus2","model.tlm.wc2.y2")
printStatus(status, 0)

status = session.oms3_addConnection("model.tlm.wc1.u1","model.tlm.wc2.y1")
printStatus(status, 0)

status = session.oms3_addConnection("model.tlm.wc1.bus1","model.tlm.wc2.bus2")
printStatus(status, 0)

status = session.oms3_addConnection("model.tlm.wc1.u2","model.tlm.wc2.y2")
printStatus(status, 0)

status = session.oms3_addConnection("model.tlm.wc2.bus2","model.tlm.wc1.bus1")
printStatus(status, 3)

status, src = session.oms3_list("model.tlm")
print(src)

status = session.oms3_deleteConnectorFromBus("model.tlm.wc1.bus1","model.tlm.wc1.y")
printStatus(status, 0)

status, src = session.oms3_list("model.tlm")
print(src)

status = session.oms3_delete("model")
printStatus(status, 0)

## Result:
## status:  [correct] ok
## status:  [correct] ok
## status:  [correct] ok
## status:  [correct] ok
## error:   [addConnectorToBus] Bus and connector must belong to same system
## status:  [correct] error
## status:  [correct] ok
## status:  [correct] ok
## status:  [correct] ok
## status:  [correct] ok
## status:  [correct] ok
## status:  [correct] ok
## status:  [correct] ok
## error:   [addConnection] Connection <"wc2.bus2", "wc1.bus1"> exists already in system "model.tlm"
## status:  [correct] error
## <?xml version="1.0"?>
## <ssd:System name="tlm">
## 	<ssd:SimulationInformation>
## 		<ssd:Annotations>
## 			<ssd:Annotation type="org.openmodelica">
## 				<oms:TlmMaster ip="" managerport="0" monitorport="0" />
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
## 				<ssd:Connector name="y1" kind="output" type="Real" />
## 				<ssd:Connector name="y2" kind="output" type="Real" />
## 				<ssd:Connector name="y3" kind="output" type="Real" />
## 			</ssd:Connectors>
## 			<ssd:Connections />
## 			<ssd:Annotations>
## 				<ssd:Annotation type="org.openmodelica">
## 					<oms:Bus name="bus2">
## 						<oms:Signals>
## 							<oms:Signal name="y1" />
## 							<oms:Signal name="y2" />
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
## 				<ssd:Connector name="u1" kind="input" type="Real" />
## 				<ssd:Connector name="u2" kind="input" type="Real" />
## 				<ssd:Connector name="y" kind="output" type="Real" />
## 			</ssd:Connectors>
## 			<ssd:Connections />
## 			<ssd:Annotations>
## 				<ssd:Annotation type="org.openmodelica">
## 					<oms:Bus name="bus1">
## 						<oms:Signals>
## 							<oms:Signal name="u1" />
## 							<oms:Signal name="u2" />
## 							<oms:Signal name="y" />
## 						</oms:Signals>
## 					</oms:Bus>
## 				</ssd:Annotation>
## 			</ssd:Annotations>
## 		</ssd:System>
## 	</ssd:Elements>
## 	<ssd:Connectors />
## 	<ssd:Connections>
## 		<ssd:Connection startElement="wc2" startConnector="y1" endElement="wc1" endConnector="u1" />
## 		<ssd:Connection startElement="wc2" startConnector="y2" endElement="wc1" endConnector="u2" />
## 	</ssd:Connections>
## 	<ssd:Annotations>
## 		<ssd:Annotation type="org.openmodelica">
## 			<oms:Connections>
## 				<oms:Connection startElement="wc1" startConnector="bus1" endElement="wc2" endConnector="bus2" />
## 			</oms:Connections>
## 		</ssd:Annotation>
## 	</ssd:Annotations>
## </ssd:System>
##
## status:  [correct] ok
## <?xml version="1.0"?>
## <ssd:System name="tlm">
## 	<ssd:SimulationInformation>
## 		<ssd:Annotations>
## 			<ssd:Annotation type="org.openmodelica">
## 				<oms:TlmMaster ip="" managerport="0" monitorport="0" />
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
## 				<ssd:Connector name="y1" kind="output" type="Real" />
## 				<ssd:Connector name="y2" kind="output" type="Real" />
## 				<ssd:Connector name="y3" kind="output" type="Real" />
## 			</ssd:Connectors>
## 			<ssd:Connections />
## 			<ssd:Annotations>
## 				<ssd:Annotation type="org.openmodelica">
## 					<oms:Bus name="bus2">
## 						<oms:Signals>
## 							<oms:Signal name="y1" />
## 							<oms:Signal name="y2" />
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
## 				<ssd:Connector name="u1" kind="input" type="Real" />
## 				<ssd:Connector name="u2" kind="input" type="Real" />
## 				<ssd:Connector name="y" kind="output" type="Real" />
## 			</ssd:Connectors>
## 			<ssd:Connections />
## 			<ssd:Annotations>
## 				<ssd:Annotation type="org.openmodelica">
## 					<oms:Bus name="bus1">
## 						<oms:Signals>
## 							<oms:Signal name="u1" />
## 							<oms:Signal name="u2" />
## 						</oms:Signals>
## 					</oms:Bus>
## 				</ssd:Annotation>
## 			</ssd:Annotations>
## 		</ssd:System>
## 	</ssd:Elements>
## 	<ssd:Connectors />
## 	<ssd:Connections>
## 		<ssd:Connection startElement="wc2" startConnector="y1" endElement="wc1" endConnector="u1" />
## 		<ssd:Connection startElement="wc2" startConnector="y2" endElement="wc1" endConnector="u2" />
## 	</ssd:Connections>
## 	<ssd:Annotations>
## 		<ssd:Annotation type="org.openmodelica">
## 			<oms:Connections>
## 				<oms:Connection startElement="wc1" startConnector="bus1" endElement="wc2" endConnector="bus2" />
## 			</oms:Connections>
## 		</ssd:Annotation>
## 	</ssd:Annotations>
## </ssd:System>
##
## status:  [correct] ok
## info:    0 warnings
## info:    2 errors
## endResult
