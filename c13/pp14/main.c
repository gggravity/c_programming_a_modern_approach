#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

bool are_anagrams(const char *word1, const char *word2);

#define NUMBERS_OF_CHARACTERS 26

// smartest mattress

int main ()
{
  bool anagrams = false;

  char word1[] = "smartest";
  char word2[] = "mattress";

  if (are_anagrams(word1, word2))
    printf ("The words are anagrams.");
  else
    printf ("The words are not anagrams.");

  return 0;
}

bool are_anagrams(const char *word1, const char *word2)
{
  bool is_anagram = true;

  int word_one[NUMBERS_OF_CHARACTERS] = {0};
  int word_two[NUMBERS_OF_CHARACTERS] = {0};

  char *w1 = (char *)word1;
  char *w2 = (char *)word2;

  while (*w1)
  {
    *w1 = tolower(*w1);
    if (isalpha(*w1))
      word_one[*w1 - 'a']++;
    w1++;
  }

  while (*w2)
  {
    *w2 = tolower(*w2);
    if (isalpha(*w2))
      word_two[*w2 - 'a']++;
    w2++;
  }

  for (int i = 0; i < NUMBERS_OF_CHARACTERS; i++)
  {
    if (word_one[i] != word_two[i])
    {
      is_anagram = false;
      break;
    }
  }

  return is_anagram;

}