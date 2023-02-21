#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 2s 5s 4s 3s 6s

#define NUM_CARDS 5

void read_cards (int hand[][2]);
void
analyze_hand (int hand[][2], bool *straight, bool *flush, bool *royal, bool *four, bool *three, int *pairs, bool *ace_low);
void
print_result (const bool *royal, const bool *straight, const bool *flush, const bool *four, const bool *three, const int *pairs, const bool *ace_low);
void check_for_flush (int hand[][2], bool *flush);
void check_for_kinds_and_pairs (int hand[][2], bool *four, bool *three, int *pairs);
int count_ranks (int hand[][2], int x);
void check_for_straight (int hand[][2], bool *straight);
void check_for_ace_low (int hand[][2], bool *ace_low);
bool duplicated_card (int hand[][2], int rank, int suit);
void check_for_royal_flush (int hand[][2], bool *royal);

int main (void)
{
  bool straight, flush, four, three, royal, ace_low;
  int pairs;

  int hand[5][2];

  for (;;) // endless loop
  {
    read_cards (hand);
    analyze_hand (hand, &straight, &flush, &royal, &four, &three, &pairs, &ace_low);
    print_result (&royal, &straight, &flush, &four, &three, &pairs, &ace_low);
  }

  return 0;
}

void read_cards (int hand[][2])
{
  char ch, rank_ch, suit_ch;
  int rank, suit;
  bool bad_card;
  int cards_read = 0;

  for (int i = 0; i < NUM_CARDS; i++)
  {
    hand[i][0] = 0;
    hand[i][1] = 0;
  }

  while (cards_read < NUM_CARDS)
  {
    bad_card = false;
    printf ("Enter a card:");
    rank_ch = (char)getchar ();

    switch (rank_ch)
    {
    case '0':
      exit (EXIT_FAILURE);
    case '2':
      rank = 0;
      break;
    case '3':
      rank = 1;
      break;
    case '4':
      rank = 2;
      break;
    case '5':
      rank = 3;
      break;
    case '6':
      rank = 4;
      break;
    case '7':
      rank = 5;
      break;
    case '8':
      rank = 6;
      break;
    case '9':
      rank = 7;
      break;
    case 't':
    case 'Y':
      rank = 8;
      break;
    case 'j':
    case 'J':
      rank = 9;
      break;
    case 'q':
    case 'Q':
      rank = 10;
      break;
    case 'k':
    case 'K':
      rank = 11;
      break;
    case 'a':
    case 'A':
      rank = 12;
      break;
    default:
      bad_card = true;
    }

    suit_ch = (char)getchar ();

    switch (suit_ch)
    {
    case 'c':
    case 'C':
      suit = 0;
      break;
    case 'd':
    case 'D':
      suit = 1;
      break;
    case 'h':
    case 'H':
      suit = 2;
      break;
    case 's':
    case 'S':
      suit = 3;
      break;
    default:
      bad_card = true;
    }

    while ((ch = (char)getchar ()) != '\n')
      if (ch != ' ')
        bad_card = true;

    if (bad_card)
      printf ("Bad card, ignored.\n");
    else if (duplicated_card (hand, rank, suit))
      printf ("Duplicate card; ignored.\n");
    else
    {
      hand[cards_read][0] = rank;
      hand[cards_read][1] = suit;
      cards_read++;

      printf ("The hand is: ");
      for (int i = 0; i < NUM_CARDS && i < cards_read; i++)
      {
        printf ("%d %d, ", hand[i][0], hand[i][1]);
      }
      printf ("\n");

    }
  }
}

bool duplicated_card (int hand[][2], int rank, int suit)
{
  for (int i = 0; i < NUM_CARDS; i++)
  {
    if (hand[i][0] == rank && hand[i][1] == suit)
      return true;
  }
  return false;
}

void
analyze_hand (int hand[][2], bool *straight, bool *flush, bool *royal, bool *four, bool *three, int *pairs, bool *ace_low)
{

  check_for_flush (hand, flush);

  check_for_straight (hand, straight);

  check_for_ace_low (hand, ace_low);

  check_for_kinds_and_pairs (hand, four, three, pairs);

  if (straight && flush)
    check_for_royal_flush (hand, royal);

}

void check_for_royal_flush (int hand[][2], bool *royal)
{
  *royal = false;
  int min = INT_MAX;

  for (int i = 0; i < NUM_CARDS; i++)
  {
    if (hand[i][0] < min)
      min = hand[i][0];
  }
  if (min == 8) // rank of the lowest value in royal flush (10).
    *royal = true;
}

void
print_result (const bool *royal, const bool *straight, const bool *flush, const bool *four, const bool *three, const int *pairs, const bool *ace_low)
{
  if (*royal)
    printf ("Royal straight flush");
  else if (*straight && *flush && !(*royal))
    printf ("Straight flush");
  else if (*four)
    printf ("Four of a kind");
  else if (*three && *pairs == 1)
    printf ("Full house");
  else if (*flush)
    printf ("Flush");
  else if (*straight)
    printf ("Straight");
  else if (*ace_low)
    printf ("Straight (ace low)");
  else if (*three)
    printf ("Three of a kind");
  else if (*pairs == 2)
    printf ("Two pairs");
  else if (*pairs == 1)
    printf ("One pair");
  else
    printf ("High card");

  printf ("\n\n");

}

void check_for_flush (int hand[][2], bool *flush)
{
  *flush = true;
  bool first_run = true;
  int last;

  for (int i = 0; i < NUM_CARDS; i++)
  {
    if (first_run)
    {
      last = hand[i][1];
      first_run = false;
    }
    if (hand[i][1] != last)
    {
      *flush = false;
      return;
    }
  }
}

void check_for_kinds_and_pairs (int hand[][2], bool *four, bool *three, int *pairs)
{
  *four = false;
  *three = false;
  *pairs = 0;
  for (int i = 0; i < NUM_CARDS; i++)
  {
    int count = count_ranks (hand, hand[i][0]);
    if (count == 4)
      *four = true;
    else if (count == 3)
      *three = true;
    else if (count == 2)
      (*pairs)++;
  }
}

int count_ranks (int hand[][2], int x)
{
  int res = 0;
  for (int i = 0; i < NUM_CARDS; i++)
    if (x == hand[i][0])
      res++;
  return res;
}

void check_for_straight (int hand[][2], bool *straight)
{
  *straight = false;

  int min = INT_MAX, cnt = 0;

  for (int i = 0; i < NUM_CARDS; i++)
  {
    if (hand[i][0] < min)
      min = hand[i][0];
  }

  for (int i = 0; i < NUM_CARDS; i++)
  {
    if (hand[i][0] >= min && hand[i][0] < min + NUM_CARDS)
      cnt++;
  }

  if (cnt == NUM_CARDS)
    *straight = true;
}

void check_for_ace_low (int hand[][2], bool *ace_low)
{
  *ace_low = false;
  bool ace = false;

  int min = INT_MAX, cnt = 0;

  for (int i = 0; i < NUM_CARDS; i++)
  {
    if (hand[i][0] < min)
      min = hand[i][0];
    if (hand[i][0] == 12)
      ace = true;
  }

  for (int i = 0; i < NUM_CARDS; i++)
  {
    if (hand[i][0] >= min && hand[i][0] < min + NUM_CARDS)
      cnt++;
  }

  if (cnt == NUM_CARDS - 1 && ace)
    *ace_low = true;
}