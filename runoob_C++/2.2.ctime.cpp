#include <stdio.h>
#include <time.h>

int main()
{
  time_t curtime = time(NULL);
  char str[26];
  ctime_s(str, sizeof str, &curtime);
  printf("当前时间 = %s", str);
  return (0);
}