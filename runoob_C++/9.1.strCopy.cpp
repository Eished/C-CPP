#include <iostream>

using namespace std;

class stud
{
public:
  char a[10] = "8999";
};
int main()
{
  stud s;
  char b[10] = "234";
  cin >> b;
  strcpy_s(s.a, b);
  strcmp(s.a, b);
  cout << s.a << strcmp(s.a, b) << endl;
  return 0;
}