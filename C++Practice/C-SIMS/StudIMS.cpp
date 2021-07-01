#include "Student.h"
#include <iostream>
#include <fstream>
#define M 30

using namespace std;

void display() {
	cout << "1:����ѧ����Ϣ\n" << endl;
	cout << "2:��ӡѧ����Ϣ\n" << endl;
	cout << "3:����ѧ����Ϣ\n" << endl;
	cout << "4:����ѧ����Ϣ\n" << endl;
	cout << "5:ͳ��ѧ����Ϣ\n" << endl;
	cout << "6:ɾ��ѧ����Ϣ\n" << endl;
	cout << "7:��ȡѧ����Ϣ\n" << endl;
	cout << "8:����ѧ����Ϣ\n" << endl;
	cout << "9:��ѧ�Ŵ�С��������\n" << endl;
	cout << "0:�˳�\n" << endl;
	cout << "�������Ӧ����ţ�" << endl;
};

int main() {
	Student CSarr[M]; // ѧ������
	Student MAarr[M];
	Student BUarr[M];
	int CScount = 0; // ѧ��˳��ţ�ֻ������
	int MAcount = 0;
	int BUcount = 0;
	int CSi = 0; // ѧ�������±�λ��
	int MAi = 0;
	int BUi = 0;
	while (true) {
		display();
		int cho;
		cin >> cho;
		switch (cho) {
		case 1: { // ����ѧ����Ϣ
			system("cls");
			int t = 0;
			cout << "����¼��������" << endl;
			cin >> t;
			cout << "���룺���� �Ա� ѧԺ��ĸ ��ѧ��� ѧԺ����" << endl;
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
		case 2: { // ��ӡѧ����Ϣ
			system("cls");
			for (int i = 0; i < M; i++) {
				if (CSarr[i].studNum > 0) {
					CSarr[i].print();
				}
				else {
					//break; // ��ӡ����λ�÷Ƿ���ѧ��
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
		case 3: { // ����ѧ����Ϣ
			system("cls");
			cout << "�������λ�ã�" << endl;
			int num;
			cin >> num;
			num = num - 1;
			cout << "���룺���� �Ա� ѧԺ��ĸ ��ѧ��� ѧԺ����" << endl;
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
				for (int i = num; i < M; i++) { // ����λ�ó�����ǰ������г��ȣ��ٴ�����ʱ�ᱻ���ǣ�M�ĳ�CSi�ɽ��
					studTmp = CSarr[i];
					CSarr[i] = stud;
					stud = studTmp;
				}
				CSi++; // �����±�����
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
		case 4: { // ����ѧ����Ϣ
			system("cls");
			cout << "�����ѯѧ�ţ�" << endl;
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
		case 5: { // ͳ��ѧ����Ϣ
			system("cls");
			Student stud;
			cout << "��������" << stud.Total() << endl;
			cout << "�����ѧԺ������" << CSi << endl;
			cout << "����ѧԺ������" << MAi << endl;
			cout << "��ľѧԺ������" << BUi << endl;
			system("pause");
			system("cls");
			break;
		}
		case 6: { // ɾ��ѧ����Ϣ
			system("cls");
			Student stud;
			cout << "����ɾ����ѧ�ţ�" << endl;
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
						cout << "ɾ���ɹ�" << endl;
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
						cout << "ɾ���ɹ�" << endl;
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
						cout << "ɾ���ɹ�" << endl;
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
		case 7: { // ��ȡѧ����Ϣ
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
			CScount = stud.studNum % 100;// �����һ�������ѧ�ţ���Ϊ��ʼֵ������������bug
			CSi = i;// ��ʼ�������±�
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
			cout << "��ȡ�ɹ���" << endl;
			system("pause");
			system("cls");
			break;
		}
		case 8: { // ����
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
			cout << "����ɹ���" << endl;
			system("pause");
			system("cls");
			break;
		}
		case 9: { // ��ѧ�Ŵ�С��������
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
						// ���뵽iλ�� Ȼ�����
						studTmp = studs[i];
						studs[i] = studs[index];
						for (int j = i + 1; j < M * 3; j++) {
							studTmpSec = studs[j];
							studs[j] = studTmp;
							studTmp = studTmpSec;
						}
						// ɾ�� Ȼ��ǰ��
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