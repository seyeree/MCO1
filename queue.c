#include "queue.h"

/**
 * Initializes the queue.
 * 
 * @param q  Pointer to the queue being set up
 */
void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

/**
 * Checks if queue is empty.
 * 
 * @param q   Pointer to the queue being checked
 * @return    1 if queue has no operational items, 0 if it contains items
 */
int isQueueEmpty(Queue *q) {
    int isEmpty = 0;
    if (q->size == 0) {
        isEmpty = 1;
    }
    return isEmpty;
}

/**
 * Checks if the queue reached the storage limit.
 * 
 * @param q   Pointer to the queue being checked
 * @return    1 if queue is full, 0 if it still has space
 */
int isQueueFull(Queue *q) {
    int isFull = 0;
    if (q->size == MAX_SIZE) {
        isFull = 1;
    }
    return isFull;
}

/**
 * Adds a new token to the back of the queue.
 * 
 * @param q   Pointer to the queue
 * @param t   Token to be added
 */
void enqueue(Queue *q, Token t) {
    if (!isQueueFull(q)) {
        q->rear++;
        q->items[q->rear] = t;
        q->size++;
    }
}

/**
 * Removes and returns the token from the front of the queue.
 * 
 * @param q   Pointer to the queue
 * @return    The token from the front of the queue, or invalid if empty
 */
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