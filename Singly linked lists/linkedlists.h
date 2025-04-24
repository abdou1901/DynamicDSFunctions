#ifndef LINKEDLISTS_H
#define LINKEDLISTS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_MESSAGE_SIZE 256
#define MAX_TIMESTAMP_SIZE 20

//structure Definition
typedef struct LogEntry {
    int ID;
    char message[MAX_MESSAGE_SIZE];
    char timestamp[MAX_TIMESTAMP_SIZE];
    int severity;
    struct LogEntry* next;
} LogEntry;

//function Prototypes
void printLogs(LogEntry *head);
void InsertLogEntryAtStart(LogEntry **head, int id, char *message, char *timestamp, int severity);
void InsertLogEntryAtEnd(LogEntry **head, int id, char *message, char *timestamp, int severity);
void InsertLogEntryAtPosition(LogEntry **head, int id, char *message, char *timestamp, int severity, int pos);
void DeleteLogById(LogEntry **head, int id);
void DeleteLogByTimestamp(LogEntry **head, char *timestamp);
void DeleteFirstLog(LogEntry **head);
void DeleteLastLog(LogEntry **head);
LogEntry *searchLogByID(LogEntry *head, int id);
LogEntry *searchLogByKeyword(LogEntry *head, char *keyword);
LogEntry *searchLogByTimestamp(LogEntry *head, char *timestamp);
void SortBySeverity(LogEntry **head);
void SortByTimestamp(LogEntry **head);
void reverseLogs(LogEntry **head);
int CountLogs(LogEntry *head);

#endif
