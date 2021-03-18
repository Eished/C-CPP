#include <stdlib.h>
// 翻转矩阵
int A[10][10];
void MM(int A[n][n])
{
  int i, j, temp;
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < i; j++)
    {
      temp = A[i][j];
      A[i][j] = A[j][i];
      A[j][i] = temp;
    }
  }
}