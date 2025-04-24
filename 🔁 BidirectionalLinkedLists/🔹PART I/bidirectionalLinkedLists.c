#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include "bidirectionalLinkedLists.h"


#define MAX 500

//*don't worry i will add comments
Node  *allocate(){
    return (Node*)malloc(sizeof(Node));
}

void insertAtBeginning(Node** head,Node **tail, int id, char* timestamp, char* LOG, char* message){
    
    Node *node;
    node =allocate();
    
    node->prev=NULL;
    node->next=*head;
    node->id=id;
    strcpy(node->LOG,LOG);
    strcpy(node->message,message);

    if (*head != NULL) (*head)->prev = node;
    else  *tail = node; 
    *head = node;


}

void insertAtEnd(Node** head, Node ** tail,int id, char* timestamp, char* LOG, char* message){
    Node *node;
    node =allocate();
    
    node->prev=*tail;
    node->next=NULL;
    node->id=id;
    strcpy(node->LOG,LOG);
    strcpy(node->message,message);

    if (*tail != NULL) (*tail)->next = node;
    else  *head = node; 
    *tail = node;

    
}


int Length(Node *head,Node *tail){
   int counter=0;
   
    while (head!=tail->next)
    {
        counter++;
        head=head->next;
    }
    return counter;
}

void insertAtPosition(Node** head,Node** tail, int id, char* timestamp, char* LOG, char* message, int position){
    if (*head == NULL || !position)
    {
        insertAtBeginning(head,tail,id,timestamp,LOG,message);
        return;
    }
    int count =Length(*head,*tail);
    if (position>=count)
    {
        insertAtEnd(head,tail,id,timestamp,LOG,message);
        return;
    }
    Node *temph=*head;
    Node *tempt=temph->next;
    
    for (int i = 0; i <position-1; i++)
    {
        temph=tempt;
        tempt=temph->next;
    }
    
    Node *temp;

    Node *node;
    node =allocate();
    node->prev=temph;
    node->next=tempt;
    node->id=id;
    strcpy(node->LOG,LOG);
    strcpy(node->message,message);
    temph->next=node;
    tempt->prev=node;
    
    

    
}

void deleteByID(Node** head, Node** tail, int id){

    if (*head==NULL) printf("NO LIST!");
    if (*head ==*tail)
    {
        head=NULL;tail=head;
        return;
    }
    
    if ((*head)->id==id)
    {
        *head=(*head)->next;
        (*head)->prev=NULL;
    }
    if ((*tail)->id==id)
    {
        *tail=(*tail)->prev;
        (*tail)->next=NULL;
    }
    Node *temph=*head;
    while (temph->id!=id)
    {
        temph=temph->next;
    }
    Node *temp;
    temp=temph->next->prev;
    temph->next->prev=temph->prev->next;
    temph->prev->next=temp;

    


}

void deleteByTimestamp(Node** head, Node** tail, char* timestamp){
    if (*head==NULL) printf("NO LIST!");
    if (*head ==*tail)
    {
        head=NULL;tail=head;
        return;
    }
    
    if ((*head)->timestamp==timestamp)
    {
        *head=(*head)->next;
        (*head)->prev=NULL;
        return;
    }
    if ((*tail)->timestamp==timestamp)
    {
        *tail=(*tail)->prev;
        (*tail)->next=NULL;
        return;
    }
    Node *temph=*head;
    while (temph->timestamp!=timestamp)
    {
        temph=temph->next;
    }
    Node *temp;
    temp=temph->next->prev;
    temph->next->prev=temph->prev->next;
    temph->prev->next=temp;
}

void deleteFirst(Node** head, Node** tail){
    *head=(*head)->next;
    (*head)->prev=NULL;
}

void deleteLast(Node** head, Node** tail){
    *tail=(*tail)->prev;
    (*tail)->next=NULL;
}

Node* searchByID(Node* head, int id){

    //*for now  will make it linear search it may update to binary search when i creat sorting procedure
    while (head->id!=id)
    {
        head=head->next;
    }
    return head;

}

Node* searchByKeyword(Node* head, char* keyword){
    //*for now  will make it linear search it may update to binary search when i creat sorting procedure
    while (head->LOG!=keyword)
    {
        head=head->next;
    }
    return head;
}

Node* searchByTimestamp(Node* head, char* timestamp){
    //*for now  will make it linear search it may update to binary search when i creat sorting procedure
    while (head->timestamp!=timestamp)
    {
        head=head->next;
    }
    return head;
}

void sortByDate(Node** head){
    *head=mergeSortByTimestamp(*head);
}

void sortBySeverity(Node** head){
    *head =mergeSortBySeverity(*head);
}

void reverseList(Node** head, Node** tail){
    Node *current=*head;
    while (current!=NULL)
    {
        Node *temp;
        temp =current->next->prev;
        current->next->prev=current->prev->next;
        current->prev->next=temp;
        current=current->prev;
    }
    Node *temp;
    temp=*head;
    *head=*tail;
    *tail=temp;
    
}

int countLogs(Node* head){
    int counter=0;
   
    while (head!=NULL)
    {
        counter++;
        head=head->next;
    }
    return counter;
}

void traverseForward(Node* head){
    
    while (head!=NULL) {
        printf("[ID: %d, message: %s, LOG : %s, timestamp : %s] <---> ", head->id, head->message,head->LOG,head->timestamp);
        head = head->next;
    }
    
    
}

void traverseBackward(Node* tail){
    while (tail!=NULL) {
        printf("[ID: %d, message: %s, LOG : %s, timestamp : %s] <---> ", tail->id, tail->message,tail->LOG,tail->timestamp);
        tail = tail->prev;
    }
    
}

void deleteAtIndex(Node** head, Node** tail, int index){
    if (*head==NULL) printf("NO LIST!");
    if (*head ==*tail)
    {
        head=NULL;tail=head;
        return;
    }
    
    if (!index)
    {
        *head=(*head)->next;
        (*head)->prev=NULL;
        return;
    }
    int count=countLogs(*head);
    if (index==count)
    {
        *tail=(*tail)->prev;
        (*tail)->next=NULL;
        return;
    }
    Node *temph=*head;
    for(int i=0;i<index;i++)
    {
        temph=temph->next;
    }
    Node *temp;
    temp=temph->next->prev;
    temph->next->prev=temph->prev->next;
    temph->prev->next=temp;

}

Node* mergeLogLists(Node* list1, Node* list2){
   
   if (list1==NULL && list2 == NULL) return NULL;
   
   
   
    Node *head;
    head=list1;
    while (list1->next!=NULL)
    {
       list1=list1->next;
    }
    list1->next=list2;
    list2->prev=list1;
    return head;
}

Node* findMiddle(Node* head) {
    if (head==NULL) return NULL;

    Node* slow = head;
    Node* fast = head;

    while (fast->next!=NULL && fast->next->next!=NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* mergeSortedLists(Node* first, Node* second) {
    if (first==NULL) return second;
    if (second==NULL) return first;

    
    if (first->id <= second->id) {
        first->next = mergeSortedLists(first->next, second);
        if (first->next!=NULL) first->next->prev = first;
        first->prev = NULL;
        return first;
    } else {
        second->next = mergeSortedLists(first, second->next);
        if (second->next!=NULL) second->next->prev = second;
        second->prev = NULL;
        return second;
    }
}

Node* mergeSort(Node* head) {
    if (head==NULL || !head->next==NULL) return head; 

    Node* middle = findMiddle(head);
    Node* secondHalf = middle->next;
    middle->next = NULL; 
    if (secondHalf!=NULL) secondHalf->prev = NULL;

    
    Node* left = mergeSort(head);
    Node* right = mergeSort(secondHalf);


    return mergeSortedLists(left, right);
}

Node* mergeSortedByTimestamp(Node* first, Node* second) {
    if (!first) return second;
    if (!second) return first;
    if (strcmp(first->timestamp, second->timestamp) <= 0) {
        first->next = mergeSortedByTimestamp(first->next, second);
        if (first->next) first->next->prev = first;
        first->prev = NULL;
        return first;
    } else {
        second->next = mergeSortedByTimestamp(first, second->next);
        if (second->next) second->next->prev = second;
        second->prev = NULL;
        return second;
    }
}

Node* mergeSortByTimestamp(Node* head) {
    if (!head || !head->next) return head;
    Node* middle = findMiddle(head);
    Node* secondHalf = middle->next;
    middle->next = NULL;
    if (secondHalf) secondHalf->prev = NULL;
    Node* left = mergeSortByTimestamp(head);
    Node* right = mergeSortByTimestamp(secondHalf);
    return mergeSortedByTimestamp(left, right);
}

Node* mergeSortedBySeverity(Node* first, Node* second) {
    if (!first) return second;
    if (!second) return first;
    if (first->LOG <= second->LOG) {
        first->next = mergeSortedBySeverity(first->next, second);
        if (first->next) first->next->prev = first;
        first->prev = NULL;
        return first;
    } else {
        second->next = mergeSortedBySeverity(first, second->next);
        if (second->next) second->next->prev = second;
        second->prev = NULL;
        return second;
    }
}

Node* mergeSortBySeverity(Node* head) {
    if (!head || !head->next) return head;
    Node* middle = findMiddle(head);
    Node* secondHalf = middle->next;
    middle->next = NULL;
    if (secondHalf) secondHalf->prev = NULL;
    Node* left = mergeSortBySeverity(head);
    Node* right = mergeSortBySeverity(secondHalf);
    return mergeSortedBySeverity(left, right);
}


