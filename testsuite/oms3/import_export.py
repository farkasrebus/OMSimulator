## status: correct
## teardown_command: rm -rf import_export-py/ test-py.ssp
## linux: yes
## mingw: yes
## win: no
## mac: no

from OMSimulator import OMSimulator
session=OMSimulator()

session.oms3_setCommandLineOption("--suppressPath=true")
session.oms3_setTempDirectory("./import_export-py/")

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

status = session.oms3_newModel("test")
printStatus(status, 0)

status = session.oms3_addSystem("test.eoo", session.oms_system_tlm)
printStatus(status, 0)

status = session.oms3_setTLMSocketData("test.eoo", "127.0.1.1", 11111, 11121)

status = session.oms3_addSystem("test.eoo.foo", session.oms_system_wc)
printStatus(status, 0)

## CS FMU
status = session.oms3_addSubModel("test.eoo.foo.A", "../FMUs/source.fmu")
printStatus(status, 0)

## table
status = session.oms3_addSubModel("test.eoo.foo.T", "setpoint.csv")
printStatus(status, 0)

status = session.oms3_addSystem("test.eoo.foo.goo", session.oms_system_sc)
printStatus(status, 0)

status = session.oms3_addSystem("test.eoo.foo2", session.oms_system_wc)
printStatus(status, 0)

status = session.oms3_addConnector("test.eoo.foo.f", session.input, session.oms_signal_type_real)
printStatus(status, 0)

status = session.oms3_addConnector("test.eoo.foo.x", session.output, session.oms_signal_type_real)
printStatus(status, 0)

status = session.oms3_addConnector("test.eoo.foo.v", session.output, session.oms_signal_type_real)
printStatus(status, 0)

status = session.oms3_addConnector("test.eoo.foo.y1", session.output, session.oms_signal_type_real)
printStatus(status, 0)

status = session.oms3_addConnector("test.eoo.foo.y2", session.output, session.oms_signal_type_real)
printStatus(status, 0)

status = session.oms3_addTLMBus("test.eoo.foo.tlm", "mechanical", 1, session.default)
printStatus(status, 0)

status = session.oms3_addConnectorToTLMBus("test.eoo.foo.tlm", "test.eoo.foo.f", "effort")
printStatus(status, 0)

status = session.oms3_addConnectorToTLMBus("test.eoo.foo.tlm", "test.eoo.foo.x", "state")
printStatus(status, 0)

status = session.oms3_addConnectorToTLMBus("test.eoo.foo.tlm", "test.eoo.foo.v", "flow")
printStatus(status, 0)

status = session.oms3_addBus("test.eoo.foo.bus")
printStatus(status, 0)

status = session.oms3_addConnectorToBus("test.eoo.foo.bus", "test.eoo.foo.y1")
printStatus(status, 0)

status = session.oms3_addConnectorToBus("test.eoo.foo.bus", "test.eoo.foo.y2")
printStatus(status, 0)

status = session.oms3_addConnector("test.eoo.foo2.f", session.input, session.oms_signal_type_real)
printStatus(status, 0)

status = session.oms3_addConnector("test.eoo.foo2.x", session.output, session.oms_signal_type_real)
printStatus(status, 0)

status = session.oms3_addConnector("test.eoo.foo2.v", session.output, session.oms_signal_type_real)
printStatus(status, 0)

status = session.oms3_addConnector("test.eoo.foo2.u1", session.input, session.oms_signal_type_real)
printStatus(status, 0)

status = session.oms3_addConnector("test.eoo.foo2.u2", session.input, session.oms_signal_type_real)
printStatus(status, 0)

status = session.oms3_addTLMBus("test.eoo.foo2.tlm", "mechanical", 1, session.default)
printStatus(status, 0)

status = session.oms3_addConnectorToTLMBus("test.eoo.foo2.tlm", "test.eoo.foo2.f", "effort")
printStatus(status, 0)

status = session.oms3_addConnectorToTLMBus("test.eoo.foo2.tlm", "test.eoo.foo2.x", "state")
printStatus(status, 0)

status = session.oms3_addConnectorToTLMBus("test.eoo.foo2.tlm", "test.eoo.foo2.v", "flow")
printStatus(status, 0)

status = session.oms3_addBus("test.eoo.foo2.bus")
printStatus(status, 0)

status = session.oms3_addConnectorToBus("test.eoo.foo2.bus", "test.eoo.foo2.u1")
printStatus(status, 0)

status = session.oms3_addConnectorToBus("test.eoo.foo2.bus", "test.eoo.foo2.u2")
printStatus(status, 0)

status = session.oms3_addTLMConnection("test.eoo.foo.tlm", "test.eoo.foo2.tlm", 0.001, 0.3, 100, 0)
printStatus(status, 0)

status = session.oms3_addConnection("test.eoo.foo.y1", "test.eoo.foo2.u1")
printStatus(status, 0)

status = session.oms3_addConnection("test.eoo.foo.y2", "test.eoo.foo2.u2")
printStatus(status, 0)

status = session.oms3_addConnection("test.eoo.foo.bus", "test.eoo.foo2.bus")
printStatus(status, 0)

status, src = session.oms3_list("test")
printStatus(status, 0)
print(src)

status = session.oms3_export("test", "test-py.ssp")
printStatus(status, 0)

status = session.oms3_delete("test")
printStatus(status, 0)

status, model = session.oms3_import("test-py.ssp")
printStatus(status, 0)

status, src = session.oms3_list(model)
printStatus(status, 0)
print(src)

status = session.oms3_delete(model)
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
## status:  [correct] ok
## status:  [correct] ok
## status:  [correct] ok
## status:  [correct] ok
## status:  [correct] ok
## status:  [correct] ok
## status:  [correct] ok
## status:  [correct] ok
## status:  [correct] ok
## status:  [correct] ok
## status:  [correct] ok
## status:  [correct] ok
## status:  [correct] ok
## status:  [correct] ok
## status:  [correct] ok
## status:  [correct] ok
## status:  [correct] ok
## status:  [correct] ok
## status:  [correct] ok
## status:  [correct] ok
## status:  [correct] ok
## status:  [correct] ok
## status:  [correct] ok
## status:  [correct] ok
## status:  [correct] ok
## status:  [correct] ok
## status:  [correct] ok
## status:  [correct] ok
## <?xml version="1.0"?>
## <ssd:SystemStructureDescription name="test" version="Draft20180219">
## 	<ssd:System name="eoo">
## 		<ssd:SimulationInformation>
## 			<ssd:Annotations>
## 				<ssd:Annotation type="org.openmodelica">
## 					<oms:TlmMaster ip="127.0.1.1" managerport="11111" monitorport="11121" />
## 				</ssd:Annotation>
## 			</ssd:Annotations>
## 		</ssd:SimulationInformation>
## 		<ssd:Elements>
## 			<ssd:System name="foo2">
## 				<ssd:SimulationInformation>
## 					<FixedStepMaster description="oms-ma" stepSize="0.100000" />
## 				</ssd:SimulationInformation>
## 				<ssd:Elements />
## 				<ssd:Connectors>
## 					<ssd:Connector name="f" kind="input" type="Real" />
## 					<ssd:Connector name="x" kind="output" type="Real" />
## 					<ssd:Connector name="v" kind="output" type="Real" />
## 					<ssd:Connector name="u1" kind="input" type="Real" />
## 					<ssd:Connector name="u2" kind="input" type="Real" />
## 				</ssd:Connectors>
## 				<ssd:Connections />
## 				<ssd:Annotations>
## 					<ssd:Annotation type="org.openmodelica">
## 						<oms:Bus name="bus">
## 							<oms:Signals>
## 								<oms:Signal name="u1" />
## 								<oms:Signal name="u2" />
## 							</oms:Signals>
## 						</oms:Bus>
## 						<oms:Bus name="tlm" type="tlm" domain="mechanical" dimensions="1" interpolation="none">
## 							<oms:Signals>
## 								<oms:Signal name="f" type="effort" />
## 								<oms:Signal name="v" type="flow" />
## 								<oms:Signal name="x" type="state" />
## 							</oms:Signals>
## 						</oms:Bus>
## 					</ssd:Annotation>
## 				</ssd:Annotations>
## 			</ssd:System>
## 			<ssd:System name="foo">
## 				<ssd:SimulationInformation>
## 					<FixedStepMaster description="oms-ma" stepSize="0.100000" />
## 				</ssd:SimulationInformation>
## 				<ssd:Elements>
## 					<ssd:System name="goo">
## 						<ssd:SimulationInformation>
## 							<VariableStepSolver description="cvode" absoluteTolerance="0.000100" relativeTolerance="0.000100" minimumStepSize="0.000100" maximumStepSize="0.100000" initialStepSize="0.000100" />
## 						</ssd:SimulationInformation>
## 						<ssd:Elements />
## 						<ssd:Connectors />
## 						<ssd:Connections />
## 					</ssd:System>
## 					<ssd:Component name="T" type="application/table" source="resources/T.csv">
## 						<ssd:Connectors>
## 							<ssd:Connector name="time" kind="output" type="Real">
## 								<ssd:ConnectorGeometry x="1.000000" y="0.333333" />
## 							</ssd:Connector>
## 							<ssd:Connector name="speed" kind="output" type="Real">
## 								<ssd:ConnectorGeometry x="1.000000" y="0.666667" />
## 							</ssd:Connector>
## 						</ssd:Connectors>
## 					</ssd:Component>
## 					<ssd:Component name="A" type="application/x-fmu-sharedlibrary" source="resources/A.fmu">
## 						<ssd:Connectors>
## 							<ssd:Connector name="y" kind="output" type="Real">
## 								<ssd:ConnectorGeometry x="1.000000" y="0.500000" />
## 							</ssd:Connector>
## 							<ssd:Connector name="A" kind="parameter" type="Real" />
## 							<ssd:Connector name="omega" kind="parameter" type="Real" />
## 						</ssd:Connectors>
## 					</ssd:Component>
## 				</ssd:Elements>
## 				<ssd:Connectors>
## 					<ssd:Connector name="f" kind="input" type="Real" />
## 					<ssd:Connector name="x" kind="output" type="Real" />
## 					<ssd:Connector name="v" kind="output" type="Real" />
## 					<ssd:Connector name="y1" kind="output" type="Real" />
## 					<ssd:Connector name="y2" kind="output" type="Real" />
## 				</ssd:Connectors>
## 				<ssd:Connections />
## 				<ssd:Annotations>
## 					<ssd:Annotation type="org.openmodelica">
## 						<oms:Bus name="bus">
## 							<oms:Signals>
## 								<oms:Signal name="y1" />
## 								<oms:Signal name="y2" />
## 							</oms:Signals>
## 						</oms:Bus>
## 						<oms:Bus name="tlm" type="tlm" domain="mechanical" dimensions="1" interpolation="none">
## 							<oms:Signals>
## 								<oms:Signal name="f" type="effort" />
## 								<oms:Signal name="v" type="flow" />
## 								<oms:Signal name="x" type="state" />
## 							</oms:Signals>
## 						</oms:Bus>
## 					</ssd:Annotation>
## 				</ssd:Annotations>
## 			</ssd:System>
## 		</ssd:Elements>
## 		<ssd:Connectors />
## 		<ssd:Connections>
## 			<ssd:Connection startElement="foo" startConnector="y1" endElement="foo2" endConnector="u1" />
## 			<ssd:Connection startElement="foo" startConnector="y2" endElement="foo2" endConnector="u2" />
## 		</ssd:Connections>
## 		<ssd:Annotations>
## 			<ssd:Annotation type="org.openmodelica">
## 				<oms:Connections>
## 					<oms:Connection startElement="foo" startConnector="tlm" endElement="foo2" endConnector="tlm" delay="0.001000" alpha="0.300000" linearimpedance="100.000000" angularimpedance="0.000000" />
## 					<oms:Connection startElement="foo" startConnector="bus" endElement="foo2" endConnector="bus" />
## 				</oms:Connections>
## 			</ssd:Annotation>
## 		</ssd:Annotations>
## 	</ssd:System>
## 	<ssd:DefaultExperiment startTime="0.000000" stopTime="1.000000" />
## </ssd:SystemStructureDescription>
##
## status:  [correct] ok
## status:  [correct] ok
## status:  [correct] ok
## status:  [correct] ok
## <?xml version="1.0"?>
## <ssd:SystemStructureDescription name="test" version="Draft20180219">
## 	<ssd:System name="eoo">
## 		<ssd:SimulationInformation>
## 			<ssd:Annotations>
## 				<ssd:Annotation type="org.openmodelica">
## 					<oms:TlmMaster ip="127.0.1.1" managerport="11111" monitorport="11121" />
## 				</ssd:Annotation>
## 			</ssd:Annotations>
## 		</ssd:SimulationInformation>
## 		<ssd:Elements>
## 			<ssd:System name="foo2">
## 				<ssd:SimulationInformation>
## 					<FixedStepMaster description="oms-ma" stepSize="0.100000" />
## 				</ssd:SimulationInformation>
## 				<ssd:Elements />
## 				<ssd:Connectors>
## 					<ssd:Connector name="f" kind="input" type="Real" />
## 					<ssd:Connector name="x" kind="output" type="Real" />
## 					<ssd:Connector name="v" kind="output" type="Real" />
## 					<ssd:Connector name="u1" kind="input" type="Real" />
## 					<ssd:Connector name="u2" kind="input" type="Real" />
## 				</ssd:Connectors>
## 				<ssd:Connections />
## 				<ssd:Annotations>
## 					<ssd:Annotation type="org.openmodelica">
## 						<oms:Bus name="bus">
## 							<oms:Signals>
## 								<oms:Signal name="u1" />
## 								<oms:Signal name="u2" />
## 							</oms:Signals>
## 						</oms:Bus>
## 						<oms:Bus name="tlm" type="tlm" domain="mechanical" dimensions="1" interpolation="none">
## 							<oms:Signals>
## 								<oms:Signal name="f" type="effort" />
## 								<oms:Signal name="v" type="flow" />
## 								<oms:Signal name="x" type="state" />
## 							</oms:Signals>
## 						</oms:Bus>
## 					</ssd:Annotation>
## 				</ssd:Annotations>
## 			</ssd:System>
## 			<ssd:System name="foo">
## 				<ssd:SimulationInformation>
## 					<FixedStepMaster description="oms-ma" stepSize="0.100000" />
## 				</ssd:SimulationInformation>
## 				<ssd:Elements>
## 					<ssd:System name="goo">
## 						<ssd:SimulationInformation>
## 							<VariableStepSolver description="cvode" absoluteTolerance="0.000100" relativeTolerance="0.000100" minimumStepSize="0.000100" maximumStepSize="0.100000" initialStepSize="0.000100" />
## 						</ssd:SimulationInformation>
## 						<ssd:Elements />
## 						<ssd:Connectors />
## 						<ssd:Connections />
## 					</ssd:System>
## 					<ssd:Component name="T" type="application/table" source="resources/T.csv">
## 						<ssd:Connectors>
## 							<ssd:Connector name="time" kind="output" type="Real">
## 								<ssd:ConnectorGeometry x="1.000000" y="0.333333" />
## 							</ssd:Connector>
## 							<ssd:Connector name="speed" kind="output" type="Real">
## 								<ssd:ConnectorGeometry x="1.000000" y="0.666667" />
## 							</ssd:Connector>
## 						</ssd:Connectors>
## 					</ssd:Component>
## 					<ssd:Component name="A" type="application/x-fmu-sharedlibrary" source="resources/A.fmu">
## 						<ssd:Connectors>
## 							<ssd:Connector name="y" kind="output" type="Real">
## 								<ssd:ConnectorGeometry x="1.000000" y="0.500000" />
## 							</ssd:Connector>
## 							<ssd:Connector name="A" kind="parameter" type="Real" />
## 							<ssd:Connector name="omega" kind="parameter" type="Real" />
## 						</ssd:Connectors>
## 					</ssd:Component>
## 				</ssd:Elements>
## 				<ssd:Connectors>
## 					<ssd:Connector name="f" kind="input" type="Real" />
## 					<ssd:Connector name="x" kind="output" type="Real" />
## 					<ssd:Connector name="v" kind="output" type="Real" />
## 					<ssd:Connector name="y1" kind="output" type="Real" />
## 					<ssd:Connector name="y2" kind="output" type="Real" />
## 				</ssd:Connectors>
## 				<ssd:Connections />
## 				<ssd:Annotations>
## 					<ssd:Annotation type="org.openmodelica">
## 						<oms:Bus name="bus">
## 							<oms:Signals>
## 								<oms:Signal name="y1" />
## 								<oms:Signal name="y2" />
## 							</oms:Signals>
## 						</oms:Bus>
## 						<oms:Bus name="tlm" type="tlm" domain="mechanical" dimensions="1" interpolation="none">
## 							<oms:Signals>
## 								<oms:Signal name="f" type="effort" />
## 								<oms:Signal name="v" type="flow" />
## 								<oms:Signal name="x" type="state" />
## 							</oms:Signals>
## 						</oms:Bus>
## 					</ssd:Annotation>
## 				</ssd:Annotations>
## 			</ssd:System>
## 		</ssd:Elements>
## 		<ssd:Connectors />
## 		<ssd:Connections>
## 			<ssd:Connection startElement="foo" startConnector="y1" endElement="foo2" endConnector="u1" />
## 			<ssd:Connection startElement="foo" startConnector="y2" endElement="foo2" endConnector="u2" />
## 		</ssd:Connections>
## 		<ssd:Annotations>
## 			<ssd:Annotation type="org.openmodelica">
## 				<oms:Connections>
## 					<oms:Connection startElement="foo" startConnector="tlm" endElement="foo2" endConnector="tlm" delay="0.001000" alpha="0.300000" linearimpedance="100.000000" angularimpedance="0.000000" />
## 					<oms:Connection startElement="foo" startConnector="bus" endElement="foo2" endConnector="bus" />
## 				</oms:Connections>
## 			</ssd:Annotation>
## 		</ssd:Annotations>
## 	</ssd:System>
## 	<ssd:DefaultExperiment startTime="0.000000" stopTime="1.000000" />
## </ssd:SystemStructureDescription>
##
## status:  [correct] ok
## endResult
