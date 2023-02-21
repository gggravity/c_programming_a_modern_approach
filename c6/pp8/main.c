#include <stdio.h>

int main ()
{
  int number_of_days = 31, start_day = 3;

  for (int i = 1; i <= number_of_days; i++)
  {
    if (i <= start_day)
      printf ("   ");
    else
      printf ("%2d ", i);
    if (i % 7 == 0)
      printf ("\n");
  }

  return 0;
}
