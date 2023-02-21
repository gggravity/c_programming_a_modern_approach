//
// Created by martin on 05/11/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct node
{
    int data;
    struct node *next;
};

struct stack_type {
    struct node *top;
};

static void terminate (const char *messages)
{
  printf ("%s\n", messages);
  exit (EXIT_FAILURE);
}

Stack create (void)
{
  Stack s = malloc (sizeof (struct stack_type));
  if (s == NULL)
  {
    terminate ("Error in create: stack could not be created.\n");
  }

  s->top = NULL;

  return s;
}

void destroy (Stack s)
{
  free (s);
}

void make_empty (Stack s)
{
  while (!is_empty (s))
    pop(s);
}

bool is_empty (Stack s)
{
  return s->top == NULL;
}

bool is_full (Stack s)
{
  return false;
}

void push (Stack s, int i)
{
  struct node * new_node = malloc (sizeof (struct stack_type));
  if (new_node == NULL)
  {
    terminate ("Error pushing to stack: stack could not be created.\n");
  }

  new_node->data = i;
  new_node->next = s->top;
  s->top = new_node;

}

int pop (Stack s)
{
  if (is_empty (s))
    terminate ("Error in pop: stack is empty.");

  struct node *pop = s->top;
  int data = s->top->data;
  s->top = s->top->next;
  free (pop);

  return data;
}
