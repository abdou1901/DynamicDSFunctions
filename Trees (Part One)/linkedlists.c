#include "linkedlists.h"


//added functions (needed )
char *toLowerCase(const char *str) {
    if (!str) return NULL;

    int length = strlen(str);
    char *result = malloc(length + 1);
    if (!result) return NULL;

    for (int i = 0; i < length; i++) {
        result[i] = (str[i] >= 'A' && str[i] <= 'Z') ? str[i] + ('a' - 'A') : str[i];
    }
    result[length] = '\0';

    return result;
}
void SwapLogData(LogEntry *node1 ,LogEntry *node2){
    int temp = node1->ID;
    node1->ID = node2->ID;
    node2->ID = temp;
    temp = node1->severity;
    node1->severity = node2->severity;
    node2->severity = temp;
    char tempstr[MAX_MESSAGE_SIZE];
    strcpy(tempstr,node1->message);
    strcpy(node1->message,node2->message);
    strcpy(node2->message , tempstr);
    char temptime[MAX_TIMESTAMP_SIZE];
    strcpy(temptime,node1->timestamp);
    strcpy(node1->timestamp,node2->timestamp);
    strcpy(node2->timestamp , temptime);
}

//printing logs
void printLogs(LogEntry *head){
    while(head){
        printf("ID: %d, Message = \"%s\", Date & time : \"%s\", severity = %d\n",head->ID,head->message,head->timestamp,head->severity);
        head = head->next;
    }
}

//inserting logs
void InsertLogEntryAtStart(LogEntry **head,int id,char *message,char *timestamp,int severity){
    LogEntry *newLog = (LogEntry *)malloc(sizeof(LogEntry));
    newLog->ID = id;
    strncpy(newLog->message,message,MAX_MESSAGE_SIZE-1);
    strncpy(newLog->timestamp,timestamp,MAX_TIMESTAMP_SIZE-1);
    newLog->severity = severity;
    newLog->next = *head;
    *head = newLog;
}
void InsertLogEntryAtEnd(LogEntry **head,int id,char *message,char *timestamp,int severity){
    LogEntry *newLog = (LogEntry *)malloc(sizeof(LogEntry));
    newLog->ID = id;
    strncpy(newLog->message,message,MAX_MESSAGE_SIZE-1);
    strncpy(newLog->timestamp,timestamp,MAX_TIMESTAMP_SIZE-1);
    newLog->severity = severity;
    newLog->next = NULL;
    if(*head == NULL){
        *head = newLog;
        return;
    }
    LogEntry *temp = *head;
    while(temp->next) temp = temp->next;
    temp->next = newLog;
}
void InsertLogEntryAtPosition(LogEntry **head,int id,char *message,char *timestamp,int severity,int pos){ // position in 1-indexed
    if(pos <1) {
        printf("Please enter valid position (>=1)!\n");
        return;
    }
    if(*head == NULL && pos != 1){
        printf("List is empty ,Position must be set to 1!\n");
        return;
    }
    LogEntry *newLog = (LogEntry *)malloc(sizeof(LogEntry));
    newLog->ID = id;
    strncpy(newLog->message,message,MAX_MESSAGE_SIZE-1);
    strncpy(newLog->timestamp,timestamp,MAX_TIMESTAMP_SIZE-1);
    newLog->severity = severity;
    if(pos == 1){
        newLog->next = *head;
        *head =newLog;
        return;
    }
    LogEntry *current = *head;
    while(current && pos-1 >1){
        current = current->next;
        pos--;
    }
    if(current == NULL){
        printf("Invalid position of insertion!\n");
        return;
    }
    newLog->next = current->next;
    current->next = newLog;
}

//deleting logs
void DeleteLogById(LogEntry **head, int id){
    if(*head == NULL) {
        printf("The list is empty !\n");
        return;
    }
    if((*head)->ID == id){
        LogEntry *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    LogEntry *current = *head;
    while(current->next){
        if(current->next->ID == id){
            LogEntry *temp = current->next;
            current->next = current->next->next;
            free(temp);
            return;
        }
        current = current->next;
    }
    printf("Log with ID = %d cannot be deleted (Id not found !)\n",id);
}
void DeleteLogByTimestamp(LogEntry **head, char *timestamp){
    if(*head == NULL) {
        printf("The list is empty !\n");
        return;
    }
    if(strcmp((*head)->timestamp,timestamp) == 0){
        LogEntry *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    LogEntry *current = *head;
    bool found = false;
    while(current && current->next){
        if(strcmp(timestamp,current->next->timestamp) ==0){
            found = true;
            LogEntry *temp = current->next;
            current->next = current->next->next;
            free(temp);
        }else current = current->next;
    }
    if(!found){
        printf("Logs with timestamp = \"%s\" cannot be deleted (Timestamp not found !)\n",timestamp);
    }  
}
void DeleteFirstLog(LogEntry **head){
    if(*head == NULL) return;
    LogEntry *temp = *head;
    *head = (*head)->next;
    free(temp); 
}
void DeleteLastLog(LogEntry **head){
    if(*head == NULL) return;
    if((*head)->next == NULL){
        free(*head);
        *head = NULL;
        return;
    }
    LogEntry *current = *head;
    while(current->next->next) current = current->next;
    LogEntry *temp = current->next;
    current->next = current->next->next;
    free(temp);
}

//earch Log Entry
LogEntry *searchLogByID(LogEntry *head,int id){
    if(head == NULL){
        printf("Log History is empty cannot find Log with Id = %d\n",id);
        return NULL;
    }
    while(head){
        if(head->ID== id){return head;}
        head = head->next;
    }
    printf("Log not found !\n");
}
LogEntry *searchLogByKeyword(LogEntry *head,char *keyword){ 
    // will return the first log that contains that keyword
    //also it is case-insensitive (capital letters are not taken in consideration(which is more realistic))
    if(head == NULL){
        printf("Log History is empty cannot find Log with keyword = \"%s\"\n",keyword);
        return NULL;
    }
    
    while(head){
        char *lowerLog = toLowerCase(head->message);
        char *lowerKeyword = toLowerCase(keyword);
        if(strstr(lowerLog ,lowerKeyword)){
            free(lowerKeyword);
            free(lowerLog);
            return head;
        }
        free(lowerKeyword);
        free(lowerLog);
        head= head->next;
    }
    printf("No matchings found with the keyword \"%s\"\n",keyword);
}
LogEntry *searchLogByTimestamp(LogEntry *head,char *timestamp){ 
    // will return the first log that contains that timestamp
    //also it is case-insensitive (capital letters are not taken in consideration(which is more realistic))
    if(head == NULL){
        printf("Log History is empty cannot find Log with timestamp = \"%s\"\n",timestamp);
        return NULL;
    }
    
    while(head){
        char *lowerLog = toLowerCase(head->timestamp);
        char *lowertimestamp = toLowerCase(timestamp);
        if(strstr(lowerLog ,lowertimestamp)){
            free(lowertimestamp);
            free(lowerLog);
            return head;
        }
        free(lowertimestamp);
        free(lowerLog);
        head= head->next;
    }
    printf("No matchings found with the timestamp \"%s\"\n",timestamp);
}


//sorting logs
void SortBySeverity(LogEntry **head){
    if(*head == NULL || (*head)->next == NULL) return;
    LogEntry *current = *head;
    while(current->next){
        LogEntry *temp = current;
        LogEntry *minnode = current;
        while(temp){
            if(temp->severity < minnode->severity){
                minnode = temp;
            }
           
            temp = temp->next;
        }
        if(minnode != current) SwapLogData(minnode,current);
        current = current->next;
    }
}
void SortByTimestamp(LogEntry **head){
    if(*head == NULL || (*head)->next == NULL) return;
    LogEntry *current = *head;
    while(current->next){
        LogEntry *temp = current;
        LogEntry *minnode = current;
        while(temp){
            if(strcmp(temp->timestamp,minnode->timestamp) <0){
                minnode = temp;
            }
           
            temp = temp->next;
        }
        if(minnode != current) SwapLogData(minnode,current);
        current = current->next;
    }
}


//Rverse the list
void reverseLogs(LogEntry **head){
    if( *head == NULL ||(*head)->next == NULL) return;
    LogEntry *prev = NULL;
    LogEntry *current = *head;
    while(current){
        LogEntry *temp = current->next;
        current->next = prev;
        prev= current;
        current = temp;
    }
    *head = prev;
}

//Count total logs 
int CountLogs(LogEntry *head){
    int  count = 0;
    while(head){count ++; head = head->next;}
    return count ;
}
