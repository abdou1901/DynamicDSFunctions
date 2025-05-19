#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "code.h"

// Function to clear the input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Function to get string input from user
void getStringInput(char *prompt, char *buffer, int size) {
    printf("%s", prompt);
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Remove newline
}

// Function to get integer input from user
int getIntInput(char *prompt) {
    int value;
    printf("%s", prompt);
    scanf("%d", &value);
    clearInputBuffer();
    return value;
}

// Test functions for each operation
void testGetSynWords() {
    printf("\n=== Testing getSynWords ===\n");
    
    FILE *f = NULL;
    TList *synList = getSynWords(f);
    
    if (synList == NULL || synList->head == NULL) {
        printf("No synonyms found or error opening file.\n");
        return;
    }
    
    printf("Synonym list:\n");
    printWords(synList, 0);
    
    // Free the list
    node *current = synList->head;
    while (current) {
        node *temp = current;
        current = current->next;
        free(temp);
    }
    free(synList);
}

void testGetAntoWords() {
    printf("\n=== Testing getAntoWords ===\n");
    
    FILE *f = NULL;
    TList *antList = getAntoWords(f);
    
    if (antList == NULL || antList->head == NULL) {
        printf("No antonyms found or error opening file.\n");
        return;
    }
    
    printf("Antonym list:\n");
    printWords(antList, 1);
    
    // Free the list
    node *current = antList->head;
    while (current) {
        node *temp = current;
        current = current->next;
        free(temp);
    }
    free(antList);
}

void testGetInfWord() {
    printf("\n=== Testing getInfWord ===\n");
    
    FILE *f = NULL;
    TList *synList = getSynWords(f);
    TList *antList = getAntoWords(f);
    
    if (synList == NULL || antList == NULL) {
        printf("Error getting word lists.\n");
        return;
    }
    
    char word[50];
    getStringInput("Enter word to get information: ", word, sizeof(word));
    
    getInfWord(synList, antList, word);
    
    // Free the lists
    node *current = synList->head;
    while (current) {
        node *temp = current;
        current = current->next;
        free(temp);
    }
    free(synList);
    
    current = antList->head;
    while (current) {
        node *temp = current;
        current = current->next;
        free(temp);
    }
    free(antList);
}

void testGetInfWord2() {
    printf("\n=== Testing getInfWord2 ===\n");
    
    FILE *f = NULL;
    TList *synList = getSynWords(f);
    TList *antList = getAntoWords(f);
    
    if (synList == NULL || antList == NULL) {
        printf("Error getting word lists.\n");
        return;
    }
    
    char word[50];
    getStringInput("Enter synonym/antonym to get information: ", word, sizeof(word));
    
    getInfWord2(synList, antList, word);
    
    // Free the lists
    node *current = synList->head;
    while (current) {
        node *temp = current;
        current = current->next;
        free(temp);
    }
    free(synList);
    
    current = antList->head;
    while (current) {
        node *temp = current;
        current = current->next;
        free(temp);
    }
    free(antList);
}

void testSortWord() {
    printf("\n=== Testing sortWord ===\n");
    
    FILE *f = NULL;
    TList *synList = getSynWords(f);
    
    if (synList == NULL || synList->head == NULL) {
        printf("No synonyms found or error opening file.\n");
        return;
    }
    
    printf("Before sorting:\n");
    printWords(synList, 0);
    
    synList = sortWord(synList);
    
    printf("\nAfter sorting by word alphabetically:\n");
    printWords(synList, 0);
    
    // Free the list
    node *current = synList->head;
    while (current) {
        node *temp = current;
        current = current->next;
        free(temp);
    }
    free(synList);
}

void testSortWord2() {
    printf("\n=== Testing sortWord2 ===\n");
    
    FILE *f = NULL;
    TList *synList = getSynWords(f);
    
    if (synList == NULL || synList->head == NULL) {
        printf("No synonyms found or error opening file.\n");
        return;
    }
    
    printf("Before sorting:\n");
    printWords(synList, 0);
    
    synList = sortWord2(synList);
    
    printf("\nAfter sorting by character count:\n");
    printWords(synList, 0);
    
    // Free the list
    node *current = synList->head;
    while (current) {
        node *temp = current;
        current = current->next;
        free(temp);
    }
    free(synList);
}

void testSortWord3() {
    printf("\n=== Testing sortWord3 ===\n");
    
    FILE *f = NULL;
    TList *synList = getSynWords(f);
    
    if (synList == NULL || synList->head == NULL) {
        printf("No synonyms found or error opening file.\n");
        return;
    }
    
    printf("Before sorting:\n");
    printWords(synList, 0);
    
    synList = sortWord3(synList);
    
    printf("\nAfter sorting by vowel count (descending):\n");
    printWords(synList, 0);
    
    // Free the list
    node *current = synList->head;
    while (current) {
        node *temp = current;
        current = current->next;
        free(temp);
    }
    free(synList);
}

void testDeleteWord() {
    printf("\n=== Testing deleteWord ===\n");
    
    FILE *f = NULL;
    TList *synList = getSynWords(f);
    TList *antList = getAntoWords(f);
    
    if (synList == NULL || antList == NULL) {
        printf("Error getting word lists.\n");
        return;
    }
    
    printf("Current words:\n");
    printWords(synList, 0);
    
    char word[50];
    getStringInput("Enter word to delete: ", word, sizeof(word));
    
    printf("\nDeleting word '%s'...\n", word);
    deleteWord(f, synList, antList, word);
    
    printf("\nAfter deletion:\n");
    printWords(synList, 0);
    
    // Free the lists
    node *current = synList->head;
    while (current) {
        node *temp = current;
        current = current->next;
        free(temp);
    }
    free(synList);
    
    current = antList->head;
    while (current) {
        node *temp = current;
        current = current->next;
        free(temp);
    }
    free(antList);
}

void testUpdateWord() {
    printf("\n=== Testing updateWord ===\n");
    
    FILE *f = NULL;
    TList *synList = getSynWords(f);
    TList *antList = getAntoWords(f);
    
    if (synList == NULL || antList == NULL) {
        printf("Error getting word lists.\n");
        return;
    }
    
    printf("Current words:\n");
    printWords(synList, 0);
    
    char word[50], synonym[50], antonym[50];
    getStringInput("Enter word to update: ", word, sizeof(word));
    getStringInput("Enter new synonym: ", synonym, sizeof(synonym));
    getStringInput("Enter new antonym: ", antonym, sizeof(antonym));
    
    printf("\nUpdating word '%s'...\n", word);
    updateWord(f, synList, antList, word, synonym, antonym);
    
    printf("\nAfter update:\n");
    printWords(synList, 0);
    
    // Free the lists
    node *current = synList->head;
    while (current) {
        node *temp = current;
        current = current->next;
        free(temp);
    }
    free(synList);
    
    current = antList->head;
    while (current) {
        node *temp = current;
        current = current->next;
        free(temp);
    }
    free(antList);
}

void testSimilarWord() {
    printf("\n=== Testing similarWord ===\n");
    
    FILE *f = NULL;
    TList *synList = getSynWords(f);
    
    if (synList == NULL || synList->head == NULL) {
        printf("No synonyms found or error opening file.\n");
        return;
    }
    
    char word[50];
    getStringInput("Enter word prefix to find similar words: ", word, sizeof(word));
    
    int rate = getIntInput("Enter match rate (0-100): ");
    
    TList *similarList = similarWord(synList, word, rate);
    
    printf("\nSimilar words with match rate >= %d%%:\n", rate);
    printWords(similarList, 0);
    
    // Free the lists
    node *current = synList->head;
    while (current) {
        node *temp = current;
        current = current->next;
        free(temp);
    }
    free(synList);
    
    current = similarList->head;
    while (current) {
        node *temp = current;
        current = current->next;
        free(temp);
    }
    free(similarList);
}

void testCountWord() {
    printf("\n=== Testing countWord ===\n");
    
    FILE *f = NULL;
    TList *synList = getSynWords(f);
    
    if (synList == NULL || synList->head == NULL) {
        printf("No synonyms found or error opening file.\n");
        return;
    }
    
    char part[50];
    getStringInput("Enter substring to search for: ", part, sizeof(part));
    
    TList *countList = countWord(synList, part);
    
    printf("\nWords containing '%s':\n", part);
    printWords(countList, 0);
    
    // Free the lists
    node *current = synList->head;
    while (current) {
        node *temp = current;
        current = current->next;
        free(temp);
    }
    free(synList);
    
    current = countList->head;
    while (current) {
        node *temp = current;
        current = current->next;
        free(temp);
    }
    free(countList);
}

void testPalindromWord() {
    printf("\n=== Testing palindromWord ===\n");
    
    FILE *f = NULL;
    TList *synList = getSynWords(f);
    
    if (synList == NULL || synList->head == NULL) {
        printf("No synonyms found or error opening file.\n");
        return;
    }
    
    TList *palindromeList = palindromWord(synList);
    
    printf("\nPalindrome words:\n");
    printWords(palindromeList, 0);
    
    // Free the lists
    node *current = synList->head;
    while (current) {
        node *temp = current;
        current = current->next;
        free(temp);
    }
    free(synList);
    
    current = palindromeList->head;
    while (current) {
        node *temp = current;
        current = current->next;
        free(temp);
    }
    free(palindromeList);
}

void testMerge() {
    printf("\n=== Testing merge ===\n");
    
    FILE *f = NULL;
    TList *synList = getSynWords(f);
    TList *antList = getAntoWords(f);
    
    if (synList == NULL || antList == NULL) {
        printf("Error getting word lists.\n");
        return;
    }
    
    // Sort the lists to ensure they're in the right order
    synList = sortWord(synList);
    antList = sortWord(antList);
    
    TList2 *mergedList = merge(synList, antList);
    
    printf("\nMerged list (bidirectional):\n");
    printWords2(mergedList);
    
    // Free the lists
    node *current = synList->head;
    while (current) {
        node *temp = current;
        current = current->next;
        free(temp);
    }
    free(synList);
    
    current = antList->head;
    while (current) {
        node *temp = current;
        current = current->next;
        free(temp);
    }
    free(antList);
    
    dnode *dcurrent = mergedList->head;
    while (dcurrent) {
        dnode *temp = dcurrent;
        dcurrent = dcurrent->next;
        free(temp);
    }
    free(mergedList);
}

void testMerge2() {
    printf("\n=== Testing merge2 ===\n");
    
    FILE *f = NULL;
    TList *synList = getSynWords(f);
    TList *antList = getAntoWords(f);
    
    if (synList == NULL || antList == NULL) {
        printf("Error getting word lists.\n");
        return;
    }
    
    // Sort the lists to ensure they're in the right order
    synList = sortWord(synList);
    antList = sortWord(antList);
    
    TList3 *mergedList = merge2(synList, antList);
    
    printf("\nMerged list (circular):\n");
    printWords3(mergedList);
    
    // Free the lists
    node *current = synList->head;
    while (current) {
        node *temp = current;
        current = current->next;
        free(temp);
    }
    free(synList);
    
    current = antList->head;
    while (current) {
        node *temp = current;
        current = current->next;
        free(temp);
    }
    free(antList);
    
    if (mergedList->head) {
        cnode *start = mergedList->head;
        cnode *current = start;
        do {
            cnode *temp = current;
            current = current->next;
            free(temp);
        } while (current != start);
    }
    free(mergedList);
}

void testAddWord() {
    printf("\n=== Testing addWord ===\n");
    
    FILE *f = NULL;
    TList *synList = getSynWords(f);
    TList *antList = getAntoWords(f);
    
    if (synList == NULL || antList == NULL) {
        printf("Error getting word lists.\n");
        return;
    }
    
    printf("Current words:\n");
    printWords(synList, 0);
    
    char word[50], synonym[50], antonym[50];
    getStringInput("Enter new word: ", word, sizeof(word));
    getStringInput("Enter synonym: ", synonym, sizeof(synonym));
    getStringInput("Enter antonym: ", antonym, sizeof(antonym));
    
    printf("\nAdding word '%s'...\n", word);
    addWord(f, synList, antList, word, synonym, antonym);
    
    printf("\nAfter addition:\n");
    printWords(synList, 0);
    
    // Free the lists
    node *current = synList->head;
    while (current) {
        node *temp = current;
        current = current->next;
        free(temp);
    }
    free(synList);
    
    current = antList->head;
    while (current) {
        node *temp = current;
        current = current->next;
        free(temp);
    }
    free(antList);
}

void testSyllable() {
    printf("\n=== Testing syllable ===\n");
    
    FILE *f = NULL;
    TList *synList = getSynWords(f);
    
    if (synList == NULL || synList->head == NULL) {
        printf("No synonyms found or error opening file.\n");
        return;
    }
    
    TQueue *syllableQueue = syllable(synList);
    
    printf("\nWords sorted by syllable count:\n");
    printQueueWords(syllableQueue);
    
    // Free the lists
    node *current = synList->head;
    while (current) {
        node *temp = current;
        current = current->next;
        free(temp);
    }
    free(synList);
    
    // Free the queue
    QNode *qcurrent = syllableQueue->head;
    while (qcurrent) {
        QNode *temp = qcurrent;
        qcurrent = qcurrent->next;
        free(temp);
    }
    free(syllableQueue);
}

void testProunounciation() {
    printf("\n=== Testing prounounciation ===\n");
    
    FILE *f = NULL;
    TList *synList = getSynWords(f);
    
    if (synList == NULL || synList->head == NULL) {
        printf("No synonyms found or error opening file.\n");
        return;
    }
    
    TQueue **pronunciationQueues = prounounciation(synList);
    
    printf("\nWords with short vowels:\n");
    printQueueWords(pronunciationQueues[SHORT]);
    
    printf("\nWords with long vowels:\n");
    printQueueWords(pronunciationQueues[LONG]);
    
    printf("\nWords with diphthongs:\n");
    printQueueWords(pronunciationQueues[DIPHTHONG]);
    
    // Free the lists
    node *current = synList->head;
    while (current) {
        node *temp = current;
        current = current->next;
        free(temp);
    }
    free(synList);
    
    // Free the queues
    for (int i = 0; i < 3; i++) {
        QNode *qcurrent = pronunciationQueues[i]->head;
        while (qcurrent) {
            QNode *temp = qcurrent;
            qcurrent = qcurrent->next;
            free(temp);
        }
        free(pronunciationQueues[i]);
    }
    free(pronunciationQueues);
}

void testToQueue() {
    printf("\n=== Testing toQueue ===\n");
    
    FILE *f = NULL;
    TList *synList = getSynWords(f);
    TList *antList = getAntoWords(f);
    
    if (synList == NULL || antList == NULL) {
        printf("Error getting word lists.\n");
        return;
    }
    
    // Sort the lists to ensure they're in the right order
    synList = sortWord(synList);
    antList = sortWord(antList);
    
    TList2 *mergedList = merge(synList, antList);
    TQueue *queue = toQueue(mergedList);
    
    printf("\nQueue created from merged list:\n");
    printQueueWords(queue);
    
    // Free the lists
    node *current = synList->head;
    while (current) {
        node *temp = current;
        current = current->next;
        free(temp);
    }
    free(synList);
    
    current = antList->head;
    while (current) {
        node *temp = current;
        current = current->next;
        free(temp);
    }
    free(antList);
    
    dnode *dcurrent = mergedList->head;
    while (dcurrent) {
        dnode *temp = dcurrent;
        dcurrent = dcurrent->next;
        free(temp);
    }
    free(mergedList);
    
    QNode *qcurrent = queue->head;
    while (qcurrent) {
        QNode *temp = qcurrent;
        qcurrent = qcurrent->next;
        free(temp);
    }
    free(queue);
}

void testToStack() {
    printf("\n=== Testing toStack ===\n");
    
    FILE *f = NULL;
    TList *synList = getSynWords(f);
    TList *antList = getAntoWords(f);
    
    if (synList == NULL || antList == NULL) {
        printf("Error getting word lists.\n");
        return;
    }
    
    // Sort the lists to ensure they're in the right order
    synList = sortWord(synList);
    antList = sortWord(antList);
    
    TList2 *mergedList = merge(synList, antList);
    TStack *stack = toStack(mergedList);
    
    printf("\nStack created from merged list:\n");
    printStack(stack);
    
    // Free the lists
    node *current = synList->head;
    while (current) {
        node *temp = current;
        current = current->next;
        free(temp);
    }
    free(synList);
    
    current = antList->head;
    while (current) {
        node *temp = current;
        current = current->next;
        free(temp);
    }
    free(antList);
    
    dnode *dcurrent = mergedList->head;
    while (dcurrent) {
        dnode *temp = dcurrent;
        dcurrent = dcurrent->next;
        free(temp);
    }
    free(mergedList);
    
    cnode *scurrent = stack->head;
    while (scurrent) {
        cnode *temp = scurrent;
        scurrent = scurrent->next;
        free(temp);
    }
    free(stack);
}

void testGetInfWordStack() {
    printf("\n=== Testing getInfWordStack ===\n");
    
    FILE *f = NULL;
    TList *synList = getSynWords(f);
    TList *antList = getAntoWords(f);
    
    if (synList == NULL || antList == NULL) {
        printf("Error getting word lists.\n");
        return;
    }
    
    // Sort the lists to ensure they're in the right order
    synList = sortWord(synList);
    antList = sortWord(antList);
    
    TList2 *mergedList = merge(synList, antList);
    TStack *stack = toStack(mergedList);
    
    char word[50];
    getStringInput("Enter word to get information from stack: ", word, sizeof(word));
    
    printf("\nInformation for word '%s' from stack:\n", word);
    getInfWordStack(stack, word);
    
    // Free the lists
    node *current = synList->head;
    while (current) {
        node *temp = current;
        current = current->next;
        free(temp);
    }
    free(synList);
    
    current = antList->head;
    while (current) {
        node *temp = current;
        current = current->next;
        free(temp);
    }
    free(antList);
    
    dnode *dcurrent = mergedList->head;
    while (dcurrent) {
        dnode *temp = dcurrent;
        dcurrent = dcurrent->next;
        free(temp);
    }
    free(mergedList);
    
    cnode *scurrent = stack->head;
    while (scurrent) {
        cnode *temp = scurrent;
        scurrent = scurrent->next;
        free(temp);
    }
    free(stack);
}

void testSortWordStack() {
    printf("\n=== Testing sortWordStack ===\n");
    
    FILE *f = NULL;
    TList *synList = getSynWords(f);
    TList *antList = getAntoWords(f);
    
    if (synList == NULL || antList == NULL) {
        printf("Error getting word lists.\n");
        return;
    }
    
    TList2 *mergedList = merge(synList, antList);
    TStack *stack = toStack(mergedList);
    
    printf("Before sorting:\n");
    printStack(stack);
    
    stack = sortWordStack(stack);
    
    printf("\nAfter sorting stack by word alphabetically:\n");
    printStack(stack);
    
    // Free the lists
    node *current = synList->head;
    while (current) {
        node *temp = current;
        current = current->next;
        free(temp);
    }
    free(synList);
    
    current = antList->head;
    while (current) {
        node *temp = current;
        current = current->next;
        free(temp);
    }
    free(antList);
    
    dnode *dcurrent = mergedList->head;
    while (dcurrent) {
        dnode *temp = dcurrent;
        dcurrent = dcurrent->next;
        free(temp);
    }
    free(mergedList);
    
    cnode *scurrent = stack->head;
    while (scurrent) {
        cnode *temp = scurrent;
        scurrent = scurrent->next;
        free(temp);
    }
    free(stack);
}

void testDeleteWordStack() {
    printf("\n=== Testing deleteWordStack ===\n");
    
    FILE *f = NULL;
    TList *synList = getSynWords(f);
    TList *antList = getAntoWords(f);
    
    if (synList == NULL || antList == NULL) {
        printf("Error getting word lists.\n");
        return;
    }
    
    TList2 *mergedList = merge(synList, antList);
    TStack *stack = toStack(mergedList);
    
    printf("Current stack:\n");
    printStack(stack);
    
    char word[50];
    getStringInput("Enter word to delete from stack: ", word, sizeof(word));
    
    stack = deleteWordStack(stack, word);
    
    printf("\nStack after deleting '%s':\n", word);
    printStack(stack);
    
    // Free the lists
    node *current = synList->head;
    while (current) {
        node *temp = current;
        current = current->next;
        free(temp);
    }
    free(synList);
    
    current = antList->head;
    while (current) {
        node *temp = current;
        current = current->next;
        free(temp);
    }
    free(antList);
    
    dnode *dcurrent = mergedList->head;
    while (dcurrent) {
        dnode *temp = dcurrent;
        dcurrent = dcurrent->next;
        free(temp);
    }
    free(mergedList);
    
    cnode *scurrent = stack->head;
    while (scurrent) {
        cnode *temp = scurrent;
        scurrent = scurrent->next;
        free(temp);
    }
    free(stack);
}

void testUpdateWordStack() {
    printf("\n=== Testing updateWordStack ===\n");
    
    FILE *f = NULL;
    TList *synList = getSynWords(f);
    TList *antList = getAntoWords(f);
    
    if (synList == NULL || antList == NULL) {
        printf("Error getting word lists.\n");
        return;
    }
    
    TList2 *mergedList = merge(synList, antList);
    TStack *stack = toStack(mergedList);
    
    printf("Current stack:\n");
    printStack(stack);
    
    char word[50], synonym[50], antonym[50];
    getStringInput("Enter word to update in stack: ", word, sizeof(word));
    getStringInput("Enter new synonym: ", synonym, sizeof(synonym));
    getStringInput("Enter new antonym: ", antonym, sizeof(antonym));
    
    stack = updateWordStack(stack, word, synonym, antonym);
    
    printf("\nStack after updating '%s':\n", word);
    printStack(stack);
    
    // Free the lists
    node *current = synList->head;
    while (current) {
        node *temp = current;
        current = current->next;
        free(temp);
    }
    free(synList);
    
    current = antList->head;
    while (current) {
        node *temp = current;
        current = current->next;
        free(temp);
    }
    free(antList);
    
    dnode *dcurrent = mergedList->head;
    while (dcurrent) {
        dnode *temp = dcurrent;
        dcurrent = dcurrent->next;
        free(temp);
    }
    free(mergedList);
    
    cnode *scurrent = stack->head;
    while (scurrent) {
        cnode *temp = scurrent;
        scurrent = scurrent->next;
        free(temp);
    }
    free(stack);
}

void testStackToQueue() {
    printf("\n=== Testing stackToQueue ===\n");
    
    FILE *f = NULL;
    TList *synList = getSynWords(f);
    TList *antList = getAntoWords(f);
    
    if (synList == NULL || antList == NULL) {
        printf("Error getting word lists.\n");
        return;
    }
    
    TList2 *mergedList = merge(synList, antList);
    TStack *stack = toStack(mergedList);
    
    printf("Current stack:\n");
    printStack(stack);
    
    TQueue *queue = stackToQueue(stack);
    
    printf("\nQueue created from stack (sorted):\n");
    printQueueWords(queue);
    
    // Free the lists
    node *current = synList->head;
    while (current) {
        node *temp = current;
        current = current->next;
        free(temp);
    }
    free(synList);
    
    current = antList->head;
    while (current) {
        node *temp = current;
        current = current->next;
        free(temp);
    }
    free(antList);
    
    dnode *dcurrent = mergedList->head;
    while (dcurrent) {
        dnode *temp = dcurrent;
        dcurrent = dcurrent->next;
        free(temp);
    }
    free(mergedList);
    
    cnode *scurrent = stack->head;
    while (scurrent) {
        cnode *temp = scurrent;
        scurrent = scurrent->next;
        free(temp);
    }
    free(stack);
    
    QNode *qcurrent = queue->head;
    while (qcurrent) {
        QNode *temp = qcurrent;
        qcurrent = qcurrent->next;
        free(temp);
    }
    free(queue);
}

void testStacktoList() {
    printf("\n=== Testing StacktoList ===\n");
    
    FILE *f = NULL;
    TList *synList = getSynWords(f);
    TList *antList = getAntoWords(f);
    
    if (synList == NULL || antList == NULL) {
        printf("Error getting word lists.\n");
        return;
    }
    
    TList2 *mergedList = merge(synList, antList);
    TStack *stack = toStack(mergedList);
    
    printf("Current stack:\n");
    printStack(stack);
    
    TList2 *newList = StacktoList(stack);
    
    printf("\nList created from stack (sorted):\n");
    printWords2(newList);
    
    // Free the lists
    node *current = synList->head;
    while (current) {
        node *temp = current;
        current = current->next;
        free(temp);
    }
    free(synList);
    
    current = antList->head;
    while (current) {
        node *temp = current;
        current = current->next;
        free(temp);
    }
    free(antList);
    
    dnode *dcurrent = mergedList->head;
    while (dcurrent) {
        dnode *temp = dcurrent;
        dcurrent = dcurrent->next;
        free(temp);
    }
    free(mergedList);
    
    cnode *scurrent = stack->head;
    while (scurrent) {
        cnode *temp = scurrent;
        scurrent = scurrent->next;
        free(temp);
    }
    free(stack);
    
    dcurrent = newList->head;
    while (dcurrent) {
        dnode *temp = dcurrent;
        dcurrent = dcurrent->next;
        free(temp);
    }
    free(newList);
}

void testAddWordStack() {
    printf("\n=== Testing addWordStack ===\n");
    
    FILE *f = NULL;
    TList *synList = getSynWords(f);
    TList *antList = getAntoWords(f);
    
    if (synList == NULL || antList == NULL) {
        printf("Error getting word lists.\n");
        return;
    }
    
    TList2 *mergedList = merge(synList, antList);
    TStack *stack = toStack(mergedList);
    
    printf("Current stack:\n");
    printStack(stack);
    
    char word[50], synonym[50], antonym[50];
    getStringInput("Enter new word to add to stack: ", word, sizeof(word));
    getStringInput("Enter synonym: ", synonym, sizeof(synonym));
    getStringInput("Enter antonym: ", antonym, sizeof(antonym));
    
    stack = addWordStack(stack, word, synonym, antonym);
    
    printf("\nStack after adding '%s':\n", word);
    printStack(stack);
    
    // Free the lists
    node *current = synList->head;
    while (current) {
        node *temp = current;
        current = current->next;
        free(temp);
    }
    free(synList);
    
    current = antList->head;
    while (current) {
        node *temp = current;
        current = current->next;
        free(temp);
    }
    free(antList);
    
    dnode *dcurrent = mergedList->head;
    while (dcurrent) {
        dnode *temp = dcurrent;
        dcurrent = dcurrent->next;
        free(temp);
    }
    free(mergedList);
    
    cnode *scurrent = stack->head;
    while (scurrent) {
        cnode *temp = scurrent;
        scurrent = scurrent->next;
        free(temp);
    }
    free(stack);
}

void testSyllableStack() {
    printf("\n=== Testing syllableStack ===\n");
    
    FILE *f = NULL;
    TList *synList = getSynWords(f);
    TList *antList = getAntoWords(f);
    
    if (synList == NULL || antList == NULL) {
        printf("Error getting word lists.\n");
        return;
    }
    
    TList2 *mergedList = merge(synList, antList);
    TStack *stack = toStack(mergedList);
    
    printf("Current stack:\n");
    printStack(stack);
    
    TStack *syllableStack = syllableStack(stack);
    
    printf("\nStack sorted by syllable count:\n");
    printStack(syllableStack);
    
    // Free the lists
    node *current = synList->head;
    while (current) {
        node *temp = current;
        current = current->next;
        free(temp);
    }
    free(synList);
    
    current = antList->head;
    while (current) {
        node *temp = current;
        current = current->next;
        free(temp);
    }
    free(antList);
    
    dnode *dcurrent = mergedList->head;
    while (dcurrent) {
        dnode *temp = dcurrent;
        dcurrent = dcurrent->next;
        free(temp);
    }
    free(mergedList);
    
    cnode *scurrent = stack->head;
    while (scurrent) {
        cnode *temp = scurrent;
        scurrent = scurrent->next;
        free(temp);
    }
    free(stack);
    
    scurrent = syllableStack->head;
    while (scurrent) {
        cnode *temp = scurrent;
        scurrent = scurrent->next;
        free(temp);
    }
    free(syllableStack);
}

void testProunounciationStack() {
    printf("\n=== Testing prounounciationStack ===\n");
    
    FILE *f = NULL;
    TList *synList = getSynWords(f);
    TList *antList = getAntoWords(f);
    
    if (synList == NULL || antList == NULL) {
        printf("Error getting word lists.\n");
        return;
    }
    
    TList2 *mergedList = merge(synList, antList);
    TStack *stack = toStack(mergedList);
    
    TStack **pronunciationStacks = prounounciationStack(stack);
    
    printf("\nWords with short vowels:\n");
    printStack(pronunciationStacks[SHORT]);
    
    printf("\nWords with long vowels:\n");
    printStack(pronunciationStacks[LONG]);
    
    printf("\nWords with diphthongs:\n");
    printStack(pronunciationStacks[DIPHTHONG]);
    
    // Free the lists
    node *current = synList->head;
    while (current) {
        node *temp = current;
        current = current->next;
        free(temp);
    }
    free(synList);
    
    current = antList->head;
    while (current) {
        node *temp = current;
        current = current->next;
        free(temp);
    }
    free(antList);
    
    dnode *dcurrent = mergedList->head;
    while (dcurrent) {
        dnode *temp = dcurrent;
        dcurrent = dcurrent->next;
        free(temp);
    }
    free(mergedList);
    
    cnode *scurrent = stack->head;
    while (scurrent) {
        cnode *temp = scurrent;
        scurrent = scurrent->next;
        free(temp);
    }
    free(stack);
    
    // Free the pronunciation stacks
    for (int i = 0; i < 3; i++) {
        scurrent = pronunciationStacks[i]->head;
        while (scurrent) {
            cnode *temp = scurrent;
            scurrent = scurrent->next;
            free(temp);
        }
        free(pronunciationStacks[i]);
    }
    free(pronunciationStacks);
}

void testGetSmallest() {
    printf("\n=== Testing getSmallest ===\n");
    
    FILE *f = NULL;
    TList *synList = getSynWords(f);
    TList *antList = getAntoWords(f);
    
    if (synList == NULL || antList == NULL) {
        printf("Error getting word lists.\n");
        return;
    }
    
    TList2 *mergedList = merge(synList, antList);
    TStack *stack = toStack(mergedList);
    
    printf("Current stack:\n");
    printStack(stack);
    
    char *smallest = getSmallest(stack);
    
    if (smallest) {
        printf("\nSmallest word (by character count): %s\n", smallest);
    } else {
        printf("\nNo words in the stack.\n");
    }
    
    // Free the lists
    node *current = synList->head;
    while (current) {
        node *temp = current;
        current = current->next;
        free(temp);
    }
    free(synList);
    
    current = antList->head;
    while (current) {
        node *temp = current;
        current = current->next;
        free(temp);
    }
    free(antList);
    
    dnode *dcurrent = mergedList->head;
    while (dcurrent) {
        dnode *temp = dcurrent;
        dcurrent = dcurrent->next;
        free(temp);
    }
    free(mergedList);
    
    cnode *scurrent = stack->head;
    while (scurrent) {
        cnode *temp = scurrent;
        scurrent = scurrent->next;
        free(temp);
    }
    free(stack);
}

void testIsPalyndromeStack() {
    printf("\n=== Testing isPalyndromeStack ===\n");
    
    char word[50];
    getStringInput("Enter word to check if it's a palindrome: ", word, sizeof(word));
    
    bool isPalindrome = isPalyndromeStack(word);
    
    printf("\nIs '%s' a palindrome? %s\n", word, isPalindrome ? "Yes" : "No");
}

void testCycleSearch() {
    printf("\n=== Testing cycleSearch ===\n");
    
    FILE *f = NULL;
    TList *synList = getSynWords(f);
    TList *antList = getAntoWords(f);
    
    if (synList == NULL || antList == NULL) {
        printf("Error getting word lists.\n");
        return;
    }
    
    TList2 *mergedList = merge(synList, antList);
    TStack *stack = toStack(mergedList);
    
    printf("Searching for cycles in the word relationships...\n");
    cycleSearch(stack);
    
    // Free the lists
    node *current = synList->head;
    while (current) {
        node *temp = current;
        current = current->next;
        free(temp);
    }
    free(synList);
    
    current = antList->head;
    while (current) {
        node *temp = current;
        current = current->next;
        free(temp);
    }
    free(antList);
    
    dnode *dcurrent = mergedList->head;
    while (dcurrent) {
        dnode *temp = dcurrent;
        dcurrent = dcurrent->next;
        free(temp);
    }
    free(mergedList);
    
    cnode *scurrent = stack->head;
    while (scurrent) {
        cnode *temp = scurrent;
        scurrent = scurrent->next;
        free(temp);
    }
    free(stack);
}

void testStackRev() {
    printf("\n=== Testing StackRev ===\n");
    
    FILE *f = NULL;
    TList *synList = getSynWords(f);
    TList *antList = getAntoWords(f);
    
    if (synList == NULL || antList == NULL) {
        printf("Error getting word lists.\n");
        return;
    }
    
    TList2 *mergedList = merge(synList, antList);
    TStack *stack = toStack(mergedList);
    
    printf("Current stack:\n");
    printStack(stack);
    
    stack = StackRev(stack);
    
    printf("\nReversed stack:\n");
    printStack(stack);
    
    // Free the lists
    node *current = synList->head;
    while (current) {
        node *temp = current;
        current = current->next;
        free(temp);
    }
    free(synList);
    
    current = antList->head;
    while (current) {
        node *temp = current;
        current = current->next;
        free(temp);
    }
    free(antList);
    
    dnode *dcurrent = mergedList->head;
    while (dcurrent) {
        dnode *temp = dcurrent;
        dcurrent = dcurrent->next;
        free(temp);
    }
    free(mergedList);
    
    cnode *scurrent = stack->head;
    while (scurrent) {
        cnode *temp = scurrent;
        scurrent = scurrent->next;
        free(temp);
    }
    free(stack);
}

// Main function with menu
int main() {
    int choice;
    
    while (1) {
        printf("\n=== Dictionary Testing Menu ===\n");
        printf("1. Test getSynWords\n");
        printf("2. Test getAntoWords\n");
        printf("3. Test getInfWord\n");
        printf("4. Test getInfWord2\n");
        printf("5. Test sortWord (alphabetically)\n");
        printf("6. Test sortWord2 (by character count)\n");
        printf("7. Test sortWord3 (by vowel count)\n");
        printf("8. Test deleteWord\n");
        printf("9. Test updateWord\n");
        printf("10. Test similarWord\n");
        printf("11. Test countWord\n");
        printf("12. Test palindromWord\n");
        printf("13. Test merge (bidirectional list)\n");
        printf("14. Test merge2 (circular list)\n");
        printf("15. Test addWord\n");
        printf("16. Test syllable\n");
        printf("17. Test prounounciation\n");
        printf("18. Test toQueue\n");
        printf("19. Test toStack\n");
        printf("20. Test getInfWordStack\n");
        printf("21. Test sortWordStack\n");
        printf("22. Test deleteWordStack\n");
        printf("23. Test updateWordStack\n");
        printf("24. Test stackToQueue\n");
        printf("25. Test StacktoList\n");
        printf("26. Test addWordStack\n");
        printf("27. Test syllableStack\n");
        printf("28. Test prounounciationStack\n");
        printf("29. Test getSmallest\n");
        printf("30. Test isPalyndromeStack\n");
        printf("31. Test cycleSearch\n");
        printf("32. Test StackRev\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();
        
        if (choice == 0) {
            break;
        }
        
        switch (choice) {
            case 1:
                testGetSynWords();
                break;
            case 2:
                testGetAntoWords();
                break;
            case 3:
                testGetInfWord();
                break;
            case 4:
                testGetInfWord2();
                break;
            case 5:
                testSortWord();
                break;
            case 6:
                testSortWord2();
                break;
            case 7:
                testSortWord3();
                break;
            case 8:
                testDeleteWord();
                break;
            case 9:
                testUpdateWord();
                break;
            case 10:
                testSimilarWord();
                break;
            case 11:
                testCountWord();
                break;
            case 12:
                testPalindromWord();
                break;
            case 13:
                testMerge();
                break;
            case 14:
                testMerge2();
                break;
            case 15:
                testAddWord();
                break;
            case 16:
                testSyllable();
                break;
            case 17:
                testProunounciation();
                break;
            case 18:
                testToQueue();
                break;
            case 19:
                testToStack();
                break;
            case 20:
                testGetInfWordStack();
                break;
            case 21:
                testSortWordStack();
                break;
            case 22:
                testDeleteWordStack();
                break;
            case 23:
                testUpdateWordStack();
                break;
            case 24:
                testStackToQueue();
                break;
            case 25:
                testStacktoList();
                break;
            case 26:
                testAddWordStack();
                break;
            case 27:
                testSyllableStack();
                break;
            case 28:
                testProunounciationStack();
                break;
            case 29:
                testGetSmallest();
                break;
            case 30:
                testIsPalyndromeStack();
                break;
            case 31:
                testCycleSearch();
                break;
            case 32:
                testStackRev();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    printf("Testing completed. Exiting...\n");
    return 0;
}
