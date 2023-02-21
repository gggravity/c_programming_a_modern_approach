#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define pf(x) printf(#x ": %d\n", x)
#define pfl(x) printf(#x ": %ld\n", x)
#define pfll(x) printf(#x ": %lld\n", x)

int max_int (int n, ...);
int max_int_new (int a, ...);

void my_printf (char *format_string, ...);

void my_printf2 (char *format_string, ...);

void display (int n, ...);

char *vstrcat (const char *first, ...);

char *max_pair (int num_parts, ...);

time_t get_time (int year);

int main ()
{
//  pf(max_int (4, 1, 2, 33, 4, 44));
//  pf(max_int_new (1, 2, 33, 4, 3, 4, 5, 44, 3, 0));
//
//  my_printf ("a:%d b:%d %f c:%d\n", 12, 2, 3);
//
//  my_printf2 ("a:%d b:%s c:%d\n", 12, "string", 3);
//
//  display (4, "Special", "Agent", "Dale", "Cooper");

//  char *p = vstrcat ("Special", "Agent", "Dale", "Cooper", NULL);
//
//  printf ("%s", p);

//  char *p = max_pair (5,
//                      180, "Seinfeld",
//                      180, "I Love Lucy",
//                      39, "The Honeymooners",
//                      210, "All in the Family",
//                      86, "The Sopranos"
//  );
//
//  printf ("%s", p);

//  char *string = "123456789 some string";
//  char *p = string;
//  long value;
//
//  value = strtol (p, &p, 10);
//
//  printf ("long extracted from string: %ld\n", value);
//  printf ("the non digit part of the string: '%s'\n", p);
//
//  int a[] = {7, 11, 15, 19};

//  srand (time (NULL));

//  for (int i = 0; i < 10; i++)
//  {
//    int n = rand() % 4;
//    printf ("%d ", a[n]);
//  }

//  for (int i = 0; i < 10; i++)
//  {
//    double d = rand() / (double)(RAND_MAX + 1);
//    printf ("%.4f\n", d);
//  }

//  char *str = "123456";
//
//  int test_A1 = atoi (str);
//  pf(test_A1);
//
//  long test_B1 = atol (str);
//  pfl(test_B1);
//
//  long long test_C1 = atoll (str);
//  pfll(test_C1);
//
//  printf ("--------------------------\n");
//
//  int test_A2 = atol (str);
//  pf(test_A2);
//
//  long test_B2 = strtol (str, NULL, 10);
//  pfl(test_B2);
//
//  long long test_C2 = strtoll (str, NULL, 10);
//  pfll(test_C2);

//  time_t t = get_time (2000);
//
//  printf ("time: %s\n", ctime(&t));


  time_t current = time(NULL);
  struct tm *ptr = localtime(&current);
  char time_string[80];

  strftime(time_string, 80, "%Y-%j", ptr);
  printf("time: %s\n", time_string );

  strftime(time_string, 80, "%Y %U %w", ptr);
  printf("time: %s\n", time_string );

  strftime(time_string, 80, "%Y-%m-%d %H:%M:%S", ptr);
  printf("time: %s\n", time_string );


  return 0;
}

time_t get_time (int year)
{
  struct tm t;
  t.tm_sec = 0;
  t.tm_min = 0;
  t.tm_hour = 12;
  t.tm_mon = 0;
  t.tm_mday = 1;
  t.tm_year = year - 1900; // years since 1900
  t.tm_isdst = -1;

  time_t return_time = mktime (&t);

  return return_time;
}

char *max_pair (int num_parts, ...)
{
  va_list ap;

  va_start(ap, num_parts);

  int longest = INT_MIN, length;
  char *title, *longest_title;

  for (int i = 0; i < num_parts; i++)
  {
    length = va_arg(ap, int);
    title = va_arg(ap, char *);
    if (length > longest)
    {
      longest = length;
      longest_title = title;
    }
  }

  return longest_title;
}

char *vstrcat (const char *first, ...)
{
  size_t len = strlen (first);
  va_list ap;
  va_start(ap, first);

  char *p;
  while ((p = va_arg(ap, char *)) != NULL)
  {
    len += strlen (p);
  }

  char *return_string = malloc (len);
  if (return_string == NULL)
  {
    va_end(ap);
    return NULL;
  }

  va_end(ap);

  strcpy (return_string, first);

  va_start(ap, first);

  while ((p = va_arg(ap, char *)) != NULL)
  {
    strcat (return_string, p);
  }

  va_end(ap);

  return return_string;
}

void display (int n, ...)
{
  va_list ap;
  va_start(ap, n);

  for (int i = 0; i < n; i++)
  {
    char *p = va_arg(ap, char *);
    if (i != n - 1)
      printf ("%s ", p);
    else
      printf ("%s", p);
  }

  va_end(ap);
}

void my_printf2 (char *format_string, ...)
{
  va_list ap;
  char str[100];
  va_start(ap, format_string);

  for (int i = 0; format_string[i] != '\0'; i++)
  {
    if (format_string[i] != '%' && format_string[i - 1] != '%')
      putchar (format_string[i]);
    else if (format_string[i + 1] == 'd')
    {
      int val = va_arg(ap, int);

      sprintf (str, "%d", val);
      for (int j = 0; str[j] != '\0'; j++)
        putchar (str[j]);
      i++;
    }
    else if (format_string[i + 1] == 's')
    {
      char *p = va_arg(ap, char *);

      for (; *p != '\0'; p++)
        putchar (*p);
      i++;
    }
  }
  va_end(ap);

}

void my_printf (char *format_string, ...)
{
  va_list ap;

  va_start(ap, format_string);

  for (int i = 0; format_string[i] != '\0'; i++)
  {
    if (format_string[i] != '%' && format_string[i - 1] != '%')
      putchar (format_string[i]);
    else if (format_string[i + 1] == 'd')
    {
      int val = va_arg(ap, int);
      char str[10];
      sprintf (str, "%d", val);
      for (int j = 0; str[j] != '\0'; j++)
        putchar (str[j]);
      i++;
    }
  }
  va_end(ap);

}

int max_int_new (int a, ...)
{
  va_list ap;
  int current = INT_MIN;

  va_start(ap, a);
  int largest = a;

  for (int i = 1; current != 0; i++)
  {
    current = va_arg(ap, int);
    if (current > largest)
      largest = current;
  }
  va_end(ap);

  return largest;
}
int max_int (int n, ...)
{
  va_list ap;
  int i, current, largest;

  va_start(ap, n);
  largest = va_arg(ap, int);

  for (i = 1; i < n; i++)
  {
    current = va_arg(ap, int);
    if (current > largest)
      largest = current;
  }
  va_end(ap);

  return largest;
}
