#include <stdio.h>
#include <complex.h>
#include <math.h>

int main ()
{
  double real, imaginary, r, theta;

  printf ("Enter real value of complex number: ");
  scanf ("%lf", &real);
  printf ("Enter imaginary value of complex number: ");
  scanf ("%lf", &imaginary);

  r = sqrt (real * real + imaginary * imaginary);
  theta = atan (real / imaginary);

  printf ("r = %g\ntheta = %g rads\n", r, theta);

  return 0;
}
