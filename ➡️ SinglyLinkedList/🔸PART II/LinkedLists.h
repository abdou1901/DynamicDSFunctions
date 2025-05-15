#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "common/common.h"
#include "../../🗂️ Stacks/🔸PART II/Stacks.h"
#include "../../📥 Queues/🔸PART II/Queues.h"
// Node structure for singular linked list 
typedef struct Node {
    char word[WORD_MAX_LENGTH];
    char relatedWord[WORD_MAX_LENGTH]; // synonym or antonym
    int charCount;
    int vowelCount;
    struct Node *next;
} node;

// Structure of a node used in a bidirectional linked list 
typedef struct DNode {
    char word[WORD_MAX_LENGTH];
    char synonym[WORD_MAX_LENGTH];
    char antonym[WORD_MAX_LENGTH];
    int charCount;
    int vowelCount;
    struct DNode *prev, *next;
} dnode;

// Structure of the node used in the circular linked list
typedef struct cnode {
    char word[WORD_MAX_LENGTH];
    char synonym[WORD_MAX_LENGTH];
    char antonym[WORD_MAX_LENGTH];
    int charCount;
    int vowelCount;
    struct cnode *next;
} cnode;

// Structure of the singly linked list
typedef struct {
    node *head;
} TList;

// Structure of bidirectional linked list (used in merge function)
typedef struct {
    dnode *head;
    dnode *tail;
} TList2;

// Structure of circular linked list (used in merge2 function)
typedef struct {
    cnode *head;
    cnode *tail;
} TList3;

// Linked list functions
node *createNode(char *word, char *relatedWord);
void addNodeAtEnd(TList *list, char *word, char *relatedWord);
void SwapData(node *node1, node *node2);
void printWords(TList *list, int option);
void printWords2(TList2 *list);
void printWords3(TList3 *list);

// File operations with linked lists
TList *getSynWords(FILE *f);
TList *getAntoWords(FILE *f);
void getInfWord(TList *syn, TList *ant, char *word);
void getInfWord2(TList *syn, TList *ant, char *inf);
void deleteWord(FILE *f, TList *syn, TList *ant, char *word);
void updateWord(FILE *f, TList *syn, TList *ant, char *word, char *syne, char *anton);
void addWord(FILE *f, TList *syn, TList *ant, char *word, char *syne, char *anton);

// Sorting and searching linked lists
TList *sortWord(TList *syn);   // Sort by word alphabetically
TList *sortWord2(TList *syn);  // Sort by char count
TList *sortWord3(TList *syn);  // Sort by vowel count
TList *similarWord(TList *syn, char *word, int rate);
TList *countWord(TList *syn, char *prt);
TList *palindromWord(TList *syn);

// Merging linked lists
TList2 *merge(TList *syn, TList *ant);
TList3 *merge2(TList *syn, TList *ant);

#endif // LINKEDLIST_H