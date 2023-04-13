#include "tcp.h"

#define CLI_MSG "\n-------------CLIENT-------------\n"
#define HOST argv[1]
#define PORT argv[2]
#define RES_PATH "./ClientData/res.txt"
#define CALC_PATH "./ClientData/calc.txt"
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
    // socket locale coté client
    int sock;
    // message à envoyer au serveur
    char* buffer;
    // chaîne où sera écrit le message reçu
    // nombre d'octets envoyés/reçus
    int nb_octets;
    // création socket TCP
    sock = creerSocketTCP(0);
    // récupération identifiants de la machine serveur
    addr_serveur = getAddrbyHostPort(HOST,atol(PORT));
    // connexion de la socket client locale à la socket coté serveur
    if (connect(sock,
                (struct sockaddr *)&addr_serveur,
                sizeof(struct sockaddr_in)) == -1)
    {
        perror("erreur connexion serveur");
        exit(1);
    }
    // connexion etablie, on envoie le message
    nb_octets = sendFile(CALC_PATH,sock);

    printf("%d octets envoyés à %s:%s\n", nb_octets, argv[1], argv[2]);
    // on attend la réponse du serveur
    readTextPrint(sock,buffer);

    FILE *f = fopen(RES_PATH, "w+");
    fprintf(f, "%s", buffer);
    fprintf(stderr,"Reponse sauvegardee dans %s\n",RES_PATH);
    fclose(f);
    // on ferme la socket
    close(sock);
    return 0;
}
