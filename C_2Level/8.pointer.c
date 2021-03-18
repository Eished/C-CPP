#include <stdio.h>
int main()
{
  int a, b = 2, *p = NULL;
  a = 1;
  p = &a;
  *p = b;
  printf("%d,%d,%p,%p,%p", *p, a, &p, p, &a);
}