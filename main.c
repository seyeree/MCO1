#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "queue.h"
#include "infix-to-postfix.h"
#include "evaluate-postfix.h"

/**
 * Prints the respective operator based on the character code.
 * 
 * @param opCode The operator's character or its code number
 */
void printOperator(int opCode) {
    if (opCode == 201) printf(">= ");
    else if (opCode == 202) printf("<= ");
    else if (opCode == 203) printf("== ");
    else if (opCode == 204) printf("!= ");
    else if (opCode == 205) printf("&& ");
    else if (opCode == 206) printf("|| ");
    else printf("%c ", opCode);
}

/**
 * Input validation function to check invalid symbols before evaluation.
 * 
 * @param infix   The expression entered by the user
 * @return        1 if valid, 0 if invalid characters are included
 */
int isValidInfix(const char* infix) {
    if (infix == NULL || strlen(infix) == 0) return 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];
        
        if (isdigit(c)) continue;

        if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || 
            c == '^' || c == '(' || c == ')' || c == '<' || c == '>' || 
            c == '!' || c == '=' || c == '&' || c == '|') {
            continue;
        }
        
        return 0;
    }
    return 1;
}

int main() {
    char input[256];
    int keepRunning = 1;

    // Main loop
    while (keepRunning) {
        fflush(stdout);

        if (scanf("%255s", input) != 1) {
            keepRunning = 0; 
        } else {
            // Exit conditions
            if (strcmp(input, "QUIT") == 0) {
                keepRunning = 0;
            } else if(!isValidInfix(input)) {
                printf("Invalid Input: Expression contains unsupported characters.\n\n");
            } else {
                // Step 1: Conversion to postfix
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

                // Step 2: Print out token string of converted postfix
                while (!isQueueEmpty(&postfix)) {
                    Token t = dequeue(&postfix);
                    if (t.type == 0) {
                        printf("%d ", t.value);
                    } else {
                        printOperator(t.value);
                    }
                }
                printf("\n");
                
                // Step 3: Computation of numerical evaluation logic
                int divError;
                int result = evaluatePostfix(&evalQueue, &divError);
                
                if (divError == 1) {
                    printf("Division by zero error!\n");
                } else {
                    printf("%d\n", result);
                }
            }
        }
    }
    
    return 0;
}