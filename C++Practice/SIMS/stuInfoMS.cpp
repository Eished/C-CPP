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
		case 1: { // 输入学生信息
			input();
			system("cls");
			break;
		}
		case 2: { // 打印学生信息
			system("cls");
			printAll();
			system("pause");
			system("cls");
			break;
		}
		case 3: { // 插入学生信息
			Ins();
			system("cls");
			break;
		}
		case 4: { // 查找学生信息
			Query();
			system("pause");
			system("cls");
			break;
		}
		case 5: { // 修改学生信息
			modify();
			system("pause");
			system("cls");
			break;
		}
		case 6: { // 删除学生信息
			Del();
			system("cls");
			break;
		}
		case 7: { // 读取学生信息
			Read();
			cout << "读取成功！" << endl;
			system("pause");
			system("cls");
			break;
		}
		case 8: { // 保存
			Save();
			cout << "保存成功！" << endl;
			system("pause");
			system("cls");
			break;
		}
		case 9: { // 按学号从小到大排序
			system("cls");
			Sort();
			system("pause");
			system("cls");
			break;
		}
		case 0: { // 退出
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
	cout << "3:插入学生信息\n" << endl;
	cout << "4:查找学生信息\n" << endl;
	cout << "5:修改学生信息\n" << endl;
	cout << "6:删除学生信息\n" << endl;
	cout << "7:读取学生信息\n" << endl;
	cout << "8:保存学生信息\n" << endl;
	cout << "9:按学号从小到大排序\n" << endl;
	cout << "0:退出\n" << endl;
	cout << "请输入对应的序号：" << endl;
}
void input() {
	int t = 0;
	cout << "输入学生人数：";
	cin >> t;
	cout << "输入：名字 性别 学院字母 入学年份 学院代码" << endl;
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
	cout << "总人数：" << Student::total << endl;
	cout << "计算机学院人数：" << Student::csCount << endl;
	cout << "管理学院人数：" << Student::maCount << endl;
	cout << "土木学院人数：" << Student::buCount << endl;
	cout << endl;
	// 输入学院 或 打印全部
	cout << "计算机学院:" << endl;
	for (int i = 0; i < CSarr.size(); i++) {
		CSarr[i].print();
	}
	cout << "\n管理学院:" << endl;
	for (int i = 0; i < MAarr.size(); i++) {
		MAarr[i].print();
	}
	cout << "\n土木学院:" << endl;
	for (int i = 0; i < BUarr.size(); i++) {
		BUarr[i].print();
	}
	cout << endl;
}

void Ins() {
	int t = 0, x = 0;
	cout << "输入插入位置：";
	cin >> x;
	cout << "输入学生人数：";
	cin >> t;
	cout << "输入：名字 性别 学院字母 入学年份 学院代码" << endl;
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
				cout << "插入位置大于数组长度" << endl;
			}
			break;
		};
		case 22: {
			if (MAarr.size() >= x) {
				MAarr.insert(MAarr.begin() + x - 1, stud);
			}
			else {
				cout << "插入位置大于数组长度" << endl;
			}
			break;
		};
		case 33: {
			if (BUarr.size() >= x) {
				BUarr.insert(BUarr.begin() + x - 1, stud);
			}
			else {
				cout << "插入位置大于数组长度" << endl;
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
	cout << "输入查询的学号:" << endl;
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
		cout << "未找到" << endl;
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
		cout << "未找到" << endl;
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
		cout << "未找到" << endl;
		break;
	};
	default:
		break;
	}
}
void Del() {
	int num;
	cout << "输入删除的学号:" << endl;
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
		cout << "未找到" << endl;
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
		cout << "未找到" << endl;
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
		cout << "未找到" << endl;
		break;
	};
	default:
		break;
	}
}

void modify() {
	int num;
	cout << "输入修改的学号:" << endl;
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
				cout << "输入：名字 性别 学院字母 入学年份 学院代码" << endl;
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
		cout << "未找到" << endl;
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
				cout << "输入：名字 性别 学院字母 入学年份 学院代码" << endl;
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
		cout << "未找到" << endl;
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
				cout << "输入：名字 性别 学院字母 入学年份 学院代码" << endl;
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
		cout << "未找到" << endl;
		break;
	};
	default:
		break;
	}
}

void Sort() {
	cout << "总人数：" << Student::total << endl;
	cout << endl;
	cout << "简单选择排序算法，从小到大排序:" << endl;
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
		cout << "没有数据" << endl;
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