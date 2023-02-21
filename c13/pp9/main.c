#include <stdio.h>
#include <ctype.h>

int vowel(char ch);
int compute_vowel_count(const char *sentence);

int main ()
{
  int count = 0;
  char word[] = "And that's the way it is.";

  for (int i = 0; word[i] != '\0'; i++)
    count += vowel(word[i]);

  printf("The sentence contain %d vowels.\n", count);
  printf("The sentence contain %d vowels.", compute_vowel_count (word));

  return 0;
}

int compute_vowel_count(const char *sentence)
{
  int count = 0;

  for (const char * p = sentence; *p != '\0'; p++)
  {
    count += vowel (*p);
  }

  return count;
}

int vowel(char ch)
{
  ch = (char)toupper(ch);

  switch (ch)
  {
  case 'A':
  case 'E':
  case 'I':
  case 'O':
  case 'U':
    return 1;
  default:
    return 0;
  }
}