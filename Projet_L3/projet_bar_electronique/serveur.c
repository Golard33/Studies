#include <netinet/in.h>
#include <pthread.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include "tcp.h"
#include<signal.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/select.h>
#include <sys/time.h>

#define TAILLEBUF 2048

#define QUESTION "/tmp/fifo_serv_main"
#define REPONSE "/tmp/fifo_main_serv"
#define NBCO 5

// Variable globale pour indiquer si le processus doit se terminer
volatile sig_atomic_t terminated = 0;

pthread_mutex_t client_id_mutex = PTHREAD_MUTEX_INITIALIZER; // Définit un mutex pour assurer l'accès exclusif à la variable client_id_counter
int client_id_counter = 0; // Initialise un compteur d'ID client à 0

int fifo_request_fd; // Définit le descripteur de fichier pour la file de requêtes
int fifo_response_fd; // Définit le descripteur de fichier pour la file de réponses

typedef struct {
    int client_id;
    int beer_type;
    int beer_size;
} beer_request_t; // Structure pour définir le format de la commande de bière

typedef struct pthread_arg_t {
    int new_socket_fd;
    char message[TAILLEBUF];
    struct sockaddr_in client_address;
    int fifo_request_fd;
    int fifo_response_fd;
} pthread_arg_t; // Structure pour stocker les arguments passés au thread

/* Routine de thread pour servir la connexion au client. */
void *pthread_routine(void *arg);

/* Gestionnaire de signal pour gérer les signaux SIGTERM et SIGINT. */
void signal_handler(int signum);

void handle_beer_order(pthread_arg_t *pthread_arg, int client_id, int choice); // Fonction pour traiter la commande de bière


int main(int argc, char *argv[]) {
    int port, socket_fd, new_socket_fd;
    struct sockaddr_in address;
    pthread_attr_t pthread_attr;
    pthread_arg_t *pthread_arg;
    pthread_t pthread;
    socklen_t client_address_len;

    /* Obtient le numéro de port à écouter à partir des arguments de ligne de commande ou de l'entrée standard. */
    port = argc > 1 ? atoi(argv[1]) : 0;
    if (!port) {
        printf("Enter Port: ");
        scanf("%d", &port);
    }

    /* Ouvre une socket serveur TCP sur ce port et écoute les connexions entrantes. */
    socket_fd = SocketServeurTCP(port);

    /* Met en écoute sur la socket. */
    if (listen(socket_fd, NBCO) == -1) {
        perror("listen, trop de clients");
        exit(1);
    }

    /* Ignore le signal SIGPIPE et définit un gestionnaire de signal pour SIGTERM et SIGINT. */
    if (signal(SIGPIPE, SIG_IGN) == SIG_ERR) {
        perror("signal");
        exit(1);
    }
    if (signal(SIGTERM, signal_handler) == SIG_ERR) {
        perror("signal");
        exit(1);
    }
    if (signal(SIGINT, signal_handler) == SIG_ERR) {
        perror("signal");
        exit(1);
    }

    /* Initialise l'attribut pthread pour créer des threads détachés. */    
    if (pthread_attr_init(&pthread_attr) != 0) {
        perror("pthread_attr_init");
        exit(1);
    }
    if (pthread_attr_setdetachstate(&pthread_attr, PTHREAD_CREATE_DETACHED) != 0) {
        perror("pthread_attr_setdetachstate");
        exit(1);
    }

    /* Ouvre les tubes nommés pour communiquer avec le processus enfant qui gère les commandes de bière. */
    int fifo_request_fd = open(QUESTION, O_WRONLY| O_SYNC);
    int fifo_response_fd = open(REPONSE, O_RDONLY| O_SYNC);

    if (fifo_request_fd == -1 || fifo_response_fd == -1) {
        perror("open");
        exit(1);
    }

    while (1) {
        /* Crée un argument pthread pour chaque connexion au client. */
        pthread_arg = (pthread_arg_t *)malloc(sizeof *pthread_arg);
        if (!pthread_arg) {
            perror("malloc");
            continue;
        }

        /* Accepte une connexion au client. */
        client_address_len = sizeof pthread_arg->client_address;
        new_socket_fd = accept(socket_fd, (struct sockaddr *)&pthread_arg->client_address, &client_address_len);
        if (new_socket_fd == -1) {
            perror("accept");
            free(pthread_arg);
            continue;
        }

        /* Initialise l'argument pthread. */
        pthread_arg->new_socket_fd = new_socket_fd;
        pthread_arg->fifo_request_fd = fifo_request_fd;
        pthread_arg->fifo_response_fd = fifo_response_fd;
        /* Crée un thread pour traiter la connexion au client. */
        if (pthread_create(&pthread, &pthread_attr, pthread_routine, (void *)pthread_arg) != 0) {
            perror("pthread_create");
            free(pthread_arg);
            continue;
        }
    }
    if (socket_fd != -1) {
        close(socket_fd);
    }    
    return 0;
}

void *pthread_routine(void *arg) {
    pthread_arg_t *pthread_arg = (pthread_arg_t *)arg;
    char message[TAILLEBUF];
    int new_socket_fd = pthread_arg->new_socket_fd, nb_octets;
    struct sockaddr_in client_address = pthread_arg->client_address;

      // Verrouille le mutex pour acceder a la variable client_id_counter
    pthread_mutex_lock(&client_id_mutex);

    // Attribution d'un ID de client et on incremente le compteur
    int client_id = client_id_counter++;

     // Deverrouille le mutex
    pthread_mutex_unlock(&client_id_mutex);

    while (1) {
        // Lecture de la commande envoyée par le client
        nb_octets = read(new_socket_fd, message, sizeof(message));
        if (nb_octets == -1) {
            perror("erreur de lecture sur la socket");
            return NULL;
        }

        // Conversion de la commande en entier
        int choice = atoi(message);
        char reponse[TAILLEBUF];

        switch (choice) {
            // Gestion de la commande de bière
            case 1: 
                handle_beer_order(pthread_arg, client_id, choice);
                break;
            // Gestion de la demande des noms de bières
            case 2:
            {
                // Demande des noms de bières au processus principal pour les deux types
                beer_request_t beer_request_fut;
                beer_request_fut.client_id = -1; // Utiliser -1 pour indiquer une demande uniquement pour les noms de bières
                beer_request_fut.beer_size = 0;
                beer_request_fut.beer_type = 0;
                
                write(pthread_arg->fifo_request_fd, &beer_request_fut, sizeof(beer_request_t));

                char response_fut[TAILLEBUF];
                read(pthread_arg->fifo_response_fd, response_fut, sizeof(response_fut));

                char* beer_name_fut = response_fut;

                if (beer_name_fut) {
                    snprintf(reponse, sizeof(reponse), "\n %s\n", beer_name_fut);
                    write(new_socket_fd, reponse, strlen(reponse) + 1);
                } else {
                    strcpy(reponse, "\nErreur lors de la récupération des noms de bieres.\n");
                    write(new_socket_fd, reponse, strlen(reponse) + 1);
                }
            }
            break;
            // Gestion de la demande des tailles de bières
            case 3:
                strcpy(reponse, "\nTailles disponibles : Demi (0.25L) ou Pinte (0.5L)\n");
                write(new_socket_fd, reponse, strlen(reponse)+1);
                break;
            // Gestion de la fin de connexion
            case 4:
                strcpy(reponse, "\nA bientot!\n");
                write(new_socket_fd, reponse, strlen(reponse)+1);
                close(new_socket_fd);
                free(pthread_arg);
                pthread_exit(NULL);
                break;
            // Gestion d'une commande invalide
            default:
                strcpy(reponse, "\nChoix invalide. Veuillez reessayer\n");
                write(new_socket_fd, reponse, strlen(reponse)+1);
                break;
        }
    }
}

// Fonction appelée lors de la réception du signal d'arrêt
void signal_handler(int signum) {
    terminated = 1;// Mettre la variable terminated à 1 pour indiquer la fin du programme
    close(fifo_request_fd);// Fermer le tube nommé pour les requêtes
    close(fifo_response_fd);// Fermer le tube nommé pour les réponses
    exit(0);// Quitter le programme
}

// Fonction pour gérer la commande de bière
void handle_beer_order(pthread_arg_t *pthread_arg, int client_id, int choice) {
    int new_socket_fd = pthread_arg->new_socket_fd;// Récupérer le descripteur de fichier du nouveau socket
    char message[TAILLEBUF];
    char reponse[TAILLEBUF];
    int beer_type, beer_size;
    beer_request_t *beer_request;
    beer_request = (beer_request_t *)malloc(sizeof *beer_request);

    memset(message, 0, sizeof(message)); // Remplir le buffer avec des 0 pour supprimer les caractères indésirables
    memset(reponse, 0, sizeof(reponse));

    // Demander le type de bière
    strcpy(reponse, "\n1. Blonde\n2. Ambree\n\nChoisissez le type de biere (1-2) : ");
    write(new_socket_fd, reponse, strlen(reponse));
    read(new_socket_fd, message, sizeof(message));
    beer_type = atoi(message);

    // Demander la taille de bière
    strcpy(reponse, "\n1. Demi (0.25L)\n2. Pinte (0.5L)\n\nChoisissez la taille (1-2) :");
    write(new_socket_fd, reponse, strlen(reponse));
    read(new_socket_fd, message, sizeof(message));
    beer_size = atoi(message);

    beer_request->client_id = client_id;
    beer_request->beer_type = beer_type;
    beer_request->beer_size = beer_size;

    // Envoyer le choix du client au programme principal via le tube de communication
    write(pthread_arg->fifo_request_fd, beer_request, sizeof(beer_request_t));
    printf("En attente de la préparation de la boisson...\n");

    // Recevoir la réponse "boisson préparée" depuis le programme principal
    char response[TAILLEBUF];
    if (read(pthread_arg->fifo_response_fd, response, sizeof(response)) > 0) {
        printf("Message recu du main: %s\n", response);
        snprintf(reponse, sizeof(reponse), "\nRésultat de la commande : %.997s", response);
        write(new_socket_fd, reponse, strlen(reponse));
    } else {
        strcpy(reponse, "Erreur lors de la préparation de la boisson.");
        write(new_socket_fd, reponse, strlen(reponse));
    }

    free(beer_request);// Libérer la mémoire allouée pour la requête de bière
}