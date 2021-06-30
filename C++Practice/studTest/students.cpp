#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
void display();

class Student
{
private:
public:
	static int total;
	static int csCount;
	static int maCount;
	static int buCount;
	//int studNum = 1;
	//string name = "1";
	//char sex = 'F';
	//string college = "1";
	//int year = 1;
	//int colNum = 1;
	int studNum = 123;
	char name[10] = "小王";
	char sex = 'F';
	char college[3] = "CS";
	int year = 3453;
	int colNum = 99;
	void print()
	{
		cout << "学号：" << studNum << "  姓名：" << name << "  性别：" << sex << "  学院：" << college << "  入学年份：" << year << "  学院顺序号：" << colNum << endl;
	};
};
void Save() {
	Student stud;
	ofstream file1;
	file1.open("cs.txt", ios::out | ios::binary);
	file1.write((char*)&stud, sizeof(stud));
	file1.close();
};
void Read() {
	Student stud2;
	ifstream file2;
	file2.open("cs.txt", ios::in | ios::binary);
	file2.read((char*)&stud2, sizeof(stud2));
	stud2.print();
	system("pause");
	system("cls");
	file2.close();
}
int main()
{
	while (true) {
		display();
		int cho;
		cin >> cho;
		switch (cho) {
		case 1: { // 输入学生信息
			system("cls");
			Save();
			break;
		}
		case 2: { // 打印学生信息
			system("cls");
			Read();
			break;
		}
		case 0:
		{ // 退出
			cout << "已退出" << endl;
			return 0;
		}
		default: {
			cout << "输入不正确!" << endl;
			system("pause");
			system("cls");
			break;
		}
		}
	}
	return 0;
}

void display() {
	cout << "1:输入学生信息\n" << endl;
	cout << "2:打印学生信息\n" << endl;
	cout << "0:退出\n" << endl;
	cout << "请输入对应的序号：" << endl;
}