#include <stdio.h>

int a;

void f(int b)
{
  int c;
}

void g(void)
{
  int d;
  {
    int e;
  }
}

int main ()
{
  int f;

  f(1); // error f defined in main. if not defined a, b, c.
  g(); //


  return 0;
}
