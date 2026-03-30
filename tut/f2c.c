#include <stdio.h>

/* make Fahrenheit-Celsius table
 * n-steps of 20F until 300F */

int main()
{
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;   /* lower limit */
  upper = 300; /* upper limit */
  step = 20;   /* step size */

  fahr = lower;
  printf("%3s %6s\n", "F", "C");
  while (fahr <= upper)
  {
    celsius = (5.0 / 9.0) * (fahr - 32.0);
    printf("%3.0f %6.1f\n", fahr, celsius); /* %d for var placement */
    fahr = fahr + step;
  }
}

/* NOTE:
 * %6d  ->  print decimal integer, 6 char wide
 * %6.2 ->  print floating point, 6 char wide + 2 fp
 * %o   ->  print octal
 * %x   ->  hex
 * %c   ->  char
 * %s   ->  string
 * %%   ->  % */

/* NOTE:
 * char ->single byte character
 * short -> short int
 * long -> long int
 * double -> 2x precision FP*/
