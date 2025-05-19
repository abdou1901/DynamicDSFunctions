#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "circularLinkedLists.h"
#define MAX 500




Node* allocate() {
    return (Node*)malloc(sizeof(Node));
}

void insertAtBeginning(Node** head, Node** tail, int id, char* timestamp, char* LOG, char* message) {
    Node* node = allocate();
    node->id = id;
    strcpy(node->LOG, LOG);
    strcpy(node->message, message);

    if (*head == NULL) {
        node->next = node;
        node->prev = node;
        *head = *tail = node;
    } else {
        node->next = *head;
        node->prev = *tail;
        (*head)->prev = node;
        (*tail)->next = node;
        *head = node;
    }
}

void insertAtEnd(Node** head, Node** tail, int id, char* timestamp, char* LOG, char* message) {
    Node* node = allocate();
    node->id = id;
    strcpy(node->LOG, LOG);
    strcpy(node->message, message);

    if (*head == NULL) {
        node->next = node;
        node->prev = node;
        *head = *tail = node;
    } else {
        node->next = *head;
        node->prev = *tail;
        (*tail)->next = node;
        (*head)->prev = node;
        *tail = node;
    }
}

void traverseForward(Node* head) {
    if (!head) return;
    Node* temp = head;
    do {
        printf("[ID: %d, message: %s, LOG: %s, timestamp: %s] <-> ", temp->id, temp->message, temp->LOG, temp->timestamp);
        temp = temp->next;
    } while (temp != head);
    printf("(Back to Head)\n");
}

void traverseBackward(Node* tail) {
    if (!tail) return;
    Node* temp = tail;
    do {
        printf("[ID: %d, message: %s, LOG: %s, timestamp: %s] <-> ", temp->id, temp->message, temp->LOG, temp->timestamp);
        temp = temp->prev;
    } while (temp != tail);
    printf("(Back to Tail)\n");
}

void deleteByID(Node** head, Node** tail, int id) {
    if (*head == NULL) return;
    Node* temp = *head;
    do {
        if (temp->id == id) {
            if (temp == *head && temp == *tail) {
                *head = *tail = NULL;
            } else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                if (temp == *head) *head = temp->next;
                if (temp == *tail) *tail = temp->prev;
            }
            free(temp);
            return;
        }
        temp = temp->next;
    } while (temp != *head);
}

int countLogs(Node* head) {
    if (!head) return 0;
    int counter = 0;
    Node* temp = head;
    do {
        counter++;
        temp = temp->next;
    } while (temp != head);
    return counter;
}

void insertLog(Node** head, Node** tail, int id, char* timestamp, char* LOG, char* message, int maxSize, int* currentSize){
    if (head ==NULL)
    {
        printf("NO LIST !"); 
        return;
    }
    
    if (*currentSize<=maxSize) insertAtEnd(head,tail,id,timestamp,LOG,message);
    else{
        (*head)->id=id;
        strcpy((*head)->timestamp,timestamp);
        strcpy((*head)->LOG,LOG);
        strcpy((*head)->message,message);    
        *head=(*head)->next;
    }
    
    
}


int detectCycle(Node* head){
    Node *slow,*fast;
    slow=head;
    fast=head->next;
    while (fast!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;

        if (slow == fast || fast==head) return 1;         
    }
    return 0;
}

Node* searchByID(Node* head, int id) {
    if (head==NULL) return NULL;
    Node* temp = head;
    do {
        if (temp->id == id) return temp;
        temp = temp->next;
    } while (temp != head);
    return NULL;
}

Node* searchByTimestamp(Node* head, char* timestamp) {
    if (!head) return NULL;
    Node* temp = head;
    do {
        if (strcmp(temp->timestamp, timestamp) == 0) return temp;
        temp = temp->next;
    } while (temp != head);
    return NULL;
}

Node* searchByKeyword(Node* head, char* keyword) {
    if (!head) return NULL;
    Node* temp = head;
    do {
        if (strstr(temp->message, keyword) != NULL) return temp;
        temp = temp->next;
    } while (temp != head);
    return NULL;
}

void reverseList(Node** head, Node** tail) {
    if (!head || !(*head) || (*head)->next == *head) return;
    Node* temp = NULL;
    Node* current = *head;
    do {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    } while (current != *head);
    *tail = *head;
    *head = temp->prev;
}


///////////////////////////////////////////////////////////////////////*


