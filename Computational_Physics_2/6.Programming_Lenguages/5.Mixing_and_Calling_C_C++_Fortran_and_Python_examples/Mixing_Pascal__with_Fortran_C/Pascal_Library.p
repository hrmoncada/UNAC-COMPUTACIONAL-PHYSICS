unit Pascal_Library;

interface

var
    P_GlobalVar:integer=12; attribute(name='P_GlobalVar');
    

function C_Sqr(x:longreal):longreal; external name 'C_Sqr';

function P_Sqr(x:longreal):longreal; attribute(name='P_Sqr');
function P_Cube(x:longreal):longreal; attribute(name='P_Cube');
procedure P_ReadVar; attribute(name='P_ReadVar');
procedure P_Add(var i,j:integer); attribute(name='P_Add');

implementation

function P_Sqr(x:longreal):longreal;
begin P_Sqr:=x*x; end;

function P_Cube(x:longreal):longreal;
begin P_Cube:=x*C_Sqr(x); end;

procedure P_ReadVar;
begin 
	write('Pascal: Enter an integer for P_GlobalVar: '); 
	readln(P_GlobalVar); 
end;

procedure P_Add(var i,j:integer);
begin
	writeln('P_Add: The sum of ',i:1,' and ',j:1,' is ',i+j:1);
end;

initialization

writeln('Pascal: Initialized Pascal Library.');

end.