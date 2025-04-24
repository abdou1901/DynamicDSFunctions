#include "queues.h"


queue *initQueue(){
    queue *logs = (queue *)malloc(sizeof(queue));
    logs->head = 0;
    logs->tail = -1;
    logs->size = 0;
    return logs;
}



bool isEmpty(queue *logs){
    return logs->size == 0;
}
bool isFull(queue *logs){
    return logs->size == MAX_queue_SIZE;
}


void Enqueue(queue *logs ,int id,char *message,char *timestamp,int severity){
    if(isFull(logs)){
        printf("The Log queue is Full !\n");
        return;
    }
    logEntry *newlog = (logEntry *)malloc(sizeof(logEntry));
    newlog->ID = id;
    newlog->severity = severity;
    strncpy(newlog->message , message,MAX_MESSAGE_SIZE-1);
    newlog->message[MAX_MESSAGE_SIZE-1] = '\0';
    strncpy(newlog->timestamp,timestamp,MAX_TIMESTAMP_SIZE-1);
    newlog->timestamp[MAX_TIMESTAMP_SIZE-1] = '\0';
    logs->tail = (logs->tail+1) % MAX_queue_SIZE;
    logs->size ++;
    logs->arr[logs->tail] = newlog;
}
logEntry *Dequeue(queue *logs){
    if(isEmpty(logs)){
        printf("The log queue is Empty, cannot dequeue !\n");
        return NULL;
    }
    logEntry *dequeuedLog = logs->arr[logs->head];
    logs->arr[logs->head] = NULL;
    logs->head = (logs->head +1)%MAX_queue_SIZE;
    logs->size--;
    return dequeuedLog;
}
logEntry *Peek(queue *logs){
    if(isEmpty(logs)){
        printf("The log queue is Empty, cannot peek !\n");
        return NULL;
    }
    return logs->arr[logs->head];
}

//(added to free the queue with all it logs)
void freeQueue(queue *logs){
    while(!isEmpty(logs)){
        logEntry *log = Dequeue(logs);
        free(log);
    }
    free(logs);
}

//(aded to print a queue)
void printQueue(queue *logs) {
    if (isEmpty(logs)) {
        printf("The log queue is Empty!\n");
        return;
    }
    printf("\nCurrent Log Queue:\n");
    printf("------------------------------------------------------------------------------------------\n");
    printf("| %-3s | %-40s | %-25s | %-8s |\n", "ID", "Message", "Timestamp", "Severity");
    printf("------------------------------------------------------------------------------------------\n");
    int index = logs->head;
    for (int i = 0; i < logs->size; i++) {
        logEntry *log = logs->arr[index];
        printf("| %-3d | %-40s | %-25s | %-8d |\n",
               log->ID, log->message, log->timestamp, log->severity);
        index = (index + 1) % MAX_queue_SIZE;
    }
    printf("------------------------------------------------------------------------------------------\n");
}

