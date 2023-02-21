#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// dog zebra rabbit catfish walrus cat fish

#define N 20

int main ()
{
  bool first_run = true;
  char smallest[N];
  char largest[N];
  char word[N];

  for (;;)
  {

    printf("Enter word (q to quit):");
    scanf ("%s", word);

    if (first_run)
    {
      strcpy (smallest, word);
      strcpy(largest, word);
      first_run = false;
    }

    if (strcmp ("q", word) == 0)
      break;
    else if (strcmp(word, smallest) < 0)
    {
      strcpy (smallest, word);
    }
    else if (strcmp (word, largest) > 0)
    {
      strcpy(largest, word);
    }
  }

  printf ("The smallest word is: %s\n", smallest);
  printf ("The largest word is: %s\n", largest);

  return 0;
}
