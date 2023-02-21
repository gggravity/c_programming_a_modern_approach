//
// Created by martin on 04/11/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

struct node {
    int data;
    struct node *next;
};

struct queue_type {
    struct node *front;
    struct node *back;
    int size;
};


Queue create (void)
{
  Queue queue = malloc (sizeof (struct queue_type));

  if (queue == NULL)
  {
    printf ("Memory error.\n");
    exit (EXIT_FAILURE);
  }

  queue->front = NULL;
  queue->back = NULL;
  queue->size = 0;

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
    struct node *new_node;

    new_node = malloc (sizeof (struct node));

    if (new_node == NULL)
    {
      printf ("Memory error.");
      exit (EXIT_FAILURE);
    }

    new_node->data = value;
    new_node->next = NULL;

    queue->front = queue->back = new_node;
    queue->size = 1;
    return;
  }
  if (queue->size > 0)
  {
    struct node *new_node;

    new_node = malloc (sizeof (struct node));

    if (new_node == NULL)
    {
      printf ("Memory error.");
      exit (EXIT_FAILURE);
    }
    new_node->data = value;
    new_node->next = NULL;

    queue->back->next = new_node;
    queue->back = new_node;

    queue->size++;
  }
}

int dequeue (Queue queue)
{
  int to_return = queue->front->data;

  if (is_empty (queue))
  {
    printf ("Error: queue is empty\n");
  }
  else
  {
    struct node *p = queue->front;
    queue->front = queue->front->next;
    queue->size--;
    free(p);
  }
  return to_return;
}

int next_enqueue (Queue queue)
{
  return queue->front->data;
}

int last_enqueue (Queue queue)
{
  return queue->back->data;
}

bool is_empty (Queue queue)
{
  return queue->size == 0 ? true : false;
}

int queue_size (Queue queue)
{
  return queue->size;
}

void print_queue (Queue queue)
{
  printf ("queue is: ");
  for (struct node *p = queue->front; p != NULL; p = p->next)
    printf ("%d ", p->data);
  printf ("\n");
}