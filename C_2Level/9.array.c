#include <stdio.h>
#define M 30
int main()
{
  int s[M], i, k = 1;
  for (i = 0; i < M; i++)
  {
    s[i] = k;
    k += 2;
  }
  printf("\nSequence Output: \n");
  for (i = 0; i < M; i++)
  {
    printf("%4d", s[i]);
    if ((i + 1) % 10 == 0)
      printf("\n");
  }
  printf("\ninvert Output: \n");
  for (i = M - 1; i >= 0; i--)
  {
    printf("%4d", s[i]);
    if (i % 10 == 0)
      printf("\n");
  }
  printf("\n");
}