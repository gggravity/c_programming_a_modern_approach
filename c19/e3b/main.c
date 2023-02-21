#include <stdio.h>
#include "queue.h"

#define N 5

int main ()
{
  printf ("is_empty(): %s\n", is_empty() ? "true": "false");
  printf ("queue_size(): %d\n", queue_size ());

  for (int i = 1; i <= N; i++)
  {
    enqueue (i);
    print_queue ();
  }

  printf ("next_enqueue(): %d\n", next_enqueue ());
  printf ("last_enqueue(): %d\n", last_enqueue ());
  printf ("is_empty(): %s\n", is_empty() ? "true": "false");
  printf ("queue_size(): %d\n", queue_size ());
  printf("de-queueing: %d\n", dequeue());
  print_queue();
  printf ("next_enqueue(): %d\n", next_enqueue ());
  printf ("last_enqueue(): %d\n", last_enqueue ());
  printf ("queue_size(): %d\n", queue_size ());

//  for (int i = 1; i < 3; i++)
//    printf("de-queueing: %d\n", dequeue());
//
//
//  for (int i = 1; i < N; i++)
//  {
//    enqueue (i);
//    print_queue ();
//  }

  return 0;
}
