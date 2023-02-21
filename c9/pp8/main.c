#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

int roll_dice (void);
bool play_game (void);

int main ()
{
  srand ((unsigned)time(NULL));

  play_game ();

  return 0;
}

int roll_dice (void)
{
  int dice1 = rand () % 6;
  int dice2 = rand () % 6;

  return dice1 + dice2;
}

bool play_game (void)
{
  bool first_round = true;

  while (true)
  {
    int roll = roll_dice ();
    if (first_round && roll == 7 || roll == 11)
    {
      printf ("You won on first round. %d equal 7 or 11\n", roll);
      break;
    }
    else if (first_round && roll == 2 || roll == 3 || roll == 12)
    {
      printf ("You lost on first round, %d equal 2, 3 or 12.\n");
      break;
    }
    else
    {
      first_round = false;

      printf ("You rolled: %d\n", roll);

      int point = roll;

      printf ("The point is: %d\n", point);

      roll = roll_dice ();

      if (point == roll)
      {
        printf ("You won. point(%d) eq roll(%d)\n", point, roll);
        break;
      }
      else if (roll == 7)
      {
        printf ("You lose. roll(%d) eq 7\n", roll);
        break;
      }
      else
      {
        printf ("the point(%d) is not equal the role(%d)\n", point, roll);
      }
    }

  }
  return true;
}