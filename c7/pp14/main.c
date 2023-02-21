#include <stdio.h>
#include <math.h>
#include <float.h>

int main ()
{
  double x = 3, y = 1, xy, average, difference = 3;

  printf (" x   y          xy         average    difference\n");
  printf ("--------------------------------------------------\n");
  while (difference > 0.00001f)
  {
    xy = x / y;
    average = (y + xy) / 2;
    printf ("%2.0lf   %-8g   %-8g   %-8g   %-8g\n", x, y, xy, average, difference);

    difference = fabs (y - average);
    y = average;
  }

  return 0;
}
