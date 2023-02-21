#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// e 1

// a: binary, b: binary, c: text, d: binary

// e 2

// a: rb, b: a, c: rb, d: r

int count_periods (const char *filename);

int line_length (const char *filename, int n);

char *ffgets (char *string, int n, FILE *stream);

int ffputs (const char *string, FILE *stream);

int main ()
{

  // e 3
  char filename[] = "../some_file.txt";
  char str[100];
  FILE *fp;

  if ((fp = fopen (filename, "r")) != NULL)
  {
    while (fgets (str, sizeof (str), fp))
      printf ("%s", str);
  }
  else
  {
    printf ("Cant open file.\n");
  }
  fclose (fp);

  puts ("");

  // e 4

  printf ("%#012.5g\n", 83.7361);
  printf ("%#012.5g\n", 29748.6607);
  printf ("%#012.5g\n", 1054932234.0);
  printf ("%#012.5g\n", 0.0000235218);

  // e 5

  // 0 is padding, . is precision, it's the same for d, but difference for f.

  printf ("%.4f\n", 0.123);
  printf ("%04f\n", 0.123);

  // e 6

  for (int i = 1; i < 10; i++)
    printf ("%d widget%s", i, i != 1 ? "s\n" : "\n");

  // e 7
//  int i, j, n;
//  float x;
//
//  n = scanf ("%d%f%d", &i, &x, &j);
//  printf ("i: %d, j: %d, n: %d\n", i, j, n);
  // 10 20 30
  // 1.0 2.0 3.0
  // 0.1 0.2 0.3
  // .1 .2 .3

  // e 8

  // " %c" is a space and a char.
  // "%1s" is a c_string with a length of 1 (+ \0).

  // e 9

  // a: getch()

  // e 10

  // see e10 project.

  // e 11

  // != have higher precedence then =, getc(source_fp) != EOF is evaluated first and the result is assigned to ch
  // the assignment is always true and the loop will never end.
  // it compiles fine, but with warnings.

  // e 12

  // while(fgetc(fp) != EOF) reads a char
  // the result is half the count, without the fix.
  int e12 = count_periods ("Makefile");
  printf ("e12: %d\n", e12);

  // e 13

  int e13 = line_length ("Makefile", 17);
  printf ("e13: %d\n", e13);

  // e 14

//  FILE *fp14 = fopen ("Makefile", "r");
//
//  while (fgets (str, 100, fp14) != NULL)
//    printf ("%s", str);


  FILE *fp14 = fopen ("testfile.txt", "w");
  char *str14 = "some test string for e 14 ~~~\n";

  for (int i = 0; i < 10; i++)
    ffputs (str14, fp14);

  // e 15

  FILE *fp15 = fopen ("e.exe", "r");

  if (fp15 == NULL)
  {
    fprintf (stderr, "Error reading stream.");
    exit (EXIT_FAILURE);
  }
  int record_number = 0;
  fseek (fp15, record_number * 64L, SEEK_SET);
  fseek (fp15, -64L, SEEK_END);
  fseek (fp15, 64L, SEEK_CUR);
  fseek (fp15, -128L, SEEK_CUR);

  fclose (fp15);

  // e 16

  long long sales_rank = 0;
  char *str_arr[] = {"989#qwerwerewrr", "24,675#sdføsdfsdfshjkl", "1,162,620#fsfdsfsdfsfsdfsd"};

  int a[10];

  for (int i = 0; i < (sizeof (str_arr) / sizeof (str_arr)[0]); i++)
  {

    int n = sscanf (str_arr[i], "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",
                    &a[0], &a[1], &a[2], &a[3], &a[4], &a[5], &a[6], &a[7], &a[8], &a[9]);

    for (int idx = 0, j = n - 1; idx < n; idx++, j--)
    {
      sales_rank += (long long) (a[idx] * pow (1000, j));
    }
    printf ("sales_rank: %lld\n", sales_rank);
    sales_rank = 0;
  }

  return 0;
}

int ffputs (const char *string, FILE *stream)
{
  if (stream == NULL)
  {
    fprintf (stderr, "Stream is NULL.");
    exit (EXIT_FAILURE);
  }

  const char *p = string;

  while (*p != '\0')
  {
    int rv = putc (*p++, stream);
    if (rv == EOF)
      return EOF;
  }

  return 0;
}

char *ffgets (char *string, int n, FILE *stream)
{
  int ch;

  if (stream == NULL)
  {
    fprintf (stderr, "Error reading stream.");
    exit (EXIT_FAILURE);
  }

  int i;
  for (i = 0; i < n; i++)
  {
    ch = getc (stream);

    string[i] = (char) ch;

    if (ch == EOF)
    {
      return NULL;
    }

    if (ch == '\n')
      break;
  }
  string[i + 1] = '\0';

  return string;
}

int line_length (const char *filename, int n)
{
  FILE *fp;
  char line[100];
  int line_number = 1;
  int line_length = -1;

  fp = fopen (filename, "r");

  if (fp == NULL)
  {
    fprintf (stderr, "Error reading file.");
    exit (EXIT_FAILURE);
  }

  while (fgets (line, 100, fp))
  {
    if (line_number == n)
    {
      line_length = (int) strlen (line);
      break;
    }
    line_number++;
  }
  return line_length;
}

int count_periods (const char *filename)
{
  FILE *fp;
  int n = 0;
  int ch;

  if ((fp = fopen (filename, "r")) != NULL)
  {
    while ((ch = fgetc (fp)) != EOF)
      if (ch == '.')
        n++;
    fclose (fp);
  }
  return n;
}