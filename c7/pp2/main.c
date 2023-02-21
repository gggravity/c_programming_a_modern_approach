#include <stdio.h>

int main ()
{
  char enter, i, n = 100;

  for (i = 1; i <= n; i++)
  {
    if (i % 24 == 0)
    {
      printf ("Pres Enter to continue...");
      while (getchar () != '\n');
    }
    printf ("%10d %10d\n", i, i * i);
  }

  return 0;
}
