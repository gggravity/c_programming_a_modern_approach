#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <ctype.h>
#include <float.h>

double triangle_area (double base, double height)
{
  return base * height / 2;
}

bool check (int x, int y, int n)
{
  return x >= 0 && x <= n - 1 && y >= 0 && y <= n - 1 ? true : false;
}

int gcd (int m, int n)
{
  while (n != 0)
  {
    int divisor = m % n;
    m = n;
    n = divisor;
  }
  return m;
}

int day_of_year (int day, int month, int year)
{
  int result = 0;
  int month_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  for (int i = 0; i < month - 1; i++)
  {
    result += month_days[i];
  }
  return result + day;
}

int digits (int n)
{
  int digits = 0;

  while (n > 0)
  {
    n /= 10;
    digits++;
  }

  return digits;
}

int digit (int n, int k)
{
  int result = 0, num_digits = 0;
  for (int i = 0; i < k; i++)
  {
    result = n % 10;
    n /= 10;
    num_digits++;
  }
  if (k > num_digits)
    return 0;
  else
    return result;
}

int f (int a, int b)
{
  return a + b;
}

void f1 (double x);

void f2 (double);

//void f3 (x); // illegal, parameter but no type.

//f3 (double x); // illegal C99, need return type

void swap1 (int a, int b);
void swap2 (int *a, int *b);

int largest (int n, const int a[n])
{
  int max = INT_MIN;

  for (int i = 0; i < n; i++)
  {
    if (a[i] > max)
      max = a[i];
  }
  return max;
}

double average (int n, const int a[n])
{
  double total = 0;

  for (int i = 0; i < n; i++)
  {
    total += a[i];
  }
  return total / n;
}

int number_of_positive_elements (int n, const int a[n])
{
  int count = 0;
  for (int i = 0; i < n; i++)
    if (a[i] >= 0) // are 0 positive?
      count++;
  return count;
}

double compute_GPA (const char grades[], int n)
{
  double total = 0;
  for (int i = 0; i < n; i++)
  {
    switch (grades[i])
    {
    case 'A':
      total += 4;
      break;
    case 'B':
      total += 3;
      break;
    case 'C':
      total += 2;
      break;
    case 'D':
      total += 1;
    default:
      break;
    }
  }
  return total / n;

}

double inner_product (const double a[], const double b[], int n)
{
  double inner_product = 0.0f;

  for (int i = 0; i < n; i++)
  {
    inner_product += a[i] * b[i];
  }
  return inner_product;
}

int chess_char_to_value (char ch)
{
  ch = toupper (ch);

  switch (ch)
  {
  case 'K':
    return 10;
  case 'Q':
    return 9;
  case 'R':
    return 5;
  case 'B':
  case 'N':
    return 3;
  case 'P':
    return 1;
  default:
    return 0;
  }
}

int evaluate_position (char board[8][8])
{
  int sum_white = 0;
  int sum_black = 0;

  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      if (isupper (board[i][j]))
      {
        sum_white += chess_char_to_value (board[i][j]);
      }
      else
      {
        sum_black += chess_char_to_value (board[i][j]);
      }
    }
  }
  return sum_white - sum_black;
}

bool has_zero (const int a[], int n)
{
  for (int i = 0; i < n; i++)
  {
    if ((a[i]) == 0)
      return true;
  }

  return false;
}

double median (double x, double y, double z)
{
  if (x <= y)
    if (y <= z)
      return y;
    else if (x <= z)
      return x;

  if (z <= y)
    return y;
  if (x <= z)
    return x;
  return z;
}

double median_fix (double x, double y, double z)
{
  double median = 0;

  if (x >= y && x <= z || x >= z && x <= y)
    median = x;
  else if (y >= x && y <= z || y >= z && y <= x)
    median = y;
  else
    median = z;

  return median;
}

double median_fix2 (double x, double y, double z)
{
  double median = 0, min = DBL_MAX, max = DBL_MIN;
  double list[] = {x, y, z};

  for (int i = 0; i < 3; i++)
  {
    if (list[i] < min)
      min = list[i];
    if (list[i] > max)
      max = list[i];
  }
  for (int i = 0; i < 3; i++)
    if (list[i] != min && list[i] != max)
      median = list[i];

  return median;
}

double median_fix3 (double x, double y, double z)
{
  double median = 0, min = DBL_MAX, max = DBL_MIN;
  double list[] = {x, y, z};

  for (int i = 0; i < 3; i++)
  {
    if (list[i] < min)
      min = list[i];
    if (list[i] > max)
      max = list[i];
  }

  return (max - min) / 3;
}

int fact (int n)
{
  return n <= 1 ? 1 : n * fact (n - 1);
}

int gcd_recursive (int m, int n)
{
  if (n <= 0)
    return m;

  int divisor = m % n;
  m = n;
  n = divisor;

  return gcd_recursive (m, n);
}

int fact_non_recursive (int n)
{
  int fact = 1;
  for (int i = 2; i <= n; i++)
  {
    fact *= i;
  }
  return fact;
}

void pb (int n)
{
  if (n != 0)
  {
    pb (n / 2);
    putchar ('0' + n % 2);
  }
}

int main ()
{
  printf ("%.f\n", triangle_area (4, 4));
  printf ("%s\n", check (1, 2, 3) ? "true" : "false");
  printf ("%s\n", check (3, 2, 1) ? "true" : "false");
  printf ("%s\n", check (-1, 2, 3) ? "true" : "false");
  printf ("%s\n", check (0, 29, 30) ? "true" : "false");
  printf ("%s\n", check (29, 0, 30) ? "true" : "false");
  printf ("%d\n", gcd (12, 6));
  printf ("%d\n", gcd (140, 4));
  printf ("%d\n", day_of_year (10, 12, 2010));
  printf ("%d\n", day_of_year (1, 1, 2000));
  printf ("%d\n", day_of_year (1, 2, 2000));
  printf ("%d\n", digits (123));
  printf ("%d\n", digits (1));
  printf ("%d\n", digits (123456789));
  printf ("%d\n", digit (123456789, 3));
  printf ("%d\n", digit (123456789, 5));
  printf ("%d\n", digit (123456789, 1));
  printf ("%d\n", digit (123456789, 9));
  printf ("%d\n", digit (123456789, 10));

  int i;
  double x;
  i = f (83, 12);
  printf ("i = f (83, 12): %d\n", i);
  x = f (83, 12);
  printf ("x = f (83, 12): %.f\n", x);
  i = f (3.15, 9.28); // legal, but a = 3 and b = 9
  printf ("i = f (3.15, 9.28): %d\n", i);
  x = f (3.15, 9.28);
  printf ("x = f (3.15, 9.28): %d\n", i); // legal, but a = 3 and b = 9
  printf ("f (83, 12): %d\n", f (83, 12));

  i = 1;
  int j = 2;

  swap1 (i, j);
  printf ("i = %d, j = %d\n", i, j);

  swap2 (&i, &j);
  printf ("i = %d, j = %d\n", i, j);

  printf ("largest: %d\n", largest (9, (int[]) {1, 2, 3, 4, 5, 16, 7, 8, 9}));
  printf ("average: %f\n", average (9, (int[]) {1, 2, 3, 4, 5, 16, 7, 8, 9}));
  printf ("number_of_positive_elements: %d\n", number_of_positive_elements (9, (int[]) {-1, -2, 0, 4, 5, 16, 7, 8, 9}));

  printf ("average of GPA: %.2f\n", compute_GPA ((char[]) {'A', 'A', 'A', 'B', 'F', 'B', 'D'}, 7));

  double m1[] = {1, 2, 3, 4, 5};
  double m2[] = {5, 4, 3, 2, 1};
  printf ("inner_product: %.2f\n", inner_product (m1, m2, 5));

  char b1[8][8] = {
      {'K', 'Q', '.', '.', '.', '.', '.', '.'},
      {'.', '.', '.', '.', '.', '.', '.', '.'},
      {'.', '.', '.', '.', '.', '.', '.', '.'},
      {'.', '.', '.', '.', '.', '.', '.', '.'},
      {'.', '.', '.', '.', '.', '.', '.', '.'},
      {'.', '.', '.', '.', '.', '.', '.', '.'},
      {'.', '.', '.', '.', '.', '.', '.', '.'},
      {'k', 'q', '.', '.', '.', '.', '.', '.'},
  };

  printf ("the board value is: %d\n", evaluate_position (b1));

  char b2[8][8] = {
      {'K', 'Q', '.', '.', '.', '.', '.', '.'},
      {'.', '.', '.', '.', '.', '.', '.', '.'},
      {'.', '.', '.', '.', '.', '.', '.', '.'},
      {'.', '.', '.', '.', '.', '.', '.', '.'},
      {'.', '.', '.', '.', '.', '.', '.', '.'},
      {'.', '.', '.', '.', '.', '.', '.', '.'},
      {'.', '.', 'r', 'b', 'n', 'p', '.', '.'},
      {'k', 'q', '.', '.', '.', '.', '.', '.'},
  };

  printf ("the board value is: %d\n", evaluate_position (b2));

  char b3[8][8] = {
      {'K', 'Q', '.', '.', '.', '.', '.', '.'},
      {'.', '.', 'R', 'B', 'N', 'P', '.', '.'},
      {'.', '.', '.', '.', '.', '.', '.', '.'},
      {'.', '.', '.', '.', '.', '.', '.', '.'},
      {'.', '.', '.', '.', '.', '.', '.', '.'},
      {'.', '.', '.', '.', '.', '.', '.', '.'},
      {'.', '.', '.', '.', '.', '.', '.', '.'},
      {'k', 'q', '.', '.', '.', '.', '.', '.'},
  };

  printf ("the board value is: %d\n", evaluate_position (b3));

  int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  printf ("%s\n", has_zero (arr1, 9) ? "true" : "false");

  int arr2[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
  printf ("%s\n", has_zero (arr2, 9) ? "true" : "false");

  printf ("%f\n", median (1, 2, 3));
  printf ("%f\n", median_fix (1, 2, 3));
  printf ("%f\n", median_fix2 (1, 2, 3));
  printf ("%f\n", median_fix3 (1, 2, 3));

  printf ("%f\n", median (1, 22, 3));
  printf ("%f\n", median_fix (1, 22, 3));
  printf ("%f\n", median_fix2 (1, 22, 3));
  printf ("%f\n", median_fix3 (1, 22, 3));

  printf ("fact(5): %d\n", fact (5));

  printf ("gcd: %d\n", gcd (42, 4));
  printf ("gcd_recursive: %d\n", gcd_recursive (42, 4));
  printf ("gcd: %d\n", gcd (9, 3));
  printf ("gcd_recursive: %d\n", gcd_recursive (9, 3));

  printf ("fact_non_recursive(5): %d\n", fact_non_recursive (5));

  printf("%d\n", 1/2);
  pb(7);

  return 0;
}

void swap1 (int a, int b)
{
  int temp = a;
  a = b;
  b = temp;
}

void swap2 (int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}
