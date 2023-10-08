#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <netinet/in.h>

int shm_id;
int *current_process;

// Gestionnaire pour le signal d'alarme
void alarm_handler(int sig) {
    *current_process = (*current_process + 1) % 3;
    alarm(1);
}

int main(int argc, char *argv[]) {
    // Vérification des arguments
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <port> <ip> <udp_port>\n", argv[0]);
        exit(1);
    }

    int port = atoi(argv[1]);
    char *ip_address = argv[2];
    int udp_port = atoi(argv[3]);

    pid_t main_pid, server_pid, control_pid;
    pid_t pids[3];

    // Création d'un segment de mémoire partagée
    shm_id = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666);
    if (shm_id == -1) {
        perror("shmget");
        exit(1);
    }

    // Attachement du segment de mémoire partagée
    current_process = (int *)shmat(shm_id, NULL, 0);
    if (current_process == (int *)-1) {
        perror("shmat");
        exit(1);
    }

    *current_process = 0;

    // Création du processus principal
    main_pid = fork();
    if (main_pid == 0) {
        // Attachement du segment de mémoire partagée dans le processus enfant
        current_process = (int *)shmat(shm_id, NULL, 0);
        if (current_process == (int *)-1) {
            perror("shmat");
            exit(1);
        }

        while (1) {
            if (*current_process == 0) {
                printf("Starting Main process...\n");
                execl("./main.out", "main.out", (char *)NULL);
            }
            usleep(1000);
        }
    }

    // Création du processus serveur
    server_pid = fork();
    if (server_pid == 0) {
        // Attachement du segment de mémoire partagée dans le processus enfant
        current_process = (int *)shmat(shm_id, NULL, 0);
        if (current_process == (int *)-1) {
            perror("shmat");
            exit(1);
        }

        while (1) {
            if (*current_process == 1) {
                printf("Starting Server process...\n");
                char port_str[6];
                snprintf(port_str, sizeof(port_str), "%d", port);
                execl("./serveur.out", "serveur.out", port_str, (char *)NULL);
            }
            usleep(1000);
        }
    }

    // Création du processus de contrôle
    control_pid = fork();
    if (control_pid == 0) {
        // Attachement du segment de mémoire partagée dans le processus enfant
        current_process = (int *)shmat(shm_id, NULL, 0);
        if (current_process == (int *)-1) {
            perror("shmat");
            exit(1);
        }

        while (1) {
            if (*current_process == 2) {
                printf("Starting Control process...\n");
                char udp_port_str[6];
                snprintf(udp_port_str, sizeof(udp_port_str), "%d", udp_port);
                execl("./controle.out", "controle.out", ip_address, udp_port_str, (char *)NULL);
            }
            usleep(1000);
        }
    }

    pids[0] = main_pid;
    pids[1] = server_pid;
    pids[2] = control_pid;

    // Configuration du gestionnaire de signal pour l'alarme
    signal(SIGALRM, alarm_handler);
    alarm(1);

    int status;
    // Attente de la fin des processus enfants
    for (int i = 0; i < 3; i++) {
        waitpid(pids[i], &status, 0);
    }

    // Détachement du segment de mémoire partagée    
    shmdt(current_process);

    // Suppression du segment de mémoire partagée
    shmctl(shm_id, IPC_RMID, NULL);

    return 0;
}

