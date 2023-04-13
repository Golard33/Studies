#include"udp.h"

int creerSocketUDP(long port)
{
    int sock;
    static struct sockaddr_in addr_local;
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == -1)
    {
        perror("Erreur création socket");
        return (-1);
    }
    // liaison de la socket sur le port local 4000
    bzero(&addr_local, sizeof(struct sockaddr_in));
    addr_local.sin_family = AF_INET;
    addr_local.sin_port = htons((uint16_t)port);
    addr_local.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(sock, (struct sockaddr *)&addr_local, sizeof(addr_local)) == -1)
    {
        perror("Erreur bind");
        return (-1);
    }
    if (port == 0)
        printf("Liaison sur un port libre reussie.\n");
    else
        printf("Liaison sur le port %ld reussie.\n", port);
    return sock;
}