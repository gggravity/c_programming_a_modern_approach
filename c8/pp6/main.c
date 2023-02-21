#include <stdio.h>
#include <ctype.h>
// Hey, dude, C is rilly cool

int main ()
{
  char c;

  printf ("Enter message:");

  while ((c = getchar ()) != '\n')
  {
    c = (char) toupper (c);

    switch (c)
    {
    case 'A':
      c = '4';
      break;
    case 'B':
      c = '8';
      break;
    case 'E':
      c = '3';
      break;
    case 'I':
      c = '1';
      break;
    case 'O':
      c = '0';
      break;
    case 'S':
      c = '5';
      break;
    default:
      break;
    }
    printf("%c", c);
  }
  printf("!!!!!!!!!");

  return 0;
}
