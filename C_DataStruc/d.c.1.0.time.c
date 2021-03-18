// #include <stdio.h>
// long f(int n)
// {
//   if (n == 0)
//     return 1;
//   else
//     return n * f(n - 1);
// }
// int main()
// {
//   int m, n = 3;
//   m = f(n);
//   printf("%d!=%d\n", n, m);
// }

//　　代码实现：
#include <stdio.h>
long f(int n)
{
  if (n == 1)
    return 1;
  else
    return n * f(n - 1);
}
int main()
{
  int m, n = 3;
  m = f(n);
  printf("%d!=%d\n", n, m);
}

#define MAXSIZE 20   //设记录不超过 20个
typedef int KeyType; //设关键字为整型量(int 型)
typedef struct
{                     //定义每个记录(数据元素)的结构
  KeyType key;        //关键字
  InfoType otherinfo; //其它数据项
} RedType;

typedef struct
{                         //定义顺序表的结构
  RedType r[MAXSIZE + 1]; //存 储顺序表的向量, //r[0]-般作哨兵或缓冲区
  int length;             //顺序表的长度
} SqList;
typedef struct
{ //要背下来
  RedType r[MAXSIZE + 1];
  int length;
} SqList;
