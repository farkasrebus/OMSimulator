# The thermostat example

The Thermostat is one of the most common examples for the simulation of Cyber Physical Systems, as while the thermostat itself is of discrete behaviour, the environment can best be described with continuously changing variables (e.g. temperature).

## The models

In our model the behaviour of the Thermostat is modelled by a so-called UML-FMU (an FMU containing an UML/SysML based model) called `advancedThermostat.fmu`. The FMU was derived from the model using a methodology dseveloped in the [OpenCPS project](https://opencps.eu/). The changes in the environment is modelled in _OpenModellica_ called `Room.fmu`. Both the user inputs (e.g. _turn-thermostat-on_, _set-target-temperature_, etc.) and the mesured temperature come from this FMU. The inputs and outputs of the models can be connected based on the names, or copied from the file `Thermostat.lua`.

In the simulated scenario, the temperature initiates from 20°C. The target temperature is 22 °C. The so-called hysteresis (the allowed difference between the actual and the target temperature before the heating/cooling system is activated) is 3 °C originally, but set to 2.5 later. The temperature of the environment is 0°C - that is, when the heating system is not activated the room of the temperature is decreasing to reach 0°C. Originally, the thermostat is turned _off_. 

The room temperature begins to decrease. After 10 time units, the thermostat is turned on. After ~345 time units, the temperature decreases below 19°C and the heating is turned on. The room temperature starts to increase. After ~1795 time units, the hysteresis is decreased to 2.5 °C. After ~2610 time units, the temperature exceeds 24.5 °C (target temperature plus hysteresis) and the heating is turned off.

## Adaptive step size control

To demonstrate how the step size can influence the accuracy of the simulation, we simulated the Thermostat example for 1000 time units with various (but constant) step sizes. The table contains the lowest temperature measured according to the simulation, the corrsponding time stamp and the time it took to perform the simulation.


| Step size      | Lowest temperature | Time stamp | Runtime | Total steps |
| --------------:| ------------------:| ----------:| -------:| -----------:|
| 10 time units  |         18.9282 °C |        380 |  0.03 s |         100 |
|  1 time unit   |         18.9927 °C |        348 |  0.26 s |       1 000 |
| 0.1 time unit  |         18.9994 °C |      344.7 |  2.64 s |      10 000 |
| 0.01 time unit |         18.9999 °C |     344.42 | 26.52 s |     100 000 |

As the results show, the reaction delay is in the same order of magnitude as the size of the simulation interval, but the runtime is inversely proportional. 

The key idea of adaptive step size control is to consider the current temperature when deciding the next step size - if it is close to the threshold, the step size is decreased but once it's far away from it, it is increased.

In this case study the simulation starts from 20 °C with an initial step size of 10 time units, which is used while the temperature is over 19.1 °C. When the temperature is between 19.1 and 19.02 degrees, the step size is adjusted to 1 time unit. When the temperature falls below 19.02 degrees the step size is set to 0.01 time units.

During simulation the step sizes were adjusted as shown in the following table.

| Start time | Initial temperature | Step size | Steps |
| ---------- | ------------------- | --------- | ----- |
|      0     |      20             |  10       |  32   |
|   320	     |  19.0939            |    1      |  18   |
|    338     |      19.019         |  0.1      |  124  |
|   350.4    |  19.0203            |    1      |  25   |
|   375.4    |  19.1009            |    10     |  63   |

The simulation ended at 1005.4 time units with the following results.

| Step size      | Lowest temperature | Time stamp | Runtime | Total steps |
| --------------:| ------------------:| ----------:| -------:| -----------:|
| (adjusted)     |         18.9994 °C |     344.2  |  0.07 s |       262   |

When comparing the results to the constant step size simulations we can see, that the reaction delay is the same as that of the smallest step size used but the runtime is of the same order of magnitude as that of the largest used step size.

## Extending the example

We extended the Thermostat example with an additional monitoring system (see _MonitoredThermostat.lua_), to demonstrate the _chains of events_ usecase. Before turning the heating on the monitoring systems runs a few checks (in the form of sending messages among each other). While the first event is caught relatively late (depending on the current step size) the reactions are performed quickly, in the matter of miliseconds.


