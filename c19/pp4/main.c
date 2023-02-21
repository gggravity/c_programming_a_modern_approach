#include <stdio.h>
#include "stack.h"

int main ()
{
  char *n;
  Stack s1, s2;

  s1 = create ();
  s2 = create ();

  char *str1 = "str1";
  char *str2 = "str2";
  char *str3 = "str3";

  push (s1, str1);
  push (s1, str2);

  printf ("len of s1: %d \n", length (s1));

  n = pop (s1);
  printf ("Popped: %s from s1\n", n);
  push (s2, n);
  n = pop (s1);
  printf ("Popped: %s from s1\n", n);
  push (s2, n);

  printf ("len of s1: %d \n", length (s1));
  printf ("len of s2: %d \n", length (s2));

  destroy (s1);

  while (!is_empty (s2))
    printf ("Popped: %s from s2\n", (char *)pop (s2));

  push (s2, str3);
  printf ("len of s2: %d \n", length (s2));

  make_empty (s2);
  printf ("len of s2: %d \n", length (s2));

  if (is_empty (s2))
    printf ("s2 is empty\n");
  else
    printf ("s2 is not empty\n");

  destroy (s2);

  return 0;
}
