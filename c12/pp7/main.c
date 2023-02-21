#include <stdio.h>
#include <limits.h>

// 34 82 49 102 7 94 23 11 50 31

#define N 10

void max_min (const int a[], int n, int *max, int *min);

int main ()
{
  int b[N], i, big, small;

  printf ("Enter %d numbers:", N);
  for (i = 0; i < N; i++)
    scanf ("%d", &b[i]);

  max_min (b, N, &big, &small);

  printf ("Largest: %d\n", big);
  printf ("Smallest: %d\n", small);

  return 0;
}

void max_min (const int a[], int n, int *max, int *min)
{
  *max = INT_MIN;
  *min = INT_MAX;

  for (const int *p = a; p < a + n; p++)
    if (*p > *max)
      *max = *p;
    else if (*p < *min)
      *min = *p;
}