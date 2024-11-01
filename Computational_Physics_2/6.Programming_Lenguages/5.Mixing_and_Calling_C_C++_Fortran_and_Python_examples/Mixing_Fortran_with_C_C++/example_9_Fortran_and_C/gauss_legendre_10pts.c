////////////////////////////////////////////////////////////////////////////////
// File: gauss_legendre_10pts.c                                               //
// Routines:                                                                  //
//    long double Gauss_Legendre_Integration_10pts( long double a, long double b,            //
//                                                     long double (*f)(long double) )  //
//    void   Gauss_Legendre_Zeros_10pts( long double zeros[] )                     //
//    void   Gauss_Legendre_Coefs_10pts( long double coef[] )                      //
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// The n-th Legendre polynomial is                                            //
//                 Pn(x) = 1/(2^n n!) (d/dx)^n (x^2-1)^n.                     //
// For the n point Gauss-Legendre integral approximation formula the          //
// coefficients are A[i] = 2 (1 - x[i]^2) / (n P(n-1)(x[i])^2 where x[i] is   //
// a zero of the n-th Legendre polynomial Pn(x).                              //
// Note that if x is a zero of Pn(x) then -x is also a zero of Pn(x) and the  //
// coefficients associated with x and -x are equal.                           //
////////////////////////////////////////////////////////////////////////////////

static const long double x[] = {
    1.48874338981631210881e-01,    4.33395394129247190794e-01,
    6.79409568299024406207e-01,    8.65063366688984510759e-01,
    9.73906528517171720066e-01
};

static const long double A[] = {
    2.95524224714752870187e-01,    2.69266719309996355105e-01,
    2.19086362515982044000e-01,    1.49451349150580593150e-01,
    6.66713443086881375920e-02
};

#define NUM_OF_POSITIVE_ZEROS  sizeof(x) / sizeof(long double)
#define NUM_OF_ZEROS           NUM_OF_POSITIVE_ZEROS+NUM_OF_POSITIVE_ZEROS

////////////////////////////////////////////////////////////////////////////////
//  long double Gauss_Legendre_Integration_10pts( long double a, long double b,              //
//                                                      long double (*f)(long double))  //
//                                                                            //
//  Description:                                                              //
//     Approximate the integral of f(x) from a to b using the 10 point Gauss- //
//     Legendre integral approximation formula.                               //
//                                                                            //
//  Arguments:                                                                //
//     long double  a   Lower limit of integration.                                //
//     long double  b   Upper limit of integration.                                //
//     long double *f   Pointer to function of a single variable of type long double.   //
//                                                                            //
//  Return Values:                                                            //
//     The integral of f from a to b.                                         //
//                                                                            //
//  Example:                                                                  //
//     {                                                                      //
//        long double f(long double);                                                   //
//        long double integral, lower_limit, upper_limit;                          //
//                                                                            //
//        (determine lower and upper limits of integration)                   //
//        integral = Gauss_Legendre_Integration_10pts(lower_limit,            //
//                                                          upper_limit, f);  //
//        ...                                                                 //
//     }                                                                      //
//     long double f(long double x) { define f }                                        //
////////////////////////////////////////////////////////////////////////////////
//                                                                            //
long double 
  Gauss_Legendre_Integration_10pts( long double a, long double b, long double (*f)(long double) )
{
   long double integral; 
   long double c = 0.5 * (b - a);
   long double d = 0.5 * (b + a);
   long double dum;

   dum = c * x[4];
   integral = A[4] * ((*f)(d - dum) + (*f)(d + dum));
   dum = c * x[3];
   integral += A[3] * ((*f)(d - dum) + (*f)(d + dum));
   dum = c * x[2];
   integral += A[2] * ((*f)(d - dum) + (*f)(d + dum));
   dum = c * x[1];
   integral += A[1] * ((*f)(d - dum) + (*f)(d + dum));
   dum = c * x[0];
   integral += A[0] * ((*f)(d - dum) + (*f)(d + dum));

   return c * integral;
}


////////////////////////////////////////////////////////////////////////////////
//  void Gauss_Legendre_Zeros_10pts( long double zeros[] )                         //
//                                                                            //
//  Description:                                                              //
//     Returns the zeros of the Legendre polynomial P10.                      //
//                                                                            //
//  Arguments:                                                                //
//     long double zeros[] Array in which to store the zeros of P10.  This array   //
//                    should be dimensioned 10 in the caller function.        //
//                    The order is from the minimum zero to the maximum.      //
//                                                                            //
//  Return Values:                                                            //
//     none                                                                   //
//                                                                            //
//  Example:                                                                  //
//     long double z[10];                                                          //
//     int i;                                                                 //
//                                                                            //
//     Gauss_Legendre_Zeros_10pts( z );                                       //
//     printf("The zeros of the Legendre polynomial P10 are:");               //
//     for ( i = 0; i < 10; i++) printf("%12.6le\n",z[i]);                    //
////////////////////////////////////////////////////////////////////////////////
//                                                                            //
void Gauss_Legendre_Zeros_10pts( long double zeros[] ) {
   
   const long double *px = &x[NUM_OF_POSITIVE_ZEROS - 1];
   long double *pz = &zeros[NUM_OF_ZEROS - 1];

   for (; px >= x; px--)  {
      *(zeros++) = - *px;
      *(pz--) = *px;
   }   
}


////////////////////////////////////////////////////////////////////////////////
//  void Gauss_Legendre_Coefs_10pts( long double coef[] )                          //
//                                                                            //
//  Description:                                                              //
//     Returns the coefficients for the 10 point Gauss-Legendre formula.      //
//                                                                            //
//  Arguments:                                                                //
//     long double coef[]  Array in which to store the coefficients of the Gauss-  //
//                    Legendre formula.  The coefficient A[i] is associated   //
//                    with the i-th zero as returned in the function above    //
//                    Gauss_Legendre_Zeros_10pts.                             //
//                                                                            //
//  Return Values:                                                            //
//     none                                                                   //
//                                                                            //
//  Example:                                                                  //
//     long double a[10];                                                          //
//     int i;                                                                 //
//                                                                            //
//     Gauss_Legendre_Coefs_10pts( a );                                       //
//     printf("The coefficients for the Gauss-Legendre formula are :\n");     //
//     for (i = 0; i < 10; i++) printf("%12.6lf\n",a[i]);                     //
////////////////////////////////////////////////////////////////////////////////
//                                                                            //
void Gauss_Legendre_Coefs_10pts( long double coefs[] ) {

   const long double *pA = &A[NUM_OF_POSITIVE_ZEROS - 1];
   long double *pc = &coefs[NUM_OF_ZEROS - 1];

   for (; pA >= A; pA--)  {
      *(coefs++) =  *pA;
      *(pc--) = *pA;
   }   
}
