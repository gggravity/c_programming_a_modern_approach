#include <stdio.h>

int main ()
{
  int number;

  printf ("Enter number:");
  scanf ("%d", &number);

  printf ("The numbers in reverse: ");
  do
  {
    printf ("%d", number % 10);
    number /= 10;
  }
  while (number > 0);

  return 0;
}
