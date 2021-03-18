#include <stdio.h>
union data //struct
{
  int a;  // 4字节
  char b; // 1字节,填充三字节
  int c;  // 偏移量为8字节, 结构体总大小12字节, 然后判断是不是最宽变量类型的整数倍
};
int main()
{
  union data data_1; // 初始化表只能有一个常量
  data_1.b = 'C';
  data_1.a = 10; // 共用内存，覆盖前面的成员
  printf("%d\n %d\n", data_1.b, data_1.a);
  return 0;
}