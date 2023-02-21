#include <stdio.h>

int main ()
{

  struct s {
      char a;
      int b[2];
      float c;
  };

  struct s s1;

  printf ("sizeof (s1.a): %lu\n", sizeof (s1.a));
  printf ("sizeof (s1.b): %lu\n", sizeof (s1.b));
  printf ("sizeof (s1.c): %lu\n", sizeof (s1.c));

  printf ("offsetof(struct s1, a): %lu\n", offsetof(struct s, a));
  printf ("offsetof(struct s1, b): %lu\n", offsetof(struct s, b));
  printf ("offsetof(struct s1, c): %lu\n", offsetof(struct s, c));

  printf ("sizeof (struct s1): %lu\n", sizeof (struct s));

  // hole of 3 after a.

  return 0;
}
