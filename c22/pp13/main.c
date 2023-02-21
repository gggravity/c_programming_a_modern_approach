#include <stdio.h>
#include <stdlib.h>

struct times {
    int departure_hour;
    int departure_minutes;
    int arrival_hour;
    int arrival_minutes;
    int minutes_to_departure;
};

size_t arr_size = 1;
int loaded_elements = 0;

typedef struct times *Times;

int main ()
{
  int hour, minutes, time_since_midnight;

  Times t_arr = malloc (sizeof (struct times) * arr_size);

  if (t_arr == NULL)
  {
    perror ("Memory error");
    exit (EXIT_FAILURE);
  }

  printf ("Enter a 24-hour time [hh:mm]:");
  scanf("%d:%d", &hour, &minutes);
//  hour = 13, minutes = 15; // 795

  time_since_midnight = hour * 60 + minutes;

  char *filename = "flights.dat";

  FILE *fp = fopen (filename, "r");

  if (fp == NULL)
  {
    fprintf (stderr, "Error opening file: %s", filename);
  }

  char *buffer;
  size_t buffer_size = 100;

  while (getline (&buffer, &buffer_size, fp) != EOF)
  {

    Times t = &t_arr[loaded_elements++];

    sscanf (buffer, "%d:%d %d:%d",
            &t->departure_hour,
            &t->departure_minutes,
            &t->arrival_hour,
            &t->arrival_minutes);

    if (loaded_elements == arr_size)
      t_arr = realloc (t_arr, arr_size *= 2);
  }

  for (Times t = t_arr; t < t_arr + loaded_elements; t++)
  {
    t->minutes_to_departure = (t->departure_hour * 60 + t->departure_minutes) - time_since_midnight;

    if (t->minutes_to_departure > 0)
    {
      printf ("next flight will depart in %d minutes\n", t->minutes_to_departure);
      printf ("With a departure time: %02d:%02d and arrival time: %02d:%02d \n",
              t->departure_hour,
              t->departure_minutes,
              t->arrival_hour,
              t->arrival_minutes);
      break;
    }
  }

  free (t_arr);

  return 0;
}
