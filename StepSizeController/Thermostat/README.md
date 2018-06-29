# The thermostat example

The Thermostat is one of the most common examples for the simulation of Cyber Physical Systems, as while the thermostat itself is of discrete behaviour, the environment can best be described with continuously changing variables (e.g. temperature).

## The models

In our model the behaviour of the Thermostat is modelled by a so-called UML-FMU (an FMU containing an UML/SysML based model) called `advancedThermostat.fmu`. The FMU was derived from the model using a methodology dseveloped in the [OpenCPS project](https://opencps.eu/). The changes in the environment is modelled in _OpenModellica_ called `Room.fmu`. Both the user inputs (e.g. _turn-thermostat-on_, _set-target-temperature_, etc.) and the mesured temperature come from this FMU. The inputs and outputs of the models can be connected based on the names, or copied from the file `Thermostat.lua`.

In the simulated scenario, the temperature initiates from 20°C, which is also the target temperature. The so-called hysteresis (the allowed difference between the actual and the target temperature before the heating/cooling system is activated) is 2°C. The temperature of the environment is 0°C - that is, when the heating system is not activated the room of the temperature is _heading towards_ (?) 0°C. Originally, the thermostat is turned _off_. 

The room temperature begins to decrease. After 10 time units, the thermostat is turned on. After ~355 time units, the temperature decreases below 19°C and the heating is turned on.
