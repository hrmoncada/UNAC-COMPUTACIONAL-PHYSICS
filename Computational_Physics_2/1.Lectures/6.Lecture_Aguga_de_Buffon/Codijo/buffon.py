#! /usr/bin/env python
#  https://people.math.sc.edu/Burkardt/py_src/prob/buffon.py
def buffon_pdf ( a, l ):

#*****************************************************************************80
#
## BUFFON_PDF evaluates the Buffon PDF.
#
#  Discussion:
#
#    In the Buffon needle experiment, we suppose that the plane has been
#    ruled by vertical lines with a spacing of A units, and that a
#    needle of length L is dropped "at random" onto this grid.
#
#    Because of the various symmetries, we may assume that this eye of
#    this needle lands in the first infinite strip, and we may further
#    assume that its Y coordinate is 0.  Thus, we have
#    the eye as (X1,Y1) with 0 <= X1 <= A and Y1 = 0.
#
#    ANGLE, the angle that the needle makes is taken to be uniformly random.
#    The point of the needle, (X2,Y2), therefore lies at
#
#      (X2,Y2) = ( X1+L*cos(ANGLE), Y1+L*sin(ANGLE) )
#
#    The needle will have crossed at least one grid line if any of the
#    following are true:
#
#      X2 <= 0, A <= X2.
#
#    The probability of a crossing on a single trial is
#
#      P(A,L) = ( 2 * L ) / ( PI * A )
#
#    and therefore, a record of the number of hits for a given number of
#    trials can be used as a very roundabout way of estimating PI.
#
#  Licensing:
#
#    This code is distributed under the GNU LGPL license.
#
#  Modified:
#
#    10 April 2016
#
#  Author:
#
#    John Burkardt
#
#  Parameters:
#
#    Input, real A, the horizontal spacing between the
#    vertical grid lines.  0 <= A.
#
#    Input, real L, the length of the needle.
#
#    Output, real PDF, the Buffon PDF.
#
  import numpy as np
  from sys import exit

  if ( a < 0.0 ):
    print ( '' )
    print ( 'BUFFON_PDF - Fatal error!' )
    print ( '  Input A < 0.' )
    exit ( 'BUFFON_PDF - Fatal error!' )
  elif ( a == 0.0 ):
    pdf = 1.0
    return pdf

  if ( l < 0.0 ):
    print ( '' )
    print ( 'BUFFON_PDF - Fatal error!' )
    print ( '  Input L < 0.' )
    exit ( 'BUFFON_PDF - Fatal error!' )
  elif ( l == 0.0 ):
    pdf = 0.0
    return pdf

  pdf = ( 2.0 * l ) / ( np.pi * a )

  return pdf

def buffon_pdf_test ( ):

#*****************************************************************************80
#
## BUFFON_PDF_TEST tests BUFFON_PDF.
#
#  Licensing:
#
#    This code is distributed under the GNU LGPL license.
#
#  Modified:
#
#    10 April 2016
#
#  Author:
#
#    John Burkardt
#
  import platform

  print ( '' )
  print ( 'BUFFON_PDF_TEST' )
  print ( '  Python version: %s' % ( platform.python_version ( ) ) )
  print ( '  BUFFON_PDF evaluates the Buffon PDF,' )
  print ( '  the probability that, on a grid of cells of width A,' )
  print ( '  a needle of length L, dropped at random,' )
  print ( '  will cross at least one grid line.' )
  print ( '' )
  print ( '      A         L        PDF' )
  print ( '' )

  for i in range ( 1, 6 ):
    a = float ( i )
    for k in range ( 0, 6 ):
      l = float ( k ) * a / 5.0
      pdf = buffon_pdf ( a, l )
      print ( '  %8.4g  %8.4g  %14g' % ( a, l, pdf ) )

    print ( '' )
#
#  Terminate.
#
  print ( '' )
  print ( 'BUFFON_PDF_TEST' )
  print ( '  Normal end of execution.' )
  return

def buffon_sample ( a, l, trial_num, seed ):

#*****************************************************************************80
#
## BUFFON_SAMPLE simulates a Buffon needle experiment.
#
#  Discussion:
#
#    In the Buffon needle experiment, we suppose that the plane has been
#    ruled by vertical lines with a spacing of A units, and that a
#    needle of length L is dropped "at random" onto this grid.
#
#    Because of the various symmetries, we may assume that this eye of
#    this needle lands in the first infinite strip, and we may further
#    assume that its Y coordinate is 0.  Thus, we have
#    the eye as (X1,Y1) with 0 <= X1 <= A and Y1 = 0.
#
#    ANGLE, the angle that the needle makes is taken to be uniformly random.
#    The point of the needle, (X2,Y2), therefore lies at
#
#      (X2,Y2) = ( X1+L*cos(ANGLE), Y1+L*sin(ANGLE) )
#
#    The needle will have crossed at least one grid line if any of the
#    following are true:
#
#      X2 <= 0, A <= X2.
#
#    The probability of a crossing on a single trial is
#
#      P(A,L) = ( 2 * L ) / ( PI * A )
#
#    and therefore, a record of the number of hits for a given number of
#    trials can be used as a very roundabout way of estimating PI.
#
#    Note that this routine will try to generate 4 * TRIAL_NUM random
#    double precision values at one time, using automatic arrays.
#    When I tried this with TRIAL_NUM = 1,000,000, the program failed,
#    because of internal system limits on such arrays.
#
#    Such a problem could be avoided by using a DO loop running through
#    each trial individually, but this tend to run much more slowly than
#    necessary.
#
#    Since this routine invokes the FORTRAN90 random number generator,
#    the user should initialize the random number generator, particularly
#    if it is desired to control whether the sequence is to be varied
#    or repeated.
#
#  Licensing:
#
#    This code is distributed under the GNU LGPL license.
#
#  Modified:
#
#    10 April 2016
#
#  Author:
#
#    John Burkardt
#
#  Parameters:
#
#    Input, real A, the horizontal spacing between the
#    vertical grid lines.  0 <= A.
#
#    Input, real L, the length of the needle.
#
#    Input, integer TRIAL_NUM, the number of times the needle is
#    to be dropped onto the grid.
#
#    Input/output, integer SEED, a seed for the random number generator.
#
#    Output, integer BUFFON_SAMPLE, the number of times the needle
#    crossed at least one line of the grid of cells.
#
#  Local Parameters:
#
#    Local, integer BATCH_SIZE, specifies the number of trials to be done
#    in a single batch.  Setting BATCH_SIZE to 1 will be very slow.
#    Replacing it by TRIAL_NUM would be fine except that your system
#    may have a limit on the size of automatic arrays.  We have set a default
#    value of 10,000 here which should be large enough to be efficient
#    but small enough not to annoy the system.
#
  import numpy as np
  from r8_uniform_01 import r8_uniform_01

  batch_size = 10000

  hits = 0

  for batch in range ( 0, trial_num ):
#
#  Randomly choose the location (X1,Y1) of the eye of the needle
#  in [0,0]x[A,0], and the angle the needle makes.
#
    x1, seed = r8_uniform_01 ( seed )
    x1 = a * x1
    angle, seed = r8_uniform_01 ( seed )
    angle = 2.0 * np.pi * angle
#
#  Compute the location of the point of the needle.
#  We only need to know the value of X2, not Y2!
#
    x2 = x1 + l * np.cos ( angle )
#
#  Count the end locations that lie outside the cell.
#
    if ( x2 <= 0.0 or a <= x2 ):
      hits = hits + 1

  return hits, seed

def buffon_sample_test ( ):

#*****************************************************************************80
#
## BUFFON_SAMPLE_TEST tests BUFFON_SAMPLE.
#
#  Licensing:
#
#    This code is distributed under the GNU LGPL license.
#
#  Modified:
#
#    10 April 2016
#
#  Author:
#
#    John Burkardt
#
  import numpy as np
  import platform

  test_num = 4

  trial_num_test = np.array ( [ 10, 100, 10000, 1000000 ] )

  a = 1.0
  l = 1.0
  seed = 123456789

  print ( '' )
  print ( 'BUFFON_SAMPLE_TEST' )
  print ( '  Python version: %s' % ( platform.python_version ( ) ) )
  print ( '  BUFFON_SAMPLE simulates a Buffon-Laplace' )
  print ( '  needle dropping experiment.  On a grid of cells of ' )
  print ( '  width A, a needle of length L is dropped' )
  print ( '  at random.  We count the number of times it crosses' )
  print ( '  at least one grid line, and use this to estimate ' )
  print ( '  the value of PI.' )

  print ( '' )
  print ( '  Cell width A =    %g' % ( a ) )
  print ( '  Needle length L = %g' % ( l ) )
  print ( '' )
  print ( '    Trials      Hits          Est(Pi)     Err' )
  print ( '' )
 
  for test in range ( 0, 4 ):

    trial_num = trial_num_test[test]

    hits, seed = buffon_sample ( a, l, trial_num, seed )

    if ( 0 < hits ):
      pi_est = ( 2.0 * l * trial_num ) / ( a * hits )
    else:
      pi_est = 1.0E+30

    err = abs ( pi_est - np.pi )

    print ( '  %8d  %8d  %14g  %14g' % ( trial_num, hits, pi_est, err ) )
#
#  Terminate.
#
  print ( '' )
  print ( 'BUFFON_SAMPLE_TEST' )
  print ( '  Normal end of execution.' )
  return

if ( __name__ == '__main__' ):
  from timestamp import timestamp
  timestamp ( ) 
  buffon_pdf_test ( )
  buffon_sample_test ( )
  timestamp ( )
 
