#include "trees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Helper functions and implementations
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

int helperQueueLen(TreeQNode *q) {
    if (q == NULL) return 0;
    return 1 + helperQueueLen(q->next);
}

WordNode *copyNodeList(WordNode *src) {
    WordNode *dst = NULL;
    while (src != NULL) {
        insertAtEnd(&dst, src->word);
        src = src->next;
    }
    return dst;    
}

void printWordNodeList(WordNode *head) {
    while (head != NULL) {
        printf("|%s", head->word);
        head = head->next;
    }
    printf("|");
    printf("\n");
}

void insertAtEnd(WordNode **head, const char *newWord) {
    WordNode *newNode = (WordNode *)malloc(sizeof(WordNode));
    strcpy(newNode->word, newWord);
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    WordNode *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

TTree2* createTreeNode2(const char *word, WordNode *synonyms, WordNode *antonyms) {
    TTree2 *newNode = (TTree2*)malloc(sizeof(TTree2));
    if (!newNode) return NULL;

    strcpy(newNode->word, word);
    newNode->antonym = NULL;
    newNode->synonym = NULL;
    
    while (synonyms != NULL) {
       insertAtEnd(&(newNode->synonym), synonyms->word);
       synonyms = synonyms->next;      
    }
    
    while (antonyms != NULL) {
        insertAtEnd(&(newNode->antonym), antonyms->word);
        antonyms = antonyms->next;
    }
    
    newNode->left = newNode->right = NULL;
    return newNode;
}

TTree2* insertBST2(TTree2 *root, const char *word, WordNode *synonyms, WordNode *antonyms) {
    if (root == NULL) return createTreeNode2(word, synonyms, antonyms);

    int cmp = strcmp(word, root->word);
    if (cmp < 0)
        root->left = insertBST2(root->left, word, synonyms, antonyms);
    else if (cmp > 0)
        root->right = insertBST2(root->right, word, synonyms, antonyms);

    return root;
}

int countVowels(char *word) {
    int count = 0;
    for (int i = 0; i < strlen(word); i++) {
        char c = tolower(word[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')  count++;
    }
    return count;
}

TTree2 *findMinNode2(TTree2 *node) {
    while (node && node->left != NULL)
        node = node->left;
    return node;
}

int countWordNodes(WordNode *head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Stack operations
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

TStack2* createTreeStack() {
    TStack2 *stack = (TStack2*)malloc(sizeof(TStack2));
    stack->top = NULL;
    return stack;
}

void pushTree(TStack2 *stack, TTree2 *node) {
    TStackNode2 *newNode = (TStackNode2*)malloc(sizeof(TStackNode2));
    newNode->treeNode = node;
    newNode->next = stack->top;
    stack->top = newNode;
}

TTree2* popTree(TStack2 *stack) {  
    if (stack->top == NULL) return NULL;
    TStackNode2 *temp = stack->top;
    TTree2 *node = temp->treeNode;
    stack->top = temp->next;
    free(temp);
    return node;
}

bool isTreeStackEmpty(TStack2 *stack) {
    return (stack->top == NULL) ? true : false;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Queue operations
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

TreeQueue *createTreeQueue() {
    TreeQueue *q = (TreeQueue*)malloc(sizeof(TreeQueue));
    q->front = NULL; 
    q->rear = NULL;
    return q;
}

void enqueueTree(TreeQueue *q, TTree2 *node) {
    TreeQNode *newnode = (TreeQNode*)malloc(sizeof(TreeQNode));
    newnode->treeNode = node;
    newnode->next = NULL;
    if (q->front == NULL && q->rear == NULL) {
        q->front = newnode;
        q->rear = newnode;
    } else {
        q->rear->next = newnode;
        q->rear = newnode;
    }
}

TTree2 *dequeueTree(TreeQueue *q) {
    if (q->front == NULL) return NULL; 
    
    TreeQNode *temp = q->front;
    TTree2 *node = temp->treeNode;
    q->front = q->front->next;
    
    if (q->front == NULL) {
        q->rear = NULL;
    }
    
    free(temp);
    return node;
}

bool isTreeQueueEmpty(TreeQueue *q) {
    return q->front == NULL;
}

int lenTreeQueue(TreeQueue *q) {
    if (q == NULL || q->front == NULL) return 0;  
    return helperQueueLen(q->front);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Helper functions for BST operations
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void StoreBSTinOrderHelper(TTree2 *tr, TreeQueue **q) {
    if (tr != NULL) { 
        StoreBSTinOrderHelper(tr->left, q);
        enqueueTree(*q, tr);
        StoreBSTinOrderHelper(tr->right, q);
    }
    return;
}

void StoreBSTpreOrderHelper(TTree2 *tr, TreeQueue **q) {
    if (tr != NULL) { 
        enqueueTree(*q, tr);
        StoreBSTpreOrderHelper(tr->left, q);
        StoreBSTpreOrderHelper(tr->right, q);
    }
    return;
}

void StoreBSTpostOrderHelper(TTree2 *tr, TreeQueue **q) {
    if (tr != NULL) { 
        StoreBSTpostOrderHelper(tr->left, q);
        StoreBSTpostOrderHelper(tr->right, q);
        enqueueTree(*q, tr);
    }
    return;
}

int HighBSTHelper(TTree2 *tr) {
    if (!tr) return -1;
    int lh = HighBSTHelper(tr->left);
    int rh = HighBSTHelper(tr->right);
    return ((rh > lh) ? rh : lh) + 1;  
}

void SizeBSTHelper(TTree2 *tr, int *counter) {
    if (!tr) return;
    (*counter)++; 
    SizeBSTHelper(tr->left, counter);
    SizeBSTHelper(tr->right, counter);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Tree operations and functions
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

TTree2 *toTree2(TStack2 *stk) {
    if (isTreeStackEmpty(stk)) return NULL;

    TTree2 *root = popTree(stk);

    while (!isTreeStackEmpty(stk)) {
        TTree2 *nextN = popTree(stk);
        root = insertBST2(root, nextN->word, nextN->synonym, nextN->antonym);
    }
    
    return root;
}

TTree2 *fillTree(const char *filename) {
    FILE *f = fopen(filename, "r");
    if (!f) {
        printf("\033[0;31mError: Could not open file %s\033[0m\n", filename);
        return NULL;
    }
    
    char line[500];
    TTree2 *root = NULL;
    int lineCount = 0;
    
    while(fgets(line, sizeof(line), f) != NULL) {
        lineCount++;
        
        int len = (int)strlen(line);
        if (len > 0 && (line[len-1] == '\n' || line[len-1] == '\r')) line[len-1] = '\0';
        
        char *hashpos = strchr(line, '#');
        if (!hashpos) {
            printf("\033[0;31mLine %d does not contain '#' delimiter: %s\033[0m\n", lineCount, line);
            
            char *mainWord = strtok(line, "=");
            if (!mainWord || strlen(mainWord) == 0) {
                printf("\033[0;31mLine %d has no main word before '='\033[0m\n", lineCount);
                continue;
            }
            WordNode *synonyms = NULL;
            char *token = strtok(NULL, "=");
            while (token != NULL) {
                insertAtEnd(&synonyms, token);
                token = strtok(NULL, "=");
            }
            printf("\033[0;34mInserting word: '%s' with '%d' synonyms and '%d' antonyms ......\033[0m\n\n", 
                   mainWord, countWordNodes(synonyms), countWordNodes(NULL));
                
            root = insertBST2(root, mainWord, synonyms, NULL);
        } else {
            *hashpos = '\0';
            
            char *mainWord = strtok(line, "=");
            if (!mainWord || strlen(mainWord) == 0) {
                printf("\033[0;31mLine %d has no main word before '='\033[0m\n", lineCount);
                continue;
            }
            
            WordNode *synonyms = NULL;
            char *token = strtok(NULL, "=");
            while (token != NULL) {
                insertAtEnd(&synonyms, token);
                token = strtok(NULL, "=");
            }
            
            WordNode *antonyms = NULL;
            char *ant = hashpos + 1;
            token = strtok(ant, "=");
            while (token != NULL) {
                insertAtEnd(&antonyms, token);
                token = strtok(NULL, "=");
            }
            
            printf("\033[0;34mInserting word: '%s' with '%d' synonyms and '%d' antonyms......\n\033[0m\n", 
                   mainWord, countWordNodes(synonyms), countWordNodes(antonyms));
                   
            root = insertBST2(root, mainWord, synonyms, antonyms);
        }
    }
    printf("Done\n");
    fclose(f);
    if (!root) {
        printf("\033[0;31mTree is empty. Can't work with that file!\033[0m\n");
    }
    return root;
}

TTree2 *getInfWordTree(TTree2 *tr, char *word) {
    if (!tr) return NULL;  
    
    int cmp = strcmp(tr->word, word);
    if (!cmp) return tr;
    if (cmp < 0) return getInfWordTree(tr->right, word);    
    if (cmp > 0) return getInfWordTree(tr->left, word);
    
    return NULL;  
}

void printTreeNodeCharacteristics(TTree2 *tr, char *word) {
    TTree2 *target = getInfWordTree(tr, word);
    if (!target) {  
        printf("Word '%s' not found in tree\n", word);
        return;
    }
    
    printf("Word: %s\n", word);
    printf("Word length: %d\n", strlen(word));
    printf("Number Of Vowels: %d\n", countVowels(word));
    printf("Synonym(s) of %s: ", word);
    printWordNodeList(target->synonym);
    printf("Antonym(s) of %s: ", word);
    printWordNodeList(target->antonym);
}

void AddWordBST(TTree2 *tr, char *word, WordNode *synonyms, WordNode *antonyms, TStack2 **stk) {
    if (!(*stk)) *stk = createTreeStack();  
    
    if (!tr) {
        tr = createTreeNode2(word, synonyms, antonyms);
        pushTree(*stk, tr);
        return;
    }
    
    int cmp = strcmp(tr->word, word);
    if (cmp < 0)  AddWordBST(tr->right, word, synonyms, antonyms, stk);
    else if (cmp > 0)  AddWordBST(tr->left, word, synonyms, antonyms, stk);
}

TTree2 *deleteWordBST(TTree2 *tr, char *word) {
    if (tr == NULL) return NULL;

    int cmp = strcmp(word, tr->word);
    if (cmp < 0) {
        tr->left = deleteWordBST(tr->left, word);
    } else if (cmp > 0) {
        tr->right = deleteWordBST(tr->right, word);
    } else {
        // Node found
        if (tr->left == NULL) {
            TTree2 *temp = tr->right;
            free(tr);
            return temp;
        } else if (tr->right == NULL) {
            TTree2 *temp = tr->left;
            free(tr);
            return temp;
        }
        // Two children below the root
        TTree2 *temp = findMinNode2(tr->right);
        strcpy(tr->word, temp->word);
        tr->synonym = copyNodeList(temp->synonym);
        tr->antonym = copyNodeList(temp->antonym);
        tr->right = deleteWordBST(tr->right, temp->word);
    }
    return tr;
}

TTree2 *UpdateWordBST(TTree2 *tr, char *word, char *syne, char *anton) {
    TTree2 *target = getInfWordTree(tr, word);
    if (!target) return tr;
    
    insertAtEnd(&(target->synonym), syne);
    insertAtEnd(&(target->antonym), anton);
    return tr;
}

void printTrNode(TTree2 *tr) {
    if (!tr) return;  
    
    printf("\033[0;32mWord: %s\033[0m\n", tr->word);
    printf("\033[0;36mSynonym(s) of %s\033[0m: ", tr->word);
    printWordNodeList(tr->synonym);
    printf("\033[0;35mAntonym(s) of %s:\033[0m ", tr->word);
    printWordNodeList(tr->antonym);
    printf("\n");
}

TTree2 *deleteSyn(TTree2 *tr, char* word, char *syn) {
    TTree2 *target = getInfWordTree(tr, word);
    if (!target || !target->synonym) return tr; 
    
    WordNode *current = target->synonym;
    WordNode *prev = NULL;
    
    while (current && strcmp(syn, current->word) != 0) {
        prev = current;    
        current = current->next;
    }
    
    if (!current) return tr;  

    if (prev != NULL) {
        prev->next = current->next;
        free(current);
        return tr;
    } else {
        target->synonym = current->next;
        free(current);
        return tr;
    }
}

TTree2 *deleteAnt(TTree2 *tr, char* word, char *ant) {
    TTree2 *target = getInfWordTree(tr, word);
    if (!target || !target->antonym) return tr;  
    
    WordNode *current = target->antonym;
    WordNode *prev = NULL;

    while (current && strcmp(ant, current->word) != 0) {
        prev = current;    
        current = current->next;
    }
    
    if (!current) return tr;  
    
    if (prev != NULL) {
        prev->next = current->next;
        free(current);
        return tr;
    } else {
        target->antonym = current->next;
        free(current);
        return tr;
    }
}

void TraversalBSTinOrder(TTree2 *tr) {   
    if (!tr) {
        return;
    }
    
    TraversalBSTinOrder(tr->left);
    printTrNode(tr);
    TraversalBSTinOrder(tr->right);
}

void TraversalBSTpreOrder(TTree2 *tr) {  
    if (!tr) {
        return;
    }
    
    printTrNode(tr);
    TraversalBSTpreOrder(tr->left);
    TraversalBSTpreOrder(tr->right);
}

void TraversalBSTpostOrder(TTree2 *tr) {  
    if (!tr) {
        return;
    }
    
    TraversalBSTpostOrder(tr->left);
    TraversalBSTpostOrder(tr->right);
    printTrNode(tr);
}

TreeQueue *StoreBSTinOrder(TTree2 *tr) {
    TreeQueue *q = createTreeQueue();
    StoreBSTinOrderHelper(tr, &q);
    return q;
}

TreeQueue *StoreBSTpreOrder(TTree2 *tr) {
    TreeQueue *q = createTreeQueue();
    StoreBSTpreOrderHelper(tr, &q);
    return q;
}

TreeQueue *StoreBSTpostOrder(TTree2 *tr) {
    TreeQueue *q = createTreeQueue();
    StoreBSTpostOrderHelper(tr, &q);
    return q;
}

void HighSizeBST(TTree2 *tr) {
    int count = 0;
    SizeBSTHelper(tr, &count);
    printf("The size of the BST is: %d\n ", count);
    printf("The height of the BST is: %d\n ", HighBSTHelper(tr));
}

TTree2 *LowestCommonAncestor(TTree2 *tr, char *word1, char *word2) {
    if (!tr) return NULL;
    int cmp2 = strcmp(tr->word, word2);
    int cmp1 = strcmp(tr->word, word1);
    if (cmp1 < 0 && cmp2 < 0) return LowestCommonAncestor(tr->right, word1, word2);
    if (cmp1 > 0 && cmp2 > 0) return LowestCommonAncestor(tr->left, word1, word2);
    return ((cmp1 >= 0 && cmp2 <= 0) || (cmp1 <= 0 && cmp2 >= 0)) ? tr : NULL;
}

int CountNodesRanges(TTree2 *tr, int l, int h) {
    if (!tr) return 0;
    if ((int)strlen(tr->word) >= l && (int)strlen(tr->word) <= h) 
        return 1 + CountNodesRanges(tr->left, l, h) + CountNodesRanges(tr->right, l, h);
    else
        return CountNodesRanges(tr->left, l, h) + CountNodesRanges(tr->right, l, h);  
}

TTree2 *inOrderSuccesor(TTree2 *tr, char *word) {
    if (!tr) return NULL;  
    
    TreeQueue *q = StoreBSTinOrder(tr);
    if (isTreeQueueEmpty(q)) return NULL; 
    
    TTree2 *target = getInfWordTree(tr, word);
    if (!target) return NULL;  
    
    TTree2 *current = NULL;
    
    while (!isTreeQueueEmpty(q)) {
        current = dequeueTree(q);
        if (current == target) {
            if (!isTreeQueueEmpty(q)) {
                return dequeueTree(q);  
            } else {
                return NULL; 
            }
        }
    }
    
    return NULL;
}

TTree2 *BSTMirror(TTree2 *tr) {
    if (!tr) return NULL;
    TTree2 *temp = tr->left;
    tr->left = BSTMirror(tr->right);
    tr->right = BSTMirror(temp);
    return tr;
}

bool isBalencedBST(TTree2 *tr) {
    if (!tr) return true;
    
    int lh = HighBSTHelper(tr->left);
    int rh = HighBSTHelper(tr->right);
    
    if (abs(lh - rh) <= 1 && isBalencedBST(tr->left) && isBalencedBST(tr->right))
        return true;
    
    return false;
}

TTree2 *BTSMerge(TTree2 *tr1, TTree2 *tr2) {
    if (!tr1) return tr2;
    if (!tr2) return tr1;
    
    TreeQueue *q1 = StoreBSTinOrder(tr1);
    TreeQueue *q2 = StoreBSTinOrder(tr2);
    
    TTree2 *root = NULL;
    
    while (!isTreeQueueEmpty(q1)) {
        TTree2 *node = dequeueTree(q1);
        root = insertBST2(root, node->word, node->synonym, node->antonym);
    }
    
    while (!isTreeQueueEmpty(q2)) {
        TTree2 *node = dequeueTree(q2);
        root = insertBST2(root, node->word, node->synonym, node->antonym);
    }
    
    return root;
}