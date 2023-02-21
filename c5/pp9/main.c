#include <stdio.h>

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
  int month1, month2, day1, day2, year1, year2, days_since_epoch1, days_since_epoch2;

  printf ("Enter first date (mm/dd/yy):");
  scanf ("%2d/%2d/%2d", &month1, &day1, &year1);

  printf ("Enter second date (mm/dd/yy):");
  scanf ("%2d/%2d/%2d", &month2, &day2, &year2);


  days_since_epoch1 = calc_days_since_epoch (day1, month1, year1);
  days_since_epoch2 = calc_days_since_epoch (day2, month2, year2);

  if (days_since_epoch1 < days_since_epoch2)
    printf ("%02d/%02d/%02d is earlier then %02d/%02d/%02d", month1, day1, year1, month2, day2, year2);
  else if (days_since_epoch2 < days_since_epoch1)
    printf ("%02d/%02d/%02d is earlier then %02d/%02d/%02d", month2, day2, year2, month1, day1, year1);
  else
    printf ("They are the same dates.");

  return 0;
}
