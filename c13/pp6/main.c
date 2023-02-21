#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM_PLANETS 9

int main (int argc, char **argv)
{

  char *planets[] = {"mercury", "venus", "earth", "mars", "jupiter", "saturn", "uranus", "neptune", "pluto"};


  for (int i = 1; i < argc; i++)
  {
    for (int j = 0; j < NUM_PLANETS; j++)
    {
      for (char *p = argv[i]; *p != '\0' ; p++)
        *p = tolower(*p);

      if (strcmp (argv[i], planets[j]) == 0)
      {
        printf("%s is %dth planet from the sun.", argv[i], j +1);
        break;
      }
      if (j == NUM_PLANETS)
        printf ("%s is not a planet", argv[i]);
    }
  }

  return 0;
}
