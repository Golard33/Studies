#ifndef TCP
#define TCP

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>
#include <stdint.h>
#include<signal.h>

#define MAX_SIZE 1024


int creerSocketTCP(long port);
int sendFile(char* path, int socketD);
int readTextPrint(int sock_id,char buffer[]);
struct sockaddr_in getAddrbyHostPort(const char* hostName,const long port);

#endif