#include <iostream>
using namespace std;
class myComplex //������
{
private:
  double real, imag; //������ʵ�����鲿
public:
  myComplex();
  myComplex(double r, double i);
  ~myComplex() {}                                                       //�����зֺ�
  myComplex addCom(myComplex c1);                                       //��Ա����, �����߶������������c���
  void outCom();                                                        //��Ա����, ��������߶�����й�����
  void outCom(string s);                                                //��Ա����, ��������߶�����й�����
  void changeReal(double r);                                            //��Ա����
  myComplex operator-(const myComplex &c);                              //��Ա ���غ���
  friend myComplex operator+(const myComplex &c1, const myComplex &c2); //��Ԫ ���غ��� c1+c2
  friend myComplex operator+(const myComplex &c1, double r);            //��Ԫ ���غ��� c1+r
  friend myComplex operator+(double r, const myComplex &c1);            //��Ԫ ���غ��� r+c1
  friend myComplex operator-(const myComplex &c1, const myComplex &c2); //��Ԫ ���غ���
  friend myComplex operator-(const myComplex &c1, double r);            //��Ԫ ���غ���
  friend myComplex operator-(double r, const myComplex &c1);            //��Ԫ ���غ���
  myComplex &operator=(const myComplex &c);                             //��Ա����
  myComplex &operator=(double);                                         //��Ա����
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
myComplex myComplex::addCom(myComplex c1)
{
  return myComplex(this->real + c1.real, this->imag + c1.imag);
}
void myComplex::outCom()
{
  cout << "(" << real << "," << imag << ")";
}
void myComplex::outCom(string s)
{
  cout << s << "(" << real << "," << imag << ")" << endl;
}
void myComplex::changeReal(double r)
{
  this->real = r;
}
myComplex myComplex::operator-(const myComplex &c)
{
  return myComplex(this->real - c.real, this->imag - c.imag); //����һ����ʱ����
}
myComplex operator+(const myComplex &c1, const myComplex &c2) //c1+c2
{
  return myComplex(c1.real + c2.real, c1.imag + c2.imag); //����һ����ʱ����
}
myComplex operator+(const myComplex &c1, double r) //c1+r
{
  return myComplex(c1.real + r, c1.imag); //����һ����ʱ����
}
myComplex operator+(double r, const myComplex &c1) //r+c2
{
  return myComplex(r + c1.real, c1.imag); //����һ����ʱ����
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
myComplex &myComplex::operator=(const myComplex &c1)
{
  this->real = c1.real;
  this->imag = c1.imag;
  return *this;
}
myComplex &myComplex::operator=(double r)
{
  this->real = r;
  this->imag = 0;
  return *this;
}

int main()
{
  myComplex c1(1, 2), c2(3, 4), res;
  c1.outCom("\t\t\tc1");
  c2.outCom("\t\t\tc2");
  res = c1 + c2;
  res.outCom("ִ�� res = c1 + c2 ��\tres");
  res = c1.addCom(c2);
  res.outCom("ִ�� res = c1.addCom(c2) ��\tres");
  res = c1 + 5;
  res.outCom("ִ�� res = c1 + 5 ��\tres");
  res = 5 + c1;
  res.outCom("ִ�� res = 5 + c1 ��\tres");
  res = c1;
  c1.outCom("\t\t\tc1");
  res.outCom("ִ�� res = c1 ��\tres");
  c1.changeReal(-3);
  c1.outCom("ִ�� changeReal(-3) ��\tc1");
  res.outCom("\t\t\tres");
  res = c1;
  res.outCom("res = c1 ��\tres");
  res = 7;
  res.outCom("res = 7 ��\tres");
  res = 7 + 8;
  res.outCom("res = 7 + 8; ��\tres");
  res = c1 = c2;
  c1.outCom("\t\t\tc1");
  c2.outCom("\t\t\tc2");
  res.outCom("res = c1 = c2 ��\tres");

  return 0;
}