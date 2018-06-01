package EventChain

class DummyEventGenerator
    Modelica.Blocks.Interfaces.RealOutput event;
    Modelica.Blocks.Interfaces.RealInput reaction;
    Real eventVar = event;
    Real reactVar = reaction;
  equation
    if (time > 0.5) then 
      eventVar = 0.0;
    else
      eventVar = 1.0;
    end if;
end DummyEventGenerator;

class EventChainLink
    Modelica.Blocks.Interfaces.RealInput leftIn;
    Modelica.Blocks.Interfaces.RealInput rightIn;
    Modelica.Blocks.Interfaces.RealOutput leftOut;
    Modelica.Blocks.Interfaces.RealOutput rightOut;
    Real leftInVar = leftIn;
    Real rightInVar = rightIn;
    Real leftOutVar = leftOut;
    Real rightOutVar = rightOut;
  equation
    leftOutVar = rightInVar;
    rightOutVar = leftInVar;
end EventChainLink;

class InverterEventChainLink
    Modelica.Blocks.Interfaces.RealInput leftIn;
    Modelica.Blocks.Interfaces.RealInput rightIn;
    Modelica.Blocks.Interfaces.RealOutput leftOut;
    Modelica.Blocks.Interfaces.RealOutput rightOut;
    Real leftInVar = leftIn;
    Real rightInVar = rightIn;
    Real leftOutVar = leftOut;
    Real rightOutVar = rightOut;
  equation
    leftOutVar = if (rightInVar < 0.1) then 1.0 else 0.0;
    rightOutVar = if (leftInVar < 0.1) then 1.0 else 0.0;
end InverterEventChainLink;


class DummyInverter
    Modelica.Blocks.Interfaces.RealOutput inverted;
    Modelica.Blocks.Interfaces.RealInput original;
    Real origVar=original;
    Real invVar=inverted;
  equation
    inverted = if (original < 0.1) then 1.0 else 0.0;
end DummyInverter;




model Chain
    DummyEventGenerator gen;
    EventChainLink link;
    DummyInverter inverter;
  equation
    connect(gen.event,link.leftIn);
    connect(link.leftOut,gen.reaction);
    connect(link.rightOut,inverter.original);
    connect(inverter.inverted,link.rightIn);
end Chain;

end EventChain;
