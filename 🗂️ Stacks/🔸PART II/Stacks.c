#include "Stacks.h"

// Basic stack operations
TStack *createStack() {
    TStack *stack = (TStack *)malloc(sizeof(TStack));
    stack->head = NULL;
    return stack;
}

bool isStackEmpty(TStack *stk) {
    return stk->head == NULL;
}

void pushToStack(TStack *stk, cnode *nod) {
    if(stk->head == NULL) {
        stk->head = nod;
        stk->head->next = NULL;
        return;
    }
    nod->next = stk->head;
    stk->head = nod;
}

cnode *peakStack(TStack *stk) {
    return stk->head;
}

cnode *popFromStack(TStack *stk) {
    if(stk->head == NULL) return NULL;
    cnode *temp = stk->head;
    stk->head = stk->head->next;
    temp->next = NULL;
    return temp;
}

void printStack(TStack *stk) {
    cnode *current = stk->head;
    int i = 1;
    while(current) {
        printf("%d) %s = %s # %s(Length = %d, Vowels Count %d)\n", 
               i++, current->word, current->synonym, current->antonym, 
               current->charCount, current->vowelCount);
        current = current->next;
    }
}

int lengthStack(TStack *stk) {
    if (isStackEmpty(stk)) return 0;
    cnode *temp = popFromStack(stk);
    int count = 1 + lengthStack(stk);
    pushToStack(stk, temp);
    return count;
}

// Stack utility functions
cnode *searchNodeInStack(TStack *stk, char *word) {
    if(stk->head == NULL) return NULL;
    if(strcmp(stk->head->word, word) == 0) return stk->head;
    cnode *temp = popFromStack(stk);
    cnode *result = searchNodeInStack(stk, word);
    pushToStack(stk, temp);
    return result;
}

void insertSorted(TStack *stk, cnode *newnode) {
    if(isStackEmpty(stk) || strcmp(newnode->word, peakStack(stk)->word) < 0) {
        pushToStack(stk, newnode);
        return;
    }
    cnode *temp = popFromStack(stk);
    insertSorted(stk, newnode);
    pushToStack(stk, temp);
}

void addNodesToArray(cnode **arr, int index, TStack *stk) {
    if(isStackEmpty(stk)) return;
    cnode *temp = popFromStack(stk);
    arr[index] = temp;
    addNodesToArray(arr, index+1, stk);
    pushToStack(stk, temp);
}

cnode *copyNode(cnode *src) {
    cnode *newNode = (cnode *)malloc(sizeof(cnode));
    newNode->charCount = src->charCount;
    newNode->vowelCount = src->vowelCount;
    strcpy(newNode->word, src->word);
    strcpy(newNode->antonym, src->antonym);
    strcpy(newNode->synonym, src->synonym);
    return newNode;
}

// Operations with stacks
TStack *toStack(TList2 *merged) {
    TStack *stk = (TStack *)malloc(sizeof(TStack));
    stk->head = NULL;
    if(merged->head == NULL) return stk;
    dnode *current = merged->head;
    while(current) {
        cnode *newnode = (cnode *)malloc(sizeof(cnode));
        newnode->charCount = current->charCount;
        newnode->vowelCount = current->vowelCount;
        strcpy(newnode->word, current->word);
        strcpy(newnode->antonym, current->antonym);
        strcpy(newnode->synonym, current->synonym);
        newnode->next = NULL;
        pushToStack(stk, newnode);
        current = current->next;
    }
    return stk;
}

TStack *getInfWordStack(TStack *stk, char *word) {
    cnode *nod = searchNodeInStack(stk, word);
    if(nod) printf("%s = %s # %s(Length = %d, Vowels Count %d)\n",
                  nod->word, nod->synonym, nod->antonym, 
                  nod->charCount, nod->vowelCount);
    return stk;
}

TStack *sortWordStack(TStack *stk) {
    if(!isStackEmpty(stk)) {
        cnode *temp = popFromStack(stk);
        sortWordStack(stk);
        insertSorted(stk, temp);
    }
    return stk;
}

TStack *deleteWordStack(TStack *stk, char *word) {
    if(isStackEmpty(stk)) return stk;
    if(strcmp(word, peakStack(stk)->word) == 0) {
        cnode *temp = popFromStack(stk);
        free(temp);
        temp = NULL;
        // If we want to delete all occurrences, continue recursion
        deleteWordStack(stk, word);
    } else {
        cnode *temp2 = popFromStack(stk);
        deleteWordStack(stk, word);
        pushToStack(stk, temp2);
    }
    return stk;
}

TStack *updateWordStack(TStack *stk, char *word, char *syne, char *anton) {
    if(isStackEmpty(stk)) return stk;
    if(strcmp(peakStack(stk)->word, word) == 0) {
        cnode *temp = peakStack(stk);
        strcpy(temp->antonym, anton);
        strcpy(temp->synonym, syne);
    }
    cnode *temp = popFromStack(stk);
    updateWordStack(stk, word, syne, anton);
    pushToStack(stk, temp);
    return stk;
}

TStack *addWordStack(TStack *stk, char *word, char *syne, char *anton) {
    cnode *newnode = (cnode *)malloc(sizeof(cnode));
    strcpy(newnode->word, word);
    strcpy(newnode->antonym, anton);
    strcpy(newnode->synonym, syne);
    newnode->charCount = strlen(word);
    newnode->vowelCount = countVowels(word);
    insertSorted(stk, newnode);
    return stk;
}

int compareNodes2(const void *a, const void *b) {
    cnode *nodeA = *(cnode **)a;
    cnode *nodeB = *(cnode **)b;
    int countA = count_syllables(nodeA->word);
    int countB = count_syllables(nodeB->word);
    if(countA != countB) {
        return countA - countB;
    }
    return strcmp(nodeA->word, nodeB->word);
}

TStack *syllableStack(TStack *stk) {
    // Count the length
    int length = lengthStack(stk);

    // Put the nodes' pointers into an array
    cnode **arr = (cnode **)malloc(length * sizeof(cnode *));
    addNodesToArray(arr, 0, stk);

    // Sort the array using quick sort (from stdlib library)
    qsort(arr, length, sizeof(cnode *), compareNodes2);

    // Create the stack and add the nodes
    TStack *newStack = (TStack *)malloc(sizeof(TStack));
    newStack->head = NULL;
    for(int i = 0; i < length; i++) {
        cnode *nodeCopy = copyNode(arr[i]);
        pushToStack(newStack, nodeCopy);
    }
    
    free(arr);
    return newStack;
}

void InsertToPronunciationStacks(TStack *stk, TStack **stacks) {
    if(isStackEmpty(stk)) return;
    cnode *temp1 = popFromStack(stk);
    cnode *temp = copyNode(temp1);
    pushToStack(stacks[getVowelType(temp->word)], temp);
    InsertToPronunciationStacks(stk, stacks);
    pushToStack(stk, temp1); 
}

TStack **pronunciationStack(TStack *stk) {
    TStack **stacks = (TStack **)malloc(3 * sizeof(TStack *));
    stacks[SHORT] = createStack();
    stacks[LONG] = createStack();
    stacks[DIPHTHONG] = createStack();
    InsertToPronunciationStacks(stk, stacks);
    return stacks;
}

void smallestword(TStack *stk, cnode **minnode) {
    if(isStackEmpty(stk)) return;
    cnode *temp = popFromStack(stk);
    if(*minnode == NULL || temp->charCount < (*minnode)->charCount) *minnode = temp;
    smallestword(stk, minnode);
    pushToStack(stk, temp);
}

char *getSmallest(TStack *stk) {
    if (isStackEmpty(stk)) {
        return NULL;
    }
    cnode *minnode = NULL;
    smallestword(stk, &minnode);

    return minnode ? minnode->word : NULL;
}

TList2 *StacktoList(TStack *stk) {
    TList2 *list = (TList2 *)malloc(sizeof(TList2));
    list->head = list->tail = NULL;
    sortWordStack(stk);
    insertSortedToList(list, stk);
    return list;
}

void insertSortedToList(TList2 *list, TStack *stk) {
    if(isStackEmpty(stk)) return;
    cnode *temp = popFromStack(stk);
    insertSortedToList(list, stk);
    dnode *newnode = (dnode *)malloc(sizeof(dnode));
    newnode->next = list->head;
    newnode->prev = NULL;
    newnode->charCount = temp->charCount;
    newnode->vowelCount = temp->vowelCount;
    strcpy(newnode->word, temp->word);
    strcpy(newnode->antonym, temp->antonym);
    strcpy(newnode->synonym, temp->synonym);
    if(list->head == NULL) list->head = list->tail = newnode;
    else {
        list->head->prev = newnode;
        list->head = newnode;
    }
    pushToStack(stk, temp);
}

TStack *StackRev(TStack *stk) {
    if(isStackEmpty(stk)) return stk;
    cnode *temp = popFromStack(stk);
    stk = StackRev(stk);
    pushToStack(stk, temp);
    return stk;
}

// Simple character stack operations
bool isSimpleStackEmpty(Tstack2 *stk) {
    return stk->head == NULL;
}

void push(Tstack2 *stk, char c) {
    Tnode *newnode = (Tnode *)malloc(sizeof(Tnode));
    newnode->c = c;
    newnode->next = stk->head;
    stk->head = newnode;
}

char pop(Tstack2 *stk) {
    char c = -1;
    if(!isSimpleStackEmpty(stk)) {
        Tnode *temp = stk->head;
        stk->head = stk->head->next;
        c = temp->c;
        free(temp);
    }
    return c;
}

void insertWordInverse(char *word, int index, Tstack2 *stk) {
    if(index == strlen(word)) return;
    push(stk, word[index]);
    insertWordInverse(word, index+1, stk);
}

bool isPalindromeStack(char *word) {
    Tstack2 *stk = (Tstack2 *)malloc(sizeof(Tstack2));
    stk->head = NULL;
    insertWordInverse(word, 0, stk);
    int i = 0;
    while(!isSimpleStackEmpty(stk)) {
        if(pop(stk) != word[i]) {
            while(!isSimpleStackEmpty(stk)) {
                pop(stk);
            }
            free(stk);
            return false;
        }
        i++;
    }
    free(stk);
    return true;
}