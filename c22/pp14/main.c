#include <stdio.h>
#include <ctype.h>

// Go ahead, make my day.
// Jr dkhdg, pdnh pb gdb.

int main ()
{
  int c, length = 0, shift;
  int message[10000];
  char filename[100];

  printf ("Enter name of file to be encrypted:");
  scanf ("%s", filename);

  FILE *fp = fopen (filename, "r");


  while ((c = fgetc(fp)) != EOF)
  {
    message[length++] = (int) c;
  }
  printf ("Enter shift amount (1 - 25):");
  scanf ("%d", &shift);

  for (int i = 0; i <= length; i++)
  {
    if (isalpha (message[i]))
    {
      if (islower (message[i]) && message[i] + shift > 'z')
        printf ("%c", (char) (message[i] - 26 + shift));
      else if ((isupper (message[i]) && message[i] + shift > 'Z'))
        printf ("%c", (char) (message[i] - 26 + shift));
      else
        printf ("%c", (char) (message[i] + shift));
    }
    else
      printf ("%c", message[i]);
  }

  return 0;
}
