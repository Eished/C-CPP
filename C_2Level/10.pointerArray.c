#include <stdio.h>
#define M 3
int main()
{
  int *p, a[M], i;
  for (p = a; p - a < M; p++)
  {
    scanf("%d", p);
    printf("%p，%p\n", a, p); // a为数组首地址 p为数组首地址
  }
  p -= M; // 重置指针起始位置
  for (i = 0; i < M; i++)
  {
    printf("%d，%d，%d\n", p[i], *(a + i), *(p + i)); // 通过指针获取数组值 数组和指针操作相同； a 是常量，p 是变量
  }
}