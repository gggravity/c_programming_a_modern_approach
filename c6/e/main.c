#include <stdio.h>
#include <math.h>

int test ()
{
  return 1;
}

int main ()
{
  int i = 1;

  while (i <= 128)
  {
    printf ("%d ", i);
    i *= 2;
  }

  printf ("\n"); // 2

  i = 9384;
  do
  {
    printf ("%d ", i);
    i /= 10;
  }
  while (i > 0);

  printf ("\n"); // 3

  int j;
  for (i = 5, j = i - 1; i > 0, j > 0; --i, j = i - 1)
  {
    printf ("e3: i:%d j:%d\n", i, j);
  }

  printf ("\n"); // 4

  printf ("e4a: "); // increment i after the body of the loop.
  for (i = 0; i < 10; i++)
  {
    printf ("%d ", i);
  }
  printf ("\n");

  printf ("e4b: "); // increment i after the body of the loop.
  for (i = 0; i < 10; ++i)
  {
    printf ("%d ", i);
  }
  printf ("\n");

  printf ("e4c: "); // increment i before the body of the loop.
  for (i = 0; i++ < 10;)
  {
    printf ("%d ", i);
  }

  printf ("\n"); // 5

  printf ("e5a: ");
  i = 11;
  while (i < 10)
  {
    printf ("%d ", i);
    i++;
  }
  printf ("\n");

  printf ("e5b: ");
  i = 11;
  for (; i < 10;)
  {
    printf ("%d ", i);
    i++;
  }
  printf ("\n");

  printf ("e5c: "); // the body of the loop will always run once.
  i = 11;
  do
  {
    printf ("%d ", i);
    i++;
  }
  while (i < 10);

  printf ("\n"); // 6

  for (i = 1; i <= 128; i *= 2)
  {
    printf ("%d ", i);
  }

  printf ("\n"); // 7

  for (i = 9384; i > 0; i /= 10)
  {
    printf ("%d ", i);
  }

  printf ("\n"); // 8

//  for (i = 10; i >= 1; i /= 2)     // produce garbage :-)
//  {                                // i /= 2 halves i everytime.
//    printf ("%d ", i++);    // i++ at the end makes the loops continue forever.
//  }
//
//  printf ("\n"); // 9
//
//  i = 10;
//  while (i >= 1)
//  {
//    printf ("%d ", i++);
//    i /= 2;
//  }

//  printf ("\n"); // 10

//  for (;;)
//  {
//    if (!test)
//      continue;
//    if (!test)
//      continue;
//  }
//
//  for (;;)
//  {
//    if (!test)
//      goto end;
//    if (!test)
//      goto end;
//    end:;
//  }

  printf ("e11: "); // 11

  int sum = 0;
  for (i = 0; i < 10; i++)
  {
    if (i % 2) // skip odd numbers
      continue;
    sum += i;
  }
  printf ("%d ", sum); // sum of even numbers below 10

  printf ("\ne12: "); // 12

  int d;
  const int n = 2000000000;
  for (d = 2001; d < n; d++)
  {
    if (n % d == 0)
      break;
  }
  printf ("%d ", d);

  for (d = 2001; d < sqrt (n); d++)
  {
    if (n % d == 0)
      break;
  }
  printf ("%d ", d);

  for (d = 2001; d * d <= n; d++)
  {
    if (n % d == 0)
      break;
  }
  printf ("%d ", d);

  printf ("\ne13: "); // 13


  for (int n = 0, m = 100; m > 0; n++)
  {
    m /= 2;
    printf ("%d ", n);
  }

  printf ("\ne13: ");
  for (int n = 0, m = 100; m > 0; n++, m /= 2)
  {
    printf ("%d ", n);
  }

  printf ("\ne14: "); // 14

  for (int n = 0; n <= 10; n++)
  {
    if (n % 2 == 0)
      printf ("n: %d -> n is even\n", n);
    else
      printf ("n: %d -> n is odd\n", n);
  }

  return 0;
}
