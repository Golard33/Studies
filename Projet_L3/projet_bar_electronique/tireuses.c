#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>
#include "tireuses.h"

#define BEER_BLONDE 1
#define BEER_AMBREE 2


#define SHM_KEY 1234
#define SEM_KEY 5678

// Structure représentant une tireuse à bière
tap_t *shm_taps; // Pointeur vers le tableau de tireuses dans la mémoire partagée

int sem_id; // ID du sémaphore

// Verrouille le sémaphore
void lock_semaphore() {
    struct sembuf op;
    op.sem_num = 0;
    op.sem_op = -1;
    op.sem_flg = 0;
    semop(sem_id, &op, 1);
}

// Déverrouille le sémaphore
void unlock_semaphore() {
    struct sembuf op;
    op.sem_num = 0;
    op.sem_op = 1;
    op.sem_flg = 0;
    semop(sem_id, &op, 1);
}

// Initialise la mémoire partagée
void setup_shared_memory() {
    int shm_id = shmget(SHM_KEY, 2 * sizeof(tap_t), IPC_CREAT | 0666);
    if (shm_id == -1) {
        perror("shmget");
        exit(1);
    }

    shm_taps = (tap_t *)shmat(shm_id, NULL, 0);
    if (shm_taps == (tap_t *)-1) {
        perror("shmat");
        exit(1);
    }
}

// Initialise le sémaphore
void setup_semaphore() {
    sem_id = semget(SEM_KEY, 1, IPC_CREAT | 0666);
    if (sem_id == -1) {
        perror("semget");
        exit(1);
    }

    if (semctl(sem_id, 0, SETVAL, 1) == -1) {
        perror("semctl");
        exit(1);
    }
}

// Initialise les tireuses à bière
void initialize_taps() {
    lock_semaphore(); // Verrouille le sémaphore

    // Initialise la première tireuse (bière blonde)
    strcpy(shm_taps[BEER_BLONDE - 1].beer_name, "Paix Dieu"); // changer nom du fut
    shm_taps[BEER_BLONDE - 1].beer_type = BEER_BLONDE;
    shm_taps[BEER_BLONDE - 1].beer_quantity = 5000; //ml

    // Initialise la deuxième tireuse (bière ambrée)
    strcpy(shm_taps[BEER_AMBREE - 1].beer_name, "Kwak");
    shm_taps[BEER_AMBREE - 1].beer_type = BEER_AMBREE;
    shm_taps[BEER_AMBREE - 1].beer_quantity = 5000; //ml

    unlock_semaphore(); // Déverrouille le sémaphore
}

// Sert de la bière d'une tireuse et met à jour la quantité restante
int serve_beer(int beer_type, int beer_size) {
    int served_quantity = 0; // Quantité de bière servie (en ml)

    lock_semaphore(); // Verrouille le sémaphore


    if (shm_taps[beer_type].beer_quantity >= beer_size) { // Met à jour la quantité de bière restante dans le fût
        shm_taps[beer_type].beer_quantity -= beer_size;
        served_quantity = beer_size; // Actualise la quantité servie
    }

    unlock_semaphore(); // Déverrouille le sémaphore

    return served_quantity; // Retourne la quantité de bière servie
}

const char* get_beer_name(int beer_type) {
    if (beer_type == BEER_BLONDE || beer_type == BEER_AMBREE) {
        return shm_taps[beer_type - 1].beer_name;
    } else {
        return NULL;
    }
}
