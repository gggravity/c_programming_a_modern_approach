#include <stdio.h>

//8 3 9 0 10
//3 5 17 1 1
//2 8 6 23 1
//15 7 3 2 9
//6 14 2 6 0

int main ()
{
  int sum_row = 0, sum_column = 0;
  int matrix[5][5];

  printf ("Enter row 1:");
  scanf("%d %d %d %d %d", &matrix[0][0], &matrix[0][1], &matrix[0][2], &matrix[0][3], &matrix[0][4]);
  printf ("Enter row 2:");
  scanf("%d %d %d %d %d", &matrix[1][0], &matrix[1][1], &matrix[1][2], &matrix[1][3], &matrix[1][4]);
  printf ("Enter row 3:");
  scanf("%d %d %d %d %d", &matrix[2][0], &matrix[2][1], &matrix[2][2], &matrix[2][3], &matrix[2][4]);
  printf ("Enter row 4:");
  scanf("%d %d %d %d %d", &matrix[3][0], &matrix[3][1], &matrix[3][2], &matrix[3][3], &matrix[3][4]);
  printf ("Enter row 5:");
  scanf("%d %d %d %d %d", &matrix[4][0], &matrix[4][1], &matrix[4][2], &matrix[4][3], &matrix[4][4]);

  size_t rows = sizeof matrix / sizeof matrix[0];
  size_t columns = sizeof  matrix[0] / sizeof matrix[0][0];

  printf ("Row totals: ");
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < columns; j++)
    {
      sum_row += matrix[i][j];
    }
    printf ("%4d", sum_row);
    sum_row = 0;
  }

  printf ("\nColumn totals: ");
  for (int i = 0; i < columns; i++)
  {
    for (int j = 0; j < rows; j++)
    {
      sum_column += matrix[j][i];
    }
    printf ("%4d", sum_column);
    sum_column = 0;
  }

  return 0;
}
