#ifndef FUNCTIONS_WRAPPER_H
#define FUNCTIONS_WRAPPER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "unified_data_structures.h"

//* Trees functions
TTree2* fw_fillTree(const char *filename);
void fw_printTreeNodeCharacteristics(TTree2 *tr, char *word);
void fw_TraversalBSTinOrder(TTree2 *tr);
void fw_TraversalBSTpreOrder(TTree2 *tr);
void fw_TraversalBSTpostOrder(TTree2 *tr);
TTree2* fw_deleteWordBST(TTree2 *tr, char *word);
TTree2* fw_UpdateWordBST(TTree2 *tr, char *word, char *syne, char *anton);
TTree2* fw_deleteSyn(TTree2 *tr, char* word, char *syn);
TTree2* fw_deleteAnt(TTree2 *tr, char* word, char *ant);
void fw_HighSizeBST(TTree2 *tr);
TTree2* fw_LowestCommonAncestor(TTree2 *tr, char *word1, char *word2);
int fw_CountNodesRanges(TTree2 *tr, int l, int h);
TTree2* fw_inOrderSuccesor(TTree2 *tr, char *word);
TTree2* fw_BSTMirror(TTree2 *tr);
int fw_isBalencedBST(TTree2 *tr);

// Recursion functions
void fw_wordPermutation(char *word);
void fw_subseqWord(char *word);
int fw_longestSubseqWord(char *word1, char *word2);
int fw_distinctSubseqWord(char *word);
int fw_isPalindromWord(char *word);

// Linked List, Stack, and Queue functions
TList* fw_getSynWords(const char *filename);
TList* fw_getAntoWords(const char *filename);
void fw_getInfWord(TList *syn, TList *ant, char *word);
void fw_printWords(TList *list, int option);
TList* fw_sortWord(TList *syn);
TList* fw_sortWord2(TList *syn);
TList* fw_sortWord3(TList *syn);
void fw_deleteWord(const char *filename, TList *syn, TList *ant, char *word);
void fw_updateWord(const char *filename, TList *syn, TList *ant, char *word, char *syne, char *anton);
TList* fw_similarWord(TList *syn, char *word, int rate);
TList* fw_countWord(TList *syn, char *prt);
TList* fw_palindromWord(TList *syn);
TStack* fw_toStack(TList *list);
void fw_printStack(TStack *stk);
void fw_printStackWords(TStack *stk);
TStack* fw_getInfWordStack(TStack *stk, char *word);
TStack* fw_sortWordStack(TStack *stk);
TStack* fw_deleteWordStack(TStack *stk, char *word);
TStack* fw_updateWordStack(TStack *stk, char *word, char *syne, char *anton);
TStack* fw_addWordStack(TStack *stk, char *word, char *syne, char *anton);
TQueue* fw_syllable(TList *syn);
TQueue** fw_prounounciation(TList *syn);
void fw_printQueueWords(TQueue *queue);
TQueue* fw_stackToQueue(TStack *stk);

#endif // FUNCTIONS_WRAPPER_H
