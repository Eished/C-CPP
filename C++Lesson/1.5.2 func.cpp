#include <iostream>
using namespace std;
int oneX = 10;
int oneY = 20;
int a = 11;
int &refValue(int &x) //����ֵ������,������ֵ
{
  return x;
}
int main()
{
  // refValue(oneX) = 30;             //����ֵ������,������ֵ
  cout << "oneX=" << oneX << endl; //��� oneX=30
  // refValue(oneY) = 40;             //����ֵ�����õĺ������ñ��ʽ,������ֵʹ��
  cout << "oneY=" << oneY << endl; //���oneY=40
  refValue(a) = 111;
  cout << refValue(a) << endl
       << a;
  return 0;
}