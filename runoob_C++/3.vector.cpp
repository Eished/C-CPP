#include <iostream>
#include <vector>

using namespace std;

class MyClass
{
public:
  MyClass();
  ~MyClass();
  void print(int);

private:
  static int a;
};
int MyClass::a = 0;
void MyClass::print(int c)
{
  cout << a++ + c << endl;
}
MyClass::MyClass()
{
}

MyClass::~MyClass()
{
}

int main()
{
  MyClass cla;
  vector<MyClass> arr;
  arr.push_back(cla);
  arr.push_back(cla);
  arr.push_back(cla);
  arr.push_back(cla);
  arr.push_back(cla);
  MyClass arr2[5];
  for (int i = 0; i < 5; ++i)
  {
    arr2[i] = cla;
    arr[i].print(1);
    arr2[i].print(2);
  }
}