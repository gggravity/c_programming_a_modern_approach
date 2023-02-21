#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

int read_line (char str[], int n)
{
  int ch, i = 1;

  while ((ch = getchar ()) == ' ');
  str[0] = (char) ch;

  while ((ch = getchar ()) != '\n' && i < n)
  {
    if (isspace (ch))
      break;
    str[i++] = (char) ch;
  }
  str[i] = '\n';
  str[i + 1] = '\0';

  return i;
}
void capitalize_array (int n, char str[n]);
void capitalize_pointer (int n, char str[n]);
void censor (char string[], int n);
char *duplicate (const char *old, char *new);
int str_cmp (char *s, char *t);
void get_extension (const char *file_name, char *extension);
void build_index_url (const char *domain, char *index_url);
int f (char *s, char *t);
int count_spaces (const char *s);
int count_spaces_new (const char *s);
bool test_extension (const char *file_name, const char *extension);
void remove_filename(char *url);

int main ()
{
  // e 1

//  printf ("%c", '\n');
//  printf ("%c", "\n"); // wrong not a char
//  printf ("%s", '\n'); // need string not char
//  printf ("%s", "\n");
//  printf ('\n'); // wrong, printf require a c_string
//  printf ("\n");
//  putchar ('\n');
//  putchar ("\n"); // wrong not a char
//  puts('\n'); // not a c_string
//  puts("\n");
//  puts("");

  // e 2

//  char *p = "abc";
//
//  printf("e2a: ");
////  putchar(p); // p is a pointer need int
//
//  printf("\ne2b: ");
//  putchar(*p); // prints a, first element int the characters array.
//
//  printf("\ne2c: ");
//  puts(p); // prints abc + newline (puts append a new line);
//
//  printf("\ne2d: ");
////  puts(*p); // p point to a = char, need char *

  // e 3

//  // 12abc34 56def78
//
//  int i, j;
//  char s[100];
//
//  scanf ("%d%s%d", &i, s, &j);
//
//  printf("%d %s %d", i, s, j); // abc34 are stored as a c_string.

  // e 4
//
//  char line[10];
//
//  read_line (line, 10);
//
//  printf ("%s", line);

  // e 5

//  char a[] = "sfjsdk34fd3dasklhjgh432!!";
//
//  printf ("%s\n", a);
//
//  capitalize_array (sizeof a / sizeof a[0], a);
//  printf ("%s\n", a);
//
//  capitalize_pointer(sizeof a / sizeof a[0], a);
//  printf ("%s\n", a);

  // e 6

//  char s[] = "food fool";
//
//  censor (s, sizeof s / sizeof s[0]);
//
//  printf ("%s\n", s);

  // e 7

//  char str1[] = "testing 123 testing 123";
//
//  *str1 = 0;
//  printf ("str1: %s\n", str1);
//
//  char str2[] = "testing 123 testing 123";
//  str2[0] = '\0';
//  printf ("str2: %s\n", str2);
//
//  char str3[] = "testing 123 testing 123";
//  strcpy (str3, "");
//  printf ("str3: %s\n", str3);
//
//  char str4[] = "testing 123 testing 123";
//  strcat (str4, "");
//  printf ("str4: %s\n", str4);

  // e 8

//  char str[] = "something and something longer";

//  strcpy (str, "tire-bouchon"); // need to be < str[]
//  printf ("%s\n", str);

//  strcpy (&str[4], "d-or-wi"); // source is copied to position 4 and NULL \0 is inserted after source.
//  printf ("%s\n", str);

//  strcat(str, "red?"); // source inserted after str.
//  printf ("%s\n", str);

  // e 9

//  char s1[] = "source inserted";
//  char s2[100];
//
//  strcpy(s1, "computer");
//  printf ("s1: %s\n", s1);
//
//  strcpy(s2, "science");
//  printf ("s2: %s\n", s2);
//
//  if (strcmp(s1, s2) < 0)
//    strcat(s1, s2);
//  else
//    strcat(s2, s1);
//
//  printf ("s1: %s\n", s1);
//  printf ("s2: %s\n", s2);
//
//  s1[strlen(s1) - 6] = '\0';
//
//  printf ("s1: %s\n", s1);

  // e 10

//  char s1[] = "source inserted";
//  char s2[100];
//
//  char *s3 = duplicate (s1, s2);
//
//  printf ("s1: %s\n", s1);
//  printf ("s1: '%s' s2: '%s' s3: '%s'\n", s1, s2, s3);
//  printf ("s1: '%p' s2: '%p' s3: '%p'\n", s1, s2, s3);
//
//  s3[0] = 'X';
//  s3 = "bla bla";
//
//  printf ("s1: '%s' s2: '%s' s3: '%s'\n", s1, s2, s3);
//  printf ("s1: '%p' s2: '%p' s3: '%p'\n", s1, s2, s3);

  // e 11

//  char s1[] = "bla bla";
//  char s2[] = "bla bla";
//  char s3[] = "bla blA";
//
//  printf ("%d\n", str_cmp (s1, s2));
//  printf ("%d\n", str_cmp (s1, s3));

  // e 12

//  char fn[] = "memo.txt";
//  char ext[3];
//
//  get_extension (fn, ext);
//
//  printf ("%s\n", ext);

  // e 13

//  char dom[] = "knking.com";
//  char url[100];
//
//  build_index_url (dom, url);
//
//  printf ("dom: %s\nurl: %s", dom, url);

  // e 14

//  char s[] = "Hsjodi", *p;
//
//  for (p = s; *p; p++)
//    --*p; //
//  puts (s);

  // e 15

//  printf ("%d\n", f ("abcd", "babc")); // how long a string starting at index 0 in s is found in t.
//  printf ("%d\n", f ("abcd", "bcdacbddef"));

  // e 16

//  char message[] = "Der var engang en mand, han boede i en spand. Og spanden var af ler, og konen vasked bleer, og drengen var barber, og tante spillede klaver - nu kan jeg ikke mer..";
//
//  printf ("%s\n", message);
//  printf ("count_spaces1: %d\n", count_spaces (message));
//  printf ("count_spaces2: %d\n", count_spaces_new (message));

  // e 17
//
//  printf_s ("%s", test_extension ("memo.JPEG", "jpeg") ? "true" : "false");

  // e 18

  char url[] = "http://www.knking.com/index.html";

  remove_filename (url);

  printf ("%s", url);

  return 0;
}

void remove_filename(char *url)
{
  char *p = url;

  while (*p++);

  while (--p > url)
    if (*p == '/')
    {
      *p = '\0';
      break;
    }
}

bool test_extension (const char *file_name, const char *extension)
{
  size_t len_ext = strlen (extension);
  size_t len_file = strlen (file_name);
  char ext[len_ext];
  char file[len_ext];

  char *p1 = (char *) file_name;
  char *p2 = file;

  while ((*p2++ = tolower (*p1++)));

  p1 = (char *) extension;
  p2 = ext;

  while ((*p2++ = tolower (*p1++)));

  if (strcmp (&file[len_file - len_ext], ext) == 0)
    return true;

  return false;
}

int count_spaces_new (const char *s)
{
  int count = 0;

  while (*s++)
    if (*s == ' ')
      count++;

  return count;
}

int count_spaces (const char *s)
{
  int count = 0;

  for (; *s != '\0'; s++)
    if (*s == ' ')
      count++;

  return count;
}

int f (char *s, char *t)
{
  char *p1, *p2;

  for (p1 = s; *p1; p1++)
  {
    for (p2 = t; *p2; p2++)
    {
      if (*p1 == *p2)
        break;
    }
    if (*p2 == '\0')
      break;
  }

  return p1 - s;
}

void build_index_url (const char *domain, char *index_url)
{
  strcpy (index_url, "http://www.");
  strcat (index_url, domain);
  strcat (index_url, "/index.html");
}

void get_extension (const char *file_name, char *extension)
{
  int index = 0;
  for (int i = 0; file_name[i] != '\0'; i++)
  {
    if (file_name[i] == '.')
      index = i;
  }
  strcpy (extension, &file_name[index + 1]);
}

int str_cmp (char *s, char *t)
{

  for (; *s == *t; s++, t++)
  {
    if (*s == '\0')
      return 0;
  }

  return *s - *t;
}

char *duplicate (const char *old, char *new)
{
  strcpy (new, old);
  return new;
}

void censor (char string[], int n)
{
  for (char *p = string; p < string + n; p++)
  {
    if (*p == 'f' && *(p + 1) == 'o' && *(p + 1) == *(p + 2))
      *p = *(p + 1) = *(p + 2) = 'x';
  }
}

void capitalize_array (int n, char str[n])
{
  for (int i = 0; str[i] != '\0'; ++i)
    str[i] = (char) toupper ((int) str[i]);
}

void capitalize_pointer (int n, char str[n])
{
  for (char *p = str; *p != '\0'; p++)
    *p = (char) toupper ((int) *p);
}