#include <stdio.h>
#include <stdlib.h>
#define C 1
int main()
{
  int c = 2;
  switch (c)
  {
  case 0 + 1 + C:
    putchar('1');
    break; // 只跳出switch
  case 'B':
    putchar('B');

  default:
    putchar('d');
  }
  putchar('*');
  return 0;
}