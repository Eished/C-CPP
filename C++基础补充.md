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



**标识符**

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



为什么要使用 **using namespace std;** ?

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



## [C++ 变量作用域](https://www.runoob.com/cplusplus/cpp-variable-scope.html)



## [C++ 常量](https://www.runoob.com/cplusplus/cpp-constants-literals.html)



## [C++ 修饰符类型](https://www.runoob.com/cplusplus/cpp-modifier-types.html)



## [C++ 存储类](https://www.runoob.com/cplusplus/cpp-storage-classes.html)



## [C++ 运算符](https://www.runoob.com/cplusplus/cpp-operators.html)



## [C++ 循环](https://www.runoob.com/cplusplus/cpp-loops.html)



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

