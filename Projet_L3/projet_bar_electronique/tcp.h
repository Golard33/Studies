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


int SocketServeurTCP (long port);


#endif