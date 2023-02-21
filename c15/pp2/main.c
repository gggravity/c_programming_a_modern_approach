#include "line.h"
#include "word.h"

#define MAX_WORD_LEN 20

int main ()
{
  char word[MAX_WORD_LEN + 2];

  clear_line ();

  for(;;)
  {
    int word_len = read_word (word, MAX_WORD_LEN + 1);

    if (word_len == 0)
    {
      flush_line();
      return 0;
    }

    if ( word_len + 1 > space_remaining())
    {
      write_line();
      clear_line();
    }
    add_word (word);
  }
}
