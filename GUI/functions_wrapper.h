#ifndef FUNCTIONS_WRAPPER_H
#define FUNCTIONS_WRAPPER_H

#include "unified_data_structures.h"

// Trees functions
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

#endif // FUNCTIONS_WRAPPER_H
