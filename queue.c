#include "queue.h"

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

int isQueueEmpty(Queue *q) {
    int isEmpty = 0;
    if (q->size == 0) {
        isEmpty = 1;
    }
    return isEmpty;
}

int isQueueFull(Queue *q) {
    int isFull = 0;
    if (q->size == MAX_SIZE) {
        isFull = 1;
    }
    return isFull;
}

void enqueue(Queue *q, Token t) {
    if (!isQueueFull(q)) {
        q->rear++;
        q->items[q->rear] = t;
        q->size++;
    }
}

Token dequeue(Queue *q) {
    Token dequeuedToken;
    dequeuedToken.type = -1;  
    dequeuedToken.value = -1; 
    
    if (!isQueueEmpty(q)) {
        dequeuedToken = q->items[q->front];
        q->front++;
        q->size--;
    }
    
    return dequeuedToken;
}