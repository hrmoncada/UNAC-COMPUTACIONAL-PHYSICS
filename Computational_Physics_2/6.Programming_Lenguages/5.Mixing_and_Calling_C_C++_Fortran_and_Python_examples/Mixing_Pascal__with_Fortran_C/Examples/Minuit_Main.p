program Minuit_Main;
{
	This program calls Minuit routines with the help of the Minuit.p unit. We use 
	the following lines to compile Minuit_Main.p on MacOS X.

	/usr/bin/gpc -c -o mp.o Minuit.p
	/usr/bin/gpc -c -o p.o Minuit_Main.p
	/usr/bin/gcc -o p.out p.o mp.o libgpc.a libmyminuit.a libf2c.a
}
uses
	minuit;
	
procedure fcn(var npar:integer; var grad,fval,xval:longreal; 
	var iflag:integer; procedure futil);
const extract_result=3;
begin
	fval:=sqr(xval-2);
	if iflag=extract_result then begin
		writeln('Main:fcn: final value of x is ',xval:1:3);
	end;
end;

procedure futil; 
begin 
end;

var
	val,err,lolim,hilim,param:longreal;
	iuint:integer;
	name:minuit_string;
	
begin
	writeln('Main: Welcome to Minuit in Pascal.');
 	mninit(5,6,7);
	mnparm(1,'X',0,0.01,-100,100,ierr);
	mncomd(fcn,'SIMPLEX',icondn,futil);
	mncomd(fcn,'CALL 3',icondn,futil);
	param:=3;
	mnexcm(fcn,'CALL',@param,1,ierr,futil);
	mnpout(1,name,val,err,lolim,hilim,iuint);
	writeln('Main: ',name,' ',val:1:3,' ',err:1:3,' ',lolim:1:3,' ',hilim:1:3,' ',iuint:1);
 	mnintr(fcn,futil);
end.
