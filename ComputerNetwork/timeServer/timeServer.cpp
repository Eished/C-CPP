#pragma warning(disable:4996)  // 关闭全部警告
/* TCPdtd.cpp - main, TCPdaytimed */
#include <process.h>
#include <stdlib.h>
#include <stdarg.h>
#include <time.h>
#include <string.h>
#include <winsock.h>
#include <iostream>

using namespace std;
void errexit(const char*, ...);
void TCPdaytimed(SOCKET);
SOCKET passiveTCP(const char*, int);
#define QLEN 5
#define WSVERS MAKEWORD(2, 0)
/*------------------------------------------------------------------------
* main - Concurrent TCP server for DAYTIME service
*------------------------------------------------------------------------
*/
int main(int argc, char* argv[])
{
	struct sockaddr_in fsin;   /* the from address of a client  */
	const	char* service = "daytime"; /* service name or port number*/
	SOCKET msock, ssock;       /* master & slave sockets  */
	int alen;                  /* from-address length */
	WSADATA wsadata;
	switch (argc)
	{
	case 1:
		break;
	case 2:
		service = argv[1];
		break;
	default:
		errexit("usage: TCPdaytimed [port]\n");
	}
	if (WSAStartup(WSVERS, &wsadata) != 0)
		errexit("WSAStartup failed\n");
	msock = passiveTCP(service, QLEN);
	while (1)
	{
		alen = sizeof(struct sockaddr);
		ssock = accept(msock, (struct sockaddr*)&fsin, &alen);
		if (ssock == INVALID_SOCKET)
			errexit("accept failed: error number %d\n",
				GetLastError());
		if (_beginthread((void (*)(void*))TCPdaytimed, 0, (void*)ssock) < 0)
		{
			errexit("_beginthread: %s\n", strerror(errno));
		}
	}
	return 1; /* not reached */
}
/*----------------------------------------------------------------------
* TCPdaytimed - do TCP DAYTIME protocol
*-----------------------------------------------------------------------
*/
void TCPdaytimed(SOCKET fd)
{
	char* pts;  /* pointer to time string */
	time_t now; /* current time */
	(void)time(&now);
	pts = ctime(&now);
	(void)send(fd, pts, strlen(pts), 0);
	(void)closesocket(fd);
}

/* passTCP.cpp - passiveTCP */
SOCKET passivesock(const char*, const char*, int);
/*------------------------------------------------------------------------------------
* passiveTCP - create a passive socket for use in a TCP server
*------------------------------------------------------------------------------------
*/
SOCKET passiveTCP(const char* service, int qlen)
{
	return passivesock(service, "tcp", qlen);
}

/* passsock.cpp - passivesock */
void errexit(const char*, ...);
/*-----------------------------------------------------------------------
* passivesock - allocate & bind a server socket using TCP or UDP
*------------------------------------------------------------------------
*/
SOCKET passivesock(const char* service, const char* transport, int qlen)
{
	struct servent* pse;    /* pointer to service information entry  */
	struct protoent* ppe;   /* pointer to protocol information entry */
	struct sockaddr_in sin; /* an Internet endpoint address */
	SOCKET s;               /* socket descriptor  */
	int type;               /* socket type (SOCK_STREAM, SOCK_DGRAM)*/
	memset(&sin, 0, sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = INADDR_ANY;
	/* Map service name to port number */
	if (pse = getservbyname(service, transport))
		sin.sin_port = (u_short)pse->s_port;
	else if ((sin.sin_port = htons((u_short)atoi(service))) == 0)
		errexit("can't get \"%s\" service entry\n", service);
	/* Map protocol name to protocol number */
	if ((ppe = getprotobyname(transport)) == 0)
		errexit("can't get \"%s\" protocol entry\n", transport);
	/* Use protocol to choose a socket type */
	if (strcmp(transport, "udp") == 0)
		type = SOCK_DGRAM;
	else
		type = SOCK_STREAM;
	/* Allocate a socket */
	s = socket(PF_INET, type, ppe->p_proto);
	if (s == INVALID_SOCKET)
		errexit("can't create socket: %d\n", GetLastError());
	/* Bind the socket */
	if (bind(s, (struct sockaddr*)&sin, sizeof(sin)) == SOCKET_ERROR)
		errexit("can't bind to %s port: %d\n", service,
			GetLastError());
	if (type == SOCK_STREAM && listen(s, qlen) == SOCKET_ERROR)
		errexit("can't listen on %s port: %d\n", service,
			GetLastError());
	return s;
}

/* errexit.cpp - errexit */
/*----------------------------------------------------------
* errexit - print an error message and exit
*----------------------------------------------------------
*/
/*VARARGS1*/
void errexit(const char* format, ...)
{
	va_list args;
	va_start(args, format);
	vfprintf(stderr, format, args);
	va_end(args);
	WSACleanup();
	exit(1);
}