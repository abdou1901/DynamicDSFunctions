#ifndef TREE_UTILS_H
#define TREE_UTILS_H

#include "unified_data_structures.h"

// WordNode operations
WordNode *copyNodeList(WordNode *src);
void printWordNodeList(WordNode *head);
void insertAtEnd(WordNode **head, const char *newWord);
int countWordNodes(WordNode *head);

// Tree node operations
TTree2 *createTreeNode2(const char *word, WordNode *synonyms, WordNode *antonyms);
TTree2 *insertBST2(TTree2 *root, const char *word, WordNode *synonyms, WordNode *antonyms);
TTree2 *findMinNode2(TTree2 *node);
int tree_countVowels(char *word);

// Stack operations for trees
TStack2Tree *createStack2();
void push2(TStack2Tree *stack, TTree2 *node);
TTree2 *pop2(TStack2Tree *stack);
bool isStack2Empty(TStack2Tree *stack);

// Queue operations for trees
TQueue *tree_createQueue();
void tree_enqueue(TQueue *q, TTree2 *node);
TTree2 *dequeue(TQueue *q);
bool isEmptyQueue(TQueue *q);
int lenQueue(TQueue *q);

// Tree operations
TTree2 *toTree(TStack2Tree *stk);
TTree2 *fillTree(const char *filename);
TTree2 *getInfWordTree(TTree2 *tr, char *word);
void printTreeNodeCharacteristics(TTree2 *tr, char *word);
void AddWordBST(TTree2 *tr, char *word, WordNode *synonyms, WordNode *antonyms, TStack2Tree **stk);
TTree2 *deleteWordBST(TTree2 *tr, char *word);
TTree2 *UpdateWordBST(TTree2 *tr, char *word, char *syne, char *anton);
void printTrNode(TTree2 *tr);
TTree2 *deleteSyn(TTree2 *tr, char *word, char *syn);
TTree2 *deleteAnt(TTree2 *tr, char *word, char *ant);
void TraversalBSTinOrder(TTree2 *tr);
void TraversalBSTpreOrder(TTree2 *tr);
void TraversalBSTpostOrder(TTree2 *tr);
TQueue *StoreBSTinOrder(TTree2 *tr);
TQueue *StoreBSTpreOrder(TTree2 *tr);
TQueue *StoreBSTpostOrder(TTree2 *tr);
void HighSizeBST(TTree2 *tr);
TTree2 *LowestCommonAncestor(TTree2 *tr, char *word1, char *word2);
int CountNodesRanges(TTree2 *tr, int l, int h);
TTree2 *inOrderSuccesor(TTree2 *tr, char *word);
TTree2 *BSTMirror(TTree2 *tr);
int isBalencedBST(TTree2 *tr);

// Helper functions
void StoreBSTinOrderHelper(TTree2 *tr, TQueue **q);
void StoreBSTpreOrderHelper(TTree2 *tr, TQueue **q);
void StoreBSTpostOrderHelper(TTree2 *tr, TQueue **q);
int HighBSTHelper(TTree2 *tr);
void SizeBSTHelper(TTree2 *tr, int *counter);
int helper(QNode *q);

#endif // TREE_UTILS_H