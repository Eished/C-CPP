#include <iostream>
#include <string>
#include <memory>
//#include"Singleton.h"
//#include"Observer.h"
using namespace std;

//struct B;
//struct A {
//	shared_ptr<B>pb;
//	~A() {
//		cout << "~A" << endl;
//	}
//};
//struct B
//{
//	shared_ptr<A>pa;
//	~B() {
//		cout << "~B" << endl;
//	}
//};
//struct BW;
//struct AW {
//	shared_ptr<BW>pb;
//	~AW() {
//		cout << "~AW" << endl;
//	}
//};
//
//struct BW
//{
//	weak_ptr<AW>pa;
//	~BW() {
//		cout << "~BW" << endl;
//	}
//};
//// pa和pb存在着循环引用，根据 shared_ptr引用计数的原理，pa和pb都无法被正常的释放
//// weak ptr是为了解决 shared ptr双向引用的问题
//void Test() {
//	cout << "Test shared_ptr and shared_ptr:" << endl;
//	shared_ptr<A>tA(new A());
//	shared_ptr<B>tB(new B());
//	cout << tA.use_count() << endl; // 1
//	cout << tB.use_count() << endl; // 1
//	tA->pb = tB;
//	tB->pa = tA;
//	cout << tA.use_count() << endl; // 2
//	cout << tB.use_count() << endl; // 2
//};
//
//void Test2() {
//	cout << "Test weak_ptr and shared_ptr:" << endl;
//	shared_ptr<AW>tA(new AW());
//	shared_ptr<BW>tB(new BW());
//	cout << tA.use_count() << endl; // 1
//	cout << tB.use_count() << endl; // 1
//	tA->pb = tB;
//	tB->pa = tA;
//	cout << tA.use_count() << endl; // 1
//	cout << tB.use_count() << endl; // 2
//};

//class User1 :public Observer {
//	virtual void Update(void* pArg) {
//		cout << "User1" << endl;
//	}
//};
//class User2 :public Observer {
//	virtual void Update(void* pArg) {
//		cout << "User2" << endl;
//	}
//};

// 虚函数 动态类型转换
class Base {
public:
	Base() :_i(0) { ; }
	virtual void T() { cout << "Base" << endl; }
private:
	int _i;
};
class Derived :public Base
{
public:
	Derived() :_j(0) { ; }
	virtual void T() { cout << "Derived" << endl; }
private:
	int _j;
};
int main()
{
	double a = 1.1;
	double e = 2;
	int b = int(a);
	double c = double(b + a);
	cout << b << endl;
	cout << b + 0.1 << endl;
	cout << c << endl;
	cout << e + 0.1 << endl;

	Base cb;
	Derived cd;
	Base* pcb;
	Derived* pcd;

	// 子类——> 父类
	pcb = static_cast<Base*>(&cd);
	pcb = dynamic_cast<Base*>(&cd);
	if (pcb == NULL)
	{
		cout << "unsafe dynamic_cast D to B" << endl;
	}
	// 父类——> 子类
	pcd = static_cast<Derived*>(&cb);
	pcd = dynamic_cast<Derived*>(&cb);
	if (pcd == NULL)
	{
		cout << "unsafe dynamic_cast B to D" << endl;
	}

	//User1 u1;
	//User2 u2;

	//Singleton::getInstance()->Do();


	//Test();
	//Test2();
	//void (*p)();
	//p = Test;

	//// unique_ptr
	//auto w = std::make_unique<int>(10);
	//cout << *(w.get()) << endl;
	////auto w2 = w; // 编译错误如果想要把w复制给w2，是不可以的。
	////因为复制从语义上来说，两个对象将共享同一块内存

	////unique ptr只支持移动语义，即如下
	//auto w2 = std::move(w);
	//cout << ((w.get() != nullptr) ? (*w.get()) : -1) << endl;
	//cout << ((w2.get() != nullptr) ? (*w2.get()) : -1) << endl;

	//{
	//	auto wA = shared_ptr<int>(new int(20));
	//	{
	//		auto wB = wA;
	//		cout << ((wA.get() != nullptr) ? (*wA.get()) : -1) << endl; //20
	//		cout << ((wB.get() != nullptr) ? (*wB.get()) : -1) << endl; //20
	//		cout << wA.use_count() << endl; //2
	//		cout << wB.use_count() << endl; //2
	//	}
	//	//cout << wB.use_count() << endl;
	//	cout << wA.use_count() << endl;
	//}
	return 0;
}