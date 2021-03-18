#include <iostream>
using namespace std;
class Demo
{
private:
  int n;

public:
  Demo(int i = 0) : n(i) {}
  Demo &operator++();   //����ǰ��
  Demo operator++(int); //���ں���
  operator int() { return n; }
  friend Demo &operator--(Demo &);
  friend Demo operator--(Demo &, int);
};
Demo &Demo::operator++() //ǰ��++
{
  n++;
  return *this;
}
Demo Demo::operator++(int k) //����++
{
  Demo tmp(*this); //��¼�޸�ǰ�Ķ���
  n++;
  return tmp; //�����޸�ǰ����
}
Demo &operator--(Demo &d) //ǰ��--
{
  d.n--;
  return d;
}
Demo operator--(Demo &d, int) //����--
{
  Demo tmp(d);
  d.n--;
  return tmp;
}
int main()
{
  Demo d(10);
  cout << (d++) << ","; // d.operator++(0)
  cout << d << ",";
  cout << (++d) << ","; // d.operator++()
  cout << d << ",";
  cout << (d--) << ","; // d.operator--(d,0)
  cout << d << ",";
  cout << (--d) << ","; // d.operator--(d)
  cout << d << ",";
  return 0;
}