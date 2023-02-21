#include <stdio.h>

int main ()
{
  double amount;

  printf ("Enter dollar and cent amount: ");
  scanf("%lf", &amount);

  printf ("Amount with tax added (10%%): $%.2f", amount * 1.1f);

  return 0;
}
