#include "Queues.h"
#include "common.h"

TQueue *createQueue() {
    TQueue *queue = (TQueue *)malloc(sizeof(TQueue));
    queue->head = queue->tail = NULL;
    return queue;
}

void enqueue(TQueue *queue, char *word) {
    QNode *newnode = (QNode *)malloc(sizeof(QNode));
    strcpy(newnode->word, word);
    newnode->next = NULL;
    if(queue->head == NULL) {
        queue->head = queue->tail = newnode;
        return;
    }
    queue->tail->next = newnode;
    queue->tail = newnode;
}

void printQueueWords(TQueue *queue) {
    QNode *current = queue->head;
    while(current) {
        printf("%s\n", current->word);
        current = current->next;
    }
}

TQueue *toQueue(TList2 *merged) {
    TQueue *q = createQueue();
    if(merged->head == NULL) return q;
    dnode *current = merged->head;
    while(current) {
        enqueue(q, current->word);
        current = current->next;
    }
    return q;
}

TQueue *syllable(TList *syn) {
    // Count the number of words in syn list
    int length = 0;
    node *tempLength = syn->head;
    while(tempLength) {
        length++;
        tempLength = tempLength->next;
    }
    
    // Array of Node pointers
    node **arr = (node **)malloc(length * sizeof(node *));
    tempLength = syn->head;
    for(int i = 0; i < length; i++) {
        arr[i] = tempLength;
        tempLength = tempLength->next;
    }

    // Sort the array based on syllables count (using quick sort from stdlib library)
    qsort(arr, length, sizeof(node *), compareNodes);

    // Create the queue and add entries
    TQueue *queue = createQueue();
    for(int i = 0; i < length; i++) {
        enqueue(queue, arr[i]->word);
    }
    free(arr);
    return queue;
}

TQueue **pronunciation(TList *syn) {
    TQueue **queues = (TQueue **)malloc(3 * sizeof(TQueue *));
    queues[SHORT] = createQueue();
    queues[LONG] = createQueue();
    queues[DIPHTHONG] = createQueue();
    node *current = syn->head;
    while(current) {
        enqueue(queues[getVowelType(current->word)], current->word);
        current = current->next;
    }
    return queues;
}

// Function from the original code needed for syllable sorting
int compareNodes(const void *a, const void *b) {
    node *nodeA = *(node **)a;
    node *nodeB = *(node **)b;
    int countA = count_syllables(nodeA->word);
    int countB = count_syllables(nodeB->word);
    if(countA != countB) {
        return countA - countB;
    }
    return strcmp(nodeA->word, nodeB->word);
}

void insertsortedtoqueue(TQueue *queue, TStack *stk) {
    if(isStackEmpty(stk)) return;
    cnode *temp = popFromStack(stk);
    enqueue(queue, temp->word);
    insertsortedtoqueue(queue, stk);
    pushToStack(stk, temp);
}

TQueue *stackToQueue(TStack *stk) {
    sortWordStack(stk);
    TQueue *queue = createQueue();
    insertsortedtoqueue(queue, stk);
    return queue;
}