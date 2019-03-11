-- status: correct
-- teardown_command: rm -rf api-test03.log api_test03.xml api-test03_tmp

oms2_setLogFile("api-test03.log")

status = oms2_setTempDirectory("./api-test03_tmp")
print("status code: " .. status)

status = oms2_newFMIModel("api_test03")
print("status code: " .. status)

-- add FMUs
status = oms2_addFMU("api_test03", "../FMUs/DualMassOscillator.System1_me.fmu", "System1")
print("status code: " .. status)
status = oms2_addFMU("api_test03", "../FMUs/DualMassOscillator.System2_me.fmu", "System2")
print("status code: " .. status)

-- add connections
status = oms2_addConnection("api_test03", "System1:F", "System2:F")
print("status code: " .. status)
status = oms2_addConnection("api_test03", "System1:s", "System2:s")
print("status code: " .. status)
status = oms2_addConnection("api_test03", "System1:v", "System2:v")
print("status code: " .. status)
status = oms2_addConnection("api_test03", "System1:a", "System2:a")
print("status code: " .. status)

-- delete FMU
status = oms2_deleteSubModel("api_test03", "System1")
print("status code: " .. status)
status = oms2_deleteSubModel("api_test03", "System1")
print("status code: " .. status)

status, source = oms2_listModel("api_test03")
print("status code: " .. status)

status = oms2_unloadModel("api_test03")
print("status code: " .. status)

print(source)

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
-- status code: 3
-- status code: 0
-- status code: 0
-- <?xml version="1.0" encoding="UTF-8"?>
-- <ssd:SystemStructureDescription name="api_test03" version="Draft20171219">
-- 	<ssd:System name="api_test03">
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
-- info:    Logging information has been saved to "api-test03.log"
-- info:    0 warnings
-- info:    1 errors
-- endResult
