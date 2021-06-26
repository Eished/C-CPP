
#include <iostream>
using namespace std;

int main()
{
	//std::cout << "Hello World!\n";
	enum num
	{
		a,
		b = 5,
		c,
	} numA;
	numA = a;
	cout << numA << endl;
	numA = b;
	cout << numA << endl;
	num d = c;
	numA = d;
	//numA = 3;
	cout << numA << endl;
}
