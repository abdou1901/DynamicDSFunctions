#include <stdio.h>
#include<stdlib.h>

#ifndef BIDIRECTIONAL_LINKED_LISTS_H
#define BIDIRECTIONAL_LINKED_LISTS_H

#define MAX 500

//* i will be casual and name it node as you want
typedef enum { INFO = 0, WARNING = 1, ERROR = 2, CRITICAL = 3 } Severity;

typedef struct Node {
    int id;               
    char timestamp[20];    
    char LOG[10];    
    char message[MAX];     
    struct Node* next;
    struct Node* prev;
} Node;

//* procedures

void insertAtBeginning(Node** head,Node **tail, int id, char* timestamp, char* LOG, char* message);

void insertAtEnd(Node** head,Node **tail,int id, char* timestamp, char* LOG, char* message);

void insertAtPosition(Node** head,Node **tail, int id, char* timestamp, char* LOG, char* message, int position);

void deleteByID(Node** head, Node** tail, int id);

void deleteByTimestamp(Node** head, Node** tail, char* timestamp);

void deleteFirst(Node** head, Node** tail);

void deleteLast(Node** head, Node** tail);

Node* searchByID(Node* head, int id);

Node* searchByKeyword(Node* head, char* keyword);

Node* searchByTimestamp(Node* head, char* timestamp);

void sortByDate(Node** head);

void sortBySeverity(Node** head);

void reverseList(Node** head, Node** tail);

int countLogs(Node* head);

void traverseForward(Node* head);

void traverseBackward(Node* tail);

void deleteAtIndex(Node** head, Node** tail, int index);

Node* mergeLogLists(Node* list1, Node* list2);


#endif // BIDIRECTIONAL_LINKED_LISTS_H



