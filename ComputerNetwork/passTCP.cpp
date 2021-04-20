/* passTCP.cpp - passiveTCP */
#include <winsock.h>
SOCKET passivesock(const char *, const char *, int);
/*------------------------------------------------------------------------------------
* passiveTCP - create a passive socket for use in a TCP server
*------------------------------------------------------------------------------------
*/
SOCKET passiveTCP(const char *service, int qlen)
{
  return passivesock(service, "tcp", qlen);
}