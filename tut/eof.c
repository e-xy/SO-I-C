#include <stdio.h>

/*
 * count characters in file and notify EOF
 */

int main()
{
  int end_cond;
  int char_cnt = 0;
  printf("%s\n", "EOF values:");
  while (end_cond = (getchar() != EOF))
  {
    printf("%d", end_cond);
    char_cnt++;
  }
  printf("%d\n", end_cond);
  printf("%s %d %s\n", "Program found: ", char_cnt, "characters before EOF :p");
  return getchar() != EOF;
}
