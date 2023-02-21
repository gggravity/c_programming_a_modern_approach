//
// Created by martin on 05/11/2021.
//

#ifndef _STACK_H_
#define _STACK_H_

#include <stdbool.h>

typedef struct stack_type *Stack;

Stack create(void);

void destroy(Stack s);

void make_empty(Stack s);

bool is_empty(Stack s);

bool is_full(Stack s);

void push(Stack s, int i);

int pop(Stack s);

#endif //_STACK_H_
