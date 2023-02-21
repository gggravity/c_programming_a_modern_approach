#include <stdio.h>
#include <assert.h>
#include <errno.h>
#include <math.h>
#include <stdlib.h>
#include <setjmp.h>
#include "stack.h"

void insert(void);
void search(void);
void update(void);
void print(void);



double try_math_fcn (double (*f) (double), double x, char *message)
{
  errno = 0;
  double y = f (x);
  if (errno != 0)
  {
    perror (message);
    exit (EXIT_FAILURE);
  }
  return y;
}

#define TRY_MATH_FCN(func, x) (try_math_fcn((func), (x), "Error in call of " #func))

jmp_buf env;

int main ()
{

  char code;

  for (;;)
  {

    setjmp(env);

    printf ("Enter operation code: ");
    scanf (" %c", &code);
    while (getchar () != '\n');
    switch (code)
    {
    case 'i':
      insert ();
      break;
    case 's':
      search ();
      break;
    case 'u':
      update ();
      break;
    case 'p':
      print ();
      break;
    case 'q':
      return 0;
    default:
      printf ("Illegal code\n");
    }
    printf ("\n");
  }

  //  double x, y;
//
//  x = 2.0f;
//
//  y = try_math_fcn(sqrt, x, "Error in call of sqrt");
//  printf("y: %.2f\n", y);
//
//  y = TRY_MATH_FCN(sqrt, x);
//  printf("y: %.2f\n", y);

  //  int *top = NULL;
//  int i = 0;
//
//  assert(top != NULL);

//  Stack stack;
//
//  stack = create(100);
//
//
//  push(stack, 1);
//  push(stack, 2);
//  push(stack, 3);
//
//  printf ("is_empty: %s\n", is_empty (stack) ? "true" : "false");
//
//  while (!is_empty (stack))
//    printf ("popping: %d\n", pop (stack));
//
//  printf ("is_empty: %s\n", is_empty (stack) ? "true" : "false");

//  pop(stack);

  return 0;
}

void insert(void)
{
  longjmp(env, 1);
  printf("running insert\n");
}

void search(void)
{
  printf("running search\n");
}

void update(void)
{
  printf("running update\n");
}

void print(void)
{
  printf("running print\n");
}