#include <stdio.h>
#include <stdlib.h>

#define KEY '&'

int main (int argc, char *argv[])
{

  if (argc != 3)
  {
    printf ("usage: xor file1 file2");
    exit(EXIT_FAILURE);
  }


  int orig_char, new_char;

  FILE *fp_original = fopen (argv[1], "rb");

  if (fp_original == NULL)
  {
    printf ("error reading: %s", argv[1]);
    exit(EXIT_FAILURE);
  }

  FILE *fp_new = fopen (argv[2], "wb");

  if (fp_new == NULL)
  {
    printf ("error writing: %s", argv[2]);
    exit(EXIT_FAILURE);
  }

  while ((orig_char = getc (fp_original)) != EOF)
  {
    new_char = orig_char ^ KEY;
    putc (new_char, fp_new);
  }

  return 0;
}
