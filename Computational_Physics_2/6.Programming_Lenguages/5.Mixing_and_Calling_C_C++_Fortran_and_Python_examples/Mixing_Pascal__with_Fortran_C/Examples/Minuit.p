unit minuit;
{
	Interface between Pascal and Minuit libraries. Here we bring a
	library of Fortran 77 routines into Pascal through a series of
	wrapper routines written in Pascal. The wrappers perform several
	functions, the formost of which are.

	1. To allow Pascal to pass constants to Minuit routines. All Minuit
	routines take only pointers to variables, so you cannot pass
	constants to them directly. The wrapper assigns space in the stack
	for the constant and passes a pointer to its location int the stack.

	2. To allow Pascal to pass strings to Minuit routines. Although not
	explicitly stated in Fortran code, a Fortran subroutine that takes a
	string parameter must also receive the length of the string as an
	integer on the stack, at the end of the routine's argument list.

	We have done our best to make our Pascal wrapper routines appear
	exactly as they would in Fortran. The wrapper routine names are
	lower-case versions of the names in the origianal Fortran names. The
	direct calls to the Fortran routines have two names. One name
	applies when we call the routine in Pascal. This name is the Minuit
	name in lower case, prefixed by F_. The other name is the an exernal
	name for the linker. This is the Minuit name in lower case, suffixed
	by _. Pascal will not allow us to use internal names ending with an
	underscore, so we hade to make the internal and external names
	different. The external names are fixed by the Fortran compiler, and
	they have underscores at the end.

	For more information on linking Pascal and Fortran, source names,
	object names, and underscores, see:

	http://alignment.hep.brandeis.edu/Software/Mixing_Manual.html
}
interface

const
	minuit_string_length=255;
	minuit_param_name_length=10;

var
	ierr:integer;
	icondn:integer;
	
type
	futil_proc=procedure;
	fcn_proc=procedure (var npar:integer; 
		var grad,fval,xval:longreal; 
		var iflag:integer; futil:futil_proc);
	minuit_string=string[minuit_string_length];
	longreal_ptr=^longreal;

procedure mnuit(fcn:fcn_proc; futil:futil_proc); 
procedure mninit(input_channel,output_channel,error_channel:integer);
procedure mnparm(param_num:integer; param_name:minuit_string; 
	guess,step,lowlim,hilim:longreal; var ierr:integer);
procedure mnintr(fcn:fcn_proc; futil:futil_proc); 
procedure mncomd(fcn:fcn_proc; command:minuit_string; var icondn:integer;
	futil:futil_proc);
procedure mnexcm(fcn:fcn_proc; command:minuit_string; 
	plist:longreal_ptr; llist:integer;
	var ierr:integer; futil:futil_proc);
procedure mnerrs(param_num:integer; var eplus,eminus,eparab,gcc:longreal);
procedure mnstat(var fmin,fedm,errdef:longreal; var npari,nparx,istat:integer);
procedure mnpout(param_num:integer; var param_name:minuit_string;
	var val,err,lolim,hilim:longreal;
	var iuint:integer);

implementation

{
      SUBROUTINE MINUIT(FCN,FUTIL)
      
      We don't let this routine have the name "minuit" because
      our unit name is "minuit", and the two names will conflict.
      So we stick with mnuit.
}
procedure F_minuit(fcn:fcn_proc; futil:futil_proc); 
	external; attribute(name='minuit_');

procedure mnuit(fcn:fcn_proc; futil:futil_proc); 
begin
	F_minuit(fcn,futil);
end;

{
      SUBROUTINE MNINIT (I1,I2,I3)
}
procedure F_mninit(var i1,i2,i3:integer); 
	external; attribute(name='mninit_');
	
procedure mninit(input_channel,output_channel,error_channel:integer);
begin
	F_mninit(input_channel,output_channel,error_channel);
end;

{
      SUBROUTINE MNPARM(K,CNAMJ,UK,WK,A,B,IERFLG)
}
procedure F_mnparm(var k:integer;var cnamj:char; var uk,wk,a,b:longreal; 
	var ierflg:integer; cnamj_length:integer);
	external; attribute(name='mnparm_');
	
procedure mnparm(param_num:integer; param_name:minuit_string; 
	guess,step,lowlim,hilim:longreal; var ierr:integer);
begin
	F_mnparm(param_num,param_name[1],
		guess,step,lowlim,hilim,ierr,length(param_name));
end;

{
      SUBROUTINE MNINTR(FCN,FUTIL)
}
procedure F_mnintr(fcn:fcn_proc; futil:futil_proc); 
	external; attribute(name='mnintr_');

procedure mnintr(fcn:fcn_proc; futil:futil_proc); 
begin
	F_mnintr(fcn,futil);
end;

{
      SUBROUTINE MNCOMD(FCN,CRDBIN,ICONDN,FUTIL)
}
procedure F_mncomd(fcn:fcn_proc; var crdbin:char; var icondn:integer;
	futil:futil_proc; crdbin_length:integer);
	external; attribute(name='mncomd_');

procedure mncomd(fcn:fcn_proc; command:minuit_string; var icondn:integer;
	futil:futil_proc);
begin
	F_mncomd(fcn,command[1],icondn,futil,length(command));
end;

{
      SUBROUTINE MNEXCM(FCN,COMAND,PLIST,LLIST,IERFLG,FUTIL)
	
	mnexcm accepts a pointer to a longreal for its plist argument. This
	should either be nil, or it should point to the first longreal in an
	array of one or more longreals. You pass the number of longreals in 
	the array in integer argument llist.
}
procedure F_mnexcm(fcn:fcn_proc; var comand:char; plist:longreal_ptr; 
	var llist,ierflg:integer; futil:futil_proc; comand_length:integer);
	external; attribute(name='mnexcm_');

procedure mnexcm(fcn:fcn_proc; command:minuit_string; 
	plist:longreal_ptr; llist:integer;
	var ierr:integer; futil:futil_proc);
begin
	F_mnexcm(fcn,command[1],plist,llist,ierr,futil,length(command));
end;

{
      SUBROUTINE MNERRS(NUMBER,EPLUS,EMINUS,EPARAB,GCC)
}
procedure F_mnerrs(var number:integer; var eplus,eminus,eparab,gcc:longreal);
	external; attribute(name='mnerrs_');

procedure mnerrs(param_num:integer; var eplus,eminus,eparab,gcc:longreal);
begin
	F_mnerrs(param_num,eplus,eminus,eparab,gcc);
end;

{
      SUBROUTINE MNSTAT(FMIN,FEDM,ERRDEF,NPARI,NPARX,ISTAT)
}
procedure F_mnstat(var fmin,fedm,errdef:longreal; var npari,nparx,istat:integer);
	external; attribute(name='mnstat_');

procedure mnstat(var fmin,fedm,errdef:longreal; var npari,nparx,istat:integer);
begin
	F_mnstat(fmin,fedm,errdef,npari,nparx,istat);
end;

{
      SUBROUTINE MNPOUT(IUEXT,CHNAM,VAL,ERR,XLOLIM,XUPLIM,IUINT)
      
      This routine returns a string. We pass it an array of characters,
      and append the length of this array to the end of the Fortran routine's
      arguments. The Fortran routine copies its string into the character
      array and pads with spaces to our specified length. We transfer the
      contents of this array into param_name for the convenience of the 
      Pascal user.
}
procedure F_mnpout(var iuext:integer; var chnam:char; 
	var val,err,xlolim,xuplim:longreal;
	var iuint:integer; chnam_length:integer);
	external; attribute(name='mnpout_');

procedure mnpout(param_num:integer;var param_name:minuit_string;
	var val,err,lolim,hilim:longreal;
	var iuint:integer);
	
var 
	i:integer; 
	s:array [1..minuit_string_length] of char;
	
begin
	F_mnpout(param_num,s[1],val,err,lolim,hilim,iuint,minuit_string_length);
	i:=1;
	param_name:='';
	while (i<=minuit_string_length) and (s[i]<>' ') do begin
		param_name:=param_name+s[i];
		inc(i);
	end;
end;

end.
