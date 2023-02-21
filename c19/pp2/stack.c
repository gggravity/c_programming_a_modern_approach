//
// Created by martin on 06/11/2021.
//

#include "stack.h"

struct stack_type {
    Item *contents;
    int top;
    int size;
};

Stack create (int size)
{
  Stack stack = malloc (sizeof (struct stack_type));

  if (stack == NULL)
  {
    printf ("Error allocating stack_type.");
    exit (EXIT_FAILURE);
  }

  stack->contents = malloc (size * sizeof (Item));
  if (stack->contents == NULL)
  {
    printf ("Error allocating stack contents.");
    exit (EXIT_FAILURE);
  }

  stack->top = 0;
  stack->size = size;

  return stack;
}

bool is_empty (Stack stack)
{
  return stack->top == 0;
}

void push (Stack stack, Item item)
{
  if (stack->top == stack->size - 1)
  {
    printf ("stack overflow");
    exit (EXIT_FAILURE);
  }

  stack->contents[stack->top++] = item;
}

Item pop (Stack stack)
{
  if (is_empty (stack))
  {
    printf ("stack underflow");
    exit (EXIT_SUCCESS);
  }

  return stack->contents[--stack->top];
}
