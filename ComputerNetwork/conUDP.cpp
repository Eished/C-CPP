/* conUDP.cpp - connectUDP */
#include <winsock.h>
SOCKET connectsock(const char *, const char *, const char *);
/*-------------------------------------------------------
* connectUDP - connect to a specified UDP service
* on a specified host
*-----------------------------------------------------
*/
SOCKET connectUDP(const char *host, const char *service)
{
  return connectsock(host, service, "udp");
}