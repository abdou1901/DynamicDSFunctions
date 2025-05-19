#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "trees.h"

node *createNode(int id,char *msg,char *time,int severity){
    node *newnode = (node *)malloc(sizeof(node));
    newnode->ID = id;
    newnode->severity = severity;
    strcpy(newnode->message,msg);
    strcpy(newnode->timestamp,time);
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
node *insertNode(node *root,int id,char *msg,char *time,int severity){
    if(root == NULL){
        return createNode(id,msg,time,severity);
    }
    if(strcmp(time,root->timestamp) < 0){
        root->left = insertNode(root->left,id,msg,time,severity);
    } else{
        root->right = insertNode(root->right,id,msg,time,severity);
    }
    return root;
}   
void printNode(node *n){
    if(n == NULL) return;
    printf("Id: %d,Severity :%d,timestamp :'%s',Message'%s'\n",n->ID,n->severity,n->timestamp,n->message);
}
node *findInOrderMin(node *root){
    node *temp = root;
    while(temp && temp->left){
        temp = temp->left; 
    }
    return temp;
}
void CopyLogData(node *dest ,node *src){
    dest->ID  = src->ID;
    dest->severity = src->severity;
    strcpy(dest->message,src->message);
    strcpy(dest->timestamp,src->timestamp);
}

node  *deleteLog(node *root,char *time){
    if(root == NULL || time == NULL) return root;
    if(strcmp(time,root->timestamp) <0){ 
        root->left = deleteLog(root->left,time);
    }else if (strcmp(time,root->timestamp) > 0){
        root->right = deleteLog(root->right,time);
    }else{ //if there is an exact match
        if(root->left == NULL){//if it has one child or none
            node *temp = root->right;
            free(root);
            return temp;
        }
        if(root->right == NULL){//same thing 
            node *temp = root->left;
            free(root);
            return temp;
        }
        //if it has two childs(right and left exist)
        node *toReplaceWith = findInOrderMin(root->right); // find the minimum one in the right subtree
        CopyLogData(root,toReplaceWith);
        root->right = deleteLog(root->right, toReplaceWith->timestamp); // delete the original copied node
    }
    return root;
}
node *searchNode(node *root,char *time){
    if(root == NULL) return NULL;
    if(strcmp(root->timestamp,time) == 0) return root;
    if(strcmp(time,root->timestamp) <0) return searchNode(root->left,time);
    return searchNode(root->right,time);
}
void inOrderTraversal(node *root){
    if(root){
        inOrderTraversal(root->left);
        printf("Id: %d,Severity :%d,timestamp :'%s',Message'%s'\n",root->ID,root->severity,root->timestamp,root->message);
        inOrderTraversal(root->right);
    }
}
void preOrderTraversal(node *root){
    if(root){
        printf("Id: %d,Severity :%d,timestamp :'%s',Message'%s'\n",root->ID,root->severity,root->timestamp,root->message);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}
void postOrderTraversal(node *root){
    if(root){
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
        printf("Id: %d,Severity :%d,timestamp :'%s',Message'%s'\n",root->ID,root->severity,root->timestamp,root->message);
    }
}
node *ConvertLLtoBST(LogEntry *head){
    if(head == NULL) return NULL;
    node *root = createNode(head->ID,head->message,head->timestamp,head->severity);
    head= head->next;
    while(head){
        insertNode(root,head->ID,head->message,head->timestamp,head->severity);
        head =head->next;
    }
    return root;
}

void freeTree(node *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}
