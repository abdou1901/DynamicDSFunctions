#ifndef STACK_H
#define STACK_H

#include "common.h"
#include "../../📥 Queues/🔸PART II/Queues.h"
#include"../../➡️ SinglyLinkedList/🔸PART II/LinkedLists.h"
// Simple stack for character-by-character operations
typedef struct Tnode {
    char c;
    struct Tnode *next;
} Tnode;

typedef struct Tstack2 {
    Tnode *head;
} Tstack2;

// Stack for nodes
typedef struct TStack {
    cnode *head;
} TStack;

// Stack operations
TStack *createStack();
bool isStackEmpty(TStack *stk);
void pushToStack(TStack *stk, cnode *nod);
cnode *peakStack(TStack *stk);
cnode *popFromStack(TStack *stk);
void printStack(TStack *stk);
int lengthStack(TStack *stk);

// Stack utility functions
cnode *searchNodeInStack(TStack *stk, char *word);
void insertSorted(TStack *stk, cnode *newnode);
void addNodesToArray(cnode **arr, int index, TStack *stk);
cnode *copyNode(cnode *src);

// Stack word operations
TStack *toStack(TList2 *merged);
TStack *getInfWordStack(TStack *stk, char *word);
TStack *sortWordStack(TStack *stk);
TStack *deleteWordStack(TStack *stk, char *word);
TStack *updateWordStack(TStack *stk, char *word, char *syne, char *anton);
TStack *addWordStack(TStack *stk, char *word, char *syne, char *anton);
TStack *syllableStack(TStack *stk);
TStack *StackRev(TStack *stk);
TStack **pronunciationStack(TStack *stk);
void InsertToPronunciationStacks(TStack *stk, TStack **stacks);
TList2 *StacktoList(TStack *stk);

// Word finding functions
void smallestword(TStack *stk, cnode **minnode);
char *getSmallest(TStack *stk);

// Comparison functions
int compareNodes2(const void *a, const void *b);

// Simple character stack operations
bool isSimpleStackEmpty(Tstack2 *stk);
void push(Tstack2 *stk, char c);
char pop(Tstack2 *stk);
void insertWordInverse(char *word, int index, Tstack2 *stk);
bool isPalindromeStack(char *word);

#endif // STACK_H