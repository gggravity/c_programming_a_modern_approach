//
// Created by martin on 16/10/2021.
//

#ifndef _STACK_H_
#define _STACK_H_

#include <stdbool.h>

typedef char Item;

typedef struct stack_type *Stack;

Stack create(int size);

void make_empty (Stack s);

bool is_empty (Stack s);

bool is_full (Stack s);

void push (Stack s, Item i);

Item pop (Stack s);

#endif //_STACK_H_
