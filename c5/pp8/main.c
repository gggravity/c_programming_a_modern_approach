#include <stdio.h>
#include <stdlib.h>

int main ()
{
  int hour, minutes, time_since_midnight;

//  printf ("Enter a 24-hour time [hh:mm]:");
//  scanf("%d:%d", &hour, &minutes)
  hour = 13, minutes = 15; // 795

  time_since_midnight = hour * 60 + minutes;

  int f1 = abs(time_since_midnight - 8 * 60);
  int f2 = abs(time_since_midnight - 9 * 60 - 43);
  int f3 = abs(time_since_midnight - 11 * 60 - 19);
  int f4 = abs(time_since_midnight - 12 * 60 - 47);
  int f5 = abs(time_since_midnight - 14 * 60);
  int f6 = abs(time_since_midnight - 15 * 60 - 45);
  int f7 = abs(time_since_midnight - 19 * 60);
  int f8 = abs(time_since_midnight - 21 * 60);

  printf("Closest departure time is ");
  if (f1 < f2 && f1 < f3 && f1 < f4 && f1 < f5 && f1 < f6 && f1 < f7 && f1 < f8)
    printf("08:00 a.m., arriving 10:16 a.m.\n");
  else if (f2 < f3 && f2 < f4 && f2 < f5 && f2 < f6 && f2 < f7 && f2 < f8)
    printf("09:43 a.m., arriving 12:52 a.m.\n");
  else if (f3 < f4 && f3 < f5 && f3 < f6 && f3 < f7 && f3 < f8)
    printf("11:19 a.m., arriving 01:31 p.m.\n");
  else if (f4 < f5 && f4 < f6 && f4 < f7 && f4 < f8)
    printf("12:47 p.m., arriving 03:00 p.m.\n");
  else if (f5 < f6 && f5 < f7 && f5 < f8)
    printf("02:00 p.m., arriving 04:08 p.m.\n");
  else if (f6 < f7 && f6 < f8)
    printf("03:45 p.m., arriving 05:55 p.m.\n");
  else if (f7 < f8)
    printf("07:00 p.m., arriving 09:20 p.m.\n");
  else
    printf("09:45 a.m., arriving 11:58 p.m.\n");

//
//
//  printf ("f1: %d\n", f1);
//  printf ("f2: %d\n", f2);
//  printf ("f3: %d\n", f3);
//  printf ("f4: %d\n", f4);
//  printf ("f5: %d\n", f5);
//  printf ("f6: %d\n", f6);
//  printf ("f7: %d\n", f7);
//  printf ("f8: %d\n", f8);

  return 0;
}
