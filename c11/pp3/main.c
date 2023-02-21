#include <stdio.h>

int greatest_common_divisor (int n, int m);
void reduce (int numerator, int denominator, int *reduced_numerator, int *reduced_denominator);

int main ()
{
  int n, m, reduced_numerator, reduced_denominator;

  printf ("Enter a fraction:");
  scanf ("%d%d", &n, &m);

  reduce (n, m, &reduced_numerator, &reduced_denominator);

  printf ("In lowest terms: %d/%d", reduced_numerator, reduced_denominator);

  return 0;
}

void reduce (int numerator, int denominator, int *reduced_numerator, int *reduced_denominator)
{
  int gcd = greatest_common_divisor (numerator, denominator);
  *reduced_numerator = numerator / gcd;
  *reduced_denominator = denominator / gcd;
}

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
