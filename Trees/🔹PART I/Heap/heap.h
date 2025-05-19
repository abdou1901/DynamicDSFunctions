#ifndef HEAP_H
#define HEAP_H

#define MAX_MESSAGE_SIZE   256
#define MAX_TIMESTAMP_SIZE 20

typedef struct {
    int  ID;
    char message[MAX_MESSAGE_SIZE];
    char timestamp[MAX_TIMESTAMP_SIZE];
    int  severity;
} LogEntry;

typedef struct {
    LogEntry **data;
    int size;
    int cap;
} LogHeap;

LogHeap *createHeap(int initialCap);
int insertLog(LogHeap *h, int id, const char *msg, const char *ts, int severity);
LogEntry *peekLog(LogHeap *h);
LogEntry *popLog(LogHeap *h);
void freeHeap(LogHeap *h);

#endif