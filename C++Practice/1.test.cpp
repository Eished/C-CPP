#include <iostream>
// #include <stdafx>
#include <assert.h>
#include <string.h>
using namespace std;
int main()
{
  char b[] = "asdfasdf";
  string c = b;
  float f = 1.232222222222222222;
  long double df = 1.232222222223333333333333333333;
  cout << c << "\n"
       << b << "\n"
       << df << "\n"
       << f << endl;
  assert(1 != 1);
}