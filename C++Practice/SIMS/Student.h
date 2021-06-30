#pragma once
#include<string>
using namespace std;

class Student
{
private:

public:
	static int total;
	static int csCount;
	static int maCount;
	static int buCount;
	int studNum;
	string name;
	char sex;
	string college;
	int year;
	int colNum;
	Student(string name, char sex, string college, int year, int colNum);
	void GenID();
	void print();
};