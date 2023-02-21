#include <stdio.h>

// Don't get mad, get even.

int main ()
{
  char ch;
  char message[100];
  char *pnt_end = message;

  printf ("Enter a message:");

  while ((ch = (char) getchar ()) != '\n')
  {
    *pnt_end++ = ch;
  }

  printf ("Reversal is:");

  while (pnt_end > message)
  {
    printf ("%c", *--pnt_end);
  }

  return 0;
}
