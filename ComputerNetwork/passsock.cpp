/* passsock.cpp - passivesock */
#include <stdlib.h>
#include <string.h>
#include <winsock.h>
void errexit(const char *, ...);
/*-----------------------------------------------------------------------
* passivesock - allocate & bind a server socket using TCP or UDP
*------------------------------------------------------------------------
*/
SOCKET passivesock(const char *service, const char *transport, int qlen)
{
  struct servent *pse;    /* pointer to service information entry  */
  struct protoent *ppe;   /* pointer to protocol information entry */
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
  if (bind(s, (struct sockaddr *)&sin, sizeof(sin)) == SOCKET_ERROR)
    errexit("can't bind to %s port: %d\n", service,
            GetLastError());
  if (type == SOCK_STREAM && listen(s, qlen) == SOCKET_ERROR)
    errexit("can't listen on %s port: %d\n", service,
            GetLastError());
  return s;
}