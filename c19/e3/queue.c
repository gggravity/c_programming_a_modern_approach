//
// Created by martin on 04/11/2021.
//

#include <stdio.h>
#include "queue.h"

#define MAXSIZE 6

typedef struct {
    int data[MAXSIZE];
    int front;
    int back;
    int size;
} Queue;

static Queue queue = {.front = -1,.back = -1,.size = -1};

void enqueue (int value)
{
  if (queue.size < 0)
  {
    queue.data[0] = value;
    queue.front = queue.back = 0;
    queue.size = 1;
    return;
  }
  if (queue.size > 0 && !is_full ())
  {
    queue.data[++queue.back] = value;
    queue.size++;
  }
  else if (is_full ())
  {
    if (queue.back == MAXSIZE - 1)
    {
      queue.back -= MAXSIZE;
    }
    queue.data[++queue.back] = value;
    queue.front++;
  }

}

int dequeue ()
{
  int to_return = queue.data[queue.front];

  if (is_empty ())
  {
    printf ("Error: queue is empty\n");
  }
  else
  {
    queue.data[queue.front] = 0;
    queue.size--;
    if (queue.front == MAXSIZE - 1)
    {
      queue.front -= MAXSIZE;
    }
    queue.front++;
  }
  return to_return;
}

int next_enqueue ()
{
  return queue.data[queue.front];
}

int last_enqueue ()
{
  return queue.data[queue.back];
}

bool is_empty ()
{
  return queue.size == 0 ? true : false;
}

bool is_full ()
{
  return queue.size == MAXSIZE;
}

int queue_size ()
{
  return queue.size;
}

void print_queue ()
{
  printf ("queue is: ");
  for (int *p = queue.data; p < queue.data + MAXSIZE; p++)
    printf ("%d ", *p);
  printf ("\n");
}