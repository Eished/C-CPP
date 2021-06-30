#include <fstream>
#include <iostream>
#include <string>
using namespace std;
// Class to define the properties
class Student
{
private:
public:
  static int total;
  static int csCount;
  static int maCount;
  static int buCount;
  int studNum = 123;
  string name = "Johna是撒旦";
  char sex = 'F';
  string college = "CC";
  int year = 2019;
  int colNum = 44;
  Student(){};
};
// int Employee::a = 1;
int main()
{
  Student Emp_1;
  // // Emp_1.Name = "John";
  // // Emp_1.Employee_ID = 2121;
  // // Emp_1.Salary = 11000;
  // //Wriring this data to Employee.txt
  // ofstream file1;
  // file1.open("Employee.txt", ios::out | ios::binary);
  // file1.write((char *)&Emp_1, sizeof(Emp_1));
  // file1.close();
  //Reading data from EMployee.txt
  ifstream file2;
  file2.open("Employee.txt", ios::in | ios::binary);
  file2.seekg(0);
  file2.read((char *)&Emp_1, sizeof(Emp_1));
  cout << "Name:" << Emp_1.name << endl;
  cout << "Employee ID:" << Emp_1.studNum << endl;
  cout << "Salary ::" << Emp_1.college << endl;
  cout << "a ::" << Emp_1.year << endl;
  file2.close();
  return 0;
}