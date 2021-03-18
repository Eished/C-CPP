#include <stdio.h>
int func(int n)
{
  int r;
  if (n < 0)
    printf("data error\n");
  else if (n == 0 | n == 1)
    r = 1;
  else
    r = n * func(n - 1);
  return r;
}
int main()
{
  int n;
  printf("pLease input n\n");
  scanf("%d", &n);
  int result = func(n);
  printf("result = %d\n", result);
  return 0;
}
