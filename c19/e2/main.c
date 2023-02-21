#include <stdio.h>
#include "stack.h"

#define N 3

int main ()
{
  printf ("is_empty(): %s\n", is_empty () ? "true" : "false");

  for (int i = 1; i <= N; i++)
  {
    printf ("pushing: %d\n", i);
    push (i);
  }

  printf ("is_empty(): %s\n", is_empty () ? "true" : "false");

  for (int i = 1; i <= N; i++)
    printf ("popping: %d\n", pop ());

  printf ("is_empty(): %s\n", is_empty () ? "true" : "false");

  return 0;
}
