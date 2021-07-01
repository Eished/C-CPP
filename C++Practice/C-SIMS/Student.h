#pragma once
using namespace std;

class Student
{
private:
	static int total;
public:
	int studNum = 0;
	char name[20] = "0";
	char sex = '0';
	char college[3] = "0";
	int year = 0;
	int colNum = 0;
	Student() {};
	Student(char name[20], char sex, char college[3], int year, int colNum);
	void GenID(int count);
	void print();
	int Total();
	void setTotal(int total);
};