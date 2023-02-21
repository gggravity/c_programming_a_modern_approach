#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 2s 5s 4s 3s 6s

#define NUM_CARDS 5

bool straight, flush, four, three;
int pairs;

void read_cards (int hand[][2]);
void analyze_hand (int hand[][2]);
void print_result (void);
void check_for_flush (int hand[][2]);
void check_for_kinds_and_pairs (int hand[][2]);
int count_ranks (int hand[][2], int x);
void check_for_straight(int hand[][2]);
bool duplicated_card (int hand[][2], int rank, int suit);

int main (void)
{
  int hand[5][2];

  for (;;) // endless loop
  {
    read_cards (hand);
    analyze_hand (hand);
    print_result ();
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
    rank_ch = getchar ();

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

    suit_ch = getchar ();

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

    while ((ch = getchar ()) != '\n')
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

void analyze_hand (int hand[][2])
{

  check_for_flush (hand);

  check_for_straight (hand);

  check_for_kinds_and_pairs (hand);

}

void print_result (void)
{
  if (straight && flush)
    printf ("Straight flush");
  else if (four)
    printf ("Four of a kind");
  else if (three && pairs == 1)
    printf ("Full house");
  else if (flush)
    printf ("Flush");
  else if (straight)
    printf ("Straight");
  else if (three)
    printf ("Three");
  else if (pairs == 2)
    printf ("Two pairs");
  else if (pairs == 1)
    printf ("One pair");
  else
    printf ("High card");

  printf ("\n\n");

}

void check_for_flush (int hand[][2])
{
  flush = true;
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
      flush = false;
      return;
    }
  }
}

void check_for_kinds_and_pairs (int hand[][2])
{
  four = false;
  three = false;
  pairs = 0;
  for (int i = 0; i < NUM_CARDS; i++)
  {
    int count = count_ranks (hand, hand[i][0]);
    if (count == 4)
      four = true;
    else if (count == 3)
      three = true;
    else if (count == 2)
      pairs++;
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

void check_for_straight(int hand[][2])
{
  straight = false;

  int min = INT_MIN, cnt = 0;

  for (int i = 0; i < NUM_CARDS; i++)
  {
    if (hand[i][0] < min)
      min = hand[i][0];
  }

  for (int i = 0; i < NUM_CARDS; i++)
  {
    if (hand[i][0] > min && hand[i][0] < NUM_CARDS)
      cnt++;
  }

  if (cnt == NUM_CARDS)
    straight = true;

//
//  rank = 0;
//  while (num_in_rank[rank] == 0)
//    rank++;
//  for (; rank < NUM_RANKS && num_in_rank[rank] > 0; rank++)
//    num_consec++;
//  if (num_consec == NUM_CARDS)
//  {
//    straight = true;
//    return;
//  }
}