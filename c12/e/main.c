#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define N 10

int sum_array (const int a[], int n);
int sum_array_new (const int a[], int n);
bool search (const int a[], int n, int key);
double inner_product (const double *a, const double *b, int n);
void store_zeros (int a[], int n);
int *find_middle (int a[], int n);
int *find_middle_new (int a[], int n);
int find_largest (const int a[], int n);
int find_largest_new (const int a[], int n);
void find_two_largest (const int *a, int n, int *largest, int *second_largest);
void indent (int n, double a[n][n]);
void indent_new (int n, double a[n][n]);
void init_random (int n, int m, int a[n][m]);
void plot_matrix (int n, int a[n]);
void plot_matrix2d (int n, int m, int a[n][m]);
void plot_rows2d (int n, int m, int a[n][m], int row);
void plot_high_of_day (int n, int m, int a[n][m]);
int sum_two_dimensional_array (int n, int m, const int a[n][m]);
int sum_two_dimensional_array_new (int n, int m, const int a[n][m]);
int evaluate_position (char board[8][8]);
int evaluate_position_new (char board[8][8]);
int chess_char_to_value (char ch);

int main ()
{
  // e 1
//  int a[] = {5, 15, 34, 54, 14, 2, 52, 72};
////  int *p = &a[1], *q = &a[5];
//  int n = sizeof a / sizeof a[0];

//  printf ("%d\n", *(p + 2)); // 54
//  printf ("%d\n", *(q - 3)); // 34
//  printf ("%lld\n", q - p); // 4
//  printf ("%s\n", p < q ? "true" : "false"); // true
//  printf ("%s\n", *p < *q ? "true" : "false"); // false

  // e 2
//  int *low = &a[0];
//  int *middle = &a[1];
//  int *high = &a[7];
//
//  for (int i = 0; i < n; i++)
//    printf ("%d ", a[i]);
//  printf ("\n");
//
//  printf ("%d %d %d\n", *low, *middle, *high);
//
//  middle = (low + ((high - low) / 2));
//
//  for (int *p = a; p < a + n; p++)
//    printf ("%d ", *p);
//  printf ("\n");
//
//  printf ("%d %d %d\n", *low, *middle, *high);

  // e 3

//  int a[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//  int *p = &a[0], *q = &a[N-1], temp;
//
//  while (p < q)
//  {
//    temp = *p;
//    *p++ = *q;
//    *q-- = temp;
//  }
//
//  for(int *ip = a; ip < a + N; ip++)
//  {
//    printf ("%d ", *ip);
//  }

  // e 4 see stack

  // e 5

//  int a[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//  int *p;
//  p = a;
//
//  printf("%s\n", p == a[0] ? "true" : "false"); // wrong, int* and int eq false
//  printf("%s\n", p == &a[0] ? "true" : "false"); // ok is true
//  printf("%s\n", *p == a[0] ? "true" : "false"); // ok is true
//  printf("%s\n", p[0] == a[0] ? "true" : "false"); // ok is true

  // e 6

//  int a[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//
//  printf ("sum_array: %d\n", sum_array (a, N));
//  printf ("sum_array_new: %d\n", sum_array_new (a, N));

  // e 7

//  int a[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//
//  printf("%s\n", search (a, N, 3) ? "true" : "false");
//  printf("%s\n", search (a, N, 0) ? "true" : "false");

  // e 8

//  int a[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//
//  for (int *p = a; p < a + N; p++)
//    printf ("%3d", *p);
//  printf ("\n");
//
//  store_zeros (a, N);
//
//  for (int *p = a; p < a + N; p++)
//    printf ("%3d", *p);
//  printf ("\n");


  // e 9

//  double a[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//  double b[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//
//  printf ("%.2f", inner_product (a, b, N));

  // e 10

//  int a[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//
//  printf ("%d\n", *find_middle (a, N));
//
//  printf ("%d\n", *find_middle_new (a, N));

  // e 11

//  int a[] = {5, 15, 34, 54, 14, 2, 52, 72};
//  int n = sizeof a / sizeof a[0];
//
//  printf ("%d\n", find_largest (a, n));
//  printf ("%d\n", find_largest_new (a, n));

  // e 12

//  int largest, second_largest;
//  int a[] = {5, 15, 34, 54, 14, 2, 52, 72};
//
//  find_two_largest (a, sizeof a / sizeof a[0], &largest, &second_largest);
//
//  printf ("largest: %d : second_largest: %d\n", largest, second_largest);

// e 13

//  double a[N][N];

//  indent (N, a);
//
//  for (int i = 0; i < N; i++)
//  {
//    for (int j = 0; j < N; j++)
//    {
//      printf ("%4.f", a[i][j]);
//    }
//    printf ("\n");
//  }

//  indent_new (N, a);
//
//  for (double *p = &a[0][0], i = 1; p <= &a[N - 1][N - 1]; p++)
//  {
//    printf ("%3.f", *p);
//    if ((int)i % 10 == 0)
//      printf ("\n");
//    i++;
//  }

  // e 14
//  int a[7][24];
//
//  init_random (7, 24, a);
//
//  printf("%s\n", search (a[0],24*7, 10) ? "true" : "false");
//
//  plot_matrix2d (7, 24, a);

  // e 15

//  int temperature[7][24];
//
//  init_random (7, 24, temperature);
//
//  plot_matrix2d (7,24, temperature);
//
//  printf("------------------------------\n");
//
//  int row = 3;
//  printf("plotting row %d:\n", row);
//
//  printf("------------------------------\n");
//
//  plot_rows2d (7,24, temperature, row);

  // e 16

//  int temperature[7][24];
//
//  init_random (7, 24, temperature);
//
//  plot_matrix2d (7, 24, temperature);
//
//  plot_high_of_day (7, 24, temperature);

  // e 17

//  int array[10][10];
//
//  init_random (10, 10, array);
//
//  plot_matrix2d (10, 10, array);
//
//  printf ("sum: %3d\n", sum_two_dimensional_array (10, 10, array));
//
//  printf ("sum: %3d\n", sum_two_dimensional_array_new (10, 10, array));

  // e 18




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

  printf ("the board value is: %d\n", evaluate_position (b1));
  printf ("the board value is: %d\n", evaluate_position (b2));
  printf ("the board value is: %d\n", evaluate_position (b3));

  printf ("the board value is: %d\n", evaluate_position_new (b1));
  printf ("the board value is: %d\n", evaluate_position_new (b2));
  printf ("the board value is: %d\n", evaluate_position_new (b3));


  return 0;
}

int evaluate_position_new (char board[8][8])
{
  int sum_white = 0;
  int sum_black = 0;

  for (char *p = &board[0][0]; p <= &board[8 -1 ][8 -1]; p++)
  {
    if (isupper (*p))
    {
      sum_white += chess_char_to_value (*p);
    }
    else
    {
      sum_black += chess_char_to_value (*p);
    }
  }

  return sum_white - sum_black;
}

int chess_char_to_value (char ch)
{
  ch = (char) toupper (ch);

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

int sum_two_dimensional_array_new (int n, int m, const int a[n][m])
{
  int sum = 0;

  for (const int *p = &a[0][0]; p <= &a[n - 1][m - 1]; p++)
    sum += *p;

  return sum;
}

int sum_two_dimensional_array (int n, int m, const int a[n][m])
{
  int i, j, sum = 0;
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
      sum += a[i][j];
  return sum;
}

void plot_high_of_day (int n, int m, int a[n][m])
{
  for (int i = 0; i < n; i++)
  {
    printf ("day %d: %3d\n", i + 1, find_largest_new (&a[i][0], m));
  }
}

void plot_rows2d (int n, int m, int a[n][m], int row)
{
  for (int *p = a[row]; p < a[row] + m; p++)
    printf ("%3d", *p);
}

void plot_matrix (int n, int a[n])
{
  for (int *p = a; p < a + n; p++)
    printf ("%3d", *p);
}

void plot_matrix2d (int n, int m, int a[n][m])
{
  for (int *p = &a[0][0], i = 1; p <= &a[n - 1][m - 1]; p++, i++)
  {
    printf ("%3d", *p);
    if (i % m == 0)
      printf ("\n");
  }
}

void init_random (int n, int m, int a[n][m])
{
  srand (1);

  for (int *p = &a[0][0]; p <= &a[n - 1][m - 1]; p++)
  {
    *p = rand () % 15 + 20;
  }
}

void indent (int n, double a[n][n])
{
  int row, col;

  for (row = 0; row < N; row++)
    for (col = 0; col < N; col++)
      if (row == col)
        a[row][col] = 1.0f;
      else
        a[row][col] = 0.0f;
}
void indent_new (int n, double a[n][n])
{
  double *p;
  int cnt = N;

  for (p = &a[0][0]; p <= &a[n - 1][n - 1]; p++, cnt++)
  {
    if (cnt == N)
    {
      *p = 1.0f;
      cnt = -1;
    }
    else
      *p = 0.0f;
  }
}

void find_two_largest (const int *a, int n, int *largest, int *second_largest)
{
  *largest = INT_MIN;
  *second_largest = INT_MIN;

  for (const int *p = a; p < a + n; p++)
  {
    if (*p > *largest)
      *largest = *p;
    if (*p > *second_largest && *p < *largest)
      *second_largest = *p;
  }
}

int find_largest_new (const int a[], int n)
{
  int const *p = a;
  int max = *p;

  for (; p < a + n; p++)
    if (*p > max)
      max = *p;

  return max;
}

int find_largest (const int a[], int n)
{
  int i, max;

  max = a[0];
  for (i = 1; i < n; i++)
    if (a[i] > max)
      max = a[i];
  return max;
}

int *find_middle_new (int a[], int n)
{
  return a + n / 2;
}

int *find_middle (int a[], int n)
{
  return &a[n / 2];
}

void store_zeros (int a[], int n)
{
  for (int *p = a; p < a + n; p++)
    *p = 0;
}

double inner_product (const double *a, const double *b, int n)
{
  double inner_product = 0.0f;

  for (const double *p = a, *q = b; p < a + n; p++, q++)
    inner_product += *p * *q;

  return inner_product;
}

bool search (const int a[], int n, int key)
{
  for (const int *p = a; p < n + a; p++)
  {
    if (*p == key)
      return true;
  }
  return false;
}

int sum_array_new (const int a[], int n)
{
  int sum = 0;
  for (const int *p = a; p < a + n; p++)
    sum += *p;
  return sum;
}

int sum_array (const int a[], int n)
{
  int i, sum;
  sum = 0;
  for (i = 0; i < n; i++)
    sum += a[i];
  return sum;
}