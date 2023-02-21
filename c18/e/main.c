#include <stdio.h>

#define PI 3.14159

// e 1

//// a: storage class: static, type qualifiers: none, type specifiers: char, declarators: **lookup, initializers, none.
//static char **lookup(int level);
//
//// b: storage class: static, type qualifiers: volatile, type specifiers: unsigned long, declarators: io_flags, initializers: none.
//volatile unsigned long io_flags;
//
//// c: storage class: extern, type qualifiers: none, type specifiers: char, declarators: *file_name[MAX_FILES] and path[], initializers: none.
//extern char *file_name[MAX_FILES], path[];
//
//// d: storage class: static, type qualifiers: const, type specifiers: char, declarators: token_buf[], initializers: "".
//static const char token_buf[] = "";

// e 2

// a: extern
// b: static
// c: extern and static

// e 3

// storage duration (static or automatic)?
// scope (block or file)
// linkage (internal, external or none)

// a: static, file, unknown
// b: automatic, block, none
// c: static, block, none
// d: automatic, block, none

//extern float a;
//
//void f(register double b)
//{
//  static int c;
//  auto char d;
//}

// e 4

//int f(int i)
//{
//  static int j = 0;
//  return i * j++;
//}

// e 5

// a: true
// b: false
// c: false
// d: true

// e 6

//void print_error(const char *message)
//{
//  static int n = 1;
//  printf("Error %d: %s\n", n++, message);
//}

// e 7

// a: false
// b: true
// c: true
// d: true

// e 8

//// a:  array of 10 of pointers to function with int argument returning char
//char (*x[10])(int);
//
//// b: function returning an array of 5 int.
//int (*x(int))[5];
//
//
//// c: x is a function with no arguments that returns a pointer to a function with an int argument that returns a pointer to a float value.
//float *(*x(void))(int);
//
//// d: x is a function with two arg (int and void(*y)int) returning a pointer to a function with int arg returning void.
//void (*x(int, void (*y)(int)))(int);

// e 9

//// a: char (*x[10]) (int);
//
////typedef char fx_t(int);
////typedef fx_t *fx_ptr_t;
////typedef fx_ptr_t fx_ptr_array_t[10];
////fx_ptr_array_t x;
//
//// b: int (*x (int))[5];
////  x is a function that returns a pointer to an array of five integers.
//
//typedef int Arr[5];
//typedef Arr Fcn (int)
//Fcn *x;
//
//// c: float *(*x (void)) (int);
//
//typedef float *Outer_Fcn (int);
//typedef Outer_Fcn *Inner_fcn (void);
//Inner_Fcn x;
//
//
//// d: void (*x (int, void (*y) (int))) (int);
//
//typedef void Outer_Fcn (int);
//typedef void *Arg_Fcn (int);
//typedef Outer_Fcn *Inner_fcn (int, Arg_Fcn);
//Outer_Fcn x;

// e 10

//// a:
//char *(*p) (char *);
//// b:
//void *(f (struct t *p, long int n)) (void);
//// c:
//void (*a[4]) (void) = {insert, search, update, print};
//// d:
//struct t (*b[10])(int, int);

// e 11

//int *f(int);
//
//int (*g(int))(int);
//
//int (*a[10])(int)

// e 12

//int return_func (double d)
//{
//  return (int) d * 5;
//}
//
//int (*f (float (*fp) (long), char *cp)) (double d)
//{
//  int t = (int)fp(10) + (int)*cp;
//  printf ("%d", t);
//
//  return &return_func;
//}
//
//
//// f a function with two args, arg 1 is a pointer to a func taking a long and returning a float, arg 2 is a char pointer.
//// returning a pointer to a function taking a double arg and returning an int.
//
//float arg1(long l)
//{
//  return (float)l;
//}


int main ()
{
 // e 13
//  char c = 65;
//  printf ("%c\n", c);
//
//  static const int i = 5, j = i * i; // need to be const to work.
//  printf ("i:%d | j:%d\n", i, j);
//
//  double d = 2 * PI;
//  printf ("d: %.2f\n", d);
//
//  double angles[] = {0, PI / 2, PI, 3 * PI / 2};
//  for (int i = 0; i < sizeof angles / sizeof angles[0]; i++)
//  {
//    printf ("%.2f ", angles[i]);
//  }

  // e 14

  // e

  // e 15

  // a


  //  char arg2 = 'X';
//
//  int x = (f (arg1, &arg2))(10.0f);
//
//  printf("x: %d\n", x);

//  printf("f(10) first time: %d\n", f(10)); // 0
//  f(10); // 10
//  f(10); // 20
//  f(10); // 30
//  f(10); // 40
//  printf("f(10) after five times: %d\n", f(10)); // 50

//  const char *error_message ="FATAL ERROR";
//
//  for (int i = 0; i < 10; i++)
//  {
//    print_error (error_message);
//  }



  return 0;
}
