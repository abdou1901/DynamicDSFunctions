#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stacks.h"


//added functions(just to help us simplify things )
stack *initStack(){
    stack *st = (stack *)malloc(sizeof(stack));
    st->top = -1;
    return st;
}

bool isFull(stack *st){
    return st->top == MAX_STACK_SIZE -1;
}
bool isEmpty(stack *st){
    return st->top == -1;
}
void printStack(stack *logs){
    if(isEmpty(logs)) return;
    for(int i= 0 ; i <= logs->top;i++){
        printf("ID: %d, Message = \"%s\", Date & time : \"%s\", severity = %d\n",logs->arr[i]->ID,logs->arr[i]->message,logs->arr[i]->timestamp,logs->arr[i]->severity);
    }

}
void pushLog(stack *logs ,int id,char *message,char *timestamp,int severity){
    if(isFull(logs)){
        printf("The Log Stack is Full !\n");
        return;
    }
    logEntry *newlog = (logEntry *)malloc(sizeof(logEntry));
    newlog->ID = id;
    newlog->severity = severity;
    strncpy(newlog->message , message,MAX_MESSAGE_SIZE-1);
    newlog->message[MAX_MESSAGE_SIZE-1] = '\0';
    strncpy(newlog->timestamp,timestamp,MAX_TIMESTAMP_SIZE-1);
    newlog->timestamp[MAX_TIMESTAMP_SIZE-1] = '\0';
    logs->top++;
    logs->arr[logs->top] = newlog;
}
logEntry *popLog(stack *logs){
    if(isEmpty(logs)){
        printf("The log stack is already empty !\n");
        return NULL;
    }
    logEntry *poppedLog = logs->arr[logs->top];
    logs->arr[logs->top] = NULL;
    logs->top--;
    
    return poppedLog;
}
logEntry *peekLog(stack *logs){
    if(isEmpty(logs)){
        printf("The log Stack is empty !\n");
        return NULL;
    }
    return logs->arr[logs->top];
}

void insertAtBottom(stack *logs, logEntry *entry){
    if(isEmpty(logs)){
        pushLog(logs,entry->ID,entry->message,entry->timestamp,entry->severity);
        free(entry);
        return;
    }
    logEntry *temp=popLog(logs);
    insertAtBottom(logs,entry);
    pushLog(logs,temp->ID,temp->message,temp->timestamp,temp->severity);
    free(temp);
}
void ReverseLogsStack(stack *logs){
    if(isEmpty(logs)) return;
    logEntry *temp =popLog(logs);
    ReverseLogsStack(logs);
    insertAtBottom(logs,temp);
}

void freeStack(stack *logs){
    while(!isEmpty(logs)){
        logEntry *temp = popLog(logs);
        free(temp);
    }
    free(logs);
}
