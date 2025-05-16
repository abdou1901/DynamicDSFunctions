#include "code.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

// Utility functions
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
        if(includes(vowels, str[i], 5)) count++;
        i++;
    }
    return count;
}

// Node operations
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

void SwapData(Node *node1, Node *node2) {
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

// Display functions
void printWords(TList *list, int option) {
    Node *current = list->head;
    if(current == NULL) {
        printf("Empty List!\n");
        return;
    }
    int i = 1;
    while(current) {
        printf("%d) %s %s %s (Length = %d, Vowels Count %d)\n", i, current->word, 
               option == 0 ? "=" : "#", current->relatedWord, current->charCount, current->vowelCount);
        i++;
        current = current->next;
    }
}

void printWords2(TList2 *list) {
    DNode *current = list->head;
    if(current == NULL) {
        printf("Empty List!\n");
        return;
    }
    int i = 1;
    while(current) {
        printf("%d) %s = %s # %s(Length = %d, Vowels Count %d)\n", i, current->word, 
               current->synonym, current->antonym, current->charCount, current->vowelCount);
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
        printf("%d) %s = %s # %s (Length = %d, Vowels Count %d)\n", i, current->word, 
               current->synonym, current->antonym, current->charCount, current->vowelCount);
        current = current->next;
        i++;
    } while (current != list->head);
}

// Word analysis functions
int matchRate(char *word1, char *word2) {
    int len1 = strlen(word1);
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

// Queue operations
WordQueue *createWordQueue() {
    WordQueue *queue = (WordQueue *)malloc(sizeof(WordQueue));
    queue->head = queue->tail = NULL;
    return queue;
}

void enqueueWord(WordQueue *queue, char *word) {
    WordQNode *newnode = (WordQNode *)malloc(sizeof(WordQNode));
    strcpy(newnode->word, word);
    newnode->next = NULL;
    if(queue->head == NULL) {
        queue->head = queue->tail = newnode;
        return;
    }
    queue->tail->next = newnode;
    queue->tail = newnode;
}

void printQueueWords(WordQueue *queue) {
    WordQNode *current = queue->head;
    while(current) {
        printf("%s\n", current->word);
        current = current->next;
    }
}

// Stack operations
CNodeStack *createCNodeStack() {
    CNodeStack *stack = (CNodeStack *)malloc(sizeof(CNodeStack));
    stack->head = NULL;
    return stack;
}

void printStack(CNodeStack *stk) {
    CNode *current = stk->head;
    int i = 1;
    while(current) {
        printf("%d) %s = %s # %s(Length = %d, Vowels Count %d)\n", i++, current->word, 
               current->synonym, current->antonym, current->charCount, current->vowelCount);
        current = current->next;
    }
}

bool isCNodeStackEmpty(CNodeStack *stk) {
    return stk->head == NULL;
}

void pushToCNodeStack(CNodeStack *stk, CNode *nod) {
    if(stk->head == NULL) {
        stk->head = nod;
        stk->head->next = NULL;
        return;
    }
    nod->next = stk->head;
    stk->head = nod;
}

CNode *peakStack(CNodeStack *stk) {
    return stk->head;
}

CNode *popFromCNodeStack(CNodeStack *stk) {
    if(stk->head == NULL) return NULL;
    CNode *temp = stk->head;
    stk->head = stk->head->next;
    temp->next = NULL;
    return temp;
}

CNode *searchNodeInStack(CNodeStack *stk, char *word) {
    if(stk->head == NULL) return NULL;
    if(strcmp(stk->head->word, word) == 0) return stk->head;
    CNode *temp = popFromCNodeStack(stk);
    CNode *result = searchNodeInStack(stk, word);
    pushToCNodeStack(stk, temp);
    return result;
}

void insertSorted(CNodeStack *stk, CNode *newnode) {
    if(isCNodeStackEmpty(stk) || strcmp(newnode->word, peakStack(stk)->word) < 0) {
        pushToCNodeStack(stk, newnode);
        return;
    }
    CNode *temp = popFromCNodeStack(stk);
    insertSorted(stk, newnode);
    pushToCNodeStack(stk, temp);
}

// Character stack operations for palindrome checking
bool isCharStackEmpty(CharStack *stk) {
    return stk->head == NULL;
}

void pushChar(CharStack *stk, char c) {
    TNode *newNode = (TNode *)malloc(sizeof(TNode));
    newNode->c = c;
    newNode->next = stk->head;
    stk->head = newNode;
}

char popChar(CharStack *stk) {
    if (isCharStackEmpty(stk)) return '\0';
    TNode *temp = stk->head;
    char c = temp->c;
    stk->head = temp->next;
    free(temp);
    return c;
}

bool isPalyndromeStack(char *word) {
    int len = strlen(word);
    CharStack *stk = (CharStack *)malloc(sizeof(CharStack));
    stk->head = NULL;
    
    // Push first half of characters onto stack
    for (int i = 0; i < len/2; i++) {
        pushChar(stk, word[i]);
    }
    
    // Compare second half with stack (skip middle char if odd length)
    int start = (len % 2 == 0) ? len/2 : len/2 + 1;
    for (int i = start; i < len; i++) {
        if (popChar(stk) != word[i]) {
            free(stk);
            return false;
        }
    }
    
    free(stk);
    return true;
}

// File operations
TList *getSynWords(FILE *f) {
    TList *list = (TList *)malloc(sizeof(TList));
    list->head = NULL;
    char buffer[170];
    char word[50];
    char syn[50];
    
    rewind(f);
    while(fgets(buffer, sizeof(buffer), f) != NULL) {
        if (sscanf(buffer, "%49[^=] = %49[^#]", word, syn) == 2) {
            // Trim trailing whitespace in syn
            int synLen = strlen(syn);
            while (synLen > 0 && isspace(syn[synLen-1])) {
                syn[synLen-1] = '\0';
                synLen--;
            }
            addNodeAtEnd(list, word, syn);
        }
    }
    
    return list;
}

TList *getAntoWords(FILE *f) {
    TList *list = (TList *)malloc(sizeof(TList));
    list->head = NULL;
    char buffer[175];
    char word[50];
    char antonym[50];
    
    rewind(f);
    while(fgets(buffer, sizeof(buffer), f)) {
        if(sscanf(buffer, " %49[^=]=%*[^#]#%49[^\n]", word, antonym) == 2) {
            addNodeAtEnd(list, word, antonym);
        }
    }
    
    return list;
}

void getInfWord(TList *syn, TList *ant, char *word) {
    Node *current = syn->head;
    printCentered(word, 28);
    bool found = false;
    while(current) {
        if(strcmp(current->word, word) == 0) {
            found = true;
            printf("Char Count = %d\nVowels Count = %d\nSynonym = %s\n", 
                   current->charCount, current->vowelCount, current->relatedWord);
            break;
        }
        current = current->next;
    }
    if(current == NULL) {
        printf("Word not found in synonyms dictionary!\n");
    }
    
    current = ant->head;
    while(current) {
        if(strcmp(current->word, word) == 0) {
            if(found) printf("Antonym = %s\n", current->relatedWord);
            else printf("Antonym = %s\nChar Count = %d\nVowels Count = %d\n", 
                        current->relatedWord, current->charCount, current->vowelCount);
            break;
        }
        current = current->next;
    }
    if(current == NULL) {
        printf("Word Not found in antonyms dictionary!\n");
    }
    printf("----------------------------\n");
}

void getInfWord2(TList *syn, TList *ant, char *inf) {
    bool found = false;
    Node *current = syn->head;
    printCentered(inf, 28);
    while(current) {
        if(strcmp(current->relatedWord, inf) == 0) {
            printf("Is a synonym for: %s\nChars Count = %d\nVowels Count = %d\n", 
                   current->word, current->charCount, current->vowelCount);
            found = true;
            break;
        }
        current = current->next;
    }
    if(!found) {
        current = ant->head;
        while(current) {
            if(strcmp(current->relatedWord, inf) == 0) {
                printf("Is an antonym for: %s\nChars Count = %d\nVowels Count = %d\n", 
                       current->word, current->charCount, current->vowelCount);
                found = true;
                break;
            }
            current = current->next;
        }
        if(!found) {
            printf("Word Not found neither in synonym nor antonym list.\n");
        }
    }
    printf("----------------------------\n");
}

// Sorting operations
TList *sortWord(TList *syn) {
    if(syn->head == NULL || (syn->head)->next == NULL) return syn;
    Node *current = syn->head;
    while(current->next) {
        Node *temp = current;
        Node *minnode = current;
        while(temp) {
            if(strcmp(temp->word, minnode->word) < 0) {
                minnode = temp;
            }
            temp = temp->next;
        }
        if(minnode != current) SwapData(minnode, current);
        current = current->next;
    }
    return syn;
}

TList *sortWord2(TList *syn) {
    if(syn->head == NULL || (syn->head)->next == NULL) return syn;
    Node *current = syn->head;
    while(current->next) {
        Node *temp = current;
        Node *minnode = current;
        while(temp) {
            if(temp->charCount < minnode->charCount) {
                minnode = temp;
            }
            temp = temp->next;
        }
        if(minnode != current) SwapData(minnode, current);
        current = current->next;
    }
    return syn;
}

TList *sortWord3(TList *syn) {
    if(syn->head == NULL || (syn->head)->next == NULL) return syn;
    Node *current = syn->head;
    while(current->next) {
        Node *temp = current;
        Node *minnode = current;
        while(temp) {
            if(temp->vowelCount < minnode->vowelCount) {
                minnode = temp;
            }
            temp = temp->next;
        }
        if(minnode != current) SwapData(minnode, current);
        current = current->next;
    }
    return syn;
}

enum VowelType getVowelType(const char *word) {
    const char *diphthongs[] = {"ai", "au", "ei", "oi", "ou", "ow", "oy"};
    for(int i = 0; i < sizeof(diphthongs)/sizeof(diphthongs[0]); i++) {
        if (strstr(word, diphthongs[i])) return DIPHTHONG;
    }
    int len = strlen(word);
    if(len >= 2 && word[len-1] == 'e') return LONG;
    return SHORT;
}