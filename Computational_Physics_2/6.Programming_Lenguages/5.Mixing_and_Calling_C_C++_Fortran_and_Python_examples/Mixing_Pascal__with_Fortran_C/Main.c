/*  http://www.bndhep.net/Software/Mixing/Mixing_Manual.html
	Main.c calls routines from C_Library.c, Fortran_Library.f, and
	Pascal_Library.p. See Manual.html for help.
*/

#include <stdio.h>
#include <string.h>

extern double C_Sqr(double x);
extern void C_Hello();

/* 
	_p_initialize is provided by libgpc.a to initialize the run-time library. 
*/
extern void _p_initialize (int argc, char **argv, char **envp, int options);
/* 
	p__M14_Pascal_library_init is the initialization procedure required by 
	Pascal_Library.o. You find out the name of this procedure using the nm
	utility at the command prompt. The M14 part will be different for different
	libraries. This is an example of one of Pascal's default two-level namespace
	routine names.
*/
extern int _p__M14_Pascal_library_init();

/*
	P_GlobalVar is a global variable declared in Pascal_Library.o, and initialized
	by the library's initialization procedure.
*/
extern int P_GlobalVar;

/*
	Here are some Pascal procedures from Pascal_Library.o.
*/
extern double P_Sqr(double x);
extern double P_Cube(double x);
extern void P_ReadVar();
extern void P_Add(int *i, int *j);

/*
	Here are some Fortran procedures from Fortran_Library.o.
*/
extern void f_sqr__(double *x, double *y);
extern void f_modulo__();
extern void nounderscores_();
extern void f_hello__();
extern void f_call__(void aprocedure(int *i,int *j));
extern void f_strings__(char *a_string, int *a_integer, char *b_string, float *a_real, 
	int len_a, int len_b);

int main (int argc, char **argv, char **envp)
{	
	printf("Main: Hello, this is Main talking.\n");
	fflush(stdout); /* So the text really appears now. */

	printf("Main: Calling C routines...\n");

	C_Hello();

	double x=2.2;
	printf("Main: The C_Sqr of %f is %f.\n",x,C_Sqr(x));

	printf("Main: Calling Pascal routines...\n");
	_p_initialize (argc, argv, envp, 0);	
	_p__M14_Pascal_library_init();
    printf("Main: P_GlobalVar was initialized to %d.\n",P_GlobalVar);

    P_ReadVar();
    printf("Main: P_GlobalVar is %d.\n",P_GlobalVar);

	printf("Main: The P_Sqr of %f is %f.\n",x,P_Sqr(x));

	printf("Main: The P_Cube of %i is %f.\n",P_GlobalVar,P_Cube(P_GlobalVar));

	printf("Main: Calling Fortran routines...\n");

	double y=3.3;
	f_sqr__(&x,&y);
	printf ("Main: The F_Sqr of %f is %f.\n",x,y);

	int i=5;
	int j=3;
	int k=-1;
	f_modulo__(&i,&j,&k);
    printf("Main: The F_Modulo of %i and %i is %i.\n",i,j,k);

	float w=4.4;
	float z=5.5;
	f_cube__(&w,&z);
    printf("Main: F_Cube of %.7f is %.7f.\n",w,z);

    nounderscores_();

	f_hello__();

	f_call__(P_Add);

	char astr[40]="A LONG STRING OF CAPITALS";
	char bstr[2]="X";
	printf("Main: astr is %i characters.\n",strlen(astr));
	printf("Main: bstr is %i characters.\n",strlen(bstr));
	
	/*
		Here we call the Fortran string routine twice, with
		a different way of generating the string pointers 
		each time.
	*/
    f_strings__(astr,&i,bstr,&w,strlen(astr),strlen(bstr));    
    f_strings__(&astr[0],&i,&bstr[0],&w,strlen(astr),strlen(bstr));    

    return 0;
}
