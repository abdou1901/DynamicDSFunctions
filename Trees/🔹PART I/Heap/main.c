#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heap.h"

// Global heap
LogHeap *heap = NULL;

// Function to clear the input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Function to get string input from user
void getStringInput(char *prompt, char *buffer, int size) {
    printf("%s", prompt);
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Remove newline
}

// Function to get integer input from user
int getIntInput(char *prompt) {
    int value;
    printf("%s", prompt);
    scanf("%d", &value);
    clearInputBuffer();
    return value;
}

// Function to print a log entry
void printLogEntry(LogEntry *log) {
    if (log == NULL) {
        printf("Log entry is NULL\n");
        return;
    }
    printf("ID: %d, Severity: %d, Timestamp: '%s', Message: '%s'\n", 
           log->ID, log->severity, log->timestamp, log->message);
}

// Function to print all logs in the heap (destructive operation)
void printAllLogs() {
    if (heap == NULL || heap->size == 0) {
        printf("Heap is empty.\n");
        return;
    }
    
    printf("\nHeap contents (in order of extraction):\n");
    printf("----------------------------------------\n");
    
    // Create a temporary copy of the heap
    LogHeap *tempHeap = createHeap(heap->cap);
    if (!tempHeap) {
        printf("Error creating temporary heap.\n");
        return;
    }
    
    // Copy all entries to the temporary heap
    for (int i = 0; i < heap->size; i++) {
        LogEntry *entry = heap->data[i];
        insertLog(tempHeap, entry->ID, entry->message, entry->timestamp, entry->severity);
    }
    
    // Extract and print all entries from the temporary heap
    int count = 0;
    while (tempHeap->size > 0) {
        LogEntry *entry = popLog(tempHeap);
        printf("%d) ", ++count);
        printLogEntry(entry);
        free(entry); // Free the popped entry
    }
    
    // Free the temporary heap
    freeHeap(tempHeap);
}

// Function to create a predefined heap
void createPredefinedHeap() {
    // Free existing heap if any
    if (heap != NULL) {
        freeHeap(heap);
    }
    
    // Create a new heap
    heap = createHeap(10);
    if (!heap) {
        printf("Error creating heap.\n");
        return;
    }
    
    // Insert some predefined log entries
    insertLog(heap, 1, "System startup", "2023-01-01 08:00:00", 1);
    insertLog(heap, 2, "User login failed", "2023-01-01 08:15:30", 3);
    insertLog(heap, 3, "Database connection established", "2023-01-01 08:30:45", 1);
    insertLog(heap, 4, "Memory usage exceeds threshold", "2023-01-01 09:45:22", 2);
    insertLog(heap, 5, "Critical error in module X", "2023-01-01 10:12:05", 5);
    insertLog(heap, 6, "Backup completed", "2023-01-01 11:30:00", 1);
    insertLog(heap, 7, "Network connection lost", "2023-01-01 12:45:10", 4);
    
    printf("\nPredefined heap created successfully.\n");
    printf("The heap contains 7 log entries with varying severity levels.\n");
}

// Function to create a custom heap
void createCustomHeap() {
    // Free existing heap if any
    if (heap != NULL) {
        freeHeap(heap);
    }
    
    // Create a new heap
    int initialCapacity = getIntInput("Enter initial heap capacity: ");
    heap = createHeap(initialCapacity);
    if (!heap) {
        printf("Error creating heap.\n");
        return;
    }
    
    int numLogs = getIntInput("How many log entries do you want to insert? ");
    
    for (int i = 0; i < numLogs; i++) {
        printf("\nLog Entry #%d:\n", i+1);
        int id = getIntInput("Enter log ID: ");
        char message[MAX_MESSAGE_SIZE];
        getStringInput("Enter log message: ", message, sizeof(message));
        char timestamp[MAX_TIMESTAMP_SIZE];
        getStringInput("Enter timestamp: ", timestamp, sizeof(timestamp));
        int severity = getIntInput("Enter severity (1-5): ");
        
        if (insertLog(heap, id, message, timestamp, severity) != 0) {
            printf("Error inserting log entry.\n");
        }
    }
    
    printf("\nCustom heap created successfully with %d log entries.\n", numLogs);
}

// Test functions for each operation
void testCreateHeap() {
    printf("\n=== Testing createHeap ===\n");
    
    // Free existing heap if any
    if (heap != NULL) {
        freeHeap(heap);
    }
    
    int initialCapacity = getIntInput("Enter initial heap capacity: ");
    heap = createHeap(initialCapacity);
    
    if (heap) {
        printf("Heap created successfully with initial capacity %d.\n", initialCapacity);
    } else {
        printf("Error creating heap.\n");
    }
}

void testInsertLog() {
    printf("\n=== Testing insertLog ===\n");
    
    if (heap == NULL) {
        printf("Heap is not initialized. Please create a heap first.\n");
        return;
    }
    
    int id = getIntInput("Enter log ID: ");
    char message[MAX_MESSAGE_SIZE];
    getStringInput("Enter log message: ", message, sizeof(message));
    char timestamp[MAX_TIMESTAMP_SIZE];
    getStringInput("Enter timestamp: ", timestamp, sizeof(timestamp));
    int severity = getIntInput("Enter severity (1-5): ");
    
    if (insertLog(heap, id, message, timestamp, severity) == 0) {
        printf("Log entry inserted successfully.\n");
        printf("Current heap size: %d\n", heap->size);
    } else {
        printf("Error inserting log entry.\n");
    }
}

void testPeekLog() {
    printf("\n=== Testing peekLog ===\n");
    
    if (heap == NULL) {
        printf("Heap is not initialized. Please create a heap first.\n");
        return;
    }
    
    LogEntry *top = peekLog(heap);
    
    if (top) {
        printf("Top log entry (without removing):\n");
        printLogEntry(top);
    } else {
        printf("Heap is empty.\n");
    }
}

void testPopLog() {
    printf("\n=== Testing popLog ===\n");
    
    if (heap == NULL) {
        printf("Heap is not initialized. Please create a heap first.\n");
        return;
    }
    
    LogEntry *top = popLog(heap);
    
    if (top) {
        printf("Popped log entry:\n");
        printLogEntry(top);
        printf("Current heap size: %d\n", heap->size);
        
        // Free the popped entry
        free(top);
    } else {
        printf("Heap is empty.\n");
    }
}

void testFreeHeap() {
    printf("\n=== Testing freeHeap ===\n");
    
    if (heap == NULL) {
        printf("Heap is not initialized. Nothing to free.\n");
        return;
    }
    
    printf("Freeing heap with %d entries...\n", heap->size);
    freeHeap(heap);
    heap = NULL;
    printf("Heap freed successfully.\n");
}

// Main function with menu
int main() {
    int choice;
    
    // First, choose between predefined or custom heap
    printf("=== Log Heap Testing ===\n");
    printf("Choose a heap to work with:\n");
    printf("1. Use a predefined heap\n");
    printf("2. Create your own heap\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    clearInputBuffer();
    
    if (choice == 1) {
        createPredefinedHeap();
    } else if (choice == 2) {
        createCustomHeap();
    } else {
        printf("Invalid choice. Exiting...\n");
        return 1;
    }
    
    // Now show the function selection menu
    while (1) {
        printf("\n=== Log Heap Testing Menu ===\n");
        printf("1. Test createHeap (create a new heap)\n");
        printf("2. Test insertLog\n");
        printf("3. Test peekLog\n");
        printf("4. Test popLog\n");
        printf("5. Test freeHeap\n");
        printf("6. Print all logs in the heap\n");
        printf("7. Create a predefined heap\n");
        printf("8. Create a custom heap\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();
        
        if (choice == 0) {
            break;
        }
        
        switch (choice) {
            case 1:
                testCreateHeap();
                break;
            case 2:
                testInsertLog();
                break;
            case 3:
                testPeekLog();
                break;
            case 4:
                testPopLog();
                break;
            case 5:
                testFreeHeap();
                break;
            case 6:
                printAllLogs();
                break;
            case 7:
                createPredefinedHeap();
                break;
            case 8:
                createCustomHeap();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    // Free the heap before exiting
    if (heap != NULL) {
        freeHeap(heap);
    }
    
    printf("Testing completed. Exiting...\n");
    return 0;
}