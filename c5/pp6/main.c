#include <stdio.h>
// 013800151735
int main ()
{
  int d, i1, i2, i3, i4, i5, j1, j2, j3, j4, j5, first_sum, second_sum, total, last;

  printf ("Please enter a 12 digits UPC:");
  scanf ("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &d, &i1, &i2, &i3, &i4, &i5, &j1, &j2, &j3, &j4, &j5, &last);

  first_sum = d + i2 + i4 + j1 + j3 + j5;
  second_sum = i1 + i3 + i5 + j2 + j4;
  total = 3 * first_sum + second_sum;

  int check = 9 - ((total - 1) % 10);

  if (check == last)
    printf ("The UPC is correct");
  else
    printf ("The UPC is incorrect");

  return 0;
}
