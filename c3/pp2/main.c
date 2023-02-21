#include <stdio.h>

int main ()
{
  int item_number, month, day, year;
  double price;

  printf ("Enter item number:");
  scanf ("%d", &item_number);

  printf ("Enter unit price:");
  scanf ("%lf", &price);

  printf ("Enter purchase date (mm/dd/yyyy):");
  scanf ("%d / %d / %d", &month, &day, &year);

  printf ("Item      Unit          Purchase\n");
  printf ("          Price         Date\n");
  printf ("%-10d$%6.2f\t%-2d/%02d/%02d", item_number, price, month, day, year);

  return 0;
}
