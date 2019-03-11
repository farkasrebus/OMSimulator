## status: correct
## teardown_command: rm -rf test02-py/
## linux: yes
## mingw: yes
## win: no
## mac: no

from OMSimulator import OMSimulator
session=OMSimulator()

session.oms3_setCommandLineOption("--suppressPath=true")
session.oms3_setTempDirectory("./test02-py/")

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

def printType(t):
  if session.oms_system_tlm == t:
    print "type: oms_system_tlm"
  elif session.oms_system_wc == t:
    print "type: oms_system_wc"
  elif session.oms_system_sc == t:
    print "type: oms_system_sc"
  else:
    print "Unknown type"

status = session.oms3_newModel("test")
printStatus(status, 0)

status = session.oms3_addSystem("test.eoo", session.oms_system_tlm)
printStatus(status, 0)

status = session.oms3_addSystem("test.eoo.foo", session.oms_system_wc)
printStatus(status, 0)

status = session.oms3_addSystem("test.eoo.foo.goo", session.oms_system_sc)
printStatus(status, 0)

status, type = session.oms3_getSystemType("test")
printType(type)
printStatus(status, 3)

status, type = session.oms3_getSystemType("test.eoo")
printType(type)
printStatus(status, 0)

status, type = session.oms3_getSystemType("test.eoo.foo")
printType(type)
printStatus(status, 0)

status, type = session.oms3_getSystemType("test.eoo.foo.goo")
printType(type)
printStatus(status, 0)

status = session.oms3_delete("test")
printStatus(status, 0)

## Result:
## status:  [correct] ok
## status:  [correct] ok
## status:  [correct] ok
## status:  [correct] ok
## error:   [oms3_getSystemType] Model "test" does not contain system ""
## Unknown type
## status:  [correct] error
## type: oms_system_tlm
## status:  [correct] ok
## type: oms_system_wc
## status:  [correct] ok
## type: oms_system_sc
## status:  [correct] ok
## status:  [correct] ok
## info:    0 warnings
## info:    1 errors
## endResult
