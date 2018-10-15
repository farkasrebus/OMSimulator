# Adaptive step size control for OMSimulator


This repository is forked from [OpenModelica/OMSimulator](https://github.com/OpenModelica/OMSimulator) with the goal of extending it with additive step size control for efficient and precise simulation.

## Simulation and step size control

The OMSimulator project is a FMI-based co-simulation environment that supports ordinary (i.e., non-delayed) and TLM connections.

OMSimulator co-simulates FMUs by iteratively making the FMUs do a step (calculate the values of the variables for a given point in time) and then exchanging messages - with a fixed communication interval. When the step size (communication interval) is too big the simulation might be inaccurate and might miss important events. On the other hand, simulating with a smaller step size is inefficient. 

A good compromise between efficiency and accuracy is to adapt the step size: when it is more important to be accurate (e.g. when the value of an important variable is getting close to a critical amount) the step size can be decreased (to make sure that the critical situation is simulated accurately) but when the critical situation is over (when the value of the variable is far from critical level) it can be increased again.

Existing approaches for step size control rely on the master simulator being able to _reject_ steps (that is, to force FMUs to revert the last step), but in reality it is often impossible. This solution does not need the FMUs to be able to revert steps.

Motivations and use-cases for adaptive step size control:
* Threshold-crossing (see above)
* Chains of discrete events: in case of DE simulation, discrete events often trigger other discrete events in other FMUs that are supposed to be nearly instant reactions. When these chains of discrete events occur, it is important to decrease the step size.
* Timed events: when an event is triggered at a given point in time, it can be caught precisely when it occurs if the step size can be adjusted.
* Relative-tolerance: step sizes can also be adjusted in order to ensure that the error of the calculation stays below a given limit

## Working with the repository

This repository is forked from [OpenModelica/OMSimulator](https://github.com/OpenModelica/OMSimulator) and synchronized according to the [GitHub recommendation](https://help.github.com/articles/syncing-a-fork/).

Clone the project using the `--recursive` flag then follow the instructions of the original repository for building and installing OMSimulator. The step size controller is currently implemented in lua and you can find case studies in the _StepSizeController_ folder.

## Working with the step size controller

This is a preliminary step size controller written in lua. It can be integrated to the OMSimulator later. The adaptive step size controller is the file _StepSizeController.lua_ located in the _StepSizeController_ folder. To use it just import the file.

```lua
package.path = package.path .. ";path/to/StepSizeController/StepSizeController.lua"
require("StepSizeController")
```

After this you can use the `oms2_simulateWithASSC` function that takes four parameters:
* _model_ denotes the model to simulate
* _communicationInterval_ denotes the _default_ communication interval (when there is no need to decrease it)
* _sensitivityModel_ is an instance of the `SensitivityModel` class. Usage is explained below.
* _imin_ denotes the minimum size of the steps (this value will be used when an event is detected)
* _tmax_ denotes the end of the simulation

The step size controller supports three of the use-cases enlisted above (it does not yet support error-approximations). The _SensitivityModel_ class has three attributes:
* The _events_ attribute should contain the set of output variables representing ocurrences of dicrete events (the type of the variables should also be specified). The step size controller detects a discrete event if any of the variables changes its value, and adjust the step size to the minimal value so that the chains of synchronized events can be simulated quickly. The step size will be adjusted back when no more events are detected.
* The _zeroCrossings_ attribute should contain a collection mapping variables to objects with a function `getStepSize(value)` that can provide an upper bound of the next step size based on the current _value_ of the variable. Two such classes are implemented in _StepSizeController.lua._ The key idea in both is to assign step sizes to intervals of the possible values of the given variable (e.g. the closer it is to the treshold the smaller the step size). The difference it that while `BandModel` specifies constant intervals, `DynamicBandModel` takes both the target and the width of the interval from variables inside the FMUs, which allows these values to change during the simulation. Naturally, other such classes can also be defined.
* The _timeIndicators_ attribute can be used for timed events and it can only be used dynamically: it should contain the set of variables containing predictions of the next point in time when a discrete event might be triggered. The step size controller will make sure that there is a step at that precise time and that the next step is minimal - unless the variable's value is changed by then. If a time indicator variable is set to a nonpositive value, it is not considered.

Examples can be found in the _StepSizeController/Thermostat_ folder. A thorough example is _MonitoredThermostat.lua_ demonstrating all three usecases.

## Advantages of the Step size controller

The step size controller allows the un-eventful parts of the simulation to be performed quickly, yet the critical parts precisely. Usefulness in case of threshold-crossing detection was measured: accuracy and efficiency was measured for constant step size simulation (with different step sizes varying from 0.01 to 10.0) and simulation with adaptive step sizes. The results can be seen in the _StepSizeController/Thermostat_ folder.
