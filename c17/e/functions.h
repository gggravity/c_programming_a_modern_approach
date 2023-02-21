//
// Created by martin on 28/10/2021.
//

#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

#include <stdbool.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct node {
    int value;
    struct node *next;
};

struct part {
    int number;
    char *name;
    int on_hand;
};

int read_line (char str[], int n);

void file_command (const char *command);

void make_empty (struct node **list);

bool is_empty (struct node *list);

bool push (struct node **list, int i);

int pop (struct node **list);

int *my_malloc (int n);

char *duplicate (char *str);

int *create_array (int n, int initial_value);

struct node *add_to_list (struct node *list, int n);

void print_list (struct node *list);

struct node *delete_from_list (struct node *list, int n);

struct node *delete_from_list_new (struct node **list, int n);

struct node *delete_from_list_e_14 (struct node **list, int n);

void print_part (struct part p);

void print_part_new (struct part *p);

int count_occurrences (struct node *list, int n);

struct node *find_last (struct node *list, int n);

struct node *insert_into_ordered_list (struct node *list, struct node *new_node);

struct node *insert_into_ordered_list_fix (struct node *list, int n);

int f1 (int (*f) (int));

int f2 (int i);

int sum (int (*f) (int), int start, int end);

int power (int i);

int compare (const void *p, const void *q);

int compare_parts (const void *p, const void *q);

int compare_parts_desc (const void *p, const void *q);

void new_cmd (void);

void open_cmd (void);

void close_cmd (void);

void close_all_cmd (void);

void save_cmd (void);

void save_as_cmd (void);

void save_all_cmd (void);

void print_cmd (void);

void exit_cmd (void);


#endif //_FUNCTIONS_H_
