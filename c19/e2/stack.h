//
// Created by martin on 04/11/2021.
//

#ifndef _STACK_H_
#define _STACK_H_


#include <stdbool.h>

void make_empty(void);

bool is_empty(void);

bool is_full(void);

void push(int data);

int pop(void);

#endif //_STACK_H_
