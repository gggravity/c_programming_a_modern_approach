//
// Created by martin on 02/11/2021.
//

#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdbool.h>

typedef int Item;

struct node
{
    Item data;
    struct node *next;
};
typedef struct node node;

struct Queue
{
    int count;
    node *front;
    node *rear;
};
typedef struct Queue Queue;

void initialize(Queue *q);

bool is_empty(Queue *q);

void enqueue(Queue *q, Item value);

Item dequeue(Queue *q);

#endif //_QUEUE_H_
