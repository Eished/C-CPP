#include <stdio.h>

int fac(int n)
{
  int t;
  if (n == 1 || n == 0)
    return 1;
  else
  {
    t = n * fac(n - 1);
    return t;
  }
}
int main()
{
  int m, y;
  scanf("%d", &m);
  if (m < 0)
    printf("Input Err!");
  else
  {
    y = fac(m);
    printf("%d!=%d", m, y);
  }
}
