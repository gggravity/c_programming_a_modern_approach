#include <stdio.h>
#include <malloc.h>
#include "operations.h"

int main (void)
{

  struct part *inventory = malloc (sizeof (struct part) * 1);

  char code;

  for (;;)
  {
    printf ("Enter operation code:");
    scanf (" %c", &code);

    while (getchar () != '\n');

    switch (code)
    {
    case 'i':
      insert (inventory);
      break;
    case 's':
      search (inventory);
      break;
    case 'u':
      update (inventory);
      break;
    case 'p':
      print (inventory);
      break;
    case 'q':
      return 0;
    default:
      printf ("Illegal code\n");
    }
    printf ("\n");
  }
}





