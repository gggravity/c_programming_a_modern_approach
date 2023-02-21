#include <stdio.h>

int main ()
{
  int num1, denom1, num2, denom2, result_num, reslut_denom;

  printf ("Enter first fraction:");
  scanf("%d / %d", &num1, &denom1);

  printf ("Enter second fraction:");
  scanf("%d / %d", &num2, &denom2);

  result_num = num1 * denom2 + num2 * denom1;

  reslut_denom = denom1 * denom2;
  printf ("The sum is %d/%d\n", result_num, reslut_denom);

  return 0;
}
