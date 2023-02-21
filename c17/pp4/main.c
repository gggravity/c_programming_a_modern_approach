#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "line.h"
#include "word.h"

int main ()
{
  int word_len = 0;
  extern int num_words;

  char word[100];

  struct node *line = NULL;


  while ((word_len = read_word (word, 50)) != EOF)
  {

//    if (word_len == 0)
//    {
//      printf ("Line need flushing...\n");
////      flush_line();
//      return 0;
//    }

    if (word_len > MAX_WORD_LEN)
      word[MAX_WORD_LEN] = '*';

    if ( word_len + 1 > space_remaining() - 1)
    {
      write_line(line);
      clear_line(&line);
    }

    add_word (word, &line);
  }

  write_line(line);

//  print_list (line);

  printf("num_words: %d\n", num_words);

  return 0;
}