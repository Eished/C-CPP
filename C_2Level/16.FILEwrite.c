#include <stdio.h>
#include <stdlib.h>
int main(void)
{
  FILE *fp;
  char ch, fileName[10];
  scanf("%s", fileName);
  if ((fp = fopen(fileName, "w")) == NULL)
  {
    printf("Can't Open File\n");
    exit(0); // 终止程序
  }
  ch = getchar(); // 接收执行scanf语句时最后输入的回车符
  ch = getchar(); // 接收输入的第一个字符
  while (ch != '#')
  {
    fputc(ch, fp);
    putchar(ch);
    ch = getchar();
    fclose(fp);
  }
}
