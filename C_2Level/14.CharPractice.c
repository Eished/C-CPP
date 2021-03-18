#include <stdio.h>
#include <string.h>
void fun(char *w, int m)
{
  char *p1, *p2, s;
  p1 = w;
  p2 = w + m - 1; // *p2="G";
  while (p1 < p2)
  {
    s = *p1++;   // s="A"; 后++优先级低于= 低于* 加括号也不管用
    *p1 = *p2--; // *(p1+1)="G"; 先取值赋值，最后--
    *p2 = s;     // *(p2-1)="A";
  }              // AG...AG;
}
int main()
{
  char a[] = "ABCDEFG";
  fun(a, strlen(a));
  puts(a);
}
