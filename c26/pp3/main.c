#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100000

int compare (const void *p, const void *q);
int compare_reverse (const void *p, const void *q);

int main ()
{

  srand (time (NULL));

  int arr[N];

  for (int i = 0; i < N; i++)
  {
    arr[i] = rand ();
  }

  qsort (arr, N, sizeof (int), compare_reverse);


  clock_t start_clock = clock ();

  qsort (arr, N, sizeof (int), compare);

  printf ("Processor time used: %g sec.\n", (clock () - start_clock) / (double) CLOCKS_PER_SEC);

  return 0;
}

int compare (const void *p, const void *q)
{
  const int *p1 = (const int *) p;
  const int *q1 = (const int *) q;

  return *p1 - *q1;
}

int compare_reverse (const void *p, const void *q)
{
  const int *p1 = (const int *) p;
  const int *q1 = (const int *) q;

  return *q1 - *p1;
}

