#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main (int argc, char *argv[])
{
  FILE *fp;

  if (argc != 2)
  {
    fprintf (stdout, "usage: toupper filename");
    exit(EXIT_FAILURE);
  }

  fp = fopen (argv[1], "r");

  if (fp == NULL)
  {
    fprintf (stderr, "Error opening: %s", argv[1]);
    exit (EXIT_FAILURE);
  }

  int ch;

  while ((ch = fgetc (fp)) != EOF)
  {
    if (isalpha(ch))
      putchar(toupper(ch));
    else
      putchar (ch);
  }

  return 0;
}