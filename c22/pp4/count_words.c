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
    printf ("Usage: count_words filename");
    exit (EXIT_FAILURE);
  }

  fp = fopen (argv[1], "r");

  if (fp == NULL)
  {
    fprintf (stderr, "Error opening file: %s", argv[1]);
    exit (EXIT_FAILURE);
  }

  int ch, count = 0;
  char string[120];

  while (fgets(string, 120, fp))
  {
    size_t len = strlen(string);
    if (len == 0) continue;

    for(int i = 0; string[i] != '\0'; i++)
    {
      if (string[i] == ' ' || string[i] == '\n' )
        count++;
    }
  }

  printf ("%d", count);

  return 0;
}
