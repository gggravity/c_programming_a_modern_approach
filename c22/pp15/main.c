#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "line.h"
#include "word.h"

#define MAX_WORD_LEN 20

int main ()
{
  FILE *fp_read = fopen ("quote.txt", "r");
  FILE *fp_write = fopen ("quote_formatted.txt", "w");

  if (fp_read == NULL || fp_write == NULL)
  {
    perror ("File error");
    exit (EXIT_FAILURE);
  }

  char word[MAX_WORD_LEN + 2];
  size_t word_len;

  clear_line ();

  clear_line ();
  for (;;)
  {
    read_word (word, MAX_WORD_LEN + 1, fp_read);
    word_len = strlen (word);
    if (word_len == 0)
    {
      flush_line (fp_write);
      break;
    }
    if (word_len > MAX_WORD_LEN)
      word[MAX_WORD_LEN] = '*';
    if (word_len + 1 > space_remaining ())
    {
      write_line (fp_write);
      clear_line ();
    }
    add_word (word);
  }

  fclose (fp_read);

  return 0;
}
