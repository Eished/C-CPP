/* errexit.cpp - errexit */
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <winsock.h>
/*----------------------------------------------------------
* errexit - print an error message and exit
*----------------------------------------------------------
*/
/*VARARGS1*/
void errexit(const char *format, ...)
{
  va_list args;
  va_start(args, format);
  vfprintf(stderr, format, args);
  va_end(args);
  WSACleanup();
  exit(1);
}