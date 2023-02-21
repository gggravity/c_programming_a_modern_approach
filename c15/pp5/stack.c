//
// Created by martin on 24/10/2021.
//

#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

#define STACK_SIZE 100

int stack[STACK_SIZE];
int top = 0;

bool is_empty ()
{
  return top == 0;
}

void push (int i)
{
  if (top == STACK_SIZE - 1)
  {
    printf ("stack overflow");
    exit (EXIT_FAILURE);
  }

  stack[top++] = i;
}

int pop ()
{
  if (is_empty ())
  {
    printf ("stack underflow");
    exit (EXIT_SUCCESS);
  }

  return stack[--top];
}