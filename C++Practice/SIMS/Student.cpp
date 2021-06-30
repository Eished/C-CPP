#include "Student.h"
#include <iostream>
using namespace std;

int Student::total = 0;
int Student::csCount = 0;
int Student::maCount = 0;
int Student::buCount = 0;
Student::Student(char name[20], char sex, char college[3], int year, int colNum) {
	//this->name = name;
	//this->college = college;
	strcpy_s(this->name, name);
	strcpy_s(this->college, college);
	this->sex = sex;
	this->year = year;
	this->colNum = colNum;
	this->total++;
	switch (colNum) {
	case 11: {
		csCount++;
		break;
	};
	case 22: {
		maCount++;
		break;
	};
	case 33: {
		buCount++;
		break;
	};
	default:
		break;
	}
}

void Student::GenID() {
	int count = 0;
	switch (colNum) {
	case 11: {
		count = csCount;
		break;
	};
	case 22: {
		count = maCount;
		break;
	};
	case 33: {
		count = buCount;
		break;
	};
	default:
		break;
	}
	studNum = colNum * 10000 + year % 100 * 100 + count;
}
void Student::print() {
	cout << "ѧ�ţ�" << studNum << "  ������" << name << "  �Ա�" << sex << "  ѧԺ��" << college << "  ��ѧ��ݣ�" << year << "  ѧԺ˳��ţ�" << colNum << endl;
}