## status: correct
## teardown_command: rm RealNetwork1.log RealNetwork1.mat

from OMSimulator import OMSimulator

oms = OMSimulator()

oms.setLogFile("RealNetwork1.log")

oms.newFMIModel("RealNetwork1")
oms.setTempDirectory("./RealNetwork1_tmp")

# instantiate FMUs
oms.addFMU("RealNetwork1", "../FMUs/Modelica.Blocks.Math.Add.fmu", "add")
oms.addFMU("RealNetwork1", "../FMUs/Modelica.Blocks.Math.Feedback.fmu", "feedback")
oms.addFMU("RealNetwork1", "../FMUs/Modelica.Blocks.Math.Gain.fmu", "gain")
oms.addFMU("RealNetwork1", "../FMUs/Modelica.Blocks.Math.Product.fmu", "product")
oms.addFMU("RealNetwork1", "../FMUs/Modelica.Blocks.Sources.Clock.fmu", "clock")
oms.addFMU("RealNetwork1", "../FMUs/Modelica.Blocks.Sources.Constant.fmu", "constant")
oms.addFMU("RealNetwork1", "../FMUs/Modelica.Blocks.Sources.Sine.fmu", "sine")
oms.addFMU("RealNetwork1", "../FMUs/Modelica.Blocks.Sources.Step.fmu", "step")

# add connections
oms.addConnection("RealNetwork1", "clock:y", "product:u1")
oms.addConnection("RealNetwork1", "constant:y", "add:u2")
oms.addConnection("RealNetwork1", "feedback:y", "add:u1")
oms.addConnection("RealNetwork1", "gain:y", "feedback:u1")
oms.addConnection("RealNetwork1", "product:y", "gain:u")
oms.addConnection("RealNetwork1", "sine:y", "feedback:u2")
oms.addConnection("RealNetwork1", "step:y", "product:u2")

# parameters
oms.setReal("RealNetwork1.clock:offset", 0.0)
oms.setReal("RealNetwork1.clock:startTime", 0.0)
oms.setReal("RealNetwork1.step:height", 3.0)
oms.setReal("RealNetwork1.step:offset", 1.0)
oms.setReal("RealNetwork1.step:startTime", 3.0)
oms.setReal("RealNetwork1.gain:k", 1e-1)
oms.setReal("RealNetwork1.sine:amplitude", 1.0)
oms.setReal("RealNetwork1.sine:freqHz", 1.0)
oms.setReal("RealNetwork1.sine:phase", 0.0)
oms.setReal("RealNetwork1.sine:offset", 0.0)
oms.setReal("RealNetwork1.sine:startTime", 2.0)
oms.setReal("RealNetwork1.constant:k", -3.0)
oms.setReal("RealNetwork1.add:k1", 2.0)
oms.setReal("RealNetwork1.add:k2", 1.0)

# simulation settings
oms.setResultFile("RealNetwork1", "RealNetwork1.mat")
oms.setStopTime("RealNetwork1", 10.0)

oms.initialize("RealNetwork1")
oms.simulate("RealNetwork1")

oms.unloadModel("RealNetwork1")

signals = ["add.y", "feedback.y", "gain.y", "step.y"]
for signal in signals:
  if (1 == oms.compareSimulationResults("RealNetwork1.mat", "../ReferenceFiles/RealNetwork1.mat", signal, 1e-2, 1e-4)):
    print(signal + " is equal")
  else:
    print(signal + " is not equal")

## Result:
## add.y is equal
## feedback.y is equal
## gain.y is equal
## step.y is equal
## info:    Logging information has been saved to "RealNetwork1.log"
## info:    8 warnings
## info:    0 errors
## endResult
