#include "tcp.h"
#include "calculs.h"
#define MESSAGE_DEFAUT "Connexion au serveur TCP etablie!"
#define SRV_MSG "\n-------------SERVEUR-------------\n"
#define HOST argv[1]
#include <sys/wait.h>

int getIntList(char *strData, int intVec[2])
{
    char *DataCopy;
    char *endptr;
    int nints = 0;
    int val;
    strcpy(DataCopy, strData);
    while ((val = strtol(DataCopy, &endptr, 10)) != 0 && DataCopy != endptr)
    {
        intVec[nints] = val;
        DataCopy = endptr;
        nints++;
    }
    return nints;
}

int analysEtSend(char *src, int sockD)
{
    //fprintf(stderr,"ANALYSE OPTIONS: SOURCE RECUE |%s|\n",src);
    
    char *endptr, BUFFER[MAX_SIZE];
    int vecNumb[MAX_SIZE], nint,n_octets;
    int opt_Calcul = strtol(src, &endptr, 10);
    struct res_analyse_donnees res;
    if (endptr == src)
    {
        fprintf(stderr, "Erreur lecture option %d\n",opt_Calcul);
        exit(1);
    }
    else
    src = endptr;

    if ((nint = getIntList(src, vecNumb)) == 0)
    {
        fprintf(stderr, "Pas d'entiers reconnus\n");
        exit(1);
    }
    
    switch (opt_Calcul)
    {
    case fact:
        if (nint != 1)
        {
            sprintf(BUFFER, "ERR: L'operation Factoriel necessite d'un seul entier.\nEntiers actuels: %d\n", nint);
        }
        else
        {
            fprintf(stderr,"Operation factoriel de %d demandée: !%d\n",vecNumb[0],vecNumb[0]);
            sprintf(BUFFER, "Le factoriel de %d est %ld.\n", vecNumb[0], factoriel(vecNumb[0]));
        }
            
        
        break;
    case puiss:
        fprintf(stderr,"Operation puissance demandee pour les donnees : %s\n",src);
        if (nint != 2)
        {
            sprintf(BUFFER, "ERR: L'operation Puissance necessite deux entiers.\nEntiers actuels : %d\n", nint);
        }
        else
            sprintf(BUFFER, "%d a la puissance %d est egal a %ld.\n", vecNumb[0], vecNumb[1],puissance(vecNumb[0],vecNumb[1]));
        break;
    case analys_don:
        fprintf(stderr,"Analyse de donnees demandee pour les donnees : %s\n",src);
        if (nint < 1)
        {
            sprintf(BUFFER, "ERR: L'analyse de donnees necessite au moins un entier.\nEntiers actuels : %d\n", nint);
        }
        else{
            analyser_donnees(vecNumb,nint,&res);
            sprintf(BUFFER, "Max: %d\nMin: %d\nMoy: %f",
                res.max, res.min,res.moy);
        }
        break;
    default:
        sprintf(BUFFER,"ERR: Option %d non reconnue.\n", opt_Calcul);
        break;
    }
    n_octets = write(sockD,BUFFER,strlen(BUFFER) + 1);
    fprintf(stderr,"Reponse envoyee au client.\n");
    return n_octets;
}

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        perror("Utilisation: ./Serveur [port serveur]");
        exit(1);
    }
    fprintf(stderr, SRV_MSG);
    // adresse socket coté client
    static struct sockaddr_in addr_client;
    // longueur adresse
    int lg_addr;

    // socket d'écoute et de service
    int socket_ecoute, socket_service;
    // buffer qui contiendra le message reçu
    char chaine_recue[MAX_SIZE];
    // chaîne reçue du client

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

    while (1)
    {
        socket_service = accept(socket_ecoute,
                                (struct sockaddr *)&addr_client,
                                (socklen_t *)&lg_addr);
        fflush(stdout);
        if (socket_service == -1)
            exit(1);

        else if (fork() == 0)
        {
            close(socket_ecoute);
            char *ip_client = inet_ntoa(addr_client.sin_addr);

            // la connexion est établie, on attend les données envoyées par le client
            //fprintf(stderr, "Message recu: \t%s \nde la part de %s \nsur le port %d\n", chaine_recue, ip_client, ntohs(addr_client.sin_port));
            analysEtSend(chaine_recue, socket_service);

            exit(EXIT_SUCCESS);
        }
        else
            wait(NULL);
    }

    // on ferme les sockets
    close(socket_service);

    return 0;
}
