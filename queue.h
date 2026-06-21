#ifndef QUEUE_H
#define QUEUE_H

#define MAX_SIZE 256

typedef struct {
    int type;  // 0 for operand, 1 for operator
    int value; 
} Token;

typedef struct {
    Token items[MAX_SIZE];
    int front;
    int rear;
    int size;
} Queue;

void initQueue(Queue *q);
int isQueueEmpty(Queue *q);
int isQueueFull(Queue *q);
void enqueue(Queue *q, Token t);
Token dequeue(Queue *q);

#endif