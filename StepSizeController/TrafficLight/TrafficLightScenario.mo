package TrafficLightScenario

type TrafficLightColor=enumeration(green,yellow,red);

class DummyTrafficLight
    Modelica.Blocks.Interfaces.RealOutput color;
    TrafficLightColor state(start=TrafficLightColor.green);
    Real colorReal = color;
  equation
    if (time >= 0.51 and time <1) then
        state=TrafficLightColor.yellow;
    elseif (time >= 1 and time <3) then
        state=TrafficLightColor.red;
    else
      state=TrafficLightColor.green;
        end if;
    colorReal=Integer(state);
end DummyTrafficLight;















class Car
    parameter Real initialDistance(unit = "m") = 16.6 "Initial distance from traffic light";
    parameter Real breakingDeceleration(unit = "m/s2") = 10.0 "Deceleration of car whilst breaking";
    parameter Real goingAcceleration(unit = "m/s2") = 5.0 "Deceleration of car whilst breaking";
    Modelica.Blocks.Interfaces.RealInput color;
    type CarState=enumeration(going,breaking,stopped,accelerating);
    CarState state(start=CarState.going);
    Real distance;
    Real speed;
    Real deceleration;
    Real lightColorReal = color;
    Integer lightColorInteger;
    TrafficLightColor lightColor;
    Boolean criticalSituation;
    Integer stateInteger;
  initial equation
    distance=initialDistance;
    speed=13.8;
    deceleration=0.0;
    criticalSituation=false;
  equation
   // lightColor= if lightColorInteger==1 then TrafficLightColor.green elseif lightColorInteger==2 then TrafficLightColor.yellow else TrafficLightColor.red;
    lightColorInteger=integer(floor(lightColorReal));
    lightColorInteger=Integer(lightColor);
    //state=if (lightColor==TrafficLightColor.green) then CarState.going elseif (speed>0) then CarState.breaking else CarState.stopped;
    stateInteger=Integer(state);
    state= if lightColor==TrafficLightColor.green then 
    //hack
              if time<1 then CarState.going else CarState.accelerating
           elseif (speed>0) then CarState.breaking else CarState.stopped;
    criticalSituation=if (distance <= 10.0 and distance >=0 and not state==CarState.stopped) then true else false;
    when (state==CarState.breaking) then reinit(deceleration,breakingDeceleration); end when;
    when (state==CarState.stopped) then reinit(deceleration,0.0); end when;
    when (state==CarState.accelerating) then reinit(deceleration,-1*goingAcceleration); end when;
    der(deceleration)=0;
    der(distance)=-1*speed;
    der(speed)=-1*deceleration;  
end Car;



































model PedestrianCrossing
    Car car;
    DummyTrafficLight light;
  equation
    connect(light.color,car.color);
end PedestrianCrossing;





end TrafficLightScenario;
