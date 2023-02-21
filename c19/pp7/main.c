#include <stdio.h>
#include "queue.h"

#define N 5

int main ()
{
  Queue queue = create();


  printf ("is_empty(): %s\n", is_empty(queue) ? "true": "false");
  printf ("queue_size(): %d\n", queue_size (queue));

  for (int i = 1; i <= N; i++)
  {
    enqueue (queue, i);
    print_queue (queue);
  }

  printf ("next_enqueue(): %d\n", next_enqueue (queue));
  printf ("last_enqueue(): %d\n", last_enqueue (queue));
  printf ("is_empty(): %s\n", is_empty(queue) ? "true": "false");
  printf ("queue_size(): %d\n", queue_size (queue));
  printf("de-queueing: %d\n", dequeue(queue));
  printf("de-queueing: %d\n", dequeue(queue));
  printf("de-queueing: %d\n", dequeue(queue));
  print_queue(queue);
  printf ("next_enqueue(): %d\n", next_enqueue (queue));
  printf ("last_enqueue(): %d\n", last_enqueue (queue));
  printf ("queue_size(): %d\n", queue_size (queue));


  return 0;
}
