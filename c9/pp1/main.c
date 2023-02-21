#include <stdio.h>
#include <limits.h>

#define BUFFER 100

void selection_sort (int n, int array[n])
{
  int largest = INT_MIN, largest_index, temp;

  if (n == 0)
    return;

  for (int i = 0; i < n; i++)
  {
    if (array[i] > largest)
    {
      largest = array[i];
      largest_index = i;
    }
  }

  temp = array[n - 1];
  array[n - 1] = largest;
  array[largest_index] = temp;
  largest = INT_MIN;
  n--;

  selection_sort (n, array);

}

int main ()
{
  int input[BUFFER];
  int c, len = 0;

  printf ("Enter a series of single digit integers:");
  while ((c = getchar ()) != '\n')
  {
    if (c != ' ')
    {
      input[len] = c - '0';
      len++;
    }
  }

  printf ("the numbers in sorted order are:\n");
  selection_sort (len, input);

  for (int i = 0; i < len; i++)
  {
    printf ("%d ", input[i]);
  }

  printf ("\n");

  return 0;
}
