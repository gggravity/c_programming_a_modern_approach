#include <stdio.h>

int main ()
{
  int number;
  printf("Enter a number:");
  scanf("%d", &number);

  if (number < 0)
    printf ("Number should be positive.");
  else if (number < 10)
    printf ("Number have 1 digit.");
  else if (number < 100)
    printf ("Number have two digits.");
  else if (number < 1000)
    printf ("Number have three digits.");
  else
    printf ("Number more then three digits.");

  return 0;
}
