#include <stdio.h>

int main ()
{
  int grade;

  printf ("Enter numerical grade:");
  scanf ("%d", &grade);

  if (grade < 0 || grade > 100)
  {
    printf ("wrong grade");
    return 1;
  }

  switch (grade / 10)
  {
  case 10:
  case 9:
    printf ("Letter grade: A");
    break;
  case 8:
    printf ("Letter grade: B");
    break;
  case 7:
    printf ("Letter grade: C");
    break;
  case 6:
    printf ("Letter grade: D");
    break;
  default:
    printf ("Letter grade: F");
    break;
  }

  return 0;
}
