#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main ()
{
  char ch;

  while ((ch = getchar()) != EOF)
  {

    if (iscntrl (ch) && ch != '\n')
      putchar ('?');
    else
      putchar (ch);
  }
  return 0;
}
