#include <stdio.h>
#include <math.h>

int main ()
{

  double result, deposit, rate, years;

  printf ("Please enter amount to deposit:");
  scanf ("%lf", &deposit);

  printf ("Please enter rate in %%:");
  scanf ("%lf", &rate);

  rate /= 100;

  printf ("Please enter number of years for the deposit:");
  scanf ("%lf", &years);

  result =  deposit * exp (rate * years);

  printf ("The amount after %.f years are $ %.2f\n", years, result);

  return 0;
}
