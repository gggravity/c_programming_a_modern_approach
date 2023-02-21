#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
//
//#define CUBE(n) ((n)*(n)*(n))
//#define REMINDER_FOUR(n) ((n) % (4))
//#define LT_100(x, y) ((((x) * (y)) < 100) ? 1 : 0)
//#define NELEMS(a) (sizeof(a) /sizeof(a)[0])
//#define DOUBLE(x) (2*(x))
//#define AVG(x, y) (((x) + (y)) / 2.)
//#define AREA(x, y) ((x) * (y))
//#define TOUPPER(c) ('a' <= (c) && (c) <= 'z' ? (c) - 'a' + 'A' : (c))

#define GENERIC_MAX(type) \
type type##_max(type x, type y) \
{                         \
return x > y ? x : y; \
}

GENERIC_MAX(long)

//long long_max (long x, long y)
//{ return x > y ? x : y; }

//GENERIC_MAX(unsigned long)
//unsigned long unsigned long_max (unsigned long x, unsigned long y) // error: two unsigned
//{ return x > y ? x : y; }

typedef unsigned long ULONG;
GENERIC_MAX(ULONG)

int main ()
{
//  // e 1
//  printf ("%d\n", CUBE(3));
//  printf ("%d\n", REMINDER_FOUR(7));
//
//  printf ("%d\n", LT_100(4, 4));
//  printf ("%d\n", LT_100(5, 50));
//
//  // e 2
//
//  int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//
//  printf ("%llu\n", NELEMS(a));
//
//  // e 3
//
//  printf ("%d\n", DOUBLE(1 + 2));
//  printf ("%d\n", 4 / DOUBLE(2));

  // e 4
//
//  printf ("%f\n", 1 / 2.5);
//  printf ("%f\n", 1. / AVG(2, 3));

//  printf ("area: %d\n", AREA(4, 2));
//  printf ("area: %f\n", 2.0f / AREA(4, 2));
//  printf ("area: %f\n", 2.0f/ AREA(2, 4));

  // e 5
//
//  char s[100];
//  int i;
//  strcpy (s, "abcd");
//  printf ("%s", s);
//  i = 0;
//  putchar (TOUPPER(s[++i]));
//
//  printf ("\n");
//
//  printf ("%s", s);
//  i = 0;
//  putchar (toupper(s[++i]));
//
//  printf ("\n");
//
//  strcpy (s, "0123");
//  i = 0;
//  putchar (TOUPPER(s[++i]));
//
//  printf ("\n");
//
//  strcpy (s, "0123");
//  i = 0;
//  putchar (toupper(s[++i]));


  // e 6
//#define DISP(f, x)  printf(#f "(%g) = %g", x, f(x))
//
//  DISP(sqrt, 3.0);
//
//  printf ("\n");
//
//#define DISP2(f, x, y)  printf(#f "(%g,%g) = %g", x, y, f(x, y))
//
//  DISP2(pow, 3.0, 2.0);

  // e 7

//  printf ("%ld\n", ULONG_max (1, 3));
//  printf ("%ld\n", long_max (1, 3));

  // e 8

  // e 9
//
//#define CHECK(x, y, n) (((x) >= 0 && ((x) <= ((n) - 1))) && ((y) >= 0 && ((y) <= ((n) - 1))))
//
//  printf ("%d\n", CHECK(1, 2, 4));
//  printf ("%d\n", CHECK(4, 2, 4));
//  printf ("%d\n", CHECK(2, 4, 4));
//  printf ("%d\n", CHECK(-1, 4, 4));
//
//#define MEDIAN(x, y, z) (((x) + (y) + (z)) / 3.0f)
//
//  printf ("%.2f\n", MEDIAN(1, 2, 3));
//  printf ("%.2f\n", MEDIAN(10, 2, 4));
//
//#define POLYNOMIAL(x) ((3 * (pow((x), 5))) + (2 * (pow((x), 4))) - (5 * (pow((x), 3))) - (pow(x, 2)) + (7 * (x)) - 6)
//
//  printf("%g", POLYNOMIAL(2.2));

  // e 10 - simple functions

  // e 11
//  int index = 10;
//
//  fprintf (stderr, "Range error: index = %d\n", index);
//
//#define ERROR(error, idx) fprintf(stderr, error, idx)
//
//  ERROR("Range error: index = %d\n", index);

  // e 12

//#define M 10
//
//#if M
//
//  printf ("Test 1\n");
//
//#endif
//
//#ifdef M
//
//  printf ("Test 2\n");
//
//#endif
//
//#ifndef M
//
//  printf ("Test 3\n");
//
//#endif
//
//#if defined(M)
//
//  printf ("Test 4\n");
//
//#endif
//
//#if !defined(M)
//
//  printf ("Test 5\n");
//
//#endif

// e 13 see other file

// e 15

////#define ENGLISH
////#define FRENCH
//#define SPANISH
//
//#if defined (ENGLISH)
//  printf ("Insert Disk 1");
//#elif defined(FRENCH)
//  printf ("Inserez Le Disque 1");
//#elif defined(SPANISH)
//printf ("Inserte El Disco 1");
//#endif

// e 16

#define IDENT(x) PRAGMA(ident #x)
#define PRAGMA(x) _Pragma(#x)

IDENT(foo) // _Pragma("ident \"foo\"")

  return 0;
}
