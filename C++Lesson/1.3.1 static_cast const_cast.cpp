#include <iostream>
using namespace std;
int main()
{
  int a = 10;
  const int *p = &a; //����ʹ�ó���ָ��p�޸�a��ֵ,"&"ȡ��ַ��,"*"�ӵ�ַȡֵ
  const int ca = 30; //��const����
  int *q;
  cout << "a���ڴ��ַΪ:\t" << &a << "\t a��ֵΪ:\t" << a << endl;
  cout << "pָ��ĵ�ַΪ:\t" << p << "\t *p��ֵΪ:\t" << *p << endl;
  q = const_cast<int *>(p); //ȥ��p�ĳ����Ը���q,���дq=p;�ᱨ��
  *q = 20;                  //���д*p=20;�Ǵ����
  cout << "a���ڴ��ַΪ:\t" << &a << "\t a��ֵΪ:\t" << a << endl;
  cout << "pָ��ĵ�ַΪ:\t" << p << "\t *p��ֵΪ:\t" << *p << endl;
  cout << "qָ��ĵ�ַΪ:\t" << q << "\t *q��ֵΪ:\t" << *q << endl;
  cout << "�ֽ���" << endl;
  p = &ca;                  //ca��ֵ�����޸�
  q = const_cast<int *>(p); //ȥ��p�ĳ����Ը���q,���дq=p;�ᱨ��
  *q = 40;                  //���д*p=40;�Ǵ����
  cout << "ca���ڴ��ַΪ:\t" << &ca << "\t ca��ֵΪ:\t" << ca << endl;
  cout << "pָ��ĵ�ַΪ:\t" << p << "\t *p��ֵΪ:\t" << *p << endl;
  cout << "qָ��ĵ�ַΪ:\t" << q << "\t *q��ֵΪ:\t" << *q << endl;
  return 0;
}