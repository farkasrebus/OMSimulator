-- status: correct
-- teardown_command: rm -rf api-test04.log api-test04_tmp

oms2_setLogFile("api-test04.log")

status = oms2_setTempDirectory("./api-test04_tmp")
print("oms2_setTempDirectory: " .. status)

status, ident = oms2_loadModel("api_test04.xml")
print("oms2_loadModel: " .. status .. " (" .. ident .. ")")

status = oms2_getElements(ident)
print("oms2_getElements: " .. status)

status = oms2_unloadModel(ident)
print("oms2_unloadModel: " .. status)

-- Result:
-- oms2_setTempDirectory: 0
-- oms2_loadModel: 0 (api_test04)
-- oms2_getElements: 0
-- oms2_unloadModel: 0
-- info:    Logging information has been saved to "api-test04.log"
-- endResult
