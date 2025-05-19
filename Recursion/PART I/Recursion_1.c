#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "Recursion_1.h"

#define MAX 500

typedef enum { INFO = 0, WARNING = 1, ERROR = 2, CRITICAL = 3 } Severity;

void reverseListRecursive(Node** head, Node** tail, Node* current) {
    if (current == NULL) return;

    
    Node* temp = current->next;
    current->next = current->prev;
    current->prev = temp;

    
    if (temp == NULL) {
        
        *tail = *head;
        *head = current;
        return;
    }

    reverseListRecursive(head, tail, temp);
}
int factorial(int n) {
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}

int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int findMaxIDRecursive(Node* head, Node* current, int maxID) {
    if (current == head) return maxID;
    if (current->id > maxID) maxID = current->id;
    return findMaxIDRecursive(head, current->next, maxID);
}

int binarySearchLogs(Node logs[], int low, int high, int targetID) {
    if (low > high) return -1;
    
    int mid = (low + high) / 2;
    if (logs[mid].id == targetID) return mid;
    if (logs[mid].id > targetID) return binarySearchLogs(logs, low, mid - 1, targetID);
    return binarySearchLogs(logs, mid + 1, high, targetID);
}

void infixToPostfixRecursive(char* infix, int index, char* postfix, int* postIndex) {
    if (infix[index] == '\0') {
        postfix[*postIndex] = '\0'; //*base case or in other term stoping condition
        return;
    }

    if (infix[index] >= 'A' && infix[index] <= 'Z') { //* get chars only
        postfix[*postIndex] = infix[index];
        (*postIndex)++;
        infixToPostfixRecursive(infix, index + 1, postfix, postIndex);
    } 
    else {
        infixToPostfixRecursive(infix, index + 1, postfix, postIndex);
        postfix[*postIndex] = infix[index];
        (*postIndex)++;
    }
}