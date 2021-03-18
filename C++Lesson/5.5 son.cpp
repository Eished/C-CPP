#include <iostream>
using namespace std;
class CB
{

public:
  int a;
  CB(int x)
  {
    a = x;
  }
  void showa()
  {
    cout << "Class Cb--a=" << a << endl;
  }
};
class CD : public CB
{
public:
  int a;                   //�����ͬ��
  CD(int x, int y) : CB(x) //x ��ʼ������ĳ�Ա����a
  {
    a = y;
  }
  void showa() //����ͬ������
  {
    cout << "Class CD--a" << a << endl;
  }
  void print2a()
  {
    cout << "a=" << a << endl;         //����������a
    cout << "CB::a=" << CB::a << endl; //���ʻ���a
  }
};
int main()
{
  CB CBobj(12);
  CBobj.showa();
  CD CDobj(48, 999);
  CDobj.showa();     //�����������showa()
  CDobj.CB::showa(); //���ʻ����showa()
  cout << "CDobj.a" << CDobj.a << endl;
  cout << "CDobj.CB::a=" << CDobj.CB::a << endl;
  return 0;
}