#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

// Madam, I am Adam.
// He lived as a devil, eh?

int main ()
{
  bool palindrome = true;
  char ch;
  char message[100];
  char *p = message;

  printf ("Enter a message:");

  while ((ch = (char)getchar ()) != '\n')
  {
    if (isalpha (ch))
      *p++ = (char)tolower (ch);
  }
  p--;

  for (char *q = message; q != p; q++, p--)
  {
    if (*q != *p)
    {
      palindrome = false;
      break;
    }
  }

  if (palindrome)
    printf ("They are palindromes");
  else
    printf ("They are NOT palindromes");

  return 0;
}
