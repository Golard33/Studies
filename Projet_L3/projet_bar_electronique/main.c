#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>
#include "fifo.h"
#include "tireuses.h"

// Structure pour représenter une demande de bière
typedef struct {
    int client_id;// L'identifiant du client qui fait la demande
    int beer_type;// Le type de bière demandé
    int beer_size;// La taille de la bière demandée
} beer_request_t;

// Constantes pour les types de bière
#define BEER_BLONDE 1
#define BEER_AMBREE 2

// Constantes pour les tailles de bière
#define BEER_SIZE_DEMI 1
#define BEER_SIZE_PINTE 2

// Chemins des fichiers de FIFO pour la communication entre les processus
#define QUESTION "/tmp/fifo_serv_main"
#define REPONSE "/tmp/fifo_main_serv"

// Variable globale pour indiquer si le processus doit se terminer
volatile sig_atomic_t terminated = 0;

// Fonction pour gérer les signaux et indiquer au processus de se terminer
void signal_handler(int signum) {
    terminated = 1;
}

void server_process(int fdq, int fdr, Queue* scheduler);

// Fonction pour gérer la demande d'une bière et la préparer
bool prepare_drink(int beer_type, int beer_size) {
    printf("Preparing the drink...\n");

    int beer_ml = 0;

    // Vérifier le type de bière et la taille demandés et affecter la quantité de bière à servir
    if (beer_type == BEER_BLONDE || beer_type == BEER_AMBREE) {
        if (beer_size == BEER_SIZE_DEMI) {
            beer_ml = 250;
        } else if (beer_size == BEER_SIZE_PINTE) {
            beer_ml = 500; // temporaire, vider completement la tireuse
        }
    }

    // Si la quantité de bière à servir est supérieure à 0
    if (beer_ml > 0) {
        int served_quantity = serve_beer(beer_type - 1, beer_ml);// Servir la quantité de bière demandée
        if (served_quantity > 0) {
            printf("Served %d mL of beer type %d.\n", served_quantity, beer_type);
            sleep(beer_ml == 250 ? 2 : 4);// Temps de sommeil pour simuler la préparation de la boisson
            return true;
        } else {
            printf("Not enough beer of type %d left in the tap.\n", beer_type);
        }
    } else {
        printf("Invalid combination of beer type and size.\n");
    }

    return false;
}

int main(int argc, char *argv[]) {
    setup_shared_memory();
    setup_semaphore();
    initialize_taps();

    signal(SIGINT, signal_handler);
    signal(SIGTERM, signal_handler);
    int fdq, fdr;
    unlink(QUESTION);
    unlink(REPONSE);

    // Création des fifos
    if (mkfifo(QUESTION, 0666) == -1 || mkfifo(REPONSE, 0666) == -1) {
        perror("Impossible creer fifos");
        exit(1);
    }

        // Processus parent - gère les demandes de boissons

        // Attendre que le serveur ouvre les tubes de communication
        fdq = open(QUESTION, O_RDONLY | O_SYNC);
        fdr = open(REPONSE, O_WRONLY| O_SYNC);

        // Initialise l'ordonnanceur FIFO
        Queue* queue = createQueue();

        // Traiter les requêtes du serveur
        server_process(fdq, fdr, queue);

        // Fermer et supprimer les tubes nommés
        close(fdq);
        close(fdr);
        unlink(QUESTION);
        unlink(REPONSE);

        //libere la memoire alloué des queue
        freeQueue(queue);
        return 0;
}

void server_process(int fdq, int fdr, Queue* scheduler) {
    while (!terminated) {
        beer_request_t beer_request;

        if (read(fdq, &beer_request, sizeof(beer_request)) > 0) {
            printf("Reçu: client_id=%d, beer_type=%d, beer_size=%d\n", beer_request.client_id, beer_request.beer_type, beer_request.beer_size);
            
            // Si client_id vaut -1, retourner le nom des bières contenues dans les 2 fûts
            if (beer_request.client_id == -1) {
                const char* beer_name1 = get_beer_name(BEER_BLONDE);
                const char* beer_name2 = get_beer_name(BEER_AMBREE);
                char response[256];
                snprintf(response, sizeof(response), "Les bières dans les fûts sont: %s et %s\n", beer_name1, beer_name2);
                write(fdr, response, sizeof(response));
            }
            // Si client_id est différent de -1, exécuter le reste du code
            else {
                enqueue(scheduler, beer_request.client_id);

                while (!isEmpty(scheduler) && !terminated) {
                    int next_client = dequeue(scheduler);
                    if (next_client != -1) {
                        bool drink_prepared = prepare_drink(beer_request.beer_type, beer_request.beer_size);
                        char response[256];
                        if (drink_prepared) {
                            snprintf(response, sizeof(response), "boisson préparée, beer_type : %d et beer_size : %d !\n",beer_request.beer_type,beer_request.beer_size  );
                        } else {
                            snprintf(response, sizeof(response), "boisson indisponible\n");
                        }
                        write(fdr, response, sizeof(response));
                    } else {
                        terminated = 1;
                    }
                }

                sleep(1); // Attends 1 seconde avant de vérifier à nouveau les demandes
            }
        }
    }
}
