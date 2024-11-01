/*
	Interface between C and Minuit libraries. The C routines
	names are the same as the Fortran names, but in lower
	case. The interface works by creating a C wrapper
	routine around a direct call to the Fortran routine. The
	Fortran routine names are the same as the wrapper
	routine names, but with an underscore on the end. This
	underscore, combined with the C compiler's rules for
	making object names our of source names, conspire to
	create an undefined symbol with a name that matches the
	defined symbol in the compiled Fortran library. That's
	if you are using GCC Fortran and C. For more information
	on linking C and Fortran with GCC, see:
	
	http://alignment.hep.brandeis.edu/Software/Mixing_Manual.html
*/

#include <string.h>

/* 
      SUBROUTINE MNINIT (I1,I2,I3)
*/
extern void mninit_(int *input_channel, int *output_channel, 
	int *error_channel); 	
void mninit(int input_channel, int output_channel, 
	int error_channel)
{
	mninit_(&input_channel,&output_channel,&error_channel);
}


/* 
      SUBROUTINE MNPARM(K,CNAMJ,UK,WK,A,B,IERFLG)
*/
extern void mnparm_ (int *k, char *cnamj, double *uk, double *wk, 
	double *a, double *b, int *ierflg, int cnamj_len); 	
void mnparm (int param_num, char param_name[20], double guess, 
	double step, double lowlim, double hilim, int *ierr)
{
	mnparm_(&param_num,&param_name[0],
		&guess,&step,&lowlim,&hilim,ierr,strlen(param_name));
}

/* 
      SUBROUTINE MNINTR(FCN,FUTIL)
*/
extern void mnintr_ (void fcn(), void futil());
void mnintr (void fcn(), void futil()) 
{
	mnintr_(fcn,futil);
}

/* 
      SUBROUTINE MINUIT(FCN,FUTIL)
*/
extern void minuit_ (void fcn(), void futil());
void minuit (void fcn(), void futil()) 
{
	minuit_(fcn,futil);
}


/* 
      SUBROUTINE MNCOMD(FCN,CRDBIN,ICONDN,FUTIL)
*/
extern void mncomd_ (void fcn(), char *crdbin, int *icondn, 
	void futil(), int crdbin_len);
void mncomd (void fcn(), char command[20], int *icondn, 
	void futil())
{
	mncomd_(fcn,&command[0],icondn,futil,strlen(command));
}

/* 
      SUBROUTINE MNEXCM(FCN,COMAND,PLIST,LLIST,IERFLG,FUTIL)
	
	mnexcm accepts a generic pointer type in its plist
	argument. This should either be nil, or it should point
	to one or more longreals. You pass the number of
	longreals in the array in integer argument llist.
*/
extern void mnexcm_ (void fcn(), char *comand, 
	double *plist, int *llist, int *ierflg, void futil(), 
	int comand_len);
void mnexcm (void fcn(), char command[20], double *plist, 
	int llist, int *ierr, void futil())
{
	mnexcm_(fcn,&command[0],plist,&llist,ierr,
		futil,strlen(command));
}


/* 
      SUBROUTINE MNERRS(NUMBER,EPLUS,EMINUS,EPARAB,GCC)
*/
extern void mnerrs_ (int *number, double *eplus, 
	double *eminus, double *eparab, double *gcc);
void mnerrs (int param_num, double *eplus, 
	double *eminus, double *eparab, double *gcc)
{
	mnerrs_ (&param_num,eplus,eminus,eparab,gcc);
}

/* 
      SUBROUTINE MNSTAT(FMIN,FEDM,ERRDEF,NPARI,NPARX,ISTAT)
*/
extern void mnstat_ (double *fmin, double *fedm, 
	double *errdef, int *npari, int *nparx, int *istat);
void mnstat (double *fmin, double *fedm, double *errdef, 
	int *npari, int *nparx, int *istat)
{
	mnstat_ (fmin,fedm,errdef,npari,nparx,istat);
}

/* 
      SUBROUTINE MNPOUT(IUEXT,CHNAM,VAL,ERR,XLOLIM,XUPLIM,IUINT)
      
      This routine returns a string. We pass it an array of
      characters, and append the length of this array to the
      end of the Fortran routine's arguments. The Fortran
      routine copies its string into the character array and
      pads with spaces to our specified length. So we have
      to get this Fortran string copied into the string
      pointed to by our param_name argument. We can't figure
      out a way to avoide repeating the constant 20 over and
      over, and the space character code 32 in this routine,
      short of using global compiler directives. We are not
      C experts, but there seems to be no way to define
      local compiler constants in C. So apologies for making
      it difficult for you to change the value 20 if you
      want to change it.
*/
extern void mnpout_ (int *iuext, char *chnam, double *val, 
	double *err, double *xlolim,
	double *xuplim, int *iuint, int chnam_len);
void mnpout (int param_num, char *param_name, double *val, 
	double *err, double *lolim,
	double *hilim, int *iuint)
{
	char s[20]="";
	int i;
	mnpout_(&param_num,&s[0],val,err,lolim,hilim,iuint,20);
	i=0;
	while (i < 20) {
		if (s[i] == 32) {s[i] = 0;};
		i++;
	}
	strcpy(param_name,s);
}


