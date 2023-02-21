#include <stdio.h>

int main ()
{
  int number = 100;

  for (int i = 1, sqr = 2; sqr <= number; i++, sqr = i * i)
  {
    if (sqr % 2 == 0)
      printf ("%d\n", sqr);
  }

  return 0;
}
