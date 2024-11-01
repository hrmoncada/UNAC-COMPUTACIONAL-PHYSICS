/* Interfaces to FORTRAN77 routines. The names now have underscores appended, and
  scalar parameters are passed by reference.*/
extern void kronrod_ ( int *n, double *eps, double x[], double w1[],
  double w2[], int *ier );
extern void timestamp_ ( );

