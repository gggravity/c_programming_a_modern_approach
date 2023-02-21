#include <stdio.h>

#define N 10

// 9 16 47 82 4 66 12 3 25 51

void quicksort (int a[], int low, int high);
int split (int a[], int low, int high);
void quicksort_old (int a[], int low, int high);
int split_old (int a[], int low, int high);

int main ()
{

  int a[N] = {9, 16, 47, 82, 4, 66, 12, 3, 25, 51}, b[N], i;

//  printf ("Enter %d numbers to be sorted:", N);
//  for (i = 0; i < N; i++)
//    scanf ("%d", &a[i]);

  // copy a to b
  for (int *pa = a, *pb = b; pa < a + N; pa++, pb++)
    *pb = *pa;

  quicksort_old (a, 0, N - 1);

  printf ("In sorted order old: ");
  for (i = 0; i < N; i++)
    printf ("%d ", a[i]);
  printf ("\n");

  quicksort (b, 0, N - 1);

  printf ("In sorted order new: ");
  for (i = 0; i < N; i++)
    printf ("%d ", b[i]);
  printf ("\n");

  return 0;
}

void quicksort (int a[], int low, int high)
{
  int middle;

  if (low >= high)
    return;

  middle = split (a, low, high);
  quicksort (a, low, middle - 1);
  quicksort (a, middle + 1, high);
}

int split (int a[], int low, int high)
{

  int part_element = *(a + low);

  for (;;)
  {
    while (low < high && part_element <= *(a + high))
      high--;

    if (low >= high)
      break;

    *(a + low++) = *(a + high);

    while (low < high && *(a + low) <= part_element)
      low++;

    if (low >= high)
      break;

    *(a + high--) = *(a + low);
  }

  *(a + high) = part_element;

  return high;
}

void quicksort_old (int a[], int low, int high)
{
  int middle;

  if (low >= high)
    return;

  middle = split_old (a, low, high);
  quicksort_old (a, low, middle - 1);
  quicksort_old (a, middle + 1, high);
}

int split_old (int a[], int low, int high)
{
  int part_element = a[low];

  for (;;)
  {
    while (low < high && part_element <= a[high])
      high--;

    if (low >= high)
      break;

    a[low++] = a[high];

    while (low < high && a[low] <= part_element)
      low++;

    if (low >= high)
      break;

    a[high--] = a[low];
  }

  a[high] = part_element;

  return high;
}