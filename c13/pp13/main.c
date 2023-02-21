#include <stdio.h>
#include <ctype.h>
#include <string.h>

void encrypt (char *message, int shift);

// Go ahead, make my day.
// Jr dkhdg, pdnh pb gdb.
// 3 23

int main ()
{
  int length = 0, shift;
  char ch;
  char message[100];

  printf ("Enter message to be encrypted:");

  while ((ch = getchar ()) != '\n')
  {
    message[length++] = ch;
  }

  message[length] = '\0';

  printf ("Enter shift amount (1 - 25):");
  scanf ("%d", &shift);

  encrypt (message, shift);

  return 0;
}

void encrypt (char *message, int shift)
{
  while (*message)
  {
    if (isalpha (*message))
    {
      if (islower (*message) && *message + shift > 'z' || isupper (*message) && *message + shift > 'Z')
        printf ("%c", (char) (*message - 26 + shift));
      else
        printf ("%c", (char) (*message + shift));
    }
    else
      printf ("%c", *message);
    message++;
  }
}