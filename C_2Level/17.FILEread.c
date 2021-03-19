#include <stdio.h>
#include <stdlib.h>
int main(void)
{
  FILE *fp;
  char ch;
  if ((fp = fopen("123", "r")) == NULL)
  {
    printf("Can't Open File\n");
    exit(0); // 终止程序
  }
  ch = getc(fp); // 接收一个字符
  while (ch != EOF)
  {
    putchar(ch);
    ch = getc(fp);
    fclose(fp);
  }
}
