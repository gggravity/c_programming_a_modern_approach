#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[])
{

  if (argc != 2)
  {
    printf ("usage: compress_file file-to-compress");
    exit (EXIT_FAILURE);
  }

  FILE *fp = fopen (argv[1], "rb");

  char new_file[strlen (argv[1]) + 4];

  strcpy (new_file, argv[1]);
  strcat (new_file, ".rle");

  FILE *new_fp = fopen (new_file, "wb");

  if (new_fp == NULL)
  {
    fprintf (stderr, "error writing to output file: %s\n", new_file);
  }

  int ch_count, ch;
  fseek (fp, 0L, SEEK_SET);

  while ((ch = getc (fp)) != EOF)
  {
    int count = 1;

    while ((ch_count = getc (fp)) != EOF)
    {
      if (ch_count == ch)
        count++;
      else
      {
        ungetc(ch_count, fp);
        break;
      }
    }
    putc (count, new_fp);
    putc (ch, new_fp);

  }

  fclose (fp);
  fclose (new_fp);

  return 0;
}
