#ifndef UNIFIED_DATA_STRUCTURES_H
#define UNIFIED_DATA_STRUCTURES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>

#define WORD_MAX_LENGTH 50

// Common enums - renamed to avoid conflicts with Windows types
typedef enum {
    VOWEL_SHORT, VOWEL_LONG, VOWEL_DIPHTHONG, VOWEL_UNKNOWN
} VowelType;

// Basic node structures for linked lists
typedef struct Node {
    char word[WORD_MAX_LENGTH];
    char relatedWord[WORD_MAX_LENGTH]; // synonym or antonym
    int charCount;
    int vowelCount;
    struct Node *next;
} Node;

// Structure for bidirectional linked list
typedef struct DNode {
    char word[WORD_MAX_LENGTH];
    char synonym[WORD_MAX_LENGTH];
    char antonym[WORD_MAX_LENGTH];
    int charCount;
    int vowelCount;
    struct DNode *prev, *next;
} DNode;

// Structure for circular linked list (also used in stack)
typedef struct CNode {
    char word[WORD_MAX_LENGTH];
    char synonym[WORD_MAX_LENGTH];
    char antonym[WORD_MAX_LENGTH];
    int charCount;
    int vowelCount;
    struct CNode *next;
} CNode;

// Structure for a simple stack node to check if a word is palindrome
typedef struct TNode {
    char c;
    struct TNode *next;
} TNode;

// Structure for singly linked list
typedef struct {
    Node *head;
} TList;

// Structure for bidirectional linked list
typedef struct {
    DNode *head;
    DNode *tail;
} TList2;

// Structure for circular linked list
typedef struct {
    CNode *head;
    CNode *tail;
} TList3;

// Forward declaration for TTree2
struct TTree2;

// Structure for queue node
typedef struct QNode {
    union {
        char word[WORD_MAX_LENGTH];
        struct TTree2 *treeNode;
    };
    struct QNode *next;
} QNode;

// Structure for queue
typedef struct {
    QNode *front;
    QNode *rear;
} TQueue;

// Structure for stack using circular nodes
typedef struct {
    CNode *head;
} TStack;

// Structure for simple character stack
typedef struct {
    TNode *head;
} TStack2;

// Tree structures
typedef struct WordNode {
    char word[WORD_MAX_LENGTH];
    struct WordNode *next;
} WordNode;

typedef struct TTree2 {
    char word[WORD_MAX_LENGTH];
    WordNode *synonym;
    WordNode *antonym;
    struct TTree2 *left;
    struct TTree2 *right;
} TTree2;

typedef struct TStackNode2 {
    TTree2 *treeNode;
    struct TStackNode2 *next;
} TStackNode2;

typedef struct {
    TStackNode2 *top;
} TStack2Tree;

#endif // UNIFIED_DATA_STRUCTURES_H
