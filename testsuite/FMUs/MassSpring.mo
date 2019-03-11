model MassSpring
  input Real f;
  output Real x;
  output Real v;
  parameter Real M=100;
  parameter Real B = 10;
  parameter Real k = 3000;
  
equation
  der(v)*M + v*B + k*x = -f;
  v = der(x);
end MassSpring;
