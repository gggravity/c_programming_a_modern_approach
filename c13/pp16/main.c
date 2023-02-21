#include <stdio.h>
#include <string.h>

void reverse(char *message);

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

  *pnt_end = '\0';

  printf ("Reversal is:");

  reverse (message);

  return 0;
}

void reverse(char *message)
{
  size_t len = strlen(message);

  char *p = message + len;

  while (p > message)
  {
    printf ("%c", *--p);
  }


}