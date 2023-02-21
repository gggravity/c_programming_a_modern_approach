//
// Created by martin on 24/10/2021.
//

#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

#include <stdbool.h>
#include "structs.h"


double shape_compute_area (struct shape shape);

struct shape shape_move (struct shape shape, int x, int y);

struct shape shape_scale (struct shape shape, double c);

struct complex make_complex (double real, double imaginary);

// add two complex numbers, returning a new complex structure.
struct complex add_complex (struct complex c1, struct complex c2);

Complex make_complex_typedef (double real, double imaginary);

Complex add_complex_typedef (Complex c1, Complex c2);

int day_of_year (struct date d);

int compare_dates (struct date d1, struct date d2);

void print_date (struct date d);

struct time split_time (long total_seconds);

void print_time (struct time t);

void print_fraction (Fraction f);

int greatest_common_divisor (Fraction f);

Fraction reduce_fraction (Fraction f);

Fraction add_fractions (Fraction f1, Fraction f2);

Fraction subtract_fractions (Fraction f1, Fraction f2);

Fraction multiply_fractions (Fraction f1, Fraction f2);

Fraction divide_fractions (Fraction f1, Fraction f2);

struct color make_color (int red, int green, int blue);

void print_color (struct color color);

int getRed (struct color c);

bool equal_color (struct color color1, struct color color2);

struct color brighter (struct color c);

struct color darker (struct color c);

int compute_area_of_rectangle (struct rectangle r);

void print_rectangle (struct rectangle r);

void print_point (struct point p);

struct point compute_center_of_rectangle (struct rectangle r);

struct rectangle move_rectangle_x_y (struct rectangle r, int x, int y);

bool p_within_r (struct rectangle r, struct point p);

void init_board(struct Square board[8][8]);

void print_board(struct Square board[8][8]);

#endif //_FUNCTIONS_H_
