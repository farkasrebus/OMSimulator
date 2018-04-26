# Additive step size control for OMSimulator

This repository is forked from [OpenModelica/OMSimulator](https://github.com/OpenModelica/OMSimulator) with the goal of extending it with additive step size control for efficient and precise simulation.

## Simulation and step size control

The OMSimulator project is a FMI-based co-simulation environment that supports ordinary (i.e., non-delayed) and TLM connections. Pre-compiled binaries are available for [Windows](https://test.openmodelica.org/hudson/job/OMSimulator-Windows-GCC/lastSuccessfulBuild/artifact/OMSimulator/install/mingw/OMSimulator-mingw-master.zip). The latest documentation is avilable as [pdf](https://openmodelica.org/doc/OMSimulator/OMSimulator.pdf) and [html](https://openmodelica.org/doc/OMSimulator/html/).

OMSimulator co-simulates FMUs by iteratively making the FMUs do a step (calculate the values of the variables for a given point in time) and tthen exchanging messages - with a fixed communication interval. When the step size (communication interval) is too big the simulation might be inaccurate and might miss important events. On the other hand, simulating with a smaller step size is inefficient. A good compromise between efficiency and accuracy is to adapt the step size: when it is more important to be accurate (e.g. when the value of an important variable is getting close to a critical amount) the step size can be decreased (to make sure that the critical situation is simulated accurately) but when the critical situation is over (when the value of the variable is far from critical level) it can be increased again.


## Working with the repository

This repository is forked from [OpenModelica/OMSimulator](https://github.com/OpenModelica/OMSimulator) and synchronized accoring to the [GitHub recommendation](https://help.github.com/articles/syncing-a-fork/).

Clone the project using the `--recursive` flag then follow the instructions of the original repository for building and installing OMSimulator. The step size controller is currently implemented in lua and you can find a case study in the _StepSizeController_ folder.