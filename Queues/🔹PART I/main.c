#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "queues.h"

// Function to clear the input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Function to create a sample queue for testing
queue* createSampleQueue() {
    queue* logs = initQueue();
    Enqueue(logs, 1, "System startup complete", "2023-05-10 08:00:00", 1);
    Enqueue(logs, 2, "User login failed", "2023-05-10 08:15:30", 3);
    Enqueue(logs, 3, "Database connection established", "2023-05-10 08:30:45", 1);
    Enqueue(logs, 4, "Memory usage exceeds threshold", "2023-05-10 09:45:22", 2);
    Enqueue(logs, 5, "Critical error in module X", "2023-05-10 10:12:05", 5);
    return logs;
}

// Test functions for each operation
void testInitQueue() {
    printf("\n=== Testing initQueue ===\n");
    
    int testChoice;
    printf("Choose test type:\n");
    printf("1. Predefined test\n");
    printf("2. No custom test available (initialization is simple)\n");
    printf("Enter your choice: ");
    scanf("%d", &testChoice);
    clearInputBuffer();
    
    if (testChoice == 1) {
        printf("\nPredefined test - Initialize a new queue:\n");
        queue* logs = initQueue();
        printf("Queue initialized successfully.\n");
        printf("Queue properties: head=%d, tail=%d, size=%d\n", logs->head, logs->tail, logs->size);
        printf("Is queue empty? %s\n", isEmpty(logs) ? "Yes" : "No");
        printf("Is queue full? %s\n", isFull(logs) ? "Yes" : "No");
        freeQueue(logs);
    } else {
        printf("No custom test available for initialization.\n");
    }
}

void testIsEmpty() {
    printf("\n=== Testing isEmpty ===\n");
    
    int testChoice;
    printf("Choose test type:\n");
    printf("1. Predefined test\n");
    printf("2. Custom test\n");
    printf("Enter your choice: ");
    scanf("%d", &testChoice);
    clearInputBuffer();
    
    if (testChoice == 1) {
        printf("\nPredefined test - Check if queue is empty:\n");
        
        // Test with empty queue
        queue* emptyLogs = initQueue();
        printf("Empty queue - isEmpty() returns: %s\n", isEmpty(emptyLogs) ? "true" : "false");
        
        // Test with non-empty queue
        queue* nonEmptyLogs = createSampleQueue();
        printf("Non-empty queue - isEmpty() returns: %s\n", isEmpty(nonEmptyLogs) ? "true" : "false");
        
        freeQueue(emptyLogs);
        freeQueue(nonEmptyLogs);
    } else if (testChoice == 2) {
        printf("\nCustom test - Check if queue is empty:\n");
        printf("1. Test with an empty queue\n");
        printf("2. Test with a queue containing logs\n");
        printf("Enter your choice: ");
        int customChoice;
        scanf("%d", &customChoice);
        clearInputBuffer();
        
        if (customChoice == 1) {
            queue* logs = initQueue();
            printf("Empty queue - isEmpty() returns: %s\n", isEmpty(logs) ? "true" : "false");
            freeQueue(logs);
        } else if (customChoice == 2) {
            queue* logs = initQueue();
            int numLogs;
            printf("How many logs do you want to add? ");
            scanf("%d", &numLogs);
            clearInputBuffer();
            
            for (int i = 0; i < numLogs; i++) {
                Enqueue(logs, i+1, "Test log", "2023-05-10 00:00:00", 1);
            }
            
            printf("Queue with %d logs - isEmpty() returns: %s\n", numLogs, isEmpty(logs) ? "true" : "false");
            freeQueue(logs);
        }
    }
}

void testIsFull() {
    printf("\n=== Testing isFull ===\n");
    
    int testChoice;
    printf("Choose test type:\n");
    printf("1. Predefined test\n");
    printf("2. Custom test\n");
    printf("Enter your choice: ");
    scanf("%d", &testChoice);
    clearInputBuffer();
    
    if (testChoice == 1) {
        printf("\nPredefined test - Check if queue is full:\n");
        
        // Test with empty queue
        queue* emptyLogs = initQueue();
        printf("Empty queue - isFull() returns: %s\n", isFull(emptyLogs) ? "true" : "false");
        
        // Test with a queue that has some elements
        queue* partialLogs = createSampleQueue();
        printf("Partially filled queue - isFull() returns: %s\n", isFull(partialLogs) ? "true" : "false");
        
        // Test with a full queue (assuming MAX_queue_SIZE is accessible)
        queue* fullLogs = initQueue();
        printf("Attempting to fill the queue to capacity...\n");
        for (int i = 0; i < MAX_queue_SIZE; i++) {
            char message[MAX_MESSAGE_SIZE];
            snprintf(message, MAX_MESSAGE_SIZE, "Log entry %d", i+1);
            Enqueue(fullLogs, i+1, message, "2023-05-10 00:00:00", 1);
        }
        printf("Queue filled with %d logs - isFull() returns: %s\n", fullLogs->size, isFull(fullLogs) ? "true" : "false");
        
        freeQueue(emptyLogs);
        freeQueue(partialLogs);
        freeQueue(fullLogs);
    } else if (testChoice == 2) {
        printf("\nCustom test - Check if queue is full:\n");
        printf("1. Test with an empty queue\n");
        printf("2. Test with a queue containing logs\n");
        printf("3. Test with a full queue\n");
        printf("Enter your choice: ");
        int customChoice;
        scanf("%d", &customChoice);
        clearInputBuffer();
        
        if (customChoice == 1) {
            queue* logs = initQueue();
            printf("Empty queue - isFull() returns: %s\n", isFull(logs) ? "true" : "false");
            freeQueue(logs);
        } else if (customChoice == 2) {
            queue* logs = initQueue();
            int numLogs;
            printf("How many logs do you want to add? ");
            scanf("%d", &numLogs);
            clearInputBuffer();
            
            if (numLogs > MAX_queue_SIZE) {
                printf("Warning: Maximum queue size is %d. Will add only %d logs.\n", MAX_queue_SIZE, MAX_queue_SIZE);
                numLogs = MAX_queue_SIZE;
            }
            
            for (int i = 0; i < numLogs; i++) {
                Enqueue(logs, i+1, "Test log", "2023-05-10 00:00:00", 1);
            }
            
            printf("Queue with %d logs - isFull() returns: %s\n", numLogs, isFull(logs) ? "true" : "false");
            freeQueue(logs);
        } else if (customChoice == 3) {
            queue* logs = initQueue();
            printf("Filling the queue to capacity...\n");
            for (int i = 0; i < MAX_queue_SIZE; i++) {
                char message[MAX_MESSAGE_SIZE];
                snprintf(message, MAX_MESSAGE_SIZE, "Log entry %d", i+1);
                Enqueue(logs, i+1, message, "2023-05-10 00:00:00", 1);
            }
            printf("Queue filled with %d logs - isFull() returns: %s\n", logs->size, isFull(logs) ? "true" : "false");
            freeQueue(logs);
        }
    }
}

void testEnqueue() {
    printf("\n=== Testing Enqueue ===\n");
    
    int testChoice;
    printf("Choose test type:\n");
    printf("1. Predefined test\n");
    printf("2. Custom test\n");
    printf("Enter your choice: ");
    scanf("%d", &testChoice);
    clearInputBuffer();
    
    if (testChoice == 1) {
        printf("\nPredefined test - Enqueue a log entry:\n");
        
        // Test with an empty queue
        queue* logs = initQueue();
        printf("Initial queue state:\n");
        printQueue(logs);
        
        printf("\nEnqueuing a log entry...\n");
        Enqueue(logs, 1, "System startup complete", "2023-05-10 08:00:00", 1);
        printf("Queue after enqueuing one log:\n");
        printQueue(logs);
        
        printf("\nEnqueuing more log entries...\n");
        Enqueue(logs, 2, "User login failed", "2023-05-10 08:15:30", 3);
        Enqueue(logs, 3, "Database connection established", "2023-05-10 08:30:45", 1);
        printf("Queue after enqueuing more logs:\n");
        printQueue(logs);
        
        freeQueue(logs);
    } else if (testChoice == 2) {
        printf("\nCustom test - Enqueue a log entry:\n");
        queue* logs = initQueue();
        
        int numLogs;
        printf("How many logs do you want to enqueue? ");
        scanf("%d", &numLogs);
        clearInputBuffer();
        
        for (int i = 0; i < numLogs; i++) {
            int id, severity;
            char message[MAX_MESSAGE_SIZE];
            char timestamp[MAX_TIMESTAMP_SIZE];
            
            printf("\nLog #%d:\n", i+1);
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
            
            Enqueue(logs, id, message, timestamp, severity);
            printf("Queue after enqueuing log #%d:\n", i+1);
            printQueue(logs);
        }
        
        freeQueue(logs);
    }
}

void testDequeue() {
    printf("\n=== Testing Dequeue ===\n");
    
    int testChoice;
    printf("Choose test type:\n");
    printf("1. Predefined test\n");
    printf("2. Custom test\n");
    printf("Enter your choice: ");
    scanf("%d", &testChoice);
    clearInputBuffer();
    
    if (testChoice == 1) {
        printf("\nPredefined test - Dequeue a log entry:\n");
        
        // Test with a sample queue
        queue* logs = createSampleQueue();
        printf("Initial queue state:\n");
        printQueue(logs);
        
        printf("\nDequeuing a log entry...\n");
        logEntry* log = Dequeue(logs);
        if (log != NULL) {
            printf("Dequeued log: ID=%d, Message=\"%s\", Timestamp=\"%s\", Severity=%d\n",
                   log->ID, log->message, log->timestamp, log->severity);
            free(log);
        }
        
        printf("\nQueue after dequeuing:\n");
        printQueue(logs);
        
        // Test with an empty queue
        queue* emptyLogs = initQueue();
        printf("\nAttempting to dequeue from an empty queue:\n");
        log = Dequeue(emptyLogs);
        if (log == NULL) {
            printf("Dequeue returned NULL as expected.\n");
        }
        
        freeQueue(logs);
        freeQueue(emptyLogs);
    } else if (testChoice == 2) {
        printf("\nCustom test - Dequeue a log entry:\n");
        printf("1. Test with a queue containing logs\n");
        printf("2. Test with an empty queue\n");
        printf("Enter your choice: ");
        int customChoice;
        scanf("%d", &customChoice);
        clearInputBuffer();
        
        if (customChoice == 1) {
            queue* logs = createSampleQueue();
            printf("Initial queue state:\n");
            printQueue(logs);
            
            int numToDequeue;
            printf("\nHow many logs do you want to dequeue? ");
            scanf("%d", &numToDequeue);
            clearInputBuffer();
            
            for (int i = 0; i < numToDequeue; i++) {
                printf("\nDequeuing log #%d...\n", i+1);
                logEntry* log = Dequeue(logs);
                if (log != NULL) {
                    printf("Dequeued log: ID=%d, Message=\"%s\", Timestamp=\"%s\", Severity=%d\n",
                           log->ID, log->message, log->timestamp, log->severity);
                    free(log);
                    printf("\nQueue after dequeuing:\n");
                    printQueue(logs);
                } else {
                    printf("Queue is empty, cannot dequeue more logs.\n");
                    break;
                }
            }
            
            freeQueue(logs);
        } else if (customChoice == 2) {
            queue* logs = initQueue();
            printf("Empty queue state:\n");
            printQueue(logs);
            
            printf("\nAttempting to dequeue from an empty queue:\n");
            logEntry* log = Dequeue(logs);
            if (log == NULL) {
                printf("Dequeue returned NULL as expected.\n");
            }
            
            freeQueue(logs);
        }
    }
}

void testPeek() {
    printf("\n=== Testing Peek ===\n");
    
    int testChoice;
    printf("Choose test type:\n");
    printf("1. Predefined test\n");
    printf("2. Custom test\n");
    printf("Enter your choice: ");
    scanf("%d", &testChoice);
    clearInputBuffer();
    
    if (testChoice == 1) {
        printf("\nPredefined test - Peek at the first log entry:\n");
        
        // Test with a sample queue
        queue* logs = createSampleQueue();
        printf("Queue state:\n");
        printQueue(logs);
        
        printf("\nPeeking at the first log entry...\n");
        logEntry* log = Peek(logs);
        if (log != NULL) {
            printf("Peeked log: ID=%d, Message=\"%s\", Timestamp=\"%s\", Severity=%d\n",
                   log->ID, log->message, log->timestamp, log->severity);
        }
        
        printf("\nQueue after peeking (should be unchanged):\n");
        printQueue(logs);
        
        // Test with an empty queue
        queue* emptyLogs = initQueue();
        printf("\nAttempting to peek at an empty queue:\n");
        log = Peek(emptyLogs);
        if (log == NULL) {
            printf("Peek returned NULL as expected.\n");
        }
        
        freeQueue(logs);
        freeQueue(emptyLogs);
    } else if (testChoice == 2) {
        printf("\nCustom test - Peek at the first log entry:\n");
        printf("1. Test with a queue containing logs\n");
        printf("2. Test with an empty queue\n");
        printf("Enter your choice: ");
        int customChoice;
        scanf("%d", &customChoice);
        clearInputBuffer();
        
        if (customChoice == 1) {
            // Let user create a custom queue
            queue* logs = initQueue();
            int numLogs;
            printf("How many logs do you want to add before peeking? ");
            scanf("%d", &numLogs);
            clearInputBuffer();
            
            for (int i = 0; i < numLogs; i++) {
                int id, severity;
                char message[MAX_MESSAGE_SIZE];
                char timestamp[MAX_TIMESTAMP_SIZE];
                
                printf("\nLog #%d:\n", i+1);
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
                
                Enqueue(logs, id, message, timestamp, severity);
            }
            
            printf("\nQueue state:\n");
            printQueue(logs);
            
            printf("\nPeeking at the first log entry...\n");
            logEntry* log = Peek(logs);
            if (log != NULL) {
                printf("Peeked log: ID=%d, Message=\"%s\", Timestamp=\"%s\", Severity=%d\n",
                       log->ID, log->message, log->timestamp, log->severity);
            }
            
            printf("\nQueue after peeking (should be unchanged):\n");
            printQueue(logs);
            
            freeQueue(logs);
        } else if (customChoice == 2) {
            queue* logs = initQueue();
            printf("Empty queue state:\n");
            printQueue(logs);
            
            printf("\nAttempting to peek at an empty queue:\n");
            logEntry* log = Peek(logs);
            if (log == NULL) {
                printf("Peek returned NULL as expected.\n");
            }
            
            freeQueue(logs);
        }
    }
}

void testFreeQueue() {
    printf("\n=== Testing freeQueue ===\n");
    
    int testChoice;
    printf("Choose test type:\n");
    printf("1. Predefined test\n");
    printf("2. No custom test available (memory freeing is not visible)\n");
    printf("Enter your choice: ");
    scanf("%d", &testChoice);
    clearInputBuffer();
    
    if (testChoice == 1) {
        printf("\nPredefined test - Free a queue:\n");
        
        // Test with a sample queue
        queue* logs = createSampleQueue();
        printf("Queue before freeing:\n");
        printQueue(logs);
        
        printf("\nFreeing the queue...\n");
        freeQueue(logs);
        printf("Queue freed successfully.\n");
        printf("Note: Memory has been freed, but this is not directly observable in the output.\n");
        
        // Test with an empty queue
        printf("\nFreeing an empty queue...\n");
        queue* emptyLogs = initQueue();
        freeQueue(emptyLogs);
        printf("Empty queue freed successfully.\n");
    } else {
        printf("No custom test available for freeQueue (memory freeing is not visible).\n");
    }
}

void testPrintQueue() {
    printf("\n=== Testing printQueue ===\n");
    
    int testChoice;
    printf("Choose test type:\n");
    printf("1. Predefined test\n");
    printf("2. Custom test\n");
    printf("Enter your choice: ");
    scanf("%d", &testChoice);
    clearInputBuffer();
    
    if (testChoice == 1) {
        printf("\nPredefined test - Print a queue:\n");
        
        // Test with a sample queue
        queue* logs = createSampleQueue();
        printf("Printing a queue with multiple logs:\n");
        printQueue(logs);
        
        // Test with an empty queue
        queue* emptyLogs = initQueue();
        printf("\nPrinting an empty queue:\n");
        printQueue(emptyLogs);
        
        // Test with a queue with one log
        queue* singleLog = initQueue();
        Enqueue(singleLog, 1, "Single log entry", "2023-05-10 08:00:00", 1);
        printf("\nPrinting a queue with a single log:\n");
        printQueue(singleLog);
        
        freeQueue(logs);
        freeQueue(emptyLogs);
        freeQueue(singleLog);
    } else if (testChoice == 2) {
        printf("\nCustom test - Print a queue:\n");
        printf("1. Print an empty queue\n");
        printf("2. Create and print a custom queue\n");
        printf("Enter your choice: ");
        int customChoice;
        scanf("%d", &customChoice);
        clearInputBuffer();
        
        if (customChoice == 1) {
            queue* logs = initQueue();
            printf("Printing an empty queue:\n");
            printQueue(logs);
            freeQueue(logs);
        } else if (customChoice == 2) {
            queue* logs = initQueue();
            int numLogs;
            printf("How many logs do you want to add? ");
            scanf("%d", &numLogs);
            clearInputBuffer();
            
            for (int i = 0; i < numLogs; i++) {
                int id, severity;
                char message[MAX_MESSAGE_SIZE];
                char timestamp[MAX_TIMESTAMP_SIZE];
                
                printf("\nLog #%d:\n", i+1);
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
                
                Enqueue(logs, id, message, timestamp, severity);
            }
            
            printf("\nPrinting the custom queue:\n");
            printQueue(logs);
            freeQueue(logs);
        }
    }
}

// Main function with menu
int main() {
    int choice;
    
    while (1) {
        printf("\n=== Log Entry Queue Testing Menu ===\n");
        printf("1. Test initQueue\n");
        printf("2. Test isEmpty\n");
        printf("3. Test isFull\n");
        printf("4. Test Enqueue\n");
        printf("5. Test Dequeue\n");
        printf("6. Test Peek\n");
        printf("7. Test freeQueue\n");
        printf("8. Test printQueue\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();
        
        if (choice == 0) {
            break;
        }
        
        switch (choice) {
            case 1:
                testInitQueue();
                break;
            case 2:
                testIsEmpty();
                break;
            case 3:
                testIsFull();
                break;
            case 4:
                testEnqueue();
                break;
            case 5:
                testDequeue();
                break;
            case 6:
                testPeek();
                break;
            case 7:
                testFreeQueue();
                break;
            case 8:
                testPrintQueue();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    printf("Testing completed. Exiting...\n");
    return 0;
}
