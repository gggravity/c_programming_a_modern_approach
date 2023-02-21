#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

// Lloyd Fosdick

int main ()
{
  char lastname[20];
  char firstname, ch;
  bool flag = true;

  printf ("Enter a first and last name:");

  while ((ch = getchar ()) != ' ')
  {
    if (flag)
    {
      firstname = ch;
      flag = false;
    }
  }

  scanf ("%s", lastname);

  printf ("%s, %c.", lastname, firstname);

  return 0;
}
