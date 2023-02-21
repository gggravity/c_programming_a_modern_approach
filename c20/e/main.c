#include <stdio.h>

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c\n"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0')

#define M(x, y) ((x)^=(y),(y)^=(x),(x)^=(y))

long output (long n)
{
  long m = n ? output (n / 2) : 0;
  printf ("%d", (int) (n % 2));
  return m;
}

unsigned short swap_bytes (unsigned short i);
unsigned short swap_bytes2 (unsigned short i);
unsigned int rotate_left (unsigned int i, int n);
unsigned int rotate_right (unsigned int i, int n);

unsigned int f (unsigned int i, int m, int n);

int count_ones (unsigned char ch);
int count_ones_no_loop (unsigned char ch);

unsigned int reverse_bits(unsigned int n);

int main ()
{

  // e 1

  unsigned short i, j, k;

  i = 8;
  j = 9;
  printf ("%d\n", i >> (i + j) >> 1);

  i = 1;
  printf ("%d\n", i & ~i);
  printf ("i:  " BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(i));
  printf ("~i: " BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(~i));

  i = 2;
  j = 1;
  k = 0;
  printf ("%d", i & ~j ^ k);

  i = 7;
  j = 8;
  k = 9;
  printf ("%d\n", i ^ j & k);

  // e 2

  i = 0x0000;
  i |= 0x0010;
  printf ("i: " BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(i));

  // e 3

  unsigned short x = 0b00000000;
  unsigned short y = 0b10100111;

  unsigned short Mxy = M(x, y);

  printf ("M(x, y): %d\n", Mxy);
  printf ("M(x, y): " BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(Mxy));

  // e 4

  printf ("%lu\n", sizeof (long));

  int r = 111;
  int g = 222;
  int b = 123;

#define MK_COLOR(r, g, b) ((long) (b) << 16 | (g) << 8 | (r))

  long rgb = MK_COLOR(r, g, b);

  printf ("rgb: %ld\n", rgb);

  // e 5

#define GET_RED(rgb) ((rgb) & (0x00FF))

#define GET_GREEN(rgb) (((rgb) >> 8) & (0x00FF))

#define GET_BLUE(rgb) (((rgb) >> 16) & (0x00FF))

  printf ("r: %ld\n", GET_RED(rgb));
  printf ("g: %ld\n", GET_GREEN(rgb));
  printf ("b: %ld\n", GET_BLUE(rgb));

  // e 6

  unsigned short value = 0x1234;
  printf ("v1: %x with the bytes swapped is: %x\n", value, swap_bytes (value));
  printf ("v2: %x with the bytes swapped is: %x\n", value, swap_bytes2 (value));

  // e 7

  unsigned int test1 = 0x12345678;
  unsigned int rl, rr;
  rl = rotate_left (test1, 4);
  rr = rotate_right (rl, 4);

  printf ("test: %x | rotate_left(4): %x | rotate_right(4): %x\n", test1, rl, rr);

  // e 8

  int n = 3;
  printf (BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(~0 << n));
  printf (BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(~(~0 << n)));
  unsigned int bin = 0b11100001011011101100101101110111;
  printf ("%d\n", f (12, 4, 2));
  printf (BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(f (bin, 8, 9)));

  // e 9

  char ch = 'A';
  printf (BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(ch));
  printf ("%d\n", count_ones (ch));
  printf ("%d\n", count_ones_no_loop (ch));

  // e 10

  unsigned int e10 = 123;
  unsigned int rb = reverse_bits(e10);
  printf (BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(e10));
  printf (BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(rb));



  return 0;
}

unsigned int reverse_bits(unsigned int n)
{
  return rotate_left (n, 4);
}

int count_ones_no_loop (unsigned char ch)
{
  return (
      ((ch >> 0) & 1)
      + ((ch >> 1) & 1)
      + ((ch >> 2) & 1)
      + ((ch >> 3) & 1)
      + ((ch >> 4) & 1)
      + ((ch >> 5) & 1)
      + ((ch >> 6) & 1)
      + ((ch >> 7) & 1)
  );

}

int count_ones (unsigned char ch)
{
  int count = 0;

  for (int i = 0; i < sizeof (char) * 8; i++)
  {
    if (ch & 1 << i)
      count++;
  }
  return count;
}

unsigned int f (unsigned int i, int m, int n)
{
  return (i >> (m + 1 - n)) & ~(~0 << n);
}

unsigned int rotate_left (unsigned int i, int n)
{
  unsigned int temp = i >> ((sizeof (int) * 8) - n);

  return i << n | temp;
}

unsigned int rotate_right (unsigned int i, int n)
{
  unsigned int temp = i << ((sizeof (int) * 8) - n);

  return temp | i >> n;
}

unsigned short swap_bytes (unsigned short i)
{
  unsigned byte1 = i & 0x00FF;
  unsigned byte2 = i >> 8 & 0x00FF;

  return byte1 << 8 | byte2;
}

unsigned short swap_bytes2 (unsigned short i)
{
  return ((i & 0x00FF) << 8) | ((i >> 8) & 0x00FF);
}