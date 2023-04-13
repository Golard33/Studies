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
#define MAX_SIZE 1024


int creerSocketTCP(long port);
ssize_t sendFile(char* path, int socketD);
#endif