//
// Created by martin on 24/10/2021.
//
#include <stdio.h>
#include "word.h"

int read_char (void)
{
  int ch = getchar ();

  if (ch == '\n' || ch == '\t')
    return ' ';

  return ch;
}

int read_word (char *word, int len)
{
  int ch, pos = 0;

  while ((ch = getchar ()) == ' ');

  while (ch != ' ' && ch != EOF)
  {
    if (pos < len)
      word[pos++] = (char)ch;
    ch = read_char();
  }
  word[pos] = '\0';

  if (pos > len)
    word[len] = '*';

  return pos;
}