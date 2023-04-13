#include "tcp.h"

int creerSocketTCP(long port)
{
    int sock;
    static struct sockaddr_in addr_local;
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
        perror("Erreur création socket");
        return (-1);
    }
    // liaison de la socket sur le port "port"
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

ssize_t sendFile(char *path, int socketD)
{
    char Data[MAX_SIZE];
    char Buffer[MAX_SIZE];
    ssize_t length = -1;
    FILE *file = fopen(path, "r");
    if (file == NULL)
    {
        printf("Error opening file");
        return -1;
    }

    while (fgets(Buffer, MAX_SIZE, file) != NULL)
        printf("DEBUG: %s", Buffer);
    strcat(Data, Buffer);
    if (strnlen(Data, MAX_SIZE) == 0)
    {
        printf("Fichier vide ou erreur de lecture du fichier");
        return -1;
    }
    fclose(file);
    printf("\nPreparation de l'envoi de %s %ld octets:\n%s\n", path, strlen(Data), Data);
    length = write(socketD, &Data, strlen(Data));
    printf("DEBUG: %ld",length);
    return (length);
}