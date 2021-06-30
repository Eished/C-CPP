#include <iostream>
#include <vector>
#include <fstream>
#include "Student.h"
#include "myfunc.h"

using namespace std;

vector<Student> CSarr;
vector<Student> MAarr;
vector<Student> BUarr;
int main() {
	while (true) {
		display();
		int cho;
		cin >> cho;
		switch (cho) {
		case 1: { // ����ѧ����Ϣ
			input();
			system("cls");
			break;
		}
		case 2: { // ��ӡѧ����Ϣ
			system("cls");
			printAll();
			system("pause");
			system("cls");
			break;
		}
		case 3: { // ����ѧ����Ϣ
			Ins();
			system("cls");
			break;
		}
		case 4: { // ����ѧ����Ϣ
			Query();
			system("pause");
			system("cls");
			break;
		}
		case 5: { // �޸�ѧ����Ϣ
			modify();
			system("pause");
			system("cls");
			break;
		}
		case 6: { // ɾ��ѧ����Ϣ
			Del();
			system("cls");
			break;
		}
		case 7: { // ��ȡѧ����Ϣ
			Read();
			cout << "��ȡ�ɹ���" << endl;
			system("pause");
			system("cls");
			break;
		}
		case 8: { // ����
			Save();
			cout << "����ɹ���" << endl;
			system("pause");
			system("cls");
			break;
		}
		case 9: { // ��ѧ�Ŵ�С��������
			system("cls");
			Sort();
			system("pause");
			system("cls");
			break;
		}
		case 0: { // �˳�
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
	cout << "3:����ѧ����Ϣ\n" << endl;
	cout << "4:����ѧ����Ϣ\n" << endl;
	cout << "5:�޸�ѧ����Ϣ\n" << endl;
	cout << "6:ɾ��ѧ����Ϣ\n" << endl;
	cout << "7:��ȡѧ����Ϣ\n" << endl;
	cout << "8:����ѧ����Ϣ\n" << endl;
	cout << "9:��ѧ�Ŵ�С��������\n" << endl;
	cout << "0:�˳�\n" << endl;
	cout << "�������Ӧ����ţ�" << endl;
}
void input() {
	int t = 0;
	cout << "����ѧ��������";
	cin >> t;
	cout << "���룺���� �Ա� ѧԺ��ĸ ��ѧ��� ѧԺ����" << endl;
	for (int i = 0; i < t; i++) {
		//string name;
		//string college;
		char name[20];
		char college[3];
		char sex;
		int year;
		int colNum;
		cin >> name >> sex >> college >> year >> colNum;
		Student stud(name, sex, college, year, colNum);
		stud.GenID();
		switch (colNum) {
		case 11: {
			CSarr.push_back(stud);
			break;
		};
		case 22: {
			MAarr.push_back(stud);
			break;
		};
		case 33: {
			BUarr.push_back(stud);
			break;
		};
		default:
			break;
		}
	}
}
void printAll() {
	cout << "��������" << Student::total << endl;
	cout << "�����ѧԺ������" << Student::csCount << endl;
	cout << "����ѧԺ������" << Student::maCount << endl;
	cout << "��ľѧԺ������" << Student::buCount << endl;
	cout << endl;
	// ����ѧԺ �� ��ӡȫ��
	cout << "�����ѧԺ:" << endl;
	for (int i = 0; i < CSarr.size(); i++) {
		CSarr[i].print();
	}
	cout << "\n����ѧԺ:" << endl;
	for (int i = 0; i < MAarr.size(); i++) {
		MAarr[i].print();
	}
	cout << "\n��ľѧԺ:" << endl;
	for (int i = 0; i < BUarr.size(); i++) {
		BUarr[i].print();
	}
	cout << endl;
}

void Ins() {
	int t = 0, x = 0;
	cout << "�������λ�ã�";
	cin >> x;
	cout << "����ѧ��������";
	cin >> t;
	cout << "���룺���� �Ա� ѧԺ��ĸ ��ѧ��� ѧԺ����" << endl;
	for (int i = 0; i < t; i++) {
		//string name;
		//string college;
		char name[20];
		char college[3];
		char sex;
		int year;
		int colNum;
		cin >> name >> sex >> college >> year >> colNum;
		Student stud(name, sex, college, year, colNum);
		stud.GenID();
		switch (colNum) {
		case 11: {
			if (CSarr.size() >= x) {
				CSarr.insert(CSarr.begin() + x - 1, stud);
			}
			else {
				cout << "����λ�ô������鳤��" << endl;
			}
			break;
		};
		case 22: {
			if (MAarr.size() >= x) {
				MAarr.insert(MAarr.begin() + x - 1, stud);
			}
			else {
				cout << "����λ�ô������鳤��" << endl;
			}
			break;
		};
		case 33: {
			if (BUarr.size() >= x) {
				BUarr.insert(BUarr.begin() + x - 1, stud);
			}
			else {
				cout << "����λ�ô������鳤��" << endl;
			}
			break;
		};
		default:
			break;
		}
	}
}
void Query() {
	int num;
	cout << "�����ѯ��ѧ��:" << endl;
	cin >> num;
	int	colNum = num / 10000;
	switch (colNum) {
	case 11: {
		for (int i = 0; i < CSarr.size(); i++) {
			if (CSarr[i].studNum == num)
			{
				CSarr[i].print();
				return;
			}
		}
		cout << "δ�ҵ�" << endl;
		break;
	};
	case 22: {
		for (int i = 0; i < MAarr.size(); i++) {
			if (MAarr[i].studNum == num)
			{
				MAarr[i].print();
				return;
			}
		}
		cout << "δ�ҵ�" << endl;
		break;
	};
	case 33: {
		for (int i = 0; i < BUarr.size(); i++) {
			if (BUarr[i].studNum == num)
			{
				BUarr[i].print();
				return;
			}
		}
		cout << "δ�ҵ�" << endl;
		break;
	};
	default:
		break;
	}
}
void Del() {
	int num;
	cout << "����ɾ����ѧ��:" << endl;
	cin >> num;
	int	colNum = num / 10000;
	switch (colNum) {
	case 11: {
		for (int i = 0; i < CSarr.size(); i++) {
			if (CSarr[i].studNum == num)
			{
				CSarr.erase(CSarr.begin() + i);
				return;
			}
		}
		cout << "δ�ҵ�" << endl;
		break;
	};
	case 22: {
		for (int i = 0; i < MAarr.size(); i++) {
			if (MAarr[i].studNum == num)
			{
				MAarr.erase(MAarr.begin() + i);
				return;
			}
		}
		cout << "δ�ҵ�" << endl;
		break;
	};
	case 33: {
		for (int i = 0; i < BUarr.size(); i++) {
			if (BUarr[i].studNum == num)
			{
				BUarr.erase(BUarr.begin() + i);
				return;
			}
		}
		cout << "δ�ҵ�" << endl;
		break;
	};
	default:
		break;
	}
}

void modify() {
	int num;
	cout << "�����޸ĵ�ѧ��:" << endl;
	cin >> num;
	int	colNum = num / 10000;
	switch (colNum) {
	case 11: {
		for (int i = 0; i < CSarr.size(); i++) {
			if (CSarr[i].studNum == num)
			{
				CSarr[i].print();
				cout << endl;
				char name[20];
				char college[3];
				char sex;
				int year;
				int colNum;
				cout << "���룺���� �Ա� ѧԺ��ĸ ��ѧ��� ѧԺ����" << endl;
				cin >> name >> sex >> college >> year >> colNum;
				//CSarr[i].name = name;
				strcpy_s(CSarr[i].name, name);
				strcpy_s(CSarr[i].college, college);
				CSarr[i].sex = sex;
				//CSarr[i].college = college;

				CSarr[i].year = year;
				CSarr[i].colNum = colNum;
				CSarr[i].GenID();
				CSarr[i].print();
				return;
			}
		}
		cout << "δ�ҵ�" << endl;
		break;
	};
	case 22: {
		for (int i = 0; i < MAarr.size(); i++) {
			if (MAarr[i].studNum == num)
			{
				MAarr[i].print();
				cout << endl;
				//string name;
				//string college;
				char name[20];
				char college[3];
				char sex;
				int year;
				int colNum;
				cout << "���룺���� �Ա� ѧԺ��ĸ ��ѧ��� ѧԺ����" << endl;
				cin >> name >> sex >> college >> year >> colNum;
				//MAarr[i].name = name;
				//MAarr[i].college = college;
				strcpy_s(CSarr[i].name, name);
				strcpy_s(CSarr[i].college, college);
				MAarr[i].sex = sex;
				MAarr[i].year = year;
				MAarr[i].colNum = colNum;
				MAarr[i].GenID();
				MAarr[i].print();
				return;
			}
		}
		cout << "δ�ҵ�" << endl;
		break;
	};
	case 33: {
		for (int i = 0; i < BUarr.size(); i++) {
			if (BUarr[i].studNum == num)
			{
				BUarr[i].print();
				cout << endl;
				//string name;
				//string college;
				char name[20];
				char college[3];
				char sex;
				int year;
				int colNum;
				cout << "���룺���� �Ա� ѧԺ��ĸ ��ѧ��� ѧԺ����" << endl;
				cin >> name >> sex >> college >> year >> colNum;
				//BUarr[i].name = name;
				//BUarr[i].college = college;
				strcpy_s(CSarr[i].name, name);
				strcpy_s(CSarr[i].college, college);
				BUarr[i].sex = sex;
				BUarr[i].year = year;
				BUarr[i].colNum = colNum;
				BUarr[i].GenID();
				BUarr[i].print();
				return;
			}
		}
		cout << "δ�ҵ�" << endl;
		break;
	};
	default:
		break;
	}
}

void Sort() {
	cout << "��������" << Student::total << endl;
	cout << endl;
	cout << "��ѡ�������㷨����С��������:" << endl;
	vector<Student> studs;
	int temp = 0;
	int less = 0;
	for (int i = 0; i < CSarr.size(); i++) {
		studs.push_back(CSarr[i]);
	}
	for (int i = 0; i < MAarr.size(); i++) {
		studs.push_back(MAarr[i]);
	}
	for (int i = 0; i < BUarr.size(); i++) {
		studs.push_back(BUarr[i]);
	}
	if (studs.size() > 0) {
		for (int i = 0; i < studs.size(); i++) {
			for (int j = i + 1; j < studs.size(); j++) {
				if (studs[i].studNum > studs[j].studNum)
				{
					if (studs[i].studNum - studs[j].studNum > less) {
						less = studs[i].studNum - studs[j].studNum;
						temp = j;
					}
				}
			}
			if (less) {
				studs.insert(studs.begin() + i, studs[temp]);
				studs.erase(studs.begin() + temp + 1);
				less = 0;
			}
		}
	}
	else {
		cout << "û������" << endl;
	}
	cout << endl;
	for (int i = 0; i < studs.size(); i++) {
		studs[i].print();
	}
}

void Save() {
	ofstream file("CS.dat", ios::out | ios::binary);
	for (int i = 0; i < CSarr.size(); i++) {
		file.write((char*)&CSarr[i], sizeof(Student));
	}
	file.close();
}
void Read() {
	Student stud;
	ifstream file("CS.dat", ios::in | ios::binary);
	file.read((char*)&stud, sizeof(Student));
	stud.print();
	CSarr.push_back(stud);
	file.close();
}