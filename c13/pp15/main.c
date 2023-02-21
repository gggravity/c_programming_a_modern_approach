#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACK_SIZE 100

int evaluate_RPN_expression (const char *expression);

bool is_empty ();

void push (int i);

int pop ();

// 1 2 3 * + =
// 7
// 5 8 * 4 9 - / =
// -8

int stack[STACK_SIZE];

int top = 0;

int main ()
{
  char ch;
  char expression[500];

  for (;;)
  {
    printf ("Enter an RPN expression (q to quit):");

    int i = 0;
    while ((ch = getchar ()) != '\n')
    {
      if (ch == 'q')
        exit (EXIT_SUCCESS);
      expression[i++] = ch;
    }
    expression[i + 1] = '\0';
    printf ("%d\n", evaluate_RPN_expression (expression));
  }
}

int evaluate_RPN_expression (const char *expression)
{
  int result = 0;

  while (*expression)
  {
    if (*expression >= '0' && *expression <= '9')
    {
      push (*expression - '0');
    }
    else if (*expression == '+')
    {
      push (pop () + pop ());
    }
    else if (*expression == '-')
    {
      int l = pop ();
      int f = pop ();
      push (f - l);
    }
    else if (*expression == '*')
    {
      push (pop () * pop ());
    }
    else if (*expression == '/')
    {
      int b = pop ();
      int t = pop ();
      push (t / b);
    }
    else if (*expression == '=')
    {
      result = pop ();
      break;
    }
    expression++;
  }
  return result;
}

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