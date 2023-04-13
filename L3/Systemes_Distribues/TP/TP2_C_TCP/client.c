#include "tcp.h"
#define MSG_ENVOIE_DEFAUT "PSEUDOTEST"
#define CLI_MSG "\n-------------CLIENT-------------\n"
#define HOST argv[1]
#define PORT argv[2]
#define FILE_PATH "./ClientData/Log.txt"

int main(int argc, char const *argv[])
{
    if (argc != 3)
    {
        perror("Utilisation: ./Client [nom_serveur] [port_serveur]");
        exit(1);
    }
    printf(CLI_MSG);
    // identification socket d'écoute du serveur
    static struct sockaddr_in addr_serveur;
    // identifiants de la machine où tourne le serveur
    struct hostent *host_serveur;
    // socket locale coté client
    int sock;
    // message à envoyer au serveur
    char *message = MSG_ENVOIE_DEFAUT;
    // chaîne où sera écrit le message reçu
    char reponse[MAX_SIZE];
    // nombre d'octets envoyés/reçus
    int nb_octets;
    // création socket TCP
    sock = creerSocketTCP(0);
    // récupération identifiants de la machine serveur
    host_serveur = gethostbyname(argv[1]);
    if (host_serveur == NULL)
    {
        perror("Erreur récupération adresse serveur\n");
        exit(1);
    }
    // création de l'identifiant de la socket d'écoute du serveur
    bzero((char *)&addr_serveur,
          sizeof(addr_serveur));
    addr_serveur.sin_family = AF_INET;
    addr_serveur.sin_port = htons(atol(argv[2]));
    memcpy(&addr_serveur.sin_addr.s_addr,
           host_serveur->h_addr, host_serveur->h_length);
    // connexion de la socket client locale à la socket coté serveur
    if (connect(sock,
                (struct sockaddr *)&addr_serveur,
                sizeof(struct sockaddr_in)) == -1)
    {
        perror("erreur connexion serveur");
        exit(1);
    }
    // connexion etablie, on envoie le message
    nb_octets = write(sock, message, strlen(message) + 1);
    printf(CLI_MSG);

    printf("%d octets envoyés à %s:%s\n%s\n", nb_octets, argv[1], argv[2], message);
    // on attend la réponse du serveur
    nb_octets = read(sock, reponse, MAX_SIZE);
    printf(CLI_MSG);
    printf("%d octets recus de %s:%s\n%s\n", nb_octets, argv[1], argv[2], reponse);

    FILE *f = fopen(FILE_PATH, "w");
    fprintf(f, "%s", reponse);

    // on ferme la socket
    close(sock);
    return 0;
}
