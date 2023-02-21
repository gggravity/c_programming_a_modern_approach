#include <stdio.h>
#include "stack.h"

#define N 10

int main ()
{
  int n;
  Stack s1, s2;

  s1 = create (1);

  for (int i = 1; i <= N; i++)
  {
    push (s1, i);
    printf ("size: %d\n", stack_size (s1));
    printf ("Peeking at s1: %d\n", peek (s1));
  }

    while (!is_empty (s1))
    printf ("Popped: %d from s1\n", pop (s1));

//  printf ("Peeking at s1: %d\n", peek (s1));
//  printf ("Peeking at s1: %d\n", peek (s1));

  //  s2 = create();
//
//  push (s1, 1);
//  push (s1, 2);
//
//  n = pop (s1);
//  printf ("Popped: %d from s1\n", n);
//  push(s2, n);
//  n = pop (s1);
//  printf ("Popped: %d from s1\n", n);
//  push(s2, n);
//
//  destroy (s1);
//
//  while (!is_empty (s2))
//    printf ("Popped: %d from s2\n", pop (s2));
//
//  push (s2, 3);
//  make_empty (s2);
//
//  if(is_empty (s2))
//    printf ("s2 is empty\n");
//  else
//    printf ("s2 is not empty\n");
//
//  destroy (s2);


  return 0;
}
