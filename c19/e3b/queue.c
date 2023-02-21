//
// Created by martin on 04/11/2021.
//

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "queue.h"

struct node {
    int data;
    struct node *next;
} node;

static struct node *front;
static struct node *back;
static int size = 0;

void enqueue (int value)
{
  if (size == 0)
  {
    struct node *new_node;

    new_node = malloc (sizeof (node));

    if (new_node == NULL)
    {
      printf ("Memory error.");
      exit (EXIT_FAILURE);
    }

    new_node->data = value;
    new_node->next = NULL;

    front = back = new_node;
    size = 1;
    return;
  }
  if (size > 0)
  {
    struct node *new_node;

    new_node = malloc (sizeof (node));

    if (new_node == NULL)
    {
      printf ("Memory error.");
      exit (EXIT_FAILURE);
    }
    new_node->data = value;
    new_node->next = NULL;

    back->next = new_node;
    back = new_node;

    size++;
  }
}

int dequeue ()
{
  int to_return = front->data;

  if (is_empty ())
  {
    printf ("Error: queue is empty\n");
  }
  else
  {
    struct node *p = front;
    front = front->next;
    size--;
    free(p);
  }
  return to_return;
}

int next_enqueue ()
{
  return front->data;
}

int last_enqueue ()
{
  return back->data;
}

bool is_empty ()
{
  return size == 0 ? true : false;
}

int queue_size ()
{
  return size;
}

void print_queue ()
{
  printf ("queue is: ");
  for (struct node *p = front; p != NULL; p = p->next)
    printf ("%d ", p->data);
  printf ("\n");
}