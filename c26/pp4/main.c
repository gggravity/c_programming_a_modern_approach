#include <stdio.h>
#include <time.h>

int main ()
{
  int day, month, year, days_later;
  printf ("Please enter date (dd/mm/yyyy) + number of days later:\n");
  scanf ("%d / %d / %d %d", &day, &month, &year, &days_later);

  struct tm time_entered;
  struct tm time_n;

  time_entered.tm_mday = day;
  time_entered.tm_mon = month - 1;
  time_entered.tm_year = year - 1900;
  time_entered.tm_sec = 0;
  time_entered.tm_min = 0;
  time_entered.tm_hour = 0;
  time_entered.tm_isdst = -1;

  time_t t1 = mktime (&time_entered);

  time_n = time_entered;

  time_n.tm_mday += days_later;

  time_t t2 = mktime (&time_n);

  printf ("time 1: %s\n", ctime(&t1));
  printf ("time 2: %s\n", ctime(&t2));

  return 0;
}
