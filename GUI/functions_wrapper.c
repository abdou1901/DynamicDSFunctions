#include "functions_wrapper.h"
#include "tree_utils.h"
#include "recursion_utils.h"

//* Trees functions
TTree2* fw_fillTree(const char *filename) {
    return fillTree(filename);
}

void fw_printTreeNodeCharacteristics(TTree2 *tr, char *word) {
    printTreeNodeCharacteristics(tr, word);
}

void fw_TraversalBSTinOrder(TTree2 *tr) {
    TraversalBSTinOrder(tr);
}

void fw_TraversalBSTpreOrder(TTree2 *tr) {
    TraversalBSTpreOrder(tr);
}

void fw_TraversalBSTpostOrder(TTree2 *tr) {
    TraversalBSTpostOrder(tr);
}

TTree2* fw_deleteWordBST(TTree2 *tr, char *word) {
    return deleteWordBST(tr, word);
}

TTree2* fw_UpdateWordBST(TTree2 *tr, char *word, char *syne, char *anton) {
    return UpdateWordBST(tr, word, syne, anton);
}

TTree2* fw_deleteSyn(TTree2 *tr, char* word, char *syn) {
    return deleteSyn(tr, word, syn);
}

TTree2* fw_deleteAnt(TTree2 *tr, char* word, char *ant) {
    return deleteAnt(tr, word, ant);
}

void fw_HighSizeBST(TTree2 *tr) {
    HighSizeBST(tr);
}

TTree2* fw_LowestCommonAncestor(TTree2 *tr, char *word1, char *word2) {
    return LowestCommonAncestor(tr, word1, word2);
}

int fw_CountNodesRanges(TTree2 *tr, int l, int h) {
    return CountNodesRanges(tr, l, h);
}

TTree2* fw_inOrderSuccesor(TTree2 *tr, char *word) {
    return inOrderSuccesor(tr, word);
}

TTree2* fw_BSTMirror(TTree2 *tr) {
    return BSTMirror(tr);
}

int fw_isBalencedBST(TTree2 *tr) {
    return isBalencedBST(tr);
}

// Recursion functions
void fw_wordPermutation(char *word) {
    wordPermutation(word);
}

void fw_subseqWord(char *word) {
    subseqWord(word);
}

int fw_longestSubseqWord(char *word1, char *word2) {
    return longestSubseqWord(word1, word2);
}

int fw_distinctSubseqWord(char *word) {
    return distinctSubseqWord(word);
}

int fw_isPalindromWord(char *word) {
    return isPalindromWord(word);
}
