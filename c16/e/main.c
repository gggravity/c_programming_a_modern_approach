#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "functions.h"

#define pd(x, y) printf(#x " = %d : " #y " = %d\n", x, y)
#define p3d(x, y, z) printf(#x " = %d : " #y " = %d : " #z " = %d\n", x, y, z)
#define pf(x, y) printf(#x " = %.1f : " #y " = %.1f\n", x, y)

int main ()
{
  // e 1

//  struct { int x, y; } x;
//  struct { int x, y; } y;
//
//  x.x = 1;
//  x.y = 2;
//
//  y.x = 3;
//  y.y = 4;
//
//  pd(x.x, x.y);
//  pd(y.x, y.y);

  // e 2

//  struct Num { double real; double imaginary; };
//
//  struct Num c1, c2, c3;
//
//  c1.real = 1;
//  c1.imaginary = 2;
//
//  c2.real = 3;
//  c2.imaginary = 4;
//
//  c3.real = 5;
//  c3.imaginary = 6;
//
//  pf (c1.real, c1.imaginary);
//  pf (c2.real, c2.imaginary);
//  pf (c3.real, c3.imaginary);
//
//  c1 = c2;
//
//  printf ("--------------------\n");
//
//  pf (c1.real, c1.imaginary);
//  pf (c2.real, c2.imaginary);
//  pf (c3.real, c3.imaginary);
//
//  c3.real = c1.real + c2.real;
//  c3.imaginary = c1.imaginary + c2.imaginary;
//
//  printf ("--------------------\n");
//
//  pf (c1.real, c1.imaginary);
//  pf (c2.real, c2.imaginary);
//  pf (c3.real, c3.imaginary);

  // e 3

//  struct complex {
//      double real;
//      double imaginary;
//  };


//  struct complex c1 = make_complex (12.3, 23.4);
//  struct complex c2 = make_complex (23.4, 123.2);
//
//  pf (c1.real, c1.imaginary);
//  pf (c2.real, c2.imaginary);
//
//  struct complex c_total = add_complex (c1, c2);
//
//  pf(c_total.real, c_total.imaginary);

  // e 4

//  Complex c1 = make_complex_typedef(12.3, 23.4);
//  Complex c2 = make_complex_typedef(23.4, 123.2);
//
//  pf (c1.real, c1.imaginary);
//  pf (c2.real, c2.imaginary);
//
//  Complex c_total = add_complex_typedef(c1, c2);
//
//  pf(c_total.real, c_total.imaginary);

  // e 5

//  struct date d1 = {21, 07, 1999}, d2 = {1, 3, 1999};
//
//  print_date (d1);
//  print_date (d2);
//  printf ("%d\n", compare_dates (d1, d2));

  // e 6

//  struct time t1 = split_time (6000);
//  struct time t2 = split_time (6666);
//
//  print_time (t1);
//  print_time (t2);

  // e 7

//  Fraction f1 = {1, 2};
//  Fraction f2 = {3, 4};
//
////  print_fraction (f1);
//  print_fraction (f2);
//
//  printf("----------------------\n");
//
//  print_fraction (reduce_fraction (f1));
//  print_fraction (reduce_fraction (f2));
//
//  printf("----------------------\n");
//
//  Fraction f3 = add_fractions (f1, f2);
//
//  print_fraction (f3);
//
//  printf("----------------------\n");

//  Fraction f4 = divide_fractions (f1, f2);
//
//  print_fraction (f4);
//
//  printf ("----------------------\n");
//
//  Fraction f5 = multiply_fractions (f1, f2);
//
//  print_fraction (f5);
//
//  printf ("----------------------\n");
//
//  Fraction f6 = subtract_fractions(f1, f2);
//
//  print_fraction (f6);

//  const struct color MAGENTA = {255, 0,255};

//  const struct color MAGENTA = {.red = 255, .blue = 255};
//
//  p3d(MAGENTA.red, MAGENTA.green, MAGENTA.blue);
//
//  print_color (MAGENTA);
//  print_color (make_color (-1, 111, 256));
//
//  printf ("red: %d\n", getRed (MAGENTA));
//
//  struct color c1 = {0, 111, 255};
//  struct color c2 = {123, 123, 123};
//
//  printf ("equal: %s\n", equal_color (c1, c2) ? "true" : "false");
//
//  printf ("----------------------\n");
//
//  print_color (c1);
//  c2 = brighter (c1);
//  struct color c3 = brighter (c2);
//  struct color c4 = brighter (c3);
//  struct color c5 = brighter (c4);
//
//  print_color (c2);
//  print_color (c3);
//  print_color (c4);
//  print_color (c5);
//
//  struct color c6 = darker(c5);
//  struct color c7 = darker(c6);
//  struct color c8 = darker(c7);
//  struct color c9 = darker(c8);
//  struct color c10 = darker(c9);
//
//  print_color (c6);
//  print_color (c7);
//  print_color (c8);
//  print_color (c9);
//  print_color (c10);

  // e 10

//  struct point p1 = {1, 3};
//  struct point p2 = {3, 1};
//  struct rectangle r1 = {p1, p2};
//
//  print_rectangle (r1);
//  printf ("Area: %d\n", compute_area_of_rectangle (r1));
//
//  struct rectangle r2 = {(struct point) {1, 5}, (struct point) {5, 1}};
//  print_rectangle (r2);
//  printf ("Area: %d\n", compute_area_of_rectangle (r2));
//
//  printf ("Area: %d\n", compute_area_of_rectangle ((struct rectangle) {(struct point) {0, 5}, (struct point) {5, 0}}));
//
//  compute_center_of_rectangle (r1);
//  compute_center_of_rectangle (r2);
//  print_point (compute_center_of_rectangle (r1));
//  print_point (compute_center_of_rectangle (r2));
//
//  printf ("----------------------\n");
//
//  print_rectangle (r1);
//  move_rectangle_x_y (r1, 1,1);
//  print_rectangle (move_rectangle_x_y (r1, 1,1));
//
//  printf ("%s\n", p_within_r (r1, (struct point){2,2}) ? "true" : "false");
//  printf ("%s\n", p_within_r (r1, (struct point){1,3}) ? "true" : "false");

  // e 11

//  printf ("double: %llu\n", sizeof(double));
//  printf ("char: %llu\n", sizeof(int));
//
//  // 20
//
//  printf ("s: %llu\n", sizeof(s));

  // e 12

  // 16

//  printf ("s: %llu\n", sizeof(u));

  // e 13

//  int RECTANGLE = 0;
//
//  struct shape s;
//
//  s.shape_kind = RECTANGLE;
//  s.center.x = 10;
//  s.u.rectangle.height = 25;
//  s.u.rectangle.width = 8;
//  s.u.circle.radius = 5;
//  s.u.circle.radius = 5;

  // e 14

//  struct shape s1;
//
//  s1.shape_kind = RECTANGLE;
//  s1.u.rectangle.height = 10;
//  s1.u.rectangle.width = 20;
//
//  double s1area = shape_compute_area (s1);
//
//  printf("%g\n", s1area);
//
//  struct shape s2;
//
//  s2.shape_kind = CIRCLE;
//  s2.u.circle.radius = 10;
//
//  double s2area = shape_compute_area (s2);
//
//  printf("%g\n", s2area);

  // e 15

//  srand(time(NULL));
//
//  for (int i = 0; i < 100; i++)
//  {
//    int day = rand () % 7;
//
//    if (day == MONDAY)
//      printf ("its monday.\n");
//    else if (day == TUESDAY)
//      printf ("its tuesday.\n");
//    else if (day == WEDNESDAY)
//      printf ("its wednesday.\n");
//    else if (day == THURSDAY)
//      printf ("its thursday.\n");
//    else if (day == FRIDAY)
//      printf ("its friday.\n");
//    else if (day == SATURDAY)
//      printf ("its saturday.\n");
//    else if (day == SUNDAY)
//      printf ("its sunday.\n");
//  }

  // e 16

  // e 17

//  enum {FALSE, TRUE} b;
//  int i;
//
//  b = FALSE;
//  printf("b: %d\n", b);
//  b = i;
//  printf("b: %d\n", b);
//  b++;
//  printf("b: %d\n", b);
//  i = b;
//  printf("i: %d\n", i);
//  i = 2 * b + 1;
//  printf("i: %d\n", i);

  // e 18

//  struct Square board[8][8];
//
//  init_board (board);
//
//  print_board (board);

  // e 19

//  struct pinball_machine {
//      char name[40];
//      int year;
//      enum { EM, SS } type;
//      int players;
//  };
//
//  struct pinball_machine pm;
//  strcpy (pm.name, "some machine");
//  pm.year = 2000;
//  pm.type = SS;
//  pm.players = 6;
//
//  printf ("name: %s\nyear: %d\ntype: %s\nplayers: %d\n", pm.name, pm.year,
//          pm.type == 0 ? "electromechanical" : "solid state", pm.players);

  // e 20

//  enum { NORTH, SOUTH, EAST, WEST } direction;
//  int x = 0, y = 0;
//
//  srand (time (NULL));
//
//  for (int i = 0; i < 1000; i++)
//  {
//    int dir = rand () % 4;
//
//    switch (dir)
//    {
//    case NORTH:
//      y++;
//      printf ("moving north to: ");
//      break;
//    case SOUTH:
//      y--;
//      printf ("moving south to: ");
//      break;
//    case EAST:
//      x++;
//      printf ("moving east to: ");
//      break;
//    case WEST:
//      x--;
//      printf ("moving west to: ");
//      break;
//    default:
//      printf ("confused\n");
//      break;
//    }
//
//    printf ("(%d, %d)\n", x, y);
//  }

  // e 21

//  enum { NUL, SOH, STX, ETX };
//  printf ("%d %d %d %d\n", NUL, SOH, STX, ETX);
//
//  enum { VT = 11, FF, CR };
//  printf ("%d %d %d\n", VT, FF, CR);
//
//  enum { ENQ = 45, ACK, BEL, LF = 37, ETB, ESC };
//  printf ("%d %d %d %d %d %d\n", ENQ, ACK, BEL, LF, ETB, ESC);

  // e 22

  enum chess_pieces { KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN };

//  const int pieces_value[] = {200, 9, 5, 3, 3, 1};

  const int pieces_value[] = {
      [KING] = 200,
      [QUEEN] = 9,
      [ROOK] = 5,
      [BISHOP] = 3,
      [KNIGHT] = 3,
      [PAWN] = 1
  };

  printf ("%d\n", pieces_value[KNIGHT]);

  return 0;
}

