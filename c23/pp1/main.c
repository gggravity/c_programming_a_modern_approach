#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void find_roots (double a, double b, double c);

int main ()
{
  find_roots (1,23,3);

  return 0;
}

void find_roots (double a, double b, double c)
{
  double part1 = -b;
  double complex = (b * b) - (4 * a * c);
  double part2 = sqrt (complex);
  double part3 = 2 * a;

  if (complex < 0)
  {
    fprintf(stderr, "The answer is complex");
    exit (EXIT_FAILURE);
  }

  double x1 = (part1 + part2) / part3;
  double x2 = (part1 - part2) / part3;

  printf ("x1: %f, x2: %f", x1, x2);
}
