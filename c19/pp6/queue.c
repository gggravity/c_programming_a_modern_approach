//
// Created by martin on 04/11/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

//#define MAXSIZE 6

struct queue_type {
    int *data;
    int front;
    int back;
    int size;
    int array_size;
};
//
//static Queue queue = {.front = -1,.back = -1,.size = -1};

Queue create (int size)
{
  Queue queue = malloc (sizeof (struct queue_type));

  if (queue == NULL)
  {
    printf ("Error in create: queue could not be created.\n");
    exit (EXIT_FAILURE);
  }

  queue->data = malloc (size * sizeof (int));

  if (queue->data == NULL)
  {
    printf ("Error in create: queue data array could not be created.\n");
    exit (EXIT_FAILURE);
  }


  queue->front = -1;
  queue->back = -1;
  queue->size = 0;
  queue->array_size = size;

  return queue;
}

void destroy (Queue queue)
{
  free (queue);
}

void enqueue (Queue queue, int value)
{
  if (queue->size == 0)
  {
    queue->data[0] = value;
    queue->front = queue->back = 0;
    queue->size = 1;
    return;
  }
  if (queue->size > 0 && !is_full (queue))
  {
    queue->data[++queue->back] = value;
    queue->size++;
  }
  else if (is_full (queue))
  {
    if (queue->back == queue->array_size - 1)
    {
      queue->back -= queue->array_size;
    }
    queue->data[++queue->back] = value;
    queue->front++;
  }

}

int dequeue (Queue queue)
{
  int to_return = queue->data[queue->front];

  if (is_empty (queue))
  {
    printf ("Error: queue is empty\n");
  }
  else
  {
    queue->data[queue->front] = 0;
    queue->size--;
    if (queue->front == queue->array_size - 1)
    {
      queue->front -= queue->array_size;
    }
    queue->front++;
  }
  return to_return;
}

int next_enqueue (Queue queue)
{
  return queue->data[queue->front];
}

int last_enqueue (Queue queue)
{
  return queue->data[queue->back];
}

bool is_empty (Queue queue)
{
  return queue->size == 0 ? true : false;
}

bool is_full (Queue queue)
{
  return queue->size == queue->array_size;
}

int queue_size (Queue queue)
{
  return queue->size;
}

void print_queue (Queue queue)
{
  printf ("queue is: ");
  for (int *p = queue->data; p < queue->data + queue->array_size; p++)
    printf ("%d ", *p);
  printf ("\n");
}