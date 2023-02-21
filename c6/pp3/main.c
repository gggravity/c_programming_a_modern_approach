#include <stdio.h>

// 6 12

int greatest_common_divisor (int n, int m)
{

  while (n != 0)
  {
    int divisor = m % n;
    m = n;
    n = divisor;
  }

  return m;
}

int main ()
{
  int n, m;

  printf ("Enter a fraction:");
  scanf ("%d%d", &n, &m);

  int gcd = greatest_common_divisor (n, m);

  printf ("In lowest terms: %d/%d", n / gcd, m / gcd);

  return 0;
}
