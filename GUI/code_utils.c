#include "code_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//* Utility functions
void printCentered(char *str, int width) {
    int len = strlen(str);
    if (len > width - 2) len = width - 2;
    int padding = (width - 2 - len) / 2;
    int extra = (width - 2 - len) % 2;
    printf("+");
    for (int i = 0; i < width - 2; i++) printf("-");
    printf("+\n");
    printf("|%*s%s%*s|\n", padding, "", str, padding + extra, "");
    printf("+");
    for (int i = 0; i < width - 2; i++) printf("-");
    printf("+\n");
}

bool includes(char *str, char c, int size) {
    for (int i = 0; i < size; i++) {
        if (str[i] == c) return true;
    }
    return false;
}

int countVowels(char *str) {
    int count = 0;
    int i = 0;
    char vowels[5] = {'a','e','u','i','o'};
    while(str[i] != '\0') {
        if(includes(vowels, tolower(str[i]), 5)) count++;
        i++;
    }
    return count;
}

Node *createNode(char *word, char *relatedWord) {
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->next = NULL;
    newnode->charCount = strlen(word);
    newnode->vowelCount = countVowels(word);
    strcpy(newnode->relatedWord, relatedWord);
    strcpy(newnode->word, word);
    return newnode;
}

void addNodeAtEnd(TList *list, char *word, char *relatedWord) {
    Node *newnode = createNode(word, relatedWord);
    newnode->next = NULL;
    if(list->head == NULL) {
        list->head = newnode;
        return;
    }
    Node *current = list->head;
    while(current->next) current = current->next;
    current->next = newnode;
}

void swapData(Node *node1, Node *node2) {
    Node temp;
    temp.charCount = node1->charCount;
    temp.vowelCount = node1->vowelCount;
    strcpy(temp.word, node1->word);
    strcpy(temp.relatedWord, node1->relatedWord);

    node1->charCount = node2->charCount;
    node1->vowelCount = node2->vowelCount;
    strcpy(node1->word, node2->word);
    strcpy(node1->relatedWord, node2->relatedWord);

    node2->charCount = temp.charCount;
    node2->vowelCount = temp.vowelCount;
    strcpy(node2->word, temp.word);
    strcpy(node2->relatedWord, temp.relatedWord);
}

void printWords(TList *list, int option) {
    Node *current = list->head;
    if(current == NULL) {
        printf("Empty List!\n");
        return;
    }
    int i = 1;
    while(current) {
        printf("%d) %s %s %s (Length = %d, Vowels Count %d)\n", 
               i, current->word, option == 0 ? "=" : "#", 
               current->relatedWord, current->charCount, current->vowelCount);
        i++;
        current = current->next;
    }
}

int matchRate(char *word1, char *word2) { 
    int len2 = strlen(word2);
    int common = 0;
    for (int i = 0; i < len2; i++) {
        if (word1[i] == word2[i]) common++;
        else break;
    }
    if (common == len2) return 100;
    return (common * 100) / len2;
}

bool isPalindrome(char *s, int l, int r) { 
    return (l >= r) ? 1 : (s[l] == s[r] && isPalindrome(s, l+1, r-1)); 
}

void printWords2(TList2 *list) {
    DNode *current = list->head;
    if(current == NULL) {
        printf("Empty List!\n");
        return;
    }
    int i = 1;
    while(current) {
        printf("%d) %s = %s # %s(Length = %d, Vowels Count %d)\n", 
               i, current->word, current->synonym, current->antonym, 
               current->charCount, current->vowelCount);
        i++;
        current = current->next;
    }
}

void printWords3(TList3 *list) {
    if (list->head == NULL) {
        printf("Empty List!\n");
        return;
    } 
    CNode *current = list->head;
    int i = 1;
    do {
        printf("%d) %s = %s # %s (Length = %d, Vowels Count %d)\n", 
               i, current->word, current->synonym, current->antonym, 
               current->charCount, current->vowelCount);
        current = current->next;
        i++;
    } while (current != list->head);
}

int is_vowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y');
}

int count_syllables(const char *word) {
    int count = 0;
    int prev_char_was_vowel = 0;
    int length = strlen(word);
    for (int i = 0; i < length; i++) {
        char c = tolower(word[i]);

        if (is_vowel(c)) {
            if(!prev_char_was_vowel) {
                count++;
                prev_char_was_vowel = 1;
            }
        } else {
            prev_char_was_vowel = 0;
        }
    }
    if(tolower(word[length - 1]) == 'e' && count > 1) count--;
    if(count == 0) count = 1;
    return count;
}

//* Queue operations
TQueue *createQueue() {
    TQueue *queue = (TQueue *)malloc(sizeof(TQueue));
    queue->front = queue->rear = NULL;
    return queue;
}

void enqueue(TQueue *queue, char *word) {
    QNode *newnode = (QNode *)malloc(sizeof(QNode));
    strcpy(newnode->word, word);
    newnode->next = NULL;
    if(queue->front == NULL) {
        queue->front = queue->rear = newnode;
        return;
    }
    queue->rear->next = newnode;
    queue->rear = newnode;
}

void printQueueWords(TQueue *queue) {
    QNode *current = queue->front;
    while(current) {
        printf("%s\n", current->word);
        current = current->next;
    }
}

// Stack operations
TStack *createStack() {
    TStack *stack = (TStack *)malloc(sizeof(TStack));
    stack->head = NULL;
    return stack;
}

void printStack(TStack *stk) {
    CNode *current = stk->head;
    int i = 1;
    while(current) {
        printf("%d) %s = %s # %s(Length = %d, Vowels Count %d)\n", 
               i++, current->word, current->synonym, current->antonym, 
               current->charCount, current->vowelCount);
        current = current->next;
    }
}

bool isStackEmpty(TStack *stk) {
    return stk->head == NULL;
}

void pushToStack(TStack *stk, CNode *nod) {
    if(stk->head == NULL) {
        stk->head = nod;
        stk->head->next = NULL;
        return;
    }
    nod->next = stk->head;
    stk->head = nod;
}

CNode *peakStack(TStack *stk) {
    return stk->head;
}

CNode *popFromStack(TStack *stk) {
    if(stk->head == NULL) return NULL;
    CNode *temp = stk->head;
    stk->head = stk->head->next;
    temp->next = NULL;
    return temp;
}

CNode *searchNodeInStack(TStack *stk, char *word) {
    if(stk->head == NULL) return NULL;
    if(strcmp(stk->head->word, word) == 0) return stk->head;
    CNode *temp = popFromStack(stk);
    CNode *result = searchNodeInStack(stk, word);
    pushToStack(stk, temp);
    return result;
}

void insertSorted(TStack *stk, CNode *newnode) {
    if(isStackEmpty(stk) || strcmp(newnode->word, peakStack(stk)->word) < 0) {
        pushToStack(stk, newnode);
        return;
    }
    CNode *temp = popFromStack(stk);
    insertSorted(stk, newnode);
    pushToStack(stk, temp);
}

// Simple stack operations
bool isSimpleStackEmpty(TStack2 *stk) {
    return stk->head == NULL;
}

void push(TStack2 *stk, char c) {
    TNode *newnode = (TNode *)malloc(sizeof(TNode));
    newnode->c = c;
    newnode->next = stk->head;
    stk->head = newnode;
}

char pop(TStack2 *stk) {
    char c = -1;
    if(!isSimpleStackEmpty(stk)) {
        TNode *temp = stk->head;
        stk->head = stk->head->next;
        c = temp->c;
        free(temp);
    }
    return c;
}

// Vowel type functions
VowelType getVowelType(const char *word) {
    const char *diphthongs[] = {"ai", "au", "ei", "oi", "ou", "ow", "oy"};
    for(int i = 0; i < sizeof(diphthongs)/sizeof(diphthongs[0]); i++)
        if (strstr(word, diphthongs[i])) return VOWEL_DIPHTHONG;
    int len = strlen(word);
    if(len >= 2 && word[len-1] == 'e') return VOWEL_LONG;
    return VOWEL_SHORT;
}
