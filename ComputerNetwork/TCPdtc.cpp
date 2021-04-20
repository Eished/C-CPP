/* TCPdtc.cpp - main, TCPdaytime */
#include <stdio.h>
#include <stdlib.h>
#include <winsock.h>
void TCPdaytime(const char *, const char *);
void errexit(const char *, ...);
SOCKET connectTCP(const char *, const char *);
#define LINELEN 128
#define WSVERS MAKEWORD(2, 0)
/*--------------------------------------------------------
* main - TCP client for DAYTIME service
*--------------------------------------------------------
*/
int main(int argc, char *argv[])
{
  char *host = "localhost";  /* host to use if none supplied */
  char *service = "daytime"; /* default service port */
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
void TCPdaytime(const char *host, const char *service)
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