-- status: correct
-- teardown_command: rm -rf simulation-lua/ test_init.dot test_sim.dot
-- linux: yes
-- mingw: no
-- win: no
-- mac: no

oms3_setCommandLineOption("--suppressPath=true")
oms3_setTempDirectory("./simulation-lua/")

function printStatus(status, expected)
  cmp = ""
  if status == expected then
    cmp = "correct"
  else
    cmp = "wrong"
  end

  if 0 == status then
    status = "ok"
  elseif 1 == status then
    status = "warning"
  elseif 3 == status then
    status = "error"
  end
  print("status:  [" .. cmp .. "] " .. status)
end

status = oms3_newModel("test")
printStatus(status, 0)

status = oms3_addSystem("test.co_sim", oms_system_wc)
printStatus(status, 0)

status = oms3_addSubModel("test.co_sim.A", "../FMUs/source.fmu")
printStatus(status, 0)

status = oms3_addSubModel("test.co_sim.B", "../FMUs/source.fmu")
printStatus(status, 0)

oms3_exportDependencyGraphs("test.co_sim", "test_init.dot", "test_sim.dot")

status = oms3_instantiate("test")
printStatus(status, 0)

v, status = oms3_getReal("test.co_sim.A.A")
printStatus(status, 0)
print("test.co_sim.A.A: " .. v)

status = oms3_setReal("test.co_sim.A.A", v + 1.0)
printStatus(status, 0)

v, status = oms3_getReal("test.co_sim.A.A")
printStatus(status, 0)
print("test.co_sim.A.A: " .. v)

status = oms3_initialize("test")
printStatus(status, 0)

v, status = oms3_getReal("test.co_sim.A.y")
printStatus(status, 0)
print("test.co_sim.A.y: " .. v)

status = oms3_simulate("test")
printStatus(status, 0)

v, status = oms3_getReal("test.co_sim.A.y")
printStatus(status, 0)
print("test.co_sim.A.y: " .. v)

status = oms3_terminate("test")
printStatus(status, 0)

status = oms3_delete("test")
printStatus(status, 0)

-- Result:
-- status:  [correct] ok
-- status:  [correct] ok
-- status:  [correct] ok
-- status:  [correct] ok
-- status:  [correct] ok
-- status:  [correct] ok
-- test.co_sim.A.A: 1.0
-- status:  [correct] ok
-- status:  [correct] ok
-- test.co_sim.A.A: 2.0
-- info:    Result file: test_res.mat (bufferSize=10)
-- status:  [correct] ok
-- status:  [correct] ok
-- test.co_sim.A.y: 0.0
-- status:  [correct] ok
-- status:  [correct] ok
-- test.co_sim.A.y: 1.6829419696158
-- status:  [correct] ok
-- status:  [correct] ok
-- endResult
