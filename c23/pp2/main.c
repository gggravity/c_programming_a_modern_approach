#include <stdio.h>
#include <string.h>

int main ()
{
  char line[1000];
  int ch;

  while (gets(line))
  {
    size_t len = strlen(line);
    char *p = line;
    char *end = line + len;

    while (*p == ' ')
      p++;

    if (p != end)
      printf ("%s\n", p);
  }

  return 0;
}
