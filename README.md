# Adaptive step size control for OMSimulator

This repository is forked from [OpenModelica/OMSimulator](https://github.com/OpenModelica/OMSimulator) with the goal of extending it with additive step size control for efficient and precise simulation.

## Simulation and step size control

The OMSimulator project is a FMI-based co-simulation environment that supports ordinary (i.e., non-delayed) and TLM connections.

OMSimulator co-simulates FMUs by iteratively making the FMUs do a step (calculate the values of the variables for a given point in time) and then exchanging messages - with a fixed communication interval. When the step size (communication interval) is too big the simulation might be inaccurate and might miss important events. On the other hand, simulating with a smaller step size is inefficient. 

A good compromise between efficiency and accuracy is to adapt the step size: when it is more important to be accurate (e.g. when the value of an important variable is getting close to a critical amount) the step size can be decreased (to make sure that the critical situation is simulated accurately) but when the critical situation is over (when the value of the variable is far from critical level) it can be increased again.

## Working with the repository

This repository is forked from [OpenModelica/OMSimulator](https://github.com/OpenModelica/OMSimulator) and synchronized according to the [GitHub recommendation](https://help.github.com/articles/syncing-a-fork/).

Clone the project using the `--recursive` flag then follow the instructions of the original repository for building and installing OMSimulator. The step size controller is currently implemented in lua and you can find case studies in the _StepSizeController_ folder.

## Working with the step size controller

The adaptive step size controller is the file _StepSizeController.lua_ located in the _StepSizeController_ folder. To use it just import the file.

```lua
package.path = package.path .. ";path/to/StepSizeController/StepSizeController.lua"
require("StepSizeController")
```

After this you can use the `oms2_simulateWithASSC` function that takes four parameters:
* _model_ denotes the model to simulate
* _communicationInterval_ denotes the _default_ communication interval (when there is no need to decrease it)
* _sensitivityModel_ is an instance of the `SensitivityModel` class. It allows the user to describe two types of sensitivities (scenarios when the step size should be adjusted):
  * The _events_ attribute should contain the set of output variables representing ocurrences of dicrete events (the type of the variables should also be specified). The step size controller detects a discrete event if any of the variables changes its value, and adjust the step size to the minimal value so that the chains of synchronized events can be simulated quickly. The step size will be adjusted back when no more events are detected.
  * The _zeroCrossings_ attribute should contain a collection mapping variables to instances of the class `BandModel`, which can determine an upper bound on the next step size based on the current value of the given variable.
* _imin_ denotes the minimum size of the steps (this value will be used when an event is detected)
* _tmax_ denotes the end of the simulation

Examples can be found in the _StepSizeController/Thermostat_ folder.

This is a preliminary step size controller written in lua. It can be integrated to the OMSimulator.

## Advantages of the Step size controller

The step size controller allows the un-eventful parts of the simulation to be performed quickly, yet the critical parts precisely. Usefulness in case of threshold-crossing detection was measured: accuracy and efficiency was measured for constant step size simulation (with different step sizes varying from 0.01 to 10.0) and simulation with adaptive step sizes. The results can be seen in the _StepSizeController/Thermostat_ folder.
