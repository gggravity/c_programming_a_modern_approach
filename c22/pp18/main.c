#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMBER_OF_INTEGERS 10000

int compare_function (const void *a, const void *b);

int main (int argc, char *argv[])
{
  int integers[NUMBER_OF_INTEGERS];

  if (argc != 2)
  {
    printf ("usage: count input_file");
    exit (EXIT_FAILURE);
  }

  FILE *fp = fopen (argv[1], "r");

  if (fp == NULL)
  {
    perror ("error reading file");
    exit (EXIT_FAILURE);
  }

  int count = 0;
  while (count < NUMBER_OF_INTEGERS && !feof (fp))
  {
    fscanf (fp, " %d", &integers[count++]);
  }

  qsort (integers, count, sizeof (int), compare_function);

//  for (int *p = integers; p < integers + count; p++)
//    printf ("%d ", *p);

  printf ("largest number in the file: %d\n", integers[count - 1]);
  printf ("smallest number in the file: %d\n", integers[0]);

  int median;

  if (count % 2 == 0)
  {
    int m = (count - 1) / 2;
    median = (integers[m] + integers[m + 1]) / 2;
  }
  else
  {
    median = integers[(count - 1) / 2];
  }

  printf ("The median in the file: %d\n", median);

  return 0;
}

int compare_function (const void *a, const void *b)
{
  const int *ia = (const int *) a;
  const int *ib = (const int *) b;

  return *ia - *ib;
}