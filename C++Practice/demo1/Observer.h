#pragma once

#ifndef OBSEVER_H_1

#define OBSEVER_H_1

#include<iostream>
using namespace std;

class Observer
{
public:
	Observer() { ; }
	virtual ~Observer() { ; }
	// �����۲�������仯ʱ��֪ͨ���۲��ߵ����������
	virtual void Update(void* pArg) {

	}
};
#endif