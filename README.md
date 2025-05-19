# **PART 1:**
## **Module 1: Linked Linear Lists**
## Insert Functions

🔧 **Function Name:**
InsertLogEntryAtStart

📁 **Module:**
linkedlists.c / linkedlists.h

📌 **Purpose:**
Insert a log entry at the beginning of a singly linked list.

🧠 **Description:**
This function creates a new log entry and adds it to the beginning of the linked list. It dynamically allocates memory for a new node, fills in the provided log details, and sets it as the new head of the list.

⚙️ **Prototype:**

```c
void InsertLogEntryAtStart(LogEntry **head, int id, char *message, char *timestamp, int severity);
```

🔢 **Parameters:**

```plaintext
| Name      | Type       | Description                       |
|-----------|------------|-----------------------------------|
| head      | LogEntry** | Pointer to the head of the list   |
| id        | int        | Unique identifier for the log     |
| message   | char*      | Message content of the log        |
| timestamp | char*      | Date and time of the log          |
| severity  | int        | Severity level of the log         |
```

🔁 **Return:**
void – No return value. Modifies the list through the head pointer.

🚩 **Pre-conditions:**

- The list should be initialized (head can be NULL if empty).
- Memory allocation must be successful.
- message and timestamp strings must be valid.


✅ **Post-conditions:**

- A new node is added at the beginning of the list.
- The head pointer now points to the new node.


💡 **Example Usage:**

```c
InsertLogEntryAtStart(&head, 1, "Memory usage high", "2025-05-18 12:00", 2);
```

🧪 **Edge Cases / Notes:**

- If malloc fails, the function may crash; consider adding error handling.
- The function uses strncpy to prevent buffer overflows.


---

🔧 **Function Name:**
InsertLogEntryAtEnd

📁 **Module:**
linkedlists.c / linkedlists.h

📌 **Purpose:**
Insert a log entry at the end of a singly linked list.

🧠 **Description:**
This function appends a new log entry to the end of the linked list. It dynamically allocates memory for a new node, fills in the provided log details, and traverses the list to attach the node at the last position.

⚙️ **Prototype:**

```c
void InsertLogEntryAtEnd(LogEntry **head, int id, char *message, char *timestamp, int severity);
```

🔢 **Parameters:**

```plaintext
| Name      | Type       | Description                       |
|-----------|------------|-----------------------------------|
| head      | LogEntry** | Pointer to the head of the list   |
| id        | int        | Unique identifier for the log     |
| message   | char*      | Message content of the log        |
| timestamp | char*      | Date and time of the log          |
| severity  | int        | Severity level of the log         |
```

🔁 **Return:**
void – No return value. Modifies the list through the head pointer.

🚩 **Pre-conditions:**

- The list should be initialized (head can be NULL if empty).
- Memory allocation must be successful.
- message and timestamp strings must be valid.


✅ **Post-conditions:**

- A new node is added at the end of the list.
- If the list was empty, the head now points to the new node.


💡 **Example Usage:**

```c
InsertLogEntryAtEnd(&head, 2, "Database connection lost", "2025-05-18 12:30", 1);
```

🧪 **Edge Cases / Notes:**

- If the list is empty, the new node becomes the head.
- If malloc fails, the function may crash; consider adding error handling.
- The function uses strncpy to prevent buffer overflows.


---

🔧 **Function Name:**
InsertLogEntryAtPosition

📁 **Module:**
linkedlists.c / linkedlists.h

📌 **Purpose:**
Insert a log entry at a specific position in a singly linked list.

🧠 **Description:**
This function inserts a new log entry at a specified position in the linked list. It dynamically allocates memory for a new node, fills in the provided log details, and traverses the list to the desired position before inserting the node.

⚙️ **Prototype:**

```c
void InsertLogEntryAtPosition(LogEntry **head, int id, char *message, char *timestamp, int severity, int pos);
```

🔢 **Parameters:**

```plaintext
| Name      | Type       | Description                       |
|-----------|------------|-----------------------------------|
| head      | LogEntry** | Pointer to the head of the list   |
| id        | int        | Unique identifier for the log     |
| message   | char*      | Message content of the log        |
| timestamp | char*      | Date and time of the log          |
| severity  | int        | Severity level of the log         |
| pos       | int        | Position to insert (1-indexed)    |
```

🔁 **Return:**
void – No return value. Modifies the list through the head pointer.

🚩 **Pre-conditions:**

- The list should be initialized (head can be NULL if empty).
- Position must be valid (≥ 1).
- If list is empty, position must be 1.
- Memory allocation must be successful.


✅ **Post-conditions:**

- A new node is added at the specified position in the list.
- If position is 1, the head now points to the new node.


💡 **Example Usage:**

```c
InsertLogEntryAtPosition(&head, 3, "User login failed", "2025-05-18 13:00", 3, 2);
```

🧪 **Edge Cases / Notes:**

- Handles special cases for insertion at the beginning.
- Provides error messages for invalid positions.
- If the position is beyond the end of the list, an error message is displayed.
- The function uses strncpy to prevent buffer overflows.


## Delete Functions

🔧 **Function Name:**
DeleteLogById

📁 **Module:**
linkedlists.c / linkedlists.h

📌 **Purpose:**
Delete a log entry with a specific ID from the linked list.

🧠 **Description:**
This function searches for a log entry with the specified ID and removes it from the linked list. It handles special cases for deleting the head node and provides feedback if the ID is not found.

⚙️ **Prototype:**

```c
void DeleteLogById(LogEntry **head, int id);
```

🔢 **Parameters:**

```plaintext
| Name | Type       | Description                     |
|------|------------|---------------------------------|
| head | LogEntry** | Pointer to the head of the list |
| id   | int        | ID of the log entry to delete   |
```

🔁 **Return:**
void – No return value. Modifies the list through the head pointer.

🚩 **Pre-conditions:**

- The list should be initialized (head can be NULL if empty).


✅ **Post-conditions:**

- If a log with the specified ID is found, it is removed from the list and its memory is freed.
- If the deleted node was the head, the head pointer is updated.


💡 **Example Usage:**

```c
DeleteLogById(&head, 2);
```

🧪 **Edge Cases / Notes:**

- Handles empty list case with an error message.
- Handles special case for deleting the head node.
- Provides feedback if the ID is not found.
- Only deletes the first occurrence of the ID if duplicates exist.


---

🔧 **Function Name:**
DeleteLogByTimestamp

📁 **Module:**
linkedlists.c / linkedlists.h

📌 **Purpose:**
Delete all log entries with a specific timestamp from the linked list.

🧠 **Description:**
This function searches for log entries with the specified timestamp and removes them from the linked list. It handles special cases for deleting the head node and provides feedback if no matching timestamps are found.

⚙️ **Prototype:**

```c
void DeleteLogByTimestamp(LogEntry **head, char *timestamp);
```

🔢 **Parameters:**

```plaintext
| Name      | Type       | Description                           |
|-----------|------------|---------------------------------------|
| head      | LogEntry** | Pointer to the head of the list       |
| timestamp | char*      | Timestamp of the log entries to delete|
```

🔁 **Return:**
void – No return value. Modifies the list through the head pointer.

🚩 **Pre-conditions:**

- The list should be initialized (head can be NULL if empty).
- timestamp string must be valid.


✅ **Post-conditions:**

- All logs with the specified timestamp are removed from the list and their memory is freed.
- If a deleted node was the head, the head pointer is updated.


💡 **Example Usage:**

```c
DeleteLogByTimestamp(&head, "2025-05-18 12:00");
```

🧪 **Edge Cases / Notes:**

- Handles empty list case with an error message.
- Handles special case for deleting the head node.
- Provides feedback if no matching timestamps are found.
- Can delete multiple entries with the same timestamp.


---

🔧 **Function Name:**
DeleteFirstLog

📁 **Module:**
linkedlists.c / linkedlists.h

📌 **Purpose:**
Delete the first log entry (head) from the linked list.

🧠 **Description:**
This function removes the first node from the linked list and updates the head pointer. It silently returns if the list is empty.

⚙️ **Prototype:**

```c
void DeleteFirstLog(LogEntry **head);
```

🔢 **Parameters:**

```plaintext
| Name | Type       | Description                     |
|------|------------|---------------------------------|
| head | LogEntry** | Pointer to the head of the list |
```

🔁 **Return:**
void – No return value. Modifies the list through the head pointer.

🚩 **Pre-conditions:**

- The list should be initialized (head can be NULL if empty).


✅ **Post-conditions:**

- If the list was not empty, the first node is removed and its memory is freed.
- The head pointer is updated to point to the second node (or NULL if the list becomes empty).


💡 **Example Usage:**

```c
DeleteFirstLog(&head);
```

🧪 **Edge Cases / Notes:**

- Silently returns if the list is empty.
- Does not provide feedback on success or failure.


---

🔧 **Function Name:**
DeleteLastLog

📁 **Module:**
linkedlists.c / linkedlists.h

📌 **Purpose:**
Delete the last log entry from the linked list.

🧠 **Description:**
This function removes the last node from the linked list. It handles special cases for empty lists and lists with only one node.

⚙️ **Prototype:**

```c
void DeleteLastLog(LogEntry **head);
```

🔢 **Parameters:**

```plaintext
| Name | Type       | Description                     |
|------|------------|---------------------------------|
| head | LogEntry** | Pointer to the head of the list |
```

🔁 **Return:**
void – No return value. Modifies the list through the head pointer.

🚩 **Pre-conditions:**

- The list should be initialized (head can be NULL if empty).


✅ **Post-conditions:**

- If the list was not empty, the last node is removed and its memory is freed.
- If the list had only one node, the head is set to NULL.


💡 **Example Usage:**

```c
DeleteLastLog(&head);
```

🧪 **Edge Cases / Notes:**

- Silently returns if the list is empty.
- Handles the special case when the list has only one node.
- Does not provide feedback on success or failure.


## Search Functions

🔧 **Function Name:**
searchLogByID

📁 **Module:**
linkedlists.c / linkedlists.h

📌 **Purpose:**
Search for a log entry with a specific ID in the linked list.

🧠 **Description:**
This function traverses the linked list to find a log entry with the specified ID. It returns a pointer to the found node or NULL if not found, with appropriate error messages.

⚙️ **Prototype:**

```c
LogEntry *searchLogByID(LogEntry *head, int id);
```

🔢 **Parameters:**

```plaintext
| Name | Type      | Description                     |
|------|-----------|---------------------------------|
| head | LogEntry* | Pointer to the head of the list |
| id   | int       | ID of the log entry to search   |
```

🔁 **Return:**
LogEntry* – Pointer to the found log entry, or NULL if not found.

🚩 **Pre-conditions:**

- The list should be initialized (head can be NULL if empty).


✅ **Post-conditions:**

- No modification to the list structure.
- Returns a pointer to the found node or NULL.


💡 **Example Usage:**

```c
LogEntry *foundLog = searchLogByID(head, 3);
if (foundLog) {
    printf("Found log: %s\n", foundLog->message);
}
```

🧪 **Edge Cases / Notes:**

- Handles empty list case with an error message.
- Provides feedback if the ID is not found.
- Returns NULL in both error cases (empty list or ID not found).
- Only finds the first occurrence of the ID if duplicates exist.


---

🔧 **Function Name:**
searchLogByKeyword

📁 **Module:**
linkedlists.c / linkedlists.h

📌 **Purpose:**
Search for a log entry containing a specific keyword in its message.

🧠 **Description:**
This function traverses the linked list to find a log entry whose message contains the specified keyword. The search is case-insensitive. It returns a pointer to the first matching node or NULL if not found, with appropriate error messages.

⚙️ **Prototype:**

```c
LogEntry *searchLogByKeyword(LogEntry *head, char *keyword);
```

🔢 **Parameters:**

```plaintext
| Name    | Type      | Description                           |
|---------|-----------|---------------------------------------|
| head    | LogEntry* | Pointer to the head of the list       |
| keyword | char*     | Keyword to search for in log messages |
```

🔁 **Return:**
LogEntry* – Pointer to the first log entry containing the keyword, or NULL if not found.

🚩 **Pre-conditions:**

- The list should be initialized (head can be NULL if empty).
- keyword string must be valid.


✅ **Post-conditions:**

- No modification to the list structure.
- Returns a pointer to the first matching node or NULL.
- Dynamically allocated memory for lowercase conversions is freed.


💡 **Example Usage:**

```c
LogEntry *foundLog = searchLogByKeyword(head, "error");
if (foundLog) {
    printf("Found log with error: %s\n", foundLog->message);
}
```

🧪 **Edge Cases / Notes:**

- Handles empty list case with an error message.
- Provides feedback if no matching logs are found.
- The search is case-insensitive.
- Only returns the first matching log entry.
- Uses dynamic memory allocation for case conversion, which is properly freed.


---

🔧 **Function Name:**
searchLogByTimestamp

📁 **Module:**
linkedlists.c / linkedlists.h

📌 **Purpose:**
Search for a log entry containing a specific timestamp or partial timestamp.

🧠 **Description:**
This function traverses the linked list to find a log entry whose timestamp contains the specified timestamp string. The search is case-insensitive and supports partial matches. It returns a pointer to the first matching node or NULL if not found, with appropriate error messages.

⚙️ **Prototype:**

```c
LogEntry *searchLogByTimestamp(LogEntry *head, char *timestamp);
```

🔢 **Parameters:**

```plaintext
| Name      | Type      | Description                                |
|-----------|-----------|-------------------------------------------|
| head      | LogEntry* | Pointer to the head of the list           |
| timestamp | char*     | Timestamp (or partial timestamp) to search|
```

🔁 **Return:**
LogEntry* – Pointer to the first log entry containing the timestamp, or NULL if not found.

🚩 **Pre-conditions:**

- The list should be initialized (head can be NULL if empty).
- timestamp string must be valid.


✅ **Post-conditions:**

- No modification to the list structure.
- Returns a pointer to the first matching node or NULL.
- Dynamically allocated memory for lowercase conversions is freed.


💡 **Example Usage:**

```c
LogEntry *foundLog = searchLogByTimestamp(head, "2025-05-18");
if (foundLog) {
    printf("Found log from May 18: %s\n", foundLog->message);
}
```

🧪 **Edge Cases / Notes:**

- Handles empty list case with an error message.
- Provides feedback if no matching logs are found.
- The search is case-insensitive.
- Supports partial timestamp matches (e.g., searching for just the date).
- Only returns the first matching log entry.
- Uses dynamic memory allocation for case conversion, which is properly freed.


## Sort Functions

🔧 **Function Name:**
SortBySeverity

📁 **Module:**
linkedlists.c / linkedlists.h

📌 **Purpose:**
Sort the linked list of log entries by severity level in ascending order.

🧠 **Description:**
This function implements a selection sort algorithm to sort the linked list by severity level. It swaps the data of nodes rather than rearranging the nodes themselves, which is more efficient for linked lists.

⚙️ **Prototype:**

```c
void SortBySeverity(LogEntry **head);
```

🔢 **Parameters:**

```plaintext
| Name | Type       | Description                     |
|------|------------|---------------------------------|
| head | LogEntry** | Pointer to the head of the list |
```

🔁 **Return:**
void – No return value. Modifies the list by rearranging node data.

🚩 **Pre-conditions:**

- The list should be initialized (head can be NULL if empty).


✅ **Post-conditions:**

- The list is sorted by severity level in ascending order.
- The physical structure of the list (node pointers) remains unchanged.
- Only the data within nodes is swapped.


💡 **Example Usage:**

```c
SortBySeverity(&head);
printLogs(head); // Now logs are sorted by severity
```

🧪 **Edge Cases / Notes:**

- Silently returns if the list is empty or has only one node.
- Uses selection sort algorithm, which has O(n²) time complexity.
- Swaps node data rather than rearranging pointers, which is more efficient for linked lists.


---

🔧 **Function Name:**
SortByTimestamp

📁 **Module:**
linkedlists.c / linkedlists.h

📌 **Purpose:**
Sort the linked list of log entries by timestamp in chronological order.

🧠 **Description:**
This function implements a selection sort algorithm to sort the linked list by timestamp. It compares timestamps lexicographically and swaps the data of nodes rather than rearranging the nodes themselves.

⚙️ **Prototype:**

```c
void SortByTimestamp(LogEntry **head);
```

🔢 **Parameters:**

```plaintext
| Name | Type       | Description                     |
|------|------------|---------------------------------|
| head | LogEntry** | Pointer to the head of the list |
```

🔁 **Return:**
void – No return value. Modifies the list by rearranging node data.

🚩 **Pre-conditions:**

- The list should be initialized (head can be NULL if empty).
- Timestamps should be in a consistent format for proper sorting.


✅ **Post-conditions:**

- The list is sorted by timestamp in chronological order.
- The physical structure of the list (node pointers) remains unchanged.
- Only the data within nodes is swapped.


💡 **Example Usage:**

```c
SortByTimestamp(&head);
printLogs(head); // Now logs are sorted chronologically
```

🧪 **Edge Cases / Notes:**

- Silently returns if the list is empty or has only one node.
- Uses selection sort algorithm, which has O(n²) time complexity.
- Assumes timestamps are in a format where lexicographical comparison yields chronological order.
- Swaps node data rather than rearranging pointers, which is more efficient for linked lists.


## Other Functions

🔧 **Function Name:**
reverseLogs

📁 **Module:**
linkedlists.c / linkedlists.h

📌 **Purpose:**
Reverse the order of nodes in the linked list to view logs in reverse order.

🧠 **Description:**
This function reverses the linked list by changing the direction of pointers. It uses an iterative approach with three pointers to track the previous, current, and next nodes during traversal.

⚙️ **Prototype:**

```c
void reverseLogs(LogEntry **head);
```

🔢 **Parameters:**

```plaintext
| Name | Type       | Description                     |
|------|------------|---------------------------------|
| head | LogEntry** | Pointer to the head of the list |
```

🔁 **Return:**
void – No return value. Modifies the list structure by reversing node pointers.

🚩 **Pre-conditions:**

- The list should be initialized (head can be NULL if empty).


✅ **Post-conditions:**

- The list is reversed, with the original tail becoming the new head.
- The head pointer is updated to point to the new head (former tail).


💡 **Example Usage:**

```c
reverseLogs(&head);
printLogs(head); // Now logs are in reverse order
```

🧪 **Edge Cases / Notes:**

- Silently returns if the list is empty or has only one node.
- Uses an iterative approach with O(n) time complexity.
- Modifies the actual structure of the list by changing node pointers.


---

🔧 **Function Name:**
CountLogs

📁 **Module:**
linkedlists.c / linkedlists.h

📌 **Purpose:**
Count the total number of log entries in the linked list.

🧠 **Description:**
This function traverses the linked list and counts the number of nodes. It provides a simple way to determine the size of the log history.

⚙️ **Prototype:**

```c
int CountLogs(LogEntry *head);
```

🔢 **Parameters:**

```plaintext
| Name | Type      | Description                     |
|------|-----------|---------------------------------|
| head | LogEntry* | Pointer to the head of the list |
```

🔁 **Return:**
int – The number of log entries in the list.

🚩 **Pre-conditions:**

- The list should be initialized (head can be NULL if empty).


✅ **Post-conditions:**

- No modification to the list structure.
- Returns the count of nodes in the list.


💡 **Example Usage:**

```c
int logCount = CountLogs(head);
printf("Total logs: %d\n", logCount);
```

🧪 **Edge Cases / Notes:**

- Returns 0 for an empty list.
- Has O(n) time complexity as it must traverse the entire list.


---

🔧 **Function Name:**
printLogs

📁 **Module:**
linkedlists.c / linkedlists.h

📌 **Purpose:**
Print all log entries in the linked list to the console.

🧠 **Description:**
This function traverses the linked list and prints the details of each log entry, including ID, message, timestamp, and severity level.

⚙️ **Prototype:**

```c
void printLogs(LogEntry *head);
```

🔢 **Parameters:**

```plaintext
| Name | Type      | Description                     |
|------|-----------|---------------------------------|
| head | LogEntry* | Pointer to the head of the list |
```

🔁 **Return:**
void – No return value. Outputs log information to the console.

🚩 **Pre-conditions:**

- The list should be initialized (head can be NULL if empty).


✅ **Post-conditions:**

- No modification to the list structure.
- Log details are printed to the console.


💡 **Example Usage:**

```c
printLogs(head);
```

🧪 **Edge Cases / Notes:**

- Silently does nothing if the list is empty.
- Has O(n) time complexity as it must traverse the entire list.


## Helper Functions

🔧 **Function Name:**
toLowerCase

📁 **Module:**
linkedlists.c / linkedlists.h

📌 **Purpose:**
Convert a string to lowercase for case-insensitive comparisons.

🧠 **Description:**
This function creates a new string that is a lowercase version of the input string. It allocates memory for the new string and converts each uppercase character to its lowercase equivalent.

⚙️ **Prototype:**

```c
char *toLowerCase(const char *str);
```

🔢 **Parameters:**

```plaintext
| Name | Type        | Description                      |
|------|-------------|----------------------------------|
| str  | const char* | Input string to convert to lowercase |
```

🔁 **Return:**
char* – A newly allocated string containing the lowercase version of the input.

🚩 **Pre-conditions:**

- str should be a valid C string or NULL.
- Memory allocation must be successful.


✅ **Post-conditions:**

- A new string is allocated and returned.
- The caller is responsible for freeing the returned string.


💡 **Example Usage:**

```c
char *lowerStr = toLowerCase("Hello World");
printf("%s\n", lowerStr); // prints "hello world"
free(lowerStr);
```

🧪 **Edge Cases / Notes:**

- Returns NULL if the input string is NULL.
- Returns NULL if memory allocation fails.
- Only converts ASCII uppercase letters (A-Z) to lowercase.
- The caller must free the returned string to avoid memory leaks.


---

🔧 **Function Name:**
SwapLogData

📁 **Module:**
linkedlists.c / linkedlists.h

📌 **Purpose:**
Swap the data between two log entry nodes.

🧠 **Description:**
This function swaps the data (ID, message, timestamp, severity) between two log entry nodes without changing the structure of the linked list. It's used by the sorting functions to rearrange log entries.

⚙️ **Prototype:**

```c
void SwapLogData(LogEntry *node1, LogEntry *node2);
```

🔢 **Parameters:**

```plaintext
| Name  | Type      | Description          |
|-------|-----------|----------------------|
| node1 | LogEntry* | First log entry node |
| node2 | LogEntry* | Second log entry node|
```

🔁 **Return:**
void – No return value. Modifies the data in the provided nodes.

🚩 **Pre-conditions:**

- Both node1 and node2 should be valid LogEntry pointers.


✅ **Post-conditions:**

- The data of node1 and node2 are swapped.
- The structure of the linked list remains unchanged.


💡 **Example Usage:**

```c
SwapLogData(head, head->next); // Swap data between first and second nodes
```

🧪 **Edge Cases / Notes:**

- Uses a temporary variable to perform the swap.
- Only swaps the data, not the node pointers.
- Assumes both nodes are valid (no NULL checking).



## **Module 2 : Bidirectional Linked Lists

## 🔧 Function Name: insertAtBeginning

📁 **Module**: bidirectionalLinkedLists.c / bidirectionalLinkedLists.h

📌 **Purpose**: Insert a log entry at the beginning of a bidirectional linked list.

🧠 **Description**: This function creates a new node with the provided log details and inserts it at the beginning of the bidirectional linked list. It properly updates the previous and next pointers to maintain the bidirectional nature of the list.

⚙️ **Prototype**:

```c
void insertAtBeginning(Node** head, Node** tail, int id, char* timestamp, char* LOG, char* message);
```

🔢 **Parameters**:

```plaintext
| Name      | Type     |
|-----------|----------|
| head      | Node**   |
| tail      | Node**   |
| id        | int      |
| timestamp | char*    |
| LOG       | char*    |
| message   | char*    |
```

🔁 **Return**:

- `void` – No return value. Modifies the list through the head and tail pointers.


🚩 **Pre-conditions**:

- head and tail pointers must be initialized (can point to NULL for empty list).
- Memory allocation must be successful.
- The timestamp, LOG, and message strings must be valid null-terminated strings.


✅ **Post-conditions**:

- A new node is added at the beginning of the list.
- The head pointer is updated to point to the new node.
- If the list was empty, the tail pointer is also updated to point to the new node.


💡 **Example Usage**:

```c
Node* head = NULL;
Node* tail = NULL;
insertAtBeginning(&head, &tail, 1, "2025-05-18 12:00:00", "WARNING", "System startup");
```

🧪 **Edge Cases / Notes**:

- If the list is empty (head is NULL), both head and tail will point to the new node.
- The function handles the bidirectional nature of the list by properly setting the prev and next pointers.


## 🔧 Function Name: insertAtEnd

📁 **Module**: bidirectionalLinkedLists.c / bidirectionalLinkedLists.h

📌 **Purpose**: Insert a log entry at the end of a bidirectional linked list.

🧠 **Description**: This function creates a new node with the provided log details and appends it to the end of the bidirectional linked list. It properly updates the previous and next pointers to maintain the bidirectional nature of the list.

⚙️ **Prototype**:

```c
void insertAtEnd(Node** head, Node** tail, int id, char* timestamp, char* LOG, char* message);
```

🔢 **Parameters**:

```plaintext
| Name      | Type     |
|-----------|----------|
| head      | Node**   |
| tail      | Node**   |
| id        | int      |
| timestamp | char*    |
| LOG       | char*    |
| message   | char*    |
```

🔁 **Return**:

- `void` – No return value. Modifies the list through the head and tail pointers.


🚩 **Pre-conditions**:

- head and tail pointers must be initialized (can point to NULL for empty list).
- Memory allocation must be successful.
- The timestamp, LOG, and message strings must be valid null-terminated strings.


✅ **Post-conditions**:

- A new node is added at the end of the list.
- The tail pointer is updated to point to the new node.
- If the list was empty, the head pointer is also updated to point to the new node.


💡 **Example Usage**:

```c
Node* head = NULL;
Node* tail = NULL;
insertAtEnd(&head, &tail, 1, "2025-05-18 12:00:00", "WARNING", "System startup");
```

🧪 **Edge Cases / Notes**:

- If the list is empty (tail is NULL), both head and tail will point to the new node.
- The function handles the bidirectional nature of the list by properly setting the prev and next pointers.


## 🔧 Function Name: insertAtPosition

📁 **Module**: bidirectionalLinkedLists.c / bidirectionalLinkedLists.h

📌 **Purpose**: Insert a log entry at a specific position in a bidirectional linked list.

🧠 **Description**: This function creates a new node with the provided log details and inserts it at the specified position in the bidirectional linked list. If the position is 0 or the list is empty, it inserts at the beginning. If the position is beyond the end of the list, it inserts at the end.

⚙️ **Prototype**:

```c
void insertAtPosition(Node** head, Node** tail, int id, char* timestamp, char* LOG, char* message, int position);
```

🔢 **Parameters**:

```plaintext
| Name      | Type     |
|-----------|----------|
| head      | Node**   |
| tail      | Node**   |
| id        | int      |
| timestamp | char*    |
| LOG       | char*    |
| message   | char*    |
| position  | int      |
```

🔁 **Return**:

- `void` – No return value. Modifies the list through the head and tail pointers.


🚩 **Pre-conditions**:

- head and tail pointers must be initialized (can point to NULL for empty list).
- Memory allocation must be successful.
- The timestamp, LOG, and message strings must be valid null-terminated strings.
- position must be a non-negative integer.


✅ **Post-conditions**:

- A new node is added at the specified position in the list.
- If position is 0 or the list is empty, the node is inserted at the beginning.
- If position is beyond the end of the list, the node is inserted at the end.
- The bidirectional links are properly maintained.


💡 **Example Usage**:

```c
Node* head = NULL;
Node* tail = NULL;
insertAtEnd(&head, &tail, 1, "2025-05-18 12:00:00", "WARNING", "First log");
insertAtEnd(&head, &tail, 3, "2025-05-18 12:10:00", "ERROR", "Third log");
insertAtPosition(&head, &tail, 2, "2025-05-18 12:05:00", "INFO", "Second log", 1);
```

🧪 **Edge Cases / Notes**:

- The function handles special cases: insertion at the beginning (position 0 or empty list) and insertion at the end (position >= list length).
- For insertion in the middle, it properly updates the bidirectional links of adjacent nodes.


## 🔧 Function Name: deleteByID

📁 **Module**: bidirectionalLinkedLists.c / bidirectionalLinkedLists.h

📌 **Purpose**: Delete a log entry with a specific ID from a bidirectional linked list.

🧠 **Description**: This function searches for a node with the specified ID in the bidirectional linked list and removes it. It properly updates the previous and next pointers of adjacent nodes to maintain the bidirectional nature of the list.

⚙️ **Prototype**:

```c
void deleteByID(Node** head, Node** tail, int id);
```

🔢 **Parameters**:

```plaintext
| Name | Type     |
|------|----------|
| head | Node**   |
| tail | Node**   |
| id   | int      |
```

🔁 **Return**:

- `void` – No return value. Modifies the list through the head and tail pointers.


🚩 **Pre-conditions**:

- head and tail pointers must be initialized (can point to NULL for empty list).


✅ **Post-conditions**:

- If a node with the specified ID is found, it is removed from the list.
- The head and/or tail pointers are updated if necessary.
- The bidirectional links of adjacent nodes are properly maintained.
- Memory for the deleted node is freed.


💡 **Example Usage**:

```c
deleteByID(&head, &tail, 2); // Delete the log entry with ID 2
```

🧪 **Edge Cases / Notes**:

- If the list is empty (head is NULL), the function returns without doing anything.
- If no node with the specified ID is found, the function returns without modifying the list.
- The function handles special cases: deletion of the only node, deletion of the head node, and deletion of the tail node.


## 🔧 Function Name: deleteByTimestamp

📁 **Module**: bidirectionalLinkedLists.c / bidirectionalLinkedLists.h

📌 **Purpose**: Delete a log entry with a specific timestamp from a bidirectional linked list.

🧠 **Description**: This function searches for a node with the specified timestamp in the bidirectional linked list and removes it. It properly updates the previous and next pointers of adjacent nodes to maintain the bidirectional nature of the list.

⚙️ **Prototype**:

```c
void deleteByTimestamp(Node** head, Node** tail, char* timestamp);
```

🔢 **Parameters**:

```plaintext
| Name      | Type     |
|-----------|----------|
| head      | Node**   |
| tail      | Node**   |
| timestamp | char*    |
```

🔁 **Return**:

- `void` – No return value. Modifies the list through the head and tail pointers.


🚩 **Pre-conditions**:

- head and tail pointers must be initialized (can point to NULL for empty list).
- The timestamp string must be a valid null-terminated string.


✅ **Post-conditions**:

- If a node with the specified timestamp is found, it is removed from the list.
- The head and/or tail pointers are updated if necessary.
- The bidirectional links of adjacent nodes are properly maintained.
- Memory for the deleted node is freed.


💡 **Example Usage**:

```c
deleteByTimestamp(&head, &tail, "2025-05-18 12:05:00"); // Delete the log entry with this timestamp
```

🧪 **Edge Cases / Notes**:

- If the list is empty (head is NULL), the function returns without doing anything.
- If no node with the specified timestamp is found, the function returns without modifying the list.
- The function handles special cases: deletion of the only node, deletion of the head node, and deletion of the tail node.


## 🔧 Function Name: deleteFirst

📁 **Module**: bidirectionalLinkedLists.c / bidirectionalLinkedLists.h

📌 **Purpose**: Delete the first log entry from a bidirectional linked list.

🧠 **Description**: This function removes the first node (head) from the bidirectional linked list. It properly updates the head pointer and the previous pointer of the new head node to maintain the bidirectional nature of the list.

⚙️ **Prototype**:

```c
void deleteFirst(Node** head, Node** tail);
```

🔢 **Parameters**:

```plaintext
| Name | Type     |
|------|----------|
| head | Node**   |
| tail | Node**   |
```

🔁 **Return**:

- `void` – No return value. Modifies the list through the head and tail pointers.


🚩 **Pre-conditions**:

- head and tail pointers must be initialized (can point to NULL for empty list).


✅ **Post-conditions**:

- If the list is not empty, the first node is removed.
- The head pointer is updated to point to the second node (or NULL if the list becomes empty).
- If the list had only one node, both head and tail are set to NULL.
- Memory for the deleted node is freed.


💡 **Example Usage**:

```c
deleteFirst(&head, &tail); // Delete the first log entry in the list
```

🧪 **Edge Cases / Notes**:

- If the list is empty (head is NULL), the function returns without doing anything.
- If the list has only one node, both head and tail are set to NULL after deletion.
- The function properly handles the bidirectional nature of the list by updating the prev pointer of the new head node.


## 🔧 Function Name: deleteLast

📁 **Module**: bidirectionalLinkedLists.c / bidirectionalLinkedLists.h

📌 **Purpose**: Delete the last log entry from a bidirectional linked list.

🧠 **Description**: This function removes the last node (tail) from the bidirectional linked list. It properly updates the tail pointer and the next pointer of the new tail node to maintain the bidirectional nature of the list.

⚙️ **Prototype**:

```c
void deleteLast(Node** head, Node** tail);
```

🔢 **Parameters**:

```plaintext
| Name | Type     |
|------|----------|
| head | Node**   |
| tail | Node**   |
```

🔁 **Return**:

- `void` – No return value. Modifies the list through the head and tail pointers.


🚩 **Pre-conditions**:

- head and tail pointers must be initialized (can point to NULL for empty list).


✅ **Post-conditions**:

- If the list is not empty, the last node is removed.
- The tail pointer is updated to point to the second-to-last node (or NULL if the list becomes empty).
- If the list had only one node, both head and tail are set to NULL.
- Memory for the deleted node is freed.


💡 **Example Usage**:

```c
deleteLast(&head, &tail); // Delete the last log entry in the list
```

🧪 **Edge Cases / Notes**:

- If the list is empty (tail is NULL), the function returns without doing anything.
- If the list has only one node, both head and tail are set to NULL after deletion.
- The function properly handles the bidirectional nature of the list by updating the next pointer of the new tail node.


## 🔧 Function Name: searchByID

📁 **Module**: bidirectionalLinkedLists.c / bidirectionalLinkedLists.h

📌 **Purpose**: Search for a log entry with a specific ID in a bidirectional linked list.

🧠 **Description**: This function traverses the bidirectional linked list to find a node with the specified ID. It returns a pointer to the node if found.

⚙️ **Prototype**:

```c
Node* searchByID(Node* head, int id);
```

🔢 **Parameters**:

```plaintext
| Name | Type     |
|------|----------|
| head | Node*    |
| id   | int      |
```

🔁 **Return**:

- `Node*` – Pointer to the node with the specified ID, or NULL if not found.


🚩 **Pre-conditions**:

- The head pointer must be initialized (can be NULL for empty list).


✅ **Post-conditions**:

- No changes to the list structure.


💡 **Example Usage**:

```c
Node* foundLog = searchByID(head, 2); // Find the log entry with ID 2
if (foundLog != NULL) {
    printf("Found log: %s\n", foundLog->message);
}
```

🧪 **Edge Cases / Notes**:

- The function performs a linear search through the list.
- The function assumes that the ID exists in the list; if not, it may lead to undefined behavior.
- A more robust implementation would check for NULL during traversal.


## 🔧 Function Name: searchByKeyword

📁 **Module**: bidirectionalLinkedLists.c / bidirectionalLinkedLists.h

📌 **Purpose**: Search for a log entry with a specific keyword in the LOG field.

🧠 **Description**: This function traverses the bidirectional linked list to find a node with the specified keyword in its LOG field. It returns a pointer to the node if found.

⚙️ **Prototype**:

```c
Node* searchByKeyword(Node* head, char* keyword);
```

🔢 **Parameters**:

```plaintext
| Name    | Type     |
|---------|----------|
| head    | Node*    |
| keyword | char*    |
```

🔁 **Return**:

- `Node*` – Pointer to the first node with the specified keyword in its LOG field, or NULL if not found.


🚩 **Pre-conditions**:

- The head pointer must be initialized (can be NULL for empty list).
- The keyword string must be a valid null-terminated string.


✅ **Post-conditions**:

- No changes to the list structure.


💡 **Example Usage**:

```c
Node* foundLog = searchByKeyword(head, "ERROR"); // Find the first log entry with "ERROR" in its LOG field
if (foundLog != NULL) {
    printf("Found error log: %s\n", foundLog->message);
}
```

🧪 **Edge Cases / Notes**:

- The function performs a linear search through the list.
- The function returns NULL if the list is empty or if no node with the specified keyword is found.
- The function only finds the first occurrence of the keyword.


## 🔧 Function Name: searchByTimestamp

📁 **Module**: bidirectionalLinkedLists.c / bidirectionalLinkedLists.h

📌 **Purpose**: Search for a log entry with a specific timestamp.

🧠 **Description**: This function traverses the bidirectional linked list to find a node with the specified timestamp. It returns a pointer to the node if found.

⚙️ **Prototype**:

```c
Node* searchByTimestamp(Node* head, char* timestamp);
```

🔢 **Parameters**:

```plaintext
| Name      | Type     |
|-----------|----------|
| head      | Node*    |
| timestamp | char*    |
```

🔁 **Return**:

- `Node*` – Pointer to the node with the specified timestamp, or NULL if not found.


🚩 **Pre-conditions**:

- The head pointer must be initialized (can be NULL for empty list).
- The timestamp string must be a valid null-terminated string.


✅ **Post-conditions**:

- No changes to the list structure.


💡 **Example Usage**:

```c
Node* foundLog = searchByTimestamp(head, "2025-05-18 12:05:00"); // Find the log entry with this timestamp
if (foundLog != NULL) {
    printf("Found log: %s\n", foundLog->message);
}
```

🧪 **Edge Cases / Notes**:

- The function performs a linear search through the list.
- The function returns NULL if the list is empty or if no node with the specified timestamp is found.
- The function assumes timestamps are unique; if multiple nodes have the same timestamp, it returns the first one found.


## 🔧 Function Name: sortByDate

📁 **Module**: bidirectionalLinkedLists.c / bidirectionalLinkedLists.h

📌 **Purpose**: Sort the bidirectional linked list by timestamp.

🧠 **Description**: This function sorts the bidirectional linked list in ascending order based on the timestamp field of each node. It uses a merge sort algorithm for efficient sorting.

⚙️ **Prototype**:

```c
void sortByDate(Node** head);
```

🔢 **Parameters**:

```plaintext
| Name | Type     |
|------|----------|
| head | Node**   |
```

🔁 **Return**:

- `void` – No return value. Modifies the list through the head pointer.


🚩 **Pre-conditions**:

- The head pointer must be initialized (can point to NULL for empty list).
- The timestamp fields must be in a format that allows lexicographical comparison (e.g., "YYYY-MM-DD HH:MM:SS").


✅ **Post-conditions**:

- The list is sorted in ascending order by timestamp.
- The bidirectional links are properly maintained.


💡 **Example Usage**:

```c
sortByDate(&head); // Sort the list by timestamp
```

🧪 **Edge Cases / Notes**:

- The function uses merge sort, which has O(n log n) time complexity.
- The function maintains the bidirectional nature of the list during sorting.
- The tail pointer is not updated by this function; it should be recalculated after sorting if needed.


## 🔧 Function Name: sortBySeverity

📁 **Module**: bidirectionalLinkedLists.c / bidirectionalLinkedLists.h

📌 **Purpose**: Sort the bidirectional linked list by severity (LOG field).

🧠 **Description**: This function sorts the bidirectional linked list in ascending order based on the LOG field of each node. It uses a merge sort algorithm for efficient sorting.

⚙️ **Prototype**:

```c
void sortBySeverity(Node** head);
```

🔢 **Parameters**:

```plaintext
| Name | Type     |
|------|----------|
| head | Node**   |
```

🔁 **Return**:

- `void` – No return value. Modifies the list through the head pointer.


🚩 **Pre-conditions**:

- The head pointer must be initialized (can point to NULL for empty list).


✅ **Post-conditions**:

- The list is sorted in ascending order by the LOG field (severity).
- The bidirectional links are properly maintained.


💡 **Example Usage**:

```c
sortBySeverity(&head); // Sort the list by severity (LOG field)
```

🧪 **Edge Cases / Notes**:

- The function uses merge sort, which has O(n log n) time complexity.
- The function maintains the bidirectional nature of the list during sorting.
- The tail pointer is not updated by this function; it should be recalculated after sorting if needed.
- The function assumes that the LOG field represents severity and can be compared lexicographically.


## 🔧 Function Name: reverseList

📁 **Module**: bidirectionalLinkedLists.c / bidirectionalLinkedLists.h

📌 **Purpose**: Reverse the order of nodes in a bidirectional linked list.

🧠 **Description**: This function reverses the order of nodes in the bidirectional linked list by swapping the next and prev pointers of each node. It also swaps the head and tail pointers.

⚙️ **Prototype**:

```c
void reverseList(Node** head, Node** tail);
```

🔢 **Parameters**:

```plaintext
| Name | Type     |
|------|----------|
| head | Node**   |
| tail | Node**   |
```

🔁 **Return**:

- `void` – No return value. Modifies the list through the head and tail pointers.


🚩 **Pre-conditions**:

- head and tail pointers must be initialized (can point to NULL for empty list).


✅ **Post-conditions**:

- The order of nodes in the list is reversed.
- The head and tail pointers are swapped.
- The bidirectional links are properly maintained.


💡 **Example Usage**:

```c
reverseList(&head, &tail); // Reverse the order of nodes in the list
```

🧪 **Edge Cases / Notes**:

- If the list is empty or has only one node, the function has no effect.
- The function properly handles the bidirectional nature of the list by swapping the next and prev pointers of each node.


## 🔧 Function Name: countLogs

📁 **Module**: bidirectionalLinkedLists.c / bidirectionalLinkedLists.h

📌 **Purpose**: Count the number of log entries in a bidirectional linked list.

🧠 **Description**: This function traverses the bidirectional linked list and counts the number of nodes.

⚙️ **Prototype**:

```c
int countLogs(Node* head);
```

🔢 **Parameters**:

```plaintext
| Name | Type     |
|------|----------|
| head | Node*    |
```

🔁 **Return**:

- `int` – The number of nodes in the list.


🚩 **Pre-conditions**:

- The head pointer must be initialized (can be NULL for empty list).


✅ **Post-conditions**:

- No changes to the list structure.


💡 **Example Usage**:

```c
int logCount = countLogs(head); // Count the number of log entries in the list
printf("Number of logs: %d\n", logCount);
```

🧪 **Edge Cases / Notes**:

- If the list is empty (head is NULL), the function returns 0.
- The function performs a linear traversal of the list, so it has O(n) time complexity.


## 🔧 Function Name: traverseForward

📁 **Module**: bidirectionalLinkedLists.c / bidirectionalLinkedLists.h

📌 **Purpose**: Traverse and print the bidirectional linked list from head to tail.

🧠 **Description**: This function traverses the bidirectional linked list from the head to the tail and prints the information of each node (ID, message, LOG, timestamp).

⚙️ **Prototype**:

```c
void traverseForward(Node* head);
```

🔢 **Parameters**:

```plaintext
| Name | Type     |
|------|----------|
| head | Node*    |
```

🔁 **Return**:

- `void` – No return value.


🚩 **Pre-conditions**:

- The head pointer must be initialized (can be NULL for empty list).


✅ **Post-conditions**:

- No changes to the list structure.
- The information of each node is printed to the standard output.


💡 **Example Usage**:

```c
traverseForward(head); // Print all log entries from head to tail
```

🧪 **Edge Cases / Notes**:

- If the list is empty (head is NULL), the function does not print anything.
- The function uses the next pointers to traverse the list from head to tail.
- The output format for each node is: "[ID: id, message: message, LOG: LOG, timestamp: timestamp] `<--->` "


## 🔧 Function Name: traverseBackward

📁 **Module**: bidirectionalLinkedLists.c / bidirectionalLinkedLists.h

📌 **Purpose**: Traverse and print the bidirectional linked list from tail to head.

🧠 **Description**: This function traverses the bidirectional linked list from the tail to the head and prints the information of each node (ID, message, LOG, timestamp).

⚙️ **Prototype**:

```c
void traverseBackward(Node* tail);
```

🔢 **Parameters**:

```plaintext
| Name | Type     |
|------|----------|
| tail | Node*    |
```

🔁 **Return**:

- `void` – No return value.


🚩 **Pre-conditions**:

- The tail pointer must be initialized (can be NULL for empty list).


✅ **Post-conditions**:

- No changes to the list structure.
- The information of each node is printed to the standard output.


💡 **Example Usage**:

```c
traverseBackward(tail); // Print all log entries from tail to head
```

🧪 **Edge Cases / Notes**:

- If the list is empty (tail is NULL), the function does not print anything.
- The function uses the prev pointers to traverse the list from tail to head.
- The output format for each node is: "[ID: id, message: message, LOG: LOG, timestamp: timestamp] `<--->` "


## 🔧 Function Name: deleteAtIndex

📁 **Module**: bidirectionalLinkedLists.c / bidirectionalLinkedLists.h

📌 **Purpose**: Delete a log entry at a specific index in a bidirectional linked list.

🧠 **Description**: This function removes the node at the specified index from the bidirectional linked list. It properly updates the previous and next pointers of adjacent nodes to maintain the bidirectional nature of the list.

⚙️ **Prototype**:

```c
void deleteAtIndex(Node** head, Node** tail, int index);
```

🔢 **Parameters**:

```plaintext
| Name  | Type     |
|-------|----------|
| head  | Node**   |
| tail  | Node**   |
| index | int      |
```

🔁 **Return**:

- `void` – No return value. Modifies the list through the head and tail pointers.


🚩 **Pre-conditions**:

- head and tail pointers must be initialized (can point to NULL for empty list).
- index must be a non-negative integer less than the length of the list.


✅ **Post-conditions**:

- If the index is valid, the node at that index is removed from the list.
- The head and/or tail pointers are updated if necessary.
- The bidirectional links of adjacent nodes are properly maintained.
- Memory for the deleted node is freed.


💡 **Example Usage**:

```c
deleteAtIndex(&head, &tail, 1); // Delete the log entry at index 1 (second node)
```

🧪 **Edge Cases / Notes**:

- If the list is empty (head is NULL), the function returns without doing anything.
- If the index is out of range (negative or >= list length), the function returns without modifying the list.
- The function handles special cases: deletion of the head node (index 0) and deletion of the tail node (index == list length - 1).


## 🔧 Function Name: mergeLogLists

📁 **Module**: bidirectionalLinkedLists.c / bidirectionalLinkedLists.h

📌 **Purpose**: Merge two bidirectional linked lists of log entries.

🧠 **Description**: This function combines two bidirectional linked lists by appending the second list to the end of the first list. It properly updates the bidirectional links between the last node of the first list and the first node of the second list.

⚙️ **Prototype**:

```c
Node* mergeLogLists(Node* list1, Node* list2);
```

🔢 **Parameters**:

```plaintext
| Name  | Type     |
|-------|----------|
| list1 | Node*    |
| list2 | Node*    |
```

🔁 **Return**:

- `Node*` – Pointer to the head of the merged list.


🚩 **Pre-conditions**:

- list1 and list2 must be valid bidirectional linked lists (can be NULL for empty lists).


✅ **Post-conditions**:

- If both lists are non-empty, list2 is appended to the end of list1.
- The bidirectional links between the last node of list1 and the first node of list2 are properly established.
- The original list1 and list2 pointers are not modified, but the internal structure of the lists is changed.


💡 **Example Usage**:

```c
Node* mergedList = mergeLogLists(list1, list2); // Merge list2 into list1
```

🧪 **Edge Cases / Notes**:

- If list1 is NULL, the function returns list2.
- If list2 is NULL, the function returns list1.
- The function assumes that both lists are properly initialized bidirectional linked lists.
- The tail pointer of the merged list is not returned; it should be recalculated if needed.


## **Module 3: Circular Linked Lists**

## 🔧 Function Name: insertAtBeginning

📁 **Module**: circularLists.c / circularLists.h

📌 **Purpose**: Insert a log entry at the beginning of a circular linked list.

🧠 **Description**: This function creates a new node with the provided log details and inserts it at the beginning of the circular linked list. It properly updates the previous and next pointers to maintain the circular nature of the list.

⚙️ **Prototype**:

```c
void insertAtBeginning(Node** head, Node** tail, int id, char* timestamp, char* LOG, char* message);
```

🔢 **Parameters**:

```plaintext
| Name      | Type     |
|-----------|----------|
| head      | Node**   |
| tail      | Node**   |
| id        | int      |
| timestamp | char*    |
| LOG       | char*    |
| message   | char*    |
```

🔁 **Return**:

- `void` – No return value. Modifies the list through the head and tail pointers.


🚩 **Pre-conditions**:

- head and tail pointers must be initialized (can point to NULL for empty list).
- Memory allocation must be successful.
- The timestamp, LOG, and message strings must be valid null-terminated strings.


✅ **Post-conditions**:

- A new node is added at the beginning of the list.
- The head pointer is updated to point to the new node.
- If the list was empty, both head and tail point to the new node, and the node's next and prev pointers point to itself.
- If the list was not empty, the circular links are properly maintained.


💡 **Example Usage**:

```c
Node* head = NULL;
Node* tail = NULL;
insertAtBeginning(&head, &tail, 1, "2025-05-18 12:00:00", "WARNING", "System startup");
```

🧪 **Edge Cases / Notes**:

- If the list is empty (head is NULL), the new node becomes both the head and tail, with its next and prev pointers pointing to itself.
- The function handles the circular nature of the list by properly setting the prev and next pointers.


## 🔧 Function Name: insertAtEnd

📁 **Module**: circularLists.c / circularLists.h

📌 **Purpose**: Insert a log entry at the end of a circular linked list.

🧠 **Description**: This function creates a new node with the provided log details and appends it to the end of the circular linked list. It properly updates the previous and next pointers to maintain the circular nature of the list.

⚙️ **Prototype**:

```c
void insertAtEnd(Node** head, Node** tail, int id, char* timestamp, char* LOG, char* message);
```

🔢 **Parameters**:

```plaintext
| Name      | Type     |
|-----------|----------|
| head      | Node**   |
| tail      | Node**   |
| id        | int      |
| timestamp | char*    |
| LOG       | char*    |
| message   | char*    |
```

🔁 **Return**:

- `void` – No return value. Modifies the list through the head and tail pointers.


🚩 **Pre-conditions**:

- head and tail pointers must be initialized (can point to NULL for empty list).
- Memory allocation must be successful.
- The timestamp, LOG, and message strings must be valid null-terminated strings.


✅ **Post-conditions**:

- A new node is added at the end of the list.
- The tail pointer is updated to point to the new node.
- If the list was empty, both head and tail point to the new node, and the node's next and prev pointers point to itself.
- If the list was not empty, the circular links are properly maintained.


💡 **Example Usage**:

```c
Node* head = NULL;
Node* tail = NULL;
insertAtEnd(&head, &tail, 1, "2025-05-18 12:00:00", "WARNING", "System startup");
```

🧪 **Edge Cases / Notes**:

- If the list is empty (head is NULL), the new node becomes both the head and tail, with its next and prev pointers pointing to itself.
- The function handles the circular nature of the list by properly setting the prev and next pointers.


## 🔧 Function Name: traverseForward

📁 **Module**: circularLists.c / circularLists.h

📌 **Purpose**: Traverse and print the circular linked list in forward direction.

🧠 **Description**: This function traverses the circular linked list from the head node and prints the information of each node (ID, message, LOG, timestamp) until it reaches the head node again.

⚙️ **Prototype**:

```c
void traverseForward(Node* head);
```

🔢 **Parameters**:

```plaintext
| Name | Type     |
|------|----------|
| head | Node*    |
```

🔁 **Return**:

- `void` – No return value.


🚩 **Pre-conditions**:

- The head pointer must be initialized (can be NULL for empty list).


✅ **Post-conditions**:

- No changes to the list structure.
- The information of each node is printed to the standard output.


💡 **Example Usage**:

```c
traverseForward(head); // Print all log entries in forward direction
```

🧪 **Edge Cases / Notes**:

- If the list is empty (head is NULL), the function returns without printing anything.
- The function uses a do-while loop to ensure that it traverses the entire circular list exactly once.
- The output format for each node is: "[ID: id, message: message, LOG: LOG, timestamp: timestamp] `<->` "
- The function indicates the completion of the circular traversal with "(Back to Head)".


## 🔧 Function Name: traverseBackward

📁 **Module**: circularLists.c / circularLists.h

📌 **Purpose**: Traverse and print the circular linked list in backward direction.

🧠 **Description**: This function traverses the circular linked list from the tail node and prints the information of each node (ID, message, LOG, timestamp) until it reaches the tail node again.

⚙️ **Prototype**:

```c
void traverseBackward(Node* tail);
```

🔢 **Parameters**:

```plaintext
| Name | Type     |
|------|----------|
| tail | Node*    |
```

🔁 **Return**:

- `void` – No return value.


🚩 **Pre-conditions**:

- The tail pointer must be initialized (can be NULL for empty list).


✅ **Post-conditions**:

- No changes to the list structure.
- The information of each node is printed to the standard output.


💡 **Example Usage**:

```c
traverseBackward(tail); // Print all log entries in backward direction
```

🧪 **Edge Cases / Notes**:

- If the list is empty (tail is NULL), the function returns without printing anything.
- The function uses a do-while loop to ensure that it traverses the entire circular list exactly once.
- The output format for each node is: "[ID: id, message: message, LOG: LOG, timestamp: timestamp] `<->` "
- The function indicates the completion of the circular traversal with "(Back to Tail)".


## 🔧 Function Name: deleteByID

📁 **Module**: circularLists.c / circularLists.h

📌 **Purpose**: Delete a log entry with a specific ID from a circular linked list.

🧠 **Description**: This function searches for a node with the specified ID in the circular linked list and removes it. It properly updates the previous and next pointers of adjacent nodes to maintain the circular nature of the list.

⚙️ **Prototype**:

```c
void deleteByID(Node** head, Node** tail, int id);
```

🔢 **Parameters**:

```plaintext
| Name | Type     |
|------|----------|
| head | Node**   |
| tail | Node**   |
| id   | int      |
```

🔁 **Return**:

- `void` – No return value. Modifies the list through the head and tail pointers.


🚩 **Pre-conditions**:

- head and tail pointers must be initialized (can point to NULL for empty list).


✅ **Post-conditions**:

- If a node with the specified ID is found, it is removed from the list.
- The head and/or tail pointers are updated if necessary.
- The circular links of adjacent nodes are properly maintained.
- Memory for the deleted node is freed.


💡 **Example Usage**:

```c
deleteByID(&head, &tail, 2); // Delete the log entry with ID 2
```

🧪 **Edge Cases / Notes**:

- If the list is empty (head is NULL), the function returns without doing anything.
- If no node with the specified ID is found, the function traverses the entire list and returns without modifying it.
- The function handles special cases: deletion of the only node, deletion of the head node, and deletion of the tail node.
- The function uses a do-while loop to ensure that it searches the entire circular list.


## 🔧 Function Name: countLogs

📁 **Module**: circularLists.c / circularLists.h

📌 **Purpose**: Count the number of log entries in a circular linked list.

🧠 **Description**: This function traverses the circular linked list and counts the number of nodes.

⚙️ **Prototype**:

```c
int countLogs(Node* head);
```

🔢 **Parameters**:

```plaintext
| Name | Type     |
|------|----------|
| head | Node*    |
```

🔁 **Return**:

- `int` – The number of nodes in the list.


🚩 **Pre-conditions**:

- The head pointer must be initialized (can be NULL for empty list).


✅ **Post-conditions**:

- No changes to the list structure.


💡 **Example Usage**:

```c
int logCount = countLogs(head); // Count the number of log entries in the list
printf("Number of logs: %d\n", logCount);
```

🧪 **Edge Cases / Notes**:

- If the list is empty (head is NULL), the function returns 0.
- The function uses a do-while loop to ensure that it counts each node in the circular list exactly once.
- The function has O(n) time complexity, where n is the number of nodes in the list.


## 🔧 Function Name: insertLog

📁 **Module**: circularLists.c / circularLists.h

📌 **Purpose**: Insert a log entry into a fixed-size circular buffer, overwriting old logs if necessary.

🧠 **Description**: This function implements a fixed-size log buffer using a circular linked list. If the buffer has not reached its maximum size, it adds a new log entry at the end. If the buffer is full, it overwrites the oldest log entry (at the head) and advances the head pointer.

⚙️ **Prototype**:

```c
void insertLog(Node** head, Node** tail, int id, char* timestamp, char* LOG, char* message, int maxSize, int* currentSize);
```

🔢 **Parameters**:

```plaintext
| Name        | Type     |
|-------------|----------|
| head        | Node**   |
| tail        | Node**   |
| id          | int      |
| timestamp   | char*    |
| LOG         | char*    |
| message     | char*    |
| maxSize     | int      |
| currentSize | int*     |
```

🔁 **Return**:

- `void` – No return value. Modifies the list through the head and tail pointers.


🚩 **Pre-conditions**:

- head and tail pointers must be initialized (can point to NULL for empty list).
- Memory allocation must be successful when adding a new node.
- The timestamp, LOG, and message strings must be valid null-terminated strings.
- maxSize must be a positive integer.
- currentSize must point to a valid integer that tracks the current number of logs.


✅ **Post-conditions**:

- If currentSize <= maxSize, a new log entry is added at the end of the list.
- If currentSize > maxSize, the oldest log entry (at the head) is overwritten with the new log data, and the head pointer is advanced.
- The circular links are properly maintained.


💡 **Example Usage**:

```c
int currentSize = 0;
int maxSize = 5; // Maximum of 5 logs in the buffer
insertLog(&head, &tail, 1, "2025-05-18 12:00:00", "WARNING", "System startup", maxSize, &currentSize);
```

🧪 **Edge Cases / Notes**:

- If the head pointer is NULL, the function prints an error message and returns.
- The function implements a circular buffer behavior, where the oldest logs are automatically overwritten when the buffer is full.
- The function does not update the currentSize parameter; this should be managed by the caller.
- There appears to be a bug in the implementation: the function does not check if currentSize is less than maxSize, but rather if currentSize is less than or equal to maxSize.


## 🔧 Function Name: detectCycle

📁 **Module**: circularLists.c / circularLists.h

📌 **Purpose**: Detect if a linked list contains a cycle.

🧠 **Description**: This function uses Floyd's Cycle-Finding Algorithm (also known as the "tortoise and hare" algorithm) to detect if a linked list contains a cycle. It uses two pointers, one moving at normal speed and one moving at twice the speed, to determine if they ever meet.

⚙️ **Prototype**:

```c
int detectCycle(Node* head);
```

🔢 **Parameters**:

```plaintext
| Name | Type     |
|------|----------|
| head | Node*    |
```

🔁 **Return**:

- `int` – Returns 1 if a cycle is detected, 0 otherwise.


🚩 **Pre-conditions**:

- The head pointer must be initialized (can be NULL for empty list).


✅ **Post-conditions**:

- No changes to the list structure.


💡 **Example Usage**:

```c
if (detectCycle(head)) {
    printf("The list contains a cycle, which is expected for a circular linked list.\n");
} else {
    printf("Warning: The list does not contain a cycle. It may be corrupted.\n");
}
```

🧪 **Edge Cases / Notes**:

- The function is designed to detect cycles in a linked list, which is a normal property of a circular linked list.
- For a properly formed circular linked list, this function should always return 1.
- The function uses Floyd's Cycle-Finding Algorithm, which has O(n) time complexity and O(1) space complexity.
- There appears to be a bug in the implementation: the function does not check if fast or fast->next is NULL before advancing, which could lead to a segmentation fault.


## 🔧 Function Name: searchByID

📁 **Module**: circularLists.c / circularLists.h

📌 **Purpose**: Search for a log entry with a specific ID in a circular linked list.

🧠 **Description**: This function traverses the circular linked list to find a node with the specified ID. It returns a pointer to the node if found, or NULL if not found.

⚙️ **Prototype**:

```c
Node* searchByID(Node* head, int id);
```

🔢 **Parameters**:

```plaintext
| Name | Type     |
|------|----------|
| head | Node*    |
| id   | int      |
```

🔁 **Return**:

- `Node*` – Pointer to the node with the specified ID, or NULL if not found.


🚩 **Pre-conditions**:

- The head pointer must be initialized (can be NULL for empty list).


✅ **Post-conditions**:

- No changes to the list structure.


💡 **Example Usage**:

```c
Node* foundLog = searchByID(head, 2); // Find the log entry with ID 2
if (foundLog != NULL) {
    printf("Found log: %s\n", foundLog->message);
}
```

🧪 **Edge Cases / Notes**:

- If the list is empty (head is NULL), the function returns NULL.
- The function uses a do-while loop to ensure that it searches the entire circular list.
- If no node with the specified ID is found after traversing the entire list, the function returns NULL.


## 🔧 Function Name: searchByTimestamp

📁 **Module**: circularLists.c / circularLists.h

📌 **Purpose**: Search for a log entry with a specific timestamp in a circular linked list.

🧠 **Description**: This function traverses the circular linked list to find a node with the specified timestamp. It returns a pointer to the node if found, or NULL if not found.

⚙️ **Prototype**:

```c
Node* searchByTimestamp(Node* head, char* timestamp);
```

🔢 **Parameters**:

```plaintext
| Name      | Type     |
|-----------|----------|
| head      | Node*    |
| timestamp | char*    |
```

🔁 **Return**:

- `Node*` – Pointer to the node with the specified timestamp, or NULL if not found.


🚩 **Pre-conditions**:

- The head pointer must be initialized (can be NULL for empty list).
- The timestamp string must be a valid null-terminated string.


✅ **Post-conditions**:

- No changes to the list structure.


💡 **Example Usage**:

```c
Node* foundLog = searchByTimestamp(head, "2025-05-18 12:00:00"); // Find the log entry with this timestamp
if (foundLog != NULL) {
    printf("Found log: %s\n", foundLog->message);
}
```

🧪 **Edge Cases / Notes**:

- If the list is empty (head is NULL), the function returns NULL.
- The function uses a do-while loop to ensure that it searches the entire circular list.
- If no node with the specified timestamp is found after traversing the entire list, the function returns NULL.
- The function uses strcmp to compare timestamps, which performs an exact match.


## 🔧 Function Name: searchByKeyword

📁 **Module**: circularLists.c / circularLists.h

📌 **Purpose**: Search for a log entry containing a specific keyword in its message.

🧠 **Description**: This function traverses the circular linked list to find a node with a message containing the specified keyword. It returns a pointer to the first matching node if found, or NULL if not found.

⚙️ **Prototype**:

```c
Node* searchByKeyword(Node* head, char* keyword);
```

🔢 **Parameters**:

```plaintext
| Name    | Type     |
|---------|----------|
| head    | Node*    |
| keyword | char*    |
```

🔁 **Return**:

- `Node*` – Pointer to the first node containing the keyword in its message, or NULL if not found.


🚩 **Pre-conditions**:

- The head pointer must be initialized (can be NULL for empty list).
- The keyword string must be a valid null-terminated string.


✅ **Post-conditions**:

- No changes to the list structure.


💡 **Example Usage**:

```c
Node* foundLog = searchByKeyword(head, "error"); // Find the first log entry with "error" in its message
if (foundLog != NULL) {
    printf("Found log with error: %s\n", foundLog->message);
}
```

🧪 **Edge Cases / Notes**:

- If the list is empty (head is NULL), the function returns NULL.
- The function uses a do-while loop to ensure that it searches the entire circular list.
- If no node with a message containing the keyword is found after traversing the entire list, the function returns NULL.
- The function uses strstr to search for the keyword within the message, which performs a substring search.


## 🔧 Function Name: reverseList

📁 **Module**: circularLists.c / circularLists.h

📌 **Purpose**: Reverse the order of nodes in a circular linked list.

🧠 **Description**: This function reverses the order of nodes in the circular linked list by swapping the next and prev pointers of each node. It also swaps the head and tail pointers.

⚙️ **Prototype**:

```c
void reverseList(Node** head, Node** tail);
```

🔢 **Parameters**:

```plaintext
| Name | Type     |
|------|----------|
| head | Node**   |
| tail | Node**   |
```

🔁 **Return**:

- `void` – No return value. Modifies the list through the head and tail pointers.


🚩 **Pre-conditions**:

- head and tail pointers must be initialized (can point to NULL for empty list).


✅ **Post-conditions**:

- The order of nodes in the list is reversed.
- The head and tail pointers are swapped.
- The circular links are properly maintained.


💡 **Example Usage**:

```c
reverseList(&head, &tail); // Reverse the order of nodes in the list
```

🧪 **Edge Cases / Notes**:

- If the list is empty (head is NULL) or has only one node (head->next == head), the function returns without making any changes.
- The function properly handles the circular nature of the list by swapping the next and prev pointers of each node.
- The function uses a do-while loop to ensure that it processes each node in the circular list exactly once.


## **Module 4 : Queues**

## 🔧 Function Name: initQueue

📁 **Module**: queues.c / queues.h

📌 **Purpose**: Initialize a new circular queue for log entries.

🧠 **Description**: This function creates and initializes a new queue structure for storing log entries. It dynamically allocates memory for the queue structure and sets the initial values for head, tail, and size.

⚙️ **Prototype**:

```c
queue *initQueue();
```

🔢 **Parameters**: None

🔁 **Return**:

- `queue*` – Pointer to the newly created and initialized queue.


🚩 **Pre-conditions**:

- Memory allocation must be successful.


✅ **Post-conditions**:

- A new queue is created with head = 0, tail = -1, and size = 0.


💡 **Example Usage**:

```c
queue *logQueue = initQueue();
```

🧪 **Edge Cases / Notes**:

- If malloc fails, the function may return NULL; consider checking the return value.


## 🔧 Function Name: isEmpty

📁 **Module**: queues.c / queues.h

📌 **Purpose**: Check if the queue is empty.

🧠 **Description**: This function determines whether the queue contains any log entries by checking if the size is zero.

⚙️ **Prototype**:

```c
bool isEmpty(queue *logs);
```

🔢 **Parameters**:

```plaintext
| Name | Type    |
|------|---------|
| logs | queue*  |
```

🔁 **Return**:

- `bool` – Returns true if the queue is empty, false otherwise.


🚩 **Pre-conditions**:

- The queue must be initialized.


✅ **Post-conditions**:

- No changes to the queue.


💡 **Example Usage**:

```c
if (isEmpty(logQueue)) {
    printf("No logs available.\n");
}
```

🧪 **Edge Cases / Notes**:

- The function assumes the queue pointer is valid.


## 🔧 Function Name: isFull

📁 **Module**: queues.c / queues.h

📌 **Purpose**: Check if the queue is full.

🧠 **Description**: This function determines whether the queue has reached its maximum capacity by checking if the size equals the maximum allowed size.

⚙️ **Prototype**:

```c
bool isFull(queue *logs);
```

🔢 **Parameters**:

```plaintext
| Name | Type    |
|------|---------|
| logs | queue*  |
```

🔁 **Return**:

- `bool` – Returns true if the queue is full, false otherwise.


🚩 **Pre-conditions**:

- The queue must be initialized.


✅ **Post-conditions**:

- No changes to the queue.


💡 **Example Usage**:

```c
if (isFull(logQueue)) {
    printf("Queue is at maximum capacity.\n");
}
```

🧪 **Edge Cases / Notes**:

- The function assumes the queue pointer is valid.
- MAX_queue_SIZE is a constant defined in the header file.


## 🔧 Function Name: Enqueue

📁 **Module**: queues.c / queues.h

📌 **Purpose**: Insert a log entry at the end of the queue.

🧠 **Description**: This function adds a new log entry to the end of the circular queue. It creates a new log entry with the provided details, updates the tail position, and increments the size of the queue.

⚙️ **Prototype**:

```c
void Enqueue(queue *logs, int id, char *message, char *timestamp, int severity);
```

🔢 **Parameters**:

```plaintext
| Name      | Type    |
|-----------|---------|
| logs      | queue*  |
| id        | int     |
| message   | char*   |
| timestamp | char*   |
| severity  | int     |
```

🔁 **Return**:

- `void` – No return value. Modifies the queue through the logs pointer.


🚩 **Pre-conditions**:

- The queue must be initialized.
- The queue must not be full.
- Memory allocation must be successful.


✅ **Post-conditions**:

- A new log entry is added at the end of the queue.
- The tail position is updated.
- The size of the queue is incremented.


💡 **Example Usage**:

```c
Enqueue(logQueue, 1, "System startup complete", "2025-05-18 12:00:00", 1);
```

🧪 **Edge Cases / Notes**:

- If the queue is full, the function prints an error message and returns without adding the log.
- The function uses a circular implementation to efficiently use memory.
- String fields are truncated if they exceed the maximum allowed size.


## 🔧 Function Name: Dequeue

📁 **Module**: queues.c / queues.h

📌 **Purpose**: Remove a log entry from the front of the queue.

🧠 **Description**: This function removes and returns the log entry at the front of the circular queue. It updates the head position and decrements the size of the queue.

⚙️ **Prototype**:

```c
logEntry *Dequeue(queue *logs);
```

🔢 **Parameters**:

```plaintext
| Name | Type    |
|------|---------|
| logs | queue*  |
```

🔁 **Return**:

- `logEntry*` – Pointer to the removed log entry, or NULL if the queue is empty.


🚩 **Pre-conditions**:

- The queue must be initialized.


✅ **Post-conditions**:

- The log entry at the front of the queue is removed.
- The head position is updated.
- The size of the queue is decremented.


💡 **Example Usage**:

```c
logEntry *oldestLog = Dequeue(logQueue);
if (oldestLog != NULL) {
    printf("Processed log: %s\n", oldestLog->message);
    free(oldestLog);
}
```

🧪 **Edge Cases / Notes**:

- If the queue is empty, the function prints an error message and returns NULL.
- The caller is responsible for freeing the memory of the returned log entry.
- The function uses a circular implementation to efficiently use memory.


## 🔧 Function Name: Peek

📁 **Module**: queues.c / queues.h

📌 **Purpose**: View the first log entry without removing it from the queue.

🧠 **Description**: This function returns a pointer to the log entry at the front of the queue without removing it, allowing inspection of the oldest log entry.

⚙️ **Prototype**:

```c
logEntry *Peek(queue *logs);
```

🔢 **Parameters**:

```plaintext
| Name | Type    |
|------|---------|
| logs | queue*  |
```

🔁 **Return**:

- `logEntry*` – Pointer to the first log entry in the queue, or NULL if the queue is empty.


🚩 **Pre-conditions**:

- The queue must be initialized.


✅ **Post-conditions**:

- No changes to the queue.


💡 **Example Usage**:

```c
logEntry *oldestLog = Peek(logQueue);
if (oldestLog != NULL) {
    printf("Next log to process: %s\n", oldestLog->message);
}
```

🧪 **Edge Cases / Notes**:

- If the queue is empty, the function prints an error message and returns NULL.
- The returned pointer should not be freed as it still points to data in the queue.


## 🔧 Function Name: freeQueue

📁 **Module**: queues.c / queues.h

📌 **Purpose**: Free all memory associated with the queue and its log entries.

🧠 **Description**: This function deallocates all memory used by the queue and its log entries. It dequeues and frees each log entry before freeing the queue structure itself.

⚙️ **Prototype**:

```c
void freeQueue(queue *logs);
```

🔢 **Parameters**:

```plaintext
| Name | Type    |
|------|---------|
| logs | queue*  |
```

🔁 **Return**:

- `void` – No return value.


🚩 **Pre-conditions**:

- The queue must be initialized.


✅ **Post-conditions**:

- All memory associated with the queue and its log entries is freed.
- The queue pointer becomes invalid and should not be used.


💡 **Example Usage**:

```c
freeQueue(logQueue);
logQueue = NULL; // Good practice to avoid dangling pointer
```

🧪 **Edge Cases / Notes**:

- The function handles empty queues correctly.
- After calling this function, the queue pointer should not be used without re-initialization.


## 🔧 Function Name: printQueue

📁 **Module**: queues.c / queues.h

📌 **Purpose**: Display all log entries in the queue.

🧠 **Description**: This function prints a formatted table of all log entries currently in the queue, showing their ID, message, timestamp, and severity.

⚙️ **Prototype**:

```c
void printQueue(queue *logs);
```

🔢 **Parameters**:

```plaintext
| Name | Type    |
|------|---------|
| logs | queue*  |
```

🔁 **Return**:

- `void` – No return value.


🚩 **Pre-conditions**:

- The queue must be initialized.


✅ **Post-conditions**:

- No changes to the queue.


💡 **Example Usage**:

```c
printQueue(logQueue);
```

🧪 **Edge Cases / Notes**:

- The function handles empty queues by printing an appropriate message.
- The function uses a circular traversal to display logs in the correct order.
- The output is formatted as a table for better readability.*


## **Module 5 : Stacks**

## 🔧 Function Name: initStack

📁 **Module**: stacks.c / stacks.h

📌 **Purpose**: Initialize a new stack for log entries.

🧠 **Description**: This function creates and initializes a new stack structure for storing log entries. It dynamically allocates memory for the stack structure and sets the initial value for the top index.

⚙️ **Prototype**:

```c
stack *initStack();
```

🔢 **Parameters**: None

🔁 **Return**:

- `stack*` – Pointer to the newly created and initialized stack.


🚩 **Pre-conditions**:

- Memory allocation must be successful.


✅ **Post-conditions**:

- A new stack is created with top = -1 (empty stack).


💡 **Example Usage**:

```c
stack *logStack = initStack();
```

🧪 **Edge Cases / Notes**:

- If malloc fails, the function may return NULL; consider checking the return value.


## 🔧 Function Name: isFull

📁 **Module**: stacks.c / stacks.h

📌 **Purpose**: Check if the stack is full.

🧠 **Description**: This function determines whether the stack has reached its maximum capacity by checking if the top index equals the maximum allowed size minus one.

⚙️ **Prototype**:

```c
bool isFull(stack *st);
```

🔢 **Parameters**:

```plaintext
| Name | Type    |
|------|---------|
| st   | stack*  |
```

🔁 **Return**:

- `bool` – Returns true if the stack is full, false otherwise.


🚩 **Pre-conditions**:

- The stack must be initialized.


✅ **Post-conditions**:

- No changes to the stack.


💡 **Example Usage**:

```c
if (isFull(logStack)) {
    printf("Stack is at maximum capacity.\n");
}
```

🧪 **Edge Cases / Notes**:

- The function assumes the stack pointer is valid.
- MAX_STACK_SIZE is a constant defined in the header file.


## 🔧 Function Name: isEmpty

📁 **Module**: stacks.c / stacks.h

📌 **Purpose**: Check if the stack is empty.

🧠 **Description**: This function determines whether the stack contains any log entries by checking if the top index is -1.

⚙️ **Prototype**:

```c
bool isEmpty(stack *st);
```

🔢 **Parameters**:

```plaintext
| Name | Type    |
|------|---------|
| st   | stack*  |
```

🔁 **Return**:

- `bool` – Returns true if the stack is empty, false otherwise.


🚩 **Pre-conditions**:

- The stack must be initialized.


✅ **Post-conditions**:

- No changes to the stack.


💡 **Example Usage**:

```c
if (isEmpty(logStack)) {
    printf("No logs available.\n");
}
```

🧪 **Edge Cases / Notes**:

- The function assumes the stack pointer is valid.


## 🔧 Function Name: printStack

📁 **Module**: stacks.c / stacks.h

📌 **Purpose**: Display all log entries in the stack.

🧠 **Description**: This function prints all log entries currently in the stack, showing their ID, message, timestamp, and severity.

⚙️ **Prototype**:

```c
void printStack(stack *logs);
```

🔢 **Parameters**:

```plaintext
| Name | Type    |
|------|---------|
| logs | stack*  |
```

🔁 **Return**:

- `void` – No return value.


🚩 **Pre-conditions**:

- The stack must be initialized.


✅ **Post-conditions**:

- No changes to the stack.


💡 **Example Usage**:

```c
printStack(logStack);
```

🧪 **Edge Cases / Notes**:

- The function silently returns if the stack is empty without printing any message.
- Logs are printed from bottom to top (index 0 to top).


## 🔧 Function Name: pushLog

📁 **Module**: stacks.c / stacks.h

📌 **Purpose**: Insert a log entry at the top of the stack.

🧠 **Description**: This function adds a new log entry to the top of the stack. It creates a new log entry with the provided details, increments the top index, and places the entry at the new top position.

⚙️ **Prototype**:

```c
void pushLog(stack *logs, int id, char *message, char *timestamp, int severity);
```

🔢 **Parameters**:

```plaintext
| Name      | Type    |
|-----------|---------|
| logs      | stack*  |
| id        | int     |
| message   | char*   |
| timestamp | char*   |
| severity  | int     |
```

🔁 **Return**:

- `void` – No return value. Modifies the stack through the logs pointer.


🚩 **Pre-conditions**:

- The stack must be initialized.
- The stack must not be full.
- Memory allocation must be successful.


✅ **Post-conditions**:

- A new log entry is added at the top of the stack.
- The top index is incremented.


💡 **Example Usage**:

```c
pushLog(logStack, 1, "System startup complete", "2025-05-18 12:00:00", 1);
```

🧪 **Edge Cases / Notes**:

- If the stack is full, the function prints an error message and returns without adding the log.
- String fields are truncated if they exceed the maximum allowed size.


## 🔧 Function Name: popLog

📁 **Module**: stacks.c / stacks.h

📌 **Purpose**: Remove a log entry from the top of the stack.

🧠 **Description**: This function removes and returns the log entry at the top of the stack. It decrements the top index after retrieving the entry.

⚙️ **Prototype**:

```c
logEntry *popLog(stack *logs);
```

🔢 **Parameters**:

```plaintext
| Name | Type    |
|------|---------|
| logs | stack*  |
```

🔁 **Return**:

- `logEntry*` – Pointer to the removed log entry, or NULL if the stack is empty.


🚩 **Pre-conditions**:

- The stack must be initialized.


✅ **Post-conditions**:

- The log entry at the top of the stack is removed.
- The top index is decremented.


💡 **Example Usage**:

```c
logEntry *topLog = popLog(logStack);
if (topLog != NULL) {
    printf("Processed log: %s\n", topLog->message);
    free(topLog);
}
```

🧪 **Edge Cases / Notes**:

- If the stack is empty, the function prints an error message and returns NULL.
- The caller is responsible for freeing the memory of the returned log entry.


## 🔧 Function Name: peekLog

📁 **Module**: stacks.c / stacks.h

📌 **Purpose**: View the top log entry without removing it from the stack.

🧠 **Description**: This function returns a pointer to the log entry at the top of the stack without removing it, allowing inspection of the most recent log entry.

⚙️ **Prototype**:

```c
logEntry *peekLog(stack *logs);
```

🔢 **Parameters**:

```plaintext
| Name | Type    |
|------|---------|
| logs | stack*  |
```

🔁 **Return**:

- `logEntry*` – Pointer to the top log entry in the stack, or NULL if the stack is empty.


🚩 **Pre-conditions**:

- The stack must be initialized.


✅ **Post-conditions**:

- No changes to the stack.


💡 **Example Usage**:

```c
logEntry *topLog = peekLog(logStack);
if (topLog != NULL) {
    printf("Most recent log: %s\n", topLog->message);
}
```

🧪 **Edge Cases / Notes**:

- If the stack is empty, the function prints an error message and returns NULL.
- The returned pointer should not be freed as it still points to data in the stack.


## 🔧 Function Name: insertAtBottom

📁 **Module**: stacks.c / stacks.h

📌 **Purpose**: Insert a log entry at the bottom of the stack.

🧠 **Description**: This function recursively inserts a log entry at the bottom of the stack. It is a helper function used primarily for reversing the stack.

⚙️ **Prototype**:

```c
void insertAtBottom(stack *logs, logEntry *entry);
```

🔢 **Parameters**:

```plaintext
| Name  | Type      |
|-------|-----------|
| logs  | stack*    |
| entry | logEntry* |
```

🔁 **Return**:

- `void` – No return value. Modifies the stack through the logs pointer.


🚩 **Pre-conditions**:

- The stack must be initialized.
- The entry pointer must be valid.


✅ **Post-conditions**:

- The log entry is inserted at the bottom of the stack.
- The original entry is freed after insertion.


💡 **Example Usage**:

```c
logEntry *entry = popLog(logStack);
if (entry != NULL) {
    insertAtBottom(logStack, entry);
}
```

🧪 **Edge Cases / Notes**:

- This function uses recursion to reach the bottom of the stack.
- The function frees the provided entry after insertion, so the caller should not free it.
- This function is primarily used as a helper for ReverseLogsStack.


## 🔧 Function Name: ReverseLogsStack

📁 **Module**: stacks.c / stacks.h

📌 **Purpose**: Reverse the order of log entries in the stack.

🧠 **Description**: This function recursively reverses the order of all log entries in the stack, effectively turning the top to bottom and vice versa.

⚙️ **Prototype**:

```c
void ReverseLogsStack(stack *logs);
```

🔢 **Parameters**:

```plaintext
| Name | Type    |
|------|---------|
| logs | stack*  |
```

🔁 **Return**:

- `void` – No return value. Modifies the stack through the logs pointer.


🚩 **Pre-conditions**:

- The stack must be initialized.


✅ **Post-conditions**:

- The order of log entries in the stack is reversed.


💡 **Example Usage**:

```c
ReverseLogsStack(logStack);
```

🧪 **Edge Cases / Notes**:

- The function silently returns if the stack is empty.
- This function uses recursion and the insertAtBottom helper function to achieve the reversal.
- The time complexity is O(n²) where n is the number of elements in the stack.


## 🔧 Function Name: freeStack

📁 **Module**: stacks.c / stacks.h

📌 **Purpose**: Free all memory associated with the stack and its log entries.

🧠 **Description**: This function deallocates all memory used by the stack and its log entries. It pops and frees each log entry before freeing the stack structure itself.

⚙️ **Prototype**:

```c
void freeStack(stack *logs);
```

🔢 **Parameters**:

```plaintext
| Name | Type    |
|------|---------|
| logs | stack*  |
```

🔁 **Return**:

- `void` – No return value.


🚩 **Pre-conditions**:

- The stack must be initialized.


✅ **Post-conditions**:

- All memory associated with the stack and its log entries is freed.
- The stack pointer becomes invalid and should not be used.


💡 **Example Usage**:

```c
freeStack(logStack);
logStack = NULL; // Good practice to avoid dangling pointer
```

🧪 **Edge Cases / Notes**:

- The function handles empty stacks correctly.
- After calling this function, the stack pointer should not be used without re-initialization.



## **Module 6: Recursion**

## 🔧 Function Name: reverseListRecursive

📁 **Module**: recursion.c / recursion.h

📌 **Purpose**: Reverse a bidirectional linked list using recursion.

🧠 **Description**: This function recursively reverses the order of nodes in a bidirectional linked list by swapping the next and prev pointers of each node. It traverses the list recursively and updates the head and tail pointers accordingly.

⚙️ **Prototype**:

```c
void reverseListRecursive(Node** head, Node** tail, Node* current);
```

🔢 **Parameters**:

```plaintext
| Name    | Type     |
|---------|----------|
| head    | Node**   |
| tail    | Node**   |
| current | Node*    |
```

🔁 **Return**:

- `void` – No return value. Modifies the list through the head and tail pointers.


🚩 **Pre-conditions**:

- head and tail pointers must be initialized (can point to NULL for empty list).
- current should initially be set to the head of the list.
- The list must be a bidirectional linked list with valid prev and next pointers.


✅ **Post-conditions**:

- The order of nodes in the list is reversed.
- The head and tail pointers are swapped.
- The bidirectional links are properly maintained.


💡 **Example Usage**:

```c
reverseListRecursive(&head, &tail, head); // Reverse the order of nodes in the list
```

🧪 **Edge Cases / Notes**:

- If the list is empty (head is NULL) or has only one node (head == tail), the function returns without making any changes.
- The function uses recursion to traverse the list and swap the pointers.
- The base case is reached when the current node's next pointer points to the original head, indicating we've processed all nodes.


## 🔧 Function Name: factorial

📁 **Module**: recursion.c / recursion.h

📌 **Purpose**: Calculate the factorial of a number using recursion.

🧠 **Description**: This function recursively calculates the factorial of a non-negative integer n. The factorial of n (denoted as n!) is the product of all positive integers less than or equal to n.

⚙️ **Prototype**:

```c
int factorial(int n);
```

🔢 **Parameters**:

```plaintext
| Name | Type |
|------|------|
| n    | int  |
```

🔁 **Return**:

- `int` – The factorial of n.


🚩 **Pre-conditions**:

- n must be a non-negative integer.


✅ **Post-conditions**:

- No changes to any data structures.


💡 **Example Usage**:

```c
int result = factorial(5); // Calculate 5! = 5 * 4 * 3 * 2 * 1 = 120
printf("5! = %d\n", result);
```

🧪 **Edge Cases / Notes**:

- The function handles the base cases of n = 0 and n = 1, both of which return 1.
- For large values of n, the result may exceed the range of an int, causing overflow.
- The function does not check for negative inputs, which would lead to infinite recursion.
- The time complexity is O(n) and the space complexity is O(n) due to the recursive call stack.


## 🔧 Function Name: fibonacci

📁 **Module**: recursion.c / recursion.h

📌 **Purpose**: Calculate the nth Fibonacci number using recursion.

🧠 **Description**: This function recursively calculates the nth number in the Fibonacci sequence. The Fibonacci sequence is defined as: F(0) = 0, F(1) = 1, and F(n) = F(n-1) + F(n-2) for n > 1.

⚙️ **Prototype**:

```c
int fibonacci(int n);
```

🔢 **Parameters**:

```plaintext
| Name | Type |
|------|------|
| n    | int  |
```

🔁 **Return**:

- `int` – The nth Fibonacci number.


🚩 **Pre-conditions**:

- n must be a non-negative integer.


✅ **Post-conditions**:

- No changes to any data structures.


💡 **Example Usage**:

```c
int result = fibonacci(6); // Calculate the 6th Fibonacci number: 0, 1, 1, 2, 3, 5, 8 -> 8
printf("The 6th Fibonacci number is %d\n", result);
```

🧪 **Edge Cases / Notes**:

- The function handles the base cases of n = 0 (returns 0) and n = 1 (returns 1).
- This implementation has exponential time complexity O(2^n) due to redundant calculations, making it inefficient for large values of n.
- The function does not check for negative inputs, which would lead to incorrect results or infinite recursion.
- For large values of n, the result may exceed the range of an int, causing overflow.
- A more efficient implementation would use memoization or an iterative approach.


## 🔧 Function Name: findMaxIDRecursive

📁 **Module**: recursion.c / recursion.h

📌 **Purpose**: Find the maximum ID value in a circular linked list using recursion.

🧠 **Description**: This function recursively traverses a circular linked list to find the node with the maximum ID value. It compares each node's ID with the current maximum and updates the maximum if necessary.

⚙️ **Prototype**:

```c
int findMaxIDRecursive(Node* head, Node* current, int maxID);
```

🔢 **Parameters**:

```plaintext
| Name    | Type   |
|---------|--------|
| head    | Node*  |
| current | Node*  |
| maxID   | int    |
```

🔁 **Return**:

- `int` – The maximum ID value found in the list.


🚩 **Pre-conditions**:

- head must be a valid pointer to the head of a circular linked list.
- current should initially be set to head->next to start the traversal.
- maxID should initially be set to head->id or a suitable minimum value.


✅ **Post-conditions**:

- No changes to the list structure.


💡 **Example Usage**:

```c
int maxID = head->id; // Start with the head's ID as the initial maximum
int result = findMaxIDRecursive(head, head->next, maxID);
printf("The maximum ID in the list is %d\n", result);
```

🧪 **Edge Cases / Notes**:

- The function assumes that the list is circular and that head is not NULL.
- The base case is reached when the current node is the head again, indicating we've traversed the entire circular list.
- The function updates the maxID parameter as it traverses the list.
- The time complexity is O(n) where n is the number of nodes in the list.
- The space complexity is O(n) due to the recursive call stack.


## 🔧 Function Name: binarySearchLogs

📁 **Module**: recursion.c / recursion.h

📌 **Purpose**: Perform a binary search on a sorted array of logs to find a log with a specific ID.

🧠 **Description**: This function implements a recursive binary search algorithm to find a log entry with a specific ID in a sorted array of logs. It repeatedly divides the search interval in half until the target ID is found or the interval is empty.

⚙️ **Prototype**:

```c
int binarySearchLogs(Node logs[], int low, int high, int targetID);
```

🔢 **Parameters**:

```plaintext
| Name     | Type    |
|----------|---------|
| logs     | Node[]  |
| low      | int     |
| high     | int     |
| targetID | int     |
```

🔁 **Return**:

- `int` – The index of the log entry with the target ID if found, or -1 if not found.


🚩 **Pre-conditions**:

- The logs array must be sorted in ascending order by ID.
- low and high must be valid indices into the logs array (0 <= low <= high < array_size).


✅ **Post-conditions**:

- No changes to the logs array.


💡 **Example Usage**:

```c
int index = binarySearchLogs(logsArray, 0, arraySize - 1, 42);
if (index != -1) {
    printf("Found log with ID 42 at index %d\n", index);
} else {
    printf("Log with ID 42 not found\n");
}
```

🧪 **Edge Cases / Notes**:

- The function returns -1 if the target ID is not found in the logs array.
- The function assumes that the logs array is sorted by ID in ascending order.
- Binary search has a time complexity of O(log n), making it efficient for large arrays.
- The space complexity is O(log n) due to the recursive call stack.


## 🔧 Function Name: infixToPostfixRecursive

📁 **Module**: recursion.c / recursion.h

📌 **Purpose**: Convert an infix expression to postfix notation using recursion.

🧠 **Description**: This function recursively converts an infix expression (e.g., A+B) to postfix notation (e.g., AB+). It processes each character of the infix expression one by one, placing operands directly in the output and handling operators according to postfix rules.

⚙️ **Prototype**:

```c
void infixToPostfixRecursive(char* infix, int index, char* postfix, int* postIndex);
```

🔢 **Parameters**:

```plaintext
| Name      | Type   |
|-----------|--------|
| infix     | char*  |
| index     | int    |
| postfix   | char*  |
| postIndex | int*   |
```

🔁 **Return**:

- `void` – No return value. The result is stored in the postfix array.


🚩 **Pre-conditions**:

- infix must be a valid null-terminated string containing the infix expression.
- index should initially be set to 0 to start from the beginning of the infix string.
- postfix must be a pre-allocated character array large enough to hold the result.
- postIndex should initially point to an integer initialized to 0.


✅ **Post-conditions**:

- The postfix array contains the postfix notation of the infix expression.
- The postIndex is updated to reflect the length of the postfix expression.


💡 **Example Usage**:

```c
char infix[] = "A+B*C";
char postfix[100];
int postIndex = 0;
infixToPostfixRecursive(infix, 0, postfix, &postIndex);
printf("Infix: %s, Postfix: %s\n", infix, postfix);
```

🧪 **Edge Cases / Notes**:

- The function assumes that the infix expression contains only uppercase letters (A-Z) as operands and simple operators.
- The implementation is simplified and may not handle complex expressions with parentheses or operator precedence correctly.
- The function places operands directly in the postfix output and appends operators after processing their operands.
- The base case is reached when the end of the infix string is encountered (infix[index] == '\0').
- The time complexity is O(n) where n is the length of the infix expression.
- The space complexity is O(n) due to the recursive call stack and the postfix output array.
## **Module 7 : Trees** 
## 🔧 Function Name: createNode

📁 **Module**: trees.c / trees.h

📌 **Purpose**: Create a new node for the Binary Search Tree (BST).

🧠 **Description**: This function allocates memory for a new BST node and initializes it with the provided log entry data. The node's left and right child pointers are set to NULL.

⚙️ **Prototype**:

```c
node *createNode(int id, char *msg, char *time, int severity);
```

🔢 **Parameters**:

```plaintext
| Name     | Type    |
|----------|---------|
| id       | int     |
| msg      | char*   |
| time     | char*   |
| severity | int     |
```

🔁 **Return**:

- `node*` – Pointer to the newly created BST node.


🚩 **Pre-conditions**:

- Memory allocation must be successful.
- The msg and time strings must be valid null-terminated strings.


✅ **Post-conditions**:

- A new node is created with the provided data.
- The left and right child pointers are initialized to NULL.


💡 **Example Usage**:

```c
node *root = createNode(1, "System startup", "2025-05-18 12:00:00", 1);
```

🧪 **Edge Cases / Notes**:

- If malloc fails, the function may return NULL; consider checking the return value.
- The function assumes that the message and timestamp strings will fit within the allocated space in the node structure.


## 🔧 Function Name: insertNode

📁 **Module**: trees.c / trees.h

📌 **Purpose**: Insert a log entry into the Binary Search Tree (BST).

🧠 **Description**: This function recursively inserts a new log entry into the BST, maintaining the tree's ordering based on timestamps. If the timestamp is less than the current node's timestamp, the entry is inserted in the left subtree; otherwise, it's inserted in the right subtree.

⚙️ **Prototype**:

```c
node *insertNode(node *root, int id, char *msg, char *time, int severity);
```

🔢 **Parameters**:

```plaintext
| Name     | Type    |
|----------|---------|
| root     | node*   |
| id       | int     |
| msg      | char*   |
| time     | char*   |
| severity | int     |
```

🔁 **Return**:

- `node*` – Pointer to the root of the tree after insertion.


🚩 **Pre-conditions**:

- The root can be NULL (empty tree) or a valid BST.
- The msg and time strings must be valid null-terminated strings.


✅ **Post-conditions**:

- A new node is inserted into the BST at the appropriate position based on timestamp.
- The BST property is maintained (all nodes in left subtree have timestamps less than the current node, all nodes in right subtree have timestamps greater than or equal to the current node).


💡 **Example Usage**:

```c
root = insertNode(root, 2, "User login", "2025-05-18 12:05:00", 2);
```

🧪 **Edge Cases / Notes**:

- If the root is NULL, a new node is created and returned.
- The function uses strcmp to compare timestamps, assuming they are in a format that allows lexicographical comparison (e.g., "YYYY-MM-DD HH:MM:SS").
- Duplicate timestamps are inserted in the right subtree.


## 🔧 Function Name: printNode

📁 **Module**: trees.c / trees.h

📌 **Purpose**: Print the information of a single node in the BST.

🧠 **Description**: This function prints the ID, severity, timestamp, and message of a given node to the standard output.

⚙️ **Prototype**:

```c
void printNode(node *n);
```

🔢 **Parameters**:

```plaintext
| Name | Type    |
|------|---------|
| n    | node*   |
```

🔁 **Return**:

- `void` – No return value.


🚩 **Pre-conditions**:

- The node pointer can be NULL or a valid node.


✅ **Post-conditions**:

- If the node is not NULL, its information is printed to the standard output.
- No changes to the node or tree structure.


💡 **Example Usage**:

```c
node *foundNode = searchNode(root, "2025-05-18 12:00:00");
printNode(foundNode);
```

🧪 **Edge Cases / Notes**:

- The function silently returns if the node is NULL, without printing any message.
- The output format is: "Id: [id], Severity: [severity], timestamp: '[timestamp]', Message: '[message]'"


## 🔧 Function Name: findInOrderMin

📁 **Module**: trees.c / trees.h

📌 **Purpose**: Find the node with the minimum timestamp in a subtree.

🧠 **Description**: This function traverses the left subtree of the given root node to find the node with the minimum timestamp value. It is typically used to find the in-order successor during deletion operations.

⚙️ **Prototype**:

```c
node *findInOrderMin(node *root);
```

🔢 **Parameters**:

```plaintext
| Name | Type    |
|------|---------|
| root | node*   |
```

🔁 **Return**:

- `node*` – Pointer to the node with the minimum timestamp in the subtree.


🚩 **Pre-conditions**:

- The root can be NULL or a valid BST node.


✅ **Post-conditions**:

- No changes to the tree structure.


💡 **Example Usage**:

```c
node *minNode = findInOrderMin(root->right);
```

🧪 **Edge Cases / Notes**:

- If the root is NULL, the function returns NULL.
- The function follows the left child pointers until it reaches a node with no left child.
- This function is primarily used as a helper for the deleteLog function.


## 🔧 Function Name: CopyLogData

📁 **Module**: trees.c / trees.h

📌 **Purpose**: Copy log data from one node to another.

🧠 **Description**: This function copies the ID, severity, message, and timestamp from a source node to a destination node. It is typically used during deletion operations when replacing a node with its in-order successor.

⚙️ **Prototype**:

```c
void CopyLogData(node *dest, node *src);
```

🔢 **Parameters**:

```plaintext
| Name | Type    |
|------|---------|
| dest | node*   |
| src  | node*   |
```

🔁 **Return**:

- `void` – No return value.


🚩 **Pre-conditions**:

- Both dest and src must be valid node pointers.
- The destination node must have enough space allocated for the message and timestamp strings.


✅ **Post-conditions**:

- The destination node contains a copy of the source node's data (ID, severity, message, timestamp).
- The tree structure (pointers) remains unchanged.


💡 **Example Usage**:

```c
node *successor = findInOrderMin(root->right);
CopyLogData(root, successor);
```

🧪 **Edge Cases / Notes**:

- The function does not check if the pointers are valid; it assumes they are.
- Only the data fields are copied, not the tree structure (left and right pointers).
- This function is primarily used as a helper for the deleteLog function.


## 🔧 Function Name: deleteLog

📁 **Module**: trees.c / trees.h

📌 **Purpose**: Delete a log entry from the Binary Search Tree (BST).

🧠 **Description**: This function recursively searches for a node with the specified timestamp and removes it from the BST while maintaining the BST property. It handles three cases: nodes with no children, nodes with one child, and nodes with two children.

⚙️ **Prototype**:

```c
node *deleteLog(node *root, char *time);
```

🔢 **Parameters**:

```plaintext
| Name | Type    |
|------|---------|
| root | node*   |
| time | char*   |
```

🔁 **Return**:

- `node*` – Pointer to the root of the tree after deletion.


🚩 **Pre-conditions**:

- The root can be NULL or a valid BST.
- The time string must be a valid null-terminated string.


✅ **Post-conditions**:

- If a node with the specified timestamp exists, it is removed from the BST.
- The BST property is maintained.
- Memory for the deleted node is freed.


💡 **Example Usage**:

```c
root = deleteLog(root, "2025-05-18 12:00:00");
```

🧪 **Edge Cases / Notes**:

- If the root is NULL or the time is NULL, the function returns the root unchanged.
- For nodes with two children, the function finds the in-order successor (minimum node in the right subtree), copies its data to the node to be deleted, and then recursively deletes the successor.
- The function handles all three deletion cases: leaf nodes, nodes with one child, and nodes with two children.


## 🔧 Function Name: searchNode

📁 **Module**: trees.c / trees.h

📌 **Purpose**: Search for a log entry in the Binary Search Tree (BST).

🧠 **Description**: This function recursively searches the BST for a node with the specified timestamp. It uses the BST property to efficiently navigate the tree.

⚙️ **Prototype**:

```c
node *searchNode(node *root, char *time);
```

🔢 **Parameters**:

```plaintext
| Name | Type    |
|------|---------|
| root | node*   |
| time | char*   |
```

🔁 **Return**:

- `node*` – Pointer to the node with the matching timestamp, or NULL if not found.


🚩 **Pre-conditions**:

- The root can be NULL or a valid BST.
- The time string must be a valid null-terminated string.


✅ **Post-conditions**:

- No changes to the tree structure.


💡 **Example Usage**:

```c
node *foundLog = searchNode(root, "2025-05-18 12:00:00");
if (foundLog != NULL) {
    printNode(foundLog);
}
```

🧪 **Edge Cases / Notes**:

- If the root is NULL, the function returns NULL.
- The function uses strcmp to compare timestamps.
- The search is optimized by using the BST property: if the target timestamp is less than the current node's timestamp, search the left subtree; otherwise, search the right subtree.


## 🔧 Function Name: inOrderTraversal

📁 **Module**: trees.c / trees.h

📌 **Purpose**: Traverse the Binary Search Tree (BST) in in-order sequence.

🧠 **Description**: This function recursively traverses the BST in in-order sequence (left subtree, current node, right subtree) and prints each node's information. In-order traversal of a BST visits nodes in ascending order of their timestamps.

⚙️ **Prototype**:

```c
void inOrderTraversal(node *root);
```

🔢 **Parameters**:

```plaintext
| Name | Type    |
|------|---------|
| root | node*   |
```

🔁 **Return**:

- `void` – No return value.


🚩 **Pre-conditions**:

- The root can be NULL or a valid BST.


✅ **Post-conditions**:

- No changes to the tree structure.
- Each node's information is printed to the standard output in ascending timestamp order.


💡 **Example Usage**:

```c
printf("Logs in chronological order:\n");
inOrderTraversal(root);
```

🧪 **Edge Cases / Notes**:

- If the root is NULL, the function returns without printing anything.
- The function prints nodes in ascending timestamp order, which is useful for viewing logs chronologically.


## 🔧 Function Name: preOrderTraversal

📁 **Module**: trees.c / trees.h

📌 **Purpose**: Traverse the Binary Search Tree (BST) in pre-order sequence.

🧠 **Description**: This function recursively traverses the BST in pre-order sequence (current node, left subtree, right subtree) and prints each node's information.

⚙️ **Prototype**:

```c
void preOrderTraversal(node *root);
```

🔢 **Parameters**:

```plaintext
| Name | Type    |
|------|---------|
| root | node*   |
```

🔁 **Return**:

- `void` – No return value.


🚩 **Pre-conditions**:

- The root can be NULL or a valid BST.


✅ **Post-conditions**:

- No changes to the tree structure.
- Each node's information is printed to the standard output in pre-order sequence.


💡 **Example Usage**:

```c
printf("Pre-order traversal of logs:\n");
preOrderTraversal(root);
```

🧪 **Edge Cases / Notes**:

- If the root is NULL, the function returns without printing anything.
- Pre-order traversal is useful for creating a copy of the tree or for expression evaluation.


## 🔧 Function Name: postOrderTraversal

📁 **Module**: trees.c / trees.h

📌 **Purpose**: Traverse the Binary Search Tree (BST) in post-order sequence.

🧠 **Description**: This function recursively traverses the BST in post-order sequence (left subtree, right subtree, current node) and prints each node's information.

⚙️ **Prototype**:

```c
void postOrderTraversal(node *root);
```

🔢 **Parameters**:

```plaintext
| Name | Type    |
|------|---------|
| root | node*   |
```

🔁 **Return**:

- `void` – No return value.


🚩 **Pre-conditions**:

- The root can be NULL or a valid BST.


✅ **Post-conditions**:

- No changes to the tree structure.
- Each node's information is printed to the standard output in post-order sequence.


💡 **Example Usage**:

```c
printf("Post-order traversal of logs:\n");
postOrderTraversal(root);
```

🧪 **Edge Cases / Notes**:

- If the root is NULL, the function returns without printing anything.
- There appears to be a bug in the implementation: the function calls preOrderTraversal for both the left and right subtrees instead of postOrderTraversal. This should be corrected to properly implement post-order traversal.
- Post-order traversal is useful for deleting a tree or for certain mathematical expressions.


## 🔧 Function Name: ConvertLLtoBST

📁 **Module**: trees.c / trees.h

📌 **Purpose**: Convert a linked list of log entries to a Binary Search Tree (BST).

🧠 **Description**: This function converts a singly linked list of log entries to a BST for improved search efficiency. It creates a BST by inserting each node from the linked list into the tree.

⚙️ **Prototype**:

```c
node *ConvertLLtoBST(LogEntry *head);
```

🔢 **Parameters**:

```plaintext
| Name | Type      |
|------|-----------|
| head | LogEntry* |
```

🔁 **Return**:

- `node*` – Pointer to the root of the newly created BST.


🚩 **Pre-conditions**:

- The head can be NULL or a valid linked list of LogEntry nodes.


✅ **Post-conditions**:

- A new BST is created containing all log entries from the linked list.
- The original linked list is not modified.


💡 **Example Usage**:

```c
node *bstRoot = ConvertLLtoBST(linkedListHead);
```

🧪 **Edge Cases / Notes**:

- If the head is NULL, the function returns NULL.
- The function creates a new BST; it does not modify the original linked list.
- The time complexity is O(n log n) for a balanced tree, where n is the number of nodes in the linked list.
- The BST is ordered by timestamp, which improves search efficiency compared to a linked list.


## 🔧 Function Name: freeTree

📁 **Module**: trees.c / trees.h

📌 **Purpose**: Free all memory associated with a Binary Search Tree (BST).

🧠 **Description**: This function recursively deallocates all memory used by the BST nodes. It traverses the tree in post-order (left, right, root) to ensure that all child nodes are freed before their parent nodes.

⚙️ **Prototype**:

```c
void freeTree(node *root);
```

🔢 **Parameters**:

```plaintext
| Name | Type    |
|------|---------|
| root | node*   |
```

🔁 **Return**:

- `void` – No return value.


🚩 **Pre-conditions**:

- The root can be NULL or a valid BST.


✅ **Post-conditions**:

- All memory associated with the BST is freed.
- The root pointer becomes invalid and should not be used.


💡 **Example Usage**:

```c
freeTree(root);
root = NULL; // Good practice to avoid dangling pointer
```

🧪 **Edge Cases / Notes**:

- If the root is NULL, the function returns without doing anything.
- The function uses post-order traversal to ensure that child nodes are freed before their parent nodes.
- After calling this function, the root pointer should not be used without re-initialization.


# **Part 2**

## **Modules based on Linked lists and Queues**
## 🔧 Function Name: getSynWords

📁 **Module**: code.c / code.h

📌 **Purpose**: Extract words and their synonyms from a text file into a linked list.

🧠 **Description**: This function reads a text file containing words, their synonyms, and antonyms, and creates a linked list where each node contains a word and its synonym. It also calculates and stores the character count and vowel count for each word.

⚙️ **Prototype**:

```c
TList *getSynWords(FILE *f);
```

🔢 **Parameters**:

```plaintext
| Name | Type   |
|------|--------|
| f    | FILE*  |
```

🔁 **Return**:

- `TList*` – Pointer to a newly created linked list containing words and their synonyms.


🚩 **Pre-conditions**:

- The file should be in the format "word = synonym # antonym".
- The file should be accessible for reading.


✅ **Post-conditions**:

- A linked list is created with nodes containing words and their synonyms.
- Each node includes the character count and vowel count for the word.


💡 **Example Usage**:

```c
FILE *file = NULL;
TList *synonymList = getSynWords(file);
```

🧪 **Edge Cases / Notes**:

- If the file cannot be opened, the function returns NULL.
- The function assumes that each line in the file follows the correct format.
- The function allocates memory for the list and its nodes, which should be freed when no longer needed.


## 🔧 Function Name: getAntoWords

📁 **Module**: code.c / code.h

📌 **Purpose**: Extract words and their antonyms from a text file into a linked list.

🧠 **Description**: This function reads a text file containing words, their synonyms, and antonyms, and creates a linked list where each node contains a word and its antonym. It also calculates and stores the character count and vowel count for each word.

⚙️ **Prototype**:

```c
TList *getAntoWords(FILE *f);
```

🔢 **Parameters**:

```plaintext
| Name | Type   |
|------|--------|
| f    | FILE*  |
```

🔁 **Return**:

- `TList*` – Pointer to a newly created linked list containing words and their antonyms.


🚩 **Pre-conditions**:

- The file should be in the format "word = synonym # antonym".
- The file should be accessible for reading.


✅ **Post-conditions**:

- A linked list is created with nodes containing words and their antonyms.
- Each node includes the character count and vowel count for the word.


💡 **Example Usage**:

```c
FILE *file = NULL;
TList *antonymList = getAntoWords(file);
```

🧪 **Edge Cases / Notes**:

- If the file cannot be opened, the function returns NULL.
- The function assumes that each line in the file follows the correct format.
- The function allocates memory for the list and its nodes, which should be freed when no longer needed.


## 🔧 Function Name: getInfWord

📁 **Module**: code.c / code.h

📌 **Purpose**: Display information about a word including its synonym, antonym, character count, and vowel count.

🧠 **Description**: This function searches for a given word in both synonym and antonym lists and displays its information including character count, vowel count, synonym, and antonym.

⚙️ **Prototype**:

```c
void getInfWord(TList *syn, TList *ant, char *word);
```

🔢 **Parameters**:

```plaintext
| Name | Type    |
|------|---------|
| syn  | TList*  |
| ant  | TList*  |
| word | char*   |
```

🔁 **Return**:

- `void` – No return value. Information is printed to the standard output.


🚩 **Pre-conditions**:

- syn and ant should be valid linked lists created by getSynWords and getAntoWords.
- word should be a valid null-terminated string.


✅ **Post-conditions**:

- Information about the word is printed to the standard output.
- No changes to the linked lists.


💡 **Example Usage**:

```c
getInfWord(synonymList, antonymList, "happy");
```

🧪 **Edge Cases / Notes**:

- If the word is not found in the synonym list, a message is printed.
- If the word is not found in the antonym list, a message is printed.
- The function prints the information in a formatted box.


## 🔧 Function Name: getInfWord2

📁 **Module**: code.c / code.h

📌 **Purpose**: Display information about a word based on its synonym or antonym.

🧠 **Description**: This function searches for a given synonym or antonym in both lists and displays information about the corresponding word including character count and vowel count.

⚙️ **Prototype**:

```c
void getInfWord2(TList *syn, TList *ant, char *inf);
```

🔢 **Parameters**:

```plaintext
| Name | Type    |
|------|---------|
| syn  | TList*  |
| ant  | TList*  |
| inf  | char*   |
```

🔁 **Return**:

- `void` – No return value. Information is printed to the standard output.


🚩 **Pre-conditions**:

- syn and ant should be valid linked lists created by getSynWords and getAntoWords.
- inf should be a valid null-terminated string representing a synonym or antonym.


✅ **Post-conditions**:

- Information about the word corresponding to the synonym or antonym is printed to the standard output.
- No changes to the linked lists.


💡 **Example Usage**:

```c
getInfWord2(synonymList, antonymList, "joyful"); // If "joyful" is a synonym for "happy"
```

🧪 **Edge Cases / Notes**:

- If the input string is not found as a synonym or antonym, a message is printed.
- The function prints the information in a formatted box.
- The function first checks if the input is a synonym, then checks if it's an antonym.


## 🔧 Function Name: sortWord

📁 **Module**: code.c / code.h

📌 **Purpose**: Sort a linked list of words alphabetically.

🧠 **Description**: This function sorts a linked list of words in alphabetical order using a selection sort algorithm. It compares words lexicographically and swaps node data to achieve the sorting.

⚙️ **Prototype**:

```c
TList *sortWord(TList *syn);
```

🔢 **Parameters**:

```plaintext
| Name | Type    |
|------|---------|
| syn  | TList*  |
```

🔁 **Return**:

- `TList*` – Pointer to the sorted linked list.


🚩 **Pre-conditions**:

- syn should be a valid linked list.


✅ **Post-conditions**:

- The linked list is sorted alphabetically by word.
- The original list structure is maintained, only the data within nodes is swapped.


💡 **Example Usage**:

```c
TList *sortedList = sortWord(synonymList);
```

🧪 **Edge Cases / Notes**:

- If the list is empty or has only one node, it is returned unchanged.
- The function uses a selection sort algorithm with O(n²) time complexity.
- The function modifies the original list rather than creating a new one.


## 🔧 Function Name: sortWord2

📁 **Module**: code.c / code.h

📌 **Purpose**: Sort a linked list of words by character count in ascending order.

🧠 **Description**: This function sorts a linked list of words based on the number of characters in each word, from shortest to longest. It uses a selection sort algorithm and swaps node data to achieve the sorting.

⚙️ **Prototype**:

```c
TList *sortWord2(TList *syn);
```

🔢 **Parameters**:

```plaintext
| Name | Type    |
|------|---------|
| syn  | TList*  |
```

🔁 **Return**:

- `TList*` – Pointer to the sorted linked list.


🚩 **Pre-conditions**:

- syn should be a valid linked list.


✅ **Post-conditions**:

- The linked list is sorted by character count in ascending order.
- The original list structure is maintained, only the data within nodes is swapped.


💡 **Example Usage**:

```c
TList *sortedByLength = sortWord2(synonymList);
```

🧪 **Edge Cases / Notes**:

- If the list is empty or has only one node, it is returned unchanged.
- The function uses a selection sort algorithm with O(n²) time complexity.
- The function modifies the original list rather than creating a new one.


## 🔧 Function Name: sortWord3

📁 **Module**: code.c / code.h

📌 **Purpose**: Sort a linked list of words by vowel count in descending order.

🧠 **Description**: This function sorts a linked list of words based on the number of vowels in each word, from most vowels to least vowels. It uses a selection sort algorithm and swaps node data to achieve the sorting.

⚙️ **Prototype**:

```c
TList *sortWord3(TList *syn);
```

🔢 **Parameters**:

```plaintext
| Name | Type    |
|------|---------|
| syn  | TList*  |
```

🔁 **Return**:

- `TList*` – Pointer to the sorted linked list.


🚩 **Pre-conditions**:

- syn should be a valid linked list.


✅ **Post-conditions**:

- The linked list is sorted by vowel count in descending order.
- The original list structure is maintained, only the data within nodes is swapped.


💡 **Example Usage**:

```c
TList *sortedByVowels = sortWord3(synonymList);
```

🧪 **Edge Cases / Notes**:

- If the list is empty or has only one node, it is returned unchanged.
- The function uses a selection sort algorithm with O(n²) time complexity.
- The function modifies the original list rather than creating a new one.


## 🔧 Function Name: deleteWord

📁 **Module**: code.c / code.h

📌 **Purpose**: Delete a word from the text file and both synonym and antonym linked lists.

🧠 **Description**: This function removes a specified word from the original text file and from both the synonym and antonym linked lists. It creates a temporary file without the word, replaces the original file, and removes the corresponding nodes from the lists.

⚙️ **Prototype**:

```c
void deleteWord(FILE *f, TList *syn, TList *ant, char *word);
```

🔢 **Parameters**:

```plaintext
| Name | Type    |
|------|---------|
| f    | FILE*   |
| syn  | TList*  |
| ant  | TList*  |
| word | char*   |
```

🔁 **Return**:

- `void` – No return value. The file and lists are modified directly.


🚩 **Pre-conditions**:

- f should be a valid file pointer (can be NULL as the function opens the file).
- syn and ant should be valid linked lists.
- word should be a valid null-terminated string.
- The file "words.txt" should exist and be accessible for reading and writing.


✅ **Post-conditions**:

- The word is removed from the text file.
- The word is removed from both linked lists.
- Memory for the removed nodes is freed.


💡 **Example Usage**:

```c
FILE *file = NULL;
deleteWord(file, synonymList, antonymList, "happy");
```

🧪 **Edge Cases / Notes**:

- If the file cannot be opened, an error message is printed.
- If the temporary file cannot be created, an error message is printed.
- The function handles the case where the word appears at the head of the list.
- The function frees the memory of the removed nodes.


## 🔧 Function Name: updateWord

📁 **Module**: code.c / code.h

📌 **Purpose**: Update a word's synonym and antonym in the text file and linked lists.

🧠 **Description**: This function updates the synonym and antonym of a specified word in the original text file and in both linked lists. It creates a temporary file with the updated information, replaces the original file, and updates the corresponding nodes in the lists.

⚙️ **Prototype**:

```c
void updateWord(FILE *f, TList *syn, TList *ant, char *word, char *syne, char *anton);
```

🔢 **Parameters**:

```plaintext
| Name  | Type    |
|-------|---------|
| f     | FILE*   |
| syn   | TList*  |
| ant   | TList*  |
| word  | char*   |
| syne  | char*   |
| anton | char*   |
```

🔁 **Return**:

- `void` – No return value. The file and lists are modified directly.


🚩 **Pre-conditions**:

- f should be a valid file pointer (can be NULL as the function opens the file).
- syn and ant should be valid linked lists.
- word, syne, and anton should be valid null-terminated strings.
- The file "words.txt" should exist and be accessible for reading and writing.


✅ **Post-conditions**:

- The word's synonym and antonym are updated in the text file.
- The word's synonym and antonym are updated in both linked lists.


💡 **Example Usage**:

```c
FILE *file = NULL;
updateWord(file, synonymList, antonymList, "happy", "joyful", "sad");
```

🧪 **Edge Cases / Notes**:

- If the file cannot be opened, an error message is printed.
- If the temporary file cannot be created, an error message is printed.
- The function assumes that the word exists in both lists.


## 🔧 Function Name: similarWord

📁 **Module**: code.c / code.h

📌 **Purpose**: Find words that are similar to a given word based on a match rate.

🧠 **Description**: This function creates a new linked list containing words from the original list that have a similarity match rate greater than or equal to the specified rate. The similarity is based on matching prefixes.

⚙️ **Prototype**:

```c
TList *similarWord(TList *syn, char *word, int rate);
```

🔢 **Parameters**:

```plaintext
| Name | Type    |
|------|---------|
| syn  | TList*  |
| word | char*   |
| rate | int     |
```

🔁 **Return**:

- `TList*` – Pointer to a new linked list containing similar words.


🚩 **Pre-conditions**:

- syn should be a valid linked list.
- word should be a valid null-terminated string.
- rate should be an integer between 0 and 100 representing a percentage.


✅ **Post-conditions**:

- A new linked list is created containing words with a similarity match rate >= the specified rate.
- The original list is not modified.


💡 **Example Usage**:

```c
TList *similarWords = similarWord(synonymList, "happy", 70); // Find words that match "happy" with at least 70% similarity
```

🧪 **Edge Cases / Notes**:

- The function allocates memory for a new list, which should be freed when no longer needed.
- The similarity is calculated based on matching prefixes, not general string similarity.
- If no words meet the similarity threshold, an empty list is returned.


## 🔧 Function Name: countWord

📁 **Module**: code.c / code.h

📌 **Purpose**: Find words that contain a specific substring.

🧠 **Description**: This function creates a new linked list containing words from the original list that contain the specified substring.

⚙️ **Prototype**:

```c
TList *countWord(TList *syn, char *prt);
```

🔢 **Parameters**:

```plaintext
| Name | Type    |
|------|---------|
| syn  | TList*  |
| prt  | char*   |
```

🔁 **Return**:

- `TList*` – Pointer to a new linked list containing words that include the substring.


🚩 **Pre-conditions**:

- syn should be a valid linked list.
- prt should be a valid null-terminated string.


✅ **Post-conditions**:

- A new linked list is created containing words that include the specified substring.
- The original list is not modified.


💡 **Example Usage**:

```c
TList *wordsWithHap = countWord(synonymList, "hap"); // Find words containing "hap" like "happy", "perhaps", etc.
```

🧪 **Edge Cases / Notes**:

- The function allocates memory for a new list, which should be freed when no longer needed.
- The search is case-sensitive.
- If no words contain the substring, an empty list is returned.


## 🔧 Function Name: palindromWord

📁 **Module**: code.c / code.h

📌 **Purpose**: Create a sorted list of palindrome words from the original list.

🧠 **Description**: This function identifies palindrome words in the original list and creates a new sorted linked list containing only these palindromes. Each word is inserted in the correct position to maintain alphabetical order.

⚙️ **Prototype**:

```c
TList *palindromWord(TList *syn);
```

🔢 **Parameters**:

```plaintext
| Name | Type    |
|------|---------|
| syn  | TList*  |
```

🔁 **Return**:

- `TList*` – Pointer to a new sorted linked list containing palindrome words.


🚩 **Pre-conditions**:

- syn should be a valid linked list.


✅ **Post-conditions**:

- A new linked list is created containing palindrome words in alphabetical order.
- The original list is not modified.


💡 **Example Usage**:

```c
TList *palindromes = palindromWord(synonymList); // Find words like "level", "radar", etc.
```

🧪 **Edge Cases / Notes**:

- The function allocates memory for a new list, which should be freed when no longer needed.
- The function uses a recursive approach to check if a word is a palindrome.
- If no palindromes are found, an empty list is returned.
- The function inserts each palindrome in the correct position to maintain alphabetical order.


## 🔧 Function Name: merge

📁 **Module**: code.c / code.h

📌 **Purpose**: Merge synonym and antonym lists into a bidirectional linked list.

🧠 **Description**: This function combines information from both synonym and antonym lists into a single bidirectional linked list. Each node in the new list contains a word, its synonym, its antonym, and other information.

⚙️ **Prototype**:

```c
TList2 *merge(TList *syn, TList *ant);
```

🔢 **Parameters**:

```plaintext
| Name | Type    |
|------|---------|
| syn  | TList*  |
| ant  | TList*  |
```

🔁 **Return**:

- `TList2*` – Pointer to a new bidirectional linked list containing merged information.


🚩 **Pre-conditions**:

- syn and ant should be valid linked lists.
- Both lists should contain the same words in the same order.


✅ **Post-conditions**:

- A new bidirectional linked list is created with nodes containing words, their synonyms, antonyms, and other information.
- The original lists are not modified.


💡 **Example Usage**:

```c
TList2 *mergedList = merge(synonymList, antonymList);
```

🧪 **Edge Cases / Notes**:

- The function allocates memory for a new list, which should be freed when no longer needed.
- The function assumes that both input lists contain the same words in the same order.
- If either list is empty or they have different lengths, the function will stop merging when it reaches the end of either list.


## 🔧 Function Name: merge2

📁 **Module**: code.c / code.h

📌 **Purpose**: Merge synonym and antonym lists into a circular linked list.

🧠 **Description**: This function combines information from both synonym and antonym lists into a single circular linked list. Each node in the new list contains a word, its synonym, its antonym, and other information.

⚙️ **Prototype**:

```c
TList3 *merge2(TList *syn, TList *ant);
```

🔢 **Parameters**:

```plaintext
| Name | Type    |
|------|---------|
| syn  | TList*  |
| ant  | TList*  |
```

🔁 **Return**:

- `TList3*` – Pointer to a new circular linked list containing merged information.


🚩 **Pre-conditions**:

- syn and ant should be valid linked lists.
- Both lists should contain the same words in the same order.


✅ **Post-conditions**:

- A new circular linked list is created with nodes containing words, their synonyms, antonyms, and other information.
- The original lists are not modified.


💡 **Example Usage**:

```c
TList3 *circularList = merge2(synonymList, antonymList);
```

🧪 **Edge Cases / Notes**:

- The function allocates memory for a new list, which should be freed when no longer needed.
- The function assumes that both input lists contain the same words in the same order.
- If either list is empty or they have different lengths, the function will stop merging when it reaches the end of either list.
- The circular nature is maintained by having the last node's next pointer point back to the head of the list.


## 🔧 Function Name: addWord

📁 **Module**: code.c / code.h

📌 **Purpose**: Add a new word with its synonym and antonym to both lists and the text file.

🧠 **Description**: This function adds a new word along with its synonym and antonym to both the synonym and antonym linked lists, and appends the information to the text file.

⚙️ **Prototype**:

```c
void addWord(FILE *f, TList *syn, TList *ant, char *word, char *syne, char *anton);
```

🔢 **Parameters**:

```plaintext
| Name  | Type    |
|-------|---------|
| f     | FILE*   |
| syn   | TList*  |
| ant   | TList*  |
| word  | char*   |
| syne  | char*   |
| anton | char*   |
```

🔁 **Return**:

- `void` – No return value. The lists and file are modified directly.


🚩 **Pre-conditions**:

- f should be a valid file pointer (can be NULL as the function opens the file).
- syn and ant should be valid linked lists.
- word, syne, and anton should be valid null-terminated strings.
- The file "words.txt" should exist and be accessible for appending.


✅ **Post-conditions**:

- The word and its synonym are added to the synonym list.
- The word and its antonym are added to the antonym list.
- The word, synonym, and antonym are appended to the text file.


💡 **Example Usage**:

```c
FILE *file = NULL;
addWord(file, synonymList, antonymList, "content", "satisfied", "dissatisfied");
```

🧪 **Edge Cases / Notes**:

- If the file cannot be opened, an error message is printed.
- The function does not check if the word already exists in the lists or file.


## 🔧 Function Name: syllable

📁 **Module**: code.c / code.h

📌 **Purpose**: Sort words into a queue based on syllable count.

🧠 **Description**: This function creates a queue where words are sorted by their syllable count. It uses the Quick Sort algorithm to sort an array of node pointers before adding them to the queue.

⚙️ **Prototype**:

```c
TQueue *syllable(TList *syn);
```

🔢 **Parameters**:

```plaintext
| Name | Type    |
|------|---------|
| syn  | TList*  |
```

🔁 **Return**:

- `TQueue*` – Pointer to a new queue containing words sorted by syllable count.


🚩 **Pre-conditions**:

- syn should be a valid linked list.


✅ **Post-conditions**:

- A new queue is created containing words sorted by syllable count.
- The original list is not modified.


💡 **Example Usage**:

```c
TQueue *syllableSortedQueue = syllable(synonymList);
```

🧪 **Edge Cases / Notes**:

- The function allocates memory for a new queue and temporary arrays, which should be freed when no longer needed.
- The function uses the Quick Sort algorithm from the standard library.
- If the input list is empty, an empty queue is returned.
- Words with the same syllable count are sorted alphabetically.


## 🔧 Function Name: prounounciation

📁 **Module**: code.c / code.h

📌 **Purpose**: Sort words into three queues based on pronunciation characteristics.

🧠 **Description**: This function categorizes words into three separate queues based on their pronunciation: short vowels, long vowels, or diphthongs. It analyzes each word to determine its vowel type.

⚙️ **Prototype**:

```c
TQueue **prounounciation(TList *syn);
```

🔢 **Parameters**:

```plaintext
| Name | Type    |
|------|---------|
| syn  | TList*  |
```

🔁 **Return**:

- `TQueue**` – Array of three queue pointers for SHORT, LONG, and DIPHTHONG pronunciations.


🚩 **Pre-conditions**:

- syn should be a valid linked list.


✅ **Post-conditions**:

- Three new queues are created, each containing words of a specific pronunciation type.
- The original list is not modified.


💡 **Example Usage**:

```c
TQueue **pronunciationQueues = prounounciation(synonymList);
// Access individual queues with pronunciationQueues[SHORT], pronunciationQueues[LONG], pronunciationQueues[DIPHTHONG]
```

🧪 **Edge Cases / Notes**:

- The function allocates memory for the queue array and individual queues, which should be freed when no longer needed.
- The function uses a simple heuristic to determine pronunciation type, which may not be accurate for all words.
- If the input list is empty, three empty queues are returned.


## 🔧 Function Name: toQueue

📁 **Module**: code.c / code.h

📌 **Purpose**: Convert a bidirectional linked list to a queue.

🧠 **Description**: This function creates a queue from a bidirectional linked list obtained from the merge function. It preserves the order of words from the original list.

⚙️ **Prototype**:

```c
TQueue *toQueue(TList2 *merged);
```

🔢 **Parameters**:

```plaintext
| Name   | Type     |
|--------|----------|
| merged | TList2*  |
```

🔁 **Return**:

- `TQueue*` – Pointer to a new queue containing the words from the bidirectional list.


🚩 **Pre-conditions**:

- merged should be a valid bidirectional linked list created by the merge function.


✅ **Post-conditions**:

- A new queue is created containing the words from the bidirectional list in the same order.
- The original list is not modified.


💡 **Example Usage**:

```c
TList2 *mergedList = merge(synonymList, antonymList);
TQueue *wordQueue = toQueue(mergedList);
```

🧪 **Edge Cases / Notes**:

- The function allocates memory for a new queue, which should be freed when no longer needed.
- If the input list is empty, an empty queue is returned.
- The queue only contains the words, not their synonyms or antonyms.


### Stacks Module Documentation



## **Modules based on Stacks**

## 🔧 Function Name: toStack

📁 **Module**: stacks.c / stacks.h

📌 **Purpose**: Convert a bidirectional linked list to a stack.

🧠 **Description**: This function creates a stack from a bidirectional linked list obtained from the merge function. Each node in the stack contains a word, its synonym, its antonym, and other information.

⚙️ **Prototype**:

```c
TStack *toStack(TList2 *merged);
```

🔢 **Parameters**:

```plaintext
| Name   | Type     |
|--------|----------|
| merged | TList2*  |
```

🔁 **Return**:

- `TStack*` – Pointer to a new stack containing the information from the bidirectional list.


🚩 **Pre-conditions**:

- merged should be a valid bidirectional linked list created by the merge function.


✅ **Post-conditions**:

- A new stack is created containing the information from the bidirectional list.
- The original list is not modified.


💡 **Example Usage**:

```c
TList2 *mergedList = merge(synonymList, antonymList);
TStack *wordStack = toStack(mergedList);
```

🧪 **Edge Cases / Notes**:

- The function allocates memory for a new stack, which should be freed when no longer needed.
- If the input list is empty, an empty stack is returned.
- The order of elements in the stack will be reversed compared to the original list due to the LIFO nature of stacks.


## 🔧 Function Name: getInfWordStack

📁 **Module**: stacks.c / stacks.h

📌 **Purpose**: Display information about a word from a stack.

🧠 **Description**: This function searches for a given word in a stack and displays its information including synonym, antonym, character count, and vowel count.

⚙️ **Prototype**:

```c
TStack *getInfWordStack(TStack *stk, char *word);
```

🔢 **Parameters**:

```plaintext
| Name | Type     |
|------|----------|
| stk  | TStack*  |
| word | char*    |
```

🔁 **Return**:

- `TStack*` – Pointer to the original stack.


🚩 **Pre-conditions**:

- stk should be a valid stack.
- word should be a valid null-terminated string.


✅ **Post-conditions**:

- Information about the word is printed to the standard output.
- The stack remains unchanged.


💡 **Example Usage**:

```c
getInfWordStack(wordStack, "happy");
```

🧪 **Edge Cases / Notes**:

- If the word is not found in the stack, nothing is printed.
- The function uses a recursive search to find the word in the stack.


## 🔧 Function Name: sortWordStack

📁 **Module**: stacks.c / stacks.h

📌 **Purpose**: Sort a stack of words alphabetically.

🧠 **Description**: This function sorts a stack of words in alphabetical order using a recursive approach. It temporarily removes elements, sorts the remaining stack, and then inserts each element back in the correct position.

⚙️ **Prototype**:

```c
TStack *sortWordStack(TStack *stk);
```

🔢 **Parameters**:

```plaintext
| Name | Type     |
|------|----------|
| stk  | TStack*  |
```

🔁 **Return**:

- `TStack*` – Pointer to the sorted stack.


🚩 **Pre-conditions**:

- stk should be a valid stack.


✅ **Post-conditions**:

- The stack is sorted alphabetically by word.
- The original stack structure is modified.


💡 **Example Usage**:

```c
TStack *sortedStack = sortWordStack(wordStack);
```

🧪 **Edge Cases / Notes**:

- If the stack is empty, it is returned unchanged.
- The function uses a recursive approach to sort the stack.
- The function modifies the original stack rather than creating a new one.


## 🔧 Function Name: deleteWordStack

📁 **Module**: stacks.c / stacks.h

📌 **Purpose**: Delete a word from a stack.

🧠 **Description**: This function removes all occurrences of a specified word from a stack. It uses a recursive approach to search for and remove the word while preserving the order of other elements.

⚙️ **Prototype**:

```c
TStack *deleteWordStack(TStack *stk, char *word);
```

🔢 **Parameters**:

```plaintext
| Name | Type     |
|------|----------|
| stk  | TStack*  |
| word | char*    |
```

🔁 **Return**:

- `TStack*` – Pointer to the modified stack.


🚩 **Pre-conditions**:

- stk should be a valid stack.
- word should be a valid null-terminated string.


✅ **Post-conditions**:

- All occurrences of the word are removed from the stack.
- Memory for the removed nodes is freed.
- The original stack structure is modified.


💡 **Example Usage**:

```c
TStack *updatedStack = deleteWordStack(wordStack, "happy");
```

🧪 **Edge Cases / Notes**:

- If the stack is empty, it is returned unchanged.
- The function uses a recursive approach to remove the word.
- The function frees the memory of the removed nodes.
- The function removes all occurrences of the word, not just the first one.


## 🔧 Function Name: updateWordStack

📁 **Module**: stacks.c / stacks.h

📌 **Purpose**: Update a word's synonym and antonym in a stack.

🧠 **Description**: This function updates the synonym and antonym of all occurrences of a specified word in a stack. It uses a recursive approach to search for and update the word while preserving the order of elements.

⚙️ **Prototype**:

```c
TStack *updateWordStack(TStack *stk, char *word, char *syne, char *anton);
```

🔢 **Parameters**:

```plaintext
| Name  | Type     |
|-------|----------|
| stk   | TStack*  |
| word  | char*    |
| syne  | char*    |
| anton | char*    |
```

🔁 **Return**:

- `TStack*` – Pointer to the modified stack.


🚩 **Pre-conditions**:

- stk should be a valid stack.
- word, syne, and anton should be valid null-terminated strings.


✅ **Post-conditions**:

- All occurrences of the word have their synonym and antonym updated.
- The original stack structure is modified.


💡 **Example Usage**:

```c
TStack *updatedStack = updateWordStack(wordStack, "happy", "joyful", "sad");
```

🧪 **Edge Cases / Notes**:

- If the stack is empty, it is returned unchanged.
- The function uses a recursive approach to update the word.
- The function updates all occurrences of the word, not just the first one.


## 🔧 Function Name: stackToQueue

📁 **Module**: stacks.c / stacks.h

📌 **Purpose**: Convert a stack to a sorted queue.

🧠 **Description**: This function first sorts a stack alphabetically and then converts it to a queue, maintaining the sorted order. It uses a recursive approach to transfer elements from the stack to the queue.

⚙️ **Prototype**:

```c
TQueue *stackToQueue(TStack *stk);
```

🔢 **Parameters**:

```plaintext
| Name | Type     |
|------|----------|
| stk  | TStack*  |
```

🔁 **Return**:

- `TQueue*` – Pointer to a new sorted queue.


🚩 **Pre-conditions**:

- stk should be a valid stack.


✅ **Post-conditions**:

- A new queue is created containing the words from the stack in alphabetical order.
- The original stack remains unchanged.


💡 **Example Usage**:

```c
TQueue *sortedQueue = stackToQueue(wordStack);
```

🧪 **Edge Cases / Notes**:

- The function allocates memory for a new queue, which should be freed when no longer needed.
- If the input stack is empty, an empty queue is returned.
- The function first sorts the stack and then transfers elements to the queue.


## 🔧 Function Name: StacktoList

📁 **Module**: stacks.c / stacks.h

📌 **Purpose**: Convert a stack to a bidirectional sorted linked list.

🧠 **Description**: This function first sorts a stack alphabetically and then converts it to a bidirectional linked list, maintaining the sorted order. It uses a recursive approach to transfer elements from the stack to the list.

⚙️ **Prototype**:

```c
TList2 *StacktoList(TStack *stk);
```

🔢 **Parameters**:

```plaintext
| Name | Type     |
|------|----------|
| stk  | TStack*  |
```

🔁 **Return**:

- `TList2*` – Pointer to a new bidirectional sorted linked list.


🚩 **Pre-conditions**:

- stk should be a valid stack.


✅ **Post-conditions**:

- A new bidirectional linked list is created containing the words from the stack in alphabetical order.
- The original stack remains unchanged.


💡 **Example Usage**:

```c
TList2 *sortedList = StacktoList(wordStack);
```

🧪 **Edge Cases / Notes**:

- The function allocates memory for a new list, which should be freed when no longer needed.
- If the input stack is empty, an empty list is returned.
- The function first sorts the stack and then transfers elements to the list.


## 🔧 Function Name: addWordStack

📁 **Module**: stacks.c / stacks.h

📌 **Purpose**: Add a new word with its synonym and antonym to a sorted stack.

🧠 **Description**: This function creates a new node with the provided word, synonym, and antonym, and inserts it into the stack in the correct position to maintain alphabetical order.

⚙️ **Prototype**:

```c
TStack *addWordStack(TStack *stk, char *word, char *syne, char *anton);
```

🔢 **Parameters**:

```plaintext
| Name  | Type     |
|-------|----------|
| stk   | TStack*  |
| word  | char*    |
| syne  | char*    |
| anton | char*    |
```

🔁 **Return**:

- `TStack*` – Pointer to the modified stack.


🚩 **Pre-conditions**:

- stk should be a valid stack (can be empty).
- word, syne, and anton should be valid null-terminated strings.


✅ **Post-conditions**:

- A new node is added to the stack in the correct position to maintain alphabetical order.
- The original stack structure is modified.


💡 **Example Usage**:

```c
TStack *updatedStack = addWordStack(wordStack, "content", "satisfied", "dissatisfied");
```

🧪 **Edge Cases / Notes**:

- The function allocates memory for a new node, which is integrated into the stack.
- The function calculates the character count and vowel count for the word.
- The function uses a recursive helper function to insert the node in the correct position.


## 🔧 Function Name: syllableStack

📁 **Module**: stacks.c / stacks.h

📌 **Purpose**: Sort a stack of words by syllable count.

🧠 **Description**: This function creates a new stack where words are sorted by their syllable count. It counts the syllables in each word, sorts them using the Quick Sort algorithm, and creates a new stack with the sorted order.

⚙️ **Prototype**:

```c
TStack *syllableStack(TStack *stk);
```

🔢 **Parameters**:

```plaintext
| Name | Type     |
|------|----------|
| stk  | TStack*  |
```

🔁 **Return**:

- `TStack*` – Pointer to a new stack containing words sorted by syllable count.


🚩 **Pre-conditions**:

- stk should be a valid stack.


✅ **Post-conditions**:

- A new stack is created containing words sorted by syllable count.
- The original stack remains unchanged.


💡 **Example Usage**:

```c
TStack *syllableSortedStack = syllableStack(wordStack);
```

🧪 **Edge Cases / Notes**:

- The function allocates memory for a new stack and temporary arrays, which should be freed when no longer needed.
- The function uses the Quick Sort algorithm from the standard library.
- If the input stack is empty, an empty stack is returned.
- Words with the same syllable count are sorted alphabetically.


## 🔧 Function Name: prounounciationStack

📁 **Module**: stacks.c / stacks.h

📌 **Purpose**: Sort words into three stacks based on pronunciation characteristics.

🧠 **Description**: This function categorizes words into three separate stacks based on their pronunciation: short vowels, long vowels, or diphthongs. It analyzes each word to determine its vowel type.

⚙️ **Prototype**:

```c
TStack **prounounciationStack(TStack *stk);
```

🔢 **Parameters**:

```plaintext
| Name | Type     |
|------|----------|
| stk  | TStack*  |
```

🔁 **Return**:

- `TStack**` – Array of three stack pointers for SHORT, LONG, and DIPHTHONG pronunciations.


🚩 **Pre-conditions**:

- stk should be a valid stack.


✅ **Post-conditions**:

- Three new stacks are created, each containing words of a specific pronunciation type.
- The original stack remains unchanged.


💡 **Example Usage**:

```c
TStack **pronunciationStacks = prounounciationStack(wordStack);
// Access individual stacks with pronunciationStacks[SHORT], pronunciationStacks[LONG], pronunciationStacks[DIPHTHONG]
```

🧪 **Edge Cases / Notes**:

- The function allocates memory for the stack array and individual stacks, which should be freed when no longer needed.
- The function uses a simple heuristic to determine pronunciation type, which may not be accurate for all words.
- If the input stack is empty, three empty stacks are returned.
- The function uses recursion to process each word in the stack.


## 🔧 Function Name: getSmallest

📁 **Module**: stacks.c / stacks.h

📌 **Purpose**: Find the word with the smallest character count in a stack.

🧠 **Description**: This function recursively searches through a stack to find the word with the smallest character count. It returns the word itself, not the entire node.

⚙️ **Prototype**:

```c
char *getSmallest(TStack *stk);
```

🔢 **Parameters**:

```plaintext
| Name | Type     |
|------|----------|
| stk  | TStack*  |
```

🔁 **Return**:

- `char*` – Pointer to the word with the smallest character count, or NULL if the stack is empty.


🚩 **Pre-conditions**:

- stk should be a valid stack.


✅ **Post-conditions**:

- The stack remains unchanged.


💡 **Example Usage**:

```c
char *smallestWord = getSmallest(wordStack);
if (smallestWord) {
    printf("The shortest word is: %s\n", smallestWord);
}
```

🧪 **Edge Cases / Notes**:

- If the stack is empty, the function returns NULL.
- The function uses recursion to search through the stack.
- The function returns a pointer to the word within the stack, not a copy of the word.


## 🔧 Function Name: cycleSearch

📁 **Module**: stacks.c / stacks.h

📌 **Purpose**: Find and print cycles in word relationships.

🧠 **Description**: This function identifies and prints cycles where a synonym or antonym of a word leads to another word, which eventually leads back to the original word. It helps identify circular relationships in the word dictionary.

⚙️ **Prototype**:

```c
void cycleSearch(TStack *stk);
```

🔢 **Parameters**:

```plaintext
| Name | Type     |
|------|----------|
| stk  | TStack*  |
```

🔁 **Return**:

- `void` – No return value. Cycles are printed to the standard output.


🚩 **Pre-conditions**:

- stk should be a valid stack containing words with their synonyms and antonyms.


✅ **Post-conditions**:

- Cycles in word relationships are printed to the standard output.
- The stack remains unchanged.


💡 **Example Usage**:

```c
cycleSearch(wordStack); // Might print cycles like "happy -> joyful -> happy"
```

🧪 **Edge Cases / Notes**:

- The function does not return any value; it prints the cycles directly.
- The implementation details of this function are not provided in the given code snippet.


## 🔧 Function Name: isPalyndromeStack

📁 **Module**: stacks.c / stacks.h

📌 **Purpose**: Check if a word is a palindrome using a stack.

🧠 **Description**: This function determines if a word is a palindrome (reads the same forwards and backwards) using a stack-based approach. It pushes characters onto a stack and then compares them with the original word.

⚙️ **Prototype**:

```c
bool isPalyndromeStack(char *word);
```

🔢 **Parameters**:

```plaintext
| Name | Type   |
|------|--------|
| word | char*  |
```

🔁 **Return**:

- `bool` – Returns true if the word is a palindrome, false otherwise.


🚩 **Pre-conditions**:

- word should be a valid null-terminated string.


✅ **Post-conditions**:

- No changes to the input word.


💡 **Example Usage**:

```c
if (isPalyndromeStack("level")) {
    printf("'level' is a palindrome\n");
}
```

🧪 **Edge Cases / Notes**:

- The function allocates memory for a temporary stack, which is freed before returning.
- The function uses recursion to push characters onto the stack.
- The comparison is case-sensitive; "Level" would not be considered a palindrome.


## 🔧 Function Name: StackRev

📁 **Module**: stacks.c / stacks.h

📌 **Purpose**: Reverse a stack using recursion.

🧠 **Description**: This function reverses the order of elements in a stack using a recursive approach. It temporarily removes elements, reverses the remaining stack, and then pushes the elements back.

⚙️ **Prototype**:

```c
TStack *StackRev(TStack *stk);
```

🔢 **Parameters**:

```plaintext
| Name | Type     |
|------|----------|
| stk  | TStack*  |
```

🔁 **Return**:

- `TStack*` – Pointer to the reversed stack.


🚩 **Pre-conditions**:

- stk should be a valid stack.


✅ **Post-conditions**:

- The order of elements in the stack is reversed.
- The original stack structure is modified.


💡 **Example Usage**:

```c
TStack *reversedStack = StackRev(wordStack);
```

🧪 **Edge Cases / Notes**:

- If the stack is empty, it is returned unchanged.
- The function uses recursion to reverse the stack.
- The function modifies the original stack rather than creating a new one.





## **Modules based on BSTs**
## 🔧 Function Name: toTree

📁 **Module**: binarySearchTrees.h / binarySearchTrees.c

📌 **Purpose**: Convert a stack to a Binary Search Tree (BST).

🧠 **Description**: This function takes a stack of tree nodes and constructs a balanced Binary Search Tree from them. It pops nodes from the stack one by one and inserts them into the BST in the correct order to maintain the BST property.

⚙️ **Prototype**:

```c
TTree *toTree(TStack *stk);
```

🔢 **Parameters**:

```plaintext
| Name | Type     | Description                                |
|------|----------|--------------------------------------------|
| stk  | TStack*  | Pointer to the stack to convert to a BST   |
```

🔁 **Return**:

- `TTree*` – Pointer to the root of the newly created BST.


🚩 **Pre-conditions**:

- The stack must be properly initialized.
- Each node in the stack must contain valid word data.


✅ **Post-conditions**:

- A new BST is created with nodes from the stack.
- The stack is emptied during the process.
- The BST maintains the binary search tree property (left child < parent < right child).


💡 **Example Usage**:

```c
TStack *wordStack = createStack();
// Push some nodes to the stack
push(wordStack, createTreeNode("apple", synonymList, antonymList));
push(wordStack, createTreeNode("banana", synonymList, antonymList));
push(wordStack, createTreeNode("cherry", synonymList, antonymList));

TTree *wordTree = toTree(wordStack);
// Now wordTree contains a BST with the words from the stack
```

🧪 **Edge Cases / Notes**:

- If the stack is empty, the function returns NULL.
- The function consumes the stack, so the stack will be empty after the function call.
- The order of insertion into the BST depends on the order of popping from the stack.


## 🔧 Function Name: fillTree

📁 **Module**: binarySearchTrees.h / binarySearchTrees.c

📌 **Purpose**: Create a BST filled with words from a file.

🧠 **Description**: This function reads a file containing words with their synonyms and antonyms, and constructs a Binary Search Tree from them. Each line in the file should follow a specific format with words, synonyms, and antonyms separated by delimiters.

⚙️ **Prototype**:

```c
TTree *fillTree(File *f);
```

🔢 **Parameters**:

```plaintext
| Name | Type     | Description                                |
|------|----------|--------------------------------------------|
| f    | File*    | Pointer to the file containing word data   |
```

🔁 **Return**:

- `TTree*` – Pointer to the root of the newly created BST.


🚩 **Pre-conditions**:

- The file must be properly opened and readable.
- The file must follow the expected format with words, synonyms, and antonyms.
- Each line should have the format: `word=synonym1=synonym2...#antonym1=antonym2...`


✅ **Post-conditions**:

- A new BST is created with nodes containing words, their synonyms, and antonyms from the file.
- The BST maintains the binary search tree property.
- The file is closed after reading.


💡 **Example Usage**:

```c
FILE *wordFile = fopen("dictionary.txt", "r");
if (wordFile) {
    TTree *wordTree = fillTree(wordFile);
    // Now wordTree contains a BST with words from the file
    // No need to close the file as fillTree does it
}
```

🧪 **Edge Cases / Notes**:

- The function handles lines with missing antonyms (lines without the # delimiter).
- The function prints status messages during the tree construction process.
- If the file cannot be opened, the function returns NULL and prints an error message.
- If the file is empty or contains no valid entries, the function returns NULL.


## 🔧 Function Name: getInfWordTree

📁 **Module**: binarySearchTrees.h / binarySearchTrees.c

📌 **Purpose**: Retrieve information about a specific word from the BST.

🧠 **Description**: This function searches for a specific word in the Binary Search Tree and returns the node containing that word. This allows access to the word's synonyms, antonyms, and other information stored in the node.

⚙️ **Prototype**:

```c
TTree *getInfWordTree(TTree *tr, char *word);
```

🔢 **Parameters**:

```plaintext
| Name | Type     | Description                                |
|------|----------|--------------------------------------------|
| tr   | TTree*   | Pointer to the root of the BST to search   |
| word | char*    | The word to search for in the BST          |
```

🔁 **Return**:

- `TTree*` – Pointer to the node containing the word, or NULL if the word is not found.


🚩 **Pre-conditions**:

- The BST must be properly initialized.
- The word parameter must be a valid null-terminated string.


✅ **Post-conditions**:

- The function returns a pointer to the node containing the word if found.
- The BST structure is not modified.


💡 **Example Usage**:

```c
TTree *wordTree = fillTree(wordFile);
char searchWord[] = "happy";
TTree *wordNode = getInfWordTree(wordTree, searchWord);
if (wordNode) {
    printf("Found word: %s\n", wordNode->word);
    printf("Synonyms: ");
    printWordNodeList(wordNode->synonym);
    printf("Antonyms: ");
    printWordNodeList(wordNode->antonym);
}
```

🧪 **Edge Cases / Notes**:

- If the tree is empty (tr is NULL), the function returns NULL.
- If the word is not found in the tree, the function returns NULL.
- The function uses binary search tree properties to efficiently find the word.


## 🔧 Function Name: AddWordBST

📁 **Module**: binarySearchTrees.h / binarySearchTrees.c

📌 **Purpose**: Add a word with its synonyms and antonyms to a sorted BST.

🧠 **Description**: This function adds a new word along with its synonyms and antonyms to a Binary Search Tree. It maintains the BST property by inserting the word in the correct position based on lexicographical order. The function also updates a stack with the newly created node.

⚙️ **Prototype**:

```c
void AddWordBST(TTree *tr, char *word, WordNode *synonyms, WordNode *antonyms, TStack **stk);
```

🔢 **Parameters**:

```plaintext
| Name     | Type       | Description                                |
|----------|------------|--------------------------------------------|
| tr       | TTree*     | Pointer to the root of the BST             |
| word     | char*      | The word to add to the BST                 |
| synonyms | WordNode*  | Linked list of synonyms for the word       |
| antonyms | WordNode*  | Linked list of antonyms for the word       |
| stk      | TStack**   | Pointer to a stack to store the new node   |
```

🔁 **Return**:

- `void` – No return value. The BST is modified through the tr parameter and the stack is updated through the stk parameter.


🚩 **Pre-conditions**:

- The word parameter must be a valid null-terminated string.
- The synonyms and antonyms parameters must be properly initialized linked lists (can be NULL).
- Memory must be available for allocation of a new node.


✅ **Post-conditions**:

- A new node containing the word, its synonyms, and antonyms is added to the BST.
- The BST property is maintained.
- The stack is updated with the new node.


💡 **Example Usage**:

```c
TTree *wordTree = NULL;
TStack *nodeStack = createStack();
WordNode *synonyms = NULL;
WordNode *antonyms = NULL;

insertAtEnd(&synonyms, "joyful");
insertAtEnd(&synonyms, "glad");
insertAtEnd(&antonyms, "sad");
insertAtEnd(&antonyms, "unhappy");

AddWordBST(wordTree, "happy", synonyms, antonyms, &nodeStack);
```

🧪 **Edge Cases / Notes**:

- If the tree is empty (tr is NULL), a new tree is created with the word as the root.
- If the stack pointer is NULL, a new stack is created.
- The function uses recursion to find the correct position for the new word.


## 🔧 Function Name: deleteWordBST

📁 **Module**: binarySearchTrees.h / binarySearchTrees.c

📌 **Purpose**: Delete a word from the BST.

🧠 **Description**: This function removes a node containing a specific word from the Binary Search Tree. It maintains the BST property by properly handling the three cases of node deletion: leaf node, node with one child, and node with two children.

⚙️ **Prototype**:

```c
TTree *deleteWordBST(TTree *tr, char *word);
```

🔢 **Parameters**:

```plaintext
| Name | Type     | Description                                |
|------|----------|--------------------------------------------|
| tr   | TTree*   | Pointer to the root of the BST             |
| word | char*    | The word to delete from the BST            |
```

🔁 **Return**:

- `TTree*` – Pointer to the root of the modified BST.


🚩 **Pre-conditions**:

- The BST must be properly initialized.
- The word parameter must be a valid null-terminated string.


✅ **Post-conditions**:

- If the word is found, the node containing it is removed from the BST.
- The BST property is maintained after deletion.
- Memory for the deleted node is freed.


💡 **Example Usage**:

```c
TTree *wordTree = fillTree(wordFile);
char wordToDelete[] = "happy";
wordTree = deleteWordBST(wordTree, wordToDelete);
```

🧪 **Edge Cases / Notes**:

- If the tree is empty (tr is NULL), the function returns NULL.
- If the word is not found in the tree, the tree remains unchanged.
- For a node with two children, the function finds the in-order successor (smallest node in the right subtree), copies its data to the current node, and then deletes the successor.


## 🔧 Function Name: UpdateWordBST

📁 **Module**: binarySearchTrees.h / binarySearchTrees.c

📌 **Purpose**: Update a word's synonym and antonym in the BST.

🧠 **Description**: This function finds a specific word in the Binary Search Tree and updates its synonyms and antonyms by adding new entries to the existing lists. It does not replace the existing lists but appends to them.

⚙️ **Prototype**:

```c
TTree *UpdateWordBST(TTree *tr, char *word, char *syne, char *anton);
```

🔢 **Parameters**:

```plaintext
| Name  | Type     | Description                                |
|-------|----------|--------------------------------------------|
| tr    | TTree*   | Pointer to the root of the BST             |
| word  | char*    | The word to update in the BST              |
| syne  | char*    | New synonym to add to the word             |
| anton | char*    | New antonym to add to the word             |
```

🔁 **Return**:

- `TTree*` – Pointer to the root of the BST (unchanged).


🚩 **Pre-conditions**:

- The BST must be properly initialized.
- The word, syne, and anton parameters must be valid null-terminated strings.


✅ **Post-conditions**:

- If the word is found, its synonym and antonym lists are updated with the new entries.
- The BST structure remains unchanged.


💡 **Example Usage**:

```c
TTree *wordTree = fillTree(wordFile);
char word[] = "happy";
char newSynonym[] = "cheerful";
char newAntonym[] = "miserable";
wordTree = UpdateWordBST(wordTree, word, newSynonym, newAntonym);
```

🧪 **Edge Cases / Notes**:

- If the tree is empty or the word is not found, the function returns the original tree without changes.
- The function adds the new synonym and antonym to the existing lists, it does not replace them.
- Memory for the new synonym and antonym entries is allocated within the function.


## 🔧 Function Name: TraversalBSTinOrder

📁 **Module**: binarySearchTrees.h / binarySearchTrees.c

📌 **Purpose**: Perform an in-order traversal of the BST.

🧠 **Description**: This function traverses the Binary Search Tree in in-order fashion (left subtree, root, right subtree) and prints the details of each node. In-order traversal of a BST visits nodes in ascending order of their keys.

⚙️ **Prototype**:

```c
void TraversalBSTinOrder(TTree *tr);
```

🔢 **Parameters**:

```plaintext
| Name | Type     | Description                                |
|------|----------|--------------------------------------------|
| tr   | TTree*   | Pointer to the root of the BST to traverse |
```

🔁 **Return**:

- `void` – No return value. Node details are printed to standard output.


🚩 **Pre-conditions**:

- The BST must be properly initialized (can be NULL for empty tree).


✅ **Post-conditions**:

- Details of each node in the BST are printed in in-order sequence.
- The BST structure remains unchanged.


💡 **Example Usage**:

```c
TTree *wordTree = fillTree(wordFile);
printf("In-order traversal of the BST:\n");
TraversalBSTinOrder(wordTree);
```

🧪 **Edge Cases / Notes**:

- If the tree is empty (tr is NULL), the function returns without printing anything.
- The function uses recursion for traversal, so very deep trees might cause stack overflow.
- In-order traversal of a BST prints words in lexicographical (alphabetical) order.


## 🔧 Function Name: TraversalBSTpreOrder

📁 **Module**: binarySearchTrees.h / binarySearchTrees.c

📌 **Purpose**: Perform a pre-order traversal of the BST.

🧠 **Description**: This function traverses the Binary Search Tree in pre-order fashion (root, left subtree, right subtree) and prints the details of each node. Pre-order traversal is useful for creating a copy of the tree or for prefix expression evaluation.

⚙️ **Prototype**:

```c
void TraversalBSTpreOrder(TTree *tr);
```

🔢 **Parameters**:

```plaintext
| Name | Type     | Description                                |
|------|----------|--------------------------------------------|
| tr   | TTree*   | Pointer to the root of the BST to traverse |
```

🔁 **Return**:

- `void` – No return value. Node details are printed to standard output.


🚩 **Pre-conditions**:

- The BST must be properly initialized (can be NULL for empty tree).


✅ **Post-conditions**:

- Details of each node in the BST are printed in pre-order sequence.
- The BST structure remains unchanged.


💡 **Example Usage**:

```c
TTree *wordTree = fillTree(wordFile);
printf("Pre-order traversal of the BST:\n");
TraversalBSTpreOrder(wordTree);
```

🧪 **Edge Cases / Notes**:

- If the tree is empty (tr is NULL), the function returns without printing anything.
- The function uses recursion for traversal, so very deep trees might cause stack overflow.
- Pre-order traversal visits the root before its children, which can be useful for creating a copy of the tree.


## 🔧 Function Name: TraversalBSTpostOrder

📁 **Module**: binarySearchTrees.h / binarySearchTrees.c

📌 **Purpose**: Perform a post-order traversal of the BST.

🧠 **Description**: This function traverses the Binary Search Tree in post-order fashion (left subtree, right subtree, root) and prints the details of each node. Post-order traversal is useful for deleting the tree or for postfix expression evaluation.

⚙️ **Prototype**:

```c
void TraversalBSTpostOrder(TTree *tr);
```

🔢 **Parameters**:

```plaintext
| Name | Type     | Description                                |
|------|----------|--------------------------------------------|
| tr   | TTree*   | Pointer to the root of the BST to traverse |
```

🔁 **Return**:

- `void` – No return value. Node details are printed to standard output.


🚩 **Pre-conditions**:

- The BST must be properly initialized (can be NULL for empty tree).


✅ **Post-conditions**:

- Details of each node in the BST are printed in post-order sequence.
- The BST structure remains unchanged.


💡 **Example Usage**:

```c
TTree *wordTree = fillTree(wordFile);
printf("Post-order traversal of the BST:\n");
TraversalBSTpostOrder(wordTree);
```

🧪 **Edge Cases / Notes**:

- If the tree is empty (tr is NULL), the function returns without printing anything.
- The function uses recursion for traversal, so very deep trees might cause stack overflow.
- Post-order traversal visits the root after its children, which is useful when deleting a tree (to avoid memory leaks).


## 🔧 Function Name: HighSizeBST

📁 **Module**: binarySearchTrees.h / binarySearchTrees.c

📌 **Purpose**: Print the height and size of the BST.

🧠 **Description**: This function calculates and prints two key metrics of a Binary Search Tree: its height (the length of the longest path from the root to a leaf) and its size (the total number of nodes). It uses helper functions to compute these values recursively.

⚙️ **Prototype**:

```c
void HighSizeBST(TTree *tr);
```

🔢 **Parameters**:

```plaintext
| Name | Type     | Description                                |
|------|----------|--------------------------------------------|
| tr   | TTree*   | Pointer to the root of the BST             |
```

🔁 **Return**:

- `void` – No return value. The height and size are printed to standard output.


🚩 **Pre-conditions**:

- The BST must be properly initialized (can be NULL for empty tree).


✅ **Post-conditions**:

- The height and size of the BST are printed to standard output.
- The BST structure remains unchanged.


💡 **Example Usage**:

```c
TTree *wordTree = fillTree(wordFile);
HighSizeBST(wordTree);
// Output might be:
// The size of the BST is: 42
// The height of the BST is: 7
```

🧪 **Edge Cases / Notes**:

- If the tree is empty (tr is NULL), the size will be 0 and the height will be -1.
- The height of a tree with only a root node is 0.
- The function uses helper functions `HighBSTHelper` and `SizeBSTHelper` to calculate the height and size recursively.


## 🔧 Function Name: LowestCommonAncestor

📁 **Module**: binarySearchTrees.h / binarySearchTrees.c

📌 **Purpose**: Find the lowest common ancestor of two nodes in the BST.

🧠 **Description**: This function finds the lowest common ancestor (LCA) of two nodes in a Binary Search Tree. The LCA is the deepest node that has both nodes as descendants. In a BST, this is the first node encountered where the two target words would split to different subtrees.

⚙️ **Prototype**:

```c
TTree *LowestCommonAncestor(TTree *tr, char *word1, char *word2);
```

🔢 **Parameters**:

```plaintext
| Name  | Type     | Description                                |
|-------|----------|--------------------------------------------|
| tr    | TTree*   | Pointer to the root of the BST             |
| word1 | char*    | First word to find the LCA for             |
| word2 | char*    | Second word to find the LCA for            |
```

🔁 **Return**:

- `TTree*` – Pointer to the lowest common ancestor node, or NULL if not found.


🚩 **Pre-conditions**:

- The BST must be properly initialized.
- Both word1 and word2 must be valid null-terminated strings.
- Both words should exist in the BST for meaningful results.


✅ **Post-conditions**:

- The function returns a pointer to the lowest common ancestor node if found.
- The BST structure remains unchanged.


💡 **Example Usage**:

```c
TTree *wordTree = fillTree(wordFile);
char word1[] = "happy";
char word2[] = "joyful";
TTree *lca = LowestCommonAncestor(wordTree, word1, word2);
if (lca) {
    printf("The lowest common ancestor of '%s' and '%s' is '%s'\n", word1, word2, lca->word);
}
```

🧪 **Edge Cases / Notes**:

- If the tree is empty (tr is NULL), the function returns NULL.
- If one or both words are not in the tree, the function may return an incorrect result.
- The function takes advantage of the BST property to efficiently find the LCA without searching the entire tree.


## 🔧 Function Name: CountNodesRanges

📁 **Module**: binarySearchTrees.h / binarySearchTrees.c

📌 **Purpose**: Count the number of nodes with word lengths within a given range.

🧠 **Description**: This function counts the number of nodes in a Binary Search Tree where the length of the word falls within a specified range [l, h]. It recursively traverses the tree and increments the count for each node that meets the criteria.

⚙️ **Prototype**:

```c
int CountNodesRanges(TTree *tr, int l, int h);
```

🔢 **Parameters**:

```plaintext
| Name | Type     | Description                                |
|------|----------|--------------------------------------------|
| tr   | TTree*   | Pointer to the root of the BST             |
| l    | int      | Lower bound of the word length range       |
| h    | int      | Upper bound of the word length range       |
```

🔁 **Return**:

- `int` – The number of nodes with word lengths within the specified range.


🚩 **Pre-conditions**:

- The BST must be properly initialized (can be NULL for empty tree).
- l and h must be valid integers with l <= h.


✅ **Post-conditions**:

- The function returns the count of nodes with word lengths in the range [l, h].
- The BST structure remains unchanged.


💡 **Example Usage**:

```c
TTree *wordTree = fillTree(wordFile);
int shortWords = CountNodesRanges(wordTree, 1, 4); // Count words with 1-4 characters
int mediumWords = CountNodesRanges(wordTree, 5, 8); // Count words with 5-8 characters
int longWords = CountNodesRanges(wordTree, 9, 20); // Count words with 9-20 characters

printf("Short words: %d\n", shortWords);
printf("Medium words: %d\n", mediumWords);
printf("Long words: %d\n", longWords);
```

🧪 **Edge Cases / Notes**:

- If the tree is empty (tr is NULL), the function returns 0.
- The function counts nodes based on the length of the word stored in each node, not based on the node's position in the tree.
- The function uses recursion to traverse the entire tree, as the word length is not related to the BST ordering.


## 🔧 Function Name: inOrderSuccesor

📁 **Module**: binarySearchTrees.h / binarySearchTrees.c

📌 **Purpose**: Find the in-order successor of a given node in the BST.

🧠 **Description**: This function finds the in-order successor of a specified word in a Binary Search Tree. The in-order successor is the node that would come immediately after the given node in an in-order traversal of the tree.

⚙️ **Prototype**:

```c
TTree *inOrderSuccesor(TTree *tr, char *word);
```

🔢 **Parameters**:

```plaintext
| Name | Type     | Description                                |
|------|----------|--------------------------------------------|
| tr   | TTree*   | Pointer to the root of the BST             |
| word | char*    | The word to find the successor for         |
```

🔁 **Return**:

- `TTree*` – Pointer to the in-order successor node, or NULL if there is no successor.


🚩 **Pre-conditions**:

- The BST must be properly initialized.
- The word parameter must be a valid null-terminated string.
- The word should exist in the BST for meaningful results.


✅ **Post-conditions**:

- The function returns a pointer to the in-order successor node if found.
- The BST structure remains unchanged.


💡 **Example Usage**:

```c
TTree *wordTree = fillTree(wordFile);
char word[] = "happy";
TTree *successor = inOrderSuccesor(wordTree, word);
if (successor) {
    printf("The in-order successor of '%s' is '%s'\n", word, successor->word);
} else {
    printf("'%s' has no in-order successor\n", word);
}
```

🧪 **Edge Cases / Notes**:

- If the tree is empty (tr is NULL), the function returns NULL.
- If the word is not found in the tree, the function returns NULL.
- If the word is the largest in the tree, it has no successor and the function returns NULL.
- The function uses a queue to store the in-order traversal of the tree, which may be memory-intensive for large trees.


## 🔧 Function Name: BSTMirror

📁 **Module**: binarySearchTrees.h / binarySearchTrees.c

📌 **Purpose**: Create a mirror image of the BST.

🧠 **Description**: This function transforms a Binary Search Tree into its mirror image by swapping the left and right children of every node. After this operation, the tree is no longer a BST (unless it was a single node or empty), but a mirror image of the original tree.

⚙️ **Prototype**:

```c
TTree *BSTMirror(TTree *tr);
```

🔢 **Parameters**:

```plaintext
| Name | Type     | Description                                |
|------|----------|--------------------------------------------|
| tr   | TTree*   | Pointer to the root of the BST to mirror   |
```

🔁 **Return**:

- `TTree*` – Pointer to the root of the mirrored tree.


🚩 **Pre-conditions**:

- The BST must be properly initialized (can be NULL for empty tree).


✅ **Post-conditions**:

- The tree is transformed into its mirror image.
- The left and right children of every node are swapped.
- The original tree structure is modified in place.


💡 **Example Usage**:

```c
TTree *wordTree = fillTree(wordFile);
printf("Original tree (in-order):\n");
TraversalBSTinOrder(wordTree);

wordTree = BSTMirror(wordTree);
printf("\nMirrored tree (in-order):\n");
TraversalBSTinOrder(wordTree);
```

🧪 **Edge Cases / Notes**:

- If the tree is empty (tr is NULL), the function returns NULL.
- After mirroring, an in-order traversal will visit nodes in reverse order compared to the original tree.
- The mirrored tree is no longer a BST unless the original tree had at most one node.
- The function modifies the tree in place rather than creating a new tree.


## 🔧 Function Name: isBalencedBST

📁 **Module**: binarySearchTrees.h / binarySearchTrees.c

📌 **Purpose**: Check if a BST is balanced.

🧠 **Description**: This function determines whether a Binary Search Tree is balanced. A balanced BST is one where the heights of the left and right subtrees of every node differ by at most 1. The function recursively checks this property for every node in the tree.

⚙️ **Prototype**:

```c
bool isBalencedBST(TTree *tr);
```

🔢 **Parameters**:

```plaintext
| Name | Type     | Description                                |
|------|----------|--------------------------------------------|
| tr   | TTree*   | Pointer to the root of the BST to check    |
```

🔁 **Return**:

- `bool` – true if the BST is balanced, false otherwise.


🚩 **Pre-conditions**:

- The BST must be properly initialized (can be NULL for empty tree).
- The stdbool.h header must be included for the bool type.


✅ **Post-conditions**:

- The function returns true if the BST is balanced, false otherwise.
- The BST structure remains unchanged.


💡 **Example Usage**:

```c
TTree *wordTree = fillTree(wordFile);
if (isBalencedBST(wordTree)) {
    printf("The BST is balanced.\n");
} else {
    printf("The BST is not balanced.\n");
}
```

🧪 **Edge Cases / Notes**:

- An empty tree (tr is NULL) is considered balanced and the function returns true.
- A tree with only a root node is balanced.
- The function uses the `HighBSTHelper` function to calculate the height of subtrees.
- The function has O(n²) time complexity in its current implementation, as it recalculates heights for each node.


## 🔧 Function Name: BTSMerge

📁 **Module**: binarySearchTrees.h / binarySearchTrees.c

📌 **Purpose**: Merge two BSTs into a single balanced BST.

🧠 **Description**: This function combines two Binary Search Trees into a single balanced BST. It first performs in-order traversals of both trees to get sorted sequences of nodes, then merges these sequences, and finally constructs a balanced BST from the merged sequence.

⚙️ **Prototype**:

```c
TTree *BTSMerge(TTree *tr1, TTree *tr2);
```

🔢 **Parameters**:

```plaintext
| Name | Type     | Description                                |
|------|----------|--------------------------------------------|
| tr1  | TTree*   | Pointer to the root of the first BST       |
| tr2  | TTree*   | Pointer to the root of the second BST      |
```

🔁 **Return**:

- `TTree*` – Pointer to the root of the merged balanced BST.


🚩 **Pre-conditions**:

- Both BSTs must be properly initialized (can be NULL for empty trees).
- Memory must be available for the new tree nodes and temporary data structures.


✅ **Post-conditions**:

- A new balanced BST is created containing all nodes from both input trees.
- The original trees remain unchanged.
- The merged tree maintains the BST property.


💡 **Example Usage**:

```c
TTree *dictionaryTree1 = fillTree(dictionaryFile1);
TTree *dictionaryTree2 = fillTree(dictionaryFile2);

TTree *mergedDictionary = BTSMerge(dictionaryTree1, dictionaryTree2);
printf("Merged dictionary:\n");
TraversalBSTinOrder(mergedDictionary);
```

🧪 **Edge Cases / Notes**:

- If both input trees are empty (tr1 and tr2 are NULL), the function returns NULL.
- If one of the input trees is empty, the function returns a copy of the other tree.
- The function creates a balanced BST by selecting the middle element of the sorted sequence as the root.
- The function uses queues to store the in-order traversals and an array to access elements by index.
- Memory for the array is dynamically allocated and freed before the function returns.

## **Modules based on Recursion**

## 🔧 Function Name: countWordOccurrence

📁 **Module**: recursion.h / recursion.c

📌 **Purpose**: Count the number of occurrences of a word in a file using recursion.

🧠 **Description**: This function recursively reads lines from a file and counts how many times a specific word appears in the text. It uses string searching to find all instances of the word in each line and accumulates the count through recursive calls.

⚙️ **Prototype**:

```c
int countWordOccurrence(FILE *f, const char *word);
```

🔢 **Parameters**:

```plaintext
| Name | Type     | Description                                |
|------|----------|--------------------------------------------|
| f    | FILE*    | Pointer to the file to search through      |
| word | char*    | The word to count occurrences of           |
```

🔁 **Return**:

- `int` – The total number of occurrences of the word in the file.


🚩 **Pre-conditions**:

- The file pointer must be valid and open for reading.
- The word parameter must be a valid null-terminated string.
- The file position indicator should be at the beginning of the file or at the position from which you want to start counting.


✅ **Post-conditions**:

- The file position indicator will be at the end of the file after the function completes.
- The function does not modify the file content.


💡 **Example Usage**:

```c
FILE *file = fopen("sample.txt", "r");
int count = countWordOccurrence(file, "hello");
printf("The word 'hello' appears %d times in the file.\n", count);
fclose(file);
```

🧪 **Edge Cases / Notes**:

- The function uses recursion, so very large files might cause stack overflow.
- The function counts overlapping occurrences (if applicable).
- The search is case-sensitive.


## 🔧 Function Name: removeWordOccurence

📁 **Module**: recursion.h / recursion.c

📌 **Purpose**: Remove all occurrences of a word from a file using recursion.

🧠 **Description**: This function recursively processes a file line by line, removing all instances of a specified word from each line. It creates a temporary file to store the modified content and returns a pointer to this temporary file.

⚙️ **Prototype**:

```c
FILE *removeWordOccurence(FILE *f, char *word);
```

🔢 **Parameters**:

```plaintext
| Name | Type     | Description                                |
|------|----------|--------------------------------------------|
| f    | FILE*    | Pointer to the file to modify              |
| word | char*    | The word to remove from the file           |
```

🔁 **Return**:

- `FILE*` – Pointer to a temporary file containing the modified content, or NULL if an error occurs.


🚩 **Pre-conditions**:

- The file pointer must be valid and open for reading.
- The word parameter must be a valid null-terminated string.
- The function must have write permissions to create a temporary file.


✅ **Post-conditions**:

- A new temporary file is created with all occurrences of the word removed.
- The original file is closed.
- The caller is responsible for closing the returned file pointer and handling the temporary file.


💡 **Example Usage**:

```c
FILE *file = fopen("sample.txt", "r");
FILE *tempFile = removeWordOccurence(file, "hello");
if (tempFile != NULL) {
    fclose(tempFile);
    replaceFile("sample.txt", "temp.txt"); // Helper function to replace original with temp
}
```

🧪 **Edge Cases / Notes**:

- The function creates a temporary file named "temp.txt" in the current directory.
- The original file is closed by the function, so the caller should not attempt to close it again.
- The caller is responsible for replacing the original file with the temporary file if desired.
- The function uses recursion, so very large files might cause stack overflow.


## 🔧 Function Name: replaceWordOccurence

📁 **Module**: recursion.h / recursion.c

📌 **Purpose**: Replace all occurrences of a word in a file with another string using recursion.

🧠 **Description**: This function recursively processes a file line by line, replacing all instances of a specified word with a replacement string. It handles both cases where the replacement is shorter or longer than the original word, and creates a temporary file to store the modified content.

⚙️ **Prototype**:

```c
FILE *replaceWordOccurence(FILE *f, char *word, char *rep);
```

🔢 **Parameters**:

```plaintext
| Name | Type     | Description                                |
|------|----------|--------------------------------------------|
| f    | FILE*    | Pointer to the file to modify              |
| word | char*    | The word to be replaced                    |
| rep  | char*    | The replacement string                     |
```

🔁 **Return**:

- `FILE*` – Pointer to a temporary file containing the modified content, or NULL if an error occurs.


🚩 **Pre-conditions**:

- The file pointer must be valid and open for reading.
- The word and rep parameters must be valid null-terminated strings.
- The function must have write permissions to create a temporary file.


✅ **Post-conditions**:

- A new temporary file is created with all occurrences of the word replaced.
- The original file is closed.
- The caller is responsible for closing the returned file pointer and handling the temporary file.


💡 **Example Usage**:

```c
FILE *file = fopen("sample.txt", "r");
FILE *tempFile = replaceWordOccurence(file, "hello", "hi");
if (tempFile != NULL) {
    fclose(tempFile);
    replaceFile("sample.txt", "temp.txt"); // Helper function to replace original with temp
}
```

🧪 **Edge Cases / Notes**:

- The function handles both cases where the replacement string is shorter or longer than the original word.
- The function creates a temporary file named "temp.txt" in the current directory.
- The original file is closed by the function, so the caller should not attempt to close it again.
- The caller is responsible for replacing the original file with the temporary file if desired.
- The function uses recursion, so very large files might cause stack overflow.


## 🔧 Function Name: wordPermutation

📁 **Module**: recursion.h / recursion.c

📌 **Purpose**: Print all permutations of a given word using recursion.

🧠 **Description**: This function generates and prints all possible arrangements of characters in a word. It uses a recursive approach to swap characters and build different permutations. The function works with the helper functions `permute` and `loop` to generate all permutations.

⚙️ **Prototype**:

```c
void wordPermutation(char *word);
```

🔢 **Parameters**:

```plaintext
| Name | Type     | Description                                |
|------|----------|--------------------------------------------|
| word | char*    | The word to generate permutations for      |
```

🔁 **Return**:

- `void` – No return value. Permutations are printed to standard output.


🚩 **Pre-conditions**:

- The word parameter must be a valid null-terminated string.
- The word should not be too long to avoid excessive permutations (factorial growth).


✅ **Post-conditions**:

- All permutations of the word are printed to standard output.
- The original word may be modified during the process but is restored before the function returns.


💡 **Example Usage**:

```c
char word[] = "abc";
wordPermutation(word);
// Output: abc acb bac bca cab cba
```

🧪 **Edge Cases / Notes**:

- The number of permutations grows factorially with the length of the word (n!).
- For words longer than 10 characters, the number of permutations becomes extremely large.
- The function prints permutations separated by tabs.
- The function does not handle duplicate characters specially; it will print duplicate permutations if the input word contains duplicate characters.


## 🔧 Function Name: subseqWord

📁 **Module**: recursion.h / recursion.c

📌 **Purpose**: Generate all possible subsequences of a given word using recursion.

🧠 **Description**: This function prints all possible subsequences of a word. A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements. The function uses a recursive approach with the helper function `generateSubsequences`.

⚙️ **Prototype**:

```c
void subseqWord(char *word);
```

🔢 **Parameters**:

```plaintext
| Name | Type     | Description                                |
|------|----------|--------------------------------------------|
| word | char*    | The word to generate subsequences for      |
```

🔁 **Return**:

- `void` – No return value. Subsequences are printed to standard output.


🚩 **Pre-conditions**:

- The word parameter must be a valid null-terminated string.
- The word should not be too long to avoid excessive subsequences (2^n growth).


✅ **Post-conditions**:

- All subsequences of the word are printed to standard output.
- The original word is not modified.


💡 **Example Usage**:

```c
char word[] = "abc";
subseqWord(word);
// Output: abc ab ac a bc b c [empty string]
```

🧪 **Edge Cases / Notes**:

- The number of subsequences grows exponentially with the length of the word (2^n).
- For words longer than 20 characters, the number of subsequences becomes extremely large.
- The function prints subsequences separated by tabs.
- The empty string is considered a valid subsequence and will be printed.


## 🔧 Function Name: longestSubseqWord

📁 **Module**: recursion.h / recursion.c

📌 **Purpose**: Find the length of the longest common subsequence between two strings using recursion.

🧠 **Description**: This function calculates the length of the longest subsequence that is common to both input strings. It uses a recursive approach with character-by-character comparison and the helper function `max` to determine the maximum length.

⚙️ **Prototype**:

```c
int longestSubseqWord(char *word1, char *word2);
```

🔢 **Parameters**:

```plaintext
| Name  | Type     | Description                                |
|-------|----------|--------------------------------------------|
| word1 | char*    | First string for comparison                |
| word2 | char*    | Second string for comparison               |
```

🔁 **Return**:

- `int` – The length of the longest common subsequence.


🚩 **Pre-conditions**:

- Both word1 and word2 must be valid null-terminated strings.
- The strings should not be too long to avoid excessive recursion depth.


✅ **Post-conditions**:

- The function returns the length of the longest common subsequence.
- The input strings are not modified.


💡 **Example Usage**:

```c
char word1[] = "abcde";
char word2[] = "ace";
int length = longestSubseqWord(word1, word2);
printf("Length of longest common subsequence: %d\n", length);
// Output: Length of longest common subsequence: 3
```

🧪 **Edge Cases / Notes**:

- The function has exponential time complexity in its current implementation.
- For long strings, the function may cause stack overflow due to deep recursion.
- A more efficient implementation would use dynamic programming with memoization.
- The function is case-sensitive in its comparison.


## 🔧 Function Name: distinctSubseqWord

📁 **Module**: recursion.h / recursion.c

📌 **Purpose**: Count the number of distinct subsequences of a given word using recursion.

🧠 **Description**: This function calculates the total number of distinct subsequences that can be formed from the input word. It uses a recursive approach that handles duplicate characters by subtracting the count of subsequences that would be duplicated.

⚙️ **Prototype**:

```c
int distinctSubseqWord(char *word);
```

🔢 **Parameters**:

```plaintext
| Name | Type     | Description                                |
|------|----------|--------------------------------------------|
| word | char*    | The word to count distinct subsequences for|
```

🔁 **Return**:

- `int` – The number of distinct subsequences.


🚩 **Pre-conditions**:

- The word parameter must be a valid null-terminated string.
- The word should not be too long to avoid excessive recursion depth.


✅ **Post-conditions**:

- The function returns the count of distinct subsequences.
- The input string is not modified.


💡 **Example Usage**:

```c
char word[] = "banana";
int count = distinctSubseqWord(word);
printf("Number of distinct subsequences: %d\n", count);
// Output will account for the repeated 'a' and 'n' characters
```

🧪 **Edge Cases / Notes**:

- The function has exponential time complexity in its current implementation.
- For words with many duplicate characters, the calculation becomes more complex.
- The empty string is counted as a valid subsequence.
- For long strings, the function may cause stack overflow due to deep recursion.


## 🔧 Function Name: isPalindromWord

📁 **Module**: recursion.h / recursion.c

📌 **Purpose**: Check if a given word is a palindrome using recursion.

🧠 **Description**: This function determines whether a word reads the same backward as forward. It uses a recursive approach by comparing the first and last characters, then recursively checking the substring between them.

⚙️ **Prototype**:

```c
bool isPalindromWord(char *word);
```

🔢 **Parameters**:

```plaintext
| Name | Type     | Description                                |
|------|----------|--------------------------------------------|
| word | char*    | The word to check if it's a palindrome     |
```

🔁 **Return**:

- `bool` – true if the word is a palindrome, false otherwise.


🚩 **Pre-conditions**:

- The word parameter must be a valid null-terminated string.
- The stdbool.h header must be included for the bool type.


✅ **Post-conditions**:

- The function returns true if the word is a palindrome, false otherwise.
- The input string may be temporarily modified during processing but is restored before the function returns.


💡 **Example Usage**:

```c
char word1[] = "racecar";
char word2[] = "hello";
printf("%s is %s a palindrome\n", word1, isPalindromWord(word1) ? "" : "not");
printf("%s is %s a palindrome\n", word2, isPalindromWord(word2) ? "" : "not");
// Output:
// racecar is a palindrome
// hello is not a palindrome
```

🧪 **Edge Cases / Notes**:

- The function creates a temporary copy of the string with reduced length for recursive calls.
- Single-character strings are considered palindromes by definition.
- The function is case-sensitive in its comparison.
- The current implementation has a potential memory issue as it doesn't properly null-terminate the temporary string in all cases.

# Optional Part: GUI 📊✨

## Overview 🌟

This document provides an in-depth description of the **Graphical User Interface (GUI)** for a dictionary management system, implemented in C using the **Windows API (Win32)** in `main.c`. The GUI enables users to interact with dictionary-related functions across three categories: **Trees**, **Linked Lists, Stacks, and Queues**, and **Recursion**. It integrates with wrapper functions in `functions_wrapper.c`, leveraging utilities from `code.c`, `code_utils.c`, `tree_utils.c`, `trees.c`, `recursion_utils.c`, and `Recursion_2.c` to manage data structures like Binary Search Trees (BSTs), linked lists, stacks, and queues. The system operates on a dictionary file (`dictinoary.txt`) with a specific format for words, synonyms, and antonyms. 🗂️

This updated documentation incorporates detailed insights from the provided source files, offering:
- Comprehensive function breakdowns with algorithms and edge cases.
- Clarification of inter-file dependencies and data flow.
- Notes on memory management, error handling, and performance.
- Enhanced build instructions and troubleshooting tips.
- Suggestions for addressing limitations (e.g., typos, redundant code).

The GUI provides a user-friendly interface for loading dictionaries, manipulating data structures, and viewing results in a read-only text area, with robust error handling and status feedback. Let’s dive into the details! 🚀

---

## Key Features 🎉

- **Category-Based Navigation**: Select **Trees**, **Linked Lists, Stacks, and Queues**, or **Recursion** via a dropdown menu. 📋
- **Dynamic Function Selection**: Functions update based on category, with argument fields generated dynamically. ⚙️
- **File Input**: A **Browse** button allows loading `dictinoary.txt` for file-based operations. 📂
- **Output Display**: Captures `stdout` output in a read-only text area using temporary files. 📜
- **Status Bar**: Displays states like "Ready" or error messages. 🔔
- **Responsive Design**: Adapts to window resizing for usability. 🖥️
- **Input Validation**: Ensures valid inputs (e.g., loaded tree/list) and shows errors. 🚫

---

## Dictionary File Format 📝

The dictionary file, named `dictinoary.txt` (note the consistent typo across all source files), stores words with their synonyms and antonyms in a structured format. Example:

```
happy=joyful=content#sad=unhappy
sad=unhappy=gloomy#happy=cheerful
```

- **Format**: `word=synonym1=synonym2#antonym1=antonym2`
- **Components**:
  - **Word**: The primary word (e.g., `happy`).
  - **Synonyms**: Zero or more synonyms separated by `=` (e.g., `joyful=content`).
  - **Antonyms**: Zero or more antonyms after `#`, separated by `=` (e.g., `sad=unhappy`).
- **Parsing**:
  - `code.c`: `getSynWords` and `getAntoWords` use `sscanf` to extract word-synonym or word-antonym pairs.
  - `tree_utils.c`/`trees.c`: `fillTree` uses `strtok` to tokenize lines, handling missing `#` by assuming synonyms only.
- **Notes**:
  - The typo `dictinoary.txt` is consistent in `code.c` and other files. Users must name the file `dictinoary.txt` or update the code to expect `dictionary.txt`.
  - Lines without `#` are treated as synonym-only entries in `fillTree`.
  - Buffer sizes (e.g., 170–175 bytes in `code.c`) assume reasonable word lengths but may overflow for very long lines.

---

## Code Structure 🏗️

The GUI is built around `main.c`, supported by source and header files defining data structures, utilities, and wrapper functions. Below is a detailed breakdown of the components and their interactions:

### 1. Data Structures (`unified_data_structures.h`) 🌍
Defined in `unified_data_structures.h`, these structures support dictionary operations:
- **TTree2**: BST node with:
  - `char word[50]`: Primary word.
  - `WordNode *synonym`: Linked list of synonyms.
  - `WordNode *antonym`: Linked list of antonyms.
  - `TTree2 *left, *right`: Child pointers.
- **TList**: Singly linked list with:
  - `Node *head`: Points to a `Node` with `char word[50]`, `char relatedWord[50]`, `int charCount`, `int vowelCount`, and `Node *next`.
- **TList2**: Bidirectional linked list with:
  - `DNode *head, *tail`: `DNode` has `char word[50]`, `char synonym[50]`, `char antonym[50]`, `int charCount`, `int vowelCount`, `DNode *next`, `DNode *prev`.
- **TList3**: Circular linked list with:
  - `CNode *head, *tail`: `CNode` has `char word[50]`, `char synonym[50]`, `char antonym[50]`, `int charCount`, `int vowelCount`, `CNode *next`.
- **TStack**: Stack with:
  - `CNode *head`: Same `CNode` as `TList3`.
- **TStack2**: Character stack with:
  - `TNode *head`: `TNode` has `char c` and `TNode *next`.
- **TQueue**: Queue with:
  - `QNode *front, *rear`: `QNode` has `char word[50]` (or `TTree2 *treeNode` in `trees.c`) and `QNode *next`.
- **WordNode**: Linked list node for synonyms/antonyms in `TTree2`:
  - `char word[50]`, `WordNode *next`.

### 2. File Interactions 📂
- **`main.c`**: GUI logic, calls `fw_*` functions from `functions_wrapper.c`, redirects `stdout` to temporary files.
- **`functions_wrapper.c`**: Wraps functions from `code.c`, `tree_utils.c`, and `recursion_utils.c`, handling file operations and data structure management.
- **`code.c`**: Implements linked list, stack, and queue operations, reading/writing `dictinoary.txt`.
- **`code_utils.c`**: Provides utility functions (e.g., `createNode`, `countVowels`, `getVowelType`) used by `code.c` and others.
- **`tree_utils.c`/`trees.c`**: Implement BST operations, with `fillTree` parsing `dictinoary.txt`. `trees.c` adds `BTSMerge`.
- **`recursion_utils.c`/`Recursion_2.c`**: Implement recursive algorithms and file utilities (e.g., `countWordOccurrence`). `Recursion_2.c` adds `reverseFile`.

**Data Flow**:
1. User selects a function in the GUI (e.g., `fw_fillTree`).
2. `main.c` calls the wrapper in `functions_wrapper.c`.
3. The wrapper opens `dictinoary.txt` (if needed) and calls the core function (e.g., `fillTree` in `tree_utils.c` or `getSynWords` in `code.c`).
4. Core functions use utilities from `code_utils.c` (e.g., `createNode`) or `recursion_utils.c` (e.g., `isPalindromWord`).
5. Output is captured via `stdout` redirection and displayed in the GUI.

### 3. GUI Components (`main.c`) 🛠️
- **`WndProc`**: Handles messages like `WM_CREATE` (initializes controls), `WM_COMMAND` (dropdown/button events), and `WM_SIZE` (resizes layout).
- **`custom_printf`**: Redirects `stdout` to a buffer for GUI display.
- **`OpenFileBrowser`**: Uses `OPENFILENAME` to select `dictinoary.txt`.
- **`ExecuteFunction`**: Runs the selected `fw_*` function, capturing output in a temporary file (e.g., `tree_output.txt`).
- **`UpdateArgsContainer`**: Dynamically creates `Edit` controls for function arguments based on `FunctionDefinition` in `main.c`.
- **Controls**:
  - **Category ComboBox**: Lists `Trees`, `Code`, `Recursion`.
  - **Function ComboBox**: Populates with `fw_*` functions.
  - **Browse Button**: For file selection.
  - **Run Button**: Triggers `ExecuteFunction`.
  - **Result Text Area**: Read-only `Edit` control for output.
  - **Status Bar**: Displays state/error messages.

### 4. Function Categories 📚
Defined via `FunctionCategory` enum in `main.c`:
- **CATEGORY_TREES**: BST operations (e.g., `fw_fillTree`, `fw_deleteWordBST`).
- **CATEGORY_CODE**: Linked lists, stacks, queues (e.g., `fw_getSynWords`, `fw_syllable`).
- **CATEGORY_RECURSION**: Recursive algorithms (e.g., `fw_wordPermutation`, `fw_longestSubseqWord`).

---

## Detailed Implementation 📜

Below is an in-depth look at key functions, their algorithms, and implementation details, grouped by category. I’ll include pseudo-code or flow descriptions for clarity, focusing on critical functions from `code.c`, `tree_utils.c`, `trees.c`, `recursion_utils.c`, and `Recursion_2.c`.

### 1. Trees 🌳
#### `TTree2* fw_fillTree(const char *filename)` (Wraps `fillTree` in `tree_utils.c`)
- **Purpose**: Builds a BST (`TTree2`) from `dictinoary.txt`.
- **Implementation**:
  - Opens `filename` (`dictinoary.txt`) in read mode.
  - Reads lines (up to 500 bytes) using `fgets`.
  - For each line:
    - Removes trailing newline.
    - Checks for `#` delimiter using `strchr`.
    - If `#` is absent, assumes synonyms only; uses `strtok` with `=` to extract word and synonyms.
    - If `#` is present, splits at `#`, then uses `strtok` with `=` for synonyms and antonyms.
    - Creates `WordNode` lists for synonyms and antonyms using `insertAtEnd`.
    - Inserts into BST using `insertBST2`.
  - Prints insertion details (word, synonym count, antonym count) to `stdout`.
  - Returns the BST root or `NULL` on file error.
- **Pseudo-Code**:
  ```plaintext
  FUNCTION fillTree(filename):
      OPEN file as f
      IF f is NULL: PRINT error; RETURN NULL
      root = NULL
      WHILE fgets(line):
          REMOVE newline from line
          hashpos = FIND '#' in line
          IF hashpos is NULL:
              mainWord = strtok(line, '=')
              synonyms = NULL
              WHILE token = strtok(NULL, '='): insertAtEnd(&synonyms, token)
              root = insertBST2(root, mainWord, synonyms, NULL)
          ELSE:
              SET hashpos to '\0'
              mainWord = strtok(line, '=')
              synonyms = NULL
              WHILE token = strtok(NULL, '='): insertAtEnd(&synonyms, token)
              antonyms = NULL
              ant = hashpos + 1
              WHILE token = strtok(ant, '='): insertAtEnd(&antonyms, token)
              root = insertBST2(root, mainWord, synonyms, antonyms)
      CLOSE f
      RETURN root
  ```
- **Edge Cases**:
  - Empty file: Returns `NULL` and prints "Tree is empty".
  - Missing main word: Skips line and prints error.
  - Buffer overflow: Line buffer (500 bytes) may truncate long lines.
- **Memory Management**: Allocates `TTree2` and `WordNode` nodes; user must free the tree (not implemented in `fillTree`).
- **Performance**: O(n log n) average case for BST insertion, where n is the number of words.

#### `TTree2* fw_deleteWordBST(TTree2 *tr, char *word)` (Wraps `deleteWordBST` in `tree_utils.c`)
- **Purpose**: Removes a word from the BST.
- **Implementation**:
  - Recursively searches for the word using `strcmp`.
  - Handles three cases:
    1. **No children**: Frees the node, returns `NULL`.
    2. **One child**: Frees the node, returns the child.
    3. **Two children**: Finds the in-order successor (minimum node in right subtree via `findMinNode2`), copies its data (`word`, `synonym`, `antonym`), and deletes the successor.
  - Uses `copyNodeList` to duplicate synonym/antonym lists.
- **Edge Cases**:
  - Word not found: Returns unchanged tree.
  - Empty tree: Returns `NULL`.
- **Memory Management**: Frees the deleted node; `copyNodeList` allocates new `WordNode` lists.
- **Performance**: O(h) where h is tree height (O(log n) for balanced, O(n) for skewed).

#### `TTree2* BTSMerge(TTree2 *tr1, TTree2 *tr2)` (`trees.c`)
- **Purpose**: Merges two BSTs into a balanced BST.
- **Implementation**:
  - Stores in-order traversals of both trees in queues (`q1`, `q2`) using `StoreBSTinOrder`.
  - Merges queues into a sorted queue (`merged`) by comparing words.
  - Converts the merged queue to an array.
  - Selects the middle element as the root and builds left/right subtrees using `insertBST2`.
- **Pseudo-Code**:
  ```plaintext
  FUNCTION BTSMerge(tr1, tr2):
      IF tr1 is NULL: RETURN tr2
      IF tr2 is NULL: RETURN tr1
      q1 = StoreBSTinOrder(tr1)
      q2 = StoreBSTinOrder(tr2)
      merged = createQueue()
      WHILE q1 and q2 not empty:
          IF q1.front.word ≤ q2.front.word:
              enqueue(merged, dequeue(q1))
          ELSE:
              enqueue(merged, dequeue(q2))
      WHILE q1 not empty: enqueue(merged, dequeue(q1))
      WHILE q2 not empty: enqueue(merged, dequeue(q2))
      count = lenQueue(merged)
      IF count = 0: RETURN NULL
      array = CONVERT merged to array
      mid = count / 2
      root = createTreeNode2(array[mid].word, array[mid].synonym, array[mid].antonym)
      FOR i from 0 to mid-1: insertBST2(root, array[i].word, array[i].synonym, array[i].antonym)
      FOR i from mid+1 to count-1: insertBST2(root, array[i].word, array[i].synonym, array[i].antonym)
      FREE array
      RETURN root
  ```
- **Edge Cases**:
  - One tree empty: Returns the other tree.
  - Both empty: Returns `NULL`.
  - Duplicate words: `insertBST2` skips duplicates.
- **Memory Management**: Allocates queue nodes, array, and new BST nodes; frees array but not queue nodes (potential leak).
- **Performance**: O(n log n) for traversal and insertion, where n is total nodes.

### 2. Linked Lists, Stacks, Queues 📑
#### `TList* fw_getSynWords(const char *filename)` (Wraps `getSynWords` in `code.c`)
- **Purpose**: Loads synonyms from `dictinoary.txt` into a `TList`.
- **Implementation**:
  - Opens `filename` in read mode.
  - Allocates a `TList` with `head = NULL`.
  - Reads lines (170 bytes) using `fgets`.
  - Uses `sscanf` with format `%49[^=] = %49[^#]` to extract word and synonym.
  - Calls `addNodeAtEnd` to append each pair to the list.
  - Closes the file and returns the list.
- **Edge Cases**:
  - File not found: Prints error via `perror` and returns `NULL`.
  - Invalid line format: Skips lines where `sscanf` fails.
- **Memory Management**: Allocates `TList` and `Node` structures; user must free the list.
- **Performance**: O(n) for reading n lines, plus O(1) per node insertion.

#### `TList* fw_sortWord(TList *syn)` (Wraps `sortWord` in `code.c`)
- **Purpose**: Sorts a `TList` alphabetically by word.
- **Implementation**:
  - Uses selection sort:
    - Iterates through the list (`current`).
    - For each `current`, finds the minimum node (`minnode`) by `strcmp`.
    - Swaps data (`word`, `relatedWord`, `charCount`, `vowelCount`) if needed using `swapData`.
  - Returns the sorted list.
- **Pseudo-Code**:
  ```plaintext
  FUNCTION sortWord(syn):
      IF syn.head is NULL or syn.head.next is NULL: RETURN syn
      current = syn.head
      WHILE current.next:
          minnode = current
          temp = current
          WHILE temp:
              IF strcmp(temp.word, minnode.word) < 0: minnode = temp
              temp = temp.next
          IF minnode ≠ current: swapData(minnode, current)
          current = current.next
      RETURN syn
  ```
- **Edge Cases**:
  - Empty or single-node list: Returns unchanged.
  - Equal words: Stable sort (maintains order).
- **Memory Management**: No additional allocation; swaps data in-place.
- **Performance**: O(n²) due to selection sort, where n is list length.

#### `TQueue* fw_syllable(TList *syn)` (Wraps `syllable` in `code.c`)
- **Purpose**: Creates a queue of words sorted by syllable count.
- **Implementation**:
  - Counts list length by traversing `syn->head`.
  - Allocates an array of `Node*` pointers.
  - Populates the array with list nodes.
  - Sorts the array using `qsort` with `compareNodes`, which compares syllable counts (via `count_syllables`) and breaks ties with `strcmp`.
  - Creates a `TQueue` and enqueues words from the sorted array.
  - Frees the array and returns the queue.
- **Pseudo-Code**:
  ```plaintext
  FUNCTION syllable(syn):
      length = 0
      FOR temp = syn.head: length++
      arr = ALLOCATE Node* array of size length
      FOR i = 0 to length-1: arr[i] = temp; temp = temp.next
      qsort(arr, length, sizeof(Node*), compareNodes)
      queue = createQueue()
      FOR i = 0 to length-1: enqueue(queue, arr[i].word)
      FREE arr
      RETURN queue
  ```
- **Edge Cases**:
  - Empty list: Returns empty queue.
  - Words with same syllable count: Sorted alphabetically.
- **Memory Management**: Allocates array and queue nodes; frees array but not queue nodes.
- **Performance**: O(n log n) due to `qsort`, where n is list length.

### 3. Recursion 🔄
#### `void fw_wordPermutation(char *word)` (Wraps `wordPermutation` in `recursion_utils.c`)
- **Purpose**: Prints all permutations of a word.
- **Implementation**:
  - Uses recursive `permute` with a helper `loop`:
    - `permute(word, index)`: If `index` equals word length, prints the word; else calls `loop`.
    - `loop(i, end, index, word)`: Swaps characters at `index` and `i`, recurses, and swaps back.
  - Generates all possible permutations by swapping characters.
- **Pseudo-Code**:
  ```plaintext
  FUNCTION wordPermutation(word):
      permute(word, 0)

  FUNCTION permute(word, index):
      IF index = len(word): PRINT word; RETURN
      loop(index, len(word), index, word)

  FUNCTION loop(i, end, index, word):
      IF i ≥ end: RETURN
      SWAP word[index], word[i]
      permute(word, index + 1)
      SWAP word[index], word[i]
      loop(i + 1, end, index, word)
  ```
- **Edge Cases**:
  - Empty word: No output.
  - Single character: Prints the character.
- **Memory Management**: Modifies word in-place; no additional allocation.
- **Performance**: O(n!) for n-character word due to generating all permutations.

#### `int fw_longestSubseqWord(char *word1, char *word2)` (Wraps `longestSubseqWord` in `recursion_utils.c`)
- **Purpose**: Returns the length of the longest common subsequence (LCS).
- **Implementation**:
  - Recursive approach:
    - If either word is empty, returns 0.
    - If first characters match, adds 1 and recurses on remaining strings.
    - Else, takes the maximum of LCS excluding first character of `word1` or `word2`.
- **Pseudo-Code**:
  ```plaintext
  FUNCTION longestSubseqWord(word1, word2):
      IF word1[0] = '\0' OR word2[0] = '\0': RETURN 0
      IF word1[0] = word2[0]:
          RETURN 1 + longestSubseqWord(word1 + 1, word2 + 1)
      ELSE:
          RETURN max(longestSubseqWord(word1, word2 + 1), longestSubseqWord(word1 + 1, word2))
  ```
- **Edge Cases**:
  - Empty strings: Returns 0.
  - No common characters: Returns 0.
- **Memory Management**: No allocation; recursive stack space.
- **Performance**: O(2^(m+n)) for strings of length m and n (exponential; could be optimized with dynamic programming).

#### `void reverseFile(const char *inputFilename, const char *outputFilename)` (`Recursion_2.c`)
- **Purpose**: Reverses the lines of a file.
- **Implementation**:
  - Opens input and output files.
  - Counts lines by reading with `fgets`.
  - Creates a stack (`Stack`) with capacity equal to line count.
  - Pushes each line onto the stack.
  - Pops lines and writes to the output file, reversing order.
  - Frees stack memory.
- **Edge Cases**:
  - File not found: Prints error via `perror`.
  - Empty file: Creates empty output file.
- **Memory Management**: Allocates stack and duplicates lines with `strdup`; frees all memory.
- **Performance**: O(n) for n lines, plus O(n) space for stack.

---

## Build Instructions 🛠️

To compile the GUI, use the provided `build.bat` with GCC. Here’s a detailed guide:

1. **Prerequisites**:
   - **GCC Compiler**: Install MinGW (e.g., via MSYS2 or standalone). Ensure `gcc` is in the system PATH.
   - **Windows SDK**: Required for Win32 API headers (`windows.h`, `commctrl.h`).
   - **Files**: Ensure all source files (`main.c`, `functions_wrapper.c`, `code.c`, `code_utils.c`, `tree_utils.c`, `trees.c`, `recursion_utils.c`, `Recursion_2.c`) and headers (`functions_wrapper.h`, `unified_data_structures.h`, `code.h`, `code_utils.h`, `tree_utils.h`, `trees.h`, `recursion_utils.h`, `Recursion_2.c`) are in the project directory.
   - **Dictionary File**: Create `dictinoary.txt` with the correct format.

2. **Update `build.bat`**:
   - The original `build.bat` may exclude `trees.c` and `Recursion_2.c`. Modify it to include all files:
     ```batch
     @echo off
     gcc -Wall -o GUI main.c functions_wrapper.c code.c code_utils.c tree_utils.c trees.c recursion_utils.c Recursion_2.c -mwindows -lcomctl32
     if %ERRORLEVEL% == 0 (
         echo Build complete. Run GUI.exe to start the application.
     ) else (
         echo Build failed.
     )
     pause
     ```
   - Flags:
     - `-Wall`: Enables warnings.
     - `-mwindows`: Links Win32 API for GUI.
     - `-lcomctl32`: Links common controls library.

3. **Run the Build**:
   - Open a command prompt in the project directory.
   - Execute: `build.bat`
   - Output: `GUI.exe` if successful.

4. **Verify**:
   - Run `GUI.exe` to launch the GUI.
   - Ensure `dictinoary.txt` is in the working directory or a path accessible via the **Browse** button.

---

## Usage Instructions 📖

1. **Launch**: Run `GUI.exe` to open the "Tree Functions GUI". ▶️
2. **Select Category**: Choose **Trees**, **Code**, or **Recursion** from the dropdown. 📋
3. **Select Function**: Pick a function (e.g., `fillTree`, `sortWord`). ⚙️
4. **Enter Arguments**:
   - For file inputs, click **Browse** to select `dictinoary.txt`. 📂
   - Enter text or numeric arguments in provided fields. ✏️
5. **Run**: Click **Run** to execute; results appear in the text area. 🏃
6. **Check Status**: View the status bar for feedback (e.g., "Ready"). 🔔

**Example**:
- Load a BST: Select **Trees** > **fillTree**, browse for `dictinoary.txt`, click **Run**.
- Sort synonyms: Select **Code** > **sortWord**, ensure a list is loaded, click **Run**.
- Generate permutations: Select **Recursion** > **wordPermutation**, enter a word (e.g., "cat"), click **Run**.

---

## Potential Issues & Limitations ⚠️

- **Typo in `dictinoary.txt`**:
  - Consistent across `code.c`, `tree_utils.c`, etc., suggesting intentional use.
  - Recommendation: Rename to `dictionary.txt` and update all file references (e.g., in `getSynWords`, `fillTree`).
- **Function Overlap**:
  - `trees.c` vs. `tree_utils.c`: Nearly identical implementations (e.g., `fillTree`, `deleteWordBST`). `tree_utils.c` is used by `functions_wrapper.c`, but `trees.c` adds `BTSMerge`.
  - `Recursion_2.c` vs. `recursion_utils.c`: Duplicate functions except for `reverseFile`.
  - Impact: Code redundancy increases maintenance effort.
- **Incomplete Implementations**:
  - `fw_toStack` and `fw_stackToQueue` in `functions_wrapper.c` are simplified/dummy implementations, limiting functionality.
  - Example: `fw_toStack` creates an empty stack instead of converting a `TList`.
- **Memory Management**:
  - Functions like `getSynWords`, `fillTree`, and `syllable` allocate memory without cleanup functions, risking leaks.
  - Example: `BTSMerge` frees the array but not queue nodes.
- **Buffer Sizes**:
  - `code.c` uses fixed buffers (e.g., 170–175 bytes for lines, 50 bytes for words). Long lines/words may cause overflows.
  - Recommendation: Use dynamic buffers or validate input lengths.
- **Performance**:
  - `sortWord` uses O(n²) selection sort; could use merge sort for O(n log n).
  - `longestSubseqWord` is O(2^n); dynamic programming would reduce to O(mn).
- **Error Handling**:
  - File errors (e.g., `fopen` failure) use `perror` or `printf` but don’t propagate to GUI consistently.
  - Input validation (e.g., empty strings) is minimal in some functions.

---

## Future Improvements 🚀

- **Fix Typo**: Update all references to `dictinoary.txt` to `dictionary.txt`. 🔍
- **Consolidate Code**:
  - Merge `trees.c` into `tree_utils.c`, keeping `BTSMerge`.
  - Merge `Recursion_2.c` into `recursion_utils.c`, retaining `reverseFile`.
- **Complete Wrappers**:
  - Implement `fw_toStack` to convert `TList` to `TStack` by iterating and pushing nodes.
  - Enhance `fw_stackToQueue` to transfer stack elements correctly.
- **Optimize Algorithms**:
  - Replace selection sort in `sortWord` with merge sort.
  - Use dynamic programming for `longestSubseqWord`.
- **Dynamic Buffers**: Replace fixed buffers with dynamic allocation (e.g., `realloc`) for lines/words.
- **Memory Cleanup**: Add functions to free `TList`, `TTree2`, `TQueue`, etc., and call them after use.
- **GUI Enhancements**:
  - Add tooltips with function descriptions.
  - Display error dialogs for invalid inputs.
  - Support multiple file formats (e.g., JSON, CSV).
- **Cross-Platform**: Port to Qt or SDL for non-Windows support. 🌐

---

## Troubleshooting 🛠️

- **Build Fails**:
  - **Cause**: Missing files or incorrect GCC setup.
  - **Fix**: Verify all source/header files are present. Install MinGW and add to PATH.
- **No Output**:
  - **Cause**: `dictinoary.txt` missing or malformed.
  - **Fix**: Ensure file exists and follows format. Check GUI status bar for errors.
- **Crashes**:
  - **Cause**: Buffer overflow or memory leak.
  - **Fix**: Validate input lengths. Use a debugger (e.g., gdb) to trace crashes.
- **Function Not Working**:
  - **Cause**: Simplified wrappers (e.g., `fw_toStack`).
  - **Fix**: Check `functions_wrapper.c` for dummy implementations and replace with full logic.

---

**Happy Dictionary Management!** 🧑‍💻📚