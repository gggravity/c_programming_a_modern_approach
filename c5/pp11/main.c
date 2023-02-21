#include <stdio.h>

void print_teens (int age)
{
  switch (age)
  {
  case 10:
    printf("ten");
    break;
  case 11:
    printf("eleven");
    break;
  case 12:
    printf("twelve");
    break;
  case 13:
    printf("thirteen");
    break;
  case 14:
    printf("fourteen");
    break;
  case 15:
    printf("fifteen");
    break;
  case 16:
    printf("sixteen");
    break;
  case 17:
    printf("seventeen");
    break;
  case 18:
    printf("eighteen");
    break;
  case 19:
    printf("nineteen");
    break;
  }
  printf ("\n");
}

void print_first_digit (int digit)
{
  if (digit <= 1 || digit > 9)
    return;

  switch (digit)
  {
  case 2:
    printf ("twenty");
    break;
  case 3:
    printf ("thirty");
    break;
  case 4:
    printf ("forty");
    break;
  case 5:
    printf ("fifty");
    break;
  case 6:
    printf ("sixty");
    break;
  case 7:
    printf ("seventy");
    break;
  case 8:
    printf ("eighty");
    break;
  case 9:
    printf ("nifty");
    break;
  default:
    break;
  }
}

void print_last_digit (int digit)
{
  if (digit < 1 || digit > 9)
    return;

  switch (digit)
  {
  case 1:
    printf ("one");
    break;
  case 2:
    printf ("two");
    break;
  case 3:
    printf ("three");
    break;
  case 4:
    printf ("four");
    break;
  case 5:
    printf ("five");
    break;
  case 6:
    printf ("six");
    break;
  case 7:
    printf ("seven");
    break;
  case 8:
    printf ("eight");
    break;
  case 9:
    printf ("nine");
    break;
  default:
    break;
  }
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
      last_digit == 0 ? : printf ("-");
      print_last_digit (last_digit);
    }
    printf ("\n");
  }

  return 0;
}
