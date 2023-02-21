#include <stdio.h>
#include <limits.h>

int calc_days_since_epoch (int day, int month, int year)
{
  switch (month)
  { /* fall through */
  case 12:
    day += 31;
  case 11:
    day += 30;
  case 10:
    day += 31;
  case 9:
    day += 31;
  case 8:
    day += 31;
  case 7:
    day += 31;
  case 6:
    day += 30;
  case 5:
    day += 31;
  case 4:
    day += 30;
  case 3:
    day += 31;
  case 2:
    day += 28;
  case 1:
    day += 31;
  default:
    break;
  }
  return year * 365 + day;
}

int main ()
{
  int day, month, year, min_day, min_month, min_year, min_time_since_epoch = INT_MAX;

  for (;;)
  {
    printf ("Enter a date (dd/mm/yy):");
    scanf ("%2d / %2d / %2d", &day, &month, &year);

    if (day == 0 && month == 0 && year == 0)
      break;

    int time_since_epoch = calc_days_since_epoch (day, month, year);

    if (time_since_epoch < min_time_since_epoch)
    {
      min_time_since_epoch = time_since_epoch;
      min_day = day;
      min_month = month;
      min_year = year;
    }
  }

  printf ("%02d/%02d/%02d is the earliest date", min_day, min_month, min_year);

  return 0;
}
