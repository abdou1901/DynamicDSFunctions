#ifndef RECURSION_PART1_H
#define RECURSION_PART1_H

#include <stdio.h>
#include <stdbool.h>

#define MAX 500

typedef struct Node {
    int id;
    char timestamp[20];
    char LOG[10];
    char message[MAX];
    struct Node* next;
    struct Node* prev;
} Node;

// PART ONE function prototypes
void reverseListRecursive(Node** head, Node** tail, Node* current);

int factorial(int n);

int fibonacci(int n);

int findMaxIDRecursive(Node* head, Node* current, int maxID);

int binarySearchLogs(Node logs[], int low, int high, int targetID);

void infixToPostfixRecursive(char* infix, int index, char* postfix, int* postIndex);

#endif // RECURSION_PART1_H