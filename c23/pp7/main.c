#include <stdio.h>
#include <string.h>

int main ()
{
  char line[1000];
  int count = 0;
  int total_count = 0;

  while (gets(line))
  {
    size_t n = strlen(line);
    for (char *p = line; p < line + n; p++)
    {
      if (strchr(".?!", *p) != NULL && (*(p + 1) == ' ' || (p + 1) == line + n))
        count++;
    }
    printf ("count: %d\n", count);
    total_count += count;
    count = 0;
  }

  printf ("total_count: %d\n", total_count);

  return 0;
}
