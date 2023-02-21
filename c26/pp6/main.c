#include <stdio.h>
#include <time.h>
#include <string.h>

int main ()
{
  time_t current = time (NULL);

  char date_time[100];

  // Sunday, June 3, 2007 05:48p
  strftime (date_time, sizeof (date_time), "%A, %B %e, %Y %I:%M", localtime (&current));
  printf ("%s", date_time);
  strftime (date_time, sizeof (date_time), "%p", localtime (&current));
  if (strcmp(date_time, "PM") == 0)
    printf ("p\n");
  else
    printf ("a\n");

  // Sun, 3 Jun 07 17:48
  strftime (date_time, sizeof (date_time), "%a, %e %b %H:%M", localtime (&current));
  printf ("%s\n", date_time);

  // 06/03/07 5:48:34 PM
  strftime (date_time, sizeof (date_time), "%x %r", localtime (&current));
  printf ("%s\n", date_time);


  return 0;
}
