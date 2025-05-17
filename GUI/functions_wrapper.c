#include "functions_wrapper.h"
#include "tree_utils.h"
#include "recursion_utils.h"
#include "code.h"

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

// Linked List, Stack, and Queue functions
TList* fw_getSynWords(const char *filename) {
    FILE *f = fopen(filename, "r");
    if (!f) return NULL;
    TList *result = getSynWords(f);
    fclose(f);
    return result;
}

TList* fw_getAntoWords(const char *filename) {
    FILE *f = fopen(filename, "r");
    if (!f) return NULL;
    TList *result = getAntoWords(f);
    fclose(f);
    return result;
}

void fw_getInfWord(TList *syn, TList *ant, char *word) {
    getInfWord(syn, ant, word);
}

void fw_printWords(TList *list, int option) {
    printWords(list, option);
}

TList* fw_sortWord(TList *syn) {
    return sortWord(syn);
}

TList* fw_sortWord2(TList *syn) {
    return sortWord2(syn);
}

TList* fw_sortWord3(TList *syn) {
    return sortWord3(syn);
}

void fw_deleteWord(const char *filename, TList *syn, TList *ant, char *word) {
    FILE *f = fopen(filename, "r");
    if (!f) return;
    deleteWord(f, syn, ant, word);
    fclose(f);
}

void fw_updateWord(const char *filename, TList *syn, TList *ant, char *word, char *syne, char *anton) {
    FILE *f = fopen(filename, "r");
    if (!f) return;
    updateWord(f, syn, ant, word, syne, anton);
    fclose(f);
}

TList* fw_similarWord(TList *syn, char *word, int rate) {
    return similarWord(syn, word, rate);
}

TList* fw_countWord(TList *syn, char *prt) {
    return countWord(syn, prt);
}

TList* fw_palindromWord(TList *syn) {
    return palindromWord(syn);
}

TStack* fw_toStack(TList *list) {
    // This is a simplified implementation - in a real scenario, you'd need proper conversion
    // For now, we'll create a dummy implementation that works with TList instead of TList2
    TStack *stack = createStack();
    return stack;
}

void fw_printStack(TStack *stk) {
    printStack(stk);
}

void fw_printStackWords(TStack *stk) {
    printStack(stk);
}

TStack* fw_getInfWordStack(TStack *stk, char *word) {
    return getInfWordStack(stk, word);
}

TStack* fw_sortWordStack(TStack *stk) {
    return sortWordStack(stk);
}

TStack* fw_deleteWordStack(TStack *stk, char *word) {
    return deleteWordStack(stk, word);
}

TStack* fw_updateWordStack(TStack *stk, char *word, char *syne, char *anton) {
    return updateWordStack(stk, word, syne, anton);
}

TStack* fw_addWordStack(TStack *stk, char *word, char *syne, char *anton) {
    return addWordStack(stk, word, syne, anton);
}

TQueue* fw_syllable(TList *syn) {
    return syllable(syn);
}

TQueue** fw_prounounciation(TList *syn) {
    return prounounciation(syn);
}

void fw_printQueueWords(TQueue *queue) {
    printQueueWords(queue);
}

TQueue* fw_stackToQueue(TStack *stk) {
    // Simplified implementation for now
    TQueue *queue = createQueue();
    if (!stk || isStackEmpty(stk)) return queue;

    // Just create a dummy queue with a single entry for demonstration
    QNode *newnode = (QNode *)malloc(sizeof(QNode));
    strcpy(newnode->word, "Converted from stack");
    newnode->next = NULL;
    queue->front = queue->rear = newnode;
    return queue;
}
