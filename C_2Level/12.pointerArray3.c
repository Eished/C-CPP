#include <stdio.h>
#define M 5
#define N 3

// 行指针+列数
void fun(double *a[], int i) // 加括号：（指针）【列数】； 不加括号：指针数组 ；**a 指向指针的指针
{
  for (int j = 0; j < N; j++)
  {
    printf("%8.2lf", a[i][j]); // 首地址【行地址】【列地址】
  }
  printf("\n");
}

int main()
{
  double s[M][N] = {{1, 2, 3}, {4, 5, 6}}, *ps[M];
  for (int i = 0; i < M; i++)
  {
    printf("%p", &s[i]);
    ps[i] = s[i]; // 把二维数组每一行的[首地址]存到指针数组里面
    fun(ps, i);   // 传递指针数组及当前行
    // for (int j = 0; j < N; j++)
    // {
    //   printf("%8.2lf", ps[i][j]); // 首地址【行地址】【列地址】
    // }
    // printf("\n");
  }
}
