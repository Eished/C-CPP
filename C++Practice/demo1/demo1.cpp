#include <iostream>
#include <string>
#include <memory>
using namespace std;

struct B;
struct A {
	shared_ptr<B>pb;
	~A() {
		cout << "~A" << endl;
	}
};
struct B
{
	shared_ptr<A>pa;
	~B() {
		cout << "~B" << endl;
	}
};
struct BW;
struct AW {
	shared_ptr<BW>pb;
	~AW() {
		cout << "~AW" << endl;
	}
};

struct BW
{
	weak_ptr<AW>pa;
	~BW() {
		cout << "~BW" << endl;
	}
};
// pa和pb存在着循环引用，根据 shared_ptr引用计数的原理，pa和pb都无法被正常的释放
// weak ptr是为了解决 shared ptr双向引用的问题
void Test() {
	cout << "Test shared_ptr and shared_ptr:" << endl;
	shared_ptr<A>tA(new A());
	shared_ptr<B>tB(new B());
	cout << tA.use_count() << endl; // 1
	cout << tB.use_count() << endl; // 1
	tA->pb = tB;
	tB->pa = tA;
	cout << tA.use_count() << endl; // 2
	cout << tB.use_count() << endl; // 2
};

void Test2() {
	cout << "Test weak_ptr and shared_ptr:" << endl;
	shared_ptr<AW>tA(new AW());
	shared_ptr<BW>tB(new BW());
	cout << tA.use_count() << endl; // 1
	cout << tB.use_count() << endl; // 1
	tA->pb = tB;
	tB->pa = tA;
	cout << tA.use_count() << endl; // 1
	cout << tB.use_count() << endl; // 2
};
int main()
{

	Test();
	Test2();
	void (*p)();
	p = Test;

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