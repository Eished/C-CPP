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

void Input(Student csArr[],Student maArr[],Student buArr[]);

void Ins(int index, Student stud, Student studArr[], int &arrIndex);

void Del(int id, Student csArr[], Student maArr[], Student buArr[]);

void Qurey(int id, Student csArr[], Student maArr[], Student buArr[]);

int main() {
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

	int n;
	cin>>n;
	for(int i=0; i<n; i++) {
		Student stud;
		cin >> stud.id >> stud.name >> stud.gender >> stud.institute;
		if(stud.institute == "CS") {
			csArr[csIndex++] = stud;
		} else if(stud.institute == "MA") {
			maArr[maIndex++] = stud;
		} else if(stud.institute == "BU") {
			buArr[buIndex++] = stud;
		}
//		stud.Print();
	}

	int c;
	cin>>c;
	for(int i=0; i<c; i++) {
		char command;
		cin >> command;
		if(command=='I') {
			int index;
//			int id;
//			string name;
//			char gender;
//			string insti;
			Student stud;
			cin>> index >> stud.id >> stud.name >> stud.gender >> stud.institute;
//			cout<< command << index << id << name << gender<< insti <<endl;
			if(stud.institute == "CS") {
				Ins(index, stud, csArr, csIndex);
				PrintInfo(csIndex,csArr);
			} else if(stud.institute=="MA") {
				Ins(index, stud, maArr, maIndex);
			} else if(stud.institute=="BU") {
				Ins(index, stud, buArr, buIndex);
			}
		} else if(command=='D') {
			int id;
			cin>>id;
//			Del(id,csArr,maArr,buArr);
//			cout<<command<< id<<endl;
			int insti;
			insti=id/10000;
			if(insti==11) {
//				cout<<insti;
				for(int j=0; j<csIndex; j++) {
					if(csArr[j].id==id) {
//						csArr[j].Print();
						cout << csArr[j].id  << " "<< csArr[j].name << " " << ((csArr[j].gender=='F')?"女":"男") << " " << csArr[j].institute << " " << endl;
						return 0;
					}
				}
				cout<< "Delete no such ID"<<endl;
			} else if(insti==22) {
				for(int j=0; j<maIndex; j++) {
					if(maArr[j].id==id) {
						cout << maArr[j].id  << " "<< maArr[j].name << " " << ((maArr[j].gender=='F')?"女":"男") << " " << maArr[j].institute << " " << endl;
						return 0;
					}
				}
				cout<< "Delete no such ID"<<endl;
			} else if(insti==33) {
				for(int j=0; j<buIndex; j++) {
					if(buArr[j].id==id) {
						cout << buArr[j].id << " " << buArr[j].name << " " << ((buArr[j].gender=='F')?"女":"男") << " " << buArr[j].institute << " " << endl;
						return 0;
					}
				}
				cout<< "Delete no such ID"<<endl;
			}

		} else if(command=='Q') {
			int id;
			cin>>id;
			int insti;
			insti=id/10000;
			if(insti==11) {
//				cout<<insti;
				for(int j=0; j<csIndex; j++) {
					if(csArr[j].id==id) {
//						csArr[j].Print();
						cout << csArr[j].id  << " "<< csArr[j].name << " " << ((csArr[j].gender=='F')?"女":"男") << " " << csArr[j].institute << " " << endl;
						return 0;
					}
				}
				cout<< "Delete no such ID"<<endl;
			} else if(insti==22) {
				for(int j=0; j<maIndex; j++) {
					if(maArr[j].id==id) {
						cout << maArr[j].id  << " "<< maArr[j].name << " " << ((maArr[j].gender=='F')?"女":"男") << " " << maArr[j].institute << " " << endl;
						return 0;
					}
				}
				cout<< "Delete no such ID"<<endl;
			} else if(insti==33) {
				for(int j=0; j<buIndex; j++) {
					if(buArr[j].id==id) {
						cout << buArr[j].id << " " << buArr[j].name << " " << ((buArr[j].gender=='F')?"女":"男") << " " << buArr[j].institute << " " << endl;
						return 0;
					}
				}
				cout<< "Delete no such ID"<<endl;
			}
		}
	}
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

void Input(Student csArr[],Student maArr[],Student buArr[]) {
//	int n;
//	cin>>n;
//	for(int i=0; i<n; i++) {
//		Student stud;
//		cin >> stud.id >> stud.name >> stud.gender >> stud.institute;
//		if(stud.institute == "CS") {
//			csArr[csIndex++]=stud;
//		} else if(stud.institute == "MA") {
//			maArr[maIndex++]=stud;
//		} else if(stud.institute == "BU") {
//			buArr[buIndex++]=stud;
//		}
//	}
}


void Ins(int index, Student stud, Student studArr[], int &arrIndex) {
	for(int i = arrIndex; i >= index; i--) {
		studArr[i] = studArr[i-1];
	}
	studArr[index-1] = stud;
	arrIndex++;
};

void Del(int id, Student csArr[], Student maArr[], Student buArr[]) {
	int insti;
	insti=id/10000;
//	cout<<insti;
	if(insti==11) {
		cout<<insti;
	} else if(insti==22) {
		cout<<insti;
	} else if(insti==33) {
		cout<<insti;
	}
};

void Query(int id, Student csArr[], Student maArr[], Student buArr[]) {
	int insti;
	insti=id/10000;
//	cout<<insti;
	if(insti==11) {
		cout<<insti;
	} else if(insti==22) {
		cout<<insti;
	} else if(insti==33) {
		cout<<insti;
	}
};