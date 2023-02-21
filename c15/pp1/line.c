//
// Created by martin on 24/10/2021.
//

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "line.h"

#define MAX_LINE_LEN 60

char line[MAX_LINE_LEN + 1];
int line_len = 0;
int num_words = 0;

void clear_line (void)
{
  line[0] = '\0';
  line_len = 0;
  num_words = 0;
}

void add_word (const char *word)
{
  if (num_words > 0)
  {
    line[line_len] = ' ';
    line[line_len + 1] = '\0';
    line_len++;
  }
  strcat (line, word);
  line_len += (int) strlen (word);
  num_words++;
}

int space_remaining (void)
{
  return MAX_LINE_LEN - line_len;
}

void write_line (void)
{

  bool drop_spaces_first = true;
  int extra_spaces = MAX_LINE_LEN - line_len;
  int spaces_to_insert;

  for (int i = 0; i < line_len; i++)
  {
    if (line[i] != ' ')
      putchar (line[i]);
    else
    {
      if (drop_spaces_first)
      {
        if (extra_spaces % 2 == 0)
          spaces_to_insert = extra_spaces / 2;
        else if (extra_spaces / 3)
          spaces_to_insert = extra_spaces / 3;
        drop_spaces_first = false;
      }
      else
      {
        spaces_to_insert = extra_spaces / (num_words - 1);
        drop_spaces_first = true;
      }

      for (int j = 1; j <= spaces_to_insert + 1; j++)
        putchar (' ');
      extra_spaces -= spaces_to_insert;
      num_words--;
    }
  }
  putchar ('\n');
}

void flush_line (void)
{
  if (line_len > 0)
    puts (line);
}



















