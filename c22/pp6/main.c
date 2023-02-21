#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define N 10

int main (int argc, char *argv[])
{
  if (argc != 2)
  {
    printf ("usage: program file");
    exit (EXIT_FAILURE);
  }

  FILE *fp = fopen (argv[1], "r");

  if (fp == NULL)
  {
    fprintf (stderr, "error opening file");
    exit (EXIT_FAILURE);
  }

  printf ("Offset              Bytes              Characters\n");
  printf ("------  -----------------------------  ----------\n");

  int ch = 0;
  int buffer[N];

  for (int offset = 0; ch != EOF; offset += 10)
  {
    fseek (fp, offset, SEEK_SET);

    printf ("%6d  ", offset);

    int count = 0;
    while ((ch = fgetc (fp)) != EOF && count < N)
    {
      buffer[count] = ch;
      count++;
    }

    for (int *p = buffer; p < buffer + count; p++)
      printf ("%02X ", *p);

    printf (" ");

    if (count < N)
    {
      for (int i = 0; i < N - count; i++)
        printf ("   ");
    }

    for (int *p = buffer; p < buffer + count; p++)
    {
      if (isprint(*p))
        printf ("%c", *p);
      else
        printf (".");
    }
    printf ("\n");
  }

  return 0;
}
