/* UDPdtd.cpp - main, UDPdaytimed */
#include <stdlib.h>
#include <time.h>
#include <winsock.h>
void errexit(const char *, ...);
SOCKET passiveUDP(const char *);
#define WSVERS MAKEWORD(2, 0)
/*------------------------------------------------------------------------
* main - Iterative UDP server for DAYTIME service
*------------------------------------------------------------------------
*/
void main(int argc, char *argv[])
{
  struct sockaddr_in fsin;   /* the from address of a client  */
  char *service = "daytime"; /* service name or port number  */
  SOCKET sock;               /* socket */
  int alen;                  /* from-address length  */
  char *pts;                 /* pointer to time string  */
  time_t now;                /* current time  */
  WSADATA wsadata;
  switch (argc)
  {
  case 1:
    break;
  case 2:
    service = argv[1];
    break;
  default:
    errexit("usage: UDPdaytimed [port]\n");
  }
  if (WSAStartup(WSVERS, &wsadata) != 0)
    errexit("WSAStartup failed\n");
  sock = passiveUDP(service);
  while (1)
  {
    alen = sizeof(struct sockaddr);
    if (recvfrom(sock, buf, sizeof(buf), 0,
                 (struct sockaddr *)&fsin, &alen) == SOCKET_ERROR)
      errexit("recvfrom: error %d\n", GetLastError());
    (void)time(&now);
    pts = ctime(&now);
    (void)sendto(sock, pts, strlen(pts), 0,
                 (struct sockaddr *)&fsin, sizeof(fsin));
  }
  return 1; /* not reached */
}