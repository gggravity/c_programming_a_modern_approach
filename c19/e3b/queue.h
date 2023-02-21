//
// Created by martin on 04/11/2021.
//

#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdbool.h>
void enqueue(int value);

int dequeue();

int next_enqueue();

int last_enqueue();

bool is_empty();

int queue_size();

void print_queue();

#endif //_QUEUE_H_
