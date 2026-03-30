#include <stdio.h>

int main()
{
  int c;                         // NOTE: we need an int to store EOF value
  while ((c = getchar()) != EOF) // NOTE: != takes precedence over =
  {
    putchar(c);
  }
  // printf("%d", getchar() != EOF);
  return getchar() != EOF;
}
