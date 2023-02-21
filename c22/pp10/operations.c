//
// Created by martin on 26/10/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include "readline.h"
#include "operations.h"

int num_parts = 0;
int array_length = 1;

struct part *inventory = NULL;

struct part *find_part (int number)
{
  struct part *p;

  for (p = inventory; p != NULL && number > p->number; p = p->next);

  if (p != NULL && number == p->number)
    return p;
  return NULL;
}

void insert (void)
{
  struct part *cur, *prev, *new_node;

  new_node = malloc (sizeof (struct part));

  if (new_node == NULL)
  {
    printf ("Database is full; can't add more parts.\n");
    return;
  }

  printf ("Enter part number:");
  scanf ("%d", &new_node->number);

  for (cur = inventory, prev = NULL;
       cur != NULL && new_node->number > cur->number;
       prev = cur, cur = cur->next);

  if (cur != NULL && new_node->number == cur->number)
  {
    printf ("Part already exists.\n");
    free (new_node);
    return;
  }

  printf ("Enter part name:");
  read_line (new_node->name, NAME_LEN);

  printf ("Enter quantity on hand:");
  scanf ("%d", &new_node->on_hand);

  new_node->next = cur;
  if (prev == NULL)
    inventory = new_node;
  else
    prev->next = new_node;
  num_parts++;
}

void search (void)
{
  int number;
  struct part *p;

  printf ("Enter part number:");
  scanf ("%d", &number);

  p = find_part (number);

  if (p != NULL)
  {
    printf ("Part name: %s\n", p->name);
    printf ("Quantity on hand: %d\n", p->on_hand);
  }
  else
  {
    printf ("Part not found.\n");
  }
}

void update (void)
{
  int number, change;
  struct part *p;

  printf ("Enter part number:");
  scanf ("%d", &number);

  p = find_part (number);

  if (p != NULL)
  {
    printf ("Enter change in quantity on hand:");
    scanf ("%d", &change);
    p->on_hand += change;
  }
  else
  {
    printf ("Part not found.\n");
  }
}

void print (void)
{
  struct part *p;

  printf ("Part Number       Part Name                Quantity on Hand\n");
  for (p = inventory; p != NULL; p = p->next)
    printf ("%11d       %-25s%-11d\n", p->number, p->name, p->on_hand);
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

void dump_database (void)
{
  char filename[100];
  fprintf (stdout, "Enter name of output file:");
  scanf ("%s", filename);

  FILE *fp;
  fp = fopen (filename, "wb");

  if (fp == NULL)
  {
    fprintf (stderr, "Error writing to database\n");
    exit (EXIT_FAILURE);
  }

  fwrite (&num_parts, sizeof (int), 1, fp);
  printf("Wrote %d parts.\n", num_parts);

  struct part *p;

  for (p = inventory; p != NULL; p = p->next)
  {
    fwrite (&p->number, sizeof (int), 1, fp);
    fwrite (&p->name, sizeof (char), NAME_LEN + 1, fp);
    fwrite (&p->on_hand, sizeof (int), 1, fp);
  }

  fclose (fp);
}

void read_database (void)
{
  char filename[100];
  fprintf (stdout, "Enter name of input file:");
  scanf ("%s", filename);

  FILE *fp;
  fp = fopen (filename, "rb");

  if (fp == NULL)
  {
    fprintf (stderr, "Error reading from database\n");
    exit (EXIT_FAILURE);
  }

  fread (&num_parts, sizeof (int), 1, fp);

  printf ("%d\n", num_parts);

  for (int i = 0; i < num_parts; i++)
  {

    struct part *new_node;

    new_node = malloc (sizeof (struct part));

    if (new_node == NULL)
    {
      printf ("Database is full; can't add more parts.\n");
      return;
    }

    fread (&new_node->number, sizeof (int), 1, fp);
    fread (&new_node->name, sizeof (char), NAME_LEN + 1, fp);
    fread (&new_node->on_hand, sizeof (int), 1, fp);

    new_node->next = inventory;
    inventory = new_node;

//    if (inventory == NULL)
//    {
//      printf("creating root node\n");
//      new_node->next = inventory;
//    }
//    else
//    {
//      printf("inserting new node\n");
//      new_node->next = inventory;
//      inventory = new_node;
//    }
  }


  fclose (fp);

}







