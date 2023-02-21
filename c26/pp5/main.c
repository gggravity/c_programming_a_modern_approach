#include <stdio.h>
#include <time.h>

int main ()
{

  int day1, month1, year1;
  int day2, month2, year2;

  printf ("Please enter date (dd/mm/yyyy):\n");
  scanf ("%d / %d / %d", &day1, &month1, &year1);

  printf ("Please enter another date (dd/mm/yyyy):\n");
  scanf ("%d / %d / %d", &day2, &month2, &year2);


  struct tm time1;
  struct tm time2;

  time1.tm_mday = day1;
  time1.tm_mon = month1 - 1;
  time1.tm_year = year1 - 1900;
  time1.tm_sec = 0;
  time1.tm_min = 0;
  time1.tm_hour = 0;
  time1.tm_isdst = -1;

  time_t t1 = mktime (&time1);

  time2.tm_mday = day2;
  time2.tm_mon = month2 - 1;
  time2.tm_year = year2 - 1900;
  time2.tm_sec = 0;
  time2.tm_min = 0;
  time2.tm_hour = 0;
  time2.tm_isdst = -1;

  time_t t2 = mktime (&time2);

  double dt = difftime (t2, t1);

  dt /= (24 * 60 * 60);

  printf ("dt: %.f days.\n", dt);

  return 0;
}
