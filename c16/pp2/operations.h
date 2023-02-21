//
// Created by martin on 26/10/2021.
//

#ifndef _OPERATIONS_H_
#define _OPERATIONS_H_

#define NAME_LEN 25
#define MAX_PARTS 100

struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
} inventory[MAX_PARTS];

int find_part (int number);
void insert (void);
void search (void);
void update (void);
void print (void);

#endif //_OPERATIONS_H_
