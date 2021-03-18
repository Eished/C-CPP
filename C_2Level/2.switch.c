#include <stdio.h>

int main()
{
  int i = 10, f;
  scanf("%d", &f);
  switch (i / f)
  {
  case 2:
    printf("2");
  case 5:
    printf("5");
  case 10:
    printf("10");
    break;
  default:
    printf("Null");
  }
  return 0;
}
