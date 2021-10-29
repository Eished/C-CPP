#include <iostream>
#include <string>

using namespace std;

class Student {
	private:
		static int total;
	
	public:
		int id;
		string name;
		char gender;
		string institute;
		
		Student();
		Student(string name, char gender, string institute);

		void GenID(int year,int studNo);
		void Print();
};

Student::Student() {};

Student::Student(string name, char gender, string institute) {
	this->name=name;
	this->gender=gender;
	this->institute=institute;
};

void Student::Print() {
//	cout << id << name << " " << gender << " " << institute << " " << endl;
	cout << name << " ";
};

void Student::GenID(int year,int studNo) {
	if(institute == "CS") {
		id = 11*10000 + year%100*100 + studNo;
	} else if(institute == "MA") {
		id = 22*10000 + year%100*100 + studNo;
	} else if(institute == "BU") {
		id = 33*10000 + year%100*100 + studNo;
	}
}

void PrintInfo(int size, Student arr[]);

void Input();

void Ins();

void Del();

void Qurey();

int main() {
//	Student stud("ÕÅÈý ", 'F', "CS", 2019, 34);
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
		Student stud(name, gender, institute);
		stud.GenID(year, studNo);
		if(institute == "CS") {
			csArr[csIndex++]=stud;
		} else if(institute == "MA") {
			maArr[maIndex++]=stud;
		} else if(institute == "BU") {
			buArr[buIndex++]=stud;
		}
	}

	PrintInfo(csIndex, csArr);
	PrintInfo(maIndex, maArr);
	PrintInfo(buIndex, buArr);
	
}

void PrintInfo(int size, Student arr[]) {
	if(size==0) {
		cout<< "no student";
	} else {
		for(int i=0; i<size; i++) {
			arr[i].Print();
		}
	}
	cout << endl;
};

void Input(){
	
}