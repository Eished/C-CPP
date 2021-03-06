#include <stdio.h>
#define M 2
#define N 3

// 首地址+行数+列数
// void fun(double a[M][N])
// {
// }

// 首地址+列数
// void fun2(double a[][N])
// {
// }

// 行指针+列数
void fun(double (*a)[N])
{
  // printf("%8.2lf%8.2lf%8.2lf\n", (*a)[0], (*a)[1], (*a)[2]);                     // 取行地址值【列下标】
  printf("%8.2lf%8.2lf%8.2lf\n", (*(a + 1))[0], (*(a + 1))[1], (*(a + 1))[2]); // 取行地址值（行指针+位移）【列下标】  *优先级高于+
  // printf("%8.2lf%8.2lf%8.2lf\n", *(*a), *(*a + 1), *(*a + 2));                   // 取值（行指针地址+位移）
  printf("%8.2lf%8.2lf%8.2lf\n", *a[1], *(a[1] + 1), *(a[1] + 2));               // 取值（行指针【行下标】+位移）
  printf("%8.2lf%8.2lf%8.2lf\n", *(*(a + 1)), *(*(a + 1) + 1), *(*(a + 1) + 2)); // 取值（取行地址值（行指针+位移）+位移）

  printf("%p\n%p\n%p\n%p\n", (&a[0] + 1), (&a[0])[1], &a[1], (&a + 7));                                                                     // 相同地址
  printf("%8.2lf%8.2lf%8.2lf%8.2lf%8.2lf%8.2lf\n", *((&a[0] + 1)[0]), *((&a[0])[1]), *(*(&a[1])), *(&a[1][0]), *(&a + 7), *(*(&a[0] + 1))); // *逆运算&

  *a[0] = *(*(a + 0)) = **a; // * 等于 []
  *a[1] = *(*(a + 1));       // 下标 等于 指针位移
  *(&a) = a;                 // * 逆运算 & 相互抵消; 由 * 等于 []，推出 [] 也和 & 相互抵消；
  printf("%d\n", *a[0] == *(*(a + 0)) == **a);

  *(*(&a[1])) = *(*(a + 1)) = *a[1];

  *(&a[1][0]) = *(*(&a[1])) = a[1][0] = *a[1];
  *((&a[0])[1]) = *(*(*(&a) + 1)) = *a[1];
  *((&a[0] + 1)[0]) = *(*(*(&a) + 1)) = *(*(a + 1)) = *a[1];
}

int main()
{
  double s[M][N] = {{1, 2, 3}, {4, 5, 6}};
  fun(s);
}
