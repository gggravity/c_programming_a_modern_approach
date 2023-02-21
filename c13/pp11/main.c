#include <stdio.h>
#include <ctype.h>

#define N 100
// it was deja vu all over again.
// 3.29

double compute_average_word_length (const char *sentence);
int readline (char str[], int n);

int main ()
{
  char sentence[N];
  printf ("Enter a sentence:");
  readline (sentence, N);

  printf ("%s\n", sentence);
  printf ("average words length: %.2f", compute_average_word_length (sentence));

  return 0;
}

double compute_average_word_length (const char *sentence)
{
  char *p = (char *) sentence;

  double characters = 0, words = 1;

  while (*p)
  {
    if (*p == ' ')
      words++;
    else if (isalpha (*p))
    {
      characters++;
    }
    p++;
  }

  return characters / words;
}

int readline (char str[], int n)
{
  char ch;
  int i = 0;

  while ((ch = (char) getchar ()) != '\n')
    if (i < n)
      str[i++] = ch;
  str[i] = '\0';

  return i;
}