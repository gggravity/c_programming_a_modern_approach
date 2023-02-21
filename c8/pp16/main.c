#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define NUMBERS_OF_CHARACTERS 26

// smartest mattress

int main ()
{
  int ch;
  bool is_anagram = true;
  int word_one[NUMBERS_OF_CHARACTERS] = {0};
  int word_two[NUMBERS_OF_CHARACTERS] = {0};

  printf ("Enter first word:");
  while ((ch = getchar ()) != '\n')
  {
    ch = tolower(ch);
    if (isalpha(ch))
      word_one[ch - 'a']++;
  }

  printf ("Enter second word:");
  while ((ch = getchar ()) != '\n')
  {
    ch = tolower(ch);
    if (isalpha(ch))
      word_two[ch - 'a']++;
  }

  for (int i = 0; i < NUMBERS_OF_CHARACTERS; i++)
  {
    if (word_one[i] != word_two[i])
    {
      is_anagram = false;
      break;
    }
  }

  if (is_anagram)
    printf ("The words are anagrams.");
  else
    printf ("The words are not anagrams.");

  return 0;
}
