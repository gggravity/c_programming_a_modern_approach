//
// Created by martin on 24/10/2021.
//
#include <stdio.h>
#include <ctype.h>
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
  int pos = 0;
  char ch;

  while (isspace (ch = (char) read_char ()));

  while (ch != ' ' && ch != EOF)
  {
    if (pos < len)
    {
      word[pos++] = (char) ch;
//      word[pos] = '\0';
    }
    ch = (char) read_char ();
  }
  word[pos] = '\0';

  if (ch == EOF)
    return -1;
  else
    return pos;
}