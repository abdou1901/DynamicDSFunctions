#ifndef CODE_H
#define CODE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

#define WORD_MAX_LENGTH 50

// Node structures
// Node structure for singular linked list 
typedef struct Node {
    char word[50];
    char relatedWord[50]; // synonym or antonym
    int charCount;
    int vowelCount;
    struct Node *next;
} Node;

// Structure of a node used in a bidirectional linked list 
typedef struct DNode {
    char word[50];
    char synonym[50];
    char antonym[50];
    int charCount;
    int vowelCount;
    struct DNode *prev, *next;
} DNode;

// Structure of the node used in the circular linked list (also on the stack)
typedef struct CNode {
    char word[50];
    char synonym[50];
    char antonym[50];
    int charCount;
    int vowelCount;
    struct CNode *next;
} CNode;

// Structure of a node used in a simple stack to check if a word is palindrome
typedef struct TNode {
    char c;
    struct TNode *next;
} TNode;

// Structure of the singly linked list
typedef struct {
    Node *head;
} TList;

// Structure of bidirectional linked list (used in merge function)
typedef struct {
    DNode *head;
    DNode *tail;
} TList2;

// Structure of circular linked list (used in merge2 function)
typedef struct {
    CNode *head;
    CNode *tail;
} TList3;

// RENAMED to avoid collision with trees.h
// Structure of the node used in the Queue
typedef struct WordQNode {
    char word[50];
    struct WordQNode *next;
} WordQNode;

// Structure of the queue 
typedef struct WordQueue {
    WordQNode *head;
    WordQNode *tail;
} WordQueue;

typedef struct CNodeStack {
    CNode *head;
} CNodeStack;

typedef struct CharStack {
    TNode *head;
} CharStack;

// Enum
enum VowelType { SHORT, LONG, DIPHTHONG, UNKNOWN };

// Function declarations
// Utility functions
void printCentered(char *str, int width);
bool includes(char *str, char c, int size);
int countVowels(char *str);
int is_vowel(char c);
int count_syllables(const char *word);
enum VowelType getVowelType(const char *word);
int matchRate(char *word1, char *word2);
bool isPalindrome(char *s, int l, int r);

// List operations
Node *createNode(char *word, char *relatedWord);
void addNodeAtEnd(TList *list, char *word, char *relatedWord);
void SwapData(Node *node1, Node *node2);
void printWords(TList *list, int option);
void printWords2(TList2 *list);
void printWords3(TList3 *list);

// Queue operations
WordQueue *createWordQueue();
void enqueueWord(WordQueue *queue, char *word);
void printQueueWords(WordQueue *queue);

// Stack operations
CNodeStack *createCNodeStack();
void printStack(CNodeStack *stk);
bool isCNodeStackEmpty(CNodeStack *stk);
void pushToCNodeStack(CNodeStack *stk, CNode *nod);
CNode *peakStack(CNodeStack *stk);
CNode *popFromCNodeStack(CNodeStack *stk);
CNode *searchNodeInStack(CNodeStack *stk, char *word);
void insertSorted(CNodeStack *stk, CNode *newnode);

// Character stack operations
bool isCharStackEmpty(CharStack *stk);
void pushChar(CharStack *stk, char c);
char popChar(CharStack *stk);
bool isPalyndromeStack(char *word);

// File operations
TList *getSynWords(FILE *f);
TList *getAntoWords(FILE *f);
void getInfWord(TList *syn, TList *ant, char *word);
void getInfWord2(TList *syn, TList *ant, char *inf);
void deleteWord(FILE *f, TList *syn, TList *ant, char *word);
void updateWord(FILE *f, TList *syn, TList *ant, char *word, char *syne, char *anton);
void addWord(FILE *f, TList *syn, TList *ant, char *word, char *syne, char *anton);

// Sorting and filtering
TList *sortWord(TList *syn);
TList *sortWord2(TList *syn);
TList *sortWord3(TList *syn);
TList *similarWord(TList *syn, char *word, int rate);
TList *countWord(TList *syn, char *prt);
TList *palindromWord(TList *syn);

// Merging operations
TList2 *merge(TList *syn, TList *ant);
TList3 *merge2(TList *syn, TList *ant);

// Word analysis
WordQueue *syllable(TList *syn);
WordQueue **prounounciation(TList *syn);
WordQueue *toQueue(TList2 *merged);

// Stack operations
CNodeStack *toStack(TList2 *merged);
CNodeStack *getInfWordStack(CNodeStack *stk, char *word);
CNodeStack *sortWordStack(CNodeStack *stk);
CNodeStack *deleteWordStack(CNodeStack *stk, char *word);
CNodeStack *updateWordStack(CNodeStack *stk, char *word, char *syne, char *anton);
CNodeStack *addWordStack(CNodeStack *stk, char *word, char *syne, char *anton);
CNodeStack *syllableStack(CNodeStack *stk);
CNodeStack *StackRev(CNodeStack *stk);
CNodeStack **prounounciationStack(CNodeStack *stk);
void InserToPronounciationStacks(CNodeStack *stk, CNodeStack **stacks);

// Conversion functions
WordQueue *stackToQueue(CNodeStack *stk);
TList2 *StacktoList(CNodeStack *stk);

// Stack utility
int lengthStack(CNodeStack *stk);
void addNodesToArray(CNode **arr, int index, CNodeStack *stk);
int compareNodes2(const void *a, const void *b);
char *getSmallest(CNodeStack *stk);
void smallestword(CNodeStack *stk, CNode **minnode);
void insertWordInverse(char *word, int index, CharStack *stk);

#endif // CODE_H