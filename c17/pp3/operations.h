//
// Created by martin on 26/10/2021.
//

#ifndef _OPERATIONS_H_
#define _OPERATIONS_H_

#define NAME_LEN 25

struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
};

int find_part (struct part *inventory, int number);
void insert (struct part *inventory);
void search (struct part *inventory);
void update (struct part *inventory);
void print (struct part *inventory);
void erase (struct part *inventory);
int compare_parts (const void *p, const void *q);

#endif //_OPERATIONS_H_
