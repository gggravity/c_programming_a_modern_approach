//
// Created by martin on 04/11/2021.
//

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "queue.h"

#define MAXSIZE 6

struct queue_type {
    int data[MAXSIZE];
    int front;
    int back;
    int size;
} ;


Queue create (void)
{
  Queue q = malloc (sizeof (struct queue_type));
  if (q == NULL)
  {
    printf("Error in create: stack could not be created.\n");
    exit(EXIT_FAILURE);
  }

  q->front = -1;
  q->back = -1;
  q->size = -1;

  return q;
}

void enqueue (Queue q, int value)
{
  if (q == NULL)
  {
    q->front = -1;
    q->back = -1;
    q->size = -1;
  }

  if (q->size < 0)
  {
    q->data[0] = value;
    q->front = q->back = 0;
    q->size = 1;
    return;
  }
  if (q->size > 0 && !is_full (q))
  {
    q->data[++q->back] = value;
    q->size++;
  }
  else if (is_full (q))
  {
    if (q->back == MAXSIZE - 1)
    {
      q->back -= MAXSIZE;
    }
    q->data[++q->back] = value;
    q->front++;
  }

}

int dequeue (Queue q)
{
  int to_return = q->data[q->front];

  if (is_empty (q))
  {
    printf ("Error: queue is empty\n");
  }
  else
  {
    q->data[q->front] = 0;
    q->size--;
    if (q->front == MAXSIZE - 1)
    {
      q->front -= MAXSIZE;
    }
    q->front++;
  }
  return to_return;
}

int next_enqueue (Queue q)
{
  return q->data[q->front];
}

int last_enqueue (Queue q)
{
  return q->data[q->back];
}

bool is_empty (Queue q)
{
  return q->size == 0 ? true : false;
}

bool is_full (Queue q)
{
  return q->size == MAXSIZE;
}

int queue_size (Queue q)
{
  return q->size;
}

void print_queue (Queue q)
{
  printf ("queue is: ");
  for (int *p = q->data; p < q->data + MAXSIZE; p++)
    printf ("%d ", *p);
  printf ("\n");
}