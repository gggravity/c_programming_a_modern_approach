#include <stdio.h>

int main ()
{
  printf ("%d %d %d\n", 077, 0x77, 0XABC);
//  printf ("%f %f %d %d %d\n", 010E2, 32.1E+5, 0790, 100_000, 3.978e-2);
  printf ("%g %g %g\n", 010E2, 32.1E+5, 3.978e-2); // ok

  short unsigned int usi = 1;
//  short float sf = 1; // invalid
  long double ld = 1;
  unsigned long ul = 1;
  __mingw_printf ("%hu %Lf %lu\n", usi, ld, ul); // microsoft bug.

  char c = 'A';
  int i = 1;
  i += c;
  printf ("%c", i);

  c = (char) (2 * (int) c - 1); // implementing defined cast.
  printf ("%c", c);

  putchar (c);
//  printf(c); // wrong.
  printf ("\n%d %d %d %d\n", 'A', 0b1000001, 0101, 0x41);

  char day = 31;
  short year = 9999;
  char min = 60;
  int min_in_day = 24 * 60 * 60;

  printf ("%d %d %d %d\n", day, year, min, min_in_day);

  printf ("%o %o %o %o\n", '\b', '\n', '\r', '\t');

  printf ("%x %x %x %x\n", '\b', '\n', '\r', '\t');

  i = 20;
  int j = 1;

  int value = i / j + 'a';
  printf ("%d\n", value);

  int ii = 1;
  long jj = 2;
  unsigned int k = 2;
  unsigned int value10 = ii + (int) jj * k;
  printf ("%d\n", value10);

  float f = 1.0f;
  double d = 1.0f;
  double value11 = (float) i * f / d;
  printf ("%lf\n", value11);

  d = (float) i + f;
  printf ("%f", d);

  {
    char c = '\1';
    short s = 2;
    int i = -3;
    long m = 5;
    float f = 6.5f;
    double d = 7.5;

    printf ("\nc * i: %d\n", c * i);
    printf ("s + m: %ld\n", s + m);
    printf ("f / c: %f\n", f / c);
    printf ("d / s: %f\n", d / s);
    printf ("f - d : %f\n", f - d);
    printf ("(int)f %d\n", (int) f);

    float frac_part = f - (int) f; // works for values less than max value of int.
    printf ("%f %f\n", f, frac_part);

    typedef char Int8;
    typedef short Int16;
    typedef int Int32;
    typedef long long Int64;

    printf ("size of Int8: %zd\n", sizeof(Int8) * 8); // return type is bytes, we want bits.
    printf ("size of Int16: %zd\n", sizeof(Int16) * 8);
    printf ("size of Int32: %zd\n", sizeof(Int32) * 8);
    printf ("size of Int64: %zd\n", sizeof(Int64) * 8);

  }

  return 0;
}
