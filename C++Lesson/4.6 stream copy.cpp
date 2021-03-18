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
  ostream &operator<<(ostream &os);                      //��Ա���� ,����
  friend istream &operator>>(istream &is, myComplex &c); //��Ԫ,��ȡ
};
ostream &myComplex::operator<<(ostream &os)
{
  if (this->imag >= 0)
  {
    os << this->real << "+" << this->imag << "i"; //�� a+bi ����ʽ����
  }
  else
  {
    os << this->real << "-" << -this->imag << "i";
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
  c1 << (c << cout << ",") << "," << n; //ע�������ʽ
  return 0;
}