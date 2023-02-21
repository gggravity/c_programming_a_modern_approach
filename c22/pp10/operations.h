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
    struct part *next;
};

struct part *find_part (int number);

void insert (void);

void search (void);

void update (void);

void print (void);

int compare_parts (const void *p, const void *q);

void dump_database (void);

void read_database (void);


#endif //_OPERATIONS_H_
