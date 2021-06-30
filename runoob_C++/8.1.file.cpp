#include <fstream>
#include <iostream>

using namespace std;

int main()
{
  char data[100];

  // 以写模式打开文件
  fstream file;
  file.open("afile.dat", ios::in | ios::out | ios::trunc);

  cout << "Writing to the file" << endl;
  cout << "Enter your name: ";
  cin.getline(data, 100);

  // 向文件写入用户输入的数据
  file << data << endl;

  // cout << "Enter your age: ";
  // cin >> data;
  // cin.ignore();

  // 再次向文件写入用户输入的数据
  // file << data << endl;

  file >> data;
  cout << "data:" << data << endl;

  // // 再次从文件读取数据，并显示它
  // file >> data;
  // cout << "data:" << data << endl;

  file.close();
  return 0;
}