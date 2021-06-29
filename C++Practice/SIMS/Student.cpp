#include "Student.h"
#include <iostream>
using namespace std;
int total = 0;
int csCount = 0;
int maCount = 0;
int buCount = 0;
Student::Student(string name, char sex, string college, int year, int colNum) {
	this->name = name;
	this->sex = sex;
	this->college = college;
	this->year = year;
	this->colNum = colNum;
	this->total++;
	//switch (colNum) {
	//case 11: {
	//	csCount++;
	//	break;
	//};
	//case 22: {
	//	maCount++;
	//	break;
	//};
	//case 33: {
	//	buCount++;
	//	break;
	//};
	//default:
	//	break;
	//}
}

void Student::GenID() {
	stdNum = colNum + year;
	cout << stdNum << endl;
}
int Student::total = 0;
void Student::print() {
	cout << this->total << endl;
	//<< "  CS:" << csCount << "  MA:" << maCount << "  BU:" << buCount << "  " << endl;
	cout << "姓名：" << name << "  性别：" << sex << "  学院：" << college << "  入学年份：" << year << "  学院顺序号：" << colNum << endl;
}