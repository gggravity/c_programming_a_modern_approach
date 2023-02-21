#include <stdio.h>
#define FRACTION 4.0f / 3.0f
#define PI 3.14

int main ()
{
  double r;
  double v;

  printf ("please enter radius of sphere: ");
  scanf ("%lf", &r);

  v = FRACTION * PI * r * r * r;

  printf ("radius: %.2f m -> volume: %.2f m^3\n", r, v);

  return 0;
}
