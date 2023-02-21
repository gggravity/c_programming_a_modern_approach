#include <stdio.h>

double compute(double x)
{
  double result;

  result = 3 * x * x * x * x * x;
  result += 2 * x * x * x * x;
  result -= 5 * x * x * x;
  result -= x * x;
  result += 7 * x;
  result -= 6;

  return result;
}

int main ()
{
  double input;
  printf ("Enter x to compute:");
  scanf("%lf", &input);

  printf ("the result is: %.2f", compute(input));

  return 0;
}
