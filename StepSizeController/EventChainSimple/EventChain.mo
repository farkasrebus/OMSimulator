package EventChain

class DummyEventGenerator
    Modelica.Blocks.Interfaces.RealOutput event;
    Real eventVar = event;
  equation
    if (time > 0.5) then 
      eventVar = 0.0;
    else
      eventVar = 1.0;
    end if;
end DummyEventGenerator;

class EventChainLink
    Modelica.Blocks.Interfaces.RealInput eventInput;
    Modelica.Blocks.Interfaces.RealOutput eventOutput;
    Real inVar = eventInput;
    Real outVar = eventOutput;
  equation
    outVar = inVar;
end EventChainLink;

class InverterEventChainLink
    Modelica.Blocks.Interfaces.RealInput eventInput;
    Modelica.Blocks.Interfaces.RealOutput eventOutput;
    Real inVar = eventInput;
    Real outVar = eventOutput;
  equation
    outVar = if (inVar < 0.1) then 1.0 else 0.0;
end InverterEventChainLink;




model Chain
    DummyEventGenerator gen;
    EventChainLink link1;
    InverterEventChainLink invLink;
    EventChainLink link2;
  equation
    connect(gen.event,link1.eventInput);
    connect(link1.eventOutput,invLink.eventInput);
    connect(invLink.eventOutput,link2.eventInput);
end Chain;

end EventChain;
