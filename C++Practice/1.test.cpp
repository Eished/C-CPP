#include <iostream>
// #include <stdafx>
#include <assert.h>
#include <string.h>
#include <vector>
using namespace std;
int main()
{
  // int a[] = {1, 2, 3, 4};
  // int len = sizeof(a) / sizeof(a[0]); //得到数组容量
  // for (int index = 0; index < len; ++index)
  // {
  //   if (a[index] == 3)
  //   {
  //     cout << index << endl;
  //     return index;
  //   }
  // }

  // int a[2][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}};
  // for (int row = 0; row < 2; row++)
  // {
  //   for (int col = 0; col < 4; col++)
  //   {
  //     cout << a[row][col] << " ";
  //   }
  //   cout << endl;
  // }
  vector<int> vec = {1, 2, 3, 4};
  // 先查看大小，自动扩容
  for (int i = 0; i < vec.size(); i++)
  {
    cout << vec[i] << " " << vec.capacity() << " " << vec.size() << endl;
  }
  cout << "尾部插入" << endl;
  vec.push_back(5); // 尾部插入
  for (int i = 0; i < vec.size(); i++)
  {
    cout << vec[i] << " " << vec.capacity() << " " << vec.size() << endl;
  }
  cout << "尾部删除" << endl;
  vec.pop_back(); // 从尾部删除
  for (int i = 0; i < vec.size(); i++)
  {
    cout << vec[i] << " " << vec.capacity() << " " << vec.size() << endl;
  }
  cout << "指定位置插入" << endl;
  vec.insert(vec.end() - 1, 6); // 指定位置插入
  for (int i = 0; i < vec.size(); i++)
  {
    cout << vec[i] << " " << vec.capacity() << " " << vec.size() << endl;
  }
  cout << "指定位置删除" << endl;
  vec.erase(vec.end() - 2); // 指定位置删除
  for (int i = 0; i < vec.size(); i++)
  {
    cout << vec[i] << " " << vec.capacity() << " " << vec.size() << endl;
  }
  cout << endl;
}