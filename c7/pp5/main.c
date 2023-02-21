#include <stdio.h>
#include <ctype.h>

int get_points_per_character (char ch)
{
  ch = (char) toupper (ch);

  switch (ch)
  {
  case 'A':
  case 'E':
  case 'I':
  case 'L':
  case 'N':
  case 'O':
  case 'R':
  case 'S':
  case 'T':
  case 'U':
    return 1;
  case 'D':
  case 'G':
    return 2;
  case 'B':
  case 'C':
  case 'M':
  case 'P':
    return 3;
  case 'F':
  case 'H':
  case 'V':
  case 'W':
  case 'Y':
    return 4;
  case 'K':
    return 5;
  case 'J':
  case 'X':
    return 8;
  case 'Q':
  case 'Z':
    return 10;
  default:
    return -1;
  }
}

int main ()
{
  char word[] = "pitFALL";

  int points = 0;
  for (int i = 0; word[i] != '\0'; i++)
  {
    points += get_points_per_character (word[i]);
  }
  printf ("%d", points);

  return 0;
}
