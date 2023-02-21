//
// Created by martin on 28/10/2021.
//

#include <stdbool.h>
#include "functions.h"

int *my_malloc (int n)
{
  int *p = malloc (n);
  if (p == NULL)
  {
    printf ("Allocation failed.\n");
    exit (EXIT_FAILURE);
  }
  else
  {
    printf ("Allocation succeed.\n");
  }
  return p;
}

char *duplicate (char *str)
{
  char *new_str;

  new_str = malloc (sizeof str);

  if (new_str == NULL)
  {
    printf ("Allocation failed.\n");
    exit (EXIT_FAILURE);
  }

  strcpy (new_str, str);

  return new_str;
}

int *create_array (int n, int initial_value)
{
  int *array = malloc (sizeof (int) * n);

  if (array == NULL)
  {
    printf ("Allocation failed.\n");
    exit (EXIT_FAILURE);
  }

  for (int *p_int = array; p_int < array + n; p_int++)
  {
    *p_int = initial_value;
  }

  return array;
}

struct node *add_to_list (struct node *list, int n)
{
  struct node *new_node;

  new_node = malloc (sizeof (struct node));

  if (new_node == NULL)
  {
    printf ("Error: malloc failed to add_to_list\n");
    exit (EXIT_FAILURE);
  }
  new_node->value = n;
  new_node->next = list;

  return new_node;
}

void print_list (struct node *list)
{
  if (is_empty (list))
    printf ("can't print an empty list.\n");
  else
  {
    for (struct node *p = list; p != NULL; p = p->next)
      printf ("value: %d ", p->value);
    printf ("\n");
  }
}

struct node *delete_from_list (struct node *list, int n)
{
  struct node *cur, *prev;

  for (cur = list, prev = NULL;
       cur != NULL && cur->value != n;
       prev = cur, cur = cur->next);

  if (cur == NULL)
    return list;
  if (prev == NULL)
    list = list->next;
  else
    prev->next = cur->next;
  free (cur);

  return list;
}

struct node *delete_from_list_new (struct node **list, int n)
{
  struct node *item = *list;

  while (item)
  {
    printf ("%d\n", item->value);
    if (item->value == n)
    {
      printf ("%d %d\n", (*list)->value, item->value);
      *list = item->next;
      free (item);
      break;
    }
    list = &item->next;
    item = item->next;
  }
  return *list;
}

void make_empty (struct node **list)
{
  while (!is_empty (*list))
    pop (list);
}

bool is_empty (struct node *list)
{
  return list == NULL ? true : false;
}

bool push (struct node **list, int i)
{
  struct node *new_node;

  new_node = malloc (sizeof (struct node));

  if (new_node == NULL)
  {
    printf ("Error: malloc failed to add_to_list\n");
    return false;
  }
  new_node->value = i;
  new_node->next = *list;
  *list = new_node;

  return true;
}

int pop (struct node **list)
{

  if (is_empty (*list))
  {
    printf ("list is empty\n");
    return -1;
  }

  struct node *p = *list;
  int pop_value;

  pop_value = (*list)->value;

  *list = (*list)->next;

  free (p);

  return pop_value;
}

void print_part (struct part p)
{
  printf ("Part number: %d\n", p.number);
  printf ("Part name: %s\n", p.name);
  printf ("Quantity on hand: %d\n", p.on_hand);
}

void print_part_new (struct part *p)
{
  printf ("Part number: %d\n", p->number);
  printf ("Part name: %s\n", p->name);
  printf ("Quantity on hand: %d\n", p->on_hand);
}

int count_occurrences (struct node *list, int n)
{
  int count = 0;

  while (list)
  {
    if (list->value == n)
      count++;
    list = list->next;
  }

  return count;
}

struct node *find_last (struct node *list, int n)
{
  struct node *p;

  while (list)
  {
    if (list->value == n)
      p = list;
    list = list->next;
  }

  return p;
}

struct node *insert_into_ordered_list (struct node *list, struct node *new_node)
{
  struct node *cur = list, *prev = NULL;
  while (cur->value <= new_node->value)
  {
    prev = cur;
    cur = cur->next;
  }
  prev->next = new_node;
  new_node->next = cur;

  return list;
}

struct node *insert_into_ordered_list_fix (struct node *list, int n)
{
  struct node *cur, *prev, *new_node;

  new_node = malloc (sizeof (struct node));
  if (new_node == NULL)
  {
    printf ("out of memory.");
    exit (EXIT_FAILURE);
  }

  new_node->value = n;

  for (cur = list, prev = NULL;
       cur != NULL && n > cur->value;
       prev = cur, cur = cur->next);

  new_node->next = cur;

  if (prev == NULL)
    list = new_node;
  else
    prev->next = new_node;

  return list;
}

struct node *delete_from_list_e_14 (struct node **list, int n)
{
  struct node *cur, *prev;

  for (cur = *list, prev = NULL;
       cur != NULL && cur->value != n;
       prev = cur, cur = cur->next);

  if (cur == NULL)
    return *list;
  if (prev == NULL)
    *list = (*list)->next;
  else
    prev->next = cur->next;
  free (cur);

  return *list;
}

int f1 (int (*f) (int))
{
  int n = 0;

  while ((*f) (n))
  {
    printf ("n: %d\n", n);
    printf ("(*f) (n): %d\n", (*f) (n));
    n++;
  }

  return n;
}

int f2 (int i)
{
  return i * i + i - 12;
}

int sum (int (*f) (int), int start, int end)
{
  int sum = 0;

  for (int i = start; i <= end; i++)
    sum += (*f) (i);

  return sum;
}

int power (int i)
{
  return i * i;
}

int compare (const void *p, const void *q)
{
  int *p1 = (int *) p;
  int *q1 = (int *) q;

  if (*p1 < *q1)
    return -1;
  else if (*p1 == *q1)
    return 0;
  else
    return 1;
}

int compare_parts (const void *p, const void *q)
{
  const struct part *p1 = p;
  const struct part *q1 = q;

  if (p1->number < q1->number)
    return -1;
  else if (p1->number == q1->number)
    return 0;
  else
    return 1;
}

int compare_parts_desc (const void *p, const void *q)
{
  const struct part *p1 = p;
  const struct part *q1 = q;

  if (p1->number < q1->number)
    return 1;
  else if (p1->number == q1->number)
    return 0;
  else
    return -1;
}

void new_cmd (void)
{
  printf ("calling new command.\n");
}

void open_cmd (void)
{
  printf ("calling open command.\n");
}

void close_cmd (void)
{
  printf ("calling close command.\n");
}

void close_all_cmd (void)
{
  printf ("calling close all command.\n");
}

void save_cmd (void)
{
  printf ("calling save command.\n");
}

void save_as_cmd (void)
{
  printf ("calling save as command.\n");
}

void save_all_cmd (void)
{
  printf ("calling save all command.\n");
}

void print_cmd (void)
{
  printf ("calling print command.\n");
}

void exit_cmd (void)
{
  printf ("calling exit command.\n");
  exit (EXIT_SUCCESS);
}

void file_command (const char *command)
{

  struct {
      char *cmd_name;
      void (*cmd_pointers) (void);

  } file_cmd[] =
      {
          {"new", new_cmd},
          {"open", open_cmd},
          {"close", close_cmd},
          {"close all", close_all_cmd},
          {"save", save_cmd},
          {"save as", save_as_cmd},
          {"save all", save_all_cmd},
          {"print", print_cmd},
          {"exit", exit_cmd}
      };

  for (int i = 0; i < sizeof file_cmd / sizeof file_cmd[0]; i++)
  {

    if (strcmp (command, file_cmd[i].cmd_name) == 0)
      file_cmd[i].cmd_pointers ();
  }
}

int read_line (char str[], int n)
{
  int ch, i = 0;

  while ((ch = getchar ()) != '\n')
    if (i < n)
      str[i++] = (char) ch;
  str[i] = '\0';

  return i;
}










