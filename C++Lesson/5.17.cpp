#include <iostream>
using namespace std;
class A //����
{
public:
  A()
  {
    i = 100;
    cout << "class A default construct function" << endl;
  }
  A(const A &s)
  {
    i = s.i;
    cout << "calss A copy construct funciton" << endl;
  }
  int getValue();
  void setValue(int);

private:
  int i;
};
int A::getValue()
{
  return i;
}
void A::setValue(int k)
{
  i = k;
}
class B : public A
{
private:
  float f;

public:
  B()
  {
    f = 20.1;
    cout << "class B default construct function" << endl;
  }
  B(const B &v) : A::A(v), f(v.f)
  {
    cout << "class B copy construct function" << endl;
  }
  float getValue();
  int getValue1()
  {
    return A::getValue();
  }
};
float B::getValue()
{
  return f;
}

int main()
{
  A a;
  B b;
  B bb(b); //������A ���ƹ��캯������B ��ֵ���캯��
  return 0;
}