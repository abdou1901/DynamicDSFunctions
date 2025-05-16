#ifndef TREES_H
#define TREES_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/////////////////////////////////////////////////////////////////
//* Structures definitions

// Word node for linked lists of synonyms and antonyms
typedef struct WordNode {
    char word[50];
    struct WordNode *next;
} WordNode;

// Tree structure with multiple synonyms and antonyms
typedef struct TTree2 {
    char word[50];
    WordNode *synonym;
    WordNode *antonym;
    struct TTree2 *left;
    struct TTree2 *right;
} TTree2;

// Stack node for tree operations
typedef struct TStackNode2 {
    TTree2 *treeNode;
    struct TStackNode2 *next;
} TStackNode2;

// Stack for tree operations
typedef struct TStack2 {
    TStackNode2 *top;
} TStack2;

// RENAMED to avoid collision with code.h
typedef struct TreeQNode {
    TTree2 *treeNode;
    struct TreeQNode *next;
} TreeQNode;

// Queue for tree operations
typedef struct TreeQueue {
    TreeQNode *front;
    TreeQNode *rear;
} TreeQueue;

/////////////////////////////////////////////////////////////////
//* Function declarations

// Basic operations
WordNode *copyNodeList(WordNode *src);
void printWordNodeList(WordNode *head);
void insertAtEnd(WordNode **head, const char *newWord);
int countWordNodes(WordNode *head);

// Tree operations
TTree2* createTreeNode2(const char *word, WordNode *synonyms, WordNode *antonyms);
TTree2* insertBST2(TTree2 *root, const char *word, WordNode *synonyms, WordNode *antonyms);
int countVowels(char *word);
TTree2 *findMinNode2(TTree2 *node);

// Stack operations
TStack2* createTreeStack();
void pushTree(TStack2 *stack, TTree2 *node);
TTree2* popTree(TStack2 *stack);
bool isTreeStackEmpty(TStack2 *stack);

// Queue operations
TreeQueue *createTreeQueue();
void enqueueTree(TreeQueue *q, TTree2 *node);
TTree2 *dequeueTree(TreeQueue *q);
bool isTreeQueueEmpty(TreeQueue *q);
int lenTreeQueue(TreeQueue *q);

// Tree manipulation
TTree2 *toTree2(TStack2 *stk);
TTree2 *fillTree(const char *filename);
TTree2 *getInfWordTree(TTree2 *tr, char *word);
void printTreeNodeCharacteristics(TTree2 *tr, char *word);
void AddWordBST(TTree2 *tr, char *word, WordNode *synonyms, WordNode *antonyms, TStack2 **stk);
TTree2 *deleteWordBST(TTree2 *tr, char *word);
TTree2 *UpdateWordBST(TTree2 *tr, char *word, char *syne, char *anton);
void printTrNode(TTree2 *tr);
TTree2 *deleteSyn(TTree2 *tr, char* word, char *syn);
TTree2 *deleteAnt(TTree2 *tr, char* word, char *ant);

// Tree traversal
void TraversalBSTinOrder(TTree2 *tr);
void TraversalBSTpreOrder(TTree2 *tr);
void TraversalBSTpostOrder(TTree2 *tr);
TreeQueue *StoreBSTinOrder(TTree2 *tr);
TreeQueue *StoreBSTpreOrder(TTree2 *tr);
TreeQueue *StoreBSTpostOrder(TTree2 *tr);

// Tree analysis
void HighSizeBST(TTree2 *tr);
TTree2 *LowestCommonAncestor(TTree2 *tr, char *word1, char *word2);
int CountNodesRanges(TTree2 *tr, int l, int h);
TTree2 *inOrderSuccesor(TTree2 *tr, char *word);
TTree2 *BSTMirror(TTree2 *tr);
bool isBalencedBST(TTree2 *tr);
TTree2 *BTSMerge(TTree2 *tr1, TTree2 *tr2);

// Helper functions
void StoreBSTinOrderHelper(TTree2 *tr, TreeQueue **q);
void StoreBSTpreOrderHelper(TTree2 *tr, TreeQueue **q);
void StoreBSTpostOrderHelper(TTree2 *tr, TreeQueue **q);
int HighBSTHelper(TTree2 *tr);
void SizeBSTHelper(TTree2 *tr, int *counter);
int helperQueueLen(TreeQNode *q);

#endif // TREES_H