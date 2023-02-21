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
    return 0;
  }
}

int scrabble_values[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main ()
{
//  char word[] = "abcdefghijklmnopqrstuvwxyz";
//
//  printf ("int scrabble[26] = {");
//  for (int i = 0; word[i] != '\0'; i++)
//  {
//    printf ("%d, ", get_points_per_character (word[i]));
//  }
//  printf ("};");

  char input[] = "the dude ate my doggi";

  int sum = 0;

  for (int i = 0; input[i] != '\0'; i++)
  {
    int input_to_int = tolower (input[i]) - 'a';
    sum += scrabble_values[input_to_int];
  }

  printf ("\"%s\" are worth %d scrabble points\n", input, sum);

  int points = 0;

  for (int i = 0; input[i] != '\0'; i++)
  {
    points += get_points_per_character (input[i]);
  }
  printf ("\"%s\" are worth %d scrabble points", input, points);

  return 0;
}
