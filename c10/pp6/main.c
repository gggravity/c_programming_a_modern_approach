#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 1 2 3 * + =
// 5 8 * 4 9 - / =
 //

#define STACK_SIZE 100

int stack[STACK_SIZE];

int top = 0;

bool is_empty ()
{
  return top == 0;
}

void push (int i)
{
  if (top == STACK_SIZE - 1)
  {
    printf ("stack overflow");
    exit (EXIT_FAILURE);
  }

  stack[top++] = i;
}

int pop ()
{
  if (is_empty ())
  {
    printf ("stack underflow");
    exit (EXIT_SUCCESS);
  }

  return stack[--top];
}

int main ()
{
  char ch;

  for (;;)
  {
    printf ("Enter an RPN expression:");

    while (ch = getchar ())
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
