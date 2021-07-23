program example(input, output);
var x, y: integer;
var g,h:real;

 

function mul(a: integer) : integer;
begin
  mul := 2*a
end;

 

function sum(a, b: integer):integer;
begin
  sum := a + b
end;

 

begin
   x := sum(sum(1,2), sum(3,4));
  write(x)
end.