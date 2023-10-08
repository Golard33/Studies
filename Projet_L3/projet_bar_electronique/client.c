#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include "tcp.h"
#define TAILLEBUF 2048
#define SERVER_NAME_LEN_MAX 255

volatile sig_atomic_t client_terminated = 0;
int socket_fd;

void signal_handler(int signum);
void error_exit(const char *msg);
int read_integer(const char *prompt, int min, int max);

void print_menu() {
    printf("\nMenu:\n");
    printf("1. Commander une biere\n");
    printf("2. Informations sur les types de bieres qui existent\n");
    printf("3. Demander la taille de la biere possible\n");
    printf("4. Quitter\n");
}

void handle_client_beer_order(int socket_fd);

int main(int argc, char *argv[]) {
    char server_name[SERVER_NAME_LEN_MAX + 1] = { 0 };
    int server_port, socket_fd, nb_octets;
    struct hostent *server_host;
    struct sockaddr_in server_address;
    char message[TAILLEBUF];
    ssize_t bytes_written, bytes_read;
    int scanf_result;
   // Gérer les signaux SIGINT et SIGTERM
    if (signal(SIGINT, signal_handler) == SIG_ERR || signal(SIGTERM, signal_handler) == SIG_ERR) {
        perror("signal");
        exit(1);
    }

/* Obtenir le nom du serveur à partir des arguments de la ligne de commande ou de l'entrée standard. */    
    if (argc > 1) {
        strncpy(server_name, argv[1], SERVER_NAME_LEN_MAX); 
    } else {
        printf("Enter Server Name: ");
        scanf("%s", server_name);
    }

    /* Obtenir le port du serveur à partir des arguments de la ligne de commande ou de l'entrée standard. */    
    server_port = argc > 2 ? atoi(argv[2]) : 0;
    if (!server_port) {
        printf("Enter Port: ");
        scanf("%d", &server_port);
    }

    /* Obtenir l'hôte du serveur à partir du nom du serveur. */
    server_host = gethostbyname(server_name);
      if (server_host == NULL) {
        perror("Echec lors de la recuperation de l'hote serveur");
        exit(1);
    }

    /* Initialisez l'adresse du serveur IPv4 avec l'hôte du serveur. */
    memset(&server_address, 0, sizeof server_address);
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(server_port);
    memcpy(&server_address.sin_addr.s_addr, server_host->h_addr, server_host->h_length);

    /* Créer une socket TCP. */
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Echec lors de la creation de la socket TCP");
        exit(1);
    }

    /* Connecter la socket avec l'adresse du serveur. */
    if (connect(socket_fd, (struct sockaddr *)&server_address, sizeof server_address) == -1) {
		perror("erreur connexion serveur");
        close(socket_fd);
        exit(1);
	}
        printf("Connexion etablie avec succes\n");
        print_menu();
        int choice = 0;
        int received_beer_response = 0;
        while (choice!= 4) {

            if (!received_beer_response) {
               choice = read_integer("\n Choisissez une option du menu ou une option pour commander une biere: ", 1, 4);
            }

            sprintf(message, "%d", choice);
            bytes_written = write(socket_fd, message, strlen(message) + 1);
            if (bytes_written == -1) {
                error_exit("Erreur lors de l'écriture sur la socket");
            }

            switch (choice) {
                case 1:
                    handle_client_beer_order(socket_fd);
                    received_beer_response = 1;
                    break;
                case 2:
                    memset(message, 0, sizeof(message)); // Ajoutez cette ligne pour mettre à zéro le tableau message
                    bytes_read = read(socket_fd, message, sizeof(message));
                    if (bytes_read == -1) {
                        error_exit("Erreur lors de la lecture de la socket");
                    }
                    printf("%s", message);
                    print_menu();
                    break;
                case 3:
                    memset(message, 0, sizeof(message)); // Ajoutez cette ligne pour mettre à zéro le tableau message
                    bytes_read = read(socket_fd, message, sizeof(message));
                    if (bytes_read == -1) {
                        error_exit("Erreur lors de la lecture de la socket");
                    }
                    printf("%s", message);
                    print_menu();
                    break;
                case 4:
                    memset(message, 0, sizeof(message)); // Ajoutez cette ligne pour mettre à zéro le tableau message
                     bytes_read = read(socket_fd, message, sizeof(message));
                    if (bytes_read == -1) {
                        error_exit("Erreur lors de la lecture de la socket");
                    }
                    printf("%s", message);
                    break;
                default:
                    printf("\nChoix invalide. Veuillez réessayer.\n");
                    break;
            }
            if (received_beer_response) {
                memset(message, 0, sizeof(message));
                bytes_read = read(socket_fd, message, sizeof(message));
                if (bytes_read == -1) {
                    error_exit("Erreur lors de la lecture de la socket");
                }
                printf("%s", message);
                received_beer_response = 0;
                print_menu();
            }
        }
    close(socket_fd);
    return 0;
}

void signal_handler(int signum) {
    client_terminated = 1;
    close(socket_fd);
    exit(0);
}

void error_exit(const char *msg) {
    perror(msg);
    close(socket_fd);
    exit(1);
}


void handle_client_beer_order(int socket_fd) {
    int beer_type, beer_size;
    char reponse[TAILLEBUF];
    char message[TAILLEBUF];
    int choix_valide;
    ssize_t bytes_written, bytes_read;
    int scanf_result;

    memset(message, 0, sizeof(message)); //permet de supprimer les caracteres indesirables
    memset(reponse, 0, sizeof(reponse));

    // Lire le type de bière du serveur et sélectionner le type de bière    
    bytes_read = read(socket_fd, message, sizeof(message));
    if (bytes_read == -1) {
        error_exit("Erreur lors de la lecture de la socket");
    }
    printf("%s", message);
    choix_valide = 0;
    do {
        scanf_result = scanf("%d", &beer_type);
        if (scanf_result == EOF) {
            error_exit("Erreur lors de la lecture de l'entrée");
        }
        getchar(); // Consommer le retour à la ligne
        if (beer_type != 1 && beer_type != 2) {
            if (!choix_valide) {
                printf("Choix invalide. Veuillez choisir 1 ou 2: ");
                choix_valide = 1;
            }
        } else {
            choix_valide = 0;
        }
    } while (beer_type != 1 && beer_type != 2 || choix_valide);

    // Envoyer le type de bière au serveur
    sprintf(message, "%d", beer_type);
    bytes_written = write(socket_fd, message, strlen(message) + 1);
    if (bytes_written == -1) {
        error_exit("Erreur lors de l'écriture sur la socket");
    }

    // Lire la taille de la bière du serveur et sélectionner la taille de la bière
    bytes_read = read(socket_fd, message, sizeof(message));
    if (bytes_read == -1) {
        error_exit("Erreur lors de la lecture de la socket");
    }
    printf("%s", message);
    choix_valide = 0;
    do {
        scanf_result = scanf("%d", &beer_size);
        if (scanf_result == EOF) {
            error_exit("Erreur lors de la lecture de l'entrée");
        }
        getchar(); // Consommer le retour à la ligne
        if (beer_size != 1 && beer_size != 2) {
            if (!choix_valide) {
                printf("Choix invalide. Veuillez choisir 1 ou 2: ");
                choix_valide = 1;
            }
        } else {
            choix_valide = 0;
        }
    } while (beer_size != 1 && beer_size != 2 || choix_valide);

    // Envoyer la taille de la bière au serveur
    sprintf(message, "%d", beer_size);
    bytes_written = write(socket_fd, message, strlen(message) + 1);
    if (bytes_written == -1) {
        error_exit("Erreur lors de l'écriture sur la socket");
    }
}

int read_integer(const char *prompt, int min, int max) {
    int number;
    int result;
    char c;

    while (1) {
        printf("%s", prompt);
        result = scanf("%d", &number);

        // Consommer le retour à la ligne et les autres caractères indésirables
        while ((c = getchar()) != '\n' && c != EOF) {}

        if (result == 1 && number >= min && number <= max) {
            return number;
        } else {
            printf("\nSaisie invalide. Veuillez entrer un nombre entier entre %d et %d.\n\n", min, max);
        }
    }
}

