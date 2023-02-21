#include <stdio.h>

int main ()
{
  int d1, d2, d3, d4;

  printf ("Enter four integers:");
  scanf ("%d%d%d%d", &d1, &d2, &d3, &d4);

  if (d1 > d2 && d1 > d3 && d1 > d4)
    printf ("Largest: %d\n", d1);
  else if (d2 > d3 && d2 > d4)
    printf ("Largest: %d\n", d2);
  else if (d3 > d4)
    printf ("Largest: %d\n", d3);
  else
    printf ("Largest: %d\n", d4);

  if (d1 < d2 && d1 < d3 && d1 < d4)
    printf ("Smallest: %d\n", d1);
  else if (d2 < d3 && d2 < d4)
    printf ("Smallest: %d\n", d2);
  else if (d3 < d4)
    printf ("Smallest: %d\n", d3);
  else
    printf ("Smallest: %d\n", d4);


    return 0;
}
