#include <stdio.h>

int main ()
{
  int num1, num2;

  printf ("Enter a two-digit number:");
  scanf ("%1d%1d", &num1, &num2);

  printf ("The reversal is: %1d%1d", num2, num1);

  return 0;
}
