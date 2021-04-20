/* conTCP.cpp - connectTCP */
#include <winsock.h>
SOCKET connectsock(const char *, const char *, const char *);
/*----------------------------------------------------
* connectTCP - connect to a specified TCP service
* on a specified host
*---------------------------------------------------
*/
SOCKET connectTCP(const char *host, const char *service)
{
  return connectsock(host, service, "tcp");
}