#include <stdio.h>

int main ()
{
//  short factorial = 1, n = 7; // short 7
//  int factorial = 1, n = 12; // int  12
//  long factorial = 1; // int 12
//  int n = 12; // int  12
//  long long factorial = 1; // long long 20
//  int n = 20; // int  12
//  float factorial = 1; // float 34
//  int n = 34; // int  12
//  double factorial = 1; // double 170
//  int n = 170; // int  12
  long double factorial = 1; // double 170
  int n = 170; // int  12

  for (int i = 1; i <= n; i++)
  {
    factorial *= i;
  }

  printf ("%d! = %Lg\n", n, factorial);

  return 0;
}
