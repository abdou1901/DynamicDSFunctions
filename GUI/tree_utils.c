#include "tree_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// WordNode operations
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

int countWordNodes(WordNode *head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

// Tree node operations
TTree2 *createTreeNode2(const char *word, WordNode *synonyms, WordNode *antonyms) {
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

TTree2 *insertBST2(TTree2 *root, const char *word, WordNode *synonyms, WordNode *antonyms) {
    if (root == NULL) return createTreeNode2(word, synonyms, antonyms);

    int cmp = strcmp(word, root->word);
    if (cmp < 0)
        root->left = insertBST2(root->left, word, synonyms, antonyms);
    else if (cmp > 0)
        root->right = insertBST2(root->right, word, synonyms, antonyms);
    // If word already exists, we don't modify it

    return root;
}

TTree2 *findMinNode2(TTree2 *node) {
    while (node && node->left != NULL)
        node = node->left;
    return node;
}

// Stack operations for trees
TStack2Tree *createStack2() {
    TStack2Tree *stack = (TStack2Tree*)malloc(sizeof(TStack2Tree));
    stack->top = NULL;
    return stack;
}

void push2(TStack2Tree *stack, TTree2 *node) {
    TStackNode2 *newNode = (TStackNode2*)malloc(sizeof(TStackNode2));
    newNode->treeNode = node;
    newNode->next = stack->top;
    stack->top = newNode;
}

TTree2 *pop2(TStack2Tree *stack) {  
    if (stack->top == NULL) return NULL;
    TStackNode2 *temp = stack->top;
    TTree2 *node = temp->treeNode;
    stack->top = temp->next;
    free(temp);
    return node;
}

bool isStack2Empty(TStack2Tree *stack) {
    return (stack->top == NULL);
}

// Queue operations for trees - RENAMED to avoid conflicts
TQueue *tree_createQueue() {
    TQueue *q = (TQueue*)malloc(sizeof(TQueue));
    q->front = NULL; 
    q->rear = NULL;
    return q;
}

void tree_enqueue(TQueue *q, TTree2 *node) {
    QNode *newnode = (QNode*)malloc(sizeof(QNode));
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

TTree2 *dequeue(TQueue *q) {
    if (q->front == NULL) return NULL; 
    
    QNode *temp = q->front;
    TTree2 *node = temp->treeNode;
    q->front = q->front->next;
    
    if (q->front == NULL) {
        q->rear = NULL;
    }
    
    free(temp);
    return node;
}

bool isEmptyQueue(TQueue *q) {
    return q->front == NULL;
}

int helper(QNode *q) {
    if (q == NULL) return 0;
    return 1 + helper(q->next);  
}

int lenQueue(TQueue *q) {
    if (q == NULL || q->front == NULL) return 0;  
    return helper(q->front);
}

// Helper functions
void StoreBSTinOrderHelper(TTree2 *tr, TQueue **q) {
    if (tr != NULL) { 
        StoreBSTinOrderHelper(tr->left, q);
        tree_enqueue(*q, tr);
        StoreBSTinOrderHelper(tr->right, q);
    }
}

void StoreBSTpreOrderHelper(TTree2 *tr, TQueue **q) {
    if (tr != NULL) { 
        tree_enqueue(*q, tr);
        StoreBSTpreOrderHelper(tr->left, q);
        StoreBSTpreOrderHelper(tr->right, q);
    }
}

void StoreBSTpostOrderHelper(TTree2 *tr, TQueue **q) {
    if (tr != NULL) { 
        StoreBSTpostOrderHelper(tr->left, q);
        StoreBSTpostOrderHelper(tr->right, q);
        tree_enqueue(*q, tr);
    }
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

// Tree operations
TTree2 *toTree(TStack2Tree *stk) {
    if (isStack2Empty(stk)) return NULL;

    TTree2 *root = pop2(stk);

    while (!isStack2Empty(stk)) {
        TTree2 *nextN = pop2(stk);
        root = insertBST2(root, nextN->word, nextN->synonym, nextN->antonym);
    }
    
    return root;
}

// RENAMED to avoid conflicts
int tree_countVowels(char *word) {
    int count = 0;
    for (int i = 0; i < strlen(word); i++) {
        char c = tolower(word[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')  count++;
    }
    return count;
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
            printf("\033[0;34mLine %d does not contain '#' delimiter: %s\033[0m\n", lineCount, line);
            
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
            continue;
        }
        
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
    
    printf("Done\n");
    fclose(f);
    if (!root) {
        printf(" \033[0;31mTree is empty. Can't work with that file! \033[0m\n");
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
    
    printf("Word : %s\n", word);
    printf("Word length : %d\n", (int)strlen(word));
    printf("Number Of Vowels : %d\n", tree_countVowels(word));
    printf("Synonym(s) of %s : ", word);
    printWordNodeList(target->synonym);
    printf("Antonym(s) of %s : ", word);
    printWordNodeList(target->antonym);
}

void AddWordBST(TTree2 *tr, char *word, WordNode *synonyms, WordNode *antonyms, TStack2Tree **stk) {
    if (!(*stk)) *stk = createStack2();  
    
    if (!tr) {
        tr = createTreeNode2(word, synonyms, antonyms);
        push2(*stk, tr);
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
        // Two children below the root father
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
    
    printf("\033[0;32mWord : %s \033[0m\n", tr->word);
    printf("\033[0;36mSynonym(s) of %s \033[0m: ", tr->word);
    printWordNodeList(tr->synonym);
    printf("\033[0;35mAntonym(s) of %s : \033[0m", tr->word);
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

TQueue *StoreBSTinOrder(TTree2 *tr) {
    TQueue *q = tree_createQueue();
    StoreBSTinOrderHelper(tr, &q);
    return q;
}

TQueue *StoreBSTpreOrder(TTree2 *tr) {
    TQueue *q = tree_createQueue();
    StoreBSTpreOrderHelper(tr, &q);
    return q;
}

TQueue *StoreBSTpostOrder(TTree2 *tr) {
    TQueue *q = tree_createQueue();
    StoreBSTpostOrderHelper(tr, &q);
    return q;
}

void HighSizeBST(TTree2 *tr) {
    int count = 0;
    SizeBSTHelper(tr, &count);
    printf("The size of the BST is : %d\n", count);
    printf("The height of the BST is : %d\n", HighBSTHelper(tr));
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
    
    TQueue *q = StoreBSTinOrder(tr);
    if (isEmptyQueue(q)) return NULL; 
    
    TTree2 *target = getInfWordTree(tr, word);
    if (!target) return NULL;  
    
    TTree2 *current = NULL;
    
    while (!isEmptyQueue(q)) {
        current = dequeue(q);
        if (current == target) {
            if (!isEmptyQueue(q)) {
                return dequeue(q);  
            } else {
                return NULL; 
            }
        }
    }
    
    return NULL;
}

TTree2 *BSTMirror(TTree2 *tr) {
    if (!tr) return NULL;
    TTree2 *temp;
    temp = tr->left;
    tr->left = tr->right;
    tr->right = temp;
    BSTMirror(tr->left);
    BSTMirror(tr->right);
    return tr;
}

int isBalencedBST(TTree2 *tr) {
    if (!tr) return 1;  
    
    int lh = HighBSTHelper(tr->left);
    int rh = HighBSTHelper(tr->right);
    int checked = (abs(lh-rh) <= 1);
    
    return checked && isBalencedBST(tr->left) && isBalencedBST(tr->right);
}
