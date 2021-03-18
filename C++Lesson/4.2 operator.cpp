#include <iostream>
using namespace std;
class myComplex //������
{
private:
  double real, imag; //������ʵ�����鲿
public:
  myComplex();
  myComplex(double r, double i);
  myComplex addCom(myComplex c);                                        //��Ա����, �����߶������������c���
  void outCom();                                                        //��Ա����, ��������߶�����й�����
  myComplex operator-(const myComplex &c);                              //��Ա ���غ���
  friend myComplex operator+(const myComplex &c1, const myComplex &c2); //��Ԫ ���غ���
  friend myComplex operator-(const myComplex &c1, const myComplex &c2); //��Ԫ ���غ���
  friend myComplex operator-(const myComplex &c1, double r);            //��Ԫ ���غ���
  friend myComplex operator-(double r, const myComplex &c1);            //��Ԫ ���غ���
};
myComplex::myComplex(double r, double i)
{
  real = r;
  imag = i;
}
myComplex::myComplex()
{
  real = 0;
  imag = 0;
}
myComplex myComplex::addCom(myComplex c)
{
  return myComplex(real + c.real, imag + c.imag);
}
void myComplex::outCom()
{
  cout << "(" << real << "," << imag << ")";
}
myComplex myComplex::operator-(const myComplex &c)
{
  return myComplex(this->real - c.real, this->imag - c.imag); //����һ����ʱ����
}
myComplex operator+(const myComplex &c1, const myComplex &c2) //c1+c2
{
  return myComplex(c1.real + c2.real, c1.imag + c2.imag); //����һ����ʱ����
}
myComplex operator-(const myComplex &c1, const myComplex &c2) //c1-c2
{
  return myComplex(c1.real - c2.real, c1.imag - c2.imag); //����һ����ʱ����
}
myComplex operator-(const myComplex &c1, double r) //c1-r
{
  return myComplex(c1.real - r, c1.imag); //����һ����ʱ����
}
myComplex operator-(double r, const myComplex &c1) //r-c1
{
  return myComplex(r + c1.real, -c1.imag); //����һ����ʱ����
}

int main()
{
  myComplex c1(1, 2), c2(3, 4), res;
  c1.outCom();
  cout << "operator+";
  c2.outCom();
  cout << "=";
  res = c1 + c2;
  res.outCom();
  cout << endl;
  c1.outCom();
  cout << "operator-";
  c2.outCom();
  cout << "=";
  res = c1 - c2;
  res.outCom();
  cout << endl;
  res = c1 - c2;
  res.outCom();
  res = c1 - 5;
  res.outCom();
  res = 5 - c1;
  res.outCom();
  return 0;
}