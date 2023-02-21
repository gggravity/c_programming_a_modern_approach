#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
  if (argc != 3)
  {
    printf ("Usage: ......");
    exit (EXIT_FAILURE);
  }

  FILE *fp_in = fopen (argv[1], "rb");
  FILE *fp_out = fopen (argv[2], "wb");

  if (fp_in == NULL || fp_out == NULL)
  {
    perror ("File error.");
    exit (EXIT_FAILURE);
  }

  int ch;
  while ((ch = getc (fp_in)) != EOF)
  {
    if (ch == '\x0a')
    {
      fputc ('\x0d', fp_out);
      fputc ('\x0a', fp_out);
    }
    else
    {
      fputc (ch, fp_out);
    }
  }

  return 0;
}