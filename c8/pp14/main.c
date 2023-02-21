#include <stdio.h>

// you can cage a swallow can't you?
// 28 22 14 12 7 3

int main ()
{
  char input[500];
  char stop = '?', ch;

  printf ("Enter a sentence:");

  int length = 0;
  while ((ch = getchar ()) != stop)
  {
    input[length++] = ch;
  }

  int last = length;

  printf ("Reversal of sentence:");

  for (int i = length; i >= 0; i--)
  {
    if (input[i] == ' ')
    {
      for (int j = i; j < last; j++)
      {
            printf ("%c", input[j]);
      }
      last = i;
    }
  }

  // no space before first word, need to print manual.
  printf(" ");
  for (int i = 0; input[i] != ' '; i++)
    printf ("%c", input[i]);
  printf("%c", stop);

  return 0;
}
