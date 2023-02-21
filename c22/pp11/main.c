#include <stdio.h>
#include <stdlib.h>

void print_date (int month, int year, int day);

int main (int argc, char *argv[])
{
  int month, year, day;

  char *buffer;
  size_t buffer_size = 32;

  buffer = (char *) malloc (buffer_size * sizeof (char));

  if (buffer == NULL)
  {
    perror ("Unable to allocate memory to buffer");
    exit (EXIT_FAILURE);
  }

  printf ("Please enter a date:");
  getline (&buffer, &buffer_size, stdin);

  if (sscanf (buffer, "%d / %d /%d", &month, &day, &year) == 3 ||
      sscanf (buffer, "%d - %d - %d", &month, &day, &year) == 3)
    print_date (month, year, day);
  else
    printf ("Can't read date.\n");

  free (buffer);

  return 0;
}

void print_date (int month, int year, int day)
{
  char *months[] = {"January", "February", "Marts", "April", "May", "June", "July", "August",
                    "September", "October", "November", "December"};

  printf ("%s %d, %d\n", months[month - 1], day, year);
}