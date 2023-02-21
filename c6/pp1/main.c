#include <stdio.h>

// 60 38.3 4.89 100.62  75.2295 0

int main ()
{
  double number, largest = 0;

  for (;;)
  {
    printf ("Enter a number:");
    scanf ("%lf", &number);

    if (!number)
      break;

    if (number > largest)
      largest = number;

  }

  printf ("The largest number entered was %.2f", largest);

  return 0;
}
