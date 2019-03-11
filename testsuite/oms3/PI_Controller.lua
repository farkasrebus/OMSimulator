-- status: correct
-- teardown_command: rm -rf PI_Controller-lua/ PI_Controller_init.dot PI_Controller_sim.dot PI_Controller_res.mat PI_Controller.ssp
-- linux: yes
-- mingw: no
-- win: no
-- mac: no

oms3_setCommandLineOption("--suppressPath=true")
oms3_setTempDirectory("./PI_Controller-lua/")

oms3_newModel("PI_Controller")
oms3_addSystem("PI_Controller.co_sim", oms_system_wc)

-- instantiate FMUs
oms3_addSubModel("PI_Controller.co_sim.addP", "../FMUs/Modelica.Blocks.Math.Add.fmu")
oms3_addSubModel("PI_Controller.co_sim.P", "../FMUs/Modelica.Blocks.Math.Gain.fmu")
oms3_addSubModel("PI_Controller.co_sim.addI", "../FMUs/Modelica.Blocks.Math.Add3.fmu")
oms3_addSubModel("PI_Controller.co_sim.I", "../FMUs/Modelica.Blocks.Continuous.Integrator.fmu")
oms3_addSubModel("PI_Controller.co_sim.addPI", "../FMUs/Modelica.Blocks.Math.Add.fmu")
oms3_addSubModel("PI_Controller.co_sim.gainPI", "../FMUs/Modelica.Blocks.Math.Gain.fmu")
oms3_addSubModel("PI_Controller.co_sim.limiter", "../FMUs/Modelica.Blocks.Nonlinear.Limiter.fmu")
oms3_addSubModel("PI_Controller.co_sim.addSat", "../FMUs/Modelica.Blocks.Math.Add.fmu")
oms3_addSubModel("PI_Controller.co_sim.gainTrack", "../FMUs/Modelica.Blocks.Math.Gain.fmu")

-- add connections
oms3_addConnection("PI_Controller.co_sim.addP.y", "PI_Controller.co_sim.P.u")
oms3_addConnection("PI_Controller.co_sim.addI.y", "PI_Controller.co_sim.I.u")
oms3_addConnection("PI_Controller.co_sim.P.y", "PI_Controller.co_sim.addPI.u1")
oms3_addConnection("PI_Controller.co_sim.I.y", "PI_Controller.co_sim.addPI.u2")
oms3_addConnection("PI_Controller.co_sim.addPI.y", "PI_Controller.co_sim.gainPI.u")
oms3_addConnection("PI_Controller.co_sim.gainPI.y", "PI_Controller.co_sim.limiter.u")
oms3_addConnection("PI_Controller.co_sim.gainPI.y", "PI_Controller.co_sim.addSat.u2")
oms3_addConnection("PI_Controller.co_sim.limiter.y", "PI_Controller.co_sim.addSat.u1")
oms3_addConnection("PI_Controller.co_sim.addSat.y", "PI_Controller.co_sim.gainTrack.u")
oms3_addConnection("PI_Controller.co_sim.gainTrack.y", "PI_Controller.co_sim.addI.u3")

-- instantiate lookup table
oms3_addSubModel("PI_Controller.co_sim.setpoint", "setpoint.csv")
oms3_addSubModel("PI_Controller.co_sim.driveTrain", "drivetrain.csv")

-- add connections
oms3_addConnection("PI_Controller.co_sim.setpoint.speed", "PI_Controller.co_sim.addP.u1")
oms3_addConnection("PI_Controller.co_sim.setpoint.speed", "PI_Controller.co_sim.addI.u1")
oms3_addConnection("PI_Controller.co_sim.driveTrain.w", "PI_Controller.co_sim.addP.u2")
oms3_addConnection("PI_Controller.co_sim.driveTrain.w", "PI_Controller.co_sim.addI.u2")

-- add connectors
oms3_addConnector("PI_Controller.co_sim.speed", output, oms_signal_type_real)
oms3_addConnection("PI_Controller.co_sim.setpoint.speed", "PI_Controller.co_sim.speed")

-- simulation settings
oms3_setStartTime("PI_Controller", 0.0)
oms3_setStopTime("PI_Controller", 4.0)
oms3_setFixedStepSize("PI_Controller.co_sim", 1e-3)
oms3_setResultFile("PI_Controller", "PI_Controller.mat", 100)

oms3_exportDependencyGraphs("PI_Controller.co_sim", "PI_Controller_init.dot", "PI_Controller_sim.dot")
--os.execute("gvpr -c \"N[$.degree==0]{delete(root, $)}\" PI_Controller_init.dot | dot -Tpdf -o PI_Controller_init.pdf")
--os.execute("gvpr -c \"N[$.degree==0]{delete(root, $)}\" PI_Controller_sim.dot | dot -Tpdf -o PI_Controller_sim.pdf")

oms3_export("PI_Controller", "PI_Controller.ssp");
oms3_delete("PI_Controller")
oms3_import("PI_Controller.ssp");

oms3_instantiate("PI_Controller")

-- set parameters
k = 100.0
yMax = 12.0
yMin = -yMax
wp = 1.0
Ni = 0.1
xi_start = 0.0
oms3_setReal("PI_Controller.co_sim.addP.k1", wp)
oms3_setReal("PI_Controller.co_sim.addP.k2", -1.0)
oms3_setReal("PI_Controller.co_sim.addI.k2", -1.0)
oms3_setReal("PI_Controller.co_sim.I.y_start", xi_start)
oms3_setReal("PI_Controller.co_sim.gainPI.k", k)
oms3_setReal("PI_Controller.co_sim.limiter.uMax", yMax)
oms3_setReal("PI_Controller.co_sim.addSat.k2", -1.0)
oms3_setReal("PI_Controller.co_sim.gainTrack.k", 1.0/(k*Ni))

print("info:    Parameter settings")
print("info:      PI_Controller.co_sim.addP.k1: " .. oms3_getReal("PI_Controller.co_sim.addP.k1"))
print("info:      PI_Controller.co_sim.addP.k2: " .. oms3_getReal("PI_Controller.co_sim.addP.k2"))
print("info:      PI_Controller.co_sim.addI.k2: " .. oms3_getReal("PI_Controller.co_sim.addI.k2"))
print("info:      PI_Controller.co_sim.I.y_start: " .. oms3_getReal("PI_Controller.co_sim.I.y_start"))
print("info:      PI_Controller.co_sim.gainPI.k: " .. oms3_getReal("PI_Controller.co_sim.gainPI.k"))
print("info:      PI_Controller.co_sim.limiter.uMax: " .. oms3_getReal("PI_Controller.co_sim.limiter.uMax"))
print("info:      PI_Controller.co_sim.addSat.k2: " .. oms3_getReal("PI_Controller.co_sim.addSat.k2"))
print("info:      PI_Controller.co_sim.gainTrack.k: " .. oms3_getReal("PI_Controller.co_sim.gainTrack.k"))

oms3_initialize("PI_Controller")
print("info:    Initialization")
print("info:      limiter.u: " .. oms3_getReal("PI_Controller.co_sim.limiter.u"))
print("info:      limiter.y: " .. oms3_getReal("PI_Controller.co_sim.limiter.y"))

oms3_simulate("PI_Controller")
print("info:    Simulation")
print("info:      limiter.u: " .. oms3_getReal("PI_Controller.co_sim.limiter.u"))
print("info:      limiter.y: " .. oms3_getReal("PI_Controller.co_sim.limiter.y"))

oms3_terminate("PI_Controller")
oms3_delete("PI_Controller")

-- Result:
-- info:    Parameter settings
-- info:      PI_Controller.co_sim.addP.k1: 1.0
-- info:      PI_Controller.co_sim.addP.k2: -1.0
-- info:      PI_Controller.co_sim.addI.k2: -1.0
-- info:      PI_Controller.co_sim.I.y_start: 0.0
-- info:      PI_Controller.co_sim.gainPI.k: 100.0
-- info:      PI_Controller.co_sim.limiter.uMax: 12.0
-- info:      PI_Controller.co_sim.addSat.k2: -1.0
-- info:      PI_Controller.co_sim.gainTrack.k: 0.1
-- info:    Result file: PI_Controller_res.mat (bufferSize=10)
-- info:    Initialization
-- info:      limiter.u: 0.0
-- info:      limiter.y: 0.0
-- info:    Simulation
-- info:      limiter.u: -10.041848601893
-- info:      limiter.y: -10.041848601893
-- endResult
