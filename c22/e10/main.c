#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
  FILE *source_fp, *dest_fp;
  int ch;

  if (argc != 3)
  {
    fprintf (stderr, "usage: fcopy source dest\n");
    exit (EXIT_FAILURE);
  }
  if ((source_fp = fopen (argv[1], "rb")) == NULL)
  {
    fprintf (stderr, "Can't open %s\n", argv[1]);
    exit (EXIT_FAILURE);
  }
  if ((dest_fp = fopen (argv[2], "wb")) == NULL)
  {
    fprintf (stderr, "Can't open %s\n", argv[2]);
    exit (EXIT_FAILURE);
  }

  while((ch = getc(source_fp)) != EOF)
  {
    if(ferror(source_fp) || feof(source_fp))
    {
      fprintf (stderr, "Error while reading from file: %s\n", argv[1]);
      exit (EXIT_FAILURE);
    }
    if(ferror(dest_fp) || feof(dest_fp))
    {
      fprintf (stderr, "Error while writing to file: %s\n", argv[2]);
      exit (EXIT_FAILURE);
    }

    putc (ch, dest_fp);
  }

  fclose (source_fp);
  fclose (dest_fp);

  return 0;
}
