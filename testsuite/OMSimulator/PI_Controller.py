## status: correct
## teardown_command: rm PI_Controller.log  PI_Controller.mat PI_Controller*.dot

from OMSimulator import OMSimulator
session = OMSimulator()

session.setLogFile("PI_Controller.log")
session.setTempDirectory("./PI_Controller_tmp")

session.newFMIModel("PI_Controller")

# instantiate FMUs
session.addFMU("PI_Controller", "../FMUs/Modelica.Blocks.Math.Add.fmu", "addP")
session.addFMU("PI_Controller", "../FMUs/Modelica.Blocks.Math.Gain.fmu", "P")
session.addFMU("PI_Controller", "../FMUs/Modelica.Blocks.Math.Add3.fmu", "addI")
session.addFMU("PI_Controller", "../FMUs/Modelica.Blocks.Continuous.Integrator.fmu", "I")
session.addFMU("PI_Controller", "../FMUs/Modelica.Blocks.Math.Add.fmu", "addPI")
session.addFMU("PI_Controller", "../FMUs/Modelica.Blocks.Math.Gain.fmu", "gainPI")
session.addFMU("PI_Controller", "../FMUs/Modelica.Blocks.Nonlinear.Limiter.fmu", "limiter")
session.addFMU("PI_Controller", "../FMUs/Modelica.Blocks.Math.Add.fmu", "addSat")
session.addFMU("PI_Controller", "../FMUs/Modelica.Blocks.Math.Gain.fmu", "gainTrack")

# add connections
session.addConnection("PI_Controller", "addP:y", "P:u")
session.addConnection("PI_Controller", "addI:y", "I:u")
session.addConnection("PI_Controller", "P:y", "addPI:u1")
session.addConnection("PI_Controller", "I:y", "addPI:u2")
session.addConnection("PI_Controller", "addPI:y", "gainPI:u")
session.addConnection("PI_Controller", "gainPI:y", "limiter:u")
session.addConnection("PI_Controller", "gainPI:y", "addSat:u2")
session.addConnection("PI_Controller", "limiter:y", "addSat:u1")
session.addConnection("PI_Controller", "addSat:y", "gainTrack:u")
session.addConnection("PI_Controller", "gainTrack:y", "addI:u3")

# parameters
k = 100.0
yMax = 12.0
yMin = -yMax
wp = 1.0
Ni = 0.1
xi_start = 0.0

# set parameters
session.setReal("PI_Controller.addP:k1", wp)
session.setReal("PI_Controller.addP:k2", -1.0)
session.setReal("PI_Controller.addI:k2", -1.0)
session.setReal("PI_Controller.I:y_start", xi_start)
session.setReal("PI_Controller.gainPI:k", k)
session.setReal("PI_Controller.limiter:uMax", yMax)
session.setReal("PI_Controller.addSat:k2", -1.0)
session.setReal("PI_Controller.gainTrack:k", 1.0/(k*Ni))

# simulation settings
session.setStopTime("PI_Controller", 4.0)
session.setCommunicationInterval("PI_Controller", 1e-4)

session.exportCompositeStructure("PI_Controller", "PI_Controller.dot")
session.exportDependencyGraphs("PI_Controller", "PI_Controller_simulation.dot", "PI_Controller_initialization.dot")
#gvpr -c "N[$.degree==0]{delete(root, $)}" PI_Controller_simulation.dot | dot -Tpdf -o PI_Controller_simulation.pdf
#gvpr -c "N[$.degree==0]{delete(root, $)}" PI_Controller_initialization.dot | dot -Tpdf -o PI_Controller_initialization.pdf
#dot -Gsplines=none PI_Controller.dot | neato -n -Gsplines=ortho -Tpdf -oPI_Controller.pdf

# instantiate lookup table
session.addTable("PI_Controller", "setpoint.csv", "setpoint")
session.addTable("PI_Controller", "drivetrain.csv", "driveTrain")

# add connections
session.addConnection("PI_Controller", "setpoint:speed", "addP:u1")
session.addConnection("PI_Controller", "setpoint:speed", "addI:u1")

session.addConnection("PI_Controller", "driveTrain:w", "addP:u2")
session.addConnection("PI_Controller", "driveTrain:w", "addI:u2")

# simulation settings
session.setResultFile("PI_Controller", "PI_Controller.mat")

# simulation
print("info:    Initialization")
session.initialize("PI_Controller")
print("info:      limiter.u: " + str(session.getReal("PI_Controller.limiter:u")[1]))
print("info:      limiter.y: " + str(session.getReal("PI_Controller.limiter:y")[1]))

print("info:    Simulation")
session.simulate("PI_Controller")
print("info:      limiter.u: " + str(session.getReal("PI_Controller.limiter:u")[1]))
print("info:      limiter.y: " + str(session.getReal("PI_Controller.limiter:y")[1]))

session.unloadModel("PI_Controller")

vars = ["limiter.u", "limiter.y"]
for var in vars:
  if (1 == session.compareSimulationResults("PI_Controller.mat", "../ReferenceFiles/PI_Controller.mat", var, 1e-2, 1e-4)):
    print("info:    " + var + " is equal")
  else:
    print("error:   " + var + " is not equal")

## Result:
## info:    Initialization
## info:      limiter.u: 0.0
## info:      limiter.y: 0.0
## info:    Simulation
## info:      limiter.u: -10.0145088937
## info:      limiter.y: -10.0145088937
## info:    limiter.u is equal
## info:    limiter.y is equal
## info:    Logging information has been saved to "PI_Controller.log"
## info:    9 warnings
## info:    0 errors
## endResult
