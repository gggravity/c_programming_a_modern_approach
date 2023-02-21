#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 7

int main ()
{
  srand(time(NULL));

  int number = 1;
  int m[N][N] = {0};
  int x = rand() % N;
  int y = rand() % N;

  // insert first number
  m[x][y] = number++;

  // insert the rest of the numbers
  for (int i = 0; i < N * N ; i++)
  {
    int up = x - 1 >= 0 ? x - 1 : N - 1;
    int right = y + 1 < N ? y + 1 : 0;
    int down = x + 1 < N ? x + 1 : 0;

    if (m[up][right] == 0)
    {
      x = up;
      y = right;
      m[x][y] = number++;
    }
    else if (m[down][y] == 0)
    {
      x = down;
      m[x][y] = number++;
    }

  }

  // print matrix
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      printf ("%4d", m[i][j]);
    }
    printf ("\n");
  }

  return 0;
}
