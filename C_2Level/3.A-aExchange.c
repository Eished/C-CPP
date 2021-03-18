#include <stdio.h>
int main()
{
  char c;                         //定义一个字符型变量
  while ((c = getchar()) != '\n') //没有读入字符没有到回车时候转换
  {
    if (c >= 'a' && c <= 'z')
    {
      c = c - 'a' + 'A'; //或者直接写c=c-32
      putchar(c);        //输出字符c
    }
  }
  putchar('\n');
}