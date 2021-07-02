#include "Student.h"
#include <iostream>
#include <cstring>
using namespace std;

int Student::total = 0;
Student::Student(char name[20], char sex, char college[3], int year, int colNum) {
	strcpy_s(this->name, name);
	strcpy_s(this->college, college);
	this->sex = sex;
	this->year = year;
	this->colNum = colNum;
	this->total++;
}

void Student::GenID(int count) {
	studNum = colNum * 10000 + year % 100 * 100 + count;
}
void Student::print() {
	cout << "学号：" << studNum << "  姓名：" << name << "  性别：" << sex << "  学院：" << college << "  入学年份：" << year << "  学院顺序号：" << colNum << endl;
}

int Student::Total() {
	return total;
}

void Student::setTotal(int total) {
	this->total = total;
}