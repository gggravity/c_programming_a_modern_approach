#include <stdio.h>

void print_teens (int age)
{

  char *numbers[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen",
                     "nineteen"};

  printf("%s\n", numbers[age - 10]);
}

void print_first_digit (int digit)
{
  if (digit <= 1 || digit > 9)
    return;

  char *numbers[] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
  printf("%s", numbers[digit - 2]);
}

void print_last_digit (int digit)
{
  if (digit < 1 || digit > 9)
    return;

  char *numbers[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

  printf("%s\n", numbers[digit - 1]);
}

int main ()
{

  for (int i = 0; i < 100; i++)
  {
    if (i >= 10 && i <= 19)
    {
      print_teens (i);
      continue;
    }

    int first_digit = i / 10;
    int last_digit = i - first_digit * 10;

    if (first_digit == 0)
    {
      print_last_digit (last_digit);
    }
    else
    {
      print_first_digit (first_digit);
      last_digit == 0 ? printf ("\n") : printf ("-");
      print_last_digit (last_digit);
    }
  }

  return 0;
}