#include <stdio.h>
#include <ctype.h>

int main ()
{
  int hour, min;
  char ch;

  printf ("Enter a 12-hour time:");
  scanf ("%d : %d %c", &hour, &min, &ch);

  if (toupper (ch) == 'P')
  {
    hour += 12;
  }
    printf ("Equivalent 24-hour time: %02d:%02d", hour, min);

  return 0;
}
