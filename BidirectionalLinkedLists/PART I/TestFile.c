#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bidirectionalLinkedLists.h"

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    
    printf("Testing insertAtBeginning and insertAtEnd:\n");
    insertAtBeginning(&head, &tail, 1, "2025-03-26 12:30:00", "ERROR", "System crash");
    insertAtEnd(&head, &tail, 2, "2025-03-26 09:15:00", "WARNING", "Low disk space");
    insertAtEnd(&head, &tail, 3, "2025-03-26 14:45:00", "INFO", "User login");
    
    printf("\nTraverse Forward:\n");
    traverseForward(head);
    
    printf("\n\nTraverse Backward:\n");
    traverseBackward(tail);
    
    printf("\n\nTesting insertAtPosition:\n");
    insertAtPosition(&head, &tail, 4, "2025-03-26 13:00:00", "CRITICAL", "Database failure", 2);
    traverseForward(head);
    
    printf("\n\nCount Logs: %d\n", countLogs(head));
    
    printf("\nTesting searchByID:\n");
    Node* foundNode = searchByID(head, 2);
    if (foundNode) printf("Found node with ID 2: %s\n", foundNode->message);
    
    printf("\nTesting searchByTimestamp:\n");
    foundNode = searchByTimestamp(head, "2025-03-26 14:45:00");
    if (foundNode) printf("Found node with timestamp 2025-03-26 14:45:00: %s\n", foundNode->message);
    
    printf("\nTesting searchByKeyword:\n");
    foundNode = searchByKeyword(head, "ERROR");
    if (foundNode) printf("Found node with LOG 'ERROR': %s\n", foundNode->message);
    
    printf("\nTesting deleteByID:\n");
    deleteByID(&head, &tail, 2);
    traverseForward(head);
    
    printf("\n\nTesting deleteByTimestamp:\n");
    deleteByTimestamp(&head, &tail, "2025-03-26 14:45:00");
    traverseForward(head);
    
    printf("\n\nTesting reverseList:\n");
    reverseList(&head, &tail);
    traverseForward(head);
    
    printf("\n\nTesting sortByDate:\n");
    insertAtEnd(&head, &tail, 5, "2025-03-25 10:00:00", "WARNING", "Memory leak");
    insertAtEnd(&head, &tail, 6, "2025-03-27 11:30:00", "INFO", "System update");
    traverseForward(head);
    sortByDate(&head);
    printf("\nAfter sorting by date:\n");
    traverseForward(head);
    
    printf("\n\nTesting sortBySeverity:\n");
    sortBySeverity(&head);
    printf("After sorting by severity:\n");
    traverseForward(head);
    
    printf("\n\nTesting deleteAtIndex:\n");
    deleteAtIndex(&head, &tail, 1);
    traverseForward(head);
    
    printf("\n\nTesting deleteFirst and deleteLast:\n");
    deleteFirst(&head, &tail);
    printf("After deleteFirst:\n");
    traverseForward(head);
    
    printf("\n\nAfter deleteLast:\n");
    deleteLast(&head, &tail);
    traverseForward(head);
    
    printf("\n\nTesting mergeLogLists:\n");
    Node* head2 = NULL;
    Node* tail2 = NULL;
    insertAtBeginning(&head2, &tail2, 7, "2025-03-28 09:00:00", "ERROR", "Network down");
    insertAtEnd(&head2, &tail2, 8, "2025-03-28 10:30:00", "CRITICAL", "Security breach");
    
    printf("First list:\n");
    traverseForward(head);
    printf("\n\nSecond list:\n");
    traverseForward(head2);
    
    Node* mergedHead = mergeLogLists(head, head2);
    printf("\n\nMerged list:\n");
    traverseForward(mergedHead);
    
    printf("\n");
    return 0;
}