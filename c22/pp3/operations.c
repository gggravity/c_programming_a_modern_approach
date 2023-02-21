//
// Created by martin on 26/10/2021.
//

#include <stdio.h>
#include <limits.h>
#include <malloc.h>
#include <search.h>
#include "readline.h"
#include "operations.h"

int num_parts = 0;
int array_length = 1;

int find_part (struct part *inventory, int number)
{
  int i;

  for (i = 0; i < num_parts; i++)
  {
    if (inventory[i].number == number)
      return i;
  }
  return -1;
}

void insert (struct part *inventory)
{
  int part_number;

  if (num_parts == array_length)
  {
    realloc (inventory, sizeof (struct part) * array_length * 2);
    array_length *= 2;
    printf ("Resizing the array to size: %d\n", array_length);
  }

  printf ("Enter part number:");
  scanf ("%d", &part_number);

  if (find_part (inventory, part_number) >= 0)
  {
    printf ("Part already exists.\n");
    return;
  }

  inventory[num_parts].number = part_number;
  printf ("Enter part name:");
  read_line (inventory[num_parts].name, NAME_LEN);

  printf ("Enter quantity on hand:");
  scanf ("%d", &inventory[num_parts].on_hand);
  num_parts++;
}

void search (struct part *inventory)
{
  int i, number;

  printf ("Enter part number:");
  scanf ("%d", &number);

  i = find_part (inventory, number);
  if (i >= 0)
  {
    printf ("Part name: %s\n", inventory[i].name);
    printf ("Quantity on hand: %d\n", inventory[i].on_hand);
  }
  else
  {
    printf ("Part not found.\n");
  }
}

void update (struct part *inventory)
{
  int i, number, change;

  printf ("Enter part number:");
  scanf ("%d", &number);
  i = find_part (inventory, number);
  if (i >= 0)
  {
    printf ("Enter change in quantity on hand:");
    scanf ("%d", &change);
    inventory[i].on_hand += change;
  }
  else
  {
    printf ("Part not found.\n");
  }
}

void print (struct part *inventory)
{
  int i;

  qsort (inventory, array_length, sizeof (struct part), compare_parts);

  printf ("Part Number       Part Name                Quantity on Hand\n");
  for (i = 0; i < num_parts; i++)
    printf ("%11d       %-25s%-11d\n", inventory[i].number, inventory[i].name, inventory[i].on_hand);
}

int compare_parts (const void *p, const void *q)
{
  const struct part *ps = p;
  const struct part *qs = q;

  if (ps->number < qs->number)
    return -1;
  else if (ps->number == qs->number)
    return 0;
  else
    return 1;

}

void erase (struct part *inventory)
{
  int i, number;

  printf ("Enter part number:");
  scanf ("%d", &number);

  i = find_part (inventory, number);

  if (i >= 0)
  {
    printf ("the part have id: %d | total parts: %d", i, num_parts);

    for (; i < num_parts - 1; i++)
    {
      inventory[i] = inventory[i + 1];
    }

    num_parts--;
  }
  else
  {
    printf ("Part not found.\n");
  }
}







