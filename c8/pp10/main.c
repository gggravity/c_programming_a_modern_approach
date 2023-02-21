#include <stdio.h>
#include <stdlib.h>

int main ()
{
  int hour, minutes, time_since_midnight;

  int departure[8][2] = {
      {8, 0},
      {9, 43},
      {11, 19},
      {12, 47},
      {2, 0},
      {3, 45},
      {7, 0},
      {9, 45}
  };
  char time_convention_departure[] = {'a', 'a', 'a', 'p', 'p', 'p', 'p', 'p'};
  int arrival[8][2] = {
      {10, 16},
      {12, 52},
      {1, 31},
      {3, 0},
      {4, 8},
      {5, 55},
      {9, 20},
      {11, 58}
  };
  char time_convention_arrival[] = {'a', 'a', 'p', 'p', 'p', 'p', 'p', 'p'};
//  printf ("Enter a 24-hour time [hh:mm]:");
//  scanf("%d:%d", &hour, &minutes)
  hour = 13, minutes = 15; // 795

  time_since_midnight = hour * 60 + minutes;

  int dt[] = {
      abs (time_since_midnight - 8 * 60),
      abs (time_since_midnight - 9 * 60 - 43),
      abs (time_since_midnight - 11 * 60 - 19),
      abs (time_since_midnight - 12 * 60 - 47),
      abs (time_since_midnight - 14 * 60),
      abs (time_since_midnight - 15 * 60 - 45),
      abs (time_since_midnight - 19 * 60),
      abs (time_since_midnight - 21 * 45)
  };

  int min = INT_MAX;
  int index;
  for (int i = 0; i < sizeof dt / sizeof dt[0]; i++)
  {
    if (dt[i] < min)
    {
      min = dt[i];
      index = i;
    }
  }

  printf ("Closest departure time is ");
  printf ("%02d:%02d %c.m., arriving %02d:%02d %c.m.",
          departure[index][0], departure[index][1],
          time_convention_departure[index],
          arrival[index][0], arrival[index][1],
          time_convention_arrival[index]);

  return 0;
}
