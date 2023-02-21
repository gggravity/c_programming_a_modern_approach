#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define N 30

int main ()
{
  char m[N][N];
  bool stuck = false;
  char letter = 'A';

  size_t rows = sizeof m / sizeof m[0];
  size_t columns = sizeof m[0] / sizeof m[0][0];

  srand (time (NULL));

  int x = rand () % N;
  int y = rand () % N;

  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < columns; j++)
    {
      m[i][j] = '.';
    }
  }
  m[x][y] = letter++;

  while (letter <= 'Z')
  {
    int moves = 0;
    bool can_move_up = false;
    bool can_move_down = false;
    bool can_move_left = false;
    bool can_move_right = false;

    if (x - 1 >= 0 && m[x - 1][y] == '.')
    {
      can_move_up = true;
      moves++;
    }
    if (x + 1 <= N - 1 && m[x + 1][y] == '.')
    {
      can_move_down = true;
      moves++;
    }
    if (y - 1 >= 0 && m[x][y - 1] == '.')
    {
      can_move_left = true;
      moves++;
    }
    if (y + 1 <= N - 1 && m[x][y + 1] == '.')
    {
      can_move_right = true;
      moves++;
    }

    if (moves == 0)
    {
      stuck = true;
      break;
    }

    int r = rand () % 4;

    if (r == 0 && can_move_up)
    {
      m[x - 1][y] = letter++;
      x--;
    }

    else if (r == 1 && can_move_down)
    {
      m[x + 1][y] = letter++;
      x++;
    }

    else if (r == 2 && can_move_left)
    {
      m[x][y - 1] = letter++;
      y--;
    }

    else if (r == 3 && can_move_right)
    {
      m[x][y + 1] = letter++;
      y++;
    }
  }

  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < columns; j++)
    {
      printf ("%c  ", m[i][j]);
    }
    printf ("\n");
  }
  if (stuck)
    printf ("stuck, breaking at letter %c with coordinates (%d, %d)", letter - 1, x, y);
  else
    printf ("finished successful");

  return 0;
}
