#include <stdio.h>

int main ()
{
  int hours, minutes;

  printf ("Enter a 24-hour time [hh:mm]:");
  scanf ("%d:%d", &hours, &minutes);

  if (hours >= 13)
  {
    printf ("Equivalent 12-hour time: %02d:%02d PM", hours - 12, minutes);
  }
  else
  {
    printf ("Equivalent 12-hour time: %02d:%02d AM", hours, minutes);
  }

  return 0;
}
