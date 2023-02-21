//
// Created by martin on 24/10/2021.
//

#ifndef _LINE_H_
#define _LINE_H_

void clear_line(void);

void add_word(const char *word);

int space_remaining(void);

void write_line(FILE *fp);

void flush_line(FILE *fp);

#endif //_LINE_H_
