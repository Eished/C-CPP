#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
class myComplex
{
private:
  double real, imag;

public:
  myComplex(double r = 0, double i = 0) : real(r), imag(i){}; //������Ա����
  operator double()                                           //����ǿ������ת������� double
  {
    return real;
  }
};

int main()
{
  myComplex c(1.2, -3.4);
  cout << (double)c << endl;
  double n = 12 + c; //�ȼ��� double n=12+ coperator double()
  cout << n;
  return 0;
}