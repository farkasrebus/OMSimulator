# Adaptive step size control for OMSimulator

This repository is forked from [OpenModelica/OMSimulator](https://github.com/OpenModelica/OMSimulator) with the goal of extending it with additive step size control for efficient and precise simulation.

## Simulation and step size control

The OMSimulator project is a FMI-based co-simulation environment that supports ordinary (i.e., non-delayed) and TLM connections.

OMSimulator co-simulates FMUs by iteratively making the FMUs do a step (calculate the values of the variables for a given point in time) and then exchanging messages - with a fixed communication interval. When the step size (communication interval) is too big the simulation might be inaccurate and might miss important events. On the other hand, simulating with a smaller step size is inefficient. 

A good compromise between efficiency and accuracy is to adapt the step size: when it is more important to be accurate (e.g. when the value of an important variable is getting close to a critical amount) the step size can be decreased (to make sure that the critical situation is simulated accurately) but when the critical situation is over (when the value of the variable is far from critical level) it can be increased again.

## Working with the repository

This repository is forked from [OpenModelica/OMSimulator](https://github.com/OpenModelica/OMSimulator) and synchronized according to the [GitHub recommendation](https://help.github.com/articles/syncing-a-fork/).

Clone the project using the `--recursive` flag then follow the instructions of the original repository for building and installing OMSimulator. The step size controller is currently implemented in lua and you can find a case study in the _StepSizeController/CaseStudy_ folder.

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
  * The _events_ attribute should contain the set of output variables representing ocurrences of dicrete events. The step size controller detects a discrete event if any of the variables changes its value, and adjust the step size to the minimal value so that the chains of synchronized events can be simulated quickly. The step size will be adjusted back when no more events are detected.
  * The _zeroCrossings_ attribute should contain a map from a variable to a funtion that takes the current value of the variable and returns an upper bound for the size of the next step.
* _imin_ denotes the minimum size of the steps (this value will be used when an event is detected)
* _tmax_ denotes the end of the simulation

An example can be found in the _StepSizeController/EventChainSimple_ folder called _ECwithSSC.lua_.

This is a preliminary step size controller written in lua. It will be integrated to the OMSimulator.
