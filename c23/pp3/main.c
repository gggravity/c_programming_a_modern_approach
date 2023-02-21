#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int main ()
{

  char line[1000];

  while (gets (line))
  {
    char *p = line;

    if (isalpha (*p))
      *p = (char)toupper (*p);

    while (true)
    {
      p = strchr (p, ' ');
      if (p == NULL)
        break;
      *(p + 1) = (char)toupper (*(p + 1));
      p++;
    }
    printf("%s\n", line);
  }

  return 0;
}
