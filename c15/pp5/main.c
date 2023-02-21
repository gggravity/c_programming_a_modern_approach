#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// 1 2 3 * + =
// 5 8 * 4 9 - / =
 //





int main ()
{
  char ch;

  for (;;)
  {
    printf ("Enter an RPN expression (q to quit):");

    while ((ch = (char)getchar ()))
    {
      if (ch >= '0' && ch <= '9')
      {
        push (ch - '0');
      }
      else if (ch == '+')
      {
        push (pop () + pop ());
      }
      else if (ch == '-')
      {
        int l = pop ();
        int f = pop ();
        push (f - l);
      }
      else if (ch == '*')
      {
        push (pop () * pop ());
      }
      else if (ch == '/')
      {
        int b = pop ();
        int t = pop ();
        push (t / b);
      }
      else if (ch == '=')
      {
        printf ("Value of expression: %d\n", pop ());
        break;
      }
      else if (ch == 'q' || ch == 'Q')
        exit (EXIT_SUCCESS);
    }
  }

}
