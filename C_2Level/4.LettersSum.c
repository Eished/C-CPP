#include <stdio.h>
int main()
{
  int s = 0, b = 0, n = 0; //定义变量s为小写字母数量,b为大写字母数量,n数字
  char c;
  while ((c = getchar()) != '\n')
  {
    if (c >= 'a' && c <= 'z')
      s++;
    if (c >= 'A' && c <= 'Z')
      b++;
    if (c >= '0' && c <= '9')
      n++;
  }
  printf("%d,%d,%d", s, b, n);
}