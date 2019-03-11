## status: correct
## teardown_command: rm DualMassOscillator_cs.log DualMassOscillator_cs.mat

from OMSimulator import OMSimulator
session = OMSimulator()

session.setLogFile("DualMassOscillator_cs.log")

session.newFMIModel("DualMassOscillator")
session.setTempDirectory("./DualMassOscillator_cs_tmp")

# instantiate FMUs
session.addFMU("DualMassOscillator", "../FMUs/DualMassOscillator.System1_cs.fmu", "System1")
session.addFMU("DualMassOscillator", "../FMUs/DualMassOscillator.System2_cs.fmu", "System2")

# add connections
session.addConnection("DualMassOscillator", "System1:F", "System2:F")
session.addConnection("DualMassOscillator", "System1:s", "System2:s")
session.addConnection("DualMassOscillator", "System1:v", "System2:v")
session.addConnection("DualMassOscillator", "System1:a", "System2:a")

session.setResultFile("DualMassOscillator", "DualMassOscillator_cs.mat")

session.setStopTime("DualMassOscillator", 0.1)
session.setCommunicationInterval("DualMassOscillator", 1e-5)

session.initialize("DualMassOscillator")
session.simulate("DualMassOscillator")

(_, tcur) = session.getCurrentTime("DualMassOscillator")
vars = ["DualMassOscillator.System1:mass1.s", "DualMassOscillator.System2:mass2.s"]
for var in vars:
  (_, value) = session.getReal(var)
  print('{0} at {1}: {2}'.format(var, tcur, value))

session.unloadModel("DualMassOscillator")

## Result:
## DualMassOscillator.System1:mass1.s at 0.1: -0.437361150714
## DualMassOscillator.System2:mass2.s at 0.1: -0.284406319121
## info:    Logging information has been saved to "DualMassOscillator_cs.log"
## info:    3 warnings
## info:    0 errors
## endResult
