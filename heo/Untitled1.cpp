#include <winsock.h>
#include<stdio.h>
int main()
{
WSADATA wsaData; // if this doesn't work
//WSAData wsaData; // then try this instead
// MAKEWORD(1,1) for Winsock 1.1, MAKEWORD(2,0) for Winsock 2.0:
if (WSAStartup(MAKEWORD(1,1), &wsaData) != 0) {
fprintf(stderr, "WSAStartup failed.\n");
exit(1);
}
}
