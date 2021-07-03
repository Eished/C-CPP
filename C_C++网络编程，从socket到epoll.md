# 虚拟机安装 ssh

```shell
1.安装命令：
sudo apt-get install openssh-server
安装完成，服务默认已经开启，可以远程ssh连接了。

2.查看ssh服务状态：
sudo service ssh status

3.ssh服务重启命令：
sudo service ssh restart

4.ssh服务的配置文件，可以修改服务端口，权限控制等
sudo gedit /etc/ssh/sshd_config
```



# [vi 常用命令](https://www.freecplus.net/28096d085cbe471c986d246b43ac4fe4.html)

## 一、关于vi

vi是最强大的文本编辑器，没有之一。尽管 vi已经是古董级的软件，但还是有无数新人迎着困难去[学习](https://www.iplaysoft.com/tag/学习)使用，可见其经典与受欢迎的程度。

无论是小说中还是电视剧，真正强大的武器都不容易驾驭，需要付出一些努力才能收获到更加强大的力量，对于vi这种**上古[神器](https://www.iplaysoft.com/tag/神器)**来说更是如此。由于它全程使用键盘操作，很多首次接触 vi的人会觉得不习惯而中途放弃。然而，坚持下来的朋友就会渐渐地发现这种键盘操作的设计绝妙，经典之所以能成为经典，必然有它的道理，不用解释太多。

观察一个程序员对vi的熟练程度，可以判断它的技术水平，如果他对vi不熟悉，就肯定不是Linux平台下的程序员，说vi不好用的人也肯定不熟悉vi和Linux，没有例外。

## 二、创建/打开文件

vi 文件名

打开一个文件，如果文件不存在，就创建它。

示例：

vi book.c

## 三、vi的三种模式

vi 有三种模式，命令行模式、插入模式和替换模式，在命令行模式下，任何键盘输入都是命令，在插入模式和替换模式下，键盘输入的才是字符。

插入模式和替换模式也合称为编辑模式。

## 四、vi的常用命令

Esc    从编辑模式切换到命令行模式。

 

i   在光标所在位置前面开始插入。

a   在光标所在的位置后面开始插入。

o  在光标所在位置行的下面插入空白行。

O  在光标所在位置行的上面插入空白行。

I   在光标所在位置行的行首开始插入。

A  在光标所在位置行的行末开始插入。

 

k   类似方向键上。

j   类似方向键下。

h  类似方向键左。

l   类是方向键右。

 

Ctrl+u  向上翻半页。

Ctrl+d  向下翻页。

 



Ctrl+g    显示光标所在位置的行号和文件的总行数。



nG 光标跳到文件的第n行行首。

G  光标跳到文件最后一行。

:5回车  光标跳到第5行。

:n回车  光标跳到第n行。

 

0   光标跳到当前行的行首。

$   光标跳到当前行的行尾。

 

w   光标跳到下个单词的开头。

b   光标跳到上个单词的开头。

e  光标跳到本单词的尾部。

 

x    每按一次，删除光标所在位置的一个字符。

nx  如"3x"表示删除光标所在位置开始的3个字符。

dw 删除光标所在位置到本单词结尾的字符。

D  删除本行光标所在位置后面全部的内容。

 

dd  删除光标所在位置的一行。

ndd 如"3dd"表示删除光标所在位置开始的3行。

 

yy  将光标所在位置的一行复制到缓冲区。

nyy 将光标所在位置的n行复制到缓冲区。

p   将缓冲区里的内容粘贴到光标所在位置。

 

r   替换光标所在位置的一个字符 replace。

R  从光标所在位置开始替换，直到按下"Esc"。

cw 从光标所在位置开始替换单词，直到按下"Esc"。

 

u  撤销命令，可多次撤销。

 

J  把当前行的下一行接到当前行的尾部。

 

/abcd  在当前打开的文件中查找“abcd”文本内容。

n   查找下一个。

N   查找上一下。

 

.  重复执行上一次执行的vi命令。

 

~  对光标当前所在的位置的字符进行大小写转换。

 

列操作

Ctrl+V  光标上或下  大写的I  输入内容  Esc

 

:w回车  存盘。

:w!回车  强制存盘。

:wq回车 存盘退出。

:x回车  存盘退出。

:q回车 不存盘退出。

:q!回车  不存盘强制退出。

 

:g/aaaaaaaaa/s//bbbbbb/g回车  把文件中全部的aaaaaaaaa替换成bbbbbb。

 

Ctl+insert  复制鼠标选中的文本，相当于Ctl+c。

Shift+insert 输出鼠标选中的文本，相当于Ctl+v。

以上两个命令在windows和UNIX中是通用的。

## vim 粘贴时取消自动换行

当vim开启smartindent时，对于代码会有自动换行的功效。但是，有时候我们需要在向vim中粘贴代码时，需要暂时关闭自动换行的功能。

**解决方法：**

:set paste

之后进行插入操作，vim提示变为： – INSERT (paste) –

这时就不再有自动换行。

**恢复：**

:set nopaste

vim提示变为：– INSERT –



## vim 支持c/c++ STL即标准库关键字高亮

```shell
git clone https://github.com/octol/vim-cpp-enhanced-highlight.git /tmp/vim-cpp-enhanced-highlight
mkdir -p ~/.vim/after/syntax/
mv /tmp/vim-cpp-enhanced-highlight/after/syntax/cpp.vim ~/.vim/after/syntax/cpp.vim
rm -rf /tmp/vim-cpp-enhanced-highlight
```



# [C语言makefile文件](https://www.freecplus.net/b7a1c199959f4349b2a98874864a2000.html)

```shell
apt install make
```

在软件的工程中的源文件是很多的，其按照类型、功能、模块分别放在若干个目录和文件中，哪些文件需要编译，那些文件需要后编译，那些文件需要重新编译，甚至进行更复杂的功能操作，这就有了我们的系统编译的工具。

在linux和unix中，有一个强大的实用程序，叫make，可以用它来管理多模块程序的编译和链接，直至生成可执行文件。

make程序需要一个编译规则说明文件，称为makefile，makefile文件中描述了整个软件工程的编译规则和各个文件之间的依赖关系。

makefile就像是一个shell脚本一样，其中可以执行操作系统的命令，它带来的好处就是我们能够实现“自动化编译”，一旦写好，只要一个make命令，整个软件功能就完全自动编译，提高了软件开发的效率。

make是一个命令工具，是一个解释makefile中指令的命令工具，一般来说大多数编译器都有这个命令，使用make可以是重新编译的次数达到最小化。

## 一、makefile的编写

makefile文件的规则可以非常复杂，比C程序还要复杂，我通过示例来介绍它的简单用法。

文件名：makefile，内容如下：

```shell
all:book1 book46
 
book1:book1.c
        gcc -o book1 book1.c
 
book46:book46.c _public.h _public.c
        gcc -o book46 book46.c _public.c
 
clean:
        rm -f book1 book46
```

**第一行**

```shell
all:book book46
```

all: 这是固定的写法。

book1 book46表示需要编译目标程序的清单，中间用空格分隔开，如果清单很长，可以用\换行。

**第二行**

makefile文件中的空行就像C程序中的空行一样，只是为了书写整洁，没有什么意义。

**第三行**

```shell
book1:book1.c
```

book1:表示需要编译的目标程序。

如果要编译目标程序book1，需要依赖源程序book1.c，当book1.c的内容发生了变化，执行make的时候就会重新编译book1。

**第四行**

```shell
        gcc -o book1 book1.c
```

这是一个编译命令，和在操作系统命令行输入的命令一样，但是要注意一个问题，在gcc之前要用tab键，看上去像8个空格，实际不是，一定要用tab，空格不行。

**第六行**

```shell
book46:book46.c _public.h _public.c
```

与第三行的含义相同。

book46:表示编译的目标程序。

如果要编译目标程序book46，需要依赖源程序book46.c、_public.h和_public.c三个文件，只要任何一个的内容发生了变化，执行make的时候就会重新编译book46。

**第七行**

```shell
        gcc -o book46 book46.c _public.c
```

与第四行的含义相同。

**第九行**

```shell
clean:
```

清除目标文件，清除的命令由第十行之后的脚本来执行。

**第十行**

```shell
        rm  -f  book1 book46
```

清除目标文件的脚本命令，注意了，rm之前也是一个tab键，不是空格。

## 二、make命令

makefile准备好了，在命令提示符下执行make就可以编译makefile中all参数指定的目标文件。

执行make编译目标程序：

![image.png](https://www.freecplus.net/runoobFiles/ueditor/image/20200318/1584536443451006468.png)

再执行一次make：

![image.png](https://www.freecplus.net/runoobFiles/ueditor/image/20200318/1584536454572081980.png)

因为全部的目标程序都是最新的，所以提示没有目标可以编译。

执行make clean，执行清除目标文件的指令。

![image.png](https://www.freecplus.net/runoobFiles/ueditor/image/20200318/1584536467750040871.png)

再执行make重新编译。

![image.png](https://www.freecplus.net/runoobFiles/ueditor/image/20200318/1584536479435025308.png)

修改_public.c程序，随便改点什么，只要改了就行。

然后再执行make：

![image.png](https://www.freecplus.net/runoobFiles/ueditor/image/20200318/1584536490024019135.png)

注意了，因为book46依赖的源程序之一_public.c改变了，所以book46重新编译。

book1没有重新编译，因为book1依赖的源文件并没有改变。

## 三、makefile文件中的变量

makefile中，变量就是一个名字，变量的值就是一个文本字符串。在makefile中的目标，依赖，命令或其他地方引用变量时，变量会被它的值替代。

我通过示例来介绍它的简单用法。

```shell
CC=gcc
FLAG=-g
 
all:book1 book46
 
book1:book1.c
        $(CC) $(FLAG) -o book1 book1.c
 
book46:book46.c _public.h _public.c
        $(CC) $(FLAG) -o book46 book46.c _public.c
 
clean:
        rm -f book1 book46
```

**第一行**

```shell
CC=gcc
```

定义变量CC，赋值gcc。

**第二行**

```shell
FLAG=-g
```

定义变量FLAG，赋值-g。

**第七行**

```shell
        $(CC)  $(FLAG) -o book1 book1.c
```

`$(CC)和$(FLAG)`就是使用变量CC和FLAG的值，类似于C语言的宏定义，替换后的结果是：

```shell
        gcc -g -o book1 book1.c
```

编译效果：

![image.png](https://www.freecplus.net/runoobFiles/ueditor/image/20200318/1584536550181088438.png)

在makefile文件中，使用变量的好处有两个：

​	1）如果在很多编译指令采用了变量，只要修改变量的值，就相当于修改全部的编译指令；

​	2）把比较长的、公共的编译指令采用变量来表示，可以让makefile更简洁。

四、应用经验

makefile文件的编写可以很复杂，复杂到我不想看，在实际开发中，用不着那么复杂的makefile，我追求简单实用的方法，腾出更多的时间和精力去做更重要的事情，那些把makefile文件写得很复杂的程序员在我看来是吃饱了撑的。

五、课后作业

把您这段时间写的程序全部编写到makefile中，以后再也不要在命令提示符下用gcc了。

六、版权声明 

C语言技术网原创文章，转载请说明文章的来源、作者和原文的链接。

来源：C语言技术网（[www.freecplus.net](http://www.freecplus.net/)）

作者：码农有道

如果文章有错别字，或者内容有错误，或其他的建议和意见，请您联系我们指正，非常感谢！！！

# C\C++网络编程，从socket到epoll

## [学习Linux编程前的准备](https://www.freecplus.net/d08d40bbe87e4ff3bdcab956fdfca6f8.html)

编译器

```shell
apt install gcc-c++
```

编译C程序的命令是gcc，编译C++程序的命令是g++，g++命令和gcc命令的用法相同，把gcc改为g++就可以了，我们在学习C语言时编写的那些示例程序，基本上都可以用g++来编译。

```
g++ -o book1 book1.c
```

**XSHELL ssh vim 語法高亮配置**

文件, 默认/当前会话属性, 终端, 终端类型：linux

文件, 默认/当前会话属性, 终端, 键盘, 功能键类型：linux



**如何对xshell中的输入命令的那一行进行高亮显示呢**

修改你登录用户目录下的.bashrc文件，把46行的注释去掉保存后重新登录即可

（如果使用其他用户登录，其下的.bashrc也要修改，和xshell无关）

![//img1.sycdn.imooc.com/5e5d2d2c0001168204690193.jpg](https://img3.sycdn.imooc.com/5e5d2d2c0001168204690193.jpg)

重新登录后

![//img4.sycdn.imooc.com/5e5d2d9b00015d9804510114.jpg](https://img1.sycdn.imooc.com/5e5d2d9b00015d9804510114.jpg)





## 一、网络通信socket

socket就是插座（中文翻译成套接字有点莫名其妙），运行在计算机中的两个程序通过socket建立起一个通道，数据在通道中传输。

   ![image.png](https://www.freecplus.net/runoobFiles/ueditor/image/20200922/1600759995760026651.png)

socket把复杂的TCP/IP协议族隐藏了起来，对程序员来说，只要用好socket相关的函数，就可以完成网络通信。

## 二、socket的分类

socket提供了流（stream）和数据报（datagram）两种通信机制，即流socket和数据报socket。

流socket基于TCP协议，是一个有序、可靠、双向字节流的通道，传输数据不会丢失、不会重复、顺序也不会错乱。就像两个人在打电话，接通后就在线了，您一句我一句的聊天。

数据报socket基于UDP协议，不需要建立和维持连接，可能会丢失或错乱。UDP不是一个可靠的协议，对数据的长度有限制，但是它的速度比较高。就像短信功能，一个人向另一个人发短信，对方不一定能收到。

在实际开发中，数据报socket的应用场景极少，本教程只介绍流socket。

## 三、客户/服务端模式

在TCP/IP网络应用中，两个程序之间通信模式是客户/服务端模式（client/server），客户/服务端也叫作客户/服务器，各人习惯。

![image.png](https://www.freecplus.net/runoobFiles/ueditor/image/20200922/1600758212122001314.png)

### 1、服务端的工作流程

1）创建服务端的socket。

2）把服务端用于通信的地址和端口绑定到socket上。

3）把socket设置为监听模式。

4）接受客户端的连接。

5）与客户端通信，接收客户端发过来的报文后，回复处理结果。

6）不断的重复第5）步，直到客户端断开连接。

7）关闭socket，释放资源。

**服务端示例（server.cpp）**

```cpp
/*
 * 程序名：server.cpp，此程序用于演示socket通信的服务端
 * 作者：C语言技术网(www.freecplus.net) 日期：20190525
*/
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
 
int main(int argc,char *argv[])
{
  if (argc!=2)
  {
    printf("Using:./server port\nExample:./server 5005\n\n"); return -1;
  }
 
  // 第1步：创建服务端的socket。
  int listenfd;
  if ( (listenfd = socket(AF_INET,SOCK_STREAM,0))==-1) { perror("socket"); return -1; }
 
  // 第2步：把服务端用于通信的地址和端口绑定到socket上。
  struct sockaddr_in servaddr;    // 服务端地址信息的数据结构。
  memset(&servaddr,0,sizeof(servaddr));
  servaddr.sin_family = AF_INET;  // 协议族，在socket编程中只能是AF_INET。
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);          // 任意ip地址。
  //servaddr.sin_addr.s_addr = inet_addr("192.168.190.134"); // 指定ip地址。
  servaddr.sin_port = htons(atoi(argv[1]));  // 指定通信端口。
  if (bind(listenfd,(struct sockaddr *)&servaddr,sizeof(servaddr)) != 0 )
  { perror("bind"); close(listenfd); return -1; }
 
  // 第3步：把socket设置为监听模式。
  if (listen(listenfd,5) != 0 ) { perror("listen"); close(listenfd); return -1; }
 
  // 第4步：接受客户端的连接。
  int  clientfd;                  // 客户端的socket。
  int  socklen=sizeof(struct sockaddr_in); // struct sockaddr_in的大小
  struct sockaddr_in clientaddr;  // 客户端的地址信息。
  clientfd=accept(listenfd,(struct sockaddr *)&clientaddr,(socklen_t*)&socklen);
  printf("客户端（%s）已连接。\n",inet_ntoa(clientaddr.sin_addr));
 
  // 第5步：与客户端通信，接收客户端发过来的报文后，回复ok。
  char buffer[1024];
  while (1)
  {
    int iret;
    memset(buffer,0,sizeof(buffer));
    if ( (iret=recv(clientfd,buffer,sizeof(buffer),0))<=0) // 接收客户端的请求报文。
    {
       printf("iret=%d\n",iret); break;  
    }
    printf("接收：%s\n",buffer);
 
    strcpy(buffer,"ok");
    if ( (iret=send(clientfd,buffer,strlen(buffer),0))<=0) // 向客户端发送响应结果。
    { perror("send"); break; }
    printf("发送：%s\n",buffer);
  }
 
  // 第6步：关闭socket，释放资源。
  close(listenfd); close(clientfd);
}
```

### 2、客户端的工作流程

1）创建客户端的socket。

2）向服务器发起连接请求。

3）与服务端通信，发送一个报文后等待回复，然后再发下一个报文。

4）不断的重复第3）步，直到全部的数据被发送完。

5）第4步：关闭socket，释放资源。

**客户端示例（client.cpp）**

```cpp
/*
 * 程序名：client.cpp，此程序用于演示socket的客户端
 * 作者：C语言技术网(www.freecplus.net) 日期：20190525
*/
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
 
int main(int argc,char *argv[])
{
  if (argc!=3)
  {
    printf("Using:./client ip port\nExample:./client 127.0.0.1 5005\n\n"); return -1;
  }
 
  // 第1步：创建客户端的socket。
  int sockfd;
  if ( (sockfd = socket(AF_INET,SOCK_STREAM,0))==-1) { perror("socket"); return -1; }
 
  // 第2步：向服务器发起连接请求。
  struct hostent* h;
  if ( (h = gethostbyname(argv[1])) == 0 )   // 指定服务端的ip地址。
  { printf("gethostbyname failed.\n"); close(sockfd); return -1; }
  struct sockaddr_in servaddr;
  memset(&servaddr,0,sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(atoi(argv[2])); // 指定服务端的通信端口。
  memcpy(&servaddr.sin_addr,h->h_addr,h->h_length); // 不能直接赋值
  if (connect(sockfd, (struct sockaddr *)&servaddr,sizeof(servaddr)) != 0)  // 向服务端发起连接清求。
  { perror("connect"); close(sockfd); return -1; }
 
  char buffer[1024];
 
  // 第3步：与服务端通信，发送一个报文后等待回复，然后再发下一个报文。
  for (int ii=0;ii<3;ii++)
  {
    int iret;
    memset(buffer,0,sizeof(buffer));
    sprintf(buffer,"这是第%d个超级女生，编号%03d。",ii+1,ii+1);
    if ( (iret=send(sockfd,buffer,strlen(buffer),0))<=0) // 向服务端发送请求报文。
    { perror("send"); break; }
    printf("发送：%s\n",buffer);
 
    memset(buffer,0,sizeof(buffer));
    if ( (iret=recv(sockfd,buffer,sizeof(buffer),0))<=0) // 接收服务端的回应报文。
    {
       printf("iret=%d\n",iret); break;
    }
    printf("接收：%s\n",buffer);
  }
 
  // 第4步：关闭socket，释放资源。
  close(sockfd);
}
```

**在运行程序之前，必须保证服务器的防火墙已经开通了网络访问策略（云服务器还需要登录云控制平台开通访问策略）。**

先启动服务端程序server，服务端启动后，进入等待客户端连接状态，然后启动客户端。

客户端的输出如下：

![image.png](https://www.freecplus.net/runoobFiles/ueditor/image/20200922/1600748091684066055.png)

服务端的输出如下：

![image.png](https://www.freecplus.net/runoobFiles/ueditor/image/20200922/1600748125501002008.png)

## 四、注意事项



在socket通信的客户端和服务器的程序里，出现了多种数据结构，调用了多个函数，涉及到很多方面的知识，对初学者来说，更重要的是了解socket通信的过程、每段代码的用途和函数调用的功能，不要去纠缠这些结构体和函数的参数，这些函数和参数虽然比较多，但可以修改的非常少，别抄错就可以了，需要注意的地方我会提出。

### 1、socket文件描述符



在UNIX系统中，一切输入输出设备皆文件，socket()函数的返回值其本质是一个文件描述符，是一个整数。

### 2、服务端程序绑定地址

如果服务器有多个网卡，多个IP地址，socket通信可以指定用其中一个地址来进行通信，也可以任意ip地址。

1）指定ip地址的代码

```cpp
  m_servaddr.sin_addr.s_addr = inet_addr("192.168.149.129");  // 指定ip地址
```

2）任意ip地址的代码

```cpp
  m_servaddr.sin_addr.s_addr = htonl(INADDR_ANY);  // 本主机的任意ip地址
```

在实际开发中，采用任意ip地址的方式比较多。

### 3、服务端程序绑定的通信端口

```cpp
  m_servaddr.sin_port = htons(5000);  // 通信端口
```

### 4、客户端程序指定服务端的ip地址

```cpp
  struct hostent* h;
  if ( (h = gethostbyname("118.89.50.198")) == 0 )   // 指定服务端的ip地址。
  { printf("gethostbyname failed.\n"); close(sockfd); return -1; }
```

### 5、客户端程序指定服务端的通信端口

```cpp
  servaddr.sin_port = htons(5000);
```

### 6、send函数

send函数用于把数据通过socket发送给对端。不论是客户端还是服务端，应用程序都用send函数来向TCP连接的另一端发送数据。

函数声明：

```cpp
ssize_t send(int sockfd, const void *buf, size_t len, int flags);
```

sockfd为已建立好连接的socket。

buf为需要发送的数据的内存地址，可以是C语言基本数据类型变量的地址，也可以数组、结构体、字符串，内存中有什么就发送什么。

len需要发送的数据的长度，为buf中有效数据的长度。

flags填0, 其他数值意义不大。

函数返回已发送的字符数。出错时返回-1，错误信息errno被标记。

注意，就算是网络断开，或socket已被对端关闭，send函数不会立即报错，要过几秒才会报错。

如果send函数返回的错误（<=0），表示通信链路已不可用。

### 7、recv函数

recv函数用于接收对端socket发送过来的数据。

recv函数用于接收对端通过socket发送过来的数据。不论是客户端还是服务端，应用程序都用recv函数接收来自TCP连接的另一端发送过来数据。

函数声明：

```cpp
ssize_t recv(int sockfd, void *buf, size_t len, int flags);
```

sockfd为已建立好连接的socket。

buf为用于接收数据的内存地址，可以是C语言基本数据类型变量的地址，也可以数组、结构体、字符串，只要是一块内存就行了。

len需要接收数据的长度，不能超过buf的大小，否则内存溢出。

flags填0, 其他数值意义不大。

函数返回已接收的字符数。出错时返回-1，失败时不会设置errno的值。

如果socket的对端没有发送数据，recv函数就会等待，如果对端发送了数据，函数返回接收到的字符数。出错时返回-1。如果socket被对端关闭，返回值为0。

如果recv函数返回的错误（<=0），表示通信通道已不可用。

### 8、服务端有两个socket

对服务端来说，有两个socket，一个是用于监听的socket，还有一个就是客户端连接成功后，由accept函数创建的用于与客户端收发报文的socket。

### 9、程序退出时先关闭socket

socket是系统资源，操作系统打开的socket数量是有限的，在程序退出之前必须关闭已打开的socket，就像关闭文件指针一样，就像delete已分配的内存一样，极其重要。

值得注意的是，关闭socket的代码不能只在main函数的最后，那是程序运行的理想状态，还应该在main函数的每个return之前关闭。

## 五、相关的库函数

### 1、socket函数

socket函数用于创建一个新的socket，也就是向系统申请一个socket资源。socket函数用户客户端和服务端。

函数声明：

```cpp
int socket(int domain, int type, int protocol);
```

参数说明：

domain：协议域，又称协议族（family）。常用的协议族有AF_INET、AF_INET6、AF_LOCAL（或称AF_UNIX，Unix域Socket）、AF_ROUTE等。协议族决定了socket的地址类型，在通信中必须采用对应的地址，如AF_INET决定了要用ipv4地址（32位的）与端口号（16位的）的组合、AF_UNIX决定了要用一个绝对路径名作为地址。

type：指定socket类型。常用的socket类型有SOCK_STREAM、SOCK_DGRAM、SOCK_RAW、SOCK_PACKET、SOCK_SEQPACKET等。流式socket（SOCK_STREAM）是一种面向连接的socket，针对于面向连接的TCP服务应用。数据报式socket（SOCK_DGRAM）是一种无连接的socket，对应于无连接的UDP服务应用。

protocol：指定协议。常用协议有IPPROTO_TCP、IPPROTO_UDP、IPPROTO_STCP、IPPROTO_TIPC等，分别对应TCP传输协议、UDP传输协议、STCP传输协议、TIPC传输协议。

说了一大堆废话，第一个参数只能填AF_INET，第二个参数只能填SOCK_STREAM，第三个参数只能填0。

除非系统资料耗尽，socket函数一般不会返回失败。

返回值：成功则返回一个socket，失败返回-1，错误原因存于errno 中。

### 2、gethostbyname函数

把ip地址或域名转换为hostent 结构体表达的地址。

函数声明：

```cpp
struct hostent *gethostbyname(const char *name);
```

参数name，域名或者主机名，例如"192.168.1.3"、"www.freecplus.net"等。

返回值：如果成功，返回一个hostent结构指针，失败返回NULL。

gethostbyname只用于客户端。

gethostbyname只是把字符串的ip地址转换为结构体的ip地址，只要地址格式没错，一般不会返回错误。失败时不会设置errno的值。

### 3、connect函数

向服务器发起连接请求。

函数声明：

```
int connect(int sockfd, struct sockaddr * serv_addr, int addrlen);
```

函数说明：connect函数用于将参数sockfd 的socket 连至参数serv_addr 指定的服务端，参数addrlen为sockaddr的结构长度。

返回值：成功则返回0，失败返回-1，错误原因存于errno 中。

connect函数只用于客户端。

如果服务端的地址错了，或端口错了，或服务端没有启动，connect一定会失败。

### 4、bind函数

服务端把用于通信的地址和端口绑定到socket上。

函数声明：

```cpp
int bind(int sockfd, const struct sockaddr *addr,socklen_t addrlen);
```

参数sockfd，需要绑定的socket。

参数addr，存放了服务端用于通信的地址和端口。

参数addrlen表示addr结构体的大小。

返回值：成功则返回0，失败返回-1，错误原因存于errno 中。

如果绑定的地址错误，或**端口已被占用**，bind函数一定会报错，否则一般不会返回错误。

### 5、listen函数

listen函数把主动连接socket变为被动连接的socket，使得这个socket可以接受其它socket的连接请求，从而成为一个服务端的socket。

函数声明：

```cpp
int listen(int sockfd, int backlog);
```

返回：0-成功， -1-失败

 参数sockfd是已经被bind过的socket。socket函数返回的socket是一个主动连接的socket，在服务端的编程中，程序员希望这个socket可以接受外来的连接请求，也就是被动等待客户端来连接。由于系统默认时认为一个socket是主动连接的，所以需要通过某种方式来告诉系统，程序员通过调用listen函数来完成这件事。

参数backlog，这个参数涉及到一些网络的细节，比较麻烦，填5、10都行，一般不超过30。

 当调用listen之后，服务端的socket就可以调用accept来接受客户端的连接请求。

返回值：成功则返回0，失败返回-1，错误原因存于errno 中。

listen函数一般不会返回错误。

### 6、accept函数

服务端接受客户端的连接。

函数声明：

```cpp
int accept(int sockfd,struct sockaddr *addr,socklen_t *addrlen);
```

参数sockfd是已经被listen过的socket。

参数addr用于存放客户端的地址信息，用sockaddr结构体表达，如果不需要客户端的地址，可以填0。

参数addrlen用于存放addr参数的长度，如果addr为0，addrlen也填0。

accept函数等待客户端的连接，如果没有客户端连上来，它就一直等待，这种方式称之为阻塞。

accept等待到客户端的连接后，创建一个新的socket，函数返回值就是这个新的socket，服务端使用这个新的socket和客户端进行报文的收发。

返回值：成功则返回0，失败返回-1，错误原因存于errno 中。

accept在等待的过程中，如果被中断或其它的原因，函数返回-1，表示失败，如果失败，可以重新accept。

### 7、函数小结

服务端函数调用的流程是：socket->bind->listen->accept->**recv/send**->close

客户端函数调用的流程是：socket->connect->**send/recv**->close

其中**send/recv**可以进行多次交互。

## 六、课后作业

1）把client.cpp和server.cpp抄下来，编译运行，试试修改参数再运行。

2）client.cpp和server.cpp程序中，有些代码不能动，有些代码可以动，把能动的都动一下，就算是抄代码，也要抄个明白。

3）服务端的accept函数会阻塞，阻塞是专业名词，即等待，可以用代码测试一下。

4）不管是服务端还是客户端recv函数也会阻塞，可以用代码测试一下。

5）修改client.cpp和server.cpp，实现点对点的聊天功能，用户在客户端输入一个字符串，然后发送给服务端，服务端收到客户端的报文后，也提示用户输入一个字符串，返回给客户端，如果服务端收到客户端的报文是“bye”通信结束。

6）如果以上作业都能完成，建议再把本文章的内容再看一次，对文章开始部分的理论知识将有新的理解。

## 七、版权声明

C语言技术网原创文章，转载请说明文章的来源、作者和原文的链接。

来源：C语言技术网（[www.freecplus.net](http://www.freecplus.net/)）

作者：码农有道