#include <stdio.h>
#include "stack.h"

// ((){}[][{}])
// [(])

int main ()
{
  char ch;
  printf ("Enter parentheses and/or braces:");

  while ((ch = (char)getchar ()) != '\n')
  {
    if (ch == '[' || ch == '(' || ch == '{')
      push (ch);
    else if (ch == ']' || ch == ')' || ch == '}')
    {
      char popped = pop ();
      if (popped == '(' && ch != ')' || popped == '{' && ch != '}' || popped == '[' && ch != ']')
      {
        break;
      }
    }
  }
  if (is_empty ())
    printf ("Parentheses/branches are nested properly");
  else
    printf ("Parentheses/branches are NOT nested properly");

  return 0;
}
