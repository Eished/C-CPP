#include <stdio.h>
void swap(int, int); /*函数说明*/
int main()
{
  int x = 10, y = 20;
  printf("(1)x=%d y=%d\n", x, y);
  swap(x, y); //值传递
  printf("(4)x=%d y=%d\n", x, y);
}
void swap(int a, int b)
{
  int t;
  printf("(2)a=%d b=%d\n", a, b);
  t = a, a = b, b = t;
  printf("(3)a=%d b=%d\n", a, b);
}