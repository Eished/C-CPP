#include <iostream>
#include <string>

using namespace std;

class Student {
	public:
		int id;
		string name;
		char gender;
		string institute;
		int year;
		int studNo;

		Student();
		Student(string name, char gender, string institute, int year, int studNo);

		void GenID();
		void Print();
};

Student::Student() {};

Student::Student(string name, char gender, string institute, int year, int studNo) {
	this->name=name;
	this->gender=gender;
	this->institute=institute;
	this->year=year;
	this->studNo=studNo;
};

void Student::Print() {
//	cout << id << name << " " << gender << " " << institute << " " << year << " " << studNo << endl;
	cout << name << " ";
};

void Student::GenID() {
	if(institute == "CS") {
		id = 11*10000 + year%100*100 + studNo;
	} else if(institute == "MA") {
		id = 22*10000 + year%100*100 + studNo;
	} else if(institute == "BU") {
		id = 33*10000 + year%100*100 + studNo;
	}
}

void PrintInfo(int size, Student *arr);

int main() {
//	cout<<"hello"<<endl;
//	Student stud("张三 ", 'F', "CS", 2019, 34);
//	stud.Print();
	Student csArr[20];
	Student maArr[20];
	Student buArr[20];
	int csIndex=0;
	int maIndex=0;
	int buIndex=0;
//	csArr[0]=stud;
//	csArr[0].Print();

	int t=0;
	cin>>t;
	for(int i=0; i<t; i++) {
		string name;
		char gender;
		string institute;
		int year;
		int studNo;
		cin >> name >> gender >> institute >> year >> studNo;
		Student stud(name, gender, institute, year, studNo);
		stud.GenID();
		if(institute == "CS") {
			csArr[csIndex++]=stud;
		} else if(institute == "MA") {
			maArr[maIndex++]=stud;
		} else if(institute == "BU") {
			buArr[buIndex++]=stud;
		}
//		stud.Print();
	}

	PrintInfo(csIndex, csArr);
	PrintInfo(maIndex, maArr);
	PrintInfo(buIndex, buArr);

//	if(csIndex==0) {
//		cout<< "no student";
//	} else {
//		for(int i=0; i<csIndex; i++) {
//			csArr[i].Print();
//		}
//	}
//	cout << endl;
//
//	if(maIndex==0) {
//		cout<< "no student";
//	} else {
//		for(int i=0; i<maIndex; i++) {
//			maArr[i].Print();
//		}
//	}
//	cout << endl;
//
//	if(buIndex==0) {
//		cout<< "no student";
//	} else {
//		for(int i=0; i<buIndex; i++) {
//			buArr[i].Print();
//		}
//	}
//	cout << endl;
}

void PrintInfo(int size, Student *arr) {
	if(size==0) {
		cout<< "no student";
	} else {
		for(int i=0; i<size; i++) {
			arr[i].Print();
		}
	}
	cout << endl;
};
