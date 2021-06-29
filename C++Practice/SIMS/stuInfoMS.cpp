#include <iostream>
#include <vector>
#include"Student.h"

using namespace std;

int main() {
	Student stud("ÕÅÈı", 'M', "CS", 2021, 22);
	stud.print();
	stud.GenID();
	return 0;
}