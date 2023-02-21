#include <stdio.h>
#include <ctype.h>

// it was deja vu all over again.

int main ()
{
  char c;
  float characters = 0, words = 1;

  while ((c = getchar ()) != '\n')
  {
    if (c == ' ')
      words++;
    else if (isalpha(c))
      characters++;
  }

  printf ("average words length: %.2f", characters / words);

  return 0;
}
