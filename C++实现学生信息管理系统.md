# C++ 实现学生信息管理系统

## 考试题目：

### A：学生信息存储（40分）

1. **业务描述：**

   - 某学校的学生信息包括：学号、姓名、性别、学院。

   - 其中学号是整数；性别用单个大写字母表示，F 表示女性，M 表示男性；姓名是字符串类型。

   - 学生学号固定长度6位，前两位表示学院，例如计算机学院编码 11，则首两位编码是 11；

     中间两位表示入学年份，例如学生是 2019 年入学，则中间编码为 19：最后两位是自动按序编号，例如学生是 2019 年入学计算机学院的第56号学生，则学号为 111956。

   - 假设学校有三个学院：

     - 计算机学院编码 11， 
     - 管理学院编码 22，
     - 土木学院编码 33。

2. **程序开发要求：**

   1. 要求使用 C++ 语言与面对对象设计思想实现开发。
   2. 定义一个学生类，包含上述学生信息。
   3. 在学生类中，定义输出函数 `Print` ，输出一个学生对象的信息。
   4. 定义学号生成函数 `GenID`，根据学生所属的学院、入学年份、学院顺序号，生成学生的学号。
   5. 学生类中，可以根据需要增加成员函数，但不能增加数据成员。
   6. 在主函数中，创建三个对象数组，对应三个学院，分别存储三个学院的学生对象。

3. **输入：**

   1. 第一行输入t，表示有t个学生。
   2. 接着输入t行，每行输入一个学生信息共五个参数，包括姓名、性别、学院、入学年份和学院顺序号，数据之间用空格隔开。其中学院用缩写表示，CS 表示计算机学院，MA 表示管理学院，BU 表示土木学院。
   3. 每输入一个学生信息，就调用函数 `GenID` 生成学生学号，并创建一个新的学生对象。然后根据学院缩写，把新学生插入到对应对象数组的末尾。
   4. 数据输入的具体格式参考输入样例。

### B：学生信息操作（50分）

1. **业务描述：**

   - 在前一题的基础上：加入增加、删除、查询的信息操作
   - 某学核的学生信息包括：学号、姓名、性别、学院。其中学号是整数；性别用单个大写字母表示，F 示女性，M 示男性；姓名是字符串类型。假设学校有三个学院：计算机字院编码11，管理学院编码 22，土木学院编码 33。
   - 编写一个程序完成学生信息的插入、存储、输出、增加、删除、查询等功能

2. **程序开发要求：**

   1. 要求使用C++语言与面向对象设计思想实现开发。
   2. 定义一个学生类，不仅包含上述学生信息，还要增加静态数据成员 `total`，表示学生总数。要求静态数据成员必须是private。
   3. 在学生中定义输出函数 `Print`，输出一个学生对象的信息。
   4. 学生类中可以根据需要增加成员函数，但不能增加据成员

3. **在主函数中，完成以下要求：**

   1. 创建三个对象数组，对应三个学院，分别存储三个学院的学生对象

   2. 定义插入函数 `Ins`，先创建一个新学生对象，根据学院缩写把新学生插入到对应数组的指定位置；插入前，指定位置上的原学生对象以及后面的学生对象都要往后移动一位。

      提示：无需考虑插入位置非法的问题；题目的插入数组位置从 1 开始计算；每增加一个新学生，学生总数加 1。

   3. 定义删除函数 `Del`，根据提供的学号先找到学生对象，删除对应数组的对应学生对象；刪除后，刪除位置后面的学生对象都要往前移动一位。

      提示：每删除一个学生，学生总数减1。

   4. 定义查询函数 `Query`，根据提供的学号，查询学生是否存在，并调用输出的数 `Print` 信息作输出。

   5. 学生总数的所有操作都必须使用学生类的静态数据 `total` 来进行，不能在类外使用其他函数或变量进行统计。

### C：学生学号排序（10分）

1. **业务描述：**
   - 现在需要对学号进行排序。设有一个数组存储了所有学院所有学生的对象，采用简单选择排序法，实现所有学生对象学号从小到大排序。
   - 简单选择排序算法说明
     - 假设 `n` 为待排序记录数，每一趟（例如第 `i` 趟，`i=1,2,...,n-1`）有 `n-i+1` 个待排序记录，
     - 在第 `i` 趟中，通过 `n-i` 次比较，选出关键字最小的记录，与第 `i` 个记录交换。
2. **程序开发要求：**
   1. 必须使用简单选择排序实现学生排序。
   2. 不允许使用第三方对象或函数实现排序，学生必须写出完整的排序算法。
   3. 无需考虑学号相同的情况。

## 功能实现：

### A：学生信息存储

- 输入文字：

张三 M CS 2019 11

杨六 M CS 2018 11

胡七 M CS 2017 11

李四 M MA 2020 22

王五 F BU 2019 33

- 功能设计：

```C++
	cout << "1:输入学生信息\n" << endl;
	cout << "2:打印学生信息\n" << endl;
	cout << "3:插入学生信息\n" << endl;
	cout << "4:查找学生信息\n" << endl;
	cout << "5:修改学生信息\n" << endl;
	cout << "6:删除学生信息\n" << endl;
	cout << "7:读取学生信息\n" << endl;
	cout << "8:保存学生信息\n" << endl;
	cout << "9:按学号从小到大排序\n" << endl;
	cout << "0:退出\n" << endl;
	cout << "请输入对应的序号：" << endl;
```



### B：学生信息操作

### C：学生学号排序

#### STL vector 版：

1. stuInfoMS.cpp

   ```C++
   #include <iostream>
   #include <vector>
   #include <fstream>
   #include "Student.h"
   #include "myfunc.h"
   
   using namespace std;
   
   vector<Student> CSarr;
   vector<Student> MAarr;
   vector<Student> BUarr;
   int main() {
   	while (true) {
   		display();
   		int cho;
   		cin >> cho;
   		switch (cho) {
   		case 1: { // 输入学生信息
   			input();
   			system("cls");
   			break;
   		}
   		case 2: { // 打印学生信息
   			system("cls");
   			printAll();
   			system("pause");
   			system("cls");
   			break;
   		}
   		case 3: { // 插入学生信息
   			Ins();
   			system("cls");
   			break;
   		}
   		case 4: { // 查找学生信息
   			Query();
   			system("pause");
   			system("cls");
   			break;
   		}
   		case 5: { // 修改学生信息
   			modify();
   			system("pause");
   			system("cls");
   			break;
   		}
   		case 6: { // 删除学生信息
   			Del();
   			system("cls");
   			break;
   		}
   		case 7: { // 读取学生信息
   			system("cls");
   			Read();
   			cout << "读取成功！" << endl;
   			system("pause");
   			system("cls");
   			break;
   		}
   		case 8: { // 保存
   			Save();
   			cout << "保存成功！" << endl;
   			system("pause");
   			system("cls");
   			break;
   		}
   		case 9: { // 按学号从小到大排序
   			system("cls");
   			Sort();
   			system("pause");
   			system("cls");
   			break;
   		}
   		case 0: { // 退出
   			cout << "已退出" << endl;
   			return 0;
   		}
   		default: {
   			cout << "输入不正确!" << endl;
   			system("pause");
   			system("cls");
   			break;
   		}
   		}
   	}
   	return 0;
   }
   
   void display() {
   	cout << "1:输入学生信息\n" << endl;
   	cout << "2:打印学生信息\n" << endl;
   	cout << "3:插入学生信息\n" << endl;
   	cout << "4:查找学生信息\n" << endl;
   	cout << "5:修改学生信息\n" << endl;
   	cout << "6:删除学生信息\n" << endl;
   	cout << "7:读取学生信息\n" << endl;
   	cout << "8:保存学生信息\n" << endl;
   	cout << "9:按学号从小到大排序\n" << endl;
   	cout << "0:退出\n" << endl;
   	cout << "请输入对应的序号：" << endl;
   }
   void input() {
   	int t = 0;
   	cout << "输入学生人数：";
   	cin >> t;
   	cout << "输入：名字 性别 学院字母 入学年份 学院代码" << endl;
   	for (int i = 0; i < t; i++) {
   		char name[20];
   		char college[3];
   		char sex;
   		int year;
   		int colNum;
   		cin >> name >> sex >> college >> year >> colNum;
   		Student stud(name, sex, college, year, colNum);
   		stud.GenID();
   		switch (colNum) {
   		case 11: {
   			CSarr.push_back(stud);
   			break;
   		};
   		case 22: {
   			MAarr.push_back(stud);
   			break;
   		};
   		case 33: {
   			BUarr.push_back(stud);
   			break;
   		};
   		default:
   			break;
   		}
   	}
   }
   void printAll() {
   	cout << "总人数：" << Student::total << endl;
   	cout << "计算机学院人数：" << Student::csCount << endl;
   	cout << "管理学院人数：" << Student::maCount << endl;
   	cout << "土木学院人数：" << Student::buCount << endl;
   	cout << endl;
   	// 输入学院 或 打印全部
   	cout << "计算机学院:" << endl;
   	for (int i = 0; i < CSarr.size(); i++) {
   		CSarr[i].print();
   	}
   	cout << "\n管理学院:" << endl;
   	for (int i = 0; i < MAarr.size(); i++) {
   		MAarr[i].print();
   	}
   	cout << "\n土木学院:" << endl;
   	for (int i = 0; i < BUarr.size(); i++) {
   		BUarr[i].print();
   	}
   	cout << endl;
   }
   
   void Ins() {
   	int t = 0, x = 0;
   	cout << "输入插入位置：";
   	cin >> x;
   	cout << "输入学生人数：";
   	cin >> t;
   	cout << "输入：名字 性别 学院字母 入学年份 学院代码" << endl;
   	for (int i = 0; i < t; i++) {
   		char name[20];
   		char college[3];
   		char sex;
   		int year;
   		int colNum;
   		cin >> name >> sex >> college >> year >> colNum;
   		Student stud(name, sex, college, year, colNum);
   		stud.GenID();
   		switch (colNum) {
   		case 11: {
   			if (CSarr.size() >= x) {
   				CSarr.insert(CSarr.begin() + x - 1, stud);
   			}
   			else {
   				cout << "插入位置大于数组长度" << endl;
   			}
   			break;
   		};
   		case 22: {
   			if (MAarr.size() >= x) {
   				MAarr.insert(MAarr.begin() + x - 1, stud);
   			}
   			else {
   				cout << "插入位置大于数组长度" << endl;
   			}
   			break;
   		};
   		case 33: {
   			if (BUarr.size() >= x) {
   				BUarr.insert(BUarr.begin() + x - 1, stud);
   			}
   			else {
   				cout << "插入位置大于数组长度" << endl;
   			}
   			break;
   		};
   		default:
   			break;
   		}
   	}
   }
   void Query() {
   	int num;
   	cout << "输入查询的学号:" << endl;
   	cin >> num;
   	int	colNum = num / 10000;
   	switch (colNum) {
   	case 11: {
   		for (int i = 0; i < CSarr.size(); i++) {
   			if (CSarr[i].studNum == num)
   			{
   				CSarr[i].print();
   				return;
   			}
   		}
   		cout << "未找到" << endl;
   		break;
   	};
   	case 22: {
   		for (int i = 0; i < MAarr.size(); i++) {
   			if (MAarr[i].studNum == num)
   			{
   				MAarr[i].print();
   				return;
   			}
   		}
   		cout << "未找到" << endl;
   		break;
   	};
   	case 33: {
   		for (int i = 0; i < BUarr.size(); i++) {
   			if (BUarr[i].studNum == num)
   			{
   				BUarr[i].print();
   				return;
   			}
   		}
   		cout << "未找到" << endl;
   		break;
   	};
   	default:
   		break;
   	}
   }
   void Del() {
   	int num;
   	cout << "输入删除的学号:" << endl;
   	cin >> num;
   	int	colNum = num / 10000;
   	switch (colNum) {
   	case 11: {
   		for (int i = 0; i < CSarr.size(); i++) {
   			if (CSarr[i].studNum == num)
   			{
   				CSarr.erase(CSarr.begin() + i);
   				return;
   			}
   		}
   		cout << "未找到" << endl;
   		break;
   	};
   	case 22: {
   		for (int i = 0; i < MAarr.size(); i++) {
   			if (MAarr[i].studNum == num)
   			{
   				MAarr.erase(MAarr.begin() + i);
   				return;
   			}
   		}
   		cout << "未找到" << endl;
   		break;
   	};
   	case 33: {
   		for (int i = 0; i < BUarr.size(); i++) {
   			if (BUarr[i].studNum == num)
   			{
   				BUarr.erase(BUarr.begin() + i);
   				return;
   			}
   		}
   		cout << "未找到" << endl;
   		break;
   	};
   	default:
   		break;
   	}
   }
   
   void modify() {
   	int num;
   	cout << "输入修改的学号:" << endl;
   	cin >> num;
   	int	colNum = num / 10000;
   	switch (colNum) {
   	case 11: {
   		for (int i = 0; i < CSarr.size(); i++) {
   			if (CSarr[i].studNum == num)
   			{
   				CSarr[i].print();
   				cout << endl;
   				char name[20];
   				char college[3];
   				char sex;
   				int year;
   				int colNum;
   				cout << "输入：名字 性别 学院字母 入学年份 学院代码" << endl;
   				cin >> name >> sex >> college >> year >> colNum;
   				strcpy_s(CSarr[i].name, name);
   				strcpy_s(CSarr[i].college, college);
   				CSarr[i].sex = sex;
   				CSarr[i].year = year;
   				CSarr[i].colNum = colNum;
   				CSarr[i].GenID();
   				CSarr[i].print();
   				return;
   			}
   		}
   		cout << "未找到" << endl;
   		break;
   	};
   	case 22: {
   		for (int i = 0; i < MAarr.size(); i++) {
   			if (MAarr[i].studNum == num)
   			{
   				MAarr[i].print();
   				cout << endl;
   				char name[20];
   				char college[3];
   				char sex;
   				int year;
   				int colNum;
   				cout << "输入：名字 性别 学院字母 入学年份 学院代码" << endl;
   				cin >> name >> sex >> college >> year >> colNum;
   				strcpy_s(MAarr[i].name, name);
   				strcpy_s(MAarr[i].college, college);
   				MAarr[i].sex = sex;
   				MAarr[i].year = year;
   				MAarr[i].colNum = colNum;
   				MAarr[i].GenID();
   				MAarr[i].print();
   				return;
   			}
   		}
   		cout << "未找到" << endl;
   		break;
   	};
   	case 33: {
   		for (int i = 0; i < BUarr.size(); i++) {
   			if (BUarr[i].studNum == num)
   			{
   				BUarr[i].print();
   				cout << endl;
   				char name[20];
   				char college[3];
   				char sex;
   				int year;
   				int colNum;
   				cout << "输入：名字 性别 学院字母 入学年份 学院代码" << endl;
   				cin >> name >> sex >> college >> year >> colNum;
   				strcpy_s(BUarr[i].name, name);
   				strcpy_s(BUarr[i].college, college);
   				BUarr[i].sex = sex;
   				BUarr[i].year = year;
   				BUarr[i].colNum = colNum;
   				BUarr[i].GenID();
   				BUarr[i].print();
   				return;
   			}
   		}
   		cout << "未找到" << endl;
   		break;
   	};
   	default:
   		break;
   	}
   }
   
   void Sort() {
   	cout << "总人数：" << Student::total << endl;
   	cout << endl;
   	cout << "简单选择排序算法，从小到大排序:" << endl;
   	vector<Student> studs;
   	int temp = 0;
   	int less = 0;
   	for (int i = 0; i < CSarr.size(); i++) {
   		studs.push_back(CSarr[i]);
   	}
   	for (int i = 0; i < MAarr.size(); i++) {
   		studs.push_back(MAarr[i]);
   	}
   	for (int i = 0; i < BUarr.size(); i++) {
   		studs.push_back(BUarr[i]);
   	}
   	if (studs.size() > 0) {
   		for (int i = 0; i < studs.size(); i++) {
   			for (int j = i + 1; j < studs.size(); j++) {
   				if (studs[i].studNum > studs[j].studNum)
   				{
   					if (studs[i].studNum - studs[j].studNum > less) {
   						less = studs[i].studNum - studs[j].studNum;
   						temp = j;
   					}
   				}
   			}
   			if (less) {
   				studs.insert(studs.begin() + i, studs[temp]);
   				studs.erase(studs.begin() + temp + 1);
   				less = 0;
   			}
   		}
   	}
   	else {
   		cout << "没有数据" << endl;
   	}
   	cout << endl;
   	for (int i = 0; i < studs.size(); i++) {
   		studs[i].print();
   	}
   }
   
   void Save() {
   	ofstream fileCS("CS.dat", ios::out | ios::binary);
   	for (int i = 0; i < CSarr.size(); i++) {
   		fileCS.write((char*)&CSarr[i], sizeof(Student));
   	}
   	ofstream fileMA("MA.dat", ios::out | ios::binary);
   	for (int i = 0; i < MAarr.size(); i++) {
   		fileMA.write((char*)&MAarr[i], sizeof(Student));
   	}
   	ofstream fileBU("BU.dat", ios::out | ios::binary);
   	for (int i = 0; i < BUarr.size(); i++) {
   		fileBU.write((char*)&BUarr[i], sizeof(Student));
   	}
   	fileCS.close();
   	fileMA.close();
   	fileBU.close();
   }
   void Read() {
   	Student stud;
   	// CS
   	ifstream fileCS("CS.dat", ios::in | ios::binary);
   	while (fileCS.read((char*)&stud, sizeof(Student))) {
   		stud.print();
   		CSarr.push_back(stud);
   	}
   	// MA
   	ifstream fileMA("MA.dat", ios::in | ios::binary);
   	while (fileMA.read((char*)&stud, sizeof(Student))) {
   		stud.print();
   		MAarr.push_back(stud);
   	}
   	// BU
   	ifstream fileBU("BU.dat", ios::in | ios::binary);
   	while (fileBU.read((char*)&stud, sizeof(Student))) {
   		stud.print();
   		BUarr.push_back(stud);
   	}
   	Student::csCount = CSarr.size();
   	Student::maCount = MAarr.size();
   	Student::buCount = BUarr.size();
   	Student::total = CSarr.size() + MAarr.size() + BUarr.size();
   	fileCS.close();
   	fileMA.close();
   	fileBU.close();
   }
   ```

2. myfunc.h

   ```C++
   #pragma once
   
   void input();
   void display();
   void printAll();
   void Query();
   void Del();
   void Ins();
   void modify();
   void Sort();
   void Save();
   void Read();
   ```

3. Student.h

   ```C++
   #pragma once
   #include<string>
   using namespace std;
   
   class Student
   {
   private:
   
   public:
   	static int total;
   	static int csCount;
   	static int maCount;
   	static int buCount;
   	int studNum = 0;
   	char name[20] = "1";
   	char sex = 'F';
   	char college[3] = "1";
   	int year = 0;
   	int colNum = 0;
   	Student() {};
   	Student(char name[20], char sex, char college[3], int year, int colNum);
   	void GenID();
   	void print();
   };
   ```

4. Student.cpp

   ```C++
   #include "Student.h"
   #include <iostream>
   using namespace std;
   
   int Student::total = 0;
   int Student::csCount = 0;
   int Student::maCount = 0;
   int Student::buCount = 0;
   Student::Student(char name[20], char sex, char college[3], int year, int colNum) {
   	strcpy_s(this->name, name);
   	strcpy_s(this->college, college);
   	this->sex = sex;
   	this->year = year;
   	this->colNum = colNum;
   	this->total++;
   	switch (colNum) {
   	case 11: {
   		csCount++;
   		break;
   	};
   	case 22: {
   		maCount++;
   		break;
   	};
   	case 33: {
   		buCount++;
   		break;
   	};
   	default:
   		break;
   	}
   }
   
   void Student::GenID() {
   	int count = 0;
   	switch (colNum) {
   	case 11: {
   		count = csCount;
   		break;
   	};
   	case 22: {
   		count = maCount;
   		break;
   	};
   	case 33: {
   		count = buCount;
   		break;
   	};
   	default:
   		break;
   	}
   	studNum = colNum * 10000 + year % 100 * 100 + count;
   }
   void Student::print() {
   	cout << "学号：" << studNum << "  姓名：" << name << "  性别：" << sex << "  学院：" << college << "  入学年份：" << year << "  学院顺序号：" << colNum << endl;
   }
   ```

   

#### C 风格原始版

```

```



## 学生成绩管理系统

### 功能需求：

1. 录入学生信息
2. 打印学生信息
3. 保存学生信息
4. 读取学生信息
5. 统计学生人数
6. 查找学生信息
7. 修改学生信息
8. 删除学生信息
9. 退出系统



