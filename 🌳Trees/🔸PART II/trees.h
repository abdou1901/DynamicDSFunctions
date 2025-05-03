#ifndef Trees_H
#define Trees_H
#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
/////////////////////////////////////////////////////////////////
//*the stuctures def
typedef struct TTree {
    char word[50];
    char synonym[50];
    char antonym[50];
    struct TTree *left;
    struct TTree *right;
} TTree;

typedef struct TStackNode {
    TTree *treeNode;
    struct TStackNode *next;
} TStackNode;

typedef struct TStack {
    TStackNode *top;
} TStack;

//*for more then a synonym and antonym
typedef struct WordNode{
    char word[50];
    struct WordNode *next;
    
}WordNode;
typedef struct TTree2 {
    char word[50];
    WordNode *synonym;
    WordNode *antonym;
    struct TTree2 *left;
    struct TTree2 *right;
} TTree2;

typedef struct TStackNode2 {
    TTree2 *treeNode;
    struct TStackNode2 *next;
} TStackNode2;

typedef struct TStack2 {
    TStackNode2 *top;
} TStack2;

typedef struct QNode {
    TTree2 *treeNode;
    struct QNode *next;
} QNode;

typedef struct {
    QNode *front;
    QNode *rear;
} TQueue;


//*//////////////////////////////////////////////////////////

//*some operations useful

WordNode *copyNodeList(WordNode *src);

void printWordNodeList(WordNode *head);

void insertAtEnd(WordNode **head, const char *newWord);

TTree2* createTreeNode2(const char *word, WordNode *synonyms, WordNode *antonyms);

TTree2* insertBST2(TTree2 *root, const char *word, WordNode *synonyms, WordNode *antonyms);

int countVowels(char *word);

TTree2 *findMinNode2(TTree2 *node);

int countWordNodes(WordNode *head);

//*stack operations
TStack2* createStack();

void push(TStack2 *stack, TTree2 *node);

TTree2* pop(TStack2 *stack);

int isStackEmpty(TStack2 *stack);

//*queue operations
TQueue *createQueue();

void enqueue(TQueue *q, TTree2 *node);

TTree2 *dequeue(TQueue *q);

bool isEmptyQueue(TQueue *q);

int lenQueue(TQueue *q);


//*the modules : 

TTree2 *toTree2(TStack2 *stk);

TTree2 *fillTree(const char *filename);

TTree2 *getInfWordTree(TTree2 *tr, char *word);

void printTreeNodeCharacteristics(TTree2 *tr,char *word);

void AddWordBST(TTree2 *tr, char *word,WordNode *synonyms,WordNode *antonyms, TStack2 **stk); //*this function adds a word with its synonym and antonym into a sorted BST.

TTree2 *deleteWordBST(TTree2 *tr, char *word);//* this function deletes a word from the BST

TTree2 *UpdateWordBST(TTree2 *tr, char *word, char *syne, char *anton);//*this function adds a word synonym and antonym on the BST.

void printTrNode(TTree2 *tr);

TTree2 *deleteSyn(TTree2 *tr,char* word,char *syn);

TTree2 *deleteAnt(TTree2 *tr,char* word,char *ant);

void TraversalBSTinOrder(TTree2 *tr);//* this function performs in-order traversal of the BST tr.

void TraversalBSTpreOrder(TTree2 *tr);//* this function performs pre-order traversal of the BST tr.

void TraversalBSTpostOrder(TTree2 *tr);//* this function performs post-order traversal of the BST tr.

TQueue *StoreBSTinOrder(TTree2 *tr);

TQueue *StoreBSTpreOrder(TTree2 *tr);

TQueue *StoreBSTpostOrder(TTree2 *tr);

void HighSizeBST(TTree2 *tr);//* this procedure prints the high and size of the BST tr.

TTree2 *LowestCommonAncestor(TTree2 *tr, char *word1, char *word2);//*this function returns the lowest common ancestor of two nodes (words).

int CountNodesRanges(TTree2 *tr, int l, int h);//*this function counts the number of nodes that lies within a given range [l, h].

TTree2 *inOrderSuccesor(TTree2 *tr , char *word);//* this function returns the in-order successor of a given node in tr.

TTree2 *BSTMirror(TTree2 *tr);//* this function returns a mirror of the BST tr.

bool isBalencedBST(TTree2 *tr);//* this function checks if a given BTS tr is balanced.

TTree2 *BTSMerge(TTree2 *tr1, TTree2 *tr2);//* this function merges two BST tr1 and tr2 into a single balanced BTS.


//*Helper functions :

void StoreBSTinOrderHelper(TTree2 *tr,TQueue **q);

void StoreBSTpreOrderHelper(TTree2 *tr,TQueue **q);

void StoreBSTpostOrderHelper(TTree2 *tr,TQueue **q);

int HighBSTHelper(TTree2 *tr);

void SizeBSTHelper(TTree2 *tr,int *counter);

int helper(QNode *q);




#endif 
