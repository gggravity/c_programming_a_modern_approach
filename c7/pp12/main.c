#include <stdio.h>

int main ()
{
  char ch;
  float number;
  float sum = 0;

  printf ("Enter an expression:");
  scanf("%f", &sum);

  while ((ch = getchar()) != '\n')
  {
    switch (ch)
    {
    case '+':
      scanf ("%f", &number);
      sum += number;
      break;
    case '-':
      scanf ("%f", &number);
      sum -= number;
      break;
    case '*':
      scanf ("%f", &number);
      sum *= number;
      break;
    case '/':
      sum /= number;
      break;
    default:
      break;
    }
  }

  printf ("sum: %.2f", sum);

  return 0;
}
