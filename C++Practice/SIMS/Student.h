#pragma once
#include<string>
using namespace std;

class Student
{
private:
	int stdNum;
	static int total;
	static int csCount;
	static int maCount;
	static int buCount;
	string name;
	char sex;
	string college;
	int year;
	int colNum;

public:
	Student(string name, char sex, string college, int year, int colNum);
	void GenID();
	void print();
};