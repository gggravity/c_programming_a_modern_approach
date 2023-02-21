//
// Created by martin on 02/11/2021.
//

#include "queue.h"

#include <stdio.h>
#include <stdlib.h>



void initialize(Queue *q)
{
  q->count = 0;
  q->front = NULL;
  q->rear = NULL;
}

void enqueue(Queue *q, Item value)
{
  node *new_node;
  new_node = malloc(sizeof(node));
  new_node->data = value;
  new_node->next = NULL;

  if(!is_empty(q))
  {
    q->rear->next = new_node;
    q->rear = new_node;
  }
  else
  {
    q->front = q->rear = new_node;
  }
  q->count++;
}

Item dequeue(Queue *q)
{
  node *temp_node;
  Item data = q->front->data;
  temp_node = q->front;
  q->front = q->front->next;
  q->count--;
  free(temp_node);

  return(data);
}

bool is_empty(Queue *q)
{
    return (q->rear == NULL);
}

