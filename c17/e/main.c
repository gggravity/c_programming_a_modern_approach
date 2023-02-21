#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

int main ()
{
  // e 1

//  int *p = my_malloc (10000);

  // e 2

//  char str[] = "some string";
//
//  printf ("%s\n", str);
//
//  char *new_str = duplicate (str);
//
//  printf ("%s\n", new_str);

  // e 3

//  int n = 10;
//  int *array = create_array (n, 3);
//
//  for (int i = 0; i < n; i++)
//  {
//    printf ("%d ", array[i]);
//  }
//  printf ("\n");

  // e 4

//  struct point { int x, y; };
//  struct rectangle { struct point upper_left, lower_right; };
//  struct rectangle *p;
//
//  p = malloc (sizeof (struct rectangle));
//
//  p->upper_left = (struct point) {10, 25};
//  p->lower_right = (struct point) {20, 15};
//
//  printf ("(%d, %d), (%d, %d)", p->upper_left.x, p->upper_left.y, p->lower_right.x, p->lower_right.y);
//
//  free (p);

  // e 5

//  struct {
//      union {
//          char a, b;
//          int c;
//      } d;
//      int e[5];
//  } f, *p = &f;
//
////  p->b = ' ';
//  p->d.b = '';
//
//  p->e[3] = 10;
//
//  (*p).d.a = '*';
//
////  p->d->c = 20;
//  p->d.c = 20;

  // e 6

//  struct node *list = NULL;
//
//  list = add_to_list (list, 1);
//  list = add_to_list (list, 2);
//  list = add_to_list (list, 3);
//  list = add_to_list (list, 4);
//  list = add_to_list (list, 5);
//  list = add_to_list (list, 6);
//  list = add_to_list (list, 7);
//
//  print_list (list);
//
//  delete_from_list_new (&list,4);
//
//  print_list (list);

  // e 7

//  struct node *list = NULL;
//
//  list = add_to_list (list, 1);
//  list = add_to_list (list, 2);
//  list = add_to_list (list, 3);
//  list = add_to_list (list, 4);
//  list = add_to_list (list, 5);
//  list = add_to_list (list, 6);
//  list = add_to_list (list, 7);
//
////  struct node *p, *c;
////
////  for (c = list, p = NULL; c != NULL; p = c, c = c->next)
////  {
////    free (p);
////  }
////  free (p);
//
//  struct node *temp;
//
//  struct node *p = list;
//
//  while (p != NULL)
//  {
//    temp = p;
//    p = p->next;
//    free (temp);
//  }
//
//  print_list (list);

  // e 8

//  struct node *list = NULL;
//
//  push (&list, 1);
//  push (&list, 2);
//  push (&list, 3);
//
//  print_list (list);
//
//  printf ("popped: %d\n", pop (&list));
//
//  printf ("popped: %d\n", pop (&list));
//
//  printf ("popped: %d\n", pop (&list));
//
//  printf ("is_empty() = %s\n", is_empty (list) ? "true" : "false");
//
//  print_list (list);
//
//  push (&list, 1);
//  push (&list, 2);
//  push (&list, 3);
//
//  print_list (list);
//
//  make_empty (&list);
//  printf ("is_empty() = %s\n", is_empty (list) ? "true" : "false");
//
//  print_list (list);

  // e 9

//  struct some_struct {
//      int a;
//  } x;
//
//  x.a = 1;
//
//  printf ("%d\n", (&x)->a);
//  printf ("%d\n", x.a);
//
//  // &x is a pointer -> is . to a member of a pointer to a struct.

  // e 10

//  struct part p;
//
//  p.number = 100;
//  strcpy(p.name, "Some Name");
//  p.on_hand = 10;
//
//  print_part (p);
//
//  printf ("------------------------\n");
//
//  print_part_new(&p);

  // e 11

//  struct node *list = NULL;
//
//  list = add_to_list (list, 3);
//  list = add_to_list (list, 2);
//  list = add_to_list (list, 1);
//  list = add_to_list (list, 3);
//  list = add_to_list (list, 3);
//  list = add_to_list (list, 6);
//  list = add_to_list (list, 3);
//
//  print_list (list);
//
//  int c = count_occurrences (list, 3);
//
//  printf("%d\n", c);

// e 12

//  struct node *new_list = find_last(list, 1);
//
//  print_list (new_list);

  // e 13

//  struct node *list = NULL;
//
//  list = insert_into_ordered_list_fix (list, 4);
//  list = insert_into_ordered_list_fix (list, 2);
//  list = insert_into_ordered_list_fix (list, 1);
//  list = insert_into_ordered_list_fix (list, 4);
//  list = insert_into_ordered_list_fix (list, 5);
//  list = insert_into_ordered_list_fix (list, 3);
//  list = insert_into_ordered_list_fix (list, 9);
//
//  print_list (list);

  // e 14

//  struct node *list = NULL;
//
//  list = add_to_list (list, 3);
//  list = add_to_list (list, 2);
//  list = add_to_list (list, 1);
//  list = add_to_list (list, 3);
//  list = add_to_list (list, 3);
//  list = add_to_list (list, 6);
//  list = add_to_list (list, 3);
//
//  print_list (list);
//
//  delete_from_list_e_14 (&list, 1);
//
//  print_list (list);

  // e 15

//  printf ("Answer: %d\n", f1(f2));

  // e 16

//  printf ("sum (power, 1, 4): %d\n", sum (power, 1, 4));

  // e 17

//  srand (time(NULL));
//
//  int a[100];
//
//  for (int *p = a; p < a + 100; p++)
//  {
//    *p = rand() % 100;
//  }
//
//  for (int *p = a; p < a + 100; p++)
//  {
//    printf("%d ", *p);
//  }
//
//  printf ("\n--------------------\n");
//
//  qsort (&a[50], 50, sizeof a[0],compare);
//
//  for (int *p = a; p < a + 100; p++)
//  {
//    printf("%d ", *p);
//  }

  // e 18

//  srand (time (NULL));
//
//  struct part parts[10];
//
//  for (int i = 0; i < 10; i++)
//  {
//    int number = rand () % 9999;
//    char name[100];
//    sprintf (name, "part %d", number);
//    parts[i] = (struct part) {number, name, rand () % 10};
//  }
//
//  for (int i = 0; i < 10; i++)
//  {
//    printf ("part number: %d | name: %s | on_hand: %d\n", parts[i].number, parts[i].name, parts[i].on_hand);
//  }
//
//  printf ("--------------------------------------------------------------\n");
//
//  qsort (parts,10,sizeof (struct part),compare_parts);
//
//  for (int i = 0; i < 10; i++)
//  {
//    printf ("part number: %d | name: %s | on_hand: %d\n", parts[i].number, parts[i].name, parts[i].on_hand);
//  }
//
//  printf ("--------------------------------------------------------------\n");
//
//  qsort (parts,10,sizeof (struct part),compare_parts_desc);
//
//  for (int i = 0; i < 10; i++)
//  {
//    printf ("part number: %d | name: %s | on_hand: %d\n", parts[i].number, parts[i].name, parts[i].on_hand);
//  }

  // e 19

  char string[100];

#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"
  for (;;)
  {
    printf ("Please enter one of the following commands and press enter:\n");
    printf ("new, open, close, close all, save, save as, save all, print or exit.\n");

    read_line (string, 100);

    file_command (string);
  }
#pragma clang diagnostic pop

  return 0;
}
