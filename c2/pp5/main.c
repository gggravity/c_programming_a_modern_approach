#include <stdio.h>

int main ()
{
  double x;
  printf ("enter the value of x: ");
  scanf ("%lf", &x);

  double result = 3 * x * x * x * x * x + 2 * x * x * x * x - 5 * x * x * x - x * x + 7 * x - 6;
  printf ("if x = %.2f, then 3x^5+2x^4-5x^3-x^2+7x-6 = %.2f", x, result);

  return 0;
}
