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
	char name[10] = "С��";
	char sex = 'F';
	char college[3] = "CS";
	int year = 3453;
	int colNum = 99;
	void print()
	{
		cout << "ѧ�ţ�" << studNum << "  ������" << name << "  �Ա�" << sex << "  ѧԺ��" << college << "  ��ѧ��ݣ�" << year << "  ѧԺ˳��ţ�" << colNum << endl;
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
		case 1: { // ����ѧ����Ϣ
			system("cls");
			Save();
			break;
		}
		case 2: { // ��ӡѧ����Ϣ
			system("cls");
			Read();
			break;
		}
		case 0:
		{ // �˳�
			cout << "���˳�" << endl;
			return 0;
		}
		default: {
			cout << "���벻��ȷ!" << endl;
			system("pause");
			system("cls");
			break;
		}
		}
	}
	return 0;
}

void display() {
	cout << "1:����ѧ����Ϣ\n" << endl;
	cout << "2:��ӡѧ����Ϣ\n" << endl;
	cout << "0:�˳�\n" << endl;
	cout << "�������Ӧ����ţ�" << endl;
}