#include <stdio.h>
#include <float.h>

//8 3 9 0 10
//3 5 17 1 1
//2 8 6 23 1
//15 7 3 2 9
//6 14 2 6 0

int main ()
{
  double sum_row = 0, highest_score = DBL_MIN, lowest_score = DBL_MAX, total_score = 0;
  int matrix[5][5] = {0};
  double scores[5] = {0};

  printf ("Enter row 1:");
  scanf ("%d %d %d %d %d", &matrix[0][0], &matrix[0][1], &matrix[0][2], &matrix[0][3], &matrix[0][4]);
  printf ("Enter row 2:");
  scanf ("%d %d %d %d %d", &matrix[1][0], &matrix[1][1], &matrix[1][2], &matrix[1][3], &matrix[1][4]);
  printf ("Enter row 3:");
  scanf ("%d %d %d %d %d", &matrix[2][0], &matrix[2][1], &matrix[2][2], &matrix[2][3], &matrix[2][4]);
  printf ("Enter row 4:");
  scanf ("%d %d %d %d %d", &matrix[3][0], &matrix[3][1], &matrix[3][2], &matrix[3][3], &matrix[3][4]);
  printf ("Enter row 5:");
  scanf ("%d %d %d %d %d", &matrix[4][0], &matrix[4][1], &matrix[4][2], &matrix[4][3], &matrix[4][4]);

  size_t rows = sizeof matrix / sizeof matrix[0];
  size_t columns = sizeof matrix[0] / sizeof matrix[0][0];

  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < columns; j++)
    {
      sum_row += matrix[i][j];
      if (matrix[i][j] > highest_score)
        highest_score = matrix[i][j];
      if (matrix[i][j] < lowest_score)
        lowest_score = matrix[i][j];
      total_score += matrix[i][j];
    }
    scores[i] = sum_row;
    sum_row = 0;
  }

  for (int i = 0; i < sizeof scores / sizeof scores[0]; i++)
  {
    printf ("Student %d scored on average: %.1f and %.1f in total\n", i + 1, scores[i] / (double) rows, scores[i]);
  }

  printf ("The highest score is: %.1f\n", highest_score);
  printf ("The lowest score is: %.1f\n", lowest_score);
  printf ("The average score is: %.1f", total_score / (double) (rows * columns));

  return 0;
}
