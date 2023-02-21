//
// Created by martin on 24/10/2021.
//

#ifndef _LINE_H_
#define _LINE_H_

#define MAX_WORD_LEN 20

struct node {
    char word[50];
    struct node *next;
};

void clear_line(struct node **line);

void add_word (char *word, struct node **line);

int space_remaining(void);

void write_line(struct node *line);

void flush_line(void);

void print_list(struct node *line);

#endif //_LINE_H_
