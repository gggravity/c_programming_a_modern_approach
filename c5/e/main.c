#include <stdio.h>
#include <stdbool.h>

int test (int i, int j)
{
  return (i >= j) + (i == j) - 1;
}

int main ()
{
  // 4
  printf ("%d", test (1, 2));
  printf ("%d", test (2, 1));
  printf ("%d", test (1, 1));

  //5
  for (int n = -5; n <= 15; n++)
  {
    if (n >= 1 <= 10) // always true
      printf ("%d is between 1 and 10\n", n);
    else
      printf ("%d is not between 1 and 10\n", n);
  }

  // 6
  for (int n = -10; n <= 10; n++)
  {
    if (n == 1 - 10) // b == -9
      printf ("e6: %d is between 1 and 10\n", n);
    else
      printf ("e6: %d wrong.\n", n);
  }

  // 7
  int i = 17;
  printf ("e7: i = %d -> %d\n", i, i >= 0 ? i : -i);
  i = -17;
  printf ("e7: I = %d -> %d\n", i, i >= 0 ? i : -i);

  // 8
  bool teenager;
  for (int age = 1; age <= 20; age++)
  {
    if (age >= 13)
      if (age <= 19)
        teenager = true;
      else
        teenager = false;
    else if (age < 13)
      teenager = false;
    printf ("e8a: age %d -> teenager: %s\n", age, teenager ? "true" : "false");
  }

  for (int age = 1; age <= 20; age++)
  {
    teenager = age >= 13 && age < 20 ? true : false;
    printf ("e8b: age %d -> teenager: %s\n", age, teenager ? "true" : "false");
  }

  i = 1;
  switch (i % 3)
  {
  case 0:
    printf ("zero");
  case 1:
    printf ("one");
  case 2:
    printf ("two");
  }

  for (int area_code = 200; area_code < 1000; area_code++)
  {
    printf("Area code: %d -> ", area_code);

    switch (area_code)
    {
    case 229:
      printf ("Albany\n");
      break;
    case 404:
    case 470:
    case 678:
    case 770:
      printf ("Atlanta\n");
      break;
    case 478:
      printf ("Macon\n");
      break;
    case 706:
    case 762:
      printf ("Columbus\n");
      break;
    case 912:
      printf ("Savannah\n");
    default:
      printf ("Area code not recognized.\n");
      break;
    }
  }
  return 0;
}
