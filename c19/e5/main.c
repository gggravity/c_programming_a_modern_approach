#include <stdio.h>
#include "queue.h"

#define N 10

int main ()
{
  Queue q1, q2;

  q1 = create ();
  q2 = create ();

  for (int i = 1; i <= N; i++)
  {
    enqueue (q1, i);
  }
  print_queue (q1);

  for (int i = 1 + N; i <= N + N; i++)
  {
    enqueue (q2, i);
  }
  print_queue (q2);

  printf ("is_empty(): %s\n", is_empty (q1) ? "true" : "false");
  printf ("queue_size(): %d\n", queue_size (q1));

  for (int i = 1; i <= N; i++)
  {
    enqueue (q1, i);
    print_queue (q1);
  }

  printf ("next_enqueue(): %d\n", next_enqueue (q1));
  printf ("last_enqueue(): %d\n", last_enqueue (q1));
  printf ("is_empty(): %s\n", is_empty (q1) ? "true" : "false");
  printf ("queue_size(): %d\n", queue_size (q1));
  printf ("de-queueing: %d\n", dequeue (q1));
  print_queue (q1);
  printf ("next_enqueue(): %d\n", next_enqueue (q1));
  printf ("last_enqueue(): %d\n", last_enqueue (q1));
  printf ("queue_size(): %d\n", queue_size (q1));



  return 0;
}
