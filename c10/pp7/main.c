#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_DIGITS 10
#define N 7

void plot_numbers (int segments[][N]);
void reset_segments (int segments[][N]);
void insert_numbers (int segments[][N], char text[]);
void clean_text(char old_text[], char new_text[]);

int main ()
{
  char text[] = "491-9014123";
  char new_text[sizeof text/sizeof text[0]];

  clean_text (text, new_text);

  int segments[MAX_DIGITS][N] = {};

  reset_segments (segments);

  insert_numbers (segments, new_text);

  plot_numbers (segments);

  return 0;
}

void insert_numbers (int segments[][N], char text[])
{
  int number;

  int zero[] = {1, 1, 1, 1, 1, 1, 0};
  int one[] = {0, 1, 1, 0, 0, 0, 0};
  int two[] = {1, 1, 0, 1, 1, 0, 1};
  int three[] = {1, 1, 1, 1, 0, 0, 1};
  int four[] = {0, 1, 1, 0, 0, 1, 1};
  int five[] = {1, 0, 1, 1, 0, 1, 1};
  int six[] = {1, 0, 1, 1, 1, 1, 1};
  int seven[] = {1, 1, 1, 0, 0, 0, 0};
  int eight[] = {1, 1, 1, 1, 1, 1, 1};
  int nine[] = {1, 1, 1, 1, 0, 1, 1};

  for (int i = 0; text[i] != '\0'; i++)
  {
    number = (int) text[i] - '0';

    switch (number)
    {
    case 0:
      for (int j = 0; j <= N; j++)
        segments[i][j] = zero[j];
      break;
    case 1:
      for (int j = 0; j <= N; j++)
        segments[i][j] = one[j];
      break;
    case 2:
      for (int j = 0; j <= N; j++)
        segments[i][j] = two[j];
      break;
    case 3:
      for (int j = 0; j <= N; j++)
        segments[i][j] = three[j];
      break;
    case 4:
      for (int j = 0; j <= N; j++)
        segments[i][j] = four[j];
      break;
    case 5:
      for (int j = 0; j <= N; j++)
        segments[i][j] = five[j];
      break;
    case 6:
      for (int j = 0; j <= N; j++)
        segments[i][j] = six[j];
      break;
    case 7:
      for (int j = 0; j <= N; j++)
        segments[i][j] = seven[j];
      break;
    case 8:
      for (int j = 0; j <= N; j++)
        segments[i][j] = eight[j];
      break;
    case 9:
      for (int j = 0; j <= N; j++)
        segments[i][j] = nine[j];
      break;
    default:
      break;
    }
  }

}

void reset_segments (int segments[][N])
{
  for (int i = 0; i < MAX_DIGITS; i++)
  {
    for (int j = 0; j < N; j++)
      segments[i][j] = 0;
  }
}

void plot_numbers (int segments[][N])
{
  for (int i = 0; i < MAX_DIGITS; i++)
  {
    if (segments[i][0] == true)
      printf ("  --  ");
    else
      printf ("      ");
  }

  printf ("\n");

  for (int i = 0; i < MAX_DIGITS; i++)
  {
    if (segments[i][5] == true && segments[i][1] == true)
      printf (" |  | ");
    else if (segments[i][5])
      printf (" |    ");
    else if (segments[i][1] == true)
      printf ("    | ");
  }

  printf ("\n");

  for (int i = 0; i < MAX_DIGITS; i++)
  {
    if (segments[i][6] == true)
      printf ("  --  ");
    else
      printf ("      ");
  }

  printf ("\n");

  for (int i = 0; i < MAX_DIGITS; i++)
  {
    if (segments[i][4] == true && segments[i][2] == true)
      printf (" |  | ");
    else if (segments[i][4])
      printf (" |    ");
    else if (segments[i][2] == true)
      printf ("    | ");
  }

  printf ("\n");

  for (int i = 0; i < MAX_DIGITS; i++)
  {
    if (segments[i][3] == true)
      printf ("  --  ");
    else
      printf ("      ");
  }
}

void clean_text(char old_text[], char new_text[])
{
  int cnt = 0;
  for (int i = 0; old_text[i] != '\0'; i++)
  {
    if (isdigit (old_text[i]))
      new_text[cnt++] = old_text[i];
  }
}