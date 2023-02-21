#include <stdio.h>

#define N 30
#define M 20

// you can cage a swallow can't you?
// 28 22 14 12 7 3

int main ()
{
  char words[N][M];
  char ch;
  int count = 0;

  printf ("Enter a sentence:");

  int n = 0, m = 0;

  while ((ch = (char)getchar ()) != '\n')
  {
    if (ch == ' ')
    {
      words[n++][m] = '\0';
      m = 0;
      count++;
    }
    else
    {
      words[n][m++] = ch;
    }
  }

  for (int i = count; i >= 0; i--)
  {
    printf ("%s ", words[i]);
  }

  return 0;
}
