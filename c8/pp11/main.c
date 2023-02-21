#include <stdio.h>
#include <ctype.h>

char convert_to_digit (char ch)
{
//  ch = toupper (ch);

  switch (ch)
  {
  case 'A':
  case 'B':
  case 'C':
    return '2';
  case 'D':
  case 'E':
  case 'F':
    return '3';
  case 'G':
  case 'H':
  case 'I':
    return '4';
  case 'J':
  case 'K':
  case 'L':
    return '5';
  case 'M':
  case 'N':
  case 'O':
    return '6';
  case 'P':
  case 'R':
  case 'S':
    return '7';
  case 'T':
  case 'U':
  case 'V':
    return '8';
  case 'X':
  case 'Y':
  case 'Z':
    return '9';
  default:
    return ch;
  }
}

int main ()
{
  char number[15];

//  CALLATT
//  1-800-COL-LECT

  printf ("Enter phone number:");
  scanf ("%14s", &number);

  for (int i = 0; number[i] != '\0'; i++)
  {
    printf ("%c", convert_to_digit (number[i]));
  }

  return 0;
}
