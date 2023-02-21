#include <stdio.h>

// 939577

int main ()
{
  int input;
  int numbers[10] = {0};

  printf ("Enter a number:");
  scanf ("%d", &input);

  while (input > 0)
  {
    int number = input % 10;
    input /= 10;

    switch (number)
    {
    case 0:
      numbers[0]++;
      break;
    case 1:
      numbers[1]++;
      break;
    case 2:
      numbers[2]++;
      break;
    case 3:
      numbers[3]++;
      break;
    case 4:
      numbers[4]++;
      break;
    case 5:
      numbers[5]++;
      break;
    case 6:
      numbers[6]++;
      break;
    case 7:
      numbers[7]++;
      break;
    case 8:
      numbers[8]++;
      break;
    case 9:
      numbers[9]++;
      break;
    default:
      break;
    }
  }

  printf ("Repeated digit(s): ");
  for (int i = 0; i < sizeof (numbers) / sizeof (numbers[0]); i++)
  {
    if (numbers[i] > 1)
      printf ("%d ", i);
  }

  return 0;
}
