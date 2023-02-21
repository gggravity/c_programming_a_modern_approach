#include <stdio.h>

int main ()
{
  float x = 1234.56789f;

  printf ("a: %-8.1e\n", x);
  printf ("b: %10.6e\n", x);
  printf ("c: %-8.3f\n", x);
  printf ("d: %6.0f\n", x);

  return 0;
}
