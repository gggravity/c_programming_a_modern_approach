#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACK_SIZE 100

int contents[STACK_SIZE];
int *ptr_top = &contents[0];

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(int i);
int pop(void);

int main ()
{

  push(1);
  push(2);
  push(3);
  printf("%s\n", is_empty() ? "true": "false");
  printf("popping: %d\n", pop());
  make_empty();
  for (int i = 0; i < STACK_SIZE - 1; i++)
    push(1);

  return 0;
}

void make_empty(void)
{
  ptr_top = &contents[0];
}
bool is_empty(void)
{
  return ptr_top == &contents[0];
}
bool is_full(void)
{
  return ptr_top == contents + STACK_SIZE - 1;
}
void push(int i)
{
  if (is_full())
  {
    printf ("stack overflow");
    exit (EXIT_FAILURE);
  }
  else
    *ptr_top++ = i;
}
int pop(void)
{
  if(is_empty())
  {
    printf("stack underflow");
    exit (EXIT_FAILURE);
  }
  else
    return *--ptr_top;
}