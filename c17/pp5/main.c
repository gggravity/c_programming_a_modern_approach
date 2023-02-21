#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <search.h>

#define N 20

int read_line (char str[], int n)
{
  int ch, i = 0;

  while ((ch = getchar ()) != '\n')
    if (i < n)
      str[i++] = (char) ch;
  str[i] = '\0';
  return i;
}

int compare (const void *p, const void *q)
{
  const char **p1 = p;
  const char **q1 = q;

  if (strcmp (*p1, *q1) > 0)
    return 1;
  else if (strcmp (*p1, *q1) == 0)
    return 0;
  else
    return -1;
}

int compare_strings (const void *p, const void *q)
{
  return strcmp (*(char **) p, *(char **) q);
}

int main ()
{

  int elements = 0;
  int length_of_array = 1;
  char **words = malloc (sizeof (char *));
  char word[N];

  for (;; elements++)
  {
    printf ("Enter word:");
    int str_len = read_line (word, N);

    if (str_len == 0)
      break;

    words[elements] = malloc ((str_len) * sizeof (char));
    strcpy (words[elements], word);
//    printf ("Inserting the element %s at position %d\n", words[elements], elements);

    if (length_of_array == elements)
    {
      realloc (words, length_of_array * 2);
      length_of_array *= 2;
//      printf ("Resizing the array to: %d\n", length_of_array);
    }
  }

  qsort (words, elements, sizeof (char *), compare);

  printf ("In sorted order: ");

  for (char **p = words; p < words + elements; p++)
  {
    printf ("%s ", *p);
  }
  printf ("\n");

  return 0;
}
