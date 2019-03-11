## status: correct
## teardown_command: rm -rf test01-py/
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

status = session.oms3_setTempDirectory("./test01-py/")
printStatus(status, 0)

status = session.oms3_newModel("test")
printStatus(status, 0)

status = session.oms3_addSystem("test", session.oms_system_tlm)
printStatus(status, 3)

status = session.oms3_addSystem("test.foo", session.oms_system_wc)
printStatus(status, 0)

status = session.oms3_addSystem("test.foo.goo", session.oms_system_sc)
printStatus(status, 0)

status = session.oms3_addSystem("test.foo.hoo", session.oms_system_wc)
printStatus(status, 3)

status, src = session.oms3_list("test")
print(src)

status, src = session.oms3_list("test.foo")
print(src)

status, src = session.oms3_list("test.foo.goo")
print(src)

status = session.oms3_newModel("test")
printStatus(status, 3)

status = session.oms3_rename("test", "foo")
printStatus(status, 0)

status = session.oms3_newModel("test")
printStatus(status, 0)

status = session.oms3_delete("test")
printStatus(status, 0)

status = session.oms3_delete("foo")
printStatus(status, 0)

status = session.oms3_newModel("test")
printStatus(status, 0)

status, src = session.oms3_list("test")
print(src)

status = session.oms3_delete("test")
printStatus(status, 0)

status = session.oms3_delete("foo")
printStatus(status, 3)

## Result:
## status:  [correct] ok
## status:  [correct] ok
## error:   [addSystem] Model "test" does not contain any system
## status:  [correct] error
## status:  [correct] ok
## status:  [correct] ok
## error:   [NewSystem] A WC system must be the root system or a subsystem of a TLM system.
## status:  [correct] error
## <?xml version="1.0"?>
## <ssd:SystemStructureDescription name="test" version="Draft20180219">
## 	<ssd:System name="foo">
## 		<ssd:SimulationInformation>
## 			<FixedStepMaster description="oms-ma" stepSize="0.100000" />
## 		</ssd:SimulationInformation>
## 		<ssd:Elements>
## 			<ssd:System name="goo">
## 				<ssd:SimulationInformation>
## 					<VariableStepSolver description="cvode" absoluteTolerance="0.000100" relativeTolerance="0.000100" minimumStepSize="0.000100" maximumStepSize="0.100000" initialStepSize="0.000100" />
## 				</ssd:SimulationInformation>
## 				<ssd:Elements />
## 				<ssd:Connectors />
## 				<ssd:Connections />
## 			</ssd:System>
## 		</ssd:Elements>
## 		<ssd:Connectors />
## 		<ssd:Connections />
## 	</ssd:System>
## 	<ssd:DefaultExperiment startTime="0.000000" stopTime="1.000000" />
## </ssd:SystemStructureDescription>
##
## <?xml version="1.0"?>
## <ssd:System name="foo">
## 	<ssd:SimulationInformation>
## 		<FixedStepMaster description="oms-ma" stepSize="0.100000" />
## 	</ssd:SimulationInformation>
## 	<ssd:Elements>
## 		<ssd:System name="goo">
## 			<ssd:SimulationInformation>
## 				<VariableStepSolver description="cvode" absoluteTolerance="0.000100" relativeTolerance="0.000100" minimumStepSize="0.000100" maximumStepSize="0.100000" initialStepSize="0.000100" />
## 			</ssd:SimulationInformation>
## 			<ssd:Elements />
## 			<ssd:Connectors />
## 			<ssd:Connections />
## 		</ssd:System>
## 	</ssd:Elements>
## 	<ssd:Connectors />
## 	<ssd:Connections />
## </ssd:System>
##
## <?xml version="1.0"?>
## <ssd:System name="goo">
## 	<ssd:SimulationInformation>
## 		<VariableStepSolver description="cvode" absoluteTolerance="0.000100" relativeTolerance="0.000100" minimumStepSize="0.000100" maximumStepSize="0.100000" initialStepSize="0.000100" />
## 	</ssd:SimulationInformation>
## 	<ssd:Elements />
## 	<ssd:Connectors />
## 	<ssd:Connections />
## </ssd:System>
##
## error:   [newModel] "test" already exists in the scope
## status:  [correct] error
## status:  [correct] ok
## status:  [correct] ok
## status:  [correct] ok
## status:  [correct] ok
## status:  [correct] ok
## <?xml version="1.0"?>
## <ssd:SystemStructureDescription name="test" version="Draft20180219">
## 	<ssd:DefaultExperiment startTime="0.000000" stopTime="1.000000" />
## </ssd:SystemStructureDescription>
##
## status:  [correct] ok
## error:   [oms3_delete] Model "foo" does not exist in the scope
## status:  [correct] error
## info:    0 warnings
## info:    4 errors
## endResult
