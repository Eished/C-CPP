#include <stdlib.h>
void StraightInsertSort(List R, int n)
{
  int i, j;
  for (i = 2; i <= n; i++) //n 为表长,从第二个记录进行插入
  {
    R[0] = R[i]; //第 i 个记录赋值为岗哨
    j = i - 1;
    while (R[0].key < R[j].key) //与岗哨比较,直至键值不大于岗哨值
    {
      R[j + 1] = R[j]; //将第 j 个记录赋值给第 j+1 个记录
      j--;
    }
    R[j + 1] = R[0]; //将第 i 个记录插入到序列中
  }
}