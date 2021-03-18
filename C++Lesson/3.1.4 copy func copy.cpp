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
  ~myDate();

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
  Student(const Student &s);       //�������ƹ��캯��
  ~Student();                      //�������ƹ��캯��

private:
  string name;     //����
  myDate birthday; //����
};

//���幹�캯��
Student::Student() : name("NoName"), birthday(myDate()){};  //���,��������
Student::Student(string n) : name(n), birthday(myDate()){}; //���,��һ������

//�����ⶨ���Ա����
Student::Student(const Student &s) //�Զ��帴�ƹ��캯��
{
  name = "Copy" + s.name;
  birthday = s.birthday;
}
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
//������������
myDate::~myDate()
{
  cout << "myDate ��������" << endl;
}
Student::~Student()
{
  cout << "Student ��������" << endl;
}
int main()
{
  Student stud;
  stud.setName("444"); //������Ϊ444
  Student ss[2] = {stud, Student()};
  stud.printStudent();
  stud.setName("111");
  ss[0] = Student(stud); //���ø��ƹ��캯��
  ss[1] = Student();
  stud.printStudent();
  ss[0].printStudent(); //���� Copy111
  ss[1].printStudent(); //Ĭ���¶���
  return 0;
}