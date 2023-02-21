#include <stdio.h>

struct dialing_code {
    char *country;
    int code;
};

const struct dialing_code country_code[] =
    {
        {"Argentina", 54}, {"Brazil", 55},
        {"China", 86}, {"Cong, Dem. Rep. of", 243},
        {"Ethiopia", 251}, {"Germany", 49},
        {"Bangladesh", 880}, {"Burma (Myanmar)", 95},
        {"Colombia", 57}, {"Egypt", 20},
        {"France", 33}, {"India", 91},
        {"Indonesia", 62}, {"Italy", 39},
        {"Mexico", 52}, {"Pakistan", 92},
        {"Poland", 48}, {"South Africa", 27},
        {"Spain", 34}, {"Thailand", 66},
        {"Ukraine", 380}, {"United States", 1},
        {"Iran", 98}, {"Japan", 81},
        {"Nigeria", 234}, {"Philippines", 63},
        {"Russia", 7}, {"South Korea", 82},
        {"Sudan", 249}, {"Turkey", 90},
        {"United Kingdom", 44}, {"Vietnam", 84},
    };

int main ()
{
  int dialing_code, index_of_dialing_code;

  for (;;)
  {
    printf ("Please enter international dialing code:");
    scanf ("%d", &dialing_code);

    if (dialing_code == 0)
      break;

    for (int i = 0; i < sizeof country_code / sizeof country_code[0]; i++)
    {
      if (country_code[i].code == dialing_code)
      {
        index_of_dialing_code = i;
        break;
      }
    }

    printf ("The country is: %s\n", country_code[index_of_dialing_code].country);

  }
  return 0;
}
