//
// Created by martin on 06/11/2021.
//

#ifndef _STACK_H_
#define _STACK_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef int Item;

typedef struct stack_type *Stack;

Stack create(int size);

bool is_empty (Stack stack);

void push (Stack stack, Item item);

Item pop (Stack stack);

#endif //_STACK_H_
