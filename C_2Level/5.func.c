char b()
{
  printf("bbbb");
}
#include <stdio.h>
double c()
{
  printf("ccc");
}

double d();

// 函数调用与声明
int main()
{
  double e();
  a();
  b();
  c();
  d();
  e();
}
int a()
{
  printf("aaaa");
}
// char a()
// {
//   printf("aaaa");
// }
// double a()
// {
//   printf("aaaa");
// }

double d()
{
  printf("dddd");
}
double e()
{
  printf("eee");
}
