#include <stdio.h>

long long factorial (int n)
{
  if (n > 50)
    n = 50;

  long long factorial = 1;

  for (int i = 2; i < n; i++)
  {
    factorial *= i;
  }

  return factorial;
}

int main ()
{
  int n;
  double e = 0.0f;

  printf ("Enter n:");
  scanf ("%d", &n);

  for (int i = 1; i < n; i++)
  {
     e += 1.0f/(float)factorial(i);
  }

  printf("e is approximately: %lf", e);

  return 0;
}
