#include <stdio.h>

int main ()
{
  float commission, value, share_amount, share_price, alternative_commission ;

  printf ("Enter number of shares:");
  scanf ("%f", &share_amount);

  printf ("Enter share price:");
  scanf ("%f", &share_price);

  value = share_price * share_amount;

  if (value < 2500.00f)
    commission = 30.00f + .017f * value;
  else if (value < 6250.00f)
    commission = 56.00f + .0066f * value;
  else if (value < 20000.00f)
    commission = 76.00f + .0034f * value;
  else if (value < 50000.00f)
    commission = 100.00f + .0022f * value;
  else if (value < 500000.00f)
    commission = 155.00f + .0011f * value;
  else
    commission = 255.00f + .0009f * value;

  if (commission < 39.00f)
    commission = 39.00f;

  // alternative commission

  if (share_amount < 2000)
    alternative_commission = 33.00f + 0.03f * share_amount;
  else
    alternative_commission = 33.00f + 0.02f * share_amount;

  printf("Value of shares are: $%.2f\n", value);
  printf("Commission: $%.2f\n", commission);

  printf("Alternative commission: $%.2f\n", alternative_commission);

  return 0;
}
