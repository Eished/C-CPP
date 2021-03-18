#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
class myComplex
{
private:
  double real, imag;

public:
  myComplex() : real(0), imag(0) {}
  myComplex(double r, double i) : real(r), imag(i) {}
  friend ostream &operator<<(ostream &os, const myComplex &c); //��Ԫ,����
  friend istream &operator>>(istream &is, myComplex &c);       //��Ԫ,��ȡ
};
ostream &operator<<(ostream &os, const myComplex &c)
{
  if (c.imag >= 0)
  {
    os << c.real << "+" << c.imag << "i"; //�� a+bi ����ʽ����
  }
  else
  {
    os << c.real << "-" << -c.imag << "i";
  }
  return os;
}
istream &operator>>(istream &is, myComplex &c)
{
  string s;
  is >> s;                  //��a+bi ��Ϊ�ַ�������,a+bi�м䲻���пո�
  int pos = s.find("+", 0); //�����鲿
  if (pos == -1)
    pos = s.find("-", 1);                      //�鲿Ϊ����ʱ
  string sReal = s.substr(0, pos);             //���������ʵ�����ַ���
  c.real = atof(sReal.c_str());                //atof() �ܽ���������ת���ɸ�����
  sReal = s.substr(pos, s.length() - pos - 1); //����������鲿���ַ���
  c.imag = atof(sReal.c_str());
  return is;
}
int main()
{
  myComplex c, c1;
  int n;
  cout << "��������������([-]a��bi)��һ������, �Կո�ָ�" << endl;
  cin >> c >> c1 >> n;
  cout << c << "," << n << "," << c1;
  return 0;
}