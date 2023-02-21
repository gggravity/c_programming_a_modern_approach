#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define N 100

bool is_palindrome(const char *message);

// Madam, I am Adam.
// He lived as a devil, eh?

int main ()
{
  char ch;
  char message[N];
  char *p = message;

  printf ("Enter a message:");
  while ((ch = (char)getchar()) != '\n')
  {
    *p++ = ch;
  }
  *p = '\0';

  if (is_palindrome (message))
    printf ("They are palindromes");
  else
    printf ("They are NOT palindromes");

  return 0;
}

bool is_palindrome(const char *message)
{
  bool palindrome = true;
  size_t n = strlen(message);
  char msg[n];

  int len = 0;
  for (int i = 0; i < n; i++)
  {
    if (isalpha (message[i]))
      msg[len++] = (char) tolower (message[i]);
  }
  msg[len] = '\0';

  for (char *p = msg, *q = msg + len -1; q > p; p++, q--)
  {
    if (*q != *p)
    {
      palindrome = false;
      break;
    }
  }
  return palindrome;
}