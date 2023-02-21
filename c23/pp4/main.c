#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main ()
{
  char line[] = "der var en gang en mand.";

  size_t len = strlen (line);

  char *pl = line;

  pl = strtok (pl, " ");

  while (strtok (NULL, " ") != NULL);

  char *p = line + len - 1;

  while (p >= line)
  {
    if (*p == '\0')
      printf ("%s ", p + 1);
    else if (p == line)
      printf ("%s ", p);
    p--;
  }

  return 0;
}
