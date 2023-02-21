#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

void avg_sum (const double a[], int n, double *avg, double *sum)
{
  int i;
  *sum = 0.0f;
  for (i = 0; i < n; i++)
    *sum += a[i];
  *avg = *sum / n;
}

void swap (int *p, int *q)
{
  int temp = *p;
  *p = *q;
  *q = temp;
}

void split_time (long total_sec, int *hr, int *min, int *sec)
{
  *hr = total_sec / (60 * 60);
  total_sec -= *hr * 60 * 60;
  *min = total_sec / 60;
  total_sec -= *min * 60;
  *sec = total_sec;
}

void find_two_largest (const int a[], int n, int *largest, int *second_largest)
{
  *largest = *second_largest = INT_MIN;

  for (int i = 0; i < n; i++)
  {
    if (a[i] > *largest)
      *largest = a[i];
    if (a[i] > *second_largest && a[i] < *largest)
      *second_largest = a[i];
  }
}

void find_two_largest_unique (const int a[], int n, int *largest, int *second_largest)
{
  *largest = *second_largest = INT_MIN;
  int index = 0;

  for (int i = 0; i < n; i++)
  {
    if (a[i] > *largest)
    {
      *largest = a[i];
      index = i;
    }
    if (a[i] > *second_largest && a[i] <= *largest && index != i)
      *second_largest = a[i];
  }
}

void split_date (int day_of_year, int year, int *month, int *day)
{
  bool leap_year = false;

  if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
    leap_year = true;

  int m[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  if (leap_year)
    m[1]++;

  int sum = 0, i = 0;
  while (sum < day_of_year && sum + m[i] < day_of_year)
    sum += m[i++];

  *month = i;
  *day = day_of_year - sum;
}

int *find_largest (int a[], int n)
{
  int largest = a[0];
  int *p;

  for (int i = 1; i < n; i++)
  {
    if (a[i] > largest)
    {
      largest = a[i];
      p = &a[i];
    }
  }

  return p;
}

int main ()
{
  int numbers[] = {1, 2, 6, 4, 9, 4, 24, 4};

  int *largest = find_largest (numbers,sizeof numbers/sizeof numbers[0]);

  printf ("The largest number is: %d", *largest);

//  int year = 2000, day_of_year = 100, months, day;
//
//  split_date (day_of_year, year, &months, &day);
//
//  printf ("its the %dth day of %dth month in the year %d.\n", day, months, year);


//  int largest, second_largest;
//
//  find_two_largest ((int[]) {6, 2, 7, 4, 5, 8, 7, 8, 4}, 9, &largest, &second_largest);
//  printf ("largest: %d, second_largest: %d\n", largest, second_largest);
//
//  find_two_largest_unique ((int[]) {6, 2, 7, 4, 5, 8, 7, 8, 4}, 9, &largest, &second_largest);
//  printf ("largest: %d, second_largest: %d\n", largest, second_largest);

//  int hours, minutes, seconds;
//  long time_since = 43384;
//
//  split_time (time_since, &hours, &minutes, &seconds);
//
//  printf ("%lds =  %dh %dm %ds\n", time_since, hours, minutes, seconds);
//
//  double average, sum;
//
//  avg_sum ((double[]) {1, 2, 3, 4, 5, 6, 7, 8, 9}, 9, &average, &sum);
//  printf ("average: %.2f, sum: %.2f\n", average, sum);
//
//  int i = 123, j = 321;
//
//  printf ("i:%d j:%d\n", i, j);
//  swap (&i, &j);
//  printf ("i:%d j:%d\n", i, j);

//  int i = 123;
//  int *p = &i;
//
//  printf ("*p: %s (%d)\n", *p == i ? "true" : "false", *p);
//  printf ("&p: %s (%d)\n", &p == i ? "true" : "false", &p);
//  printf ("*&p: %s (%d)\n", *&p == i ? "true" : "false", *&p);
//  printf ("&*p: %s (%d)\n", &*p == i ? "true" : "false", &*p);
//  printf ("*i: %s (%d)\n", *i == i ? "true" : "false", *i);
//  printf ("&i: %s (%d)\n", &i == i ? "true" : "false", &i);
//  printf ("*&i: %s (%d)\n", *&i == i ? "true" : "false", *&i);
//  printf ("&*i: %s (%d)\n", &*i == i ? "true" : "false", &*i);



  return 0;
}
