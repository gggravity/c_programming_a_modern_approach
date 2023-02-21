#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define N 20

void print_array (const char walk[N][N]);

void
check_moves (const char m[N][N], int x, int y, int *moves, bool *can_move_up, bool *can_move_down, bool *can_move_left, bool *can_move_right);

void
move (char m[N][N], bool can_move_up, bool can_move_down, bool can_move_left, bool can_move_right, char *letter, int *x, int *y);

void generate_empty_board (char m[N][N]);

void generate_random_walk (char m[N][N], bool *stuck, char *letter, int *x, int *y);

int main ()
{
  char m[N][N];
  bool stuck = false;
  char letter = 'A';

  generate_empty_board (m);

  srand (time (NULL));

  int x = rand () % N;
  int y = rand () % N;

  generate_random_walk (m, &stuck, &letter, &x, &y);

  print_array (m);

  if (stuck)
    printf ("stuck, breaking at letter %c with coordinates (%d, %d)", letter - 1, x, y);
  else
    printf ("finished successful");

  return 0;
}

void generate_random_walk (char m[N][N], bool *stuck, char *letter, int *x, int *y)
{
  m[(*x)][(*y)] = (*letter)++;

  while ((*letter) <= 'Z')
  {
    int moves = 0;
    bool can_move_up = false;
    bool can_move_down = false;
    bool can_move_left = false;
    bool can_move_right = false;

    check_moves (m, (*x), (*y), &moves, &can_move_up, &can_move_down, &can_move_left, &can_move_right);

    if (moves == 0)
    {
      *stuck = true;
      break;
    }

    move (m, can_move_up, can_move_down, can_move_left, can_move_right, letter, x, y);

  }
}

void generate_empty_board (char m[N][N])
{
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      m[i][j] = '.';
    }
  }
}

void
move (char m[N][N], bool can_move_up, bool can_move_down, bool can_move_left, bool can_move_right, char *letter, int *x, int *y)
{
  int r = rand () % 4;

  if (r == 0 && can_move_up)
  {
    m[(*x) - 1][(*y)] = (*letter)++;
    (*x)--;
  }

  else if (r == 1 && can_move_down)
  {
    m[(*x) + 1][(*y)] = (*letter)++;
    (*x)++;
  }

  else if (r == 2 && can_move_left)
  {
    m[(*x)][(*y) - 1] = (*letter)++;
    (*y)--;
  }

  else if (r == 3 && can_move_right)
  {
    m[(*x)][(*y) + 1] = (*letter)++;
    (*y)++;
  }
}

void
check_moves (const char m[N][N], int x, int y, int *moves, bool *can_move_up, bool *can_move_down, bool *can_move_left, bool *can_move_right)
{
  if (x - 1 >= 0 && m[x - 1][y] == '.')
  {
    *can_move_up = true;
    (*moves)++;
  }
  if (x + 1 <= N - 1 && m[x + 1][y] == '.')
  {
    *can_move_down = true;
    (*moves)++;
  }
  if (y - 1 >= 0 && m[x][y - 1] == '.')
  {
    *can_move_left = true;
    (*moves)++;
  }
  if (y + 1 <= N - 1 && m[x][y + 1] == '.')
  {
    *can_move_right = true;
    (*moves)++;
  }
}

void print_array (const char walk[N][N])
{
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      printf ("%c  ", walk[i][j]);
    }
    printf ("\n");
  }
}

