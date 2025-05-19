#ifndef CIRCULAR_LINKED_LISTS_H
#define CIRCULAR_LINKED_LISTS_H
#define MAX 500
typedef enum { INFO = 0, WARNING = 1, ERROR = 2, CRITICAL = 3 } Severity;
typedef struct Node {
    int id;
    char timestamp[20];
    char LOG[10];
    char message[MAX];
    struct Node* next;
    struct Node* prev;
} Node;


Node* allocate() ;

void insertAtBeginning(Node** head, Node** tail, int id, char* timestamp, char* LOG, char* message) ;

void insertAtEnd(Node** head, Node** tail, int id, char* timestamp, char* LOG, char* message) ;

void traverseForward(Node* head) ;

void traverseBackward(Node* tail) ;

void deleteByID(Node** head, Node** tail, int id) ;

int countLogs(Node* head) ;

void insertLog(Node** head, Node** tail, int id, char* timestamp, char* LOG, char* message, int maxSize, int* currentSize);

int detectCycle(Node* head);

Node* searchByID(Node* head, int id) ;

Node* searchByTimestamp(Node* head, char* timestamp) ;

Node* searchByKeyword(Node* head, char* keyword) ;

void reverseList(Node** head, Node** tail) ;

#endif 
