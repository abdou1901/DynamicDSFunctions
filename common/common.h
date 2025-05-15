#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

#define WORD_MAX_LENGTH 50

// Common utility functions
void printCentered(char *str, int width);
bool includes(char *str, char c, int size);
int countVowels(char *str);
int count_syllables(const char *word);
bool isPalindrome(char *s, int l, int r);
int is_vowel(char c);
int matchRate(char *word1, char *word2);

// Common enum
enum VowelType { SHORT, LONG, DIPHTHONG, UNKNOWN };
enum VowelType getVowelType(const char *word);

#endif // COMMON_H