#include <iostream>
using namespace std;

class Book
{
public:
  int a = 0, b = 1, c = 2;
  Book()
  {
    cout << a << b << c << endl;
  };
  void print()
  {
    cout << "Print:" << a << endl;
  };
};

struct Food
{
  char a[10];
  int b;
};

struct Rice : Book
{
};
int main()
{
  // class
  Book book;
  book.print();
  cout << book.a << endl;
  book.a = 999;
  cout << book.a << endl;

  // struct
  Food food;
  // food.a = "ljoujo"; 字符串数组，不能直接赋值
  // 使用复制字符串函数
  strcpy(food.a, "milk");
  cout << food.a << endl;
  // 数字可以赋值
  food.b = 1;
  cout << food.b << endl;

  // 结构体继承类
  Rice rice;
  rice.print();
  cout << rice.a << endl;
  rice.a = 999;
  cout << rice.a << endl;

  return 0;
}