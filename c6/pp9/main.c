#include <stdio.h>

int main ()
{
  double loan, rate, payment;
  int number_of_payments;

  printf ("Enter amount of loan:");
  scanf ("%lf", &loan);

  printf ("Enter interest rate:");
  scanf ("%lf", &rate);

  printf ("Enter monthly payment:");
  scanf ("%lf", &payment);

  printf ("Number of payments:");
  scanf ("%d", &number_of_payments);

  rate = 1 + rate / 100 / 12;
  for (int i = 1; i < number_of_payments; i++)
  {
    loan = loan * rate - payment;
    printf ("Balance after %d. payment: %.2f\n", i, loan);
  }

  return 0;
}
