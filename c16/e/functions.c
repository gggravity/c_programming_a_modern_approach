//
// Created by martin on 24/10/2021.
//

#include <stdio.h>
#include <math.h>
#include "functions.h"

void init_board(struct Square board[8][8])
{
  struct Square square;
  square.piece = EMPTY;

  for (struct Square *p = &board[0][0]; p <= &board[7][7]; p++)
    *p = square;


  square.piece = PAWN;
  square.color = BLACK;
  for (struct Square *p = (struct Square *) &board[1]; p < board[1] + 8; p++)
    *p = square;

  square.color = WHITE;
  for (struct Square *p = (struct Square *) &board[6]; p < board[6] + 8; p++)
    *p = square;

  square.piece = BISHOP;
  board[7][2] = square;
  board[7][5] = square;

  square.color = BLACK;
  board[0][2] = square;
  board[0][5] = square;

  square.piece = KNIGHT;
  board[0][1] = square;
  board[0][6] = square;

  square.color = WHITE;
  board[7][1] = square;
  board[7][6] = square;

  square.piece = ROOK;
  board[7][0] = square;
  board[7][7] = square;

  square.color = BLACK;
  board[0][0] = square;
  board[0][7] = square;

  square.piece = QUEEN;
  board[0][3] = square;

  square.color = WHITE;
  board[7][3] = square;

  square.piece = KING;
  board[7][4] = square;

  square.color = BLACK;
  board[0][4] = square;


}

void print_square(struct Square s)
{
  switch (s.piece)
  {
  case 0:
    printf(" .. ");
    break;
  case 1:
    s.color == WHITE ? printf(" pw ") : printf(" PW ");
    break;
  case 2:
    s.color == WHITE ? printf(" kn ") : printf(" KN ");
    break;
  case 3:
    s.color == WHITE ? printf(" bi ") : printf(" BI ");
    break;
  case 4:
    s.color == WHITE ? printf(" ro ") : printf(" RO ");
    break;
  case 5:
    s.color == WHITE ? printf(" qe ") : printf(" QE ");
    break;
  case 6:
    s.color == WHITE ? printf(" ki ") : printf(" KI ");
    break;
  default:
    printf(" ");
    break;


  }
}


void print_board(struct Square board[8][8])
{
  int i = 1;
  for (struct Square *p = &board[0][0]; p <= &board[7][7]; p++)
  {
    print_square (*p);
    if (i % 8 == 0)
      printf ("\n");
    i++;
  }
}



bool p_within_r (struct rectangle r, struct point p)
{
  if (p.x > r.upper_left.x && p.x < r.lower_right.x && p.y < r.upper_left.y && p.y > r.lower_right.y)
    return true;
  else
    return false;
}

struct rectangle move_rectangle_x_y (struct rectangle r, int x, int y)
{
  struct rectangle r_new;

  r_new.upper_left.x = r.upper_left.x + x;
  r_new.lower_right.x = r.lower_right.x + x;

  r_new.upper_left.y = r.upper_left.y + y;
  r_new.lower_right.y = r.lower_right.y + y;

  return r_new;
}

struct point compute_center_of_rectangle (struct rectangle r)
{
  int x_center = (r.upper_left.x + r.lower_right.x) / 2;
  int y_center = (r.upper_left.y + r.lower_right.y) / 2;

  return (struct point) {x_center, y_center};
}

int compute_area_of_rectangle (struct rectangle r)
{
  return abs (r.upper_left.x - r.lower_right.x) * abs (r.upper_left.y - r.lower_right.y);
}

void print_rectangle (struct rectangle r)
{
  printf ("(%d, %d), (%d, %d)\n", r.upper_left.x, r.upper_left.y, r.lower_right.x, r.lower_right.y);
}

void print_point (struct point p)
{
  printf ("(%d, %d)\n", p.x, p.y);
}

struct color darker (struct color c)
{
  struct color color;

  color.red = c.red;
  color.green = c.green;
  color.blue = c.blue;

  if (color.red == 255 && color.green == 255 && color.blue == 255)
  {
    color.red = 252;
    color.green = 252;
    color.blue = 252;
    return color;
  }

  if (color.red > 252)
    color.red = 252;
  if (color.green > 252)
    color.green = 252;
  if (color.blue > 252)
    color.blue = 252;

  if (color.red * 0.7 >= 0)
    color.red = (int) (color.red * 0.7);
  else
    color.red = 0;
  if (color.green * 0.7 >= 0)
    color.green = (int) (color.green * 0.7);
  else
    color.green = 0;
  if (color.blue * 0.7 >= 0)
    color.blue = (int) (color.blue * 0.7);
  else
    color.blue = 0;

  return color;
}

struct color brighter (struct color c)
{
  struct color color;

  color.red = c.red;
  color.green = c.green;
  color.blue = c.blue;

  if (color.red == 0 && color.green == 0 && color.blue == 0)
  {
    color.red = 3;
    color.green = 3;
    color.blue = 3;
    return color;
  }

  if (color.red < 3)
    color.red = 3;
  if (color.green < 3)
    color.green = 3;
  if (color.blue < 3)
    color.blue = 3;

  if (color.red / 0.7 <= 255)
    color.red = (int) (color.red / 0.7);
  else
    color.red = 255;
  if (color.green / 0.7 <= 255)
    color.green = (int) (color.green / 0.7);
  else
    color.green = 255;
  if (color.blue / 0.7 <= 255)
    color.blue = (int) (color.blue / 0.7);
  else
    color.blue = 255;

  return color;
}

bool equal_color (struct color color1, struct color color2)
{
  return color1.red == color2.red && color1.green == color2.green && color1.blue == color2.blue ? true : false;
}

int getRed (struct color c)
{
  return c.red;
}

void print_color (struct color color)
{
  printf ("rgb(%d,%d,%d)\n", color.red, color.green, color.blue);
}

struct color make_color (int red, int green, int blue)
{
  struct color color;

  if (red < 0)
    red = 0;
  if (red > 255)
    red = 255;

  if (green < 0)
    green = 0;
  if (green > 255)
    green = 255;

  if (blue < 0)
    blue = 0;
  if (blue > 255)
    blue = 255;

  color.red = red;
  color.green = green;
  color.blue = blue;

  return color;
}

Fraction subtract_fractions (Fraction f1, Fraction f2)
{
  Fraction f;

  f.numerator = f1.numerator * f1.denominator - f1.numerator * f2.denominator;

  f.denominator = f1.denominator * f2.denominator;

  return reduce_fraction (f);

}
Fraction multiply_fractions (Fraction f1, Fraction f2)
{
  Fraction f;

  f.numerator = f1.numerator * f2.numerator;

  f.denominator = f1.denominator * f2.denominator;

  return reduce_fraction (f);

}

Fraction divide_fractions (Fraction f1, Fraction f2)
{
  Fraction f;

  f.numerator = f1.numerator * f2.denominator;

  f.denominator = f1.denominator * f2.numerator;

  return reduce_fraction (f);
}

Fraction add_fractions (Fraction f1, Fraction f2)
{
  Fraction f;

  f.numerator = f1.numerator * f2.denominator + f1.numerator * f1.denominator;

  f.denominator = f1.denominator * f2.denominator;

  return reduce_fraction (f);
}

Fraction reduce_fraction (Fraction f)
{
  Fraction new_fraction;
  int gcd = greatest_common_divisor (f);
  new_fraction.numerator = f.numerator / gcd;
  new_fraction.denominator = f.denominator / gcd;

  if (new_fraction.denominator < 0 && new_fraction.numerator > 0)
  {
    new_fraction.numerator *= -1;
    new_fraction.denominator *= -1;
  }

  return new_fraction;
}

int greatest_common_divisor (Fraction f)
{

  while (f.numerator != 0)
  {
    int divisor = f.denominator % f.numerator;
    f.denominator = f.numerator;
    f.numerator = divisor;
  }

  return f.denominator;
}

void print_fraction (Fraction f)
{
  printf ("%d / %d\n", f.numerator, f.denominator);
}

struct time split_time (long total_seconds)
{
  struct time t;
  t.hours = total_seconds / (60 * 60);
  t.minutes = (total_seconds % (60 * 60)) / 60;
  t.secounds = (total_seconds % (60 * 60)) % 60;

  return t;
}

void print_time (struct time t)
{
  printf ("%dh %dm %ds\n", t.hours, t.minutes, t.secounds);
}

void print_date (struct date d)
{
  printf ("day: %02d | month: %02d | year: %d\n", d.day, d.month, d.year);
}

int compare_dates (struct date d1, struct date d2)
{
  // all mouths have 30 days and leap years don't exist. :-)
  int since_zero_d1 = d1.year * 365 + d1.month * 30 + d1.day;
  int since_zero_d2 = d2.year * 365 + d2.month * 30 + d2.day;

  if (since_zero_d1 < since_zero_d2)
    return -1;
  else if (since_zero_d1 > since_zero_d2)
    return 1;
  else
    return 0;
}

int day_of_year (struct date d)
{
  return d.day;
}

Complex add_complex_typedef (Complex c1, Complex c2)
{
  Complex c;

  c.real = c1.real + c2.real;
  c.imaginary = c1.imaginary + c2.imaginary;

  return c;
}

Complex make_complex_typedef (double real, double imaginary)
{
  Complex c;

  c.real = real;
  c.imaginary = imaginary;

  return c;
}

struct complex add_complex (struct complex c1, struct complex c2)
{
  struct complex c;

  c.real = c1.real + c2.real;
  c.imaginary = c1.imaginary + c2.imaginary;

  return c;
}

struct complex make_complex (double real, double imaginary)
{
  struct complex c;

  c.real = real;
  c.imaginary = imaginary;

  return c;
}

double shape_compute_area (struct shape shape)
{
  double area = 0;

  if (shape.shape_kind == RECTANGLE)
    area = shape.u.rectangle.width * shape.u.rectangle.height;
  else if (shape.shape_kind == CIRCLE)
    area = M_PI * pow (shape.u.circle.radius, 2);

  return area;
}

struct shape shape_move (struct shape shape, int x, int y)
{
  struct shape this;

  this.shape_kind = shape.shape_kind;
  this.center.x = shape.center.x + x;
  this.center.y = shape.center.y + y;
  this.u.rectangle.width = shape.u.rectangle.width;
  this.u.rectangle.height = shape.u.rectangle.height;
  this.u.circle.radius = shape.u.circle.radius;

  return this;
}

struct shape shape_scale (struct shape shape, double c)
{
  struct shape this;

  this.shape_kind = shape.shape_kind;
  this.center.x = shape.center.x;
  this.center.y = shape.center.y;
  this.u.rectangle.width = (int)(shape.u.rectangle.width * c);
  this.u.rectangle.height = (int)(shape.u.rectangle.height * c);
  this.u.circle.radius = (int)(shape.u.circle.radius * c);

  return this;
}