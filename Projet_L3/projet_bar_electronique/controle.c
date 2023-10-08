#include <arpa/inet.h>
#include <signal.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include "tireuses.h"

#define BEER_BLONDE 1
#define BEER_AMBREE 2

tap_t *shm_taps;
int blonde_empty_sent = 0;
int ambree_empty_sent = 0;
int *in_command;
int sem_id;

// Mettre à jour le fut en fonction des informations reçues
void update_keg(int keg, int quantity, const char* beer_name) {
lock_semaphore();
shm_taps[keg - 1].beer_quantity = quantity;
strncpy(shm_taps[keg - 1].beer_name, beer_name, sizeof(shm_taps[keg - 1].beer_name) - 1);
shm_taps[keg - 1].beer_name[sizeof(shm_taps[keg - 1].beer_name) - 1] = '\0';
unlock_semaphore();
}

// Traiter les messages reçus du serveur
void handle_received_message(const char* buffer) {
int keg, quantity;
char beer_name[64];
if (sscanf(buffer, "Keg purchased: %d, quantity: %d, beer: %63[^\n]", &keg, &quantity, beer_name) == 3) {
    update_keg(keg, quantity, beer_name);
    }
}

// Vérifier l'état des tireuses et envoyer un message si une tireuse est vide
void check_tap_status(int sockfd, struct sockaddr_in server_addr, int *in_command) {

    while (1) {
        int empty_tap = 0;
        if (!*in_command) {
            if (shm_taps[BEER_BLONDE - 1].beer_quantity == 0) {
                if (!blonde_empty_sent) {
                    printf("Beer Blonde is empty\n");
                    empty_tap = BEER_BLONDE;
                    blonde_empty_sent = 1;
                }
            } else {
                blonde_empty_sent = 0;
            }
            if (shm_taps[BEER_AMBREE - 1].beer_quantity == 0) {
                if (!ambree_empty_sent) {
                    printf("Beer Ambrée is empty\n");
                    empty_tap = BEER_AMBREE;
                    ambree_empty_sent = 1;
                }
            } else {
                ambree_empty_sent = 0;
            }

            if (empty_tap) {
                char message[32];
                sprintf(message, "Empty tap: %d", empty_tap);
                int n = sendto(sockfd, message, strlen(message), 0, (const struct sockaddr *)&server_addr, sizeof(server_addr));
                if (n < 0) {
                    perror("sendto");
                    exit(EXIT_FAILURE);
                }
                *in_command = 1;
            }
        }
        sleep(2);
    }
}
void release_shared_memory() {
    if (shmdt(shm_taps) == -1) {
        perror("shmdt");
        exit(EXIT_FAILURE);
    }
}
void release_semaphore() {
    if (semctl(sem_id, 0, IPC_RMID) == -1) {
        perror("semctl");
        exit(EXIT_FAILURE);
    }
}
void handle_signal(int signum) {
    release_shared_memory();
    release_semaphore();
    exit(EXIT_SUCCESS);
}



int main(int argc, char *argv[]) {
    setup_shared_memory();
    setup_semaphore();
    initialize_taps();
    signal(SIGINT, handle_signal);
    signal(SIGTERM, handle_signal);

    int shm_id_in_command = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666);
    if (shm_id_in_command == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }
    in_command = (int *)shmat(shm_id_in_command, NULL, 0);
    if (in_command == (int*)-1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <IP address> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Création de la socket UDP
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr, client_addr;
    char buffer[1024];
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(argv[2]));

    // Création d'un processus fils pour gérer l'état des tireuses
    pid_t pid = fork();
    if (pid == 0) {
        check_tap_status(sockfd, server_addr, in_command);
    } else if (pid > 0) {
        while (1) {
            int len, n;
            len = sizeof(client_addr);
            // Recevoir les messages du client
            n = recvfrom(sockfd, (char *)buffer, 1024, MSG_WAITALL, (struct sockaddr *)&client_addr, &len);
            if (n < 0) {
                perror("recvfrom failed");
                exit(EXIT_FAILURE);
            }
            buffer[n] = '\0';
            printf("Client : %s\n", buffer);
            // Traiter les messages reçus
            handle_received_message(buffer);

            // Indiquer que le traitement est terminé
            *in_command = 0;
        }
    } else {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }

    return 0;
}