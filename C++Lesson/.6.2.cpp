#include <iostream>
using namespace std;
class A
{
  int n;

public:
  ~A()
  {
    cout << "Aĉĉ" << endl;
  }
  virtual void f() = 0;
};
class D : public A
{
public:
  ~D()
  {
    cout << "Dĉĉ" << endl;
  }
  virtual void f()
  {
    cout << "D::f" << endl;
  }
};
int main()
{
  A *a;
  D q;
  a = &q;
  a->f();
  return 0;
}