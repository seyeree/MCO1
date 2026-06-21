#include "stack.h"

void initStack(Stack *s) {
    s->top = -1;
}

int isStackEmpty(Stack *s) {
    int isEmpty = 0;
    if (s->top == -1) {
        isEmpty = 1;
    }
    return isEmpty;
}

int isStackFull(Stack *s) {
    int isFull = 0;
    if (s->top == MAX_SIZE - 1) {
        isFull = 1;
    }
    return isFull;
}

void push(Stack *s, int value) {
    if (!isStackFull(s)) {
        s->top++;
        s->items[s->top] = value;
    }
}

int pop(Stack *s) {
    int poppedValue = -999; 
    
    if (!isStackEmpty(s)) {
        poppedValue = s->items[s->top];
        s->top--;
    }
    
    return poppedValue;
}

int peek(Stack *s) {
    int topValue = -999;
    
    if (!isStackEmpty(s)) {
        topValue = s->items[s->top];
    }
    
    return topValue;
}