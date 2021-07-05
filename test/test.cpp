#include <cstring>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
int main()
{
  char a = 'A';
  char b[3] = "CS";
  char c[3];
  c[0] = a;
  std::cout << sizeof(a) << std::endl;
  std::cout << sizeof(b) << std::endl;
  std::cout << sizeof(c) << c << std::endl;
  return 0;
}