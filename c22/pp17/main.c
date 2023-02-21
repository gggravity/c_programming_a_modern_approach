#include <stdio.h>
#include <stdlib.h>

int main ()
{
  FILE *fp = fopen ("../input.txt", "r");

  if (fp == NULL)
  {
    perror ("Error reading file");
    exit (EXIT_FAILURE);
  }

  int a, b, c;
  char line[100];

  while (fgets (line, 100, fp))
  {
    if (sscanf (line, "%d . %d . %d", &a, &b, &c) == 3 ||
        sscanf (line, "(%d) %d-%d", &a, &b, &c) == 3 ||
        sscanf (line, "%d - %d - %d", &a, &b, &c) == 3 ||
        sscanf (line, "%d %d %d", &a, &b, &c) == 3 ||
        sscanf (line, "%3d%3d%4d", &a, &b, &c) == 3)
      printf ("(%d) %d-%d\n", a, b, c);
  }

  return 0;
}
