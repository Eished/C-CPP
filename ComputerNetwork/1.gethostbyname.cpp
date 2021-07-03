#include <iostream>
#include <winsock.h>
#define WSVERS MAKEWORD(2, 0)

using namespace std;

int main(int argc, char *argv[])
{
  WSADATA wsadata;
  WSAStartup(WSVERS, &wsadata);
  struct hostent *h;
  h = gethostbyname(argv[1]);
  cout << h->h_addr_list << endl;
  cout << h->h_name << endl;
  cout << h->h_aliases << endl;
  cout << h->h_addrtype << endl;
  cout << h->h_length << endl;
  return 0;
}