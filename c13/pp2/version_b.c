#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_REMIND 50
#define MSG_LEN 60

int read_line (char str[], int n);

int main ()
{
  char reminders[MAX_REMIND][MSG_LEN + 3];
  char day_str[20], msg_str[MSG_LEN + 1];
  int day, i, j, num_remind = 0;
  char time_str[] = "00:00";

  for (;;)
  {
    if (num_remind == MAX_REMIND)
    {
      printf ("-- No space left --\n");
      break;
    }

    printf ("Enter day and reminder:");
    scanf ("%2d", &day);
    if (day == 0)
      break;
    else if (day < 0 || day > 31)
    {
      printf ("ERROR: Wrong day try again.\n");
      fflush (stdin);
      continue;
    }

    sprintf (day_str, "%2d", day);

    read_line (msg_str, MSG_LEN);

    if (isdigit (msg_str[0]) &&
        isdigit (msg_str[1]) &&
        msg_str[2] == ':' &&
        isdigit (msg_str[3]) &&
        isdigit (msg_str[4]))
    {
      strncpy (time_str, msg_str, 5);
      strcpy (msg_str, &msg_str[6]);
    }

    strcat (day_str, "  ");
    strcat (day_str, time_str);

    for (i = 0; i < num_remind; i++)
      if (strcmp (day_str, reminders[i]) < 0)
        break;
    for (j = num_remind; j > i; j--)
      strcpy (reminders[j], reminders[j - 1]);

    strcpy (reminders[i], day_str);

    strcat (reminders[i], "  ");
    strcat (reminders[i], msg_str);

    strcpy (time_str, "00:00");
    num_remind++;


  }

  printf ("\nDay   Time  Reminder\n");
  for (i = 0; i < num_remind; i++)
    printf (" %s\n", reminders[i]);


  return 0;
}

int read_line (char str[], int n)
{
  int ch, i = -1;

  while ((ch = getchar ()) != '\n')
    if (i < n)
      str[i++] = ch;
  str[i] = '\0';

  return i;
}
