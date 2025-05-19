#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stacks.h"

// Global stack
stack *logStack = NULL;

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
void printLogEntry(logEntry *log) {
    if (log == NULL) {
        printf("Log entry is NULL\n");
        return;
    }
    printf("ID: %d, Severity: %d, Timestamp: '%s', Message: '%s'\n", 
           log->ID, log->severity, log->timestamp, log->message);
}

// Function to create a predefined stack
void createPredefinedStack() {
    // Free existing stack if any
    if (logStack != NULL) {
        freeStack(logStack);
    }
    
    // Create a new stack
    logStack = initStack();
    if (!logStack) {
        printf("Error creating stack.\n");
        return;
    }
    
    // Push some predefined log entries
    pushLog(logStack, 1, "System startup", "2023-01-01 08:00:00", 1);
    pushLog(logStack, 2, "User login failed", "2023-01-01 08:15:30", 3);
    pushLog(logStack, 3, "Database connection established", "2023-01-01 08:30:45", 1);
    pushLog(logStack, 4, "Memory usage exceeds threshold", "2023-01-01 09:45:22", 2);
    pushLog(logStack, 5, "Critical error in module X", "2023-01-01 10:12:05", 5);
    
    printf("\nPredefined stack created successfully.\n");
    printf("The stack contains 5 log entries (Critical error is at the top).\n");
}

// Function to create a custom stack
void createCustomStack() {
    // Free existing stack if any
    if (logStack != NULL) {
        freeStack(logStack);
    }
    
    // Create a new stack
    logStack = initStack();
    if (!logStack) {
        printf("Error creating stack.\n");
        return;
    }
    
    int numLogs = getIntInput("How many log entries do you want to push? ");
    
    for (int i = 0; i < numLogs; i++) {
        printf("\nLog Entry #%d:\n", i+1);
        int id = getIntInput("Enter log ID: ");
        char message[MAX_MESSAGE_SIZE];
        getStringInput("Enter log message: ", message, sizeof(message));
        char timestamp[MAX_TIMESTAMP_SIZE];
        getStringInput("Enter timestamp: ", timestamp, sizeof(timestamp));
        int severity = getIntInput("Enter severity (1-5): ");
        
        pushLog(logStack, id, message, timestamp, severity);
    }
    
    printf("\nCustom stack created successfully with %d log entries.\n", numLogs);
}

// Test functions for each operation
void testInitStack() {
    printf("\n=== Testing initStack ===\n");
    
    // Free existing stack if any
    if (logStack != NULL) {
        freeStack(logStack);
    }
    
    logStack = initStack();
    
    if (logStack) {
        printf("Stack initialized successfully.\n");
        printf("Stack is %s.\n", isEmpty(logStack) ? "empty" : "not empty");
    } else {
        printf("Error initializing stack.\n");
    }
}

void testIsFull() {
    printf("\n=== Testing isFull ===\n");
    
    if (logStack == NULL) {
        printf("Stack is not initialized. Please create a stack first.\n");
        return;
    }
    
    printf("Stack is %s.\n", isFull(logStack) ? "full" : "not full");
    printf("Current stack size: %d/%d\n", logStack->top + 1, MAX_STACK_SIZE);
}

void testIsEmpty() {
    printf("\n=== Testing isEmpty ===\n");
    
    if (logStack == NULL) {
        printf("Stack is not initialized. Please create a stack first.\n");
        return;
    }
    
    printf("Stack is %s.\n", isEmpty(logStack) ? "empty" : "not empty");
    printf("Current stack size: %d/%d\n", logStack->top + 1, MAX_STACK_SIZE);
}

void testPrintStack() {
    printf("\n=== Testing printStack ===\n");
    
    if (logStack == NULL) {
        printf("Stack is not initialized. Please create a stack first.\n");
        return;
    }
    
    if (isEmpty(logStack)) {
        printf("Stack is empty.\n");
        return;
    }
    
    printf("Stack contents (from bottom to top):\n");
    printStack(logStack);
}

void testPushLog() {
    printf("\n=== Testing pushLog ===\n");
    
    if (logStack == NULL) {
        printf("Stack is not initialized. Please create a stack first.\n");
        return;
    }
    
    if (isFull(logStack)) {
        printf("Stack is full. Cannot push more logs.\n");
        return;
    }
    
    int id = getIntInput("Enter log ID: ");
    char message[MAX_MESSAGE_SIZE];
    getStringInput("Enter log message: ", message, sizeof(message));
    char timestamp[MAX_TIMESTAMP_SIZE];
    getStringInput("Enter timestamp: ", timestamp, sizeof(timestamp));
    int severity = getIntInput("Enter severity (1-5): ");
    
    pushLog(logStack, id, message, timestamp, severity);
    printf("Log entry pushed successfully.\n");
    printf("Current stack size: %d/%d\n", logStack->top + 1, MAX_STACK_SIZE);
}

void testPopLog() {
    printf("\n=== Testing popLog ===\n");
    
    if (logStack == NULL) {
        printf("Stack is not initialized. Please create a stack first.\n");
        return;
    }
    
    if (isEmpty(logStack)) {
        printf("Stack is empty. Cannot pop.\n");
        return;
    }
    
    logEntry *poppedLog = popLog(logStack);
    
    if (poppedLog) {
        printf("Popped log entry:\n");
        printLogEntry(poppedLog);
        printf("Current stack size: %d/%d\n", logStack->top + 1, MAX_STACK_SIZE);
        
        // Free the popped entry
        free(poppedLog);
    }
}

void testPeekLog() {
    printf("\n=== Testing peekLog ===\n");
    
    if (logStack == NULL) {
        printf("Stack is not initialized. Please create a stack first.\n");
        return;
    }
    
    if (isEmpty(logStack)) {
        printf("Stack is empty. Cannot peek.\n");
        return;
    }
    
    logEntry *topLog = peekLog(logStack);
    
    if (topLog) {
        printf("Top log entry (without popping):\n");
        printLogEntry(topLog);
    }
}

void testInsertAtBottom() {
    printf("\n=== Testing insertAtBottom ===\n");
    
    if (logStack == NULL) {
        printf("Stack is not initialized. Please create a stack first.\n");
        return;
    }
    
    if (isFull(logStack)) {
        printf("Stack is full. Cannot insert more logs.\n");
        return;
    }
    
    int id = getIntInput("Enter log ID: ");
    char message[MAX_MESSAGE_SIZE];
    getStringInput("Enter log message: ", message, sizeof(message));
    char timestamp[MAX_TIMESTAMP_SIZE];
    getStringInput("Enter timestamp: ", timestamp, sizeof(timestamp));
    int severity = getIntInput("Enter severity (1-5): ");
    
    // Create a new log entry
    logEntry *newLog = (logEntry *)malloc(sizeof(logEntry));
    if (!newLog) {
        printf("Error allocating memory for log entry.\n");
        return;
    }
    
    newLog->ID = id;
    newLog->severity = severity;
    strncpy(newLog->message, message, MAX_MESSAGE_SIZE-1);
    newLog->message[MAX_MESSAGE_SIZE-1] = '\0';
    strncpy(newLog->timestamp, timestamp, MAX_TIMESTAMP_SIZE-1);
    newLog->timestamp[MAX_TIMESTAMP_SIZE-1] = '\0';
    
    printf("\nStack before insertion at bottom:\n");
    printStack(logStack);
    
    insertAtBottom(logStack, newLog);
    
    printf("\nStack after insertion at bottom:\n");
    printStack(logStack);
}

void testReverseLogsStack() {
    printf("\n=== Testing ReverseLogsStack ===\n");
    
    if (logStack == NULL) {
        printf("Stack is not initialized. Please create a stack first.\n");
        return;
    }
    
    if (isEmpty(logStack)) {
        printf("Stack is empty. Nothing to reverse.\n");
        return;
    }
    
    printf("\nStack before reversal:\n");
    printStack(logStack);
    
    ReverseLogsStack(logStack);
    
    printf("\nStack after reversal:\n");
    printStack(logStack);
}

void testFreeStack() {
    printf("\n=== Testing freeStack ===\n");
    
    if (logStack == NULL) {
        printf("Stack is not initialized. Nothing to free.\n");
        return;
    }
    
    printf("Freeing stack with %d entries...\n", logStack->top + 1);
    freeStack(logStack);
    logStack = NULL;
    printf("Stack freed successfully.\n");
}

// Main function with menu
int main() {
    int choice;
    
    // First, choose between predefined or custom stack
    printf("=== Log Stack Testing ===\n");
    printf("Choose a stack to work with:\n");
    printf("1. Use a predefined stack\n");
    printf("2. Create your own stack\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    clearInputBuffer();
    
    if (choice == 1) {
        createPredefinedStack();
    } else if (choice == 2) {
        createCustomStack();
    } else {
        printf("Invalid choice. Exiting...\n");
        return 1;
    }
    
    // Now show the function selection menu
    while (1) {
        printf("\n=== Log Stack Testing Menu ===\n");
        printf("1. Test initStack (create a new stack)\n");
        printf("2. Test isFull\n");
        printf("3. Test isEmpty\n");
        printf("4. Test printStack\n");
        printf("5. Test pushLog\n");
        printf("6. Test popLog\n");
        printf("7. Test peekLog\n");
        printf("8. Test insertAtBottom\n");
        printf("9. Test ReverseLogsStack\n");
        printf("10. Test freeStack\n");
        printf("11. Create a predefined stack\n");
        printf("12. Create a custom stack\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();
        
        if (choice == 0) {
            break;
        }
        
        switch (choice) {
            case 1:
                testInitStack();
                break;
            case 2:
                testIsFull();
                break;
            case 3:
                testIsEmpty();
                break;
            case 4:
                testPrintStack();
                break;
            case 5:
                testPushLog();
                break;
            case 6:
                testPopLog();
                break;
            case 7:
                testPeekLog();
                break;
            case 8:
                testInsertAtBottom();
                break;
            case 9:
                testReverseLogsStack();
                break;
            case 10:
                testFreeStack();
                break;
            case 11:
                createPredefinedStack();
                break;
            case 12:
                createCustomStack();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    // Free the stack before exiting
    if (logStack != NULL) {
        freeStack(logStack);
    }
    
    printf("Testing completed. Exiting...\n");
    return 0;
}
