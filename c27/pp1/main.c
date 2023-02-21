#include <stdio.h>
#include <complex.h>
#include <math.h>
//#include <tgmath.h>

int main (void)
{
  double a = 5, b = 2, c = 1;
//  double a = 1, b = 1, c = -2;

  double discriminant = b * b - 4 * a * c;
  double complex discriminant_sqrt = csqrt (discriminant);
  double complex root1 = (-b + discriminant_sqrt) / (2 * a);
  double complex root2 = (-b - discriminant_sqrt) / (2 * a);

  if (discriminant < 0)
  {
    printf ("root1 = %g %s %gi\n",
            creal (root1),
            signbit(cimag (root1)) ? "-" : "+",
            fabs (cimag (root1))
    );
    printf ("root2 = %g %s %gi\n",
            creal (root2),
            signbit(cimag (root2)) ? "-" : "+",
            fabs (cimag (root2))
    );
  }
  else
  {
    printf ("root1 = %g\n", creal (root1));
    printf ("root2 = %g\n", creal (root2));
  }

  return 0;
}
