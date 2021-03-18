#include <stdio.h>
#define R 20        /*宏定义*/
#define M int main( /*宏定义*/
#define N(n) n * 10 /*宏定义*/
#define ADD(a, b) (a + b) /*宏定义 加括号提高计算优先级*/
int add(int a, int b) { return a + b; }
M)
{
  int a = R;
  printf("a=%d\n", a);
  printf("hello world\n");

  int b = N(a); // int b=a*10;
  printf("b=%d\n", b);

  int c = add(a, b); // 函数
  printf("c=%d\n", c);

  int d = ADD(a, b); // 宏函数替换
  printf("d=%d\n", d);

  int e = ADD(a, b) * ADD(a, b); // 预处理后 宏替换为：a+b*a+b。运算是编译时执行
  printf("e=%d\n", e);

  int f = ADD(10.5, 10);
  printf("f=%d\n", f);

  float h = ADD(10.5, 10); // 宏替换不考虑数据类型
  printf("h=%f\n", h);

  // 宏替换 条件编译

  return 0;
}