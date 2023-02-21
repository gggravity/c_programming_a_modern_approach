#include <stdio.h>

int main ()
{
  double loan, rate, payment;

  printf ("Enter amount of loan:");
  scanf("%lf",&loan);

  printf ("Enter interest rate:");
  scanf("%lf", &rate);

  printf ("Enter monthly payment:");
  scanf("%lf", &payment);

  rate = 1 + rate / 100 / 12;
  loan = loan * rate - payment;
  printf ("Balance remaining after first payment: %.2f\n", loan);

  loan = loan * rate - payment;
  printf ("Balance remaining after second payment: %.2f\n", loan);

  loan = loan * rate - payment;
  printf ("Balance remaining after third payment: %.2f\n", loan);

  return 0;
}
