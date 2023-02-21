#include <stdio.h>

int main ()
{
  int n = 10, odd = 3;

  for (int i = 1, square = 1; i <= n; odd += 2, ++i)
  {
    printf ("%10d%10d\n", i, square);
    square += odd;
  }

  return 0;
}
