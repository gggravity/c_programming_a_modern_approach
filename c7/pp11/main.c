#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

int main ()
{
  bool is_last_name = false;
  bool first_letter_in_last_name = true;
  char ch, first_letter = '|';

  while ((ch = getchar ()) != '\n')
  {
    if (first_letter == '|')
      first_letter = ch;
    if (ch == ' ')
      is_last_name = true;
    if (is_last_name && ch != ' ')
    {
      if (first_letter_in_last_name)
      {
        printf ("%c", toupper (ch));
        first_letter_in_last_name = false;
      }
      else
      {
        printf ("%c", ch);
      }
    }
  }
  printf (", %c.", toupper (first_letter));

  return 0;
}
