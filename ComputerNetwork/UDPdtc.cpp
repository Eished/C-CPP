/* UDPdtc.cpp - main, UDPdaytime */
#include <stdio.h>
#include <stdlib.h>
#include <winsock.h>
void UDPdaytime(const char *, const char *);
void errexit(const char *, ...);
SOCKET connectUDP(const char *, const char *);
#define LINELEN 128
#define WSVERS MAKEWORD(2, 0)
#define MSG "what daytime is it ?\n"
/*--------------------------------------------------------
* main - UDP client for DAYTIME service
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
    fprintf(stderr, "usage: UDPdaytime [host [port]]\n");
    exit(1);
  }
  if (WSAStartup(WSVERS, &wsadata) != 0)
    errexit("WSAStartup failed\n");
  UDPdaytime(host, service);
  WSACleanup();
  return 0; /* exit */
}
/*-----------------------------------------------------
* UDPdaytime - invoke Daytime on specified host and print results
*-----------------------------------------------------
*/
void UDPdaytime(const char *host, const char *service)
{
  char buf[LINELEN + 1]; /* buffer for one line of text */
  SOCKET s;              /* socket descriptor */
  int n;                 /* recv character count  */
  s = connectUDP(host, service);
  (void)send(s, MSG, strlen(MSG), 0);
  /* Read the daytime */
  n = recv(s, buf, LINELEN, 0);
  if (n == SOCKET_ERROR)
    errexit("recv failed: recv() error %d\n", GetLastError());
  else
  {
    buf[cc] = '\0'; /* ensure null-termination  */
    (void)fputs(buf, stdout);
  }
  closesocket(s);
  return 0; /* exit  */
}