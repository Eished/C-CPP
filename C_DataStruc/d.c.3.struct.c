#include <stdio.h>
struct weapon //自定义类型
{
  char name[20];
  int atk;
  int price;
} weapon_2; //可以直接在尾部定义变量
int main()
{
  int a = 0;
  float b = 0.0;

  weapon weapon_1 = {"weapon_name", 100, 200};
  printf("%s\n%d\n", weapon_1.name, ++weapon_1.price);

  // 结构体指针
  struct weapon *w;
  w = &weapon_1;
  printf("name=%s\n", (*w).name); //点运算符优先级高于 * ，要加括号
  // 使用指针指向运算符
  printf("name=%s\n", w->name);

  // 结构体数组的使用方法
  struct weapon weapon_2[2] = {"weapon_name1", 100, 200, "weapon_name2", 300, 400}; //每个数据项可以用{}括起来
  printf("%s\n%d\n", weapon_2[0].name, weapon_2[1].atk);

  // 指针指针结构体数组
  struct weapon *p;
  p = weapon_2; // p->name;  p 里面是 wapon_2[0].name
  printf("name=%s\n", p->name);
  // p+1 指针第二个成员
  printf("name=%s\n", (++p)->name);

  return 0;
}