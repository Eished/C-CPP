#include <iostream>
#include <string>
using namespace std;
static int glos = 100;
void f()
{
  int a = 1;
  static int fs = 1;
  cout << "��f��:a(�Զ�����)=" << a << " fs(��̬)" << fs << " glos(��̬)=" << glos << endl;
  a += 2;
  fs += 2;
  glos += 10;
  cout << "��f��:a(�Զ�����)=" << a << " fs(��̬)" << fs << " glos(��̬)=" << glos << endl
       << endl;
}
int main()
{
  static int ms = 10;
  for (int i = 1; i <= 3; i++)
    f();
  cout << "ms=" << ms << endl;
  cout << "glos=" << glos << endl;
  return 0;
}