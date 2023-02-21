#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int mbcheck (const char *s)
{
  int n;

  for (mblen (NULL, 0);; s += n)
    if ((n = mblen (s, MB_CUR_MAX)) <= 0)
      return n;
}

int main ()
{
//  setlocale (LC_ALL, "Shift-JIS");

  printf ("%d\n", mbcheck ((char[]) {'\x05', '\x87', '\x80', '\x36', '\xed', '\xaa'}));
  printf ("%d\n", mbcheck ((char[]) {'\x20', '\xe4', '\x50', '\x88', '\x3f'}));
  printf ("%d\n", mbcheck ((char[]) {'\xde', '\xad', '\xbe', '\xef'}));
  printf ("%d\n", mbcheck ((char[]) {'\x8a', '\x60', '\x92', '\x74', '\x41'}));

  setlocale (LC_ALL, ".utf8");
  setlocale (LC_ALL, "");
  printf ("LC_ALL: %s\n", setlocale (LC_ALL, NULL));
  printf ("LC_CTYPE: %s\n", setlocale (LC_CTYPE, NULL));

  printf ("d\xe9j\xe0 vu\n");
  printf ("C\xf4te d'Azur\n");
  printf ("cr\xe8me br\xfbl\xe9 e\n"); // need fix
  printf ("cr\xe9me fra\xee che\n"); // need fix
  printf ("Fahrvergn\xfcgen\n");
  printf ("t\xeate-\xe0-t\xeate\n");

//  printf ("d\xc3\xa9j\xc3\xa0 vu\n");
//  printf ("C\xc3\xb4te d'Azur\n");
//  printf ((char[]) {'c', 'r', '\xc3', '\xa8', 'm', 'e', ' ', 'b', 'r', '\xc3', '\xbb', 'l', '\xc3', '\xa9', 'e', '\n',
//                    '\0'});
//  printf ((char[]) {'c', 'r', '\xc3', '\xa8', 'm', 'e', ' ', 'f', 'r', 'a', '\xc3', '\xae', 'c', 'h', 'e', '\n', '\0'});
//  printf ("Fahrvergn\xc3\xbcgen\n");
//  printf ("t\xc3\xaate-\xc3\xa0-t\xc3\xaate\n");

  return 0;
}
