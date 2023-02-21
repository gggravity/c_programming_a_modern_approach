#include <stdio.h>

int factorial (int n)
{
  if (n > 20)
    n = 20;

  int factorial = 1;

  for (int i = 2; i < n; i++)
  {
    factorial *= i;
  }

  return factorial;
}

int main ()
{
  double n = 0.0000001f;
  double e = 1.0f;
  double to_add;

  int i = 1;

  do
  {
    i++;
    to_add = 1.0f/factorial(i);
    e += to_add;

  }
  while (to_add > n);

  printf("e is approximately: %f with %d loops", e, i);

  return 0;
}
