#include "tcp.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

int SocketServeurTCP(long port) 
{
    int socket_fd;
    static struct sockaddr_in address;

    //creation socket TCP
      if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("erreur creation socket");
        exit(1);
    }

    // liaison de la socket sur le port "port"
    memset(&address, 0, sizeof address);
    address.sin_family = AF_INET;
    address.sin_port = htons((uint16_t)port);
    address.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(socket_fd, (struct sockaddr *)&address, sizeof(address)) == -1) 
    {
        perror("Erreur bind");
        return (-1);
    }
    if (port == 0)
        printf("Liaison sur un port libre reussie.\n");
    else
        printf("Liaison sur le port %ld reussie.\n", port);
    return socket_fd;
}

