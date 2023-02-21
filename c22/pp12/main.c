#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
  int item_number, month, day, year;
  double price;

  if (argc != 2)
  {
    printf ("Usage: program datafile\n");
    exit (EXIT_FAILURE);
  }

  FILE *fp = fopen (argv[1], "r");

  if (fp == NULL)
  {
    fprintf (stderr, "can't open file: %s\n", argv[1]);
  }

  char *buffer;
  size_t buffer_size;
  size_t n;

  printf ("Item      Unit Price    Purchase Date\n");
  printf ("-------------------------------------\n");

  while ((n = getline (&buffer, &buffer_size, fp)) != EOF)
  {
    sscanf (buffer, "%d , %lf , %d / %d / %d", &item_number, &price, &month, &day, &year);
    printf ("%-10d$%9.2f       %02d/%02d/%02d\n", item_number, price, month, day, year);
  }

  return 0;
}
