//
// Created by martin on 13/11/2021.
//

#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <malloc.h>
#include "functions.h"

double round_nearest (double x)
{
  return x < 0.0 ? ceil (x - 0.05) : floor (x + 0.5);
}

double round_nearest_n (double x, int n)
{

  x *= pow (10, n);
  x /= pow (10, n);

  return x < 0.0 ?
         ceil (x * pow (10, n) - 0.05) / pow (10, n) :
         floor (x * pow (10, n) + 0.5) / pow (10, n);
}

bool check_c_identifier (char *string)
{
  char *p = string;

  if (!isalpha (*p) && *p++ != '_')
    return false;

  while (*p != '\0')
  {
    if (!isalnum (*p) && *p != '_')
      return false;
    p++;
  }

  return true;
}

long int is_valid_hex_decimal (char *hex_string)
{

  long int return_value = 0;
  char *p = hex_string;

  while (*p != '\0')
  {
    if (!isxdigit (*p))
      return -1;
    p++;
  }

  sscanf (hex_string, "%lx", &return_value);

  return return_value;
}

int numchar (const char *s, char ch)
{
  int count = 0;

  while (true)
  {
    s = strchr (s, ch);
    if (s == NULL)
      break;
    count++;
    s++;
  }

  return count;
}

char *my_strdup (char *s)
{
  size_t len = strlen (s) + 1;

  char *copy = malloc(len);

  strcpy (copy, s);

  return copy;
}

bool my_stricmp (char *s1, char *s2)
{

  if (strlen (s1) != strlen (s2))
    return false;

  for (int i = 0; s1[i] != '\0'; i++)
  {
    if (tolower (s1[i]) != tolower (s2[i]))
    return false;
  }
  return true;
}

char *my_strlwr (char *s)
{

  for (char *p = s; *p != '\0'; p++)
  {
    if (isupper (*p))
      *p = (char) tolower (*p);
  }

  return s;
}

char *my_strrev (char *s)
{
  size_t len = strlen (s);

  char *start = s;
  char *end = s + len - 1;

  while (start < end)
  {
    char tmp = *start;
    *start = *end;
    *end = tmp;
    start++;
    end--;
  }

  return s;
}

char *my_strset (char *s, char ch)
{
  char *p = s;

  while (*p != '\0')
    *p++ = ch;

  return s;
}

int count_words(char *sentence)
{
  int count = 0;

  char *p = strtok (sentence, " ");

  if (p == NULL)
    return count;
  else
    count++;

  while (strtok (NULL, " ") != NULL)
    count++;

  return count;
}