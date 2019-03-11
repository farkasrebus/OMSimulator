-- status: correct
-- teardown_command: rm -rf api-test02.log api_test02.xml api_test02b.xml api-test02_tmp

oms2_setLogFile("api-test02.log")

status = oms2_setTempDirectory("./api-test02_tmp")
print("status code: " .. status)

status = oms2_newFMIModel("api_test02")
print("status code: " .. status)

-- add FMUs
status = oms2_addFMU("api_test02", "../FMUs/DualMassOscillator.System1_me.fmu", "System1")
print("status code: " .. status)
status = oms2_addFMU("api_test02", "../FMUs/DualMassOscillator.System2_me.fmu", "System2")
print("status code: " .. status)

-- add connections
status = oms2_addConnection("api_test02", "System1:F", "System2:F")
print("status code: " .. status)
status = oms2_addConnection("api_test02", "System1:s", "System2:s")
print("status code: " .. status)
status = oms2_addConnection("api_test02", "System1:v", "System2:v")
print("status code: " .. status)
status = oms2_addConnection("api_test02", "System1:a", "System2:a")
print("status code: " .. status)

status = oms2_saveModel("api_test02", "api_test02.xml")
print("status code: " .. status)

status, source1 = oms2_listModel("api_test02")
print("status code: " .. status)
status = oms2_unloadModel("api_test02")
print("status code: " .. status)

status, ident = oms2_loadModel("api_test02.xml")
print("status code: " .. status .. " (" .. ident .. ")")

status = oms2_deleteConnection("api_test02", "System1:a", "System2:a")
print("status code: " .. status)
status = oms2_deleteConnection("api_test02", "System1:s", "System2:s")
print("status code: " .. status)
status = oms2_deleteConnection("api_test02", "System1:F", "System2:F")
print("status code: " .. status)
status = oms2_deleteConnection("api_test02", "System1:v", "System2:v")
print("status code: " .. status)

status, source2 = oms2_listModel("api_test02")
print("status code: " .. status)

status = oms2_unloadModel("api_test02")
print("status code: " .. status)

print(source1)
print(source2)

-- Result:
-- status code: 0
-- status code: 0
-- status code: 0
-- status code: 0
-- status code: 0
-- status code: 0
-- status code: 0
-- status code: 0
-- status code: 0
-- status code: 0
-- status code: 0
-- status code: 0 (api_test02)
-- status code: 0
-- status code: 0
-- status code: 0
-- status code: 0
-- status code: 0
-- status code: 0
-- <?xml version="1.0" encoding="UTF-8"?>
-- <ssd:SystemStructureDescription name="api_test02" version="Draft20171219">
-- 	<ssd:System name="api_test02">
-- 		<ssd:Component name="System1" type="application/x-fmu-sharedlibrary" source="../FMUs/DualMassOscillator.System1_me.fmu">
-- 			<ssd:Connectors>
-- 				<ssd:Connector name="F" kind="input" type="Real">
-- 					<ssd:ConnectorGeometry x="0.000000" y="0.500000" />
-- 				</ssd:Connector>
-- 				<ssd:Connector name="a" kind="output" type="Real">
-- 					<ssd:ConnectorGeometry x="1.000000" y="0.250000" />
-- 				</ssd:Connector>
-- 				<ssd:Connector name="s" kind="output" type="Real">
-- 					<ssd:ConnectorGeometry x="1.000000" y="0.500000" />
-- 				</ssd:Connector>
-- 				<ssd:Connector name="v" kind="output" type="Real">
-- 					<ssd:ConnectorGeometry x="1.000000" y="0.750000" />
-- 				</ssd:Connector>
-- 			</ssd:Connectors>
-- 		</ssd:Component>
-- 		<ssd:Component name="System2" type="application/x-fmu-sharedlibrary" source="../FMUs/DualMassOscillator.System2_me.fmu">
-- 			<ssd:Connectors>
-- 				<ssd:Connector name="a" kind="input" type="Real">
-- 					<ssd:ConnectorGeometry x="0.000000" y="0.250000" />
-- 				</ssd:Connector>
-- 				<ssd:Connector name="s" kind="input" type="Real">
-- 					<ssd:ConnectorGeometry x="0.000000" y="0.500000" />
-- 				</ssd:Connector>
-- 				<ssd:Connector name="v" kind="input" type="Real">
-- 					<ssd:ConnectorGeometry x="0.000000" y="0.750000" />
-- 				</ssd:Connector>
-- 				<ssd:Connector name="F" kind="output" type="Real">
-- 					<ssd:ConnectorGeometry x="1.000000" y="0.500000" />
-- 				</ssd:Connector>
-- 			</ssd:Connectors>
-- 		</ssd:Component>
-- 		<ssd:Connections>
-- 			<ssd:Connection startElement="System2" startConnector="F" endElement="System1" endConnector="F" />
-- 			<ssd:Connection startElement="System1" startConnector="s" endElement="System2" endConnector="s" />
-- 			<ssd:Connection startElement="System1" startConnector="v" endElement="System2" endConnector="v" />
-- 			<ssd:Connection startElement="System1" startConnector="a" endElement="System2" endConnector="a" />
-- 		</ssd:Connections>
-- 	</ssd:System>
-- 	<ssd:DefaultExperiment startTime="0.000000" stopTime="1.000000" />
-- </ssd:SystemStructureDescription>
--
-- <?xml version="1.0" encoding="UTF-8"?>
-- <ssd:SystemStructureDescription name="api_test02" version="Draft20171219">
-- 	<ssd:System name="api_test02">
-- 		<ssd:Component name="System1" type="application/x-fmu-sharedlibrary" source="../FMUs/DualMassOscillator.System1_me.fmu">
-- 			<ssd:Connectors>
-- 				<ssd:Connector name="F" kind="input" type="Real">
-- 					<ssd:ConnectorGeometry x="0.000000" y="0.500000" />
-- 				</ssd:Connector>
-- 				<ssd:Connector name="a" kind="output" type="Real">
-- 					<ssd:ConnectorGeometry x="1.000000" y="0.250000" />
-- 				</ssd:Connector>
-- 				<ssd:Connector name="s" kind="output" type="Real">
-- 					<ssd:ConnectorGeometry x="1.000000" y="0.500000" />
-- 				</ssd:Connector>
-- 				<ssd:Connector name="v" kind="output" type="Real">
-- 					<ssd:ConnectorGeometry x="1.000000" y="0.750000" />
-- 				</ssd:Connector>
-- 			</ssd:Connectors>
-- 		</ssd:Component>
-- 		<ssd:Component name="System2" type="application/x-fmu-sharedlibrary" source="../FMUs/DualMassOscillator.System2_me.fmu">
-- 			<ssd:Connectors>
-- 				<ssd:Connector name="a" kind="input" type="Real">
-- 					<ssd:ConnectorGeometry x="0.000000" y="0.250000" />
-- 				</ssd:Connector>
-- 				<ssd:Connector name="s" kind="input" type="Real">
-- 					<ssd:ConnectorGeometry x="0.000000" y="0.500000" />
-- 				</ssd:Connector>
-- 				<ssd:Connector name="v" kind="input" type="Real">
-- 					<ssd:ConnectorGeometry x="0.000000" y="0.750000" />
-- 				</ssd:Connector>
-- 				<ssd:Connector name="F" kind="output" type="Real">
-- 					<ssd:ConnectorGeometry x="1.000000" y="0.500000" />
-- 				</ssd:Connector>
-- 			</ssd:Connectors>
-- 		</ssd:Component>
-- 		<ssd:Connections />
-- 	</ssd:System>
-- 	<ssd:DefaultExperiment startTime="0.000000" stopTime="1.000000" />
-- </ssd:SystemStructureDescription>
--
-- info:    Logging information has been saved to "api-test02.log"
-- endResult
