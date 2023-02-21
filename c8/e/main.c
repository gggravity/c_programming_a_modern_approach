#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int main ()
{

//  int a[] = {1, 2, 3};
//
//  for (char i = 0; i < sizeof (a) / sizeof (a[0]); i++)
//  {
//    printf ("Hello, World! %d\n", a[i]);
//  }
//
//  bool weekend[7] = {true, false, false, false, false, false, true};
//  bool weekend[7] = {[0] = true, [6] = true};
//
//  for (int i = 0; i < sizeof (weekend) / sizeof (weekend[0]); i++)
//  {
//    printf ("%s ", weekend[i] ? "true" : "false");
//  }

//  int fib_numbers[40] = {0, 1};
//
//  for (int i = 2; i < 2 + sizeof (fib_numbers) / sizeof (fib_numbers[0]); i++)
//  {
//    fib_numbers[i] = fib_numbers[i - 1] + fib_numbers[i - 2];
//    printf ("%2d %10d\n", i - 2, fib_numbers[i - 2]);
//  }

//  const int segments[10][7] = {
//      {1, 1, 1, 1, 1, 1, 0},
//      {0, 1, 1, 0, 0, 0, 0},
//      {1, 1, 0, 1, 1, 0, 1},
//      {1, 1, 1, 1, 0, 0, 1},
//      {0, 1, 1, 0, 0, 1, 1},
//      {1, 0, 1, 1, 0, 1, 1},
//      {1, 0, 1, 1, 1, 1, 1},
//      {1, 1, 1, 0, 0, 0, 0},
//      {1, 1, 1, 1, 1, 1, 1},
//      {1, 1, 1, 1, 0, 1, 1}
//  };
//  const int segments[10][7] = {
//      {1, 1, 1, 1, 1, 1, 0},
//      {[1] = 1, [2] = 1},
//      {1, 1, 0, 1, 1, 0, 1},
//      {1, 1, 1, 1, 0, 0, 1},
//      {0, 1, 1, 0, 0, 1, 1},
//      {1, 0, 1, 1, 0, 1, 1},
//      {1, 0, 1, 1, 1, 1, 1},
//      {1, 1, 1, 0, 0, 0, 0},
//      {1, 1, 1, 1, 1, 1, 1},
//      {1, 1, 1, 1, 0, 1, 1}
//  };
//  for (int i = 0; i < 10; i++)
//  {
//    if (segments[i][0] == true)
//      printf ("  --  ");
//    else
//      printf ("      ");
//  }
//
//  printf ("\n");
//
//  for (int i = 0; i < 10; i++)
//  {
//    if (segments[i][5] == true && segments[i][1] == true)
//      printf (" |  | ");
//    else if (segments[i][5])
//      printf (" |    ");
//    else if (segments[i][1] == true)
//      printf ("    | ");
//  }
//
//  printf ("\n");
//
//  for (int i = 0; i < 10; i++)
//  {
//    if (segments[i][6] == true)
//      printf ("  --  ");
//    else
//      printf ("      ");
//  }
//
//  printf ("\n");
//
//  for (int i = 0; i < 10; i++)
//  {
//    if (segments[i][4] == true && segments[i][2] == true)
//      printf (" |  | ");
//    else if (segments[i][4])
//      printf (" |    ");
//    else if (segments[i][2] == true)
//      printf ("    | ");
//  }
//
//  printf ("\n");
//
//  for (int i = 0; i < 10; i++)
//  {
//    if (segments[i][3] == true)
//      printf ("  --  ");
//    else
//      printf ("      ");
//  }

//  double avg_hour = 0;
//  double avg_day = 0;
//  double avg = 0;
//
//  printf ("    ");
//  for (int i = 1; i <= 30; i++)
//  {
//    printf ("d%02d ", i);
//  }
//  printf (" avg\n");
//
//  int temperature_readings[60][30] = {0};
//  size_t rows = sizeof (temperature_readings) / sizeof (temperature_readings[0]);
//  size_t columns = sizeof (temperature_readings[0]) / sizeof (temperature_readings[0][0]);
//
//  srand (time (NULL));
//
//  for (int i = 0; i < rows; i++)
//  {
//    for (int j = 0; j < columns; j++)
//      temperature_readings[i][j] = rand () % 40 - 10;
//  }
//
//  for (int i = 0; i < rows; i++)
//  {
//    printf ("h%02d ", i + 1);
//    for (int j = 0; j < columns; j++)
//    {
//      printf ("%3d ", temperature_readings[i][j]);
//      avg_hour += temperature_readings[i][j];
//      avg += temperature_readings[i][j];
//    }
//    printf (" %.2lf\n", avg_hour / 30);
//    avg_hour = .0f;
//  }
//
//  printf ("avg ");
//  for (int j = 0; j < columns; j++)
//  {
//    for (int i = 0; i < rows; i++)
//    {
//      avg_day += temperature_readings[i][j];
//    }
//    printf ("%3.f ", avg_day / 60);
//    avg_day = 0.0f;
//  }
//  printf (" %.2f", avg / (30 * 60));

//  char chess_board[8][8] =
//      {
//          {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
//          {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
//          {' ', '-', ' ', '-', ' ', '-', ' ', '-'},
//          {'-', ' ', '-', ' ', '-', ' ', '-', ' '},
//          {' ', '-', ' ', '-', ' ', '-', ' ', '-'},
//          {'-', ' ', '-', ' ', '-', ' ', '-', ' '},
//          {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
//          {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
//      };
//
//  size_t rows = sizeof (chess_board) / sizeof (chess_board[0]);
//  size_t columns = sizeof (chess_board[0]) / sizeof (chess_board[0][0]);
//
//  for (int i = 0; i < rows; i++)
//  {
//    for (int j = 0; j < columns; j++)
//    {
//      printf("%c  ", chess_board[i][j]);
//    }
//    printf ("\n");
//  }

  char checker_board[8][8];

  size_t rows = sizeof checker_board / sizeof checker_board[0];
  size_t columns = sizeof checker_board[0] / sizeof checker_board[0][0];

  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < columns; j++)
    {
      if ((i + j) % 2 == 0)
        checker_board[i][j] = 'B';
      else
        checker_board[i][j] = 'R';

      printf (" %c ", checker_board[i][j]);
    }
    printf ("\n");
  }

  return 0;
}
