## status: correct
## teardown_command: rm -rf externalmodels-py
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

status = session.oms3_setTempDirectory("./externalmodels-py/")
printStatus(status, 0)

status = session.oms3_newModel("model")
printStatus(status, 0)

status = session.oms3_addSystem("model.tlm", session.oms_system_tlm)
printStatus(status, 0)

status = session.oms3_addExternalModel("model.tlm.external", "resources/external.mo", "resources/startscript.sh")
printStatus(status, 0)

status = session.oms3_addTLMBus("model.tlm.external.tlmbus", "mechanical", 1, session.default)

status, src = session.oms3_list("model.tlm")
print(src)

status = session.oms3_delete("model")
printStatus(status, 0)

## Result:
## status:  [correct] ok
## status:  [correct] ok
## status:  [correct] ok
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
## 		<ssd:Component name="external" source="resources/external.mo">
## 			<ssd:Annotations>
## 				<ssd:Annotation type="org.openmodelica">
## 					<oms:Bus name="tlmbus" type="tlm" domain="mechanical" dimensions="1" interpolation="none">
## 						<oms:Signals />
## 					</oms:Bus>
## 				</ssd:Annotation>
## 			</ssd:Annotations>
## 			<ssd:SimulationInformation>
## 				<ssd:Annotations>
## 					<ssd:Annotation type="org.openmodelica">
## 						<oms:ExternalModel startscript="resources/startscript.sh" />
## 					</ssd:Annotation>
## 				</ssd:Annotations>
## 			</ssd:SimulationInformation>
## 		</ssd:Component>
## 	</ssd:Elements>
## 	<ssd:Connectors />
## 	<ssd:Connections />
## </ssd:System>
##
## status:  [correct] ok
## endResult
