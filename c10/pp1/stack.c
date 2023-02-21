//
// Created by martin on 16/10/2021.
//
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define  STACK_SIZE 100

char contents[STACK_SIZE];
int top = 0;

void make_empty (void)
{
  top = 0;
}

bool is_empty (void)
{
  return top == 0;
}

bool is_full (void)
{
  return top == STACK_SIZE;
}

void push (char ch)
{
  if (is_full ())
  {
    printf ("stack overflow");
    exit (EXIT_FAILURE);
  }
  else
    contents[top++] = ch;
}

char pop (void)
{
  if (is_empty ())
  {
    printf ("stack underflow");
    exit (EXIT_FAILURE);
  }
  else
    return contents[--top];
}

