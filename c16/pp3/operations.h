//
// Created by martin on 26/10/2021.
//

#ifndef _OPERATIONS_H_
#define _OPERATIONS_H_

#define NAME_LEN 25
#define MAX_PARTS 100

  struct part {
      int number;
      int price;
      char name[NAME_LEN + 1];
      int on_hand;
  };

int find_part (int number, const int *num_parts, struct part inventory[]);
void insert (int *num_parts, struct part inventory[]);
void search (int *num_parts, struct part inventory[]);
void update (int *num_parts, struct part inventory[]);
void print (const int *num_parts, struct part inventory[]);

#endif //_OPERATIONS_H_
