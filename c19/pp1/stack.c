//
// Created by martin on 16/10/2021.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "stack.h"

struct stack_type {
    Item *contents;
    int top;
    int size;
};

Stack create (int size)
{
  Stack s = malloc (sizeof (struct stack_type));

  if (s == NULL)
  {
    printf ("Memory error 1.");
    exit (EXIT_FAILURE);
  }

  s->contents = malloc (size * sizeof (Item));
  if (s->contents == NULL)
  {
    free (s);
    printf ("Memory error 2.");
    exit (EXIT_FAILURE);
  }

  s->top = 0;
  s->size = size;

  return s;
}

void make_empty (Stack s)
{
  s->top = 0;
}

bool is_empty (Stack s)
{
  return s->top == 0;
}

bool is_full (Stack s)
{
  return s->top == s->size;
}

void push (Stack s, Item ch)
{
  if (is_full (s))
  {
    printf ("stack overflow");
    exit (EXIT_FAILURE);
  }
  else
    s->contents[s->top++] = ch;
}

Item pop (Stack s)
{
  if (is_empty (s))
  {
    printf ("stack underflow");
    exit (EXIT_FAILURE);
  }
  else
    return s->contents[--s->top];
}

