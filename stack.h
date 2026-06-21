#ifndef STACK_H
#define STACK_H

#define MAX_SIZE 256

typedef struct {
    int items[MAX_SIZE]; 
    int top;
} Stack;

void initStack(Stack *s);
int isStackEmpty(Stack *s);
int isStackFull(Stack *s);
void push(Stack *s, int value);
int pop(Stack *s);
int peek(Stack *s);

#endif