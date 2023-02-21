#include <stdio.h>
#include <stdlib.h>

void find_closest_flight (int desired_time, int *departure_time, int *arrival_time);

int main ()
{
  int hour, minutes, time_since_midnight, departure_time, arrival_time;

  hour = 13, minutes = 50;

  time_since_midnight = hour * 60 + minutes;

  find_closest_flight (time_since_midnight, &departure_time, &arrival_time);

  int dt = departure_time - time_since_midnight;

  if (dt > 0)
    printf ("The closest flight is departing in %d minutes, ", dt);
  else if (dt < 0)
    printf ("The closest flight departed %d minutes ago, ", abs(dt));
  else
    printf ("The closest flight is departing now, \n");

  printf ("arriving at the destination in %d minutes.", arrival_time - time_since_midnight);

  return 0;
}

void find_closest_flight (int desired_time, int *departure_time, int *arrival_time)
{

  int f1 = abs (desired_time - 8 * 60);
  int f2 = abs (desired_time - 9 * 60 - 43);
  int f3 = abs (desired_time - 11 * 60 - 19);
  int f4 = abs (desired_time - 12 * 60 - 47);
  int f5 = abs (desired_time - 14 * 60);
  int f6 = abs (desired_time - 15 * 60 - 45);
  int f7 = abs (desired_time - 19 * 60);
  int f8 = abs (desired_time - 21 * 60);

  if (f1 < f2 && f1 < f3 && f1 < f4 && f1 < f5 && f1 < f6 && f1 < f7 && f1 < f8)
  {
    *departure_time = 8 * 60;
    *arrival_time = 12 * 60 + 12;
  }
  else if (f2 < f3 && f2 < f4 && f2 < f5 && f2 < f6 && f2 < f7 && f2 < f8)
  {
    *departure_time = 9 * 60 + 43;
    *arrival_time = 12 * 60 + 52;
  }
  else if (f3 < f4 && f3 < f5 && f3 < f6 && f3 < f7 && f3 < f8)
  {
    *departure_time = 11 * 60 + 19;
    *arrival_time = 13 * 60 + 31;
  }
  else if (f4 < f5 && f4 < f6 && f4 < f7 && f4 < f8)
  {
    *departure_time = 12 * 60 + 47;
    *arrival_time = 15 * 60;
  }
  else if (f5 < f6 && f5 < f7 && f5 < f8)
  {
    *departure_time = 14 * 60;
    *arrival_time = 16 * 60 + 8;
  }
  else if (f6 < f7 && f6 < f8)
  {
    *departure_time = 15 * 60 + 45;
    *arrival_time = 17 * 60 + 55;
  }
  else if (f7 < f8)
  {
    *departure_time = 19 * 60;
    *arrival_time = 21 * 60 + 20;
  }
  else
  {
    *departure_time = 21 * 60 + 45;
    *arrival_time = 23 * 60 + 58;
  }
}
