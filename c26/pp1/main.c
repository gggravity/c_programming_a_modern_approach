#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ()
{
  srand(time(NULL));

  for (int i = 0; i < 20; i++)
  {
    unsigned char c = (rand() & 1);
//    unsigned char c = rand() / (RAND_MAX / 10 + 1) & 1;
    printf ("%x\n", c);
  }

  return 0;
}
