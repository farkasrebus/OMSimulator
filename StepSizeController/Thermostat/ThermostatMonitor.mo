package ThermostatMonitor

class ThermostatOnMonitor
    Modelica.Blocks.Interfaces.IntegerInput turnOn;
    Modelica.Blocks.Interfaces.IntegerInput turnOff;
    Modelica.Blocks.Interfaces.RealInput request;
    Modelica.Blocks.Interfaces.RealOutput reply;
    Boolean turnedon;
  equation
    turnedon= (turnOn>0) or (pre(turnedon) and (turnOff==0));
    reply=if (request<0.5) then -1.0 elseif (turnedon) then 1.0 else 0.0;
end ThermostatOnMonitor;















class HeatingOnMonitor
    Modelica.Blocks.Interfaces.IntegerInput turnOn;
    Modelica.Blocks.Interfaces.IntegerInput turnOff;
    Modelica.Blocks.Interfaces.RealInput request;
    Modelica.Blocks.Interfaces.RealOutput reply;
    Boolean turnedon;
  equation
    turnedon= (turnOn>0) or (pre(turnedon) and (turnOff==0));
    reply=if (request<0.5) then -1.0 elseif (turnedon) then 0.0 else 1.0;
end HeatingOnMonitor;














class CriticalTemperatureMonitor
    Modelica.Blocks.Interfaces.RealInput temperature;
    Modelica.Blocks.Interfaces.RealInput target;
    Modelica.Blocks.Interfaces.RealInput hysteresis;
    Modelica.Blocks.Interfaces.RealInput request;
    Modelica.Blocks.Interfaces.RealOutput reply;
    Boolean critical;
    Real currentTarget;
    Real currentBandWith;
  equation
    critical = (temperature < target - hysteresis);
    reply= if (request<0.5) then -1.0 elseif (critical) then 1.0 else 0.0;
    currentTarget = if (target<temperature) then target+hysteresis else target-hysteresis;
    currentBandWith=1.0;
end CriticalTemperatureMonitor;










class CentralMonitor
    Modelica.Blocks.Interfaces.IntegerInput heatOnPermission;
    Modelica.Blocks.Interfaces.IntegerOutput heatOnGrant;
    
    Modelica.Blocks.Interfaces.RealOutput termReq;
    Modelica.Blocks.Interfaces.RealOutput heatReq;
    Modelica.Blocks.Interfaces.RealOutput tempReq;
    
    Modelica.Blocks.Interfaces.RealInput termReply;
    Modelica.Blocks.Interfaces.RealInput heatReply;
    Modelica.Blocks.Interfaces.RealInput tempReply;
     
    Modelica.Blocks.Interfaces.RealOutput state; //1 - idle, 2 - waitTerm, 3 - waitHeat, 4 - waitTemp, 5 - finish
    
    Real nextHeartBeat;
    Modelica.Blocks.Interfaces.RealOutput lastTermReply;
    Modelica.Blocks.Interfaces.RealOutput lastHeatReply;
    Modelica.Blocks.Interfaces.RealOutput lastTempReply;
    Boolean grant;
  initial equation
    nextHeartBeat=180;
    termReq=0.0;
    tempReq=0.0;
    state=1;
  equation
    termReq=if (state> 1.5 and state <2.5) then 1.0 else 0.0;
    heatReq=if (state> 2.5 and state < 3.5) then 1.0 else 0.0;
    tempReq=if (state> 3.5 and state < 4.5) then 1.0 else 0.0;
    
    der(state)=0;
    
    der(nextHeartBeat)=0;
    der(lastTermReply)=0;
    der(lastHeatReply)=0;
    der(lastTempReply)=0;
    
    when (heatOnPermission > 0.5) then reinit(state,2); end when;
    when (time>=nextHeartBeat) then reinit(state,2); end when;
    when (termReply>-0.5) then reinit(state,3); end when;
    when (heatReply>-0.5) then reinit(state,4); end when;
    when (tempReply>-0.5) then reinit(state,5); end when;
    when (tempReply<-0.5) then reinit(state,1); end when;
    
    grant=(lastTermReply+lastHeatReply+lastTempReply>2.5);
    
    
    when (state < 1.5) then reinit(nextHeartBeat,time+180); end when;
    when (state> 2.5 and state < 3.5) then reinit(lastTermReply,termReply); end when;
    when (state> 3.5 and state < 4.5) then reinit(lastHeatReply,heatReply); end when;
    when (state> 4.5) then reinit(lastTempReply,tempReply); end when;
    
    
    heatOnGrant=if (state> 4.5) and grant then 1.0 else 0.0;
    
    
end CentralMonitor;

























class DummyTestEnvironment
    Modelica.Blocks.Interfaces.IntegerOutput turnThermostatOn;
    Modelica.Blocks.Interfaces.IntegerOutput turnThermostatOff;
    Modelica.Blocks.Interfaces.IntegerOutput turnHeatingOnPermission;
    Modelica.Blocks.Interfaces.IntegerOutput turnHeatingOff;
    Modelica.Blocks.Interfaces.RealOutput temperature;
    Modelica.Blocks.Interfaces.RealOutput target;
    Modelica.Blocks.Interfaces.RealOutput hysteresis;
    
    //ThermostatOnMonitor tom;
    //HeatingOnMonitor  hom;
    //CriticalTemperatureMonitor ctm;
    //CentralMonitor cm;
  initial equation
    temperature=20.0;
    
  equation
    turnThermostatOn=if (time>0.5 and time<=1) then 1 else 0;
    turnThermostatOff=0;
    target=20.0;
    hysteresis=3.0;
    der(temperature)=-1.0;
    turnHeatingOnPermission=if (time>2.9 and time <3.1) then 1 else 0;
    turnHeatingOff=0;
    
    /*connect(turnThermostatOn,tom.turnOn);//
    connect(turnThermostatOff,tom.turnOff);//
    connect(turnHeatingOff,hom.turnOff);//
    connect(temperature,ctm.temperature);//
    connect(target,ctm.target);//
    connect(hysteresis,ctm.hysteresis);//
  
    
    connect(turnHeatingOnPermission,cm.heatOnPermission);//
    connect(cm.heatOnGrant,hom.turnOn);//
   
    connect(cm.termReq,tom.request);
    connect(cm.heatReq,hom.request);
    connect(cm.tempReq,ctm.request);
    connect(cm.termReply,tom.reply);
    connect(cm.heatReply,hom.reply);
    connect(cm.tempReply,ctm.reply);*/
    
end DummyTestEnvironment;
































  

end ThermostatMonitor;
