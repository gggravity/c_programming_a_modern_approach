#include <stdio.h>

// 17/2/2011

int main ()
{
  int day, month, year;

  char *months[] = {"", "January", "February", "Marts", "April", "May", "June", "July", "August", "September", "October",
                    "November", "December"};

  printf ("Enter a date (dd/mm/yyyy):");
  scanf ("%d / %d / %d", &day, &month, &year);

  printf ("You entered the date %d. %s, %d.", day, months[month], year);

  return 0;
}
