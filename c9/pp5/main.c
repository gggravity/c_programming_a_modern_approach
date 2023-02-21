#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int s = 7;

void create_magic_square(int n, char magic_square[n][n]);
void print_magic_square(int n, char magic_square[n][n]);
void init_magic_square(int n, char magic_square[n][n]);

int main ()
{

  char m[s][s];

  create_magic_square (s, m);
  print_magic_square (s, m);

  return 0;
}

void create_magic_square(int n, char magic_square[n][n])
{
  srand(time(NULL));

  int number = 1;

  int x = rand() % n;
  int y = rand() % n;

  // variable length array can't be initialized
  init_magic_square (n, magic_square);

  // insert first number
  magic_square[x][y] = (char)number++;

  // insert the rest of the numbers
  for (int i = 0; i < n * n ; i++)
  {
    int up = x - 1 >= 0 ? x - 1 : n - 1;
    int right = y + 1 < n ? y + 1 : 0;
    int down = x + 1 < n? x + 1 : 0;

    if (magic_square[up][right] == 0)
    {
      x = up;
      y = right;
      magic_square[x][y] = (char)number++;
    }
    else if (magic_square[down][y] == 0)
    {
      x = down;
      magic_square[x][y] = (char)number++;
    }
  }
}

void print_magic_square(int n, char magic_square[n][n])
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf ("%4d", magic_square[i][j]);
    }
    printf ("\n");
  }
}

void init_magic_square(int n, char magic_square[n][n])
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      magic_square[i][j] = 0;
    }
  }
}