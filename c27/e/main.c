#include <stdio.h>
//#include <stdint.h>
//#include <inttypes.h>
#include <math.h>
#include <complex.h>
#include <tgmath.h>

#define INT32_C_M(n)  n##L
#define UINT32_C_M(n)  n##UL

#define INT64_C_M(n)  n##LL
#define UINT64_C_M(n)  n##ULL

int main ()
{
//  INT32_C_M(1234);
//  UINT32_C_M(1234);
//
//  INT64_C_M(1234);
//  UINT64_C_M(1234);
//
//  int8_t i1 = 123;
//  printf ("%d\n", i1);
//  printf("%" PRId8 "\n", i1);
//
//  int32_t i2 = 1234;
//  printf("%12.4d\n", i2);
//  printf("%12.4" PRId32 "\n", i2);
//
//  uint16_t ui16 = 1234;
//  printf("%-6o\n", ui16);
//  printf("%-6" PRIo16 "\n", ui16);
//
//  uint64_t ui64 = 123456789;
//  printf ("%#lx\n", ui64);
//  printf ("%#" PRIx64 "\n", ui64);

  int i = 123;
  float f = -123.123f;
  double d = 0.04f;
  long double ld = 123.123f;
  float complex fc = 12 + 1*I;
  double complex dc = 12 + 1*I;
  long double complex ldc = 12 + 1*I;

  printf ("tan(i): %g\n", tan(i));
  printf ("fabs(f): %g\n", fabs(f));
  printf ("asin(d): %g\n", asin(d));
  printf ("exp(ld): %g\n", exp(ld));
  printf ("log(fc): %g %gI\n", creal (log(fc)), cimag (log(fc)));
  printf ("acosh(dc): %g\n", acosh(dc));
  printf ("nexttoward(d, ld): %g\n", nexttoward(d, ld));
  printf ("remainder(f, i): %g\n", remainder(f, i));
  printf ("copysign(d, ld): %g\n", copysign(d, ld));
  printf ("carg(i): %g\n", carg(i));
  printf ("cimag(f): %g\n", cimag(f));
  printf ("conj(ldc): %g\n", conj(ldc));




  return 0;
}
