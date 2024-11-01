/*
	Minuit_Main.c calls Minuit routines with the help of
	Minuit.h. Here's how we compile it on MacOS X.

	/usr/bin/gcc -o c.out Minuit_Main.c libmyminuit.a libf2c.a
*/

#include <stdio.h>
#include <string.h>

#include "minuit.h"

void fcn (int *npar, double *grad, double *fval, double *xval,
	int *iflag, void futil())
{
	#define extract_result 3
	*fval=(*xval-2) * (*xval-2);
	if (*iflag==extract_result) {
		printf("Main:fcn: final value of X is %f.\n",*xval);
	}
}

void futil () { }

int main (int argc, char **argv, char **envp)
{	
	double val,err,lolim,hilim,param;
	int iuint,ierr,icondn;
	char name[20]="test";
	
	printf("Main: Welcome to Minuit in C.");
 	mninit(5,6,7);
	mnparm(1,"X",0,0.01,-100,100,&ierr);
	mncomd(fcn,"SIMPLEX",&icondn,futil);
	mncomd(fcn,"CALL 3",&icondn,futil);
	param=3;
	mnexcm(fcn,"CALL",&param,1,&ierr,futil);
	mnpout(1,&name[0],&val,&err,&lolim,&hilim,&iuint);
	printf("Main: %s %f %f %f %f %f \n",name,val,err,lolim,hilim,iuint);
 	mnintr(fcn,futil);
}
