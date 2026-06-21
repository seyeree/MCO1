#include <stdio.h>
#include <ctype.h>
#include "stack.h"
#include "queue.h"
#include "infix-to-postfix.h"

int getPrecedence(int opCode) {
    int precedence = 0;
    if (opCode == '!') precedence = 8;
    else if (opCode == '^') precedence = 7;
    else if (opCode == '*' || opCode == '/' || opCode == '%') precedence = 6;
    else if (opCode == '+' || opCode == '-') precedence = 5;
    else if (opCode == '>' || opCode == '<' || opCode == 201 || opCode == 202) precedence = 4; 
    else if (opCode == 203 || opCode == 204) precedence = 3; 
    else if (opCode == 205) precedence = 2; 
    else if (opCode == 206) precedence = 1; 
    return precedence;
}

Queue infixToPostfix(char* infix) {
    Stack opStack;
    Queue postQueue;
    initStack(&opStack);
    initQueue(&postQueue);
    
    int i = 0;
    while (infix[i] != '\0') {
        if (isdigit(infix[i])) {
            int num = 0;
            while (isdigit(infix[i])) {
                num = (num * 10) + (infix[i] - '0');
                i++;
            }
            Token t;
            t.type = 0; 
            t.value = num;
            enqueue(&postQueue, t);
            continue; 
        } 
        else if (infix[i] == '(') {
            push(&opStack, '(');
        } 
        else if (infix[i] == ')') {
            int popped = pop(&opStack);
            while (popped != '(' && popped != -999) {
                Token t;
                t.type = 1; 
                t.value = popped;
                enqueue(&postQueue, t);
                popped = pop(&opStack);
            }
        } 
        else {
            int opCode = infix[i];
            
            // Handle multi-character logical and relational operators
            if ((infix[i] == '>' && infix[i+1] == '=') || 
                (infix[i] == '<' && infix[i+1] == '=') || 
                (infix[i] == '=' && infix[i+1] == '=') || 
                (infix[i] == '!' && infix[i+1] == '=') ||
                (infix[i] == '&' && infix[i+1] == '&') ||
                (infix[i] == '|' && infix[i+1] == '|')) {
                
                if (infix[i] == '>') opCode = 201; // >=
                else if (infix[i] == '<') opCode = 202; // <=
                else if (infix[i] == '=') opCode = 203; // ==
                else if (infix[i] == '!') opCode = 204; // !=
                else if (infix[i] == '&') opCode = 205; // &&
                else if (infix[i] == '|') opCode = 206; // ||
                i++; 
            }

            while (!isStackEmpty(&opStack) && peek(&opStack) != '(' && 
                   getPrecedence(peek(&opStack)) >= getPrecedence(opCode)) {
                Token t;
                t.type = 1;
                t.value = pop(&opStack);
                enqueue(&postQueue, t);
            }
            push(&opStack, opCode);
        }
        i++;
    }
    
    while (!isStackEmpty(&opStack)) {
        Token t;
        t.type = 1;
        t.value = pop(&opStack);
        enqueue(&postQueue, t);
    }
    
    return postQueue;
}