#include <iostream>
using namespace std;

int main()
{
  enum num
  {
    a = 1,
    b = 2
  } numA;
  numA = a;
  cout << numA << endl;
  return 0;
}