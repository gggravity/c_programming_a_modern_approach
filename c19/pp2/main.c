#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// 1 2 3 * + =
// 5 8 * 4 9 - / =
 //


int main ()
{
  char ch;

  Stack stack = create (100);

  for (;;)
  {
    printf ("Enter an RPN expression:");

    while (ch = getchar ())
    {
      if (ch >= '0' && ch <= '9')
      {
        push (stack, ch - '0');
      }
      else if (ch == '+')
      {
        push (stack, pop (stack) + pop (stack));
      }
      else if (ch == '-')
      {
        int l = pop (stack);
        int f = pop (stack);
        push (stack, f - l);
      }
      else if (ch == '*')
      {
        push (stack, pop (stack) * pop (stack));
      }
      else if (ch == '/')
      {
        int b = pop (stack);
        int t = pop (stack);
        push (stack, t / b);
      }
      else if (ch == '=')
      {
        printf ("Value of expression: %d\n", pop (stack));
        break;
      }
      else if (ch == 'q' || ch == 'Q')
        exit (EXIT_SUCCESS);
    }
  }

}
