//
// Created by martin on 04/11/2021.
//

#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdbool.h>

typedef struct queue_type *Queue;

Queue create (void);

void destroy (Queue queue);

void enqueue (Queue queue, int value);

int dequeue (Queue queue);

int next_enqueue (Queue queue);

int last_enqueue (Queue queue);

bool is_empty (Queue queue);

int queue_size (Queue queue);

void print_queue (Queue queue);

#endif //_QUEUE_H_
