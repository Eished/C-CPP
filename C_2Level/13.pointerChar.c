#include <stdio.h>

int main()
{
  char *s;
  s = "good!";
  char s2[10];
  scanf("%s", s2);
  s2[0] = '?';
  printf("%s\n", s2);
  printf("%s", s);
}
