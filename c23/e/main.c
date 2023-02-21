#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "functions.h"

typedef struct sentence sentence;
int main ()
{
//
//  printf ("1: %f\n", round_nearest (3.14159));
//  printf ("2: %f\n", round_nearest_n (3.14159, 3));
//
//#ifdef FP_FAST_FMA
//  printf("FP_FAST_FMA: true\n");
//#endif

//  char *strings[] = {"_c_identifier", "some_string", "some/string", "123some_string"};
//
//  size_t n = sizeof (strings)/ sizeof (strings[0]);
//
//  for (int i = 0; i < n; i++)
//    printf("%s: %s\n", strings[i], check_c_identifier (strings[i]) ? "true" : "false");
//
//  printf ("-------------------------\n");
//
//  for (char **p = strings; p < strings + n; p++)
//    printf("%s: %s\n", *p, check_c_identifier (*p) ? "true" : "false");


//  printf ("%ld\n", is_valid_hex_decimal ("ff"));
//  printf ("%ld\n", is_valid_hex_decimal ("123"));
//  printf ("%ld\n", is_valid_hex_decimal ("1FF0"));

  // 6

  // a: memmove, b: memmove, c: strncpy, d: memcpy

//  char *str = malloc(1000);
//  strcpy (str, "0dddiuououoddd898080");
//
//  char *start = str;
//  char *p = start + 1000;
//
//  while(p > start)
//  {
//    p = strrchr (str, 'd');
//    if (p == NULL)
//      break;
//    printf ("%c", *p);
//    p[0] = '\0';
//  }

//  printf ("numchar: %d\n", numchar ("0dddiuouoduoddd898080", 'd'));

  // e 9

//  char ch = 'b';
//
//  if (ch == 'a' || ch == 'b' || ch == 'c')
//    printf ("match\n");
//
//  if (strchr("abc", ch) != NULL)
//    printf ("match\n");

  // e 10

//  char *str = "foo";
//
//  if(strcmp (str, "foo") == 0 || strcmp (str, "bar") == 0 || strcmp (str, "baz") == 0)
//    printf ("match\n");
//
//  if(strstr("foo bar baz", str) != NULL)
//    printf ("match\n");

  // e 11

//  int n = 5;
//  char s[] = "der var en gang en mand.";
//  size_t len = strlen(s);
//  char *p = s + len - n;
////  memset (&s[len - n], '!', n);
//  memset (p, '!', n);
//  printf ("%s\n", s);

  // e 12

//  char string[] = "test string";
//
//  char * test_string = my_strdup (string);
//
//  printf("%s\n",test_string);
//
//  free (test_string);
//
//  char str1[] = "ABCDEFG";
//  char str2[] = "abcdefg";
//
//  printf("test: %s\n", my_stricmp (str1, str2) ? "true" : "false");
//
//  char test_c[] = "QweRtY";
//
//  printf ("%s\n", my_strlwr(test_c));
//
//  char test_d[] = "qwerty";
//
//  printf ("%s\n", my_strrev(test_d));
//
//  char test_e[] = "qwerty";
//
//  printf ("%s\n", my_strset(test_e, 'X'));

  // e 13

  char sentence[] = "der var en gang en mand som boet i en spand";

  printf ("count_words: %d\n", count_words (sentence));

  return 0;
}
