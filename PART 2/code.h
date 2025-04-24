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
//Node structure for singular linked list 
typedef struct Node {
    char word[50];
    char relatedWord[50];//synonym or antonym
    int charCount;
    int vowelCount;
    struct Node *next;
} node;

//structure of a node used in a biderectional linked list 
typedef struct DNode {
    char word[50];
    char synonym[50];
    char antonym[50];
    int charCount;
    int vowelCount;
    struct DNode *prev, *next;
} dnode;

//strcture of the node used in the circular linked list ( also on the stack )
typedef struct cnode {
    char word[50];
    char synonym[50];
    char antonym[50];
    int charCount;
    int vowelCount;
    struct cnode *next;
} cnode;

//structure of a node used in a simple stack to check if a word is palindrome
typedef struct Tnode{
    char c;
    struct Tnode *next;
}Tnode;

//structure of the singly linked list
typedef struct {
    node *head;
} TList;

// structure of bidirectional linked list (used in merge function)
typedef struct {
    dnode *head;
    dnode *tail;
} TList2;

//structure of circular linked list (used in merge2 function)
typedef struct {
    cnode *head;
    cnode *tail;
} TList3;

//structure of the node used in the Queue
typedef struct QNode {
    char word[50];
    struct QNode *next;
} QNode;
//structure of the queue 
typedef struct TQueue {
    QNode *head;
    QNode *tail;
} TQueue;
typedef struct TStack{
    cnode *head;
}TStack ;
typedef struct Tstack2{
    Tnode *head;
}Tstack2;

//enum
enum VowelType { SHORT, LONG, DIPHTHONG, UNKNOWN };

// functions 
void printCentered(char *str, int width);
bool includes(char *str, char c, int size);
int countVowels(char *str);
node *createNode(char *word , char *relatedWord);
void addNodeAtEnd(TList *list, char *word, char *relatedWord);
void SwapData(node *node1 , node *node2);
void printWords(TList *list, int option);
int matchRate(char *word1, char *word2);
bool isPalindrome(char *s, int l, int r);
void printWords2(TList2 *list);
void printWords3(TList3 *list);
int is_vowel(char c);
int count_syllables(const char *word);
TQueue *createQueue();
TStack *createStack();
void printQueueWords(TQueue *queue);
enum VowelType getVowelType(const char *word);
void printStack(TStack *stk);
bool isStackEmpty(TStack *stk);
void pushToStack(TStack *stk , cnode *nod);
cnode *peakStack(TStack *stk);
cnode *popFromStack(TStack *stk);
cnode *searchNodeInStack(TStack *stk, char *word);
void insertSorted(TStack *stk , cnode *newnode);
TList *getSynWords(FILE *f);
TList *getAntoWords(FILE *f);
void getInfWord(TList *syn, TList *ant, char *word);
void getInfWord2(TList *syn, TList *ant, char *inf);

TList *sortWord(TList *syn);
TList *sortWord2(TList *syn);
TList *sortWord3(TList *syn);

void deleteWord(FILE *f, TList *syn, TList *ant, char *word);
void updateWord(FILE *f , TList *syn, TList *ant, char *word, char *syne, char *anton);

TList *similarWord(TList *syn, char *word, int rate);
TList *countWord(TList *syn, char *prt);
TList *palindromWord(TList *syn);
TList2 *merge(TList *syn, TList *ant);
TList3 *merge2(TList *syn, TList *ant);
void addWord(FILE *f,TList *syn, TList *ant, char *word, char *syne, char *anton);
TQueue *syllable(TList *syn);
TQueue **prounounciation(TList *syn);
TQueue *toQueue(TList2 *merged);
TStack *toStack(TList2 *merged);
TStack *getInfWordStack(TStack *stk, char *word);
TStack *sortWordStack(TStack *stk);
TStack *deleteWordStack(TStack *stk, char *word);
TStack *updateWordStack(TStack *stk, char *word, char *syne, char *anton);
TStack *addWordStack(TStack *stk, char *word, char *syne, char *anton);
TStack *syllableStack(TStack *stk);
TStack *StackRev(TStack *stk);
TStack **prounounciationStack(TStack *stk);
void InserToPronounciationStacks(TStack *stk, TStack **stacks);

TQueue *stackToQueue(TStack *stk);
TList2 *StacktoList(TStack *stk);

bool isSimpleStackEmpty(Tstack2 *stk);
void push(Tstack2 *stk, char c);
char pop(Tstack2 *stk);
bool isPalyndromeStack(char *word);

int lengthStack(TStack *stk);
void addNodesToArray(cnode **arr, int index, TStack *stk);
int compareNodes2(const void *a, const void *b);
char *getSmallest(TStack *stk);
void smallestword(TStack *stk, cnode **minnode);

void insertWordInverse(char *word, int index, Tstack2 *stk);
#endif // WORD_LIBRARY_H
