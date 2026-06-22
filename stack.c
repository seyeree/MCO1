#include "stack.h"

/**
 * Initializes the stack.
 * 
 * @param s  Pointer to the stack being set up
 */
void initStack(Stack *s) {
    s->top = -1;
}

/**
 * Checks if the stack is empty.
 * 
 * @param s  Pointer to the stack being checked
 */
int isStackEmpty(Stack *s) {
    int isEmpty = 0;
    if (s->top == -1) {
        isEmpty = 1;
    }
    return isEmpty;
}

/**
 * Checks if the stack reached the storage limit.
 * 
 * @param s  Pointer to the stack being checked
 */
int isStackFull(Stack *s) {
    int isFull = 0;
    if (s->top == MAX_SIZE - 1) {
        isFull = 1;
    }
    return isFull;
}

/**
 * Pushes a new operatir onto the top of the stack.
 * 
 * @param s       Pointer to the stack
 * @param value   The operator to be added to the stack
 */
void push(Stack *s, int value) {
    if (!isStackFull(s)) {
        s->top++;
        s->items[s->top] = value;
    }
}

/**
 * Removes and returns the top value from the stack.
 * 
 * @param s  Pointer to the stack
 * @return   The value from the top of the stack, or -999 if empty
 */
int pop(Stack *s) {
    int poppedValue = -999; 
    
    if (!isStackEmpty(s)) {
        poppedValue = s->items[s->top];
        s->top--;
    }
    
    return poppedValue;
}

/**
 * Checks and returns the top value from the stack without removing it.
 * 
 * @param s   Pointer to the stack
 * @return    The value from the top of the stack, or -999 if empty
 */
int peek(Stack *s) {
    int topValue = -999;
    
    if (!isStackEmpty(s)) {
        topValue = s->items[s->top];
    }
    
    return topValue;
}