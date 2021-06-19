#pragma once
#include<iostream>
using namespace std;
class Singleton
{
public:
	static const Singleton* getInstance();
	static void Do() {
		cout << "DO" << endl;
	}
private:
	// 将构造和析构函数私有化，防止外部访问
	Singleton() {};
	~Singleton() {};

	static Singleton* This; // 使用静态变量帮助解决资源的分配和释放
};
