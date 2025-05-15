#ifndef QUEUE_H
#define QUEUE_H

#include "common/common.h"
#include "➡️ SinglyLinkedList/🔸PART II/LinkedLists.h"
#include "../../🗂️ Stacks/🔸PART II/Stacks.h"
// Structure for Queue nodes
typedef struct QNode {
    char word[WORD_MAX_LENGTH];
    struct QNode *next;
} QNode;

// Structure for Queue
typedef struct TQueue {
    QNode *head;
    QNode *tail;
} TQueue;

// Queue operations
TQueue *createQueue();
void enqueue(TQueue *queue, char *word);
void printQueueWords(TQueue *queue);
void insertsortedtoqueue(TQueue *queue, struct TStack *stk);

// Queue-based operations
TQueue *syllable(TList *syn);
TQueue **prounounciation(TList *syn);
TQueue *toQueue(TList2 *merged);
TQueue *stackToQueue(struct TStack *stk);

#endif // QUEUE_H