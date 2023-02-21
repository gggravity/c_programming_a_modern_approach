#include <stdio.h>

int main ()
{
  int wind_speed;

//  printf ("Enter wind speed in knots:");
//  scanf ("%d", &wind_speed);

  for (wind_speed = 0; wind_speed <= 100; wind_speed++)
  {
    printf("Wind speed: %d -> ", wind_speed);

    if (wind_speed < 1)
      printf ("Calm\n");
    else if (wind_speed <= 3)
      printf ("Light air\n");
    else if (wind_speed <= 27)
      printf ("Breeze\n");
    else if (wind_speed <= 47)
      printf ("Gale\n");
    else if (wind_speed <= 63)
      printf ("Storm\n");
    else
      printf ("Hurricane\n");
  }
  return 0;
}
