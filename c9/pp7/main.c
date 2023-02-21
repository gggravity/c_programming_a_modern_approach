#include <stdio.h>

int power (int x, int n)
{
  if (n == 0)
    return 1;
  else
    return x * power (x, n - 1);
}

int new_power (int x, int n)
{
  if (n == 0)
    return 1;
  else if (n % 2 == 0)
    return new_power (x, n / 2) * new_power (x, n / 2);
  else
    return x * power (x, n - 1);
}

int main ()
{
  printf ("power(5, 7): %d\n", power (5, 7));
  printf ("new_power(5, 7): %d\n", power (5, 7));
  return 0;
}
