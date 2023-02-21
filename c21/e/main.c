#include <stdio.h>
#include <ctype.h>

// e 1

// C:\cygwin64\lib\gcc\x86_64-pc-cygwin\10\include

// e 2

// int <stdio.h>
// #define	getchar()	_getchar_unlocked()
// #define	getchar()	getc(stdin)

// e 3

// the function have to come first else the preprocessor don't know what to replace.

// e 4

// e 5

//#define islower(c) ((c) >= 'a' && (c) <= 'z')

// It's a redefinition. Only legal if ctype.h is not included.

// e 6

// a: they are reserved for use in the library.

// b: 9 is a whitespace character and have _SPACE   0x20 (bit 5) set
// 32 is the same as 9
// A 65 is uppercase and alpha and have _UPPER   0x01 set (bit 0)
// 94 ^ is non of the mentioned thing.

// c. it will run faster.

// e 7

// a: time.h
// b: ctype.h
// c: limits.h
// d: math.h
// e: limits.h
// f: float.h
// g: string.h
// h: stdio.h



int main ()
{
  char ch = 'a';

  islower(ch);
  printf ("Hello, World!\n");
  return 0;
}
