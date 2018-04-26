# Demonstration of the advantages of adaptive stepsize control

This folder contains a simple case study to demonstrate the advantages of adaptive step size control.

## The Traffic light scenario

The modelled situation is the following.

There is a road with a pedestrian crossing with a traffic light controlling the cars so the pedestrians can safely cross the road.
A car is approaching the zebra just as the light is about to turn red. We want to know if the car is able to stop before the zebra crossing.

### The files

* `TrafficLightScenario.mo` contains the (small) modelica package that models the scenario.
..* `Car` models the behavior of the car in the situation. The variable _distance_ denotes the cars current distance from the traffic light and the zebra. If the distance is still positive when the car is stopped, the car managed to brake in time. If the distance is negativem the car run over the line (and possibly the pedestrians).
..* `DummyTrafficLight` models the behavior of the traffic light (it's called _dummy_ because it is time-dependent, only usable for this scenario and not realistically timed).
..* `PedestrianCrossing` connect the two models together (to allow simulation in OMEdit).
* `TrafficLightScenario_Car.fmu` and `TrafficLightScenario_DummyTrafficLight.fmu` are the FMUs exported from the classes.
* `TrafficLightScenario.lua` contains the lua script input of _OMSimulator_

## The significance of ste size control

Simulating the model in OMEdit shows that the car is stopped in time. The OMSimulator also concludes this when the two FMUs are co-simulated with a 0.005 s communication interval. However, increasing the interval to 0.01 s results in a negative distance after the brake. This reason for this is that the larger communication interval resulted in the car geting the information too late.

(Obviously, in this case the simulation was wrong in the _safe_ direction - meaning the simulation shows a bad scenario that wouldn't happen in real life, but the delayed communication could also allow the simulation to miss a critical value of the variable.)

One way to avoid this is to chose the step size to be small, however, that would mean the simulation would run longer and it is not always feasible in case of big system.

A good compromise between efficiency and accuracy is to adapt the step size: when it is more important to be accurate (e.g. when the car is driving up to the pedestrian crossing) the step size can be decreased but when the critical situation is over (e.g. when the car has already passed the zebra) it can be increased again. `TrafficLightScenario.lua` demonstrates this based on the variable _criticalSituation_ in the car's model (the situation is considered _critical_ when the car is close to the zebra - but not reaching it yet - and has not stopped yet).

## Usage

`TrafficLightScenario.lua` could be used as an example for establishing the connections and the models. The simulation can be run by the following command (executed from this folder).

```
../../install/linux/bin/OMSimulator TrafficLightScenario.lua
```

Currenty the adaptive step size control is commented, thus running OMSimulator on it gives the following result.

```
Initialization: Communication interval set to 0.01
stdout            | info    | The initialization finished successfully without homotopy method.
stdout            | info    | The initialization finished successfully without homotopy method.
Car's distance from pedestrian crossing afeter breaking: -0.1049000000001
info:    Logging information has been saved to "TrafficLightScenario.log"

```

However running the same command after uncommenting the step size control (e.g. insert a third `-` before `--[[`) shows the car is able to stop safely.

```
Initialization: Communication interval set to 0.01
stdout            | info    | The initialization finished successfully without homotopy method.
stdout            | info    | The initialization finished successfully without homotopy method.
Critical situation. Communication interval set to 0.005
Critical situation over. Communication interval set to 0.01
Car's distance from pedestrian crossing afeter breaking: 0.029697500001023
Critical situation. Communication interval set to 0.005
Critical situation over. Communication interval set to 0.01
info:    Logging information has been saved to "TrafficLightScenario.log"
```

The same scenario can be simulated by _TLSwoithSSC.lua_ that uses the _StepSizeCpontroller.lua_ file, however, that doesn't print the car's distance (notheless, the result is shown in the generated plot).



