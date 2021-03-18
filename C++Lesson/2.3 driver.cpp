#include <iostream>
#include <string>
using namespace std;
class myDate
{
public:
  myDate();                    //���캯��
  myDate(int, int, int);       //���캯��
  void setDate(int, int, int); //��������
  void setDate(myDate);        //��������
  myDate getDate();            //��ȡ����
  void setYear(int);           //������
  int getMonth();              //��ȡ��
  void printDate() const;      //��ӡ����

private:
  int year, month, day; //��Ա����,������
};
//�����ⶨ���Ա����
myDate::myDate()
{
  year = 1970, month = 1, day = 1;
}
myDate::myDate(int y, int m, int d)
{
  year = y;
  month = m;
  day = d;
}
void myDate::setDate(int y, int m, int d)
{
  year = y;
  month = m;
  day = d;
  return;
}
void myDate::setDate(myDate oneD)
{
  year = oneD.year;
  month = oneD.month;
  day = oneD.day;
  return;
}
myDate myDate::getDate()
{
  return *this;
}
void myDate::setYear(int y)
{
  year = y;
  return;
}
int myDate::getMonth()
{
  return month;
}

void myDate::printDate() const
{
  cout << year << "/" << month << "/" << day;
  return;
}
class Student
{
public:
  void setStudent(string, myDate); //����ѧ����Ϣ
  void setName(string);            //��������
  string getName();                //��ȡ����
  void setBirthday(myDate);        //��������
  myDate getBirthday();            //��ȡ����
  void printStudent() const;       //��ӡ��Ϣ

private:
  string name;     //����
  myDate birthday; //����
};
//�����ⶨ���Ա����
void Student::setStudent(string s, myDate d)
{
  name = s;
  birthday.setDate(d);
  return;
}
void Student::setName(string n)
{
  name = n;
  return;
}
string Student::getName()
{
  return name;
}
void Student::setBirthday(myDate d)
{
  birthday.setDate(d);
  return;
}
myDate Student::getBirthday()
{
  return birthday;
}
void Student::printStudent() const
{
  cout << "����:" << name << "\t����:";
  birthday.printDate(); //������myDate �ĳ�Ա����
  cout << endl;
}
int main()
{
  Student ss;
  int y, m, d;
  string name_;
  cout << "������ѧ��������������, ������\"�� �� ��\"�Ĵ�������:";
  cin >> name_ >> y >> m >> d;
  ss.setStudent(name_, myDate(y, m, d));
  ss.printStudent();
  return 0;
}