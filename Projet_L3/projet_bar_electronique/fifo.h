#ifndef FIFO_H
#define FIFO_H

typedef struct Client {
    int id;
    struct Client* next;
} Client;

typedef struct Queue {
    Client* front;
    Client* rear;
} Queue;

Queue* createQueue();
int isEmpty(Queue* q);
void enqueue(Queue* q, int id);
int dequeue(Queue* q);
void freeQueue(Queue* q);

#endif // FIFO_H

