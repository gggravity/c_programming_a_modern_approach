#include <stdio.h>

int main ()
{
  int i = 5, j = 3;

  printf ("a: %d %d\n", i / j, i % j);
  i = 2, j = 3;
  printf ("b: %d\n", (i + 10) % j);
  i = 7, j = 8;
  int k = 9;
  printf ("c: %d\n", (i + 10) % k / j);
  i = 1, j = 2, k = 3;
  printf ("d: %d\n", (i + 5) % (j + 2) / k);

  i = 5, j = 2;
  printf ("2: %d %d\n", (-i) / j, -(i / j)); // result is always 0 or negative.

  printf ("3a: %d\n", 8 / 5);
  printf ("3b: %d\n", -8 / 5);
  printf ("3c: %d\n", 8 / -5);
  printf ("3d: %d\n", -8 / -5);

  int total = 1234232;
  int test1 = 9 - ((total - 1) % 10);
  int test2 = (total % 10) % 10; // wrong math.
  printf ("test1: %d, test2: %d\n", test1, test2);

  int test3 = (10 - (total % 10)) % 10;
  printf ("test3: %d\n", test3);

  i = 7, j = 8;
  i *= j + 1;
  printf ("9a: %d %d\n", i, j);

  i = j = k = 1;
  i += j += k;
  printf ("9b: %d %d %d\n", i, j, k);

  i = 1, j = 2, k = 3;
  i -= j -= k;
  printf ("9c: %d %d %d\n", i, j, k);

  i = 2, j = 1, k = 0;
  i *= j *= k;
  printf ("9d: %d %d %d\n", i, j, k);

  i = 6;
  j = i += i;
  printf ("10a: %d %d\n", i, j);

  i = 5;
  j = (i -= 2) + 1;
  printf ("10b: %d %d\n", i, j);

  i = 7;
  j = 6 + (i = 2.5);
  printf ("10c: %d %d\n", i, j);

  i = 2, j = 8;
  j = (i = 6) + (j = 3);
  printf ("10d: %d %d\n", i, j);

  i = 1;
  printf ("11a: %d \n", i++ - 1); // 0
  printf ("11a: %d\n", i); // 2

  i = 10, j = 5;
  printf ("11b: %d\n", i++ - ++j); // 4
  printf ("11b: %d %d\n", i, j); // 11 6

  i = 7, j = 8;
  printf ("11c: %d\n", i++ - --j); // 0
  printf ("11c: %d %d\n", i, j); // 8 7

  i = 3, j = 4, k = 5;
  printf ("11d: %d\n", i++ - j++ + --k); // 3
  printf ("11d: %d %d %d\n", i, j, k); // 4 5 4

  i = 5;
  j = ++i * 3 - 2;
  printf ("12a: %d %d\n", i, j); // 6 16

  i = 5;
  j = 3 - 2 * i++;
  printf ("12b: %d %d\n", i, j); // 6 -7

  i = 7;
  j = 3 * i-- + 2;
  printf ("12c: %d %d\n", i, j); // 6 23

  i = 7;
  j = 3 + --i * 2;
  printf ("12d: %d %d\n", i, j); // 6 15

  // 13 ++i -> i += 1
  i = 1;
  printf ("%d ", ++i); // i = i + 1;
  i = 1;
  printf ("%d ", i++); // i = i; i = i + 1;
  i = 1;
  printf ("%d\n", i += 1); // i = i + 1;

  int a = 1, b = 2, c = 3, d = 4, e = 5;
  printf ("14a: %d\n", a * b - c * d + e);
  printf ("14a: %d\n", (a * b) - (c * d) + e);
  printf ("14b: %d\n", a / b % c / d);
  printf ("14b: %d\n", (((a / b) % c) / d));
  printf ("14c: %d\n", -a - b + c - +d);
  printf ("14c: %d\n", (-a) - b + c - (+d));
  printf ("14d: %d\n", a * -b / c - d);
  printf ("14d: %d\n", ((a * (-b)) / c) - d);

  i = 1, j = 2;
  printf ("15a: 3 = %d\n", i += j);

  i = 1, j = 2;
  printf ("15b: 1 = %d\n", i--);

  i = 1, j = 2;
  printf ("15c: 2 = %d\n", i * j / i);

  i = 1, j = 2;
  printf ("15d: 1 = %d\n", i % ++j);

  return 0;
}
