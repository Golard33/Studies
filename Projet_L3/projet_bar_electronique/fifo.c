#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fifo.h"

// Fonction pour créer une nouvelle file d'attente
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}


// Fonction pour vérifier si la file d'attente est vide
int isEmpty(Queue* q) {
    return q->front == NULL;
}

// Fonction pour ajouter un nouveau client à la file d'attente
void enqueue(Queue* q, int id) {
    Client* newClient = (Client*)malloc(sizeof(Client));
    newClient->id = id;
    newClient->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newClient;
        return;
    }

    q->rear->next = newClient;
    q->rear = newClient;
}

// Fonction pour retirer le client suivant de la file d'attente
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("La file d'attente est vide.\n");
        return -1;
    }

    Client* temp = q->front;
    int clientId = temp->id;
    q->front = temp->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return clientId;
}

// Fonction pour libérer la mémoire alloué aux queue
void freeQueue(Queue* q) {
    while (!isEmpty(q)) {
        dequeue(q);
    }
    free(q);
}