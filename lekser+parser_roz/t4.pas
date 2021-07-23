program example(input, output);
var x, y: integer;
var g,h:real;

function f(a: integer; b: real): integer;
begin
    f:=a+10
end;

begin
 x := f(f(3,4),f(5,6))
end.
