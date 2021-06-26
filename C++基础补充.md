# 菜鸟教程 C++ 笔记


## [C++ 教程](https://www.runoob.com/cplusplus/cpp-tutorial.html)



## [C++ 简介](https://www.runoob.com/cplusplus/cpp-intro.html)



## [C++ 环境设置](https://www.runoob.com/cplusplus/cpp-environment-setup.html)

对于上面的一闪而过，我这个 C++ 码龄 3 年的给出问题所在和解决方法。

一闪而过是因为你的程序没有输入，只有固定的输出。程序会在运行到 return 语句时退出程序。

之前给的三种解决办法我一一讲解：

第一种：

```C++
cin.clear();  // 清空缓存
cin.sync();   // 清空缓存
cin.get();    // 接收键盘输入
// From:本帖，"但对于太突然"
```

这种采用了输入方法来不让程序终止，他会在读入到数据后退出程序（cin.get）。

```C++
#include <stdio.h>
int main()
{
  getchar();
  return 0;
}
// From:本帖，"xuezy"
```

这种是采用了输入方法，但不同于上一种的是，这次是使用 getchar 函数获取一个 char 类型，但不将读入的数据存放于任何变量。

```C++
#include <stdlib.h>
int main()
{
  system("pause"); //注意：“system("pause")”;语句会显示“请按任意键继续……”
  return 0;
}
// From:本帖，"xuezy"
```

此方法是采用 system() 函数中的 pause 命令进行程序的暂停。

- win 使用命令行：

```C++
$ g++ 1.3.1.cpp
$ ./a.exe
```



## [C++ 基本语法](https://www.runoob.com/cplusplus/cpp-basic-syntax.html)

**在 C++ 中 main 函数前面为什么要加上数据类型，比如： int void?**

- **main** 函数的返回值是返回给主调进程，使主调进程得知被调用程序的运行结果。
- 标准规范中规定 **main** 函数的返回值为 **int**，一般约定返回 0 值时代表程序运行无错误，其它值均为错误号，但该约定并非强制。
- 如果程序的运行结果不需要返回给主调进程，或程序开发人员确认该状态并不重要，比如所有出错信息均在程序中有明确提示的情况下，可以不写 main 函数的返回值。在一些检查不是很严格的编译器中，比如 VC, VS 等，void 类型的 main 是允许的。不过在一些检查严格的编译器下，比如 g++, 则要求 main 函数的返回值必须为 int 型。
- 所以在编程时，区分程序运行结果并以 int 型返回，是一个良好的编程习惯。



### **标识符**

**定义：**变量、符号常量、函数、数组、类型、文件、标签和其他各种用户定义的对象的名称。

-  第一个字符必须是字母或下划线
-  后续字符可以是字母、数字或下划线
-  标识符的有效长度不超过247字符
-  标识符不能和关键字相同
-  标识符区分大小写
-  最好也不要和系统预定义标识符同名
-  标识符命名要做到“见名知义”
-  应该避免使用可能引起混淆的字母

C/C++可以使用带有 **$** 的标识符



### 为什么要使用 **using namespace std;** ?

- 有些名字容易冲突，所以会使用命名空间的方式进行区分，具体来说就是加个前缀。比如 C++ 标准库里面定义了 vector 容器，你自己也写了个 vector 类，这样名字就冲突了。于是标准库里的名字都加上 std:: 的前缀，你必须用 std::vector 来引用。同理，你自己的类也可以加个自定义的前缀。
- 但是经常写全名会很繁琐，所以在没有冲突的情况下你可以偷懒，写一句 using namespace std;，接下去的代码就可以不用写前缀直接写 vector 了。





## [C++ 注释](https://www.runoob.com/cplusplus/cpp-comments.html)

块注释符（/*...*/）是不可以嵌套使用的。

**#if 0 ... #endif** 属于条件编译，0 即为参数。

此外，我们还可以使用 **#if 0 ... #endif** 来实现注释，且可以实现嵌套，格式为：

```C++
#if 0
   code
#endif 
```

你可以把 **#if 0** 改成 **#if 1** 来执行 **code** 的代码。

这种形式对程序调试也可以帮助，测试时使用 **#if 1** 来执行测试代码，发布后使用 **#if 0** 来屏蔽测试代码。

**#if** 后可以是任意的条件语句。

下面的代码如果 condition 条件为 true 执行 code1 ，否则执行 code2。

```C++
#if condition
  code1
#else
  code2
#endif
```



## [C++ 数据类型](https://www.runoob.com/cplusplus/cpp-data-types.html)

下表显示了各种变量类型在内存中存储值时需要占用的内存，以及该类型的变量所能存储的最大值和最小值。

**注意：**不同系统会有所差异，一字节为 8 位。

**注意：**long int 8 个字节，int 都是 4 个字节，早期的 C 编译器定义了 long int 占用 4 个字节，int 占用 2 个字节，新版的 C/C++ 标准兼容了早期的这一设定。

| 类型               | 位            | 范围                                                         |
| :----------------- | :------------ | :----------------------------------------------------------- |
| char               | 1 个字节      | -128 到 127 或者 0 到 255                                    |
| unsigned char      | 1 个字节      | 0 到 255                                                     |
| signed char        | 1 个字节      | -128 到 127                                                  |
| int                | 4 个字节      | -2147483648 到 2147483647                                    |
| unsigned int       | 4 个字节      | 0 到 4294967295                                              |
| signed int         | 4 个字节      | -2147483648 到 2147483647                                    |
| short int          | 2 个字节      | -32768 到 32767                                              |
| unsigned short int | 2 个字节      | 0 到 65,535                                                  |
| signed short int   | 2 个字节      | -32768 到 32767                                              |
| long int           | 8 个字节      | -9,223,372,036,854,775,808 到 9,223,372,036,854,775,807      |
| signed long int    | 8 个字节      | -9,223,372,036,854,775,808 到 9,223,372,036,854,775,807      |
| unsigned long int  | 8 个字节      | 0 到 18,446,744,073,709,551,615                              |
| float              | 4 个字节      | 精度型占4个字节（32位）内存空间，+/- 3.4e +/- 38 (~7 个数字) |
| double             | 8 个字节      | 双精度型占8 个字节（64位）内存空间，+/- 1.7e +/- 308 (~15 个数字) |
| long double        | 16 个字节     | 长双精度型 16 个字节（128位）内存空间，可提供18-19位有效数字。 |
| wchar_t            | 2 或 4 个字节 | 1 个宽字符                                                   |

从上表可得知，变量的大小会根据编译器和所使用的电脑而有所不同。

下面实例会输出您电脑上各种数据类型的大小。

### 实例

```C++
#include<iostream>  
#include <limits>
 
using namespace std;  
  
int main()  
{  
    cout << "type: \t\t" << "************size**************"<< endl;  
    cout << "bool: \t\t" << "所占字节数：" << sizeof(bool);  
    cout << "\t最大值：" << (numeric_limits<bool>::max)();  
    cout << "\t\t最小值：" << (numeric_limits<bool>::min)() << endl;  
    cout << "char: \t\t" << "所占字节数：" << sizeof(char);  
    cout << "\t最大值：" << (numeric_limits<char>::max)();  
    cout << "\t\t最小值：" << (numeric_limits<char>::min)() << endl;  
    cout << "signed char: \t" << "所占字节数：" << sizeof(signed char);  
    cout << "\t最大值：" << (numeric_limits<signed char>::max)();  
    cout << "\t\t最小值：" << (numeric_limits<signed char>::min)() << endl;  
    cout << "unsigned char: \t" << "所占字节数：" << sizeof(unsigned char);  
    cout << "\t最大值：" << (numeric_limits<unsigned char>::max)();  
    cout << "\t\t最小值：" << (numeric_limits<unsigned char>::min)() << endl;  
    cout << "wchar_t: \t" << "所占字节数：" << sizeof(wchar_t);  
    cout << "\t最大值：" << (numeric_limits<wchar_t>::max)();  
    cout << "\t\t最小值：" << (numeric_limits<wchar_t>::min)() << endl;  
    cout << "short: \t\t" << "所占字节数：" << sizeof(short);  
    cout << "\t最大值：" << (numeric_limits<short>::max)();  
    cout << "\t\t最小值：" << (numeric_limits<short>::min)() << endl;  
    cout << "int: \t\t" << "所占字节数：" << sizeof(int);  
    cout << "\t最大值：" << (numeric_limits<int>::max)();  
    cout << "\t最小值：" << (numeric_limits<int>::min)() << endl;  
    cout << "unsigned: \t" << "所占字节数：" << sizeof(unsigned);  
    cout << "\t最大值：" << (numeric_limits<unsigned>::max)();  
    cout << "\t最小值：" << (numeric_limits<unsigned>::min)() << endl;  
    cout << "long: \t\t" << "所占字节数：" << sizeof(long);  
    cout << "\t最大值：" << (numeric_limits<long>::max)();  
    cout << "\t最小值：" << (numeric_limits<long>::min)() << endl;  
    cout << "unsigned long: \t" << "所占字节数：" << sizeof(unsigned long);  
    cout << "\t最大值：" << (numeric_limits<unsigned long>::max)();  
    cout << "\t最小值：" << (numeric_limits<unsigned long>::min)() << endl;  
    cout << "double: \t" << "所占字节数：" << sizeof(double);  
    cout << "\t最大值：" << (numeric_limits<double>::max)();  
    cout << "\t最小值：" << (numeric_limits<double>::min)() << endl;  
    cout << "long double: \t" << "所占字节数：" << sizeof(long double);  
    cout << "\t最大值：" << (numeric_limits<long double>::max)();  
    cout << "\t最小值：" << (numeric_limits<long double>::min)() << endl;  
    cout << "float: \t\t" << "所占字节数：" << sizeof(float);  
    cout << "\t最大值：" << (numeric_limits<float>::max)();  
    cout << "\t最小值：" << (numeric_limits<float>::min)() << endl;  
    cout << "size_t: \t" << "所占字节数：" << sizeof(size_t);  
    cout << "\t最大值：" << (numeric_limits<size_t>::max)();  
    cout << "\t最小值：" << (numeric_limits<size_t>::min)() << endl;  
    cout << "string: \t" << "所占字节数：" << sizeof(string) << endl;  
    // << "\t最大值：" << (numeric_limits<string>::max)() << "\t最小值：" << (numeric_limits<string>::min)() << endl;  
    cout << "type: \t\t" << "************size**************"<< endl;  
    return 0;  
}
```

本实例使用了 **endl**，这将在每一行后插入一个换行符，**<<** 运算符用于向屏幕传多个值，**sizeof()** 函数用来获取各种数据类型的大小。

当上面的代码被编译和执行时，它会产生以下的结果，结果会根据所使用的计算机而有所不同：

```C++
type:         ************size**************
bool:         所占字节数：1    最大值：1        最小值：0
char:         所占字节数：1    最大值：        最小值：?
signed char:     所占字节数：1    最大值：        最小值：?
unsigned char:     所占字节数：1    最大值：?        最小值：
wchar_t:     所占字节数：4    最大值：2147483647        最小值：-2147483648
short:         所占字节数：2    最大值：32767        最小值：-32768
int:         所占字节数：4    最大值：2147483647    最小值：-2147483648
unsigned:     所占字节数：4    最大值：4294967295    最小值：0
long:         所占字节数：8    最大值：9223372036854775807    最小值：-9223372036854775808
unsigned long:     所占字节数：8    最大值：18446744073709551615    最小值：0
double:     所占字节数：8    最大值：1.79769e+308    最小值：2.22507e-308
long double:     所占字节数：16    最大值：1.18973e+4932    最小值：3.3621e-4932
float:         所占字节数：4    最大值：3.40282e+38    最小值：1.17549e-38
size_t:     所占字节数：8    最大值：18446744073709551615    最小值：0
string:     所占字节数：24
type:         ************size**************
```

### typedef 声明

您可以使用 **typedef** 为一个已有的类型取一个新的名字。下面是使用 typedef 定义一个新类型的语法：

```C++
typedef type newname; 
```

例如，下面的语句会告诉编译器，feet 是 int 的另一个名称：

```C++
typedef int feet;
```

现在，下面的声明是完全合法的，它创建了一个整型变量 distance：

```C++
feet distance;
```

### 枚举类型

枚举类型(enumeration)是C++中的一种派生数据类型，它是由用户定义的若干枚举常量的集合。

如果一个变量只有几种可能的值，可以定义为枚举(enumeration)类型。所谓"枚举"是指将变量的值一一列举出来，变量的值只能在列举出来的值的范围内。

创建枚举，需要使用关键字 **enum**。枚举类型的一般形式为：

```c++
enum 枚举名{ 
     标识符[=整型常数], 
     标识符[=整型常数], 
... 
    标识符[=整型常数]
} 枚举变量;
    
```

如果枚举没有初始化, 即省掉"=整型常数"时, 则从第一个标识符开始。

- 每个枚举元素在声明时被分配一个整型值，**默认从 0 开始，逐个加 1。**
- 也可以在定义枚举类型时对枚举元素赋值，此时，赋值的枚举值为所赋的值，而其他没有赋值的枚举值在为**前一个枚举值加 1**。

例如，下面的代码定义了一个颜色枚举，变量 c 的类型为 color。最后，c 被赋值为 "blue"。

```C++
enum color { red, green, blue } c;
c = blue;
```

默认情况下，第一个名称的值为 0，第二个名称的值为 1，第三个名称的值为 2，以此类推。但是，您也可以给名称赋予一个特殊的值，只需要添加一个初始值即可。例如，在下面的枚举中，**green** 的值为 5。

```C++
enum color { red, green=5, blue };
```

在这里，**blue** 的值为 6，因为默认情况下，每个名称都会比它前面一个名称大 1，但 red 的值依然为 0。

### 枚举实例测试：

```C++
#include <iostream>
using namespace std;

int main(){
    enum days{one, two, three}day;
    day = one;
    switch(day){
        case one:
            cout << "one" << endl;
            break;
        case two:
            cout << "two" << endl;
            break;
        default:
            cout << "three" << endl;
            break;
    }
    return 0;
}
```



### typedef 和 using

可以使用 **typedef** 为类型添加別名：

```C++
typedef int Int;
```

当然，也可以使用 **using**：

```C++
using Int=int;
```

可以看到，第二种可读性更高。

另外，using 在模板环境中会更加强大。

假设有一个模板参数是 int 的类 grid，那么可以这么做：

```C++
using grid1=grid<1>;
```

那要声明一个指向返回 void，有一个 int 参数的函数的函数指针呢？

或许可以使用 **typedef**：

```C++
typedef void(*f1)(int);
```

可以看到，可读性很低，那使用 using 呢？

```C++
using f1=void(*)(int);
```

使用 using 明显更好理解：

所以，始终优先使用 using。

那如果将函数指针作参数呢？

```C++
void func(void(*f1)(int)){
//...
}
```

这无法使用 using 完成。

但是，使用 <functional> 中的 function 可以更好地完成任务：

```C++
void func(function<void(int)>f1){
//...
}
```

所以，尽量不去使用 **typedef**。



## [C++ 变量类型](https://www.runoob.com/cplusplus/cpp-variable-types.html)

基于前一章讲解的基本类型，有以下几种基本的变量类型，将在下一章中进行讲解：

| 类型    | 描述                                                         |
| :------ | :----------------------------------------------------------- |
| bool    | 存储值 true 或 false。                                       |
| char    | 通常是一个字符（八位）。这是一个整数类型。                   |
| int     | 对机器而言，整数的最自然的大小。                             |
| float   | 单精度浮点值。单精度是这样的格式，1位符号，8位指数，23位小数。![img](https://www.runoob.com/wp-content/uploads/2014/09/v2-749cc641eb4d5dafd085e8c23f8826aa_hd.png) |
| double  | 双精度浮点值。双精度是1位符号，11位指数，52位小数。![img](https://www.runoob.com/wp-content/uploads/2014/09/v2-48240f0e1e0dd33ec89100cbe2d30707_hd.png) |
| void    | 表示类型的缺失。                                             |
| wchar_t | 宽字符类型。                                                 |

### **C++ 中的变量声明**

变量声明向编译器保证变量以给定的类型和名称存在，这样编译器在不需要知道变量完整细节的情况下也能继续进一步的编译。变量声明只在编译时有它的意义，在程序连接时编译器需要实际的变量声明。

用 extern 声明外部变量是不能进行初始化： **extern int a;** 只是声明而不是定义，声明是不会为变量开辟内存空间的，自然无法对其进行初始化的操作。

### **C++ 中的左值和右值**

C++ 中有两种类型的表达式：

- **左值（lvalue）：**指向**内存位置**的表达式被称为左值（lvalue）表达式。左值可以出现在赋值号的左边或右边。
- **右值（rvalue）：**术语右值（rvalue）指的是存储在内存中某些地址的**数值**。右值是不能对其进行赋值的表达式，也就是说，右值可以出现在赋值号的右边，但不能出现在赋值号的左边。



### 自动转换和强制转换。

**自动转换规则：**

- 1、若参与运算量的类型不同，则先转换成同一类型，然后进行运算。
- 2、转换按数据长度增加的方向进行，以保证精度不降低。如int型和long型运算时，先把int量转成long型后再进行运算。   a、若两种类型的字节数不同，转换成字节数高的类型   b、若两种类型的字节数相同，且一种有符号，一种无符号，则转换成无符号类型
-  3、所有的浮点运算都是以双精度进行的，即使仅含float单精度量运算的表达式，也要先转换成double型，再作运算。
-  4、char型和short型参与运算时，必须先转换成int型。
-  5、在赋值运算中，赋值号两边量的数据类型不同时，赋值号右边量的类型将转换为左边量的类型。如果右边量的数据类型长度比左边长时，将丢失一部分数据，这样会降低精度:

```C++
int a=1;
double b=2.5;
a=b;
cout << a; //输出为 2，丢失小数部分
int a = 1;
double b = 2.1;
cout << "a + b = " << a + b << endl;  //输出为a + b = 3.1
```

**强制转换规则：**

强制类型转换是通过类型转换运算来实现的。其一般形式为：（类型说明符）（表达式）其功能是把表达式的运算结果强制转换成类型说明符所表示的类型

```C++
int a = 1;
double b = 2.1;
cout << "a + b = " << a + (int)b << endl;  //输出为a + b = 3
```



## [C++ 变量作用域](https://www.runoob.com/cplusplus/cpp-variable-scope.html)

作用域是程序的一个区域，一般来说有三个地方可以定义变量：

- 在函数或一个代码块内部声明的变量，称为局部变量。
- 在函数参数的定义中声明的变量，称为形式参数。
- 在所有函数外部声明的变量，称为全局变量。

### 全局变量和 static 变量

**C++ 全局变量、局部变量、静态全局变量、静态局部变量的区别**

C++ 变量根据定义的位置的不同的生命周期，具有不同的作用域，作用域可分为 6 种：**全局作用域**，**局部作用域**，**语句作用域**，**类作用域**，**命名空间作用域和文件作用域**。

**从作用域看：**

全局变量具有全局作用域。全局变量只需在一个源文件中定义，就可以作用于所有的源文件。当然，其他不包含全局变量定义的源文件需要用extern 关键字再次声明这个全局变量。

静态局部变量具有局部作用域，它只被初始化一次，自从第一次被初始化直到程序运行结束都一直存在，它和全局变量的区别在于全局变量对所有的函数都是可见的，而静态局部变量只对定义自己的函数体始终可见。

局部变量也只有局部作用域，它是自动对象（auto），它在程序运行期间不是一直存在，而是只在函数执行期间存在，函数的一次调用执行结束后，变量被撤销，其所占用的内存也被收回。

静态全局变量也具有全局作用域，它与全局变量的区别在于如果程序包含多个文件的话，它作用于定义它的文件里，不能作用到其它文件里，即被static关键字修饰过的变量具有文件作用域。这样即使两个不同的源文件都定义了相同名字的静态全局变量，它们也是不同的变量。

**从分配内存空间看：**

全局变量，静态局部变量，静态全局变量都在静态存储区分配空间，而局部变量在栈里分配空间。

全局变量本身就是静态存储方式， 静态全局变量当然也是静态存储方式。这两者在存储方式上并无不同。这两者的区别虽在于非静态全局变量的作用域是整个源程序，当一个源程序由多个源文件组成时，非静态的全局变量在各个源文件中都是有效的。 而静态全局变量则限制了其作用域， 即只在定义该变量的源文件内有效，在同一源程序的其它源文件中不能使用它。由于静态全局变量的作用域局限于一个源文件内，只能为该源文件内的函数公用，因此可以避免在其它源文件中引起错误。

-  1)、静态变量会被放在程序的静态数据存储区（数据段）(全局可见)中，这样可以在下一次调用的时候还可以保持原来的赋值。这一点是它与堆栈变量和堆变量的区别。
-  2)、变量用static告知编译器，自己仅仅在变量的作用范围内可见。这一点是它与全局变量的区别。

从以上分析可以看出， 把局部变量改变为静态变量后是改变了它的存储方式即改变了它的生存期。把全局变量改变为静态变量后是改变了它的作用域，限制了它的使用范围。因此static 这个说明符在不同的地方所起的作用是不同的。应予以注意。

**Tips:**

- A、若全局变量仅在单个C文件中访问，则可以将这个变量修改为静态全局变量，以降低模块间的耦合度；
- B、若全局变量仅由单个函数访问，则可以将这个变量改为该函数的静态局部变量，以降低模块间的耦合度；
- C、设计和使用访问动态全局变量、静态全局变量、静态局部变量的函数时，需要考虑重入问题，因为他们都放在静态数据存储区，全局可见；
- D、如果我们需要一个可重入的函数，那么，我们一定要避免函数中使用static变量(这样的函数被称为：带“内部存储器”功能的的函数)
- E、函数中必须要使用static变量情况:比如当某函数的返回值为指针类型时，则必须是static的局部变量的地址作为返回值，若为auto类型，则返回为错指针。

\-----------------------------------------------------------------------------------------------------------

**static 全局变量**:改变作用范围，不改变存储位置

**static 局部变量**：改变存储位置，不改变作用范围

**静态函数** ：在函数的返回类型前加上static关键字,函数即被定义为静态函数。静态函数与普通函数不同，它只能在声明它的文件当中可见，不能被其它文件使用。

如果在一个源文件中定义的函数，只能被本文件中的函数调用，而不能被同一程序其它文件中的函数调用，这种函数也称为内部函数。定义一个内部函数，只需在函数类型前再加一个“static”关键字即可。

## [C++ 常量](https://www.runoob.com/cplusplus/cpp-constants-literals.html)

### 整数常量

整数常量可以是十进制、八进制或十六进制的常量。前缀指定基数：0x 或 0X 表示十六进制，0 表示八进制，不带前缀则默认表示十进制。

整数常量也可以带一个后缀，后缀是 U 和 L 的组合，U 表示无符号整数（unsigned），L 表示长整数（long）。后缀可以是大写，也可以是小写，U 和 L 的顺序任意。

下面列举几个整数常量的实例：

```C++
212         // 合法的
215u        // 合法的
0xFeeL      // 合法的
078         // 非法的：8 不是八进制的数字
032UU       // 非法的：不能重复后缀
```

以下是各种类型的整数常量的实例：

```C++
85         // 十进制
0213       // 八进制 
0x4b       // 十六进制 
30         // 整数 
30u        // 无符号整数 
30l        // 长整数 
30ul       // 无符号长整数
```



### 浮点常量

浮点常量由整数部分、小数点、小数部分和指数部分组成。您可以使用小数形式或者指数形式来表示浮点常量。

当使用小数形式表示时，必须包含整数部分、小数部分，或同时包含两者。当使用指数形式表示时， 必须包含小数点、指数，或同时包含两者。带符号的指数是用 e 或 E 引入的。

下面列举几个浮点常量的实例：

```C++
3.14159       // 合法的 
314159E-5L    // 合法的 
510E          // 非法的：不完整的指数
210f          // 非法的：没有小数或指数
.e55          // 非法的：缺少整数或分数
```

### 字符常量

字符常量是括在单引号中。如果常量以 L（仅当大写时）开头，则表示它是一个宽字符常量（例如 L'x'），此时它必须存储在 **wchar_t** 类型的变量中。否则，它就是一个窄字符常量（例如 'x'），此时它可以存储在 **char** 类型的简单变量中。

字符常量可以是一个普通的字符（例如 'x'）、一个转义序列（例如 '\t'），或一个通用的字符（例如 '\u02C0'）。

在 C++ 中，有一些特定的字符，当它们前面有反斜杠时，它们就具有特殊的含义，被用来表示如换行符（\n）或制表符（\t）等。下表列出了一些这样的转义序列码：

| 转义序列  | 含义                         |
| :-------- | :--------------------------- |
| `\\`      | `\ 字符`                     |
| `\'`      | `' 字符`                     |
| `\"`      | `" 字符`                     |
| `\?`      | `? 字符`                     |
| `\a`      | `警报铃声`                   |
| `\b`      | `退格键`                     |
| `\f`      | `换页符`                     |
| `\n`      | `换行符`                     |
| `\r`      | `回车`                       |
| `\t`      | `水平制表符`                 |
| `\v`      | `垂直制表符`                 |
| `\ooo`    | `一到三位的八进制数`         |
| `\xhh...` | `一个或多个数字的十六进制数` |

### 定义常量

在 C++ 中，有两种简单的定义常量的方式：

- 使用 **#define** 预处理器。
- 使用 **const** 关键字。

### #define 预处理器

下面是使用 #define 预处理器定义常量的形式：

```C++
#define identifier value
```

### 宏定义 #define 和常量 const 的区别

**类型和安全检查不同**

宏定义是字符替换，没有数据类型的区别，同时这种替换没有类型安全检查，可能产生边际效应等错误；

const常量是常量的声明，有类型区别，需要在编译阶段进行类型检查

**编译器处理不同**

宏定义是一个"编译时"概念，在预处理阶段展开，不能对宏定义进行调试，生命周期结束与编译时期；

const常量是一个"运行时"概念，在程序运行使用，类似于一个只读行数据

**存储方式不同**

宏定义是直接替换，不会分配内存，存储与程序的代码段中；

const常量需要进行内存分配，存储与程序的数据段中

**定义域不同**

```C++
void f1 ()
{
    #define N 12
    const int n 12;
}
void f2 ()
{
    cout<<N <<endl; //正确，N已经定义过，不受定义域限制
    cout<<n <<endl; //错误，n定义域只在f1函数中
}
```

**定义后能否取消**

宏定义可以通过#undef来使之前的宏定义失效

const常量定义后将在定义域内永久有效

```C++
void f1()
{
  #define N 12
  const int n = 12;

  #undef N //取消宏定义后，即使在f1函数中，N也无效了
  #define N 21//取消后可以重新定义
}
```

**是否可以做函数参数**

宏定义不能作为参数传递给函数

const常量可以在函数的参数列表中出现



预处理 **#define** 变量定义值以后，不能用分号，分号终止宏定义。



## [C++ 修饰符类型](https://www.runoob.com/cplusplus/cpp-modifier-types.html)

C++ 允许在 **char、int 和 double** 数据类型前放置修饰符。修饰符用于改变基本类型的含义，所以它更能满足各种情境的需求。

下面列出了数据类型修饰符：

- signed
- unsigned
- long
- short

修饰符 **signed、unsigned、long 和 short** 可应用于整型，**signed** 和 **unsigned** 可应用于字符型，**long** 可应用于双精度型。

修饰符 **signed** 和 **unsigned** 也可以作为 **long** 或 **short** 修饰符的前缀。例如：**unsigned long int**。

C++ 允许使用速记符号来声明**无符号短整数**或**无符号长整数**。您可以不写 int，只写单词 **unsigned、short** 或 **unsigned、long**，int 是隐含的。例如，下面的两个语句都声明了无符号整型变量。



## [C++ 存储类](https://www.runoob.com/cplusplus/cpp-storage-classes.html)

存储类定义 C++ 程序中变量/函数的范围（可见性）和生命周期。这些说明符放置在它们所修饰的类型之前。下面列出 C++ 程序中可用的存储类：

- auto
- register
- static
- extern
- mutable
- thread_local (C++11)

从 C++ 17 开始，auto 关键字不再是 C++ 存储类说明符，且 register 关键字被弃用。

### auto 存储类

自 C++ 11 以来，**auto** 关键字用于两种情况：声明变量时根据初始化表达式自动推断该变量的类型、声明函数时函数返回值的占位符。

C++98标准中auto关键字用于自动变量的声明，但由于使用极少且多余，在C++11中已删除这一用法。

根据初始化表达式自动推断被声明的变量的类型，如：

```C++
auto f=3.14;      //double
auto s("hello");  //const char*
auto z = new auto(9); // int*
auto x1 = 5, x2 = 5.0, x3='r';//错误，必须是初始化为同一类型
```

### register 存储类

**register** 存储类用于定义存储在寄存器中而不是 RAM 中的局部变量。这意味着变量的最大尺寸等于寄存器的大小（通常是一个词），且不能对它应用一元的 '&' 运算符（因为它没有内存位置）。

`{   register int  miles; }`

寄存器只用于需要快速访问的变量，比如计数器。还应注意的是，定义 'register' 并不意味着变量将被存储在寄存器中，它意味着变量可能存储在寄存器中，这取决于硬件和实现的限制。

### static 存储类

**static** 存储类指示编译器在程序的生命周期内保持局部变量的存在，而不需要在每次它进入和离开作用域时进行创建和销毁。因此，使用 static 修饰局部变量可以在函数调用之间保持局部变量的值。

static 修饰符也可以应用于全局变量。当 static 修饰全局变量时，会使变量的作用域限制在声明它的文件内。

在 C++ 中，当 static 用在类数据成员上时，会导致仅有一个该成员的副本被类的所有对象共享。

### extern 存储类

**extern** 存储类用于提供一个全局变量的引用，全局变量对所有的程序文件都是可见的。当您使用 'extern' 时，对于无法初始化的变量，会把变量名指向一个之前定义过的存储位置。

当您有多个文件且定义了一个可以在其他文件中使用的全局变量或函数时，可以在其他文件中使用 *extern* 来得到已定义的变量或函数的引用。可以这么理解，*extern* 是用来在另一个文件中声明一个全局变量或函数。

extern 修饰符通常用于当有两个或多个文件共享相同的全局变量或函数的时候，如下所示：

第一个文件：main.cpp

```C++
#include <iostream>
 
int count ;
extern void write_extern();
 
int main()
{
   count = 5;
   write_extern();
}
```

第二个文件：support.cpp

```C++
#include <iostream>
 
extern int count;
 
void write_extern(void)
{
   std::cout << "Count is " << count << std::endl;
}
```

在这里，第二个文件中的 *extern* 关键字用于声明已经在第一个文件 main.cpp 中定义的 count。现在 ，编译这两个文件，如下所示：

```shell
$ g++ main.cpp support.cpp -o write
```

这会产生 **write** 可执行程序，尝试执行 **write**，它会产生下列结果：

```shell
$ ./write
Count is 5
```



### mutable 存储类

**mutable** 说明符仅适用于类的对象，这将在本教程的最后进行讲解。它允许对象的成员替代常量。也就是说，mutable 成员可以通过 const 成员函数修改。

### thread_local 存储类

使用 thread_local 说明符声明的变量仅可在它在其上创建的线程上访问。 变量在创建线程时创建，并在销毁线程时销毁。 每个线程都有其自己的变量副本。

thread_local 说明符可以与 static 或 extern 合并。

可以将 thread_local 仅应用于数据声明和定义，thread_local 不能用于函数声明或定义。

以下演示了可以被声明为 thread_local 的变量：

```C++
thread_local int x;  // 命名空间下的全局变量
class X
{
    static thread_local std::string s; // 类的static成员变量
};
static thread_local std::string X::s;  // X::s 是需要定义的
 
void foo()
{
    thread_local std::vector<int> v;  // 本地变量
}
```



在前面的学习中我们看到的输出没有 **std::**，而这一节出现了上面的代码。

```C++
std::cout << "Count is " << count << std::endl;
```

**std** 是标准库函数使用的命名空间，是 standard（标准）的缩写。

**using namespace std** ，它声明了命名空间 **std**，后续如果有未指定命名空间的符号，那么默认使用 **std**，这样就可以使用 **cin、cout、vector** 等。

假设你不使用预处理 **using namespace std;**,就要加上 **std::cin** 或者 **std::cout**。

**cin** 用于从控制台获取用户输入，**cout** 用于将数据输出到控制台。

**cin** 是输入流对象，**cout** 是输出流对象，它们分别可以用 **>>** 和 **<<**，是因为分别在其类中对相应运算符进行了重载。



## [C++ 运算符](https://www.runoob.com/cplusplus/cpp-operators.html)

### 杂项运算符

下表列出了 C++ 支持的其他一些重要的运算符。

| 运算符                 | 描述                                                         |
| :--------------------- | :----------------------------------------------------------- |
| `sizeof`               | [sizeof 运算符](https://www.runoob.com/cplusplus/cpp-sizeof-operator.html)返回变量的大小。例如，sizeof(a) 将返回 4，其中 a 是整数。 |
| `Condition ? X : Y`    | [条件运算符](https://www.runoob.com/cplusplus/cpp-conditional-operator.html)。如果 Condition 为真 ? 则值为 X : 否则值为 Y。 |
| `,`                    | [逗号运算符](https://www.runoob.com/cplusplus/cpp-comma-operator.html)会顺序执行一系列运算。整个逗号表达式的值是以逗号分隔的列表中的最后一个表达式的值。 |
| `.（点）和 ->（箭头）` | [成员运算符](https://www.runoob.com/cplusplus/cpp-member-operators.html)用于引用类、结构和共用体的成员。 |
| `Cast`                 | [强制转换运算符](https://www.runoob.com/cplusplus/cpp-casting-operators.html)把一种数据类型转换为另一种数据类型。例如，int(2.2000) 将返回 2。 |
| `&`                    | [指针运算符 &](https://www.runoob.com/cplusplus/cpp-pointer-operators.html) 返回变量的地址。例如 &a; 将给出变量的实际地址。 |
| `*`                    | [指针运算符 *](https://www.runoob.com/cplusplus/cpp-pointer-operators.html) 指向一个变量。例如，*var; 将指向变量 var。 |

### C++ 中的运算符优先级

运算符的优先级确定表达式中项的组合。这会影响到一个表达式如何计算。某些运算符比其他运算符有更高的优先级，例如，乘除运算符具有比加减运算符更高的优先级。

例如 x = 7 + 3 * 2，在这里，x 被赋值为 13，而不是 20，因为运算符 * 具有比 + 更高的优先级，所以首先计算乘法 3*2，然后再加上 7。

下表将按运算符优先级从高到低列出各个运算符，具有较高优先级的运算符出现在表格的上面，具有较低优先级的运算符出现在表格的下面。在表达式中，较高优先级的运算符会优先被计算。

| 类别         | 运算符                             | 结合性     |
| :----------- | :--------------------------------- | :--------- |
| `后缀`       | `() [] -> . ++ - -`                | `从左到右` |
| `一元`       | `+ - ! ~ ++ - - (type)* & sizeof`  | `从右到左` |
| `乘除`       | `* / %`                            | `从左到右` |
| `加减`       | `+ -`                              | `从左到右` |
| `移位`       | `<< >>`                            | `从左到右` |
| `关系`       | `< <= > >=`                        | `从左到右` |
| `相等`       | `== !=`                            | `从左到右` |
| `位与 AND`   | `&`                                | `从左到右` |
| `位异或 XOR` | `^`                                | `从左到右` |
| `位或 OR`    | `|`                                | `从左到右` |
| `逻辑与 AND` | `&&`                               | `从左到右` |
| `逻辑或 OR`  | `||`                               | `从左到右` |
| `条件`       | `?:`                               | `从右到左` |
| `赋值`       | `= += -= *= /= %=>>= <<= &= ^= |=` | `从右到左` |
| `逗号`       | `,`                                | `从左到右` |

## [C++ 循环](https://www.runoob.com/cplusplus/cpp-loops.html)

### 循环类型

C++ 编程语言提供了以下几种循环类型。点击链接查看每个类型的细节。

| 循环类型                                                     | 描述                                                         |
| :----------------------------------------------------------- | :----------------------------------------------------------- |
| [while 循环](https://www.runoob.com/cplusplus/cpp-while-loop.html) | 当给定条件为真时，重复语句或语句组。它会在执行循环主体之前测试条件。 |
| [for 循环](https://www.runoob.com/cplusplus/cpp-for-loop.html) | 多次执行一个语句序列，简化管理循环变量的代码。               |
| [do...while 循环](https://www.runoob.com/cplusplus/cpp-do-while-loop.html) | 除了它是在循环主体结尾测试条件外，其他与 while 语句类似。    |
| [嵌套循环](https://www.runoob.com/cplusplus/cpp-nested-loops.html) | 您可以在 while、for 或 do..while 循环内使用一个或多个循环。  |



### 循环控制语句

循环控制语句更改执行的正常序列。当执行离开一个范围时，所有在该范围中创建的自动对象都会被销毁。

C++ 提供了下列的控制语句。点击链接查看每个语句的细节。

| 控制语句                                                     | 描述                                                         |
| :----------------------------------------------------------- | :----------------------------------------------------------- |
| [break 语句](https://www.runoob.com/cplusplus/cpp-break-statement.html) | 终止 **loop** 或 **switch** 语句，程序流将继续执行紧接着 loop 或 switch 的下一条语句。 |
| [continue 语句](https://www.runoob.com/cplusplus/cpp-continue-statement.html) | 引起循环跳过主体的剩余部分，立即重新开始测试条件。           |
| [goto 语句](https://www.runoob.com/cplusplus/cpp-goto-statement.html) | 将控制转移到被标记的语句。但是不建议在程序中使用 goto 语句。 |



## [C++ 判断](https://www.runoob.com/cplusplus/cpp-decision.html)



## [C++ 函数](https://www.runoob.com/cplusplus/cpp-functions.html)



## [C++ 数字](https://www.runoob.com/cplusplus/cpp-numbers.html)



## [C++ 数组](https://www.runoob.com/cplusplus/cpp-arrays.html)



## [C++ 字符串](https://www.runoob.com/cplusplus/cpp-strings.html)



## [C++ 指针](https://www.runoob.com/cplusplus/cpp-pointers.html)



## [C++ 引用](https://www.runoob.com/cplusplus/cpp-references.html)



## [C++ 日期 & 时间](https://www.runoob.com/cplusplus/cpp-date-time.html)



## [C++ 基本的输入输出](https://www.runoob.com/cplusplus/cpp-basic-input-output.html)



## [C++ 数据结构](https://www.runoob.com/cplusplus/cpp-data-structures.html)




# C++ 面向对象


## [C++ 类 & 对象](https://www.runoob.com/cplusplus/cpp-classes-objects.html)



## [C++ 继承](https://www.runoob.com/cplusplus/cpp-inheritance.html)



## [C++ 重载运算符和重载函数](https://www.runoob.com/cplusplus/cpp-overloading.html)



## [C++ 多态](https://www.runoob.com/cplusplus/cpp-polymorphism.html)



## [C++ 数据抽象](https://www.runoob.com/cplusplus/cpp-data-abstraction.html)



## [C++ 数据封装](https://www.runoob.com/cplusplus/cpp-data-encapsulation.html)



## [C++ 接口（抽象类）](https://www.runoob.com/cplusplus/cpp-interfaces.html)




# C++ 高级教程


## [C++ 文件和流](https://www.runoob.com/cplusplus/cpp-files-streams.html)



## [C++ 异常处理](https://www.runoob.com/cplusplus/cpp-exceptions-handling.html)



## [C++ 动态内存](https://www.runoob.com/cplusplus/cpp-dynamic-memory.html)



## [C++ 命名空间](https://www.runoob.com/cplusplus/cpp-namespaces.html)



## [C++ 模板](https://www.runoob.com/cplusplus/cpp-templates.html)



## [C++ 预处理器](https://www.runoob.com/cplusplus/cpp-preprocessor.html)



## [C++ 信号处理](https://www.runoob.com/cplusplus/cpp-signal-handling.html)



## [C++ 多线程](https://www.runoob.com/cplusplus/cpp-multithreading.html)



## [C++ Web 编程](https://www.runoob.com/cplusplus/cpp-web-programming.html)




# C++ 资源库


## [C++ STL 教程](https://www.runoob.com/cplusplus/cpp-stl-tutorial.html)



## [C++ 标准库](https://www.runoob.com/cplusplus/cpp-standard-library.html)



## [C++ 有用的资源](https://www.runoob.com/cplusplus/cpp-useful-resources.html)



## [C++ 实例](https://www.runoob.com/cplusplus/cpp-examples.html)

