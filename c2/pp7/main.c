#include <stdio.h>

int main ()
{
  int amount, bills;

  printf ("Enter amount:");
  scanf ("%d", &amount);

  bills = amount / 20;
  printf ("$20 bills: %d\n", bills);
  amount -= bills * 20;
  bills = amount / 10;
  printf ("$10 bills: %d\n", bills);
  amount -= bills * 10;
  bills = amount / 5;
  printf (" $5 bills: %d\n", bills);
  amount -= bills * 50;
  printf (" $1 bills: %d\n", amount);


  return 0;
}
