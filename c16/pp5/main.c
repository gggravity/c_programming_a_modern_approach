#include <stdio.h>
#include <stdlib.h>

struct flight {
    int departure;
    int arrival;
};

void selection_sort (int n, struct flight flights[]);

void print_flight(struct flight f);

int main ()
{
  int hour, minutes, time_since_midnight, closest_flight = INT_MAX, selected_flight_index = 0;


  struct flight flights[] =
      {
          {8 * 60, 12 * 60 + 12},
          {9 * 60 - 43, 12 * 60 + 52},
          {11 * 60 - 19, 13 * 60 + 31},
          {12 * 60 - 47, 15 * 60},
          {14 * 60, 16 * 60 + 3},
          {15 * 60 - 45, 17 * 55 + 55},
          {19 * 60, 21 * 60 + 20},
          {21 * 60, 23 * 60 + 58}
      };



//  printf ("Enter a 24-hour time [hh:mm]:");
//  scanf("%d:%d", &hour, &minutes)
  hour = 13, minutes = 15; // 795

  time_since_midnight = hour * 60 + minutes;

  printf ("Selected time: %d\n", time_since_midnight);

  for (int i = 0; i < sizeof flights / sizeof flights[0]; i++)
  {
    print_flight (flights[i]);
    if (abs(flights[i].departure - time_since_midnight) < closest_flight)
    {
      closest_flight = abs(flights[i].departure - time_since_midnight);
      selected_flight_index = i;
    }
    printf ("Time diff: %d\n", flights[i].departure - time_since_midnight);
  }

  printf("The winner is: ");
  print_flight (flights[selected_flight_index]);
  printf ("Time diff: %d\n", flights[selected_flight_index].departure - time_since_midnight);

  return 0;
}

void print_flight(struct flight f)
{
  printf ("Departure: %d, arrival: %d, ", f.departure, f.arrival);
}

void selection_sort (int n, struct flight flights[])
{
  int largest = INT_MIN, largest_index, temp;

  if (n == 0)
    return;

  for (int i = 0; i < n; i++)
  {
    if (flights[i].departure > largest)
    {
      largest = flights[i].departure;
      largest_index = i;
    }
  }

  temp = flights[n - 1].departure;
  flights[n - 1].departure = largest;
  flights[largest_index].departure = temp;
  largest = INT_MIN;
  n--;

  selection_sort (n, flights);

}