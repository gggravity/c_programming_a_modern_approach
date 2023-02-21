//
// Created by martin on 25/10/2021.
//

#ifndef _STRUCTS_H_
#define _STRUCTS_H_

struct complex {
    double real;
    double imaginary;
};

typedef struct {
    double real;
    double imaginary;
} Complex;

struct date {
    int day;
    int month;
    int year;
};

struct time {
    int hours;
    int minutes;
    int secounds;
};

typedef struct {
    int numerator;
    int denominator;
} Fraction;

struct color {
    int red;
    int green;
    int blue;
};

struct point {
    int x;
    int y;
};

struct rectangle {
    struct point upper_left;
    struct point lower_right;
};

//struct {
//    double a;
//    union {
//        char b[4];
//        double c;
//        int d;
//    } e;
//    char f[4];
//} s;
//
//union {
//    double a;
//    struct {
//        char b[4];
//        double c;
//        int d;
//    } e;
//    char f[4];
//} u;

enum shape_kinds { RECTANGLE, CIRCLE };

struct shape {
    int shape_kind; // RECTANGLE or CIRCLE
    struct point center; //coordinates of center
    union {
        struct {
            int height;
            int width;
        } rectangle;
        struct {
            int radius;
        } circle;
    } u;
} s;

//enum days_of_the_week { MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY};

typedef enum { MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY} dotw;

enum Piece { EMPTY, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING };
enum Color { BLACK, WHITE };

struct Square {
    enum Piece piece;
    enum Color color;
};

#endif //_STRUCTS_H_
