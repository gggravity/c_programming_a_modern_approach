#include <stdio.h>
#include "queue.h"

int main ()
{
  Queue q;

  initialize (&q);

  for (int i = 1; i <= 10; i++)
    enqueue (&q, i);

  for (int i = 1; i <= 10; i++)
  {
    Item item = dequeue (&q);
    printf ("%d\n", item);
  }

  return 0;
}
