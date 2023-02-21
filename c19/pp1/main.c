#include <stdio.h>
#include "stack.h"

// ((){}[][{}])
// [(])

int main ()
{
  Stack stack;

  stack = create (100);

  char ch;
  printf ("Enter parentheses and/or braces:");

  while ((ch = (char)getchar ()) != '\n')
  {
    if (ch == '[' || ch == '(' || ch == '{')
      push (stack, ch);
    else if (ch == ']' || ch == ')' || ch == '}')
    {
      Item popped = pop (stack);
      if (popped == '(' && ch != ')' || popped == '{' && ch != '}' || popped == '[' && ch != ']')
      {
        break;
      }
    }
  }
  if (is_empty (stack))
    printf ("Parentheses/branches are nested properly");
  else
    printf ("Parentheses/branches are NOT nested properly");

  return 0;
}
