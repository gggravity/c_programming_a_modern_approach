#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 25
#define MAX_PARTS 100

struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
};

void read_parts (char *filename, struct part *inventory);

void write_parts (char *filename, struct part *inventory);

void merge_inventory (struct part *inventory_1, struct part *inventory_2, struct part *merged_inventory);

void print_inventory (struct part *inventory);

static int compare_parts (const void *p, const void *q);

static int get_length (struct part *inventory);

static int find_part (int number, struct part *inventory, int len);

int main (int argc, char *argv[])
{
  if (argc != 4)
  {
    printf ("usage: merge merged_file file_to_merge_1 file_to_merge_2");
    exit (EXIT_FAILURE);
  }

  struct part inventory[MAX_PARTS];
  struct part to_merge_1[MAX_PARTS];
  struct part to_merge_2[MAX_PARTS];

  read_parts (argv[2], to_merge_1);
  read_parts (argv[3], to_merge_2);

  merge_inventory (to_merge_1, to_merge_2, inventory);

//  write_parts (argv[1], inventory);

  print_inventory (inventory);

  return 0;
}

void print_inventory (struct part *inventory)
{
  for (struct part *p = inventory; p < inventory + MAX_PARTS && p->number != 0 && strlen (p->name) != 0; p++)
  {
    printf ("part number: %d\n", p->number);
    printf ("part name: %s\n", p->name);
    printf ("parts on hand: %d\n\n", p->on_hand);
  }
}

void merge_inventory (struct part *inventory_1, struct part *inventory_2, struct part *merged_inventory)
{

  int len1 = get_length (inventory_1);
  int len2 = get_length (inventory_2);
  int len_merged = 0;

  qsort (inventory_1, len1, sizeof (struct part), compare_parts);
  qsort (inventory_2, len2, sizeof (struct part), compare_parts);

  struct part *pm = merged_inventory;

  for (struct part *p = inventory_1; p < inventory_1 + len1; p++, pm++)
  {
    pm->number = p->number;
    strcpy (pm->name, p->name);
    pm->on_hand = p->on_hand;
    len_merged++;
  }

  for (struct part *p = inventory_2; p < inventory_2 + len2; p++, pm++)
  {
    int match = find_part (p->number, merged_inventory, len_merged);

    if (match == -1)
    {
      pm->number = p->number;
      strcpy (pm->name, p->name);
      pm->on_hand = p->on_hand;
      len_merged++;
    }
    else
    {
      if (strcmp (merged_inventory[match].name, p->name) != 0)
      {
        fprintf (stderr, "Parts name don't match: '%s' != '%s'\n", merged_inventory[match].name, p->name);
      }
      merged_inventory[match].on_hand += p->on_hand;
      pm--;
    }
  }
}

void read_parts (char *filename, struct part *inventory)
{
  FILE *fp = fopen (filename, "rb");

  if (fp == NULL)
  {
    fprintf (stderr, "Can't read from file: %s", filename);
    exit (EXIT_FAILURE);
  }
  fread (inventory, sizeof (struct part), MAX_PARTS, fp);
}

void write_parts (char *filename, struct part *inventory)
{
  FILE *fp = fopen (filename, "wb");

  if (fp == NULL)
  {
    fprintf (stderr, "Can't write to file: %s", filename);
    exit (EXIT_FAILURE);
  }
  fwrite (inventory, sizeof (struct part), MAX_PARTS, fp);
}

static int compare_parts (const void *p, const void *q)
{
  const struct part *p1 = p;
  const struct part *q1 = q;

  if (p1->number < q1->number)
    return -1;
  else if (p1->number == q1->number)
    return 0;
  else
    return 1;
}

static int get_length (struct part *inventory)
{
  int len = 0;

  for (int i = 0; i < MAX_PARTS; i++)
  {
    size_t name_len = strlen (inventory[i].name);
    if (inventory[i].number == 0 || name_len == 0)
      break;
    else
      len++;
  }

  return len;
}

static int find_part (int number, struct part *inventory, int len)
{
  int i;

  for (i = 0; i < len; i++)
  {
    if (inventory[i].number == number)
      return i;
  }
  return -1;
}