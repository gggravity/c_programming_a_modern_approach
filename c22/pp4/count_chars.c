#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
  FILE *fp;

  if (argc != 2)
  {
    printf ("Usage: word_chars filename");
    exit (EXIT_FAILURE);
  }

  fp = fopen (argv[1], "r");

  if (fp == NULL)
  {
    fprintf (stderr, "Error opening file: %s", argv[1]);
    exit (EXIT_FAILURE);
  }

  int ch, count = 0;

  while ((ch = getc (fp)) != EOF)
  {
    count++;
  }

  printf ("%d", count);

  return 0;
}
