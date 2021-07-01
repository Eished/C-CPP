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
	char name[20] = "1";
	char sex = 'F';
	char college[3] = "1";
	int year = 0;
	int colNum = 0;
	Student() {};
	Student(char name[20], char sex, char college[3], int year, int colNum);
	void GenID();
	void print();
};