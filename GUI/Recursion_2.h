#ifndef E2A0CD64_5ADF_4CFB_8245_C47FAE2BE7F5
#define E2A0CD64_5ADF_4CFB_8245_C47FAE2BE7F5
#ifndef RECURSION_PART2_H
#define RECURSION_PART2_H

#include <stdio.h>
#include <stdbool.h>

// PART TWO function prototypes
FILE *openFile(const char *filename, const char *mode);

char *readLine(FILE *file);

void parseLineS(char *line, char *word, char *syn);

void parseLineA(char *line, char *word, char *ant);


int countWordOccurrence(FILE *f, const char *word);

FILE *removeWordOccurence(FILE *f, char *word);

FILE *replaceWordOccurence(FILE *f, char *word, char *rep);


void permute(char *word, int index);

void loop(int i, int end, int index, char *word);

void wordPermutation(char *word);

void generateSubsequences(char *word, int index, char *currentSubseq, int subseqIndex);

void subseqWord(char *word);

int max(int a, int b);

int longestSubseqWord(char *word1, char *word2);

int distinctSubseqWord(char *word);

bool isPalindromWord(char *word);


typedef struct {
    char **lines;
    int top;
    int capacity;
} Stack;

Stack *createStack(int capacity);

void push(Stack *stack, const char *line);

char *pop(Stack *stack);

void reverseFile(const char *inputFilename, const char *outputFilename);

void replaceFile(const char *original, const char *temp);

#endif // RECURSION_PART2_H


#endif /* E2A0CD64_5ADF_4CFB_8245_C47FAE2BE7F5 */
