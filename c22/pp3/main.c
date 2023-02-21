#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
  if (argc < 2)
  {
    printf ("usage fcat file1 file2 ... fileN");
    exit (EXIT_FAILURE);
  }

  FILE *fp;
  int ch;

  for (int i = 1; i < argc; i++)
  {
    fp = fopen (argv[i], "r");

    if (fp == NULL)
    {
      fprintf (stderr, "Error reading file: %s", argv[i]);
      exit (EXIT_FAILURE);
    }
    else
    {
      while ((ch = getc (fp)) != EOF)
      {
        putchar (ch);
      }
    }
  }

  return 0;
}
