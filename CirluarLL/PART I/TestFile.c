#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "circularLinkedLists.h"

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    int currentSize = 0;
    int maxSize = 5;
    
    printf("Testing allocate(), insertAtBeginning(), insertAtEnd():\n");
    insertAtBeginning(&head, &tail, 1, "2025-03-26 12:30:00", "ERROR", "System crash");
    insertAtEnd(&head, &tail, 2, "2025-03-26 09:15:00", "WARNING", "Low disk space");
    insertAtEnd(&head, &tail, 3, "2025-03-26 14:45:00", "INFO", "User login");
    
    printf("\nTesting traverseForward():\n");
    traverseForward(head);
    
    printf("\nTesting traverseBackward():\n");
    traverseBackward(tail);
    
    printf("\nTesting countLogs(): %d\n", countLogs(head));
    
    printf("\nTesting searchByID():\n");
    Node* foundNode = searchByID(head, 2);
    if (foundNode) printf("Found node with ID 2: %s\n", foundNode->message);
    
    printf("\nTesting searchByTimestamp():\n");
    foundNode = searchByTimestamp(head, "2025-03-26 14:45:00");
    if (foundNode) printf("Found node with timestamp 2025-03-26 14:45:00: %s\n", foundNode->message);
    
    printf("\nTesting searchByKeyword():\n");
    foundNode = searchByKeyword(head, "crash");
    if (foundNode) printf("Found node with keyword 'crash': %s\n", foundNode->message);
    
    printf("\nTesting detectCycle(): %d\n", detectCycle(head));
    
    printf("\nTesting insertLog():\n");
    currentSize = countLogs(head);
    insertLog(&head, &tail, 4, "2025-03-26 16:00:00", "CRITICAL", "Database failure", maxSize, &currentSize);
    traverseForward(head);
    
    printf("\nTesting reverseList():\n");
    reverseList(&head, &tail);
    traverseForward(head);
    
    printf("\nTesting deleteByID():\n");
    deleteByID(&head, &tail, 2);
    traverseForward(head);
    
    return 0;
}