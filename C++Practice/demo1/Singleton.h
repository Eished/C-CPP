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
	// ���������������˽�л�����ֹ�ⲿ����
	Singleton() {};
	~Singleton() {};

	static Singleton* This; // ʹ�þ�̬�������������Դ�ķ�����ͷ�
};
