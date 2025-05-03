#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "circularLinkedLists.h"





int main() {
    Node* head = NULL;
    Node* tail = NULL;

    insertAtBeginning(&head, &tail, 1, "2025-03-26 12:30:00", "ERROR", "System crash");
    insertAtEnd(&head, &tail, 2, "2025-03-26 09:15:00", "WARNING", "Low disk space");
    insertAtEnd(&head, &tail, 3, "2025-03-26 14:45:00", "INFO", "User login");
    
    printf("Traverse Forward:\n");
    traverseForward(head);
    
    printf("\nTraverse Backward:\n");
    traverseBackward(tail);
    
    printf("\nDeleting ID 2...\n");
    deleteByID(&head, &tail, 2);
    traverseForward(head);
    
    printf("\nTotal Logs: %d\n", countLogs(head));
    
    return 0;
}