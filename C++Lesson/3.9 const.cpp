#include <iostream>
#include <string>
using namespace std;
class constClass
{
  const int conMbr; //���еĳ�����Ա����
  int Mbr;          //��ͨ��Ա����

public:
  constClass() : conMbr(0), Mbr(100) {} //��ʼ���б�����ʼֵ
  constClass(int i) : conMbr(i)         //��ʼ���б�����ʼֵ
  {
    Mbr = 200;
  }
  void printConst()
  {
    cout << "conMbr=" << conMbr << ",Mbr" << Mbr << endl;
  }
  int getConst()
  {
    cout << "���÷ǳ�������" << endl;
    return conMbr;
  }
  int getConst() const
  {
    cout << "���ó�������" << endl;
    return conMbr;
  }
  int getValue()
  {
    return Mbr;
  }
  void processConst()
  {
    cout << "--��processConst������ �ǳ���--" << endl;
    int x = 2 * conMbr + 1;
    cout << "x=2*conMbr+1=" << x << endl; //���Զ�ȡ conMbr
    //conMbr++; //����, ���ܸ��ĳ�����Ա���� conMbr��ֵ
    Mbr++; //�����޸ķǳ�����Ա Mbr��ֵ
    cout << "Mbr=" << Mbr << endl;
  }
  void processConst() const
  {
    cout << "--��processConst������ ����--" << endl;
    int x = conMbr + 1;
    cout << "x=conMbr+1=" << x << endl; //���Զ�ȡ conMbr
    //conMbr++; //����, ���ܸ��ĳ�����Ա���� conMbr��ֵ
    // Mbr++; //�����޸ķǳ�����Ա Mbr��ֵ
    cout << "Mbr=" << Mbr << endl;
  }
};

int main()
{
  constClass ob1(123), ob2;
  ob1.printConst();
  cout << "ob2.getConst()=" << ob2.getConst() << endl;
  ob2.processConst();
  const constClass ob3(20);
  cout << "ob3.getConst()=" << ob3.getConst() << endl;
  ob3.processConst();
  return 0;
}