#include <stdio.h>

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones);

int main ()
{
  int amount, bills;
  int twenties, tens, fives, ones;

  printf ("Enter amount:");
  scanf ("%d", &amount);

  pay_amount (amount,&twenties, &tens, &fives, &ones);

  printf("$%d split are:\n", amount);
  printf("$20 bills: %d\n", twenties);
  printf("$10 bills: %d\n", tens);
  printf(" $5 bills: %d\n", fives);
  printf(" $1 bills: %d\n", ones);

  return 0;
}

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones)
{
  *twenties = dollars / 20;
  dollars -= *twenties * 20;

  *tens = dollars / 10;
  dollars -= *tens * 10;

  *fives = dollars / 5;
  dollars -= *fives * 50;

  *ones = dollars;
}
