#include <stdio.h>
struct weapon //自定义类型作为节点元素
{
  int price;
  int atk;
  struct weapon *next; // 存放下一个节点的地址
};
int main()
{
  struct weapon a, b, c, *head;
  a.price = 100;
  a.atk = 100;
  b.price = 200;
  b.atk = 200;
  c.price = 300;
  c.atk = 300;
  // 连成链表
  head = &a;
  a.next = &b;
  b.next = &c;
  c.next = NULL;
  // 生成指针p 访问结点
  struct weapon *p;
  p = head;
  while (p != NULL)
  {
    printf("%d,%d\n", p->atk, p->price);
    p = p->next;
  }

  return 0;
}