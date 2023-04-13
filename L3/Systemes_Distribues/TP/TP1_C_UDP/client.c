#include "udp.h"

#define TAILLEBUF 100
#define MSG_ENVOIE_DEFAUT "Bonjour"
#define CLI_MSG "\n-------------CLIENT-------------\n"
#define HOST argv[1]
#define PORT argv[2]

int main(int argc, char const *argv[])
{
    if(argc != 3) {
        perror("Utilisation: ./Client [nom_serveur] [port_serveur]");
        exit(1);
    }
    printf(CLI_MSG);

    
    //identifiant de la machine serveur
    struct hostent *serveur_hote;
    //adresse de la socket cote serveur
    static struct sockaddr_in addr_serveur;
    //taille de l'adresse socket
    socklen_t lg;

    int sock;
    char *msg = MSG_ENVOIE_DEFAUT;
    char buffer[TAILLEBUF];
    char *reponse;
    int nb_octets;

    //creation socket UDP
    sock = creerSocketUDP(0);
    if (sock == -1)
    {
        perror("Erreur socket");
    }
    
    //recuperation identifiant srv
    serveur_hote = gethostbyname(HOST);
    
    if (serveur_hote == NULL)
    {
        perror("Erreur adresse serveur");
        exit(1);
    }
    
    //creation adresse socket destinatrice
    bzero(&addr_serveur,sizeof(struct sockaddr_in));
    addr_serveur.sin_family = AF_INET;
    addr_serveur.sin_port = htons( atol(PORT));
    memcpy(&addr_serveur.sin_addr.s_addr,serveur_hote -> h_addr,serveur_hote->h_length);

    //envoi du message au serveur
    lg = sizeof(struct sockaddr_in);
    nb_octets = sendto(
        sock,
        msg,
        strlen(msg)+1,
        0,
        (struct sockaddr*) &addr_serveur,lg);

    if (nb_octets == -1)
    {
        perror("Erreur de reponse serveur");
        exit(1);
    }

    printf("%d octets envoyés à %s:%s\n", nb_octets,HOST,PORT);

    //on attend la reponse du serveur
    nb_octets = recvfrom(sock, buffer, TAILLEBUF, 0, (struct sockaddr*) &addr_serveur,&lg);
    
    if (nb_octets == -1)
    {
        perror("Erreur de reponse serveur");
        exit(1);
    }
    printf(CLI_MSG);
    reponse = (char*) malloc(nb_octets*sizeof(char));
    memcpy(reponse,buffer,nb_octets);
    printf("Reponse recue du serveur : %s\n",reponse);


    //fermeture socket
    close(sock);

    return 0;
}
