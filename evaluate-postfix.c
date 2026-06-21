#include <stdio.h>
#include <math.h>
#include "stack.h"
#include "queue.h"
#include "evaluate-postfix.h"

int evaluatePostfix(Queue* postQueue, int* divByZeroError) {
    Stack evalStack;
    initStack(&evalStack);
    *divByZeroError = 0;
    int finalResult = 0;
    
    while (!isQueueEmpty(postQueue)) {
        Token t = dequeue(postQueue);
        
        if (t.type == 0) { 
            push(&evalStack, t.value);
        } else { 
            int val2, val1, res = 0;
            
            if (t.value == '!') {
                val1 = pop(&evalStack);
                res = !val1;
            } else {
                val2 = pop(&evalStack);
                val1 = pop(&evalStack);
                
                if (t.value == '+') res = val1 + val2;
                else if (t.value == '-') res = val1 - val2;
                else if (t.value == '*') res = val1 * val2;
                else if (t.value == '%') res = val1 % val2;
                else if (t.value == '^') res = (int)pow(val1, val2);
                else if (t.value == '>') res = val1 > val2;
                else if (t.value == '<') res = val1 < val2;
                else if (t.value == 201) res = val1 >= val2; 
                else if (t.value == 202) res = val1 <= val2; 
                else if (t.value == 203) res = val1 == val2; 
                else if (t.value == 204) res = val1 != val2; 
                else if (t.value == 205) res = val1 && val2; 
                else if (t.value == 206) res = val1 || val2; 
                else if (t.value == '/') {
                    if (val2 == 0) {
                        *divByZeroError = 1;
                    } else {
                        res = val1 / val2;
                    }
                }
            }
            push(&evalStack, res);
        }
    }
    
    if (!isStackEmpty(&evalStack)) {
        finalResult = pop(&evalStack);
    }
    
    return finalResult;
}