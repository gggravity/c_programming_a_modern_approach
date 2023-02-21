#include <stdio.h>
#include <ctype.h>

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

int main ()
{
  int count = 0;
  char word[] = "And that's the way it is.";

  for (int i = 0; word[i] != '\0'; i++)
    count += vowel(word[i]);

  printf("The sentence contain %d vowels.", count);

  return 0;
}
