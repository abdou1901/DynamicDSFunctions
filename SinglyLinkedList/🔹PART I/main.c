#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "linkedlists.h"

// Function to clear the input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Function to create a sample log list for testing
LogEntry* createSampleLogList() {
    LogEntry* head = NULL;
    InsertLogEntryAtEnd(&head, 1, "System startup complete", "2023-05-10 08:00:00", 1);
    InsertLogEntryAtEnd(&head, 2, "User login failed: incorrect password", "2023-05-10 08:15:30", 3);
    InsertLogEntryAtEnd(&head, 3, "Database connection established", "2023-05-10 08:30:45", 1);
    InsertLogEntryAtEnd(&head, 4, "Memory usage exceeds threshold", "2023-05-10 09:45:22", 2);
    InsertLogEntryAtEnd(&head, 5, "Critical error in module X", "2023-05-10 10:12:05", 5);
    return head;
}

// Function to free all logs in the list
void freeAllLogs(LogEntry** head) {
    while (*head != NULL) {
        LogEntry* temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

// Test functions for each operation
void testPrintLogs() {
    printf("\n=== Testing printLogs ===\n");
    LogEntry* head = createSampleLogList();
    
    printf("Sample log list:\n");
    printLogs(head);
    
    freeAllLogs(&head);
}

void testInsertLogEntryAtStart() {
    printf("\n=== Testing InsertLogEntryAtStart ===\n");
    LogEntry* head = createSampleLogList();
    
    printf("Before insertion:\n");
    printLogs(head);
    
    printf("\nPredefined test - Insert at start:\n");
    InsertLogEntryAtStart(&head, 6, "New log at start", "2023-05-10 11:00:00", 2);
    printLogs(head);
    
    printf("\nCustom test - Insert at start:\n");
    int id;
    char message[MAX_MESSAGE_SIZE];
    char timestamp[MAX_TIMESTAMP_SIZE];
    int severity;
    
    printf("Enter log ID: ");
    scanf("%d", &id);
    clearInputBuffer();
    
    printf("Enter log message: ");
    fgets(message, MAX_MESSAGE_SIZE, stdin);
    message[strcspn(message, "\n")] = 0; // Remove newline
    
    printf("Enter timestamp: ");
    fgets(timestamp, MAX_TIMESTAMP_SIZE, stdin);
    timestamp[strcspn(timestamp, "\n")] = 0; // Remove newline
    
    printf("Enter severity (1-5): ");
    scanf("%d", &severity);
    clearInputBuffer();
    
    InsertLogEntryAtStart(&head, id, message, timestamp, severity);
    printf("\nAfter custom insertion:\n");
    printLogs(head);
    
    freeAllLogs(&head);
}

void testInsertLogEntryAtEnd() {
    printf("\n=== Testing InsertLogEntryAtEnd ===\n");
    LogEntry* head = createSampleLogList();
    
    printf("Before insertion:\n");
    printLogs(head);
    
    printf("\nPredefined test - Insert at end:\n");
    InsertLogEntryAtEnd(&head, 6, "New log at end", "2023-05-10 11:00:00", 2);
    printLogs(head);
    
    printf("\nCustom test - Insert at end:\n");
    int id;
    char message[MAX_MESSAGE_SIZE];
    char timestamp[MAX_TIMESTAMP_SIZE];
    int severity;
    
    printf("Enter log ID: ");
    scanf("%d", &id);
    clearInputBuffer();
    
    printf("Enter log message: ");
    fgets(message, MAX_MESSAGE_SIZE, stdin);
    message[strcspn(message, "\n")] = 0; // Remove newline
    
    printf("Enter timestamp: ");
    fgets(timestamp, MAX_TIMESTAMP_SIZE, stdin);
    timestamp[strcspn(timestamp, "\n")] = 0; // Remove newline
    
    printf("Enter severity (1-5): ");
    scanf("%d", &severity);
    clearInputBuffer();
    
    InsertLogEntryAtEnd(&head, id, message, timestamp, severity);
    printf("\nAfter custom insertion:\n");
    printLogs(head);
    
    freeAllLogs(&head);
}

void testInsertLogEntryAtPosition() {
    printf("\n=== Testing InsertLogEntryAtPosition ===\n");
    LogEntry* head = createSampleLogList();
    
    printf("Before insertion:\n");
    printLogs(head);
    
    printf("\nPredefined test - Insert at position 3:\n");
    InsertLogEntryAtPosition(&head, 6, "New log at position 3", "2023-05-10 11:00:00", 2, 3);
    printLogs(head);
    
    printf("\nCustom test - Insert at position:\n");
    int id, position;
    char message[MAX_MESSAGE_SIZE];
    char timestamp[MAX_TIMESTAMP_SIZE];
    int severity;
    
    printf("Enter log ID: ");
    scanf("%d", &id);
    clearInputBuffer();
    
    printf("Enter log message: ");
    fgets(message, MAX_MESSAGE_SIZE, stdin);
    message[strcspn(message, "\n")] = 0; // Remove newline
    
    printf("Enter timestamp: ");
    fgets(timestamp, MAX_TIMESTAMP_SIZE, stdin);
    timestamp[strcspn(timestamp, "\n")] = 0; // Remove newline
    
    printf("Enter severity (1-5): ");
    scanf("%d", &severity);
    
    printf("Enter position: ");
    scanf("%d", &position);
    clearInputBuffer();
    
    InsertLogEntryAtPosition(&head, id, message, timestamp, severity, position);
    printf("\nAfter custom insertion:\n");
    printLogs(head);
    
    freeAllLogs(&head);
}

void testDeleteLogById() {
    printf("\n=== Testing DeleteLogById ===\n");
    LogEntry* head = createSampleLogList();
    
    printf("Before deletion:\n");
    printLogs(head);
    
    printf("\nPredefined test - Delete log with ID 3:\n");
    DeleteLogById(&head, 3);
    printLogs(head);
    
    printf("\nCustom test - Delete log by ID:\n");
    int id;
    
    printf("Enter log ID to delete: ");
    scanf("%d", &id);
    clearInputBuffer();
    
    DeleteLogById(&head, id);
    printf("\nAfter custom deletion:\n");
    printLogs(head);
    
    freeAllLogs(&head);
}

void testDeleteLogByTimestamp() {
    printf("\n=== Testing DeleteLogByTimestamp ===\n");
    LogEntry* head = createSampleLogList();
    
    printf("Before deletion:\n");
    printLogs(head);
    
    printf("\nPredefined test - Delete log with timestamp '2023-05-10 08:30:45':\n");
    DeleteLogByTimestamp(&head, "2023-05-10 08:30:45");
    printLogs(head);
    
    printf("\nCustom test - Delete log by timestamp:\n");
    char timestamp[MAX_TIMESTAMP_SIZE];
    
    printf("Enter timestamp to delete: ");
    fgets(timestamp, MAX_TIMESTAMP_SIZE, stdin);
    timestamp[strcspn(timestamp, "\n")] = 0; // Remove newline
    
    DeleteLogByTimestamp(&head, timestamp);
    printf("\nAfter custom deletion:\n");
    printLogs(head);
    
    freeAllLogs(&head);
}

void testDeleteFirstLog() {
    printf("\n=== Testing DeleteFirstLog ===\n");
    LogEntry* head = createSampleLogList();
    
    printf("Before deletion:\n");
    printLogs(head);
    
    printf("\nDeleting first log:\n");
    DeleteFirstLog(&head);
    printLogs(head);
    
    freeAllLogs(&head);
}

void testDeleteLastLog() {
    printf("\n=== Testing DeleteLastLog ===\n");
    LogEntry* head = createSampleLogList();
    
    printf("Before deletion:\n");
    printLogs(head);
    
    printf("\nDeleting last log:\n");
    DeleteLastLog(&head);
    printLogs(head);
    
    freeAllLogs(&head);
}

void testSearchLogByID() {
    printf("\n=== Testing searchLogByID ===\n");
    LogEntry* head = createSampleLogList();
    
    printf("Log list:\n");
    printLogs(head);
    
    printf("\nPredefined test - Search log with ID 4:\n");
    LogEntry* result = searchLogByID(head, 4);
    if (result) {
        printf("Found log: ID: %d, Message = \"%s\", Date & time : \"%s\", severity = %d\n", 
               result->ID, result->message, result->timestamp, result->severity);
    }
    
    printf("\nCustom test - Search log by ID:\n");
    int id;
    
    printf("Enter log ID to search: ");
    scanf("%d", &id);
    clearInputBuffer();
    
    result = searchLogByID(head, id);
    if (result) {
        printf("Found log: ID: %d, Message = \"%s\", Date & time : \"%s\", severity = %d\n", 
               result->ID, result->message, result->timestamp, result->severity);
    }
    
    freeAllLogs(&head);
}

void testSearchLogByKeyword() {
    printf("\n=== Testing searchLogByKeyword ===\n");
    LogEntry* head = createSampleLogList();
    
    printf("Log list:\n");
    printLogs(head);
    
    printf("\nPredefined test - Search log with keyword 'error':\n");
    LogEntry* result = searchLogByKeyword(head, "error");
    if (result) {
        printf("Found log: ID: %d, Message = \"%s\", Date & time : \"%s\", severity = %d\n", 
               result->ID, result->message, result->timestamp, result->severity);
    }
    
    printf("\nCustom test - Search log by keyword:\n");
    char keyword[MAX_MESSAGE_SIZE];
    
    printf("Enter keyword to search: ");
    fgets(keyword, MAX_MESSAGE_SIZE, stdin);
    keyword[strcspn(keyword, "\n")] = 0; // Remove newline
    
    result = searchLogByKeyword(head, keyword);
    if (result) {
        printf("Found log: ID: %d, Message = \"%s\", Date & time : \"%s\", severity = %d\n", 
               result->ID, result->message, result->timestamp, result->severity);
    }
    
    freeAllLogs(&head);
}

void testSearchLogByTimestamp() {
    printf("\n=== Testing searchLogByTimestamp ===\n");
    LogEntry* head = createSampleLogList();
    
    printf("Log list:\n");
    printLogs(head);
    
    printf("\nPredefined test - Search log with timestamp '08:15':\n");
    LogEntry* result = searchLogByTimestamp(head, "08:15");
    if (result) {
        printf("Found log: ID: %d, Message = \"%s\", Date & time : \"%s\", severity = %d\n", 
               result->ID, result->message, result->timestamp, result->severity);
    }
    
    printf("\nCustom test - Search log by timestamp:\n");
    char timestamp[MAX_TIMESTAMP_SIZE];
    
    printf("Enter timestamp to search: ");
    fgets(timestamp, MAX_TIMESTAMP_SIZE, stdin);
    timestamp[strcspn(timestamp, "\n")] = 0; // Remove newline
    
    result = searchLogByTimestamp(head, timestamp);
    if (result) {
        printf("Found log: ID: %d, Message = \"%s\", Date & time : \"%s\", severity = %d\n", 
               result->ID, result->message, result->timestamp, result->severity);
    }
    
    freeAllLogs(&head);
}

void testSortBySeverity() {
    printf("\n=== Testing SortBySeverity ===\n");
    LogEntry* head = createSampleLogList();
    
    printf("Before sorting:\n");
    printLogs(head);
    
    printf("\nAfter sorting by severity:\n");
    SortBySeverity(&head);
    printLogs(head);
    
    freeAllLogs(&head);
}

void testSortByTimestamp() {
    printf("\n=== Testing SortByTimestamp ===\n");
    LogEntry* head = createSampleLogList();
    
    printf("Before sorting:\n");
    printLogs(head);
    
    printf("\nAfter sorting by timestamp:\n");
    SortByTimestamp(&head);
    printLogs(head);
    
    freeAllLogs(&head);
}

void testReverseLogs() {
    printf("\n=== Testing reverseLogs ===\n");
    LogEntry* head = createSampleLogList();
    
    printf("Before reversing:\n");
    printLogs(head);
    
    printf("\nAfter reversing:\n");
    reverseLogs(&head);
    printLogs(head);
    
    freeAllLogs(&head);
}

void testCountLogs() {
    printf("\n=== Testing CountLogs ===\n");
    LogEntry* head = createSampleLogList();
    
    printf("Log list:\n");
    printLogs(head);
    
    int count = CountLogs(head);
    printf("\nTotal number of logs: %d\n", count);
    
    freeAllLogs(&head);
}

// Main function with menu
int main() {
    int choice, testChoice;
    
    while (1) {
        printf("\n=== Log Entry Linked List Testing Menu ===\n");
        printf("1. Test printLogs\n");
        printf("2. Test InsertLogEntryAtStart\n");
        printf("3. Test InsertLogEntryAtEnd\n");
        printf("4. Test InsertLogEntryAtPosition\n");
        printf("5. Test DeleteLogById\n");
        printf("6. Test DeleteLogByTimestamp\n");
        printf("7. Test DeleteFirstLog\n");
        printf("8. Test DeleteLastLog\n");
        printf("9. Test searchLogByID\n");
        printf("10. Test searchLogByKeyword\n");
        printf("11. Test searchLogByTimestamp\n");
        printf("12. Test SortBySeverity\n");
        printf("13. Test SortByTimestamp\n");
        printf("14. Test reverseLogs\n");
        printf("15. Test CountLogs\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();
        
        if (choice == 0) {
            break;
        }
        
        switch (choice) {
            case 1:
                testPrintLogs();
                break;
            case 2:
                testInsertLogEntryAtStart();
                break;
            case 3:
                testInsertLogEntryAtEnd();
                break;
            case 4:
                testInsertLogEntryAtPosition();
                break;
            case 5:
                testDeleteLogById();
                break;
            case 6:
                testDeleteLogByTimestamp();
                break;
            case 7:
                testDeleteFirstLog();
                break;
            case 8:
                testDeleteLastLog();
                break;
            case 9:
                testSearchLogByID();
                break;
            case 10:
                testSearchLogByKeyword();
                break;
            case 11:
                testSearchLogByTimestamp();
                break;
            case 12:
                testSortBySeverity();
                break;
            case 13:
                testSortByTimestamp();
                break;
            case 14:
                testReverseLogs();
                break;
            case 15:
                testCountLogs();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    printf("Testing completed. Exiting...\n");
    return 0;
}
