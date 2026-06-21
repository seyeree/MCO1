#include <stdio.h>
#include <string.h>
#include "queue.h"
#include "infix-to-postfix.h"
#include "evaluate-postfix.h"

void printOperator(int opCode) {
    if (opCode == 201) printf(">= ");
    else if (opCode == 202) printf("<= ");
    else if (opCode == 203) printf("== ");
    else if (opCode == 204) printf("!= ");
    else if (opCode == 205) printf("&& ");
    else if (opCode == 206) printf("|| ");
    else printf("%c ", opCode);
}

int main() {
    char input[256];
    int keepRunning = 1;
    
    while (keepRunning) {
        if (scanf("%255s", input) != 1) {
            keepRunning = 0; 
        } else {
            if (strcmp(input, "QUIT") == 0) {
                keepRunning = 0;
            } else {
                Queue postfix = infixToPostfix(input);
                
                Queue evalQueue;
                evalQueue.front = postfix.front;
                evalQueue.rear = postfix.rear;
                evalQueue.size = postfix.size;
                
                int i = 0;
                while (i <= postfix.rear) {
                    evalQueue.items[i] = postfix.items[i];
                    i++;
                }

                while (!isQueueEmpty(&postfix)) {
                    Token t = dequeue(&postfix);
                    if (t.type == 0) {
                        printf("%d ", t.value);
                    } else {
                        printOperator(t.value);
                    }
                }
                printf("\n");
                
                int divError;
                int result = evaluatePostfix(&evalQueue, &divError);
                
                if (divError == 1) {
                    printf("Division by zero error!\n\n");
                } else {
                    printf("%d\n\n", result);
                }
            }
        }
    }
    
    return 0;
}