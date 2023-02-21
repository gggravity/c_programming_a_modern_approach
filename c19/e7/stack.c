//
// Created by martin on 05/11/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct stack_type {
    Item *contents;
    int top;
    int size;
};

static inline void terminate (const char *messages)
{
  printf ("%s\n", messages);
  exit (EXIT_FAILURE);
}


Stack create (int size)
{
  Stack s = malloc (sizeof (struct stack_type));

  if (s == NULL)
  {
    terminate ("Error in create: stack could not be created.\n");
  }

  s->contents = malloc (size * sizeof (Item));

  if (s->contents == NULL)
  {
    free (s);
    terminate ("Error in create: stack could not be created.\n");
  }

  s->top = 0;
  s->size = size;

  return s;
}

void destroy (Stack s)
{
  free (s->contents);
  free (s);
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

void push (Stack s, int i)
{
  if (is_full (s))
  {
    s->size *= 2;
    s->contents = realloc(s->contents, s->size);
  }
  s->contents[s->top++] = i;
}

Item pop (Stack s)
{
  if (is_empty (s))
    terminate ("Error in pop: stack is empty.");
  return s->contents[--s->top];
}

Item peek (Stack s)
{
  if (is_empty (s))
    terminate ("Error in peek: stack is empty.");
  return s->contents[s->top - 1];
}

int stack_size (Stack s)
{
  return s->size;
}