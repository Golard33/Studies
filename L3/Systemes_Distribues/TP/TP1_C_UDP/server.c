#include "udp.h"

#define TAILLEBUF 100
#define MSG_ENVOIE_DEFAUT "Bien recu"
#define SRV_MSG "\n-------------SERVEUR-------------\n"
#define HOST argv[1]

int main(int argc, char const *argv[])
{

    if(argc != 2) {
        perror("Utilisation: ./Serveur [port_serveur]");
        exit(1);
    }
    printf(SRV_MSG);
    // adresse de la socket coté serveur
    static struct sockaddr_in addr_client;
    // identifiant du client
    struct hostent *host_client;
    // taille de l'addresse socket
    socklen_t lg;
    // descripteur de la socket locale
    int sock;
    // chaine  à envoyer en réponse
    char *reponse = MSG_ENVOIE_DEFAUT;
    // buffer de réception
    char buffer[TAILLEBUF];
    // chaine reçue
    char *chaine;
    // nombre d'octets lus ou envoyés
    int nb_octets;
    // création de la socket
    sock = creerSocketUDP(atol(HOST));
    // attente de données venant d'un client
    lg = sizeof(struct sockaddr_in);
    nb_octets = recvfrom(sock, buffer, TAILLEBUF, 0, (struct sockaddr *)&addr_client, &lg);
    if (nb_octets == -1)
    {
        perror("Erreur réception paquet");
        exit(1);
    } // récupère nom de la machine émettrice des données
    host_client = gethostbyaddr(&(addr_client.sin_addr), sizeof(addr_client.sin_addr), AF_INET);
    if (host_client == NULL)
    {
        perror("Erreur gethostbyaddr");
        exit(1);
    }
    printf(SRV_MSG);
    // affichage message reçu et coordonnées émetteur
    chaine = (char *)malloc(nb_octets * sizeof(char));
    memcpy(chaine, buffer, nb_octets);
    printf("Message recu: \t%s \nde la part de %s \nsur le port %d\n", chaine, host_client->h_name, ntohs(addr_client.sin_port));
    // envoi de la réponse à l'émetteur
    nb_octets = sendto(sock, reponse, strlen(reponse) + 1, 0, (struct sockaddr *)&addr_client, lg);
    if (nb_octets == -1)
    {
        perror("Erreur envoi réponse");
        exit(1);
    } // fermeture la socket
    close(sock);
    
    return 0;
}
