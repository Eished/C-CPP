#include <iostream>
#include <string>
using namespace std;
class Demo
{
  int id;

public:
  Demo(int i)
  {
    id = i;
    cout << "id=" << id << "���캯��" << endl;
  }
  void printDemo();
  ~Demo()
  {
    cout << "id=" << id << "��������" << endl; //�½ڽ���
  }
};
void Demo::printDemo()
{
  cout << "id=" << id << endl;
}
int main()
{
  Demo d4(4); //�������ڶ���
  d4.printDemo();
  d4 = 6; //�ɿ����ǽ�������6 תΪDemo ����
  d4.printDemo();
  return 0;
}