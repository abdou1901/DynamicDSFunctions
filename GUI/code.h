#ifndef BFA6D897_E220_4FD4_A052_F4BEB91360E9
#define BFA6D897_E220_4FD4_A052_F4BEB91360E9
#ifndef CODE_H
#define CODE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>
#include "unified_data_structures.h"

#define WORD_MAX_LENGTH 50

// Function declarations
void printCentered(char *str, int width);
bool includes(char *str, char c, int size);
int countVowels(char *str);
Node *createNode(char *word , char *relatedWord);
void addNodeAtEnd(TList *list, char *word, char *relatedWord);
void SwapData(Node *node1 , Node *node2);
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
VowelType getVowelType(const char *word);
void printStack(TStack *stk);
bool isStackEmpty(TStack *stk);
void pushToStack(TStack *stk , CNode *nod);
CNode *peakStack(TStack *stk);
CNode *popFromStack(TStack *stk);
CNode *searchNodeInStack(TStack *stk, char *word);
void insertSorted(TStack *stk , CNode *newnode);
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

bool isSimpleStackEmpty(TStack2 *stk);
void push(TStack2 *stk, char c);
char pop(TStack2 *stk);
bool isPalyndromeStack(char *word);

int lengthStack(TStack *stk);
void addNodesToArray(CNode **arr, int index, TStack *stk);
int compareNodes2(const void *a, const void *b);
char *getSmallest(TStack *stk);
void smallestword(TStack *stk, CNode **minnode);

void insertWordInverse(char *word, int index, TStack2 *stk);

// Tree functions
TTree2* fillTree(const char *filename);
void printTreeNodeCharacteristics(TTree2 *tr, char *word);
void TraversalBSTinOrder(TTree2 *tr);
void TraversalBSTpreOrder(TTree2 *tr);
void TraversalBSTpostOrder(TTree2 *tr);
TTree2* deleteWordBST(TTree2 *tr, char *word);
TTree2* UpdateWordBST(TTree2 *tr, char *word, char *syne, char *anton);
TTree2* deleteSyn(TTree2 *tr, char* word, char *syn);
TTree2* deleteAnt(TTree2 *tr, char* word, char *ant);
void HighSizeBST(TTree2 *tr);
TTree2* LowestCommonAncestor(TTree2 *tr, char *word1, char *word2);
int CountNodesRanges(TTree2 *tr, int l, int h);
TTree2* inOrderSuccesor(TTree2 *tr, char *word);
TTree2* BSTMirror(TTree2 *tr);
int isBalencedBST(TTree2 *tr);

// Recursion functions
void wordPermutation(char *word);
void subseqWord(char *word);
int longestSubseqWord(char *word1, char *word2);
int distinctSubseqWord(char *word);
bool isPalindromWord(char *word);

#endif // CODE_H
#endif /* BFA6D897_E220_4FD4_A052_F4BEB91360E9 */
