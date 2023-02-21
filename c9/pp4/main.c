#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define NUMBERS_OF_CHARACTERS 26

// smartest mattress

void read_word(int word[26]);

bool equal_array(const int word1[NUMBERS_OF_CHARACTERS], const int word2[NUMBERS_OF_CHARACTERS]);

int main ()
{

  int word_one[NUMBERS_OF_CHARACTERS] = {0};
  int word_two[NUMBERS_OF_CHARACTERS] = {0};

  printf ("Enter first word:");
  read_word (word_one);

  printf ("Enter second word:");
  read_word (word_two);

  if (equal_array(word_one, word_two))
    printf ("The words are anagrams.");
  else
    printf ("The words are not anagrams.");

  return 0;
}

void read_word(int word[26])
{
  int ch;

  while ((ch = getchar ()) != '\n')
  {
    ch = tolower (ch);
    if (isalpha (ch))
      word[ch - 'a']++;
  }
}

bool equal_array(const int word1[NUMBERS_OF_CHARACTERS], const int word2[NUMBERS_OF_CHARACTERS])
{
  bool is_anagram = true;

  for (int i = 0; i < NUMBERS_OF_CHARACTERS; i++)
  {
    if (word1[i] != word2[i])
    {
      is_anagram = false;
      break;
    }
  }

  return is_anagram;
}