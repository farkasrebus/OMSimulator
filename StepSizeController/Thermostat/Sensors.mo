package Sensors

class SensorInterface
    Modelica.Blocks.Interfaces.RealInput tempin;
    Modelica.Blocks.Interfaces.RealInput request;
    Modelica.Blocks.Interfaces.RealOutput reply;
    Modelica.Blocks.Interfaces.RealOutput tempout;

  equation
    tempout=tempin;
    reply= if (request > 0.5) then tempin else 0.0;
end SensorInterface;

class Monitor
    Modelica.Blocks.Interfaces.RealInput mes1;
    Modelica.Blocks.Interfaces.RealInput mes2;
    Modelica.Blocks.Interfaces.RealInput mes3;
    Modelica.Blocks.Interfaces.RealInput on;
    Modelica.Blocks.Interfaces.RealOutput req1;
    Modelica.Blocks.Interfaces.RealOutput req2;
    Modelica.Blocks.Interfaces.RealOutput req3;
    Modelica.Blocks.Interfaces.RealOutput med;
    Real m1;
    Real m2;
    Real m3;
    VoterState state(start=VoterState.wait1);
  initial equation
    med=0.0;
  equation
    req1=if (state==VoterState.wait1) then 1.0 else 0.0;
    req2=if (state==VoterState.wait2) then 1.0 else 0.0;
    req3=if (state==VoterState.wait3) then 1.0 else 0.0;
    
    
    if (state==VoterState.wait2) then when (temp2 > 0.0) then sate=VoterState.wait3; end when; end if;
    if (state==VoterState.wait3) then when (temp3 > 0.0) then sate=VoterState.wait1; end when; end if;
    
    when (state==VoterState.wait2) then 
      reinit(m1,mes1); 
    end when;
    when (state==VoterState.wait3) then 
      reinit(m2,mes2); 
    end when;
    when (state==VoterState.wait1) then 
      reinit(m3,mes3);
      reinit(med,(m1+m2+m3)/3); 
    end when;
    
    when (mes1>0.0) then reinit(state,VoterState.wait2); end when;
    when (mes2>0.0) then reinit(state,VoterState.wait3); end when;
    when (mes3>0.0) then reinit(state,VoterState.wait1); end when;
    
    
end Monitor;



end Sensors;
