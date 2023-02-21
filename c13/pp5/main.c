#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
  int sum = 0;
  if (argc > 1)
  {
    for (int i = 1; i < argc; i++)
      sum += atoi (argv[i]);

    printf ("the sum is: %d\n", sum);

  }
  else
  {
    printf ("usage: sum 8 24 62\n", sum);
    printf ("the sum is: 94");
  }
  return 0;
}
