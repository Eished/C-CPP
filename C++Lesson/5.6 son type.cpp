#include <iostream>
#include <string>
using namespace std;
class CStudent //����
{
private:
  string name; //����
  string id;   //ѧ��
  char gender; //�Ա�,'F'����Ů��, 'M'��������
  int age;     //����
public:
  void PrintInfo();
  void SetInfo(const string &, const string &, int, char);
  void SetName(string);
  string GetName();
  void SetId(string);
  string GetId();
};
void CStudent::PrintInfo()
{
  cout << "����:\t" << name << endl;
  cout << "ѧ��:\t" << id << endl;
  cout << "����:\t" << age << endl;
  cout << "�Ա�:\t" << gender << endl;
}
void CStudent::SetInfo(const string &name_, const string &id_, int age_, char gender_)
{
  name = name_;
  id = id_;
  age = age_;
  gender = gender_;
}
void CStudent::SetName(string name)
{
  this->name = name;
}
string CStudent::GetName()
{
  return name;
}
void CStudent::SetId(string id)
{
  this->id = id;
}
string CStudent::GetId()
{
  return id;
}

class CUndergraduateStudent : public CStudent //��������, �̳����� CStudent
{
private:
  string department; //ѧ��������ϵ��

public:
  void PrintInfo();
  void SetInfo(const string &, const string &, int, char, const string &);
};
void CUndergraduateStudent::PrintInfo()
{
  CStudent::PrintInfo();
  cout << "Ժϵ:\t" << department << endl
       << endl;
}
void CUndergraduateStudent::SetInfo(const string &name_, const string &id_, int age_, char gender_, const string &department_)
{
  CStudent::SetInfo(name_, id_, age_, gender_);
  department = department_;
}

class CGraduatedStudent : public CStudent //�о�����
{
private:
  string department; //ѧ��������ϵ��
  string advisor;    //��ʦ
public:
  void PrintInfo();
  void SetInfo(const string &name_, const string &id_, int age_, char gender_, const string &department_, const string &advisor_);
};
void CGraduatedStudent::PrintInfo()
{
  CStudent::PrintInfo();
  cout << "Ժϵ:\t" << department << endl;
  cout << "��ʦ:\t" << advisor << endl;
}
void CGraduatedStudent::SetInfo(const string &name_, const string &id_, int age_, char gender_, const string &department_, const string &advisor_)
{
  CStudent::SetInfo(name_, id_, age_, gender_);
  department = department_;
  advisor = advisor_;
}
int main()
{
  CStudent s1;              //�������
  CUndergraduateStudent s2; //���������
  CGraduatedStudent s3;     //���������
  s2.SetInfo("����", "2020-6-2-4", 19, 'M', "��ѧϵ");
  s3.SetInfo("����", "M2021-12", 19, 'F', "�����ϵ", "�޽���");
  s2.PrintInfo();                                    //���������ຯ��
  s3.PrintInfo();                                    //���������ຯ��
  cout << s2.GetName() << endl;                      //ͨ�����๫�г�Ա��������
  s2.SetName("�Ŷ�");                                //���๫�г�Ա����
  s2.PrintInfo();                                    //�����๫�г�Ա����
  cout << s2.GetName() << "," << s2.GetId() << endl; //���๫�г�Ա����
  return 0;
}