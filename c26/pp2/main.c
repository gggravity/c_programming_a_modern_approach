#include <stdio.h>
#include <stdlib.h>

void cleanup_1(void)
{
  printf ("That's All, ");
}

void cleanup_2(void)
{
  printf ("Folks!");
}

int main ()
{

  atexit(cleanup_2);
  atexit(cleanup_1);

  return 0;
}
