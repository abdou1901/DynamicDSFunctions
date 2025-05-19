#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heap.h"

static int compareLogs(const LogEntry *a, const LogEntry *b) {
    if (a->severity != b->severity)
        return a->severity - b->severity;
    return strcmp(a->timestamp, b->timestamp);
}

static void swapEntries(LogEntry **a, LogEntry **b) {
    LogEntry *tmp = *a;
    *a = *b;
    *b = tmp;
}

static void heapifyUp(LogHeap *h, int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (compareLogs(h->data[i], h->data[parent]) > 0) {
            swapEntries(&h->data[i], &h->data[parent]);
            i = parent;
        } else {
            break;
        }
    }
}

static void heapifyDown(LogHeap *h, int i) {
    int left, right, largest;
    while (1) {
        left = 2 * i + 1;
        right = 2 * i + 2;
        largest = i;

        if (left < h->size && compareLogs(h->data[left], h->data[largest]) > 0)
            largest = left;
        if (right < h->size && compareLogs(h->data[right], h->data[largest]) > 0)
            largest = right;

        if (largest != i) {
            swapEntries(&h->data[i], &h->data[largest]);
            i = largest;
        } else {
            break;
        }
    }
}

LogHeap *createHeap(int initialCap) {
    LogHeap *h = malloc(sizeof(LogHeap));
    if (!h) return NULL;
    h->data = malloc(sizeof(LogEntry*) * initialCap);
    if (!h->data) {
        free(h);
        return NULL;
    }
    h->size = 0;
    h->cap  = initialCap;
    return h;
}

int insertLog(LogHeap *h, int id, const char *msg, const char *ts, int severity) {
    if (h->size == h->cap) {
        int newCap = h->cap * 2;
        LogEntry **newArr = realloc(h->data, sizeof(LogEntry*) * newCap);
        if (!newArr) return -1;
        h->data = newArr;
        h->cap  = newCap;
    }

    LogEntry *e = malloc(sizeof(LogEntry));
    if (!e) return -1;
    e->ID = id;
    e->severity = severity;
    strncpy(e->message, msg, MAX_MESSAGE_SIZE - 1);
    e->message[MAX_MESSAGE_SIZE - 1] = '\0';
    strncpy(e->timestamp, ts, MAX_TIMESTAMP_SIZE - 1);
    e->timestamp[MAX_TIMESTAMP_SIZE - 1] = '\0';

    h->data[h->size] = e;
    heapifyUp(h, h->size);
    h->size++;
    return 0;
}

LogEntry *peekLog(LogHeap *h) {
    if (h->size == 0) return NULL;
    return h->data[0];
}

LogEntry *popLog(LogHeap *h) {
    if (h->size == 0) return NULL;
    LogEntry *top = h->data[0];
    h->size--;
    if (h->size > 0) {
        h->data[0] = h->data[h->size];
        heapifyDown(h, 0);
    }
    return top;
}

void freeHeap(LogHeap *h) {
    for (int i = 0; i < h->size; i++) {
        free(h->data[i]);
    }
    free(h->data);
    free(h);
}
