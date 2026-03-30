#include <stdio.h>

/* celsius -> fahr table w/ fp precision */

float fahr, cel;
int lower, upper, step;

/*
 * NOTE:
 * celsius 2 fahr calc
 * float c  <-  celsius
 * float f  ->  converted_fahr*/
float c2f(float c)
{
  float f = (9.0 / 5.0) * c + 32.0;
  return f;
}

int main()
{
  lower = 0;
  upper = 40;
  step = 1;

  // print out c2f table
  printf("%3s %6s\n", "C", "F");
  for (cel = lower; cel <= upper; cel += step)
  {
    fahr = c2f(cel);
    printf("%3.0f %6.2f\n", cel, fahr);
  }
  return 0;
}
