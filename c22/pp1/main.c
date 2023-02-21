#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main (int argc, char *argv[])
{
  bool fail = false;
  FILE *fp;

  if (argc < 2)
  {
    printf ("usage: canopen filename\n");
    exit (EXIT_FAILURE);
  }

  for (int i = 1; i < argc; i++)
  {
    if ((fp = fopen (argv[i], "r")) == NULL)
    {
      fprintf (stderr, "%s can't be opened\n", argv[i]);
      fail = true;
    }
    else
    {
      fprintf (stdout, "%s can be opened\n", argv[i]);
    }
    fclose (fp);
  }

  if (fail)
    exit (EXIT_FAILURE);

  return 0;
}
