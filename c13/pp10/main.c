#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

void reverse_name (char *name);

int main ()
{
  char first_name[100];
  char last_name[100];
  char name[100];

  printf ("Enter a name:");
  scanf ("%s %s", first_name, last_name);

  strcpy (name, first_name);
  strcat (name, " ");
  strcat (name, last_name);

  reverse_name (name);

  return 0;
}

void reverse_name (char *name)
{
  char *pnt_last_name = name;
  while (*pnt_last_name++ != ' ');

  printf ("%c", toupper (*pnt_last_name++));

  char *pnt_lower = pnt_last_name;

  while (*pnt_lower++)
    *pnt_lower = (char) tolower (*pnt_lower);

  printf ("%s, %c.", pnt_last_name, toupper (name[0]));

}