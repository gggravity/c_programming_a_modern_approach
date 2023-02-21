#include <stdio.h>

int main ()
{
  char i;

  for (i = 1; ; i++)
  {
    printf ("%10d %10d\n", i, i * i);
  }

  return 0;
}
