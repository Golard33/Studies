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

struct sockaddr_in getAddrbyHostPort(const char *hostName, const long port)
{
    struct hostent *Hostaddr;
    static struct sockaddr_in addr_sv;

    Hostaddr = gethostbyname(hostName);
    if (Hostaddr == NULL)
    {
        perror("Erreur récupération adresse serveur\n");
        exit(1);
    }
    // création de l'identifiant de la socket d'écoute du serveur
    bzero(&addr_sv,
          sizeof(struct sockaddr_in));
    addr_sv.sin_family = AF_INET;
    addr_sv.sin_port = htons((uint16_t) port);
    memcpy(&addr_sv.sin_addr.s_addr,
           Hostaddr->h_addr, Hostaddr->h_length);
    return addr_sv;
}

int sendFile(char *path, int socketD)
{
    char Data[MAX_SIZE] = "";
    char Buffer[MAX_SIZE];
    int length = -1;
    FILE *file = fopen(path, "r");
    if (file == NULL)
    {
        printf("Error opening file");
        return -1;
    }

    while (feof(file) == 0 && (fgets(Buffer, MAX_SIZE, file) != NULL))
    {
        strcat(Data, Buffer);
    }
    fclose(file);
    //printf("\nPreparation de l'envoi du contenu de %s\n", path);
    length = write(socketD, &Data, strlen(Data));
    if (length == -1) fprintf(stderr,"Erreur lors de l'envoi de %s\n",path);
    else fprintf(stderr,"\nLe contenu de %s a ete correctement envoye\n",path);
    return (length);
}

int readTextPrint(int socket_service,char *buffer)
{
    int nb_octets;
    nb_octets = read(socket_service, buffer,
                     MAX_SIZE);
    if (nb_octets <= 0)
    {
        fprintf(stderr,"Read error\n");
        exit(EXIT_FAILURE);
    }

    fprintf(stderr,"\n%d bytes recus:\n%s\n",nb_octets, buffer);
    return nb_octets;
}
