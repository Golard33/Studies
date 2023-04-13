#include "tcp.h"

#define MESSAGE_DEFAUT "Connexion au serveur TCP etablie!"
#define SRV_MSG "\n-------------SERVEUR-------------\n"
#define HOST argv[1]
#define FILE_PATH "./ServerData/Lorem.txt"
int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        perror("Utilisation: ./Serveur [port serveur]");
        exit(1);
    }
    printf(SRV_MSG);
    // adresse socket coté client
    static struct sockaddr_in addr_client;
    // longueur adresse
    int lg_addr;
    // socket d'écoute et de service
    int socket_ecoute, socket_service;
    // buffer qui contiendra le message reçu
    char message[MAX_SIZE];
    // chaîne reçue du client
    char *chaine_recue;
    // chaîne renvoyée au client
    //char *reponse = MESSAGE_DEFAUT;
    // nombre d'octets reçus ou envoyés
    int nb_octets;
    // création socket TCP d'écoute
    socket_ecoute = creerSocketTCP(atol(HOST));
    // configuration socket écoute : 5 connexions max en attente
    if (listen(socket_ecoute, 5) == -1)
    {
        perror("Erreur listen");
        exit(1);
    }

    // on attend la connexion du client
    lg_addr = sizeof(struct sockaddr_in);
    socket_service = accept(socket_ecoute,
                            (struct sockaddr *)&addr_client,
                            (socklen_t *)&lg_addr);
    if (socket_service == -1)
    {
        perror("Erreur accept");
        exit(1);
    }
    char *ip_client = inet_ntoa(addr_client.sin_addr);
    
    // la connexion est établie, on attend les données envoyées par le client
    nb_octets = read(socket_service, message,
                     MAX_SIZE);
    printf(SRV_MSG);
    
    // affichage du message reçu
    chaine_recue =
        (char *)malloc(nb_octets * sizeof(char));
    memcpy(chaine_recue, message, nb_octets);
    


    printf("Message recu: \t%s \nde la part de %s \nsur le port %d\n", chaine_recue, ip_client, ntohs(addr_client.sin_port));
    
    // on envoie la réponse au client
    printf(SRV_MSG);
    sendFile(FILE_PATH, socket_service);
    
    // on ferme les sockets
    close(socket_service);
    close(socket_ecoute);
    
    return 0;
}
