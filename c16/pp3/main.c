#include <stdio.h>
#include "operations.h"

#define MAX_PARTS 100

int main (void)
{

  struct part inventory[MAX_PARTS];

  int num_parts = 0;
  char code;

  for (;;)
  {
    printf ("Enter operation code:");
    scanf (" %c", &code);

    while (getchar () != '\n');

    switch (code)
    {
    case 'i':
      insert (&num_parts, inventory);
      break;
    case 's':
      search (&num_parts, inventory);
      break;
    case 'u':
      update (&num_parts, inventory);
      break;
    case 'p':
      print (&num_parts, inventory);
      break;
    case 'q':
      return 0;
    default:
      printf ("Illegal code\n");
    }
    printf ("\n");
  }
}





