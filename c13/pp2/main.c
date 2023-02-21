#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_REMIND 50
#define MSG_LEN 60

int read_line (char str[], int n);

int main ()
{
  char reminders[MAX_REMIND][MSG_LEN + 3];
  char date_str[20], msg_str[MSG_LEN + 1];
  int day, month, i, j, num_remind = 0;

  for (;;)
  {
    if (num_remind == MAX_REMIND)
    {
      printf ("-- No space left --\n");
      break;
    }

    printf ("Enter day/month and reminder:");
    scanf ("%2d/", &day);
    if (day == 0)
      break;
    else if (day < 0 || day > 31)
    {
      printf ("ERROR: Wrong date try again.\n");
      fflush (stdin);
      continue;
    }

    scanf ("%2d", &month);
    if (month == 0)
      break;
    else if (month < 0 || month > 12)
    {
      printf ("ERROR: Wrong date try again.\n");
      fflush (stdin);
      continue;
    }


    read_line (msg_str, MSG_LEN);


    sprintf (date_str, "%02d/%02d", day, month);

    for (i = 0; i < num_remind; i++)
      if (strcmp (date_str, reminders[i]) < 0)
        break;
    for (j = num_remind; j > i; j--)
      strcpy (reminders[j], reminders[j - 1]);

    strcpy (reminders[i], date_str);
    strcat (reminders[i], "    ");
    strcat (reminders[i], msg_str);

    num_remind++;
  }

  printf ("\nDate      Reminder\n");
  for (i = 0; i < num_remind; i++)
    printf ("%s\n", reminders[i]);

  return 0;
}

int read_line (char str[], int n)
{
  int ch, i = 0;

  while ((ch = getchar ()) != '\n')
    if (i < n)
      str[i++] = (char) ch;
  str[i] = '\0';

  return i;
}
