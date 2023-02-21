#include <stdio.h>

// you can cage a swallow can't you?
// 28 22 14 12 7 3

int main ()
{
  char input[500];
  char stop = '?', ch;
  char *length = input;

  printf ("Enter a sentence:");

  while ((ch = (char) getchar ()) != stop)
  {
    *length++ = ch;
  }

  char *last = length;

  printf ("Reversal of sentence:");

  for (; length >= input; length--)
  {
    if (*length == ' ')
    {
      for (char *p = length; p < last; p++)
      {
        printf ("%c", *p);
      }
      last = length;
    }
  }

  printf (" ");
  for (char *p = input; *p != ' '; p++)
    printf ("%c", *p);
  printf ("%c", stop);

  return 0;
}
