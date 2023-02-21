#include <stdio.h>

// 12 28

int main ()
{
  int n, m;

  printf ("Enter two integers:");
  scanf ("%d%d", &n, &m);

  while (n != 0)
  {
    int divisor = m % n;
    m = n;
    n = divisor;
  }

  printf ("Greatest common divisor: %d", m);

  return 0;
}
