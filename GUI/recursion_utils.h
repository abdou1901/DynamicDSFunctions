#ifndef RECURSION_UTILS_H
#define RECURSION_UTILS_H

#include "unified_data_structures.h"

// File operations
FILE *openFile(const char *filename, const char *mode);
char *readLine(FILE *file);
void parseLineS(char *line, char *word, char *syn);
void parseLineA(char *line, char *word, char *ant);
int countWordOccurrence(FILE *f, const char *word);
FILE *removeWordOccurence(FILE *f, char *word);
FILE *replaceWordOccurence(FILE *f, char *word, char *rep);

// Word operations
void permute(char *word, int index);
void loop(int i, int end, int index, char *word);
void wordPermutation(char *word);
void generateSubsequences(char *word, int index, char *currentSubseq, int subseqIndex);
void subseqWord(char *word);
int max(int a, int b);
int longestSubseqWord(char *word1, char *word2);
int distinctSubseqWord(char *word);
bool isPalindromWord(char *word);  // Changed from bool to int to match code.h

#endif // RECURSION_UTILS_H
