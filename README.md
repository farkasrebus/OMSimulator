# Additive step size control for OMSimulator

This repository is forked from [OpenModelica/OMSimulator](https://github.com/OpenModelica/OMSimulator) with the goal of extending it with additive step size control for efficient and precise simulation.

## Simulation and step size control

The OMSimulator project is a FMI-based co-simulation environment that supports ordinary (i.e., non-delayed) and TLM connections. Pre-compiled binaries are available for [Windows-MSVC](https://test.openmodelica.org/hudson/job/OMSimulator-Windows-MSVC/lastSuccessfulBuild/artifact/OMSimulator/install/win/OMSimulator-win-master.zip) and [Windows-GCC](https://test.openmodelica.org/hudson/job/OMSimulator-Windows-GCC/lastSuccessfulBuild/artifact/OMSimulator/install/mingw/OMSimulator-mingw-master.zip).

OMSimulator co-simulates FMUs by iteratively making the FMUs do a step (calculate the values of the variables for a given point in time) and then exchanging messages - with a fixed communication interval. When the step size (communication interval) is too big the simulation might be inaccurate and might miss important events. On the other hand, simulating with a smaller step size is inefficient. A good compromise between efficiency and accuracy is to adapt the step size: when it is more important to be accurate (e.g. when the value of an important variable is getting close to a critical amount) the step size can be decreased (to make sure that the critical situation is simulated accurately) but when the critical situation is over (when the value of the variable is far from critical level) it can be increased again.

## Working with the repository

This repository is forked from [OpenModelica/OMSimulator](https://github.com/OpenModelica/OMSimulator) and synchronized according to the [GitHub recommendation](https://help.github.com/articles/syncing-a-fork/).

Clone the project using the `--recursive` flag then follow the instructions of the original repository for building and installing OMSimulator. The step size controller is currently implemented in lua and you can find a case study in the _StepSizeController/CaseStudy_ folder.

## Working with the step size controller

The adaptive step size controller is the file _StepSizeController.lua_ located in the _StepSizeController_ folder. To use it just import the file.

```lua
package.path = package.path .. ";path/to/StepSizeController/StepSizeController.lua"
require("StepSizeController")
```

After this you can use the _simulateWithAdaptiveStepSizeControl_ function that takes four parameters:
* _model_ denotes the model to simulate
* _criticalVarName_ is the name of a boolean variable whose value is true when the step size have to be low and false otherwise
* _bigStepSize_ is the size of the large steps
* _smallStepSize_ is the size of small steps

An example can be found in the _StepSizeController/CaseStudy_ folder called _TLSwithSSC.lua_.

This is a preliminary step size controller that requires the user to configure everything. The step size controller will be improved with more functionality.
