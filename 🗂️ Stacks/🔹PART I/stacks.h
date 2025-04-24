#ifndef STACKS_H
#define STACKS_H

#include <stdbool.h>

#define MAX_STACK_SIZE 100
#define MAX_MESSAGE_SIZE 256
#define MAX_TIMESTAMP_SIZE 20

typedef struct log {
    int ID;
    char message[MAX_MESSAGE_SIZE];
    char timestamp[MAX_TIMESTAMP_SIZE];
    int severity;
} logEntry;

typedef struct stack {
    logEntry *arr[MAX_STACK_SIZE];
    int top;
} stack;

// Initialization
stack *initStack();
void freeStack(stack *logs);

// Stack operations
bool isFull(stack *st);
bool isEmpty(stack *st);
void pushLog(stack *logs, int id, char *message, char *timestamp, int severity);
logEntry *popLog(stack *logs);
logEntry *peekLog(stack *logs);
void printStack(stack *logs);
void ReverseLogsStack(stack *logs);

#endif
