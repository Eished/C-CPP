/* TCPdtc.cpp - main, TCPdaytime */
#include <stdio.h>
#include <stdlib.h>
#include <winsock.h>
void TCPdaytime(const char*, const char*);
void errexit(const char*, ...);
SOCKET connectTCP(const char*, const char*);
#define LINELEN 128
#define WSVERS MAKEWORD(2, 0)
/*--------------------------------------------------------
* main - TCP client for DAYTIME service
*--------------------------------------------------------
*/
int main(int argc, char* argv[])
{
	char* host = "localhost";  /* host to use if none supplied */
	char* service = "daytime"; /* default service port */
	WSADATA wsadata;
	switch (argc)
	{
	case 1:
		host = "localhost";
		break;
	case 3:
		service = argv[2];
		/* FALL THROUGH */
	case 2:
		host = argv[1];
		break;
	default:
		fprintf(stderr, "usage: TCPdaytime [host [port]]\n");
		exit(1);
	}
	if (WSAStartup(WSVERS, &wsadata) != 0)
		errexit("WSAStartup failed\n");
	TCPdaytime(host, service);
	WSACleanup();
	return 0; /* exit */
}
/*-----------------------------------------------------
* TCPdaytime - invoke Daytime on specified host and print results
*-----------------------------------------------------
*/
void TCPdaytime(const char* host, const char* service)
{
	char buf[LINELEN + 1]; /* buffer for one line of text  */
	SOCKET s;              /* socket descriptor  */
	int cc;                /* recv character count */
	s = connectTCP(host, service);
	cc = recv(s, buf, LINELEN, 0);
	while (cc != SOCKET_ERROR && cc > 0)
	{
		buf[cc] = '\0'; /* ensure null-termination  */
		(void)fputs(buf, stdout);
		cc = recv(s, buf, LINELEN, 0);
	}
	closesocket(s);
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

/* consock.cpp - connectsock */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock.h>
#ifndef INADDR_NONE
#define INADDR_NONE 0xffffffff
#endif /* INADDR_NONE */
void errexit(const char*, ...);
/*-------------------------------------------------------
* connectsock - allocate & connect a socket using TCP or UDP
*------------------------------------------------------
*/

SOCKET connectsock(const char* host, const char* service, const char* transport)
{
	struct hostent* phe;    /* pointer to host information entry  */
	struct servent* pse;    /* pointer to service information entry */
	struct protoent* ppe;   /* pointer to protocol information entry */
	struct sockaddr_in sin; /* an Internet endpoint address */
	int s, type;            /* socket descriptor and socket type */
	memset(&sin, 0, sizeof(sin));
	sin.sin_family = AF_INET;

	/* Map service name to port number */
	if (pse = getservbyname(service, transport))
		sin.sin_port = pse->s_port;
	else if ((sin.sin_port = htons((u_short)atoi(service))) == 0)
		errexit("can't get \"%s\" service entry\n", service);
	/* Map host name to IP address, allowing for dotted decimal */
	if (phe = gethostbyname(host))
		memcpy(&sin.sin_addr, phe->h_addr, phe->h_length);
	else if ((sin.sin_addr.s_addr = inet_addr(host)) == INADDR_NONE)
		errexit("can't get \"%s\" host entry\n", host);
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
	/* Connect the socket */
	if (connect(s, (struct sockaddr*)&sin, sizeof(sin)) == SOCKET_ERROR)
		errexit("can't connect to %s.%s: %d\n", host, service,
			GetLastError());
	return s;
}

/* conTCP.cpp - connectTCP */
/*----------------------------------------------------
* connectTCP - connect to a specified TCP service
* on a specified host
*---------------------------------------------------
*/
SOCKET connectTCP(const char* host, const char* service)
{
	return connectsock(host, service, "tcp");
}
