//
// Created by martin on 04/11/2021.
//

#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdbool.h>

typedef struct queue_type *Queue;

Queue create (void);

void enqueue(Queue q, int value);

int dequeue(Queue q);

int next_enqueue(Queue q);

int last_enqueue(Queue q);

bool is_empty(Queue q);

bool is_full(Queue q);

int queue_size(Queue q);

void print_queue(Queue q);

#endif //_QUEUE_H_
