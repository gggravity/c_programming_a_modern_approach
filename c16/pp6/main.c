#include <stdio.h>

struct date {
    int day;
    int month;
    int year;
};

int calc_days_since_epoch (struct date d)
{
  int day = 0;
  switch (d.month)
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
  return d.year * 365 + day + d.day;
}

int compare_dates(struct date d1, struct date d2)
{
  int days_since_epoch1, days_since_epoch2;
  days_since_epoch1 = calc_days_since_epoch (d1);
  days_since_epoch2 = calc_days_since_epoch (d2);

  if (days_since_epoch1 > days_since_epoch2)
    return -1;
  else if (days_since_epoch1 < days_since_epoch2)
    return 1;
  else
    return 0;
}

int main ()
{
  struct date d1, d2;

  printf ("Enter first date (mm/dd/yy):");
  scanf ("%2d/%2d/%2d", &d1.month, &d1.day, &d1.year);

  printf ("Enter second date (mm/dd/yy):");
  scanf ("%2d/%2d/%2d", &d2.month, &d2.day, &d2.year);

  if (compare_dates (d1, d2) > 0)
    printf ("%02d/%02d/%02d is earlier then %02d/%02d/%02d", d1.month, d1.day, d1.year, d2.month, d2.day, d2.year);
  else if (compare_dates (d1, d2) < 0)
    printf ("%02d/%02d/%02d is earlier then %02d/%02d/%02d", d2.month, d2.day, d2.year, d1.month, d1.day, d1.year);
  else
    printf ("They are the same dates.");

  return 0;
}
