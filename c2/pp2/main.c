#include <stdio.h>
#define FRACTION 4.0f / 3.0f
#define PI 3.14

int main ()
{
  int r = 10;
  double v = FRACTION * PI * r * r * r;

  printf ("radius: %d m -> volume: %.2f m^3\n", r, v);

  return 0;
}
