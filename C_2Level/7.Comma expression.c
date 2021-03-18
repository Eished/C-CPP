#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main()
{
  int a = 1, b = 1;
  a = ++a, a + 10, a * 10;
  printf("a=%d", a);
  b = (++b, b + 10, b * 10);
  printf("b=%d", b);
  return 0;
}