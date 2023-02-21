#include <stdio.h>

int main ()
{
  int num1, denom1, num2, denom2, result_num, result_denom;
  char ch;

  printf ("Enter two fractions:");
  scanf ("%d / %d %c %d / %d", &num1, &denom1, &ch, &num2, &denom2);

  if (ch == '+')
  {
    result_num = num1 * denom2 + num2 * denom1;
    result_denom = denom1 * denom2;

    printf ("The sum is %d/%d", result_num, result_denom);
  }
  else if (ch == '-')
  {
    result_num = num1 * denom2 - num2 * denom1;
    result_denom = denom1 * denom2;

    printf ("The difference is %d/%d", result_num, result_denom);
  }
  else if (ch == '*')
  {
    result_num = num1 * num2;
    result_denom = denom1 * denom2;

    printf ("The multiplication is %d/%d", result_num, result_denom);
  }
  else if (ch == '/')
  {
    result_num = num1 * denom2;
    result_denom = denom1 * num2;

    printf ("The division is %d/%d", result_num, result_denom);
  }
  else
  {
    printf ("%c is not valid, use +, -, * or /", ch);
  }

  return 0;
}
