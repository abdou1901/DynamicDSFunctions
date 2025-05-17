#ifndef CODE_UTILS_H
#define CODE_UTILS_H

#include "unified_data_structures.h"

//* Utility functions
void printCentered(char *str, int width);
bool includes(char *str, char c, int size);
int countVowels(char *str);
Node *createNode(char *word, char *relatedWord);
void addNodeAtEnd(TList *list, char *word, char *relatedWord);
void swapData(Node *node1, Node *node2);
void printWords(TList *list, int option);
int matchRate(char *word1, char *word2);
bool isPalindrome(char *s, int l, int r);
void printWords2(TList2 *list);
void printWords3(TList3 *list);
int is_vowel(char c);
int count_syllables(const char *word);

// Queue operations
TQueue *createQueue();
void enqueue(TQueue *queue, char *word);
void printQueueWords(TQueue *queue);

// Stack operations
TStack *createStack();
void printStack(TStack *stk);
bool isStackEmpty(TStack *stk);
void pushToStack(TStack *stk, CNode *nod);
CNode *peakStack(TStack *stk);
CNode *popFromStack(TStack *stk);
CNode *searchNodeInStack(TStack *stk, char *word);
void insertSorted(TStack *stk, CNode *newnode);

//* Simple stack operations
bool isSimpleStackEmpty(TStack2 *stk);
void push(TStack2 *stk, char c);
char pop(TStack2 *stk);

//* Vowel type functions
VowelType getVowelType(const char *word);

#endif // CODE_UTILS_H
