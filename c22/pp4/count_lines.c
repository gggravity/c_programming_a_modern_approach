//
// Created by martin on 09/11/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[])
{
  FILE *fp;

  if (argc != 2)
  {
    printf ("Usage: count_lines filename");
    exit (EXIT_FAILURE);
  }

  fp = fopen (argv[1], "r");

  if (fp == NULL)
  {
    fprintf (stderr, "Error opening file: %s", argv[1]);
    exit (EXIT_FAILURE);
  }

  int ch, count = 0;
  char string[1000];

  while (fgets(string, 1000, fp))
  {
        count++;
  }

  printf ("%d", count);

  return 0;
}
