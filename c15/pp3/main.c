#include <stdio.h>
#include "quicksort.h"
#define N 10

// 9 16 47 82 4 66 12 3 25 51

int main (void)
{
  int a[N];

  printf ("Enter %d numbers to be sorted:", N);
  for (int i = 0; i < N; i++)
    scanf ("%d", &a[i]);

  quicksort (a, 0, N - 1);

  printf ("In sorted order: ");
  for (int i = 0; i < N; i++)
    printf ("%d ", a[i]);
  printf ("\n");

  return 0;
}



















