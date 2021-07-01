#include "Student.h"
#include <iostream>
#include <fstream>
#define M 30

using namespace std;

void display() {
	cout << "1:输入学生信息\n" << endl;
	cout << "2:打印学生信息\n" << endl;
	cout << "3:插入学生信息\n" << endl;
	cout << "4:查找学生信息\n" << endl;
	cout << "5:统计学生信息\n" << endl;
	cout << "6:删除学生信息\n" << endl;
	cout << "7:读取学生信息\n" << endl;
	cout << "8:保存学生信息\n" << endl;
	cout << "9:按学号从小到大排序\n" << endl;
	cout << "0:退出\n" << endl;
	cout << "请输入对应的序号：" << endl;
};

int main() {
	Student CSarr[M]; // 学生数组
	Student MAarr[M];
	Student BUarr[M];
	int CScount = 0; // 学号顺序号：只增不减
	int MAcount = 0;
	int BUcount = 0;
	int CSi = 0; // 学生数组下标位置
	int MAi = 0;
	int BUi = 0;
	while (true) {
		display();
		int cho;
		cin >> cho;
		switch (cho) {
		case 1: { // 输入学生信息
			system("cls");
			int t = 0;
			cout << "输入录入人数：" << endl;
			cin >> t;
			cout << "输入：名字 性别 学院字母 入学年份 学院代码" << endl;
			for (int i = 0; i < t; i++) {
				char name[20];
				char college[3];
				char sex;
				int year;
				int colNum;
				cin >> name >> sex >> college >> year >> colNum;
				Student stud(name, sex, college, year, colNum);
				switch (colNum) {
				case 11: {
					stud.GenID(++CScount);
					CSarr[CSi++] = stud;
					break;
				};
				case 22: {
					stud.GenID(++MAcount);
					MAarr[MAi++] = stud;
					break;
				};
				case 33: {
					stud.GenID(++BUcount);
					BUarr[BUi++] = stud;
					break;
				};
				default:
					break;
				}
			}
			system("cls");
			break;
		}
		case 2: { // 打印学生信息
			system("cls");
			for (int i = 0; i < M; i++) {
				if (CSarr[i].studNum > 0) {
					CSarr[i].print();
				}
				else {
					//break; // 打印插入位置非法的学生
				}
			}
			for (int i = 0; i < M; i++) {
				if (MAarr[i].studNum > 0) {
					MAarr[i].print();
				}
				else {
					//break;
				}
			}
			for (int i = 0; i < M; i++) {
				if (BUarr[i].studNum > 0) {
					BUarr[i].print();
				}
				else {
					//break;
				}
			}
			system("pause");
			system("cls");
			break;
		}
		case 3: { // 插入学生信息
			system("cls");
			cout << "输入插入位置：" << endl;
			int num;
			cin >> num;
			num = num - 1;
			cout << "输入：名字 性别 学院字母 入学年份 学院代码" << endl;
			char name[20];
			char college[3];
			char sex;
			int year;
			int colNum;
			cin >> name >> sex >> college >> year >> colNum;
			Student stud(name, sex, college, year, colNum);
			Student studTmp;
			switch (colNum) {
			case 11: {
				stud.GenID(++CScount);
				for (int i = num; i < M; i++) { // 插入位置超过当前输入队列长度，再次输入时会被覆盖；M改成CSi可解决
					studTmp = CSarr[i];
					CSarr[i] = stud;
					stud = studTmp;
				}
				CSi++; // 数组下标增加
				break;
			};
			case 22: {
				stud.GenID(++MAcount);
				for (int i = num; i < M; i++) {
					studTmp = MAarr[i];
					MAarr[i] = stud;
					stud = studTmp;
				}
				MAi++;
				break;
			};
			case 33: {
				stud.GenID(++BUcount);
				for (int i = num; i < M; i++) {
					studTmp = BUarr[i];
					BUarr[i] = stud;
					stud = studTmp;
				}
				BUi++;
				break;
			};
			default:
				break;
			}
			system("pause");
			system("cls");
			break;
		}
		case 4: { // 查找学生信息
			system("cls");
			cout << "输入查询学号：" << endl;
			int num;
			cin >> num;
			int colNum = num / 10000;
			switch (colNum) {
			case 11: {
				for (int i = 0; i < M; i++) {
					if (CSarr[i].studNum == num) {
						CSarr[i].print();
						break;
					}
				}
			}
			case 22: {
				for (int i = 0; i < M; i++) {
					if (MAarr[i].studNum == num) {
						MAarr[i].print();
						break;
					}
				}
			}
			case 33: {
				for (int i = 0; i < M; i++) {
					if (BUarr[i].studNum == num) {
						BUarr[i].print();
						break;
					}
				}
			}
			}
			system("pause");
			system("cls");
			break;
		}
		case 5: { // 统计学生信息
			system("cls");
			Student stud;
			cout << "总人数：" << stud.Total() << endl;
			cout << "计算机学院人数：" << CSi << endl;
			cout << "管理学院人数：" << MAi << endl;
			cout << "土木学院人数：" << BUi << endl;
			system("pause");
			system("cls");
			break;
		}
		case 6: { // 删除学生信息
			system("cls");
			Student stud;
			cout << "输入删除的学号：" << endl;
			int num;
			cin >> num;
			int colNum = num / 10000;
			switch (colNum) {
			case 11: {
				for (int i = 0; i < M; i++) {
					if (CSarr[i].studNum == num) {
						for (int j = i; j < M - 1; j++) {
							CSarr[j] = CSarr[j + 1];
						}
						CSi--;
						stud.setTotal(stud.Total() - 1);
						cout << "删除成功" << endl;
						break;
					}
				}
			}
			case 22: {
				for (int i = 0; i < M; i++) {
					if (MAarr[i].studNum == num) {
						for (int j = i; j < M - 1; j++) {
							MAarr[j] = MAarr[j + 1];
						}
						MAi--;
						stud.setTotal(stud.Total() - 1);
						cout << "删除成功" << endl;
						break;
					}
				}
			}
			case 33: {
				for (int i = 0; i < M; i++) {
					if (BUarr[i].studNum == num) {
						for (int j = i; j < M - 1; j++) {
							BUarr[j] = BUarr[j + 1];
						}
						BUi--;
						stud.setTotal(stud.Total() - 1);
						cout << "删除成功" << endl;
						break;
					}
				}
			}
			default:
				break;
			}
			system("pause");
			system("cls");
			break;
		}
		case 7: { // 读取学生信息
			system("cls");
			Student stud;
			int i = 0;
			// CS
			ifstream fileCS("CS.dat", ios::in | ios::binary);
			while (fileCS.read((char*)&stud, sizeof(Student))) {
				stud.print();
				CSarr[i] = stud;
				i++;
			}
			CScount = stud.studNum % 100;// 读最后一个对象的学号，作为起始值；乱序插入后有bug
			CSi = i;// 初始化数组下标
			i = 0;
			fileCS.close();
			// MA
			ifstream fileMA("MA.dat", ios::in | ios::binary);
			while (fileMA.read((char*)&stud, sizeof(Student))) {
				stud.print();
				MAarr[i] = stud;
				i++;
			}
			MAcount = stud.studNum % 100;
			MAi = i;
			i = 0;
			fileMA.close();
			// BU
			ifstream fileBU("BU.dat", ios::in | ios::binary);
			while (fileBU.read((char*)&stud, sizeof(Student))) {
				stud.print();
				BUarr[i] = stud;
				i++;
			}
			BUcount = stud.studNum % 100;
			BUi = i;
			stud.setTotal(CScount + MAcount + BUcount);
			fileBU.close();
			cout << "读取成功！" << endl;
			system("pause");
			system("cls");
			break;
		}
		case 8: { // 保存
			system("cls");
			ofstream fileCS("CS.dat", ios::out | ios::binary);
			for (int i = 0; i < M; i++) {
				if (CSarr[i].studNum > 0) {
					fileCS.write((char*)&CSarr[i], sizeof(Student));
				}
			}
			fileCS.close();
			ofstream fileMA("MA.dat", ios::out | ios::binary);
			for (int i = 0; i < M; i++) {
				if (MAarr[i].studNum > 0) {
					fileMA.write((char*)&MAarr[i], sizeof(Student));
				}
			}
			fileMA.close();
			ofstream fileBU("BU.dat", ios::out | ios::binary);
			for (int i = 0; i < M; i++) {
				if (BUarr[i].studNum > 0) {
					fileBU.write((char*)&BUarr[i], sizeof(Student));
				}
			}
			fileBU.close();
			cout << "保存成功！" << endl;
			system("pause");
			system("cls");
			break;
		}
		case 9: { // 按学号从小到大排序
			system("cls");
			Student studs[M * 3];
			int index = 0;
			for (int i = 0; i < M; i++) {
				if (CSarr[i].studNum > 0) {
					studs[index] = CSarr[i];
					index++;
				}
				if (MAarr[i].studNum > 0) {
					studs[index] = MAarr[i];
					index++;
				}
				if (BUarr[i].studNum > 0) {
					studs[index] = BUarr[i];
					index++;
				}
			}
			int less = 0;
			Student studTmp;
			Student studTmpSec;
			for (int i = 0; i < M * 3; i++) {
				if (studs[i].studNum > 0) {
					for (int j = i + 1; j < M * 3; j++) {
						if (studs[j].studNum > 0 && studs[i].studNum - studs[j].studNum > less) {
							less = studs[i].studNum - studs[j].studNum;
							index = j;
						}
					}
					if (less) {
						// 插入到i位置 然后后移
						studTmp = studs[i];
						studs[i] = studs[index];
						for (int j = i + 1; j < M * 3; j++) {
							studTmpSec = studs[j];
							studs[j] = studTmp;
							studTmp = studTmpSec;
						}
						// 删除 然后前移
						for (int j = index + 1; j < M * 3 - 1; j++) {
							studs[j] = studs[j + 1];
						}
						// studs[index].print();
						less = 0;
					}
				}
			}
			for (int i = 0; i < M * 3; i++) {
				if (studs[i].studNum > 0) {
					studs[i].print();
				}
			}
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