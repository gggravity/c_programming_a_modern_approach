//
// Created by martin on 13/11/2021.
//

#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

#include <stdbool.h>

double round_nearest (double x);

double round_nearest_n (double x, int n);

bool check_c_identifier (char *string);

long int is_valid_hex_decimal (char *hex_string);

int numchar (const char *s, char ch);

char *my_strdup (char *s);

bool my_stricmp (char *s1, char *s2);

char *my_strlwr (char *s);

char *my_strrev (char *s);

char *my_strset (char *s, char ch);

int count_words(char *sentence);

#endif //_FUNCTIONS_H_
