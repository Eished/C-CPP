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
  Student();                       //���캯��,�޲���
  Student(string);                 //���캯��,��һ������
  void setStudent(string, myDate); //����ѧ����Ϣ
  void setName(string);            //��������
  string getName();                //��ȡ����
  void setBirthday(myDate);        //��������
  myDate getBirthday();            //��ȡ����
  void printStudent() const;       //��ӡ��Ϣ
  // Student(const Student &s);

private:
  string name;     //����
  myDate birthday; //����
};

//���幹�캯��
Student::Student() : name("NoName"), birthday(myDate()){};  //���,��������
Student::Student(string n) : name(n), birthday(myDate()){}; //���,��һ������

//�����ⶨ���Ա����
// Student::Student(const Student &s)
// {
//   name = "Copy" + s.name;
//   birthday = s.birthday;
// }
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
  Student stud;
  stud.printStudent();                           //���Ĭ��ֵ
  stud.setName("111");                           //������Ϊ111
  stud.printStudent();                           //����޸ĺ��ֵ 111
  Student *spointer[2] = {new Student(), &stud}; //��ʼ��
  Student sy[2] = {Student(), stud};             //��ʼ�� �����µ��ڴ��ַ
  for (int i = 0; i < 2; i++)                    //ʹ��ָ�����ָ��ָ��Ķ����ֵ
    spointer[i]->printStudent();                 //����111
  for (int i = 0; i < 2; i++)                    //ʹ�õ�����������ֵ
    sy[i].printStudent();                        //����111
  stud.setName("222");                           //����222
  for (int i = 0; i < 2; i++)                    //sp[1]ָ��Ķ����ֵ�ı�
    spointer[i]->printStudent();                 //����222
  spointer[0]->setName("333");                   //Ӱ��student��ֵ
  spointer[1]->setName("444");                   //Ӱ��stud��ֵ
  for (int i = 0; i < 2; i++)                    //ָ������ֵ���ı�
    spointer[i]->printStudent();                 // ����444
  stud.printStudent();                           //ֵ��� ����444 ����1970
  for (int i = 0; i < 2; i++)
    sy[i].printStudent(); //ֵ����
  // ����NoName ����1970
  // ����111 ����1970
  return 0;
}