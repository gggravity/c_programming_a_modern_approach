//
// Created by martin on 24/10/2021.
//

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>
#include "line.h"

#define MAX_LINE_LEN 50

int line_len = 0;
int num_words = 0;

void clear_line (struct node **line)
{
//  line[0] = '\0';
  *line = NULL;
  line_len = 0;
  num_words = 0;
}

void add_word (char *word, struct node **line)
{

  struct node *new_node;

  new_node = malloc (sizeof (struct node));

  if (new_node == NULL)
  {
    printf ("Out of memory error.\n");
  }

  strcpy (new_node->word, word);
  new_node->next = NULL;

  if (*line == NULL)
  {
    *line = new_node;
  }
  else
  {
    struct node *last_node = *line;

    while (last_node->next != NULL)
    {
      last_node = last_node->next;
    }

    last_node->next = new_node;
  }

  num_words++;
  line_len += (int) strlen (new_node->word) + 1;

}

int space_remaining (void)
{
//  printf("space_remaining () %d\n", MAX_LINE_LEN - line_len);

  return MAX_LINE_LEN - line_len;
}

void write_line (struct node *line)
{
  int extra_spaces = MAX_LINE_LEN - line_len;
  int spaces_to_insert;

  struct node *p = line;
  bool word = true;

  for (int i = 0; i < line_len && p != NULL; i++)
  {
    if (word)
    {
      printf ("%s", p->word);
      p = p->next;
      word = false;
    }
    else
    {
      spaces_to_insert = extra_spaces / (num_words);
      for (int j = 1; j <= spaces_to_insert + 1; j++)
        printf (" ");
      extra_spaces -= spaces_to_insert;
      num_words--;
      word = true;
    }
  }
  printf ("\n");
}

void flush_line (void)
{
//  printf("entering flush_line\n");
//  if (line_len > 0)
//    puts (line->word);
}

void print_list (struct node *line)
{
  struct node *p;

  for (p = line; p != NULL; p = p->next)
    printf ("%s ", p->word);
  printf ("\n");
}



















