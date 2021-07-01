#pragma once
using namespace std;

class Student
{
private:

public:
	static int total;
	static int csCount;
	static int maCount;
	static int buCount;
	int studNum = 0;
	char name[20] = "0";
	char sex = '0';
	char college[3] = "0";
	int year = 0;
	int colNum = 0;
	Student() {};
	Student(char name[20], char sex, char college[3], int year, int colNum);
	void GenID();
	void print();
};