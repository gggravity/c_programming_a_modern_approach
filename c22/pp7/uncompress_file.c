#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[])
{

  if (argc != 2)
  {
    printf ("usage: uncompress_file file-to-uncompress.rle");
    exit (EXIT_FAILURE);
  }

  FILE *fp = fopen (argv[1], "rb");

  char ext[4];
  strcpy (ext, argv[1] + strlen (argv[1]) - 4);

  if (strcmp (ext, ".rle") != 0)
  {
    fprintf (stderr, "error: %s don't end with .rle (%s)", argv[1], ext);
  }

  char new_file[strlen (argv[1]) - 3 + 15];

  strcpy (new_file, argv[1]);
  size_t len = strlen (new_file);
  new_file[len - 4] = '\0';
  strcat (new_file, ".uncompress_file");

  FILE *new_fp = fopen (new_file, "wb");

  if (new_fp == NULL)
  {
    fprintf (stderr, "error writing to output file: %s\n", new_file);
  }

  int count;

  fseek (fp, 0L, SEEK_SET);

  while ((count = getc (fp)) != EOF)
  {
    int ch = getc (fp);

    if (ch == EOF)
      break;

    for (int i = 1; i <= count; i++)
    {
      putc (ch, new_fp);
    }

  }

  fclose (fp);
  fclose (new_fp);

  return 0;
}
