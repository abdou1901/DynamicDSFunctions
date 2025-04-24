#ifndef TREES_H
#define TREES_H

#include "linkedlists.h"
#define MAX_MESSAGE_SIZE 256
#define MAX_TIMESTAMP_SIZE 20

typedef struct node {
    int ID;
    char message[MAX_MESSAGE_SIZE];
    char timestamp[MAX_TIMESTAMP_SIZE];
    int severity;
    struct node* right;
    struct node* left;
} node;

node *createNode(int id, char *msg, char *time, int severity);
node *insertNode(node *root, int id, char *msg, char *time, int severity);
void printNode(node *n);
node *findInOrderMin(node *root);
void CopyLogData(node *dest, node *src);
node *deleteLog(node *root, char *time);
node *searchNode(node *root, char *time);
void inOrderTraversal(node *root);
void preOrderTraversal(node *root);
void postOrderTraversal(node *root);
node *ConvertLLtoBST(LogEntry *head);
void freeTree(node *root);

#endif