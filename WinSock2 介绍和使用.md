# [Winsock2使用记录](https://www.cnblogs.com/oberon-zjt0806/p/14814144.html)

> 本文地址：https://www.cnblogs.com/oberon-zjt0806/p/14814144.html
> WinSock 2 MSDN文档：https://docs.microsoft.com/en-us/windows/win32/winsock/windows-sockets-start-page-2
> 一个很好的范例（如果我的代码有问题，可供参考这个）：https://github.com/gaohaoning/cpp_socket



目录

[toc]



# 什么是WinSock？

这还不简单，当然是Windows的袜子啦

WinSock（全称Windows Sockets）是巨硬微软提供的用于Windows平台的C++网络连接库。

简单来说我们知道在Java中，我们可以通过JDK提供的`java.net`库来实现建立套接字的TCP/UDP传输：

```java
public class Client
{
	private String svrip = "";
	private int port;
	
	public AnotherClient(String serverIP,int port) {
		svrip = serverIP;
		this.port = port;
	}
	
	public void Start() {
		Socket cltsock = null; // Client's socket
		
		OutputStream ostrm = null; // O-stream for sending to server
		BufferedWriter bwriter = null;
		
		InputStream istrm = null;
		BufferedReader breader = null;
		
		try {
			cltsock = new Socket(svrip,port);
			System.out.println(String.format("Client at %s has started.", cltsock.getInetAddress().toString()));
			istrm = cltsock.getInputStream();
			
			// .....后面不写了，意思意思得了
```

WinSock的功能与之类似，只不过因为结构僵化的C++标准委员会迟迟不将专用于C++网络连接的`<network>`纳入STL（标准库）中，所以我们这里只好委曲求全地使用Windows的标准，在Linux环境中，替代品为系统内核提供的`<sys/socket.h>`库。不过整体使用上，两者区别并不那么大。

Winsock比较常用的有两类版本——1.1和2.x。本文这里，当然了，标题也说了，以Winsock2为准，建立一个**IPv4协议下的传输链路**。

# Workflow

嗯，自从因为各种原因对自己产生了一个巨大的否定以来，我发现总结一个具体的工作流程（Workflow）出来还是挺重要的一件事。

那么，我们这里就尝试总结一下，建立一个连接并发送消息期间，Winsock都做了什么：

graph TD subgraph server[Server] 	begin[开始] --> init[初始化WSA] --> setupsvr[建立Server Socket] --> binding[设置地址绑定] --> listening[Server Socket启动监听] 	accept((接收来自Client的连接)) 	recv[接收来自Client的消息] 	send[向Client发送信息] 	close[关闭Server Socket] 	terminal[结束] 	listening --> accept 	accept --> send 	accept --> recv 	send --> close 	recv --> close 	close --> terminal end subgraph client[Client] 	beginc[开始] --> initc[初始化WSA] --> setupclt[建立Client Socket] 	connect{连接ip所在的Server的连接} 	crecv[接收来自Server的消息] 	csend[向Server发送信息] 	cclose[关闭Client Socket] 	terminalc[结束] 	setupclt --> connect 	connect --> csend 	connect --> crecv 	csend --> cclose 	crecv --> cclose 	cclose --> terminalc end csend -.-> recv send -.-> crecv

# Server Side（服务端）

先说Server这边，从上面这张图来看，他做了这么几件事：

1. 初始化WSA
   所谓WSA就是WinSock API，当然了，因为我们这里用的是Winsock2，所以我们做的就是对Winsock2的初始化，毕竟只有初始化之后我们才能使用Winsock里面的相关功能，当然具体来说这里其实还包括一些其他的事情，比如版本比对之类的。
2. 建立Server的套接字
   当我们可以使用Winsock的相关功能后，我们就可以通过Winsock建立套接字以建立连接了。
3. 绑定地址
   这个先留着，放到代码里再说……
4. 启动监听
   当套接字被启动后，我们允许该套接字监听是否有外部的客户端的连接请求
5. 接收Client的连接
   有Client的时候我们获得这位Client的套接字。
6. 收发消息
   连接建立完成了，可以传输数据了
7. 结束
   打完收工！

## 初始化WSA

既然我们使用Winsock2，那么我们首先做的必然就是对Winsock2的调取，原始的来说，Winsock2隶属于Win32的系统库，当你引入头文件`WinSock2.h`的时候你就已经获得了Winsock2的结构声明。当然，为了让他能够调取系统库，我们需要把他静态链接进来

```cpp
#include <WinSock2.h>
#include <ws2tcpip.h>	//???
#pragma comment(lib, "WS2_32.lib")
```

注意，上面第2行中，我又引入了一个`ws2tcpip.h`，这是因为在`Winsock2.h`中声明的有关函数**不再倡用了（Deprecated）**，这种情况下直接使用这类函数会直接触发错误，当然，**如果你执意要用的话，那就在最开始的时候补充一下抑制宏**：

```cpp
//如果你非要使用Deprecated内容的话
#define _WINSOCK_DEPRECATED_NO_WARNINGS
// includes... pragma...
```

然后我们开始在Server的主程序里初始化WSA，初始化过程主要经过：设置版本限制→初始化→获得初始化信息，因此我们首先设置我们能接受的WinSock库的最低版本：

```cpp
WORD verRequest = MAKEWORD(1, 1);
```

虽然说我们用的是WinSock2，不过我们这里本着向下兼容的原则，我们约定要是只有1.1也行……
然后我们需要使用`WSAStartup`函数来真正初始化WSA，这个函数接收两个参数，一个版本约定和一个数据结构：

```cpp
WSAData wData;
int $err = WSAStartup(wVersionRequest, &wData);
```

初始化期间，系统会根据你提供的Version Request来评估当前系统内的Winsock版本，并将结果写进wData中，返回初始化失败的错误代码，如果没有错误返回0，因此，这里我们在发生错误的情况下直接结束程序。

```cpp
if($err != 0)
{
	cout << "Initialization Failed" << endl;
	WSACleanup();
	ExitProcess($err);
}
```

如果到这里没进入if的话，那么说明初始化成功了，我们可以输出WSA的信息看一眼：

```cpp
cout << wData.szDescription << endl;
```

`wData.szDescription`存放了初始化时系统获得的API描述文本，在我的机器上，输出的是

```text
WINSOCK 2.0
```

很明显，因为我用的WinSock2嘛，也就是说现在为止我系统中提供的WinSock库并没有什么问题。

## 建立服务端套接字

既然WSA可以正常使用，那么从这里开始我们就正式的开始用WSA提供的功能了。

既然是服务端程序，那么能想到的第一件事必然是：**建立套接字（Socket）**！

WinSock提供了`SOCKET`类型和`socket`函数来表示并创建一个套接字。我们先来看一下`socket()`函数该怎么用：

```cpp
SOCKET socket(
    _In_ int af,
    _In_ int type,
    _In_ int protocol
    );
```

其实前面修饰符还有什么`_Must_inspect_result_`什么的，这些我们先不管，捞干的来看就是这样的函数。

| 参数名称 | 类型 | 用途                                                         |
| -------: | :--: | :----------------------------------------------------------- |
|       af | int  | 你的socket所使用的地址协议族，我们这里只介绍IPv4的，所以这里填入`AF_INET`就好了 |
|     type | int  | 你的socket建立连接所传输的数据形式，比较常用的有流式`SOCK_STREAM`或者数据报`SOCK_DGRAM`，当然还有其他的这里暂时不作介绍 |
| protocol | int  | 你的socket使用的传输协议，可填入以`IPPROTO_*`开头的常量，也可以填入`0`来自动选择协议，自动选择协议的规则与`type`相关，例如`type=SOCK_STREAM`那么会使用TCP协议，如果是`type=SOCK_DGRAM`那么会选择UDP协议 |

我们这里以IPv4的TCP协议为例，那么可以创建这样的socket：

```cpp
SOCKET sckSrv = socket(AF_INET, SOCK_STREAM, 0);
```

如果socket没有成功创建，那么函数会返回一个`INVALID_SOCKET`

## 为Server socket绑定地址

使用上面的方法创建的套接字仅包含地址协议的信息，但这个套接字并不具备一个地址，出于某种原因，我们并不能直接操纵Socket实体本身来设置这些东西，因为`SOCKET`类型说到底只是一个句柄id，并不承载其他信息。WinSock提供了专用于给socket绑定地址的函数`bind`：

```cpp
int bind(
	SOCKET		s,
	const sockaddr 	*name,
	int            	namelen
    );
```

还是直接捞干的看，这里的`SOCKET s`肯定就是刚才的`sckSrv`，填进去就可以了。而`name`这里就需要特别注意一下了，`name`要求你输入的实际上是你的ip地址，但是这里接受的类型是`SOCKADDR *`，`SOCKADDR`是用于表示地址的一个数据结构，包含地址协议族和具体的ip地址信息，不过`SOCKADDR`的结构很raw，不是很好构建，因此我们需要使用一个改进结构`SOCKADDR_IN`，这个结构专用于IPv4（IPv6请使用`SOCKADDR_IN6`）：

```cpp
typedef struct sockaddr_in {
        short   sin_family;
        u_short sin_port;
        struct  in_addr sin_addr;
        char    sin_zero[8];
} SOCKADDR_IN;
```

因此我们这里如果要构建地址的话：

```cpp
SOCKADDR_IN addrSrv;
addrSrv.sin_family = AF_INET;
```

注意，这里的`sin_addr`是个`in_addr`类型，这个类型并不支持直接输入我们所说的字面上的ip地址"xxx.xxx.xxx.xxx"这种的，因此如果你想用字符串的ip地址输入进去的话，就必须用`inet_aton`做地址形式转换。

```cpp
#ifdef _WINSOCK_DEPRECATED_NO_WARNINGS
//指定为本机地址
addrSrv.sin_addr = inet_addr("127.0.0.1");
//或者你也可以指定为缺省路由（0.0.0.0），向下面这样写
addrSrv.sin_addr = INADDR_ANY;
#endif
```

然而，如果你没有解除Deprecation warning（没有定义`_WINSOCK_DEPRECATED_NO_WARNINGS`）的话，那么直接使用`inet_addr`会**报错**，这种情况下如果**坚持不添加**抑制宏的替代做法是使用`inet_pton`来完成：

```cpp
#if (!defined _WINSOCK_DEPRECATED_NO_WARNINGS) && (defined _WS2TCPIP_H_)
inet_pton(AF_INET, "127.0.0.1", &(addrSrv.sin_addr));
#endif
```

其实这个类型是个32位整数，如果你确定你的ip地址写成32位整数是什么样子的话那么没有必要费劲巴力的做地址形式转换，而直接赋值成`0x????????`的形式，但是这样代码可读性很差，而且还涉及到本机到网络传输时的大小端点转换问题（`hton*`），而`inet_*`转换出来的地址码是确定符合网络传输的形式（这话是巨硬msdn里说的）。

最后我们不要忘了还得提供端口号：

```cpp
addrSrv.sin_port = htons(17500);	// 这个需要转换为网络格式，端口号随你喜欢
```

当然，如果你引入了`<ws2tcpip.h>`，那么你还可以继续用更加通用的地址结构`sockaddr_gen`，当然，不用也没关系，使用这个结构（其实是个union）只是规避了接下来的类型转换的问题。(注意，名字是**小写**的，和之前的不一样，之前的`SOCKADDR`和`SOCKADDR_IN`其实也可以全小写)：

```cpp
#ifdef _WS2TCPIP_H_
sockaddr_gen gaddrSrv;
gaddrSrv.AddressIn = addrSrv;
```

上述内容其实是为了构建地址（不得不说确实挺麻烦，而且事情特别多，但是如果理清的话其实很容易），说白了就是准备填入`name`这个参数，但是注意，由于`bind`的`name`参数是`SOCKADDR *`类型，因此你不管用什么类型折腾，最后都要转换回这个raw类型：

```cpp
// 如果没定义gaddrSrv
bind(sckSrv, (SOCKADDR *)&addrSrv, sizeof(SOCKADDR));
// 如果定义了gaddrSrv
bind(sckSrv, &(gaddrSrv.Address), sizeof(SOCKADDR));
```

第三个参数的`namelen`就指定成`SOCKADDR`的大小即可（因为name指向SOCKADDR嘛）。

## 启动服务端监听

服务端嘛，你要服务的嘛，所以我们需要打开服务端的监听，让sckSrv听取外界是否有其他socket连入，使用`listen`函数启动监听：

```cpp
listen(sckSrv, SOMAXCONN);
```

第一个参数就是你的服务器套接字，第二个参数是最大允许的连接等待队列长度，`SOMAXCONN`是最大的允许限制范围了，设置为`SOMAXCONN`可以理解为没有数量限制（其实是有的，`SOMAXCONN=0x7fffffff`，当然，WinSock允许使用`SOMAXCONN_HINT`设置更大的值，但仅限于能够在巨硬自己的TCP/IP协议服务供应器下使用，我们这里不考虑这个东西）。

## 获取连入的客户端

启用监听后，Server将能够获得来自外界的连接请求，使用`accept`原语来取得连入的客户端信息：

```cpp
SOCKET accept(
  SOCKET   s,
  sockaddr *addr,
  int      *addrlen
);
```

`accept`原语令服务器`s`接收第一个等待连接的客户端（**如果没有则阻塞这个服务器进程，直至有第一个进入**），并获取这个客户端的地址信息，存入`addr`中。

由于我们后面会需要Server向Client发送数据，因此我们这里获得客户端addr的行为是必需的，所以还是类似的方式，定义客户端的addr结构：

```cpp
SOCKADDR_IN addrCli;
SOCKET sckCli = accept(sckSrv, (SOCKADDR *) &addrCli, sizeof(SOCKADDR));
```

由于我们并不知道客户端的任何网络地址信息，因此我们只创建`addrCli`但无需初始化，与`addrSrv`类似，你也可以使用`sockaddr_gen`类型，这里不演示了。

> 再次强调，这里的`accept`原语是**阻塞**的！如果需要非阻塞的accept原语，可能需要`select`配合，但是本文暂时不讨论这个。

当然，如果`accept`的参数不正确（比如你的addrlen大小不对），那么他有可能返回一个`INVALID_SOCKET`

## 收发数据

获得了客户端的socket，我们就说**建立了从server到socket的连接**，连接建立完成，我们就可以经由这个连接传递数据了（双向地）。

当然了，直接使用`send`和`recv`原语就可以了，但是在使用之前，我们先确立缓冲区用于存储收发的数据：

```cpp
char sendbuf[1024] = "Hello, from SERVER.",
	 recvbuf[1024];
```

然后我们集中看一下send和recv原语：

```cpp
int send(
  SOCKET     s,
  const char *buf,
  int        len,
  int        flags
);

int recv(
  SOCKET s,
  char   *buf,
  int    len,
  int    flags
);
```

应该很言简意赅了，`s`是你要发送的client socket，`flags`我们先不管，给0就可以，`flags`主要控制消息收发时的行为，我们这里就按照一般的收发方法正常收发就可以了。我们这里让server**先对连入的client发送消息，然后再发送**（留意这一点，下面我们写客户端的时候就需要把这个顺序反过来，当然你也可以在这里先收后发，那在客户端那边就还得反过来）：

```cpp
send(sckCli, sendbuf, sizeof(sendbuf), 0);
recv(sckCli, recvbuf, sizeof(recvbuf), 0);
```

就可以收发信息了，如果没有别的事情的话，那么就可以……

## 关闭套接字、释放WSA

**善始善终是一种美德**，特别是对于C++而言。如果没有别的事情，我们想结束的话，那就需要关闭套接字，然后释放掉WSA，这两个很简单：

```cpp
closesocket(sckCli);
closesocket(sckSrv);
WSACleanup();
ExitProcess(0);
```

好了，服务端程序就写的差不多了，代码会在文章最后整理。

# Client Side（客户端）

客户端和服务端的写法就差不太多了，但是注意几点：

1. 由于客户端是积极连接服务端，因此客户端一般不需要自己的ip地址，所以客户端的socket**不需要地址绑定，也不需要启动监听**
2. 服务端是`accept`原语，那么**客户端就是`connect`原语**
3. 客户端只需要创建自己的socket，**不需要考虑服务端**
4. 没了

相比较刚才的过程而言，再补充说明几个新加入的东西……

## 与服务端的积极连接

服务端是被动的accept外界的连接，那等的是谁呢，显然就是客户端主动的connect。

```cpp
int connect(
  SOCKET         s,
  const sockaddr *name,
  int            namelen
);
```

其中`s`是**客户端自己的socket**，虽然说客户端的socket并不需要绑定地址，但是客户端仍然要提供**服务端**的地址信息（不然鬼知道你想跟谁连），也就是说`addrSrv`仍然要提供。

然后再注意的一点就是**收发和服务端应当是相反的**。

同样，代码我在后面汇总。

# 当你遇到错误时……

写这两个程序期间，你可能就已经开始运行调试了，当然多数时候你不大可能一遍写成（除非你是直接拷的代码），因此难以避免的你会遇到各种错误，有的和你的代码有关，有的可能与你的网络环境有关，前者你大可通过调试器和文档来解决，但后者就很难捕捉了。

而WinSock用于返回错误的函数`WSAGetLastError()`，主要用于返回错误代码，你可以根据[msdn文档](https://docs.microsoft.com/en-us/windows/win32/winsock/windows-sockets-error-codes-2)对照你的错误代码来定位你的错误。如果没有任何错误，该函数应当返回0。

# 代码汇总

#### Server

```cpp
#include <WinSock2.h>
#include <ws2tcpip.h>	//???
#include <iostream>

#pragma comment(lib, "WS2_32.lib")

using namespace std;

int main(int argc, char **argv)
{
	WORD verRequest = MAKEWORD(1, 1);
	WSAData wData;
	int $err = WSAStartup(wVersionRequest, &wData);
	if($err != 0)
	{
		cout << "Initialization Failed" << endl;
		WSACleanup();
		ExitProcess($err);
	}
	cout << wData.szDescription << endl;

	SOCKET sckSrv = socket(AF_INET, SOCK_STREAM, 0);
	if(sckSrv == INVALID_SOCKET)
	{
		closesocket(sckSvr);
		WSACleanup();
		ExitProcess(INVALID_SOCKET);
	}

	SOCKADDR_IN addrSrv;
	addrSrv.sin_family = AF_INET;
	inet_pton(AF_INET, "127.0.0.1", &(addrSrv.sin_addr));
	addrSrv.sin_port = htons(17500);

	bind(sckSrv, (SOCKADDR *)&addrSrv, sizeof(SOCKADDR));

	listen(sckSrv, SOMAXCONN);

	SOCKADDR_IN addrCli;
	SOCKET sckCli = accept(sckSrv, (SOCKADDR *) &addrCli, sizeof(SOCKADDR));
	
	if(sckCli == INVALID_SOCKET)
	{
		closesocket(sckCli);
		closeSocket(sckSvr)
		WSACleanup();
		ExitProcess(INVALID_SOCKET);
	}

	char sendbuf[1024] = "Hello, from SERVER.",
	 	 recvbuf[1024];

	send(sckCli, sendbuf, sizeof(sendbuf), 0);
	recv(sckCli, recvbuf, sizeof(recvbuf), 0);
	
	cout << recvbuf << endl;

	closesocket(sckCli);
	closesocket(sckSrv);

	WSACleanup();
	
	ExitProcess(0);
}
```

#### Client

```cpp
#include <WinSock2.h>
#include <ws2tcpip.h>	//???
#include <iostream>

#pragma comment(lib, "WS2_32.lib")

using namespace std;

int main(int argc, char **argv)
{
	WORD verRequest = MAKEWORD(1, 1);
	WSAData wData;
	int $err = WSAStartup(wVersionRequest, &wData);
	if($err != 0)
	{
		cout << "Initialization Failed" << endl;
		WSACleanup();
		ExitProcess($err);
	}
	cout << wData.szDescription << endl;

	SOCKET sckCli;
	if(sckCli == INVALID_SOCKET)
	{
		closesocket(sckCli);
		WSACleanup();
		ExitProcess(INVALID_SOCKET);
	}

	SOCKADDR_IN addrSrv;
	addrSrv.sin_family = AF_INET;
	inet_pton(AF_INET, "127.0.0.1", &(addrSrv.sin_addr));
	addrSrv.sin_port = htons(17500);

	connect(sckCli, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));

	char sendbuf[1024] = "Hi, from CLIENT.",
	 	 recvbuf[1024];

	recv(sckCli, recvbuf, sizeof(recvbuf), 0);
	cout << recvbuf << endl;
	send(sckCli, sendbuf, sizeof(sendbuf), 0);

	closesocket(sckCli);

	WSACleanup();

	ExitProcess(0);
}
```

------

作者：[Oberon](https://www.cnblogs.com/oberon-zjt0806/)

出处：https://www.cnblogs.com/oberon-zjt0806/