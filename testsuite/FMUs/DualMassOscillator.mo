package DualMassOscillator
  model System1
    Modelica.Mechanics.Translational.Components.Fixed fixed(s0=0) annotation(Placement(transformation(extent={{-10, -10}, {10, 10}}, rotation=0, origin={-70, 0})));
    Modelica.Mechanics.Translational.Components.Mass mass1(m=1, s(fixed=true, start=1), v(fixed=true, start=0), L=0) annotation(Placement(transformation(extent={{-14, -10}, {6, 10}})));
    Modelica.Mechanics.Translational.Components.SpringDamper springDamper1(c=1e4, d=2, s_rel0=0) annotation(Placement(transformation(extent={{-50, -10}, {-30, 10}})));
    Modelica.Mechanics.Translational.Sensors.PositionSensor positionSensor annotation(Placement(transformation(extent={{20, -40}, {40, -20}})));
    Modelica.Mechanics.Translational.Sensors.SpeedSensor speedSensor annotation(Placement(transformation(extent={{20, -60}, {40, -40}})));
    Modelica.Mechanics.Translational.Sensors.AccSensor accSensor annotation(Placement(transformation(extent={{20, -80}, {40, -60}})));
    Modelica.Mechanics.Translational.Sources.Force force annotation(Placement(transformation(extent={{40, -10}, {20, 10}})));
    Modelica.Blocks.Interfaces.RealInput F annotation(Placement(transformation(extent={{120, -10}, {100, 10}}), iconTransformation(extent={{120, -10}, {100, 10}})));
    Modelica.Blocks.Interfaces.RealOutput s annotation(Placement(transformation(extent={{100, -40}, {120, -20}}), iconTransformation(extent={{100, -40}, {120, -20}})));
    Modelica.Blocks.Interfaces.RealOutput v annotation(Placement(transformation(extent={{100, -60}, {120, -40}}), iconTransformation(extent={{100, -60}, {120, -40}})));
    Modelica.Blocks.Interfaces.RealOutput a annotation(Placement(transformation(extent={{100, -80}, {120, -60}}), iconTransformation(extent={{100, -80}, {120, -60}})));
  equation
    connect(fixed.flange, springDamper1.flange_a) annotation(Line(points={{-70, 0}, {-60, 0}, {-50, 0}}, color={0, 127, 0}));
    connect(springDamper1.flange_b, mass1.flange_a) annotation(Line(points={{-30, 0}, {-22, 0}, {-14, 0}}, color={0, 127, 0}));
    connect(mass1.flange_b, positionSensor.flange) annotation(Line(points={{6, 0}, {12, 0}, {12, -30}, {20, -30}}, color={0, 127, 0}));
    connect(mass1.flange_b, speedSensor.flange) annotation(Line(points={{6, 0}, {12, 0}, {12, -50}, {20, -50}}, color={0, 127, 0}));
    connect(mass1.flange_b, accSensor.flange) annotation(Line(points={{6, 0}, {12, 0}, {12, -70}, {20, -70}}, color={0, 127, 0}));
    connect(force.flange, mass1.flange_b) annotation(Line(points={{20, 0}, {6, 0}}, color={0, 127, 0}));
    connect(accSensor.a, a) annotation(Line(points={{41, -70}, {110, -70}}, color={0, 0, 127}));
    connect(speedSensor.v, v) annotation(Line(points={{41, -50}, {110, -50}}, color={0, 0, 127}));
    connect(positionSensor.s, s) annotation(Line(points={{41, -30}, {110, -30}}, color={0, 0, 127}));
    connect(force.f, F) annotation(Line(points={{42, 0}, {110, 0}}, color={0, 0, 127}));
    annotation(Icon(coordinateSystem(preserveAspectRatio=false)), Diagram(coordinateSystem(preserveAspectRatio=false)));
  end System1;

  model System2
    Modelica.Mechanics.Translational.Components.Fixed fixed(s0=0) annotation(Placement(transformation(extent={{80, -10}, {100, 10}})));
    Modelica.Mechanics.Translational.Components.Mass mass2(m=1, s(fixed=true, start=2), v(fixed=true, start=0), L=0) annotation(Placement(transformation(extent={{20, -10}, {40, 10}})));
    Modelica.Mechanics.Translational.Components.SpringDamper springDamper2(c=1e5, d=6.3246, s_rel0=0) annotation(Placement(transformation(extent={{50, -10}, {70, 10}})));
    Modelica.Mechanics.Translational.Components.SpringDamper springDamper_coupling(c=1e6, d=14.1421, s_rel0=0) annotation(Placement(transformation(extent={{-10, -10}, {10, 10}})));
    Modelica.Blocks.Interfaces.RealOutput F annotation(Placement(transformation(extent={{-100, -10}, {-120, 10}})));
    Modelica.Blocks.Interfaces.RealInput s annotation(Placement(transformation(extent={{-120, -40}, {-100, -20}})));
    Modelica.Blocks.Interfaces.RealInput v annotation(Placement(transformation(extent={{-120, -60}, {-100, -40}})));
    Modelica.Blocks.Interfaces.RealInput a annotation(Placement(transformation(extent={{-120, -80}, {-100, -60}})));
    Modelica.Mechanics.Translational.Sensors.ForceSensor forceSensor annotation(Placement(transformation(extent={{-20, 10}, {-40, -10}})));
    Modelica.Mechanics.Translational.Sources.Move move annotation(Placement(transformation(extent={{-68, -10}, {-48, 10}})));
  equation
    connect(forceSensor.f, F) annotation(Line(points={{-22, 11}, {-90, 11}, {-90, 0}, {-110, 0}}, color={0, 0, 127}));
    connect(s, move.u[1]) annotation(Line(points={{-110, -30}, {-80, -30}, {-80, -1.33333}, {-70, -1.33333}}, color={0, 0, 127}));
    connect(v, move.u[2]) annotation(Line(points={{-110, -50}, {-80, -50}, {-80, 0}, {-70, 0}}, color={0, 0, 127}));
    connect(a, move.u[3]) annotation(Line(points={{-110, -70}, {-80, -70}, {-80, 1.33333}, {-70, 1.33333}}, color={0, 0, 127}));
    connect(springDamper_coupling.flange_b, mass2.flange_a) annotation(Line(points={{10, 0}, {15, 0}, {20, 0}}, color={0, 127, 0}));
    connect(mass2.flange_b, springDamper2.flange_a) annotation(Line(points={{40, 0}, {45, 0}, {50, 0}}, color={0, 127, 0}));
    connect(springDamper2.flange_b, fixed.flange) annotation(Line(points={{70, 0}, {80, 0}, {90, 0}}, color={0, 127, 0}));
    connect(forceSensor.flange_a, springDamper_coupling.flange_a) annotation(Line(points={{-20, 0}, {-15, 0}, {-10, 0}}, color={0, 127, 0}));
    connect(move.flange, forceSensor.flange_b) annotation(Line(points={{-48, 0}, {-44, 0}, {-40, 0}}, color={0, 127, 0}));
    annotation(Icon(coordinateSystem(preserveAspectRatio=false)), Diagram(coordinateSystem(preserveAspectRatio=false)));
  end System2;

  model CoupledSystem
    System1 system1 annotation(Placement(transformation(extent={{-30, -10}, {-10, 10}})));
    System2 system2 annotation(Placement(transformation(extent={{10, -10}, {30, 10}})));
  equation
    connect(system2.F, system1.F) annotation(Line(points={{9, 0}, {-9, 0}}, color={0, 0, 127}));
    connect(system1.s, system2.s) annotation(Line(points={{-9, -3}, {-9, -3}, {9, -3}}, color={0, 0, 127}));
    connect(system1.v, system2.v) annotation(Line(points={{-9, -5}, {-9, -5}, {9, -5}}, color={0, 0, 127}));
    connect(system1.a, system2.a) annotation(Line(points={{-9, -7}, {-9, -7}, {9, -7}}, color={0, 0, 127}));
    annotation(Icon(coordinateSystem(preserveAspectRatio=false)), Diagram(coordinateSystem(preserveAspectRatio=false)));
  end CoupledSystem;

  model ReferenceSystem
    Modelica.Mechanics.Translational.Components.Fixed fixed(s0=0) annotation(Placement(transformation(extent={{-10, -10}, {10, 10}}, rotation=0, origin={-90, 0})));
    Modelica.Mechanics.Translational.Components.Mass mass1(m=1, s(fixed=true, start=1), v(fixed=true, start=0), L=0) annotation(Placement(transformation(extent={{-40, -10}, {-20, 10}})));
    Modelica.Mechanics.Translational.Components.SpringDamper springDamper1(c=1e4, d=2, s_rel0=0) annotation(Placement(transformation(extent={{-70, -10}, {-50, 10}})));
    Modelica.Mechanics.Translational.Components.Fixed fixed1(s0=0) annotation(Placement(transformation(extent={{80, -10}, {100, 10}})));
    Modelica.Mechanics.Translational.Components.Mass mass2(m=1, s(fixed=true, start=2), v(fixed=true, start=0), L=0) annotation(Placement(transformation(extent={{20, -10}, {40, 10}})));
    Modelica.Mechanics.Translational.Components.SpringDamper springDamper2(c=1e5, d=6.3246, s_rel0=0) annotation(Placement(transformation(extent={{50, -10}, {70, 10}})));
    Modelica.Mechanics.Translational.Components.SpringDamper springDamper_coupling(c=1e6, d=14.1421, s_rel0=0) annotation(Placement(transformation(extent={{-10, -10}, {10, 10}})));
  equation
    connect(fixed.flange, springDamper1. flange_a) annotation(Line(points={{-90, 0}, {-80, 0}, {-70, 0}}, color={0, 127, 0}));
    connect(springDamper1.flange_b, mass1. flange_a) annotation(Line(points={{-50, 0}, {-40, 0}}, color={0, 127, 0}));
    connect(springDamper_coupling.flange_b, mass2. flange_a) annotation(Line(points={{10, 0}, {15, 0}, {20, 0}}, color={0, 127, 0}));
    connect(mass2.flange_b, springDamper2. flange_a) annotation(Line(points={{40, 0}, {45, 0}, {50, 0}}, color={0, 127, 0}));
    connect(springDamper2.flange_b, fixed1.flange) annotation(Line(points={{70, 0}, {80, 0}, {90, 0}}, color={0, 127, 0}));
    connect(mass1.flange_b, springDamper_coupling.flange_a) annotation(Line(points={{-20, 0}, {-15, 0}, {-10, 0}}, color={0, 127, 0}));
    annotation(Icon(coordinateSystem(preserveAspectRatio=false, extent={{-100, -20}, {100, 20}})), Diagram(coordinateSystem(preserveAspectRatio=false, extent={{-100, -20}, {100, 20}})));
  end ReferenceSystem;

  model ReferenceSystemEq
    Real s1;
    Real v1;
    Real s2;
    Real v2;
    Real F;
    parameter Real d1 = 2;
    parameter Real d2 = 6.3246;
    parameter Real dc = 14.1421;
    parameter Real c1 = 1e4;
    parameter Real c2 = 1e5;
    parameter Real cc = 1e6;
    parameter Real m1 = 1;
    parameter Real m2 = 1;
  initial equation
    s1 = 1;
    s2 = 2;
    v1 = 0;
    v2 = 0;
  equation
    der(s1) = v1;
    der(s2) = v2;
    m1*der(v1) = -c1*s1 - d1*v1 + F;
    m2*der(v2) = -c2*s2 - d2*v2 - F;
    F = -cc*s1 - dc*v1 + cc*s2 + dc*v2;
    annotation(Icon(coordinateSystem(preserveAspectRatio=false)), Diagram(coordinateSystem(preserveAspectRatio=false)));
  end ReferenceSystemEq;

  model System1Eq
    Real s1 = out_s1;
    Real v1 = out_v1;
    Real F = in_F;
    parameter Real d1 = 2;
    parameter Real c1 = 1e4;
    parameter Real m1 = 1;
    Modelica.Blocks.Interfaces.RealInput in_F annotation(Placement(transformation(extent={{120, -10}, {100, 10}}), iconTransformation(extent={{120, -10}, {100, 10}})));
    Modelica.Blocks.Interfaces.RealOutput out_s1 annotation(Placement(transformation(extent={{100, -40}, {120, -20}}), iconTransformation(extent={{100, -40}, {120, -20}})));
    Modelica.Blocks.Interfaces.RealOutput out_v1 annotation(Placement(transformation(extent={{100, -60}, {120, -40}}), iconTransformation(extent={{100, -60}, {120, -40}})));
  initial equation
    s1 = 1;
    v1 = 0;
  equation
    der(s1) = v1;
    m1*der(v1) = -c1*s1 - d1*v1 + F;
    annotation(Icon(coordinateSystem(preserveAspectRatio=false)), Diagram(coordinateSystem(preserveAspectRatio=false)));
  end System1Eq;

  model System2Eq
    Real s1 = in_s1;
    Real v1 = in_v1;
    Real s2;
    Real v2;
    Real F = out_F;
    parameter Real d2 = 6.3246;
    parameter Real dc = 14.1421;
    parameter Real c2 = 1e5;
    parameter Real cc = 1e6;
    parameter Real m2 = 1;
    Modelica.Blocks.Interfaces.RealOutput out_F annotation(Placement(transformation(extent={{-100, -10}, {-120, 10}})));
    Modelica.Blocks.Interfaces.RealInput in_s1 annotation(Placement(transformation(extent={{-120, -40}, {-100, -20}})));
    Modelica.Blocks.Interfaces.RealInput in_v1 annotation(Placement(transformation(extent={{-120, -60}, {-100, -40}})));
  initial equation
    s2 = 2;
    v2 = 0;
  equation
    der(s2) = v2;
    m2*der(v2) = -c2*s2 - d2*v2 - F;
    F = -cc*s1 - dc*v1 + cc*s2 + dc*v2;
    annotation(Icon(coordinateSystem(preserveAspectRatio=false)), Diagram(coordinateSystem(preserveAspectRatio=false)));
  end System2Eq;

  model CoupledSystemEq
    System1Eq system1Eq annotation(Placement(transformation(extent={{-30, -10}, {-10, 10}})));
    System2Eq system2Eq annotation(Placement(transformation(extent={{10, -10}, {30, 10}})));
  equation
    connect(system1Eq.in_F, system2Eq.out_F) annotation(Line(points={{-9, 0}, {9, 0}, {9, 0}}, color={0, 0, 127}));
    connect(system1Eq.out_s1, system2Eq.in_s1) annotation(Line(points={{-9, -3}, {-0.5, -3}, {-0.5, -3}, {9, -3}}, color={0, 0, 127}));
    connect(system1Eq.out_v1, system2Eq.in_v1) annotation(Line(points={{-9, -5}, {-0.5, -5}, {-0.5, -5}, {9, -5}}, color={0, 0, 127}));
    annotation(Icon(coordinateSystem(preserveAspectRatio=false)), Diagram(coordinateSystem(preserveAspectRatio=false)));
  end CoupledSystemEq;
  annotation(uses(Modelica(version="3.2.2")));
end DualMassOscillator;
