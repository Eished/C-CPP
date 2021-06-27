#include <ctime>
#include <iostream>

using namespace std;

int main(void)
{
  // 基于当前系统的当前日期/时间
  time_t now = time(NULL);
  // 把 now 转换为字符串形式
  char *str = ctime(&now);
  cout << "本地日期和时间：" << str << endl;
  // 把 now 转换为 tm 结构
  tm *t = gmtime(&now);
  // 返回形式为：day month date hours:minutes:seconds year
  char *tt = asctime(t);
  cout << "UTC 日期和时间：" << tt << endl;
  return 0;
}