#ifndef QUEUES_H
#define QUEUES_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAX_queue_SIZE 100
#define MAX_MESSAGE_SIZE 256
#define MAX_TIMESTAMP_SIZE 20

//define Log Entry Structure
typedef struct log {
    int ID;
    char message[MAX_MESSAGE_SIZE];
    char timestamp[MAX_TIMESTAMP_SIZE];
    int severity;
} logEntry;

//Define Queue Structure
typedef struct queue {
    logEntry *arr[MAX_queue_SIZE];
    int head, tail, size;
} queue;

//functions Declarations
queue *initQueue();
bool isEmpty(queue *logs);
bool isFull(queue *logs);
void Enqueue(queue *logs, int id, char *message, char *timestamp, int severity);
logEntry *Dequeue(queue *logs);
logEntry *Peek(queue *logs);
void freeQueue(queue *logs);
void printQueue(queue *logs);
#endif // LOG_QUEUE_H
