#include <iostream>
#include <string>
using namespace std;
class Samp
{
public:
  void Setij(int a, int b)
  {
    i = a;
    j = b;
    cout << "i=" << i << "���캯��" << endl;
  }
  void printDemo();
  ~Samp()
  {
    cout << "i=" << i << "��������" << endl;
  }
  int GetMuti()
  {
    return i * j;
  }

protected:
  int i;
  int j;
};

int main()
{
  Samp *p;
  p = new Samp[5];
  if (!p)
  {
    cout << "�ڴ�������\n";
    return 1;
  }
  for (int j = 0; j < 5; j++)

    p[j].Setij(j, j);
  for (int k = 0; k < 5; k++)
    cout << "Muti[" << k << "] ֵ��:" << p[k].GetMuti() << endl;
  delete[] p;

  return 0;
}